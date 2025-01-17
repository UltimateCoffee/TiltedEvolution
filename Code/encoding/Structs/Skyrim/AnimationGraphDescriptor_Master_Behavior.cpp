#include <Structs/AnimationGraphDescriptorManager.h>
#include <Structs/Skyrim/AnimationGraphDescriptor_Master_Behavior.h>
#include <Structs/AnimationGraphVariable.h>

AnimationGraphDescriptor_Master_Behavior::AnimationGraphDescriptor_Master_Behavior(
    AnimationGraphDescriptorManager& aManager)
{   
    enum Variables
    {
        kSpeed = 0,
        kDirection = 1,
        kTurnDelta = 2,
        kiSyncIdleLocomotion = 3,
        kSpeedWalk = 4,
        kSpeedRun = 5,
        kfSpeedMin = 6,
        kuseShield = 7,
        kuseMLh = 8,
        kblendMoveStart = 9,
        kblendMoveStop = 10,
        kblendDefault = 11,
        kWalkSpeedMult = 12,
        kTurnDeltaDamped = 13,
        kTurnMin = 14,
        kIsFirstPerson = 15,
        kPitch = 16,
        kPitchLook = 17,
        kblendAttackPowerFast = 18,
        kblendAttackPowerSlow = 19,
        kblendFast = 20,
        kIsPlayer = 21,
        kattackPowerStartTime = 22,
        kblendMove1stP = 23,
        kIntVariable = 24,
        kIsNPC = 25,
        kblendSlow = 26,
        kPitchDefault = 27,
        kPitchOverride = 28,
        kstaggerMagnitude = 29,
        kblockDown = 30,
        kblockLeft = 31,
        kblockRight = 32,
        kblockUp = 33,
        krecoilMagnitude = 34,
        kiRightHandType = 35,
        kIsBlocking = 36,
        kiWantBlock = 37,
        kIsAttackReady = 38,
        kiAnnotation = 39,
        kSpeedSampled = 40,
        kbMotionDriven = 41,
        kblendAttackRelease = 42,
        kattackComboStartFraction = 43,
        kblendAttackCombo = 44,
        kattackIntroLength = 45,
        kIsShouting = 46,
        kweaponSpeedMult = 47,
        kiSyncTurnState = 48,
        ki1stPerson = 49,
        kIsSprinting = 50,
        kbIsSynced = 51,
        kIsBlockHit = 52,
        kTimeDelta = 53,
        kPitchOffset = 54,
        kPitchAcc = 55,
        kPitchThresh = 56,
        kUsePitch = 57,
        kDisablePitch = 58,
        kweapAdj = 59,
        kiLeftHandType = 60,
        kweapChangeStartFraction = 61,
        k1stPRot = 62,
        k1stPRotDamped = 63,
        kRotMax = 64,
        kPitchManualOverride = 65,
        kSpeedAcc = 66,
        kIsCastingRight = 67,
        kIsCastingLeft = 68,
        kCastBlend = 69,
        kbVoiceReady = 70,
        kbWantCastLeft = 71,
        kbWantCastRight = 72,
        kbWantCastVoice = 73,
        kBlendDamped = 74,
        kb1HM_MLh_attack = 75,
        kIs1HM = 76,
        ki1HMState = 77,
        kRawBlend = 78,
        kBlendAcc = 79,
        kb1HMCombat = 80,
        kbAnimationDriven = 81,
        kbCastReady = 82,
        kIsStaggering = 83,
        kIsRecoiling = 84,
        kIsAttacking = 85,
        kIsInCastState = 86,
        kbleedoutTurnMult = 87,
        kIsInCastStateDamped = 88,
        kbAllowRotation = 89,
        kbMagicDraw = 90,
        kCastBlendDamped = 91,
        kbMLh_Ready = 92,
        kbMRh_Ready = 93,
        kiState = 94,
        kiState_NPCSprinting = 95,
        kiState_NPCDefault = 96,
        kfIsFirstPerson = 97,
        kbInMoveState = 98,
        kiState_NPCSneaking = 99,
        kiState_NPCBowDrawn = 100,
        kBoolVariable = 101,
        kDualMagicState = 102,
        kiDualMagicState = 103,
        kInDualMagicState = 104,
        kiState_NPCBlocking = 105,
        kiState_NPCBleedout = 106,
        kiBlockState = 107,
        kbSprintOK = 108,
        kiSyncSprintState = 109,
        kIsEquipping = 110,
        kIsUnequipping = 111,
        kiIsInSneak = 112,
        kcurrentDefaultState = 113,
        kBowZoom = 114,
        kbowZoomAmt = 115,
        kbIdlePlaying = 116,
        kiMagicEquipped = 117,
        kiEquippedItemState = 118,
        kiMagicState = 119,
        kIsCastingDual = 120,
        kbIsDialogueExpressive = 121,
        kiIsDialogueExpressive = 122,
        kbAnimObjectLoaded = 123,
        kfEquipWeapAdj = 124,
        kbEquipUnequip = 125,
        kbAttached = 126,
        kbodyMorphWeight = 127,
        kIsBashing = 128,
        kbEquipOk = 129,
        kIsBleedingOut = 130,
        kfMagicForceEquipBlendValue = 131,
        kFemaleOffset = 132,
        kblendVerySlow = 133,
        kblendDialogue = 134,
        kiSyncIdleState = 135,
        kfIdleTimer = 136,
        kbIsH2HSolo = 137,
        kAdditiveHeadTransl = 138,
        kAdditiveHeadScale = 139,
        kAdditiveHeadRot = 140,
        k2HMweaponSpeedMult = 141,
        kiState_NPC1HM = 142,
        kiState_NPC2HM = 143,
        kiState_NPCBow = 144,
        kiState_NPCMagic = 145,
        kiState_NPCMagicCasting = 146,
        kiState_NPCHorse = 147,
        kiState_HorseSprint = 148,
        kiCharacterSelector = 149,
        krandomStartTime = 150,
        kbHeadTracking = 151,
        kbIsRiding = 152,
        kfMinSpeed = 153,
        kiCombatStance = 154,
        kturnSpeedMult = 155,
        kiSyncTurnDirection = 156,
        kfTwistDirection = 157,
        kIntDirection = 158,
        kDirectionRange = 159,
        kDirectionRangeDamped = 160,
        kDirectionDamped = 161,
        kIsDismounting = 162,
        kTargetLocation = 163,
        kbTalkable = 164,
        kbNeutralState = 165,
        kCastOK = 166,
        kblendFromAnimDriven = 167,
        kwalkBackRate = 168,
        kbRitualSpellActive = 169,
        kSwimDirection = 170,
        kiRegularAttack = 171,
        kIsAttackReady_32 = 172,
        kcamerafromx = 173,
        kcamerafromy = 174,
        kcamerafromz = 175,
        kVelocityZ = 176,
        kbInJumpState = 177,
        kLookAtOutOfRange = 178,
        kiRightHandEquipped = 179,
        kiLeftHandEquipped = 180,
        ktestint = 181,
        kiIsPlayer = 182,
        kSpeedDamped = 183,
        kbodyMorphMuscular = 184,
        kbHeadTrackSpine = 185,
        kIsSneaking = 186,
        kiGetUpType = 187,
        kiState_NPCAttacking = 188,
        kiState_NPCPowerAttacking = 189,
        kiState_NPCAttacking2H = 190,
        kLookAtOnGain = 191,
        kLookAtOffGain = 192,
        kLookAtEyeOnGain = 193,
        kLookAtEyeOffGain = 194,
        kiDrunkVariable = 195,
        kiState_NPCDrunk = 196,
        kleftWeaponSpeedMult = 197,
        kbLeftHandAttack = 198,
        kBlendJump = 199,
        kbIsInMT = 200,
        kBoolVariable00 = 201,
        kbHumanoidFootIKEnable = 202,
        ktestPitchOffset = 203,
        kbBowDrawn = 204,
        kIsBeastRace = 205,
        kbHumanoidFootIKDisable = 206,
        kiTempSwitch = 207,
        kiState_NPCBowDrawnQuickShot = 208,
        kiState_NPCBlockingShieldCharge = 209,
        kbStaggerPlayerOverride = 210,
        kbNoStagger = 211,
        kbIsStaffLeftCasting = 212,
        kIs3rdPKillOnly = 213,
        kbPerkShieldCharge = 214,
        kbPerkQuickShot = 215,
        km_bEnablePitchTwistModifier = 216,
        km_worldFromModelFeedbackGain = 217,
        kIsBleedingOutTransition = 218,
        kbMesmerize = 219,
        kiIsHorse = 220,
        kbWantMountedWeaponAnims = 221,
        kiUseMountedSwimming = 222,
        kAimPitchCurrent = 223,
        kAimHeadingCurrent = 224,
        kbAimActive = 225,
        kAimGainOff = 226,
        kAimGainOnMounted = 227,
        kAimGainOnDragonMount = 228,
        kiWantMountedWeaponAnims = 229,
        //start modded

        //end modded        
        kiWeaponReady = 230,
        kZoomAcc = 231,
        kAimHeadingMax = 232,
        kAimPitchMax = 233,
        kAimGainOn = 234,
        kbDisableInterp = 235,
        kBowAimOffsetPitch = 236,
        kBowAimOffsetHeading = 237,
        kbPerkQuickDraw = 238,
        kbForceIdleStop = 239,
        kIsInDWattack = 240,
        kbShortKillMove = 241,
        kbLongKillMove = 242,
        kiCrossbowState = 243,
        kInt32Variable = 244,
        kAllowBlockModify = 245,
        k_iState_NPCSneaking = 246,
        kMagicLeftActive = 247,
        kAllowMagicModify = 248,
        kMagicAimOffsetHeading = 249,
        kMagicAimOffsetPitch = 250,
        kNotCasting = 251,
        kCastBlendGain = 252,
        kiWantBlock01 = 253,
        kstaggerDirection = 254,
        kiSyncForwardState = 255,
        kfMinTurnDelta = 256,
        kbHeadTrackingOn = 257,
        km_onOffGain = 258,
        km_groundAscendingGain = 259,
        km_groundDescendingGain = 260,
        km_footPlantedGain = 261,
        km_footRaisedGain = 262,
        km_footUnlockGain = 263,
        km_errorUpDownBias = 264,
        km_alignWorldFromModelGain = 265,
        km_hipOrientationGain = 266,
        km_footPlantedAnkleHeightMS = 267,
        km_footRaisedAnkleHeightMS = 268,
        km_maxAnkleHeightMS = 269,
        km_minAnkleHeightMS = 270,
        kbDisableHeadTrack = 271,
        kbCanHeadTrack = 272,
        kisIdleSitting = 273,
        kbMirroredAttack = 274,
        kfMinMoveSpeed = 275,
        kiState_HorseDefault = 276,
        kHorseSpeedSampled = 277,
        kwalkBackSpeedMult = 278,
        kiState_HorseFall = 279,
        kbInSwimState = 280,
        kiState_HorseSwim = 281,
        kbHorseFootIKEnable = 282,
        kbNoHeadTrack = 283,
        kisMoving = 284,
        kblendVeryFast = 285,
        kAimHeadingMaxMounted = 286,
        kAimPitchMaxMounted = 287,
        kMC_2HM_WeapSpeed = 288,
        kiSyncDialogueResponse = 289,
        kbBlendOutSlow = 290,
        kisInFurniture = 291,
        kbIdleBeforeConversation = 292,
        kbMotionDrivenDialogue = 293,
        kbAnimationDrivenDialogue = 294,
        kbHDDialogue = 295,
        kbHHDialogue = 296,
        kbTalkableWithItem = 297,
        kisCarryItem = 298,
        kIsRomanticFollower = 299,
        kIsRF_Talk = 300
    };

    AnimationGraphDescriptorManager::Builder s_builder(
        aManager, m_key,
        AnimationGraphDescriptor(
        {
            kbEquipOk,
            kbMotionDriven,
            kIsBeastRace,
            kIsSneaking,
            kIsBleedingOut,
            kIsCastingDual,
            kIs1HM,
            kIsCastingRight,
            kIsCastingLeft,
            kIsBlockHit,
            kIsPlayer,
            kIsNPC,
            kbIsSynced,
            kbVoiceReady,
            kbWantCastLeft,
            kbWantCastRight,
            kbWantCastVoice,
            kb1HM_MLh_attack,
            kb1HMCombat,
            kbAnimationDriven,
            kbCastReady,
            kIsAttacking,
            kbAllowRotation,
            kbMagicDraw,
            kbMLh_Ready,
            kbMRh_Ready,
            kbInMoveState,
            kbSprintOK,
            kbIdlePlaying,
            kbIsDialogueExpressive,
            kbAnimObjectLoaded,
            kbEquipUnequip,
            kbAttached,
            kbIsH2HSolo,
            kbHeadTracking,
            kbIsRiding,
            kbTalkable,
            kbRitualSpellActive,
            kbInJumpState,
            kbHeadTrackSpine,
            kbLeftHandAttack,
            kbIsInMT,
            kbHumanoidFootIKEnable,
            kbHumanoidFootIKDisable,
            kbStaggerPlayerOverride,
            kbNoStagger,
            kbIsStaffLeftCasting,
            kbPerkShieldCharge,
            kbPerkQuickShot,
            kIsBlocking,
            kIsBashing,
            kIsStaggering,
            kIsRecoiling,
            kIsEquipping,
            kIsUnequipping,
            kisInFurniture,
            kbNeutralState,
            kbBowDrawn,
            // TODO: this was added extra for spell cast sync
            kPitchOverride,
            kNotCasting
        },
        {
            kTurnDelta,
            kDirection,
            kSpeedSampled,
            kweapAdj,
            kSpeed,
            // TODO: this was added extra for spell cast sync
            kCastBlend,
            kPitchOffset,
            kSpeedDamped,
            kPitch,
            kVelocityZ,
            k1stPRot,
            k1stPRotDamped,
            kCastBlendDamped
        },
        {
            kiRightHandEquipped,
            kiLeftHandEquipped,
            ki1HMState,
            kiState,
            kiLeftHandType,
            kiRightHandType,
            kiSyncIdleLocomotion,
            kiSyncForwardState,
            kiSyncTurnState,
            kiIsInSneak,
            kiWantBlock,
            kiRegularAttack,
            // TODO: this was added extra for spell cast sync
            ktestint,
            kcurrentDefaultState
        }));
        
}

/*
enum Actions
{
    kRightAttack = 0x13005,
    kJump = 0x13006,
    kLand = 0x937F5,
    kDraw = 0x132AF,
    kRightPowerAttack = 0x13383,
    kRightRelease = 0x13454,
    kActivate = 0x13009,
    kMoveStart = 0x959F8,
    kMoveStop = 0x959F9,
    kFall = 0x937F4,
    kSheath = 0x46BAF,
    kTurnRight = 0x959FC,
    kTurnLeft = 0x959FD,
    kTurnStop = 0x959FE
};
 */
