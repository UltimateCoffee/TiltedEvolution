#pragma once

#include <optional>

#if defined(TP_SKYRIM) && TP_PLATFORM_64
#define POINTER_SKYRIMSE(className, variableName, ...) static AutoPtr<className> variableName(__VA_ARGS__)
//#define POINTER_SKYRIMSE_V2(variableName, ...) static AutoPtr<decltype()> variableName(__VA_ARGS__)
#else
#define POINTER_SKYRIMSE(className, variableName, ...) ;
#endif

#if defined(TP_FALLOUT) && TP_PLATFORM_64
#define POINTER_FALLOUT4(className, variableName, ...) static AutoPtr<className> variableName(__VA_ARGS__)
#else
#define POINTER_FALLOUT4(className, variableName, ...) ;
#endif

// TODO: should this be debug only? I removed the check since debug is broken, can only use releasedbg
#define TP_ASSERT(Expr, Msg, ...)                                                                                      \
    if (!(Expr))                                                                                                       \
    {                                                                                                                  \
        Utils::Assert(#Expr, fmt::format(Msg, __VA_ARGS__).c_str());                                                   \
    }

namespace Utils
{
static void Assert(const char* apExpression, const char* apMessage)
{
    spdlog::critical("Assertion failed ({}): {}", apExpression, apMessage);

    if (IsDebuggerPresent())
        __debugbreak();
}

TiltedPhoques::String RandomString(size_t aLength);
TiltedPhoques::WString RandomStringW(size_t aLength);

std::optional<uint32_t> GetServerId(entt::entity aEntity) noexcept;
} // namespace Utils
