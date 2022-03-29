#pragma once

#include <Structs/GameId.h>

struct Equipment
{
    bool operator==(const Equipment& acRhs) const noexcept;
    bool operator!=(const Equipment& acRhs) const noexcept;

    void Serialize(TiltedPhoques::Buffer::Writer& aWriter) const noexcept;
    void Deserialize(TiltedPhoques::Buffer::Reader& aReader) noexcept;

    GameId RightHandWeapon{};
#if TP_SKYRIM
    GameId LeftHandWeapon{};
    GameId LeftHandSpell{};
    GameId RightHandSpell{};
    GameId Shout{};
    GameId Ammo{};
#endif
};