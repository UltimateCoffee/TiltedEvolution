#include <World.h>
#include <Components.h>
#include <random>

namespace Utils
{

String RandomString(size_t aLength)
{
    constexpr char kAllowedCharacters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device device;
    std::mt19937 generator(device());
    const std::uniform_int_distribution<> distribution(0, std::size(kAllowedCharacters) - 1);

    String result;

    for (std::size_t i = 0; i < aLength; ++i)
    {
        result += kAllowedCharacters[distribution(generator)];
    }

    return result;
}

TiltedPhoques::WString RandomStringW(size_t aLength)
{
    constexpr wchar_t kAllowedCharacters[] = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device device;
    std::mt19937 generator(device());
    const std::uniform_int_distribution<> distribution(0, std::size(kAllowedCharacters) - 1);

    TiltedPhoques::WString result;

    for (std::size_t i = 0; i < aLength; ++i)
    {
        result += kAllowedCharacters[distribution(generator)];
    }

    return result;
}

std::optional<uint32_t> GetServerId(entt::entity aEntity) noexcept
{
    const auto* pLocalComponent = World::Get().try_get<LocalComponent>(aEntity);
    const auto* pRemoteComponent = World::Get().try_get<RemoteComponent>(aEntity);

    uint32_t serverId = -1;
    if (pLocalComponent)
        serverId = pLocalComponent->Id;
    else if (pRemoteComponent)
        serverId = pRemoteComponent->Id;
    else
    {
        const auto* pFormIdComponent = World::Get().try_get<FormIdComponent>(aEntity);
        spdlog::warn("This entity has neither a local or remote component: {:X}, form id: {:X}",  aEntity, pFormIdComponent ? pFormIdComponent->Id : 0);
        return std::nullopt;
    }

    return {serverId};
}
}
