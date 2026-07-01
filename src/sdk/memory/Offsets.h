#pragma once
#include <cstdint>

namespace Offsets
{

    // ============================================
    // Context: AmmoIndex_t
    // ============================================
    namespace AmmoIndex_t
    {
        constexpr  ptrdiff_t m_nPrimaryAmmoType = 0x4CE;
        constexpr  ptrdiff_t m_nSecondaryAmmoType = 0x4CF;
    }

    // ============================================
    // Context: AnimLoopMode_t
    // ============================================
    namespace AnimLoopMode_t
    {
        constexpr  ptrdiff_t m_nSeqLoopMode = 0xC;
        constexpr  ptrdiff_t m_nAnimLoopMode = 0xBC;
        constexpr  ptrdiff_t m_nDefaultAnimLoopMode = 0x1160;
        constexpr  ptrdiff_t m_nIdleAnimLoopMode = 0x1358;
    }

    // ============================================
    // Context: AnimationAlgorithm_t
    // ============================================
    namespace AnimationAlgorithm_t
    {
        constexpr  ptrdiff_t m_nAnimationAlgorithm = 0x18;
        constexpr  ptrdiff_t m_nPrevAnimationAlgorithm = 0x689;
    }

    // ============================================
    // Context: AttachmentHandle_t
    // ============================================
    namespace AttachmentHandle_t
    {
        constexpr  ptrdiff_t m_eyeAttachment = 0x1299;
        constexpr  ptrdiff_t m_chestAttachment = 0x129A;
        constexpr  ptrdiff_t m_iStartAttachment = 0x1274;
        constexpr  ptrdiff_t m_iEndAttachment = 0x1275;
        constexpr  ptrdiff_t m_iEyeAttachment = 0x1175;
        constexpr  ptrdiff_t m_nAttachmentIndex = 0x64;
        constexpr  ptrdiff_t m_leftFootAttachment = 0x1170;
        constexpr  ptrdiff_t m_rightFootAttachment = 0x1171;
        constexpr  ptrdiff_t m_nAttachIndex = 0x1020;
        constexpr  ptrdiff_t m_nAttachment = 0xFB4;
    }

    // ============================================
    // Context: BeamClipStyle_t
    // ============================================
    namespace BeamClipStyle_t
    {
        constexpr  ptrdiff_t m_nClipStyle = 0x104C;
    }

    // ============================================
    // Context: BeamType_t
    // ============================================
    namespace BeamType_t
    {
        constexpr  ptrdiff_t m_nBeamType = 0xFF0;
    }

    // ============================================
    // Context: BloodType
    // ============================================
    namespace BloodType
    {
        constexpr  ptrdiff_t m_nBloodType = 0x5F8;
    }

    // ============================================
    // Context: BreakableContentsType_t
    // ============================================
    namespace BreakableContentsType_t
    {
        constexpr  ptrdiff_t m_BreakableContentsType = 0x1260;
    }

    // ============================================
    // Context: C4LightEffect_t
    // ============================================
    namespace C4LightEffect_t
    {
        constexpr  ptrdiff_t m_eActiveLightEffect = 0x1CB4;
    }

    // ============================================
    // Context: CAnimGraph2ParamOptionalRef
    // ============================================
    namespace CAnimGraph2ParamOptionalRef
    {
        constexpr  ptrdiff_t m_bIsDefusing = 0x2A0;
        constexpr  ptrdiff_t m_moveType = 0x2B8;
        constexpr  ptrdiff_t m_moveDirectionID = 0x2D0;
        constexpr  ptrdiff_t m_flMoveSpeedX = 0x2E8;
        constexpr  ptrdiff_t m_flMoveSpeedY = 0x300;
        constexpr  ptrdiff_t m_flMoveSpeedHorizontal = 0x318;
        constexpr  ptrdiff_t m_flPreviousMoveSpeedHorizontal = 0x330;
        constexpr  ptrdiff_t m_flCrouchAmount = 0x348;
        constexpr  ptrdiff_t m_bIsWalking = 0x360;
        constexpr  ptrdiff_t m_flWeaponDropAmount = 0x378;
        constexpr  ptrdiff_t m_groundAction = 0x390;
        constexpr  ptrdiff_t m_groundActionDirectionID = 0x3A8;
        constexpr  ptrdiff_t m_flGroundTurnAngleOrVelocity = 0x3C0;
        constexpr  ptrdiff_t m_flLadderCycle = 0x3D8;
        constexpr  ptrdiff_t m_flLadderYaw = 0x3F0;
        constexpr  ptrdiff_t m_flLadderYawBackwards = 0x408;
        constexpr  ptrdiff_t m_airAction = 0x420;
        constexpr  ptrdiff_t m_flAirHeightAboveGround = 0x438;
        constexpr  ptrdiff_t m_leftFootTarget = 0x450;
        constexpr  ptrdiff_t m_rightFootTarget = 0x468;
        constexpr  ptrdiff_t m_flFlashedAmount = 0x480;
        constexpr  ptrdiff_t m_flAimPitchAngle = 0x498;
        constexpr  ptrdiff_t m_flAimYawAngle = 0x4B0;
        constexpr  ptrdiff_t m_flinchHead = 0x4C8;
        constexpr  ptrdiff_t m_flinchHeadRestart = 0x4E0;
        constexpr  ptrdiff_t m_flinchBody = 0x4F8;
        constexpr  ptrdiff_t m_flinchBodyRestart = 0x510;
        constexpr  ptrdiff_t m_flinchIsOnFire = 0x528;
        constexpr  ptrdiff_t m_action = 0x88;
        constexpr  ptrdiff_t m_bActionReset = 0xA0;
        constexpr  ptrdiff_t m_flWeaponActionSpeedScale = 0xB8;
        constexpr  ptrdiff_t m_weaponCategory = 0xD0;
        constexpr  ptrdiff_t m_weaponType = 0xE8;
        constexpr  ptrdiff_t m_weaponExtraInfo = 0x100;
        constexpr  ptrdiff_t m_flWeaponAmmo = 0x118;
        constexpr  ptrdiff_t m_flWeaponAmmoMax = 0x130;
        constexpr  ptrdiff_t m_flWeaponAmmoReserve = 0x148;
        constexpr  ptrdiff_t m_bWeaponIsSilenced = 0x160;
        constexpr  ptrdiff_t m_flWeaponIronsightAmount = 0x178;
        constexpr  ptrdiff_t m_bIsUsingLegacyModel = 0x190;
        constexpr  ptrdiff_t m_idleVariation = 0x1A8;
        constexpr  ptrdiff_t m_deployVariation = 0x1C0;
        constexpr  ptrdiff_t m_attackType = 0x1D8;
        constexpr  ptrdiff_t m_attackThrowStrength = 0x1F0;
        constexpr  ptrdiff_t m_flAttackVariation = 0x208;
        constexpr  ptrdiff_t m_inspectVariation = 0x220;
        constexpr  ptrdiff_t m_inspectExtraInfo = 0x238;
        constexpr  ptrdiff_t m_reloadStage = 0x250;
        constexpr  ptrdiff_t m_nAnimationSeed = 0x88;
        constexpr  ptrdiff_t m_characterMode = 0xA0;
        constexpr  ptrdiff_t m_nTeamPreviewVariant = 0xB8;
        constexpr  ptrdiff_t m_nTeamPreviewRandom = 0xD0;
        constexpr  ptrdiff_t m_nTeamPreviewPosition = 0xE8;
        constexpr  ptrdiff_t m_endOfMatchCelebration = 0x100;
        constexpr  ptrdiff_t m_bannerAnimation = 0x130;
        constexpr  ptrdiff_t m_weaponState = 0x178;
        constexpr  ptrdiff_t m_inspectTurnAngle = 0x190;
        constexpr  ptrdiff_t m_bCT = 0x1A8;
    }

    // ============================================
    // Context: CAnimGraphControllerBase
    // ============================================
    namespace CAnimGraphControllerBase
    {
        constexpr  ptrdiff_t m_pMainGraphController = 0x1058;
    }

    // ============================================
    // Context: CAnimGraphControllerManager
    // ============================================
    namespace CAnimGraphControllerManager
    {
        constexpr  ptrdiff_t m_graphControllerManager = 0xFA8;
    }

    // ============================================
    // Context: CAttachmentNameSymbolWithStorage
    // ============================================
    namespace CAttachmentNameSymbolWithStorage
    {
        constexpr  ptrdiff_t m_sMuzzleAttachment = 0x2D0;
    }

    // ============================================
    // Context: CAttributeList
    // ============================================
    namespace CAttributeList
    {
        constexpr  ptrdiff_t m_AttributeList = 0x208;
        constexpr  ptrdiff_t m_NetworkedDynamicAttributes = 0x280;
    }

    // ============================================
    // Context: CAttributeManager
    // ============================================
    namespace CAttributeManager
    {
        constexpr  ptrdiff_t m_pManager = 0x70;
    }

    // ============================================
    // Context: CBaseAnimGraph
    // ============================================
    namespace CBaseAnimGraph
    {
        constexpr  ptrdiff_t m_pClientsideRagdoll = 0x1088;
    }

    // ============================================
    // Context: CBaseAnimGraphController
    // ============================================
    namespace CBaseAnimGraphController
    {
        constexpr  ptrdiff_t m_animationController = 0x4E0;
    }

    // ============================================
    // Context: CBaseAnimGraphDestructibleParts_GraphController
    // ============================================
    namespace CBaseAnimGraphDestructibleParts_GraphController
    {
        constexpr  ptrdiff_t m_pAnimGraphDestructibleGraphController = 0x68;
    }

    // ============================================
    // Context: CBasePlayerController
    // ============================================
    namespace CBasePlayerController
    {
        constexpr  ptrdiff_t m_pPredictionOwner = 0x12A0;
    }

    // ============================================
    // Context: CBitVec
    // ============================================
    namespace CBitVec
    {
        constexpr  ptrdiff_t m_LinksTouchingSomething = 0xFB0;
    }

    // ============================================
    // Context: CBodyComponent
    // ============================================
    namespace CBodyComponent
    {
        constexpr  ptrdiff_t m_CBodyComponent = 0x30;
    }

    // ============================================
    // Context: CBuoyancyHelper
    // ============================================
    namespace CBuoyancyHelper
    {
        constexpr  ptrdiff_t m_BuoyancyHelper = 0xFA8;
    }

    // ============================================
    // Context: CCSGameModeRules
    // ============================================
    namespace CCSGameModeRules
    {
        constexpr  ptrdiff_t m_pGameModeRules = 0xD98;
    }

    // ============================================
    // Context: CCSPlayerAnimationState
    // ============================================
    namespace CCSPlayerAnimationState
    {
        constexpr  ptrdiff_t m_AnimationState = 0x310;
    }

    // ============================================
    // Context: CCSPlayerController_ActionTrackingServices
    // ============================================
    namespace CCSPlayerController_ActionTrackingServices
    {
        constexpr  ptrdiff_t m_pActionTrackingServices = 0x818;
    }

    // ============================================
    // Context: CCSPlayerController_DamageServices
    // ============================================
    namespace CCSPlayerController_DamageServices
    {
        constexpr  ptrdiff_t m_pDamageServices = 0x820;
    }

    // ============================================
    // Context: CCSPlayerController_InGameMoneyServices
    // ============================================
    namespace CCSPlayerController_InGameMoneyServices
    {
        constexpr  ptrdiff_t m_pInGameMoneyServices = 0x808;
    }

    // ============================================
    // Context: CCSPlayerController_InventoryServices
    // ============================================
    namespace CCSPlayerController_InventoryServices
    {
        constexpr  ptrdiff_t m_pInventoryServices = 0x810;
    }

    // ============================================
    // Context: CCSPlayerLegacyJump
    // ============================================
    namespace CCSPlayerLegacyJump
    {
        constexpr  ptrdiff_t m_LegacyJump = 0x6B8;
    }

    // ============================================
    // Context: CCSPlayerModernJump
    // ============================================
    namespace CCSPlayerModernJump
    {
        constexpr  ptrdiff_t m_ModernJump = 0x6D0;
    }

    // ============================================
    // Context: CCSPlayer_ActionTrackingServices
    // ============================================
    namespace CCSPlayer_ActionTrackingServices
    {
        constexpr  ptrdiff_t m_pActionTrackingServices = 0x1488;
    }

    // ============================================
    // Context: CCSPlayer_AimPunchServices
    // ============================================
    namespace CCSPlayer_AimPunchServices
    {
        constexpr  ptrdiff_t m_pAimPunchServices = 0x1490;
    }

    // ============================================
    // Context: CCSPlayer_BulletServices
    // ============================================
    namespace CCSPlayer_BulletServices
    {
        constexpr  ptrdiff_t m_pBulletServices = 0x1468;
    }

    // ============================================
    // Context: CCSPlayer_BuyServices
    // ============================================
    namespace CCSPlayer_BuyServices
    {
        constexpr  ptrdiff_t m_pBuyServices = 0x1478;
    }

    // ============================================
    // Context: CCSPlayer_DamageReactServices
    // ============================================
    namespace CCSPlayer_DamageReactServices
    {
        constexpr  ptrdiff_t m_pDamageReactServices = 0x1498;
    }

    // ============================================
    // Context: CCSPlayer_GlowServices
    // ============================================
    namespace CCSPlayer_GlowServices
    {
        constexpr  ptrdiff_t m_pGlowServices = 0x1480;
    }

    // ============================================
    // Context: CCSPlayer_HostageServices
    // ============================================
    namespace CCSPlayer_HostageServices
    {
        constexpr  ptrdiff_t m_pHostageServices = 0x1470;
    }

    // ============================================
    // Context: CCSPlayer_PingServices
    // ============================================
    namespace CCSPlayer_PingServices
    {
        constexpr  ptrdiff_t m_pPingServices = 0x13C8;
    }

    // ============================================
    // Context: CChoreoComponent
    // ============================================
    namespace CChoreoComponent
    {
        constexpr  ptrdiff_t m_pChoreoComponent = 0xB10;
    }

    // ============================================
    // Context: CClientAlphaProperty
    // ============================================
    namespace CClientAlphaProperty
    {
        constexpr  ptrdiff_t m_pClientAlphaProperty = 0xF50;
    }

    // ============================================
    // Context: CCollisionProperty
    // ============================================
    namespace CCollisionProperty
    {
        constexpr  ptrdiff_t m_Collision = 0xD28;
        constexpr  ptrdiff_t m_pCollision = 0x340;
    }

    // ============================================
    // Context: CColorGradient
    // ============================================
    namespace CColorGradient
    {
        constexpr  ptrdiff_t m_Gradient = 0x48;
    }

    // ============================================
    // Context: CDestructiblePartsComponent
    // ============================================
    namespace CDestructiblePartsComponent
    {
        constexpr  ptrdiff_t m_pDestructiblePartsSystemComponent = 0xB48;
    }

    // ============================================
    // Context: CEntityAttributeTable
    // ============================================
    namespace CEntityAttributeTable
    {
        constexpr  ptrdiff_t m_pAttributes = 0x48;
    }

    // ============================================
    // Context: CEntityHandle
    // ============================================
    namespace CEntityHandle
    {
        constexpr  ptrdiff_t m_hDetectParentChange = 0x1458;
        constexpr  ptrdiff_t m_hSource = 0x6B4;
        constexpr  ptrdiff_t m_hItem = 0x40;
        constexpr  ptrdiff_t m_hEntity = 0x38;
        constexpr  ptrdiff_t m_hOtherEntity = 0x3C;
        constexpr  ptrdiff_t m_hOwner = 0x8;
    }

    // ============================================
    // Context: CEntityIOOutput
    // ============================================
    namespace CEntityIOOutput
    {
        constexpr  ptrdiff_t m_StyleEvent = 0x1038;
        constexpr  ptrdiff_t m_OnStartDeath = 0x11D0;
        constexpr  ptrdiff_t m_OnBreak = 0x11E8;
        constexpr  ptrdiff_t m_OnTakeDamage = 0x1220;
        constexpr  ptrdiff_t m_OnSpawn = 0x600;
        constexpr  ptrdiff_t m_OnTrigger = 0x618;
        constexpr  ptrdiff_t m_OnPlay = 0x600;
        constexpr  ptrdiff_t m_OnPlayerPickup = 0x17A0;
        constexpr  ptrdiff_t m_onSoundFinished = 0x650;
        constexpr  ptrdiff_t m_pOutputAnimBegun = 0x12D8;
        constexpr  ptrdiff_t m_pOutputAnimOver = 0x12F0;
        constexpr  ptrdiff_t m_pOutputAnimLoopCycleOver = 0x1308;
        constexpr  ptrdiff_t m_OnAnimReachedStart = 0x1320;
        constexpr  ptrdiff_t m_OnAnimReachedEnd = 0x1338;
        constexpr  ptrdiff_t m_pOutputOnEntitiesSpawned = 0x600;
        constexpr  ptrdiff_t m_OnStartTouch = 0xFA8;
        constexpr  ptrdiff_t m_OnStartTouchAll = 0xFC0;
        constexpr  ptrdiff_t m_OnEndTouch = 0xFD8;
        constexpr  ptrdiff_t m_OnEndTouchAll = 0xFF0;
        constexpr  ptrdiff_t m_OnTouching = 0x1008;
        constexpr  ptrdiff_t m_OnTouchingEachEntity = 0x1020;
        constexpr  ptrdiff_t m_OnNotTouching = 0x1038;
        constexpr  ptrdiff_t m_OnPass = 0x608;
        constexpr  ptrdiff_t m_OnFail = 0x620;
    }

    // ============================================
    // Context: CEntityIdentity
    // ============================================
    namespace CEntityIdentity
    {
        constexpr  ptrdiff_t m_pEntity = 0x10;
        constexpr  ptrdiff_t m_pPrev = 0x50;
        constexpr  ptrdiff_t m_pNext = 0x58;
        constexpr  ptrdiff_t m_pPrevByClass = 0x60;
        constexpr  ptrdiff_t m_pNextByClass = 0x68;
    }

    // ============================================
    // Context: CEntityIndex
    // ============================================
    namespace CEntityIndex
    {
        constexpr  ptrdiff_t m_nLastKillerIndex = 0x1C88;
        constexpr  ptrdiff_t m_iIDEntIndex = 0x33FC;
        constexpr  ptrdiff_t m_iTargetItemEntIdx = 0x3418;
        constexpr  ptrdiff_t m_iOldIDEntIndex = 0x341C;
        constexpr  ptrdiff_t m_iHostageEntityIDs = 0x618;
    }

    // ============================================
    // Context: CEntityInstance
    // ============================================
    namespace CEntityInstance
    {
        constexpr  ptrdiff_t m_pOwner = 0x30;
    }

    // ============================================
    // Context: CEntityOutputTemplate
    // ============================================
    namespace CEntityOutputTemplate
    {
        constexpr  ptrdiff_t m_OnHealthChanged = 0x1200;
        constexpr  ptrdiff_t m_onGUIDChanged = 0x620;
        constexpr  ptrdiff_t m_OnEntitySpawned = 0x668;
    }

    // ============================================
    // Context: CFiringModeFloat
    // ============================================
    namespace CFiringModeFloat
    {
        constexpr  ptrdiff_t m_flCycleTime = 0x740;
        constexpr  ptrdiff_t m_flMaxSpeed = 0x750;
        constexpr  ptrdiff_t m_flSpread = 0x758;
        constexpr  ptrdiff_t m_flInaccuracyCrouch = 0x760;
        constexpr  ptrdiff_t m_flInaccuracyStand = 0x768;
        constexpr  ptrdiff_t m_flInaccuracyJump = 0x770;
        constexpr  ptrdiff_t m_flInaccuracyLand = 0x778;
        constexpr  ptrdiff_t m_flInaccuracyLadder = 0x780;
        constexpr  ptrdiff_t m_flInaccuracyFire = 0x788;
        constexpr  ptrdiff_t m_flInaccuracyMove = 0x790;
        constexpr  ptrdiff_t m_flRecoilAngle = 0x798;
        constexpr  ptrdiff_t m_flRecoilAngleVariance = 0x7A0;
        constexpr  ptrdiff_t m_flRecoilMagnitude = 0x7A8;
        constexpr  ptrdiff_t m_flRecoilMagnitudeVariance = 0x7B0;
    }

    // ============================================
    // Context: CFiringModeInt
    // ============================================
    namespace CFiringModeInt
    {
        constexpr  ptrdiff_t m_nTracerFrequency = 0x7B8;
    }

    // ============================================
    // Context: CGameSceneNode
    // ============================================
    namespace CGameSceneNode
    {
        constexpr  ptrdiff_t m_sceneNode = 0x80;
        constexpr  ptrdiff_t m_pParent = 0x38;
        constexpr  ptrdiff_t m_pChild = 0x40;
        constexpr  ptrdiff_t m_pNextSibling = 0x48;
        constexpr  ptrdiff_t m_pGameSceneNode = 0x330;
        constexpr  ptrdiff_t m_pSceneNode = 0x8;
    }

    // ============================================
    // Context: CGameSceneNodeHandle
    // ============================================
    namespace CGameSceneNodeHandle
    {
        constexpr  ptrdiff_t m_hParent = 0x70;
    }

    // ============================================
    // Context: CGlobalSymbol
    // ============================================
    namespace CGlobalSymbol
    {
        constexpr  ptrdiff_t m_sExplosionType = 0x1288;
        constexpr  ptrdiff_t m_sAnimGraph2Identifier = 0x440;
        constexpr  ptrdiff_t m_OutflowID = 0x0;
        constexpr  ptrdiff_t m_szName = 0x720;
        constexpr  ptrdiff_t m_szAnimClass = 0x870;
        constexpr  ptrdiff_t m_NodeName = 0x20;
        constexpr  ptrdiff_t m_animgraphCharacterModeString = 0x3440;
        constexpr  ptrdiff_t m_DecalType = 0xF8;
    }

    // ============================================
    // Context: CGlowProperty
    // ============================================
    namespace CGlowProperty
    {
        constexpr  ptrdiff_t m_Glow = 0xDD8;
    }

    // ============================================
    // Context: CHandle
    // ============================================
    namespace CHandle
    {
        constexpr  ptrdiff_t m_hPlayerPing = 0x48;
        constexpr  ptrdiff_t m_hEntOwner = 0x3C;
        constexpr  ptrdiff_t m_hInfoFan = 0x10B0;
        constexpr  ptrdiff_t m_hPlayerParent = 0x118C;
        constexpr  ptrdiff_t m_hOriginalController = 0x1450;
        constexpr  ptrdiff_t m_hBreaker = 0x1254;
        constexpr  ptrdiff_t m_hPhysicsAttacker = 0x12B8;
        constexpr  ptrdiff_t m_hLastAttacker = 0x12C4;
        constexpr  ptrdiff_t m_hBombPlanter = 0x148;
        constexpr  ptrdiff_t m_glowEntity = 0xFA8;
        constexpr  ptrdiff_t m_hCarriedHostage = 0x48;
        constexpr  ptrdiff_t m_hCarriedHostageProp = 0x4C;
        constexpr  ptrdiff_t m_hFilter = 0x690;
        constexpr  ptrdiff_t m_hProxySoundscape = 0x678;
        constexpr  ptrdiff_t m_hPrevOwner = 0x18D0;
        constexpr  ptrdiff_t m_hViewPosition = 0x11B0;
        constexpr  ptrdiff_t m_hZoomOwner = 0x2A0;
        constexpr  ptrdiff_t m_hHudModelArms = 0x1B58;
        constexpr  ptrdiff_t m_leader = 0x11F8;
        constexpr  ptrdiff_t m_hHostageGrabber = 0x1230;
        constexpr  ptrdiff_t m_hCtrl = 0x8;
        constexpr  ptrdiff_t m_hObserverTarget = 0x4C;
        constexpr  ptrdiff_t m_hStartPoint = 0x126C;
        constexpr  ptrdiff_t m_hEndPoint = 0x1270;
        constexpr  ptrdiff_t m_hLight = 0x610;
        constexpr  ptrdiff_t m_hPath = 0x650;
        constexpr  ptrdiff_t m_hMaster = 0x13D0;
        constexpr  ptrdiff_t m_hSceneObjectController = 0x364;
        constexpr  ptrdiff_t m_hEffectEntity = 0x51C;
        constexpr  ptrdiff_t m_hOwnerEntity = 0x520;
        constexpr  ptrdiff_t m_hGroundEntity = 0x530;
        constexpr  ptrdiff_t m_hOldMoveParent = 0x574;
        constexpr  ptrdiff_t m_hHolidayHatAddon = 0x13A8;
        constexpr  ptrdiff_t m_hController = 0x13A8;
        constexpr  ptrdiff_t m_hDefaultController = 0x13AC;
        constexpr  ptrdiff_t m_hPrevPostProcessingVolume = 0x2A8;
        constexpr  ptrdiff_t m_OwningPlayer = 0x17C8;
        constexpr  ptrdiff_t m_KillingPlayer = 0x17CC;
        constexpr  ptrdiff_t m_hOuter = 0x24;
        constexpr  ptrdiff_t m_hColorCorrectionCtrl = 0xA0;
        constexpr  ptrdiff_t m_hViewEntity = 0xA4;
        constexpr  ptrdiff_t m_hTonemapController = 0xA8;
        constexpr  ptrdiff_t m_hOldFogController = 0x1B0;
        constexpr  ptrdiff_t m_hActivePostProcessingVolume = 0x1FC;
        constexpr  ptrdiff_t m_hSwitchToWeaponAfterThrow = 0x1D4C;
        constexpr  ptrdiff_t m_hPlayerPawn = 0x90C;
        constexpr  ptrdiff_t m_hObserverPawn = 0x910;
        constexpr  ptrdiff_t m_hOriginalControllerOfCurrentPawn = 0x930;
        constexpr  ptrdiff_t m_hOwner = 0x20;
        constexpr  ptrdiff_t m_hTarget = 0x608;
        constexpr  ptrdiff_t m_hCamera = 0x8;
        constexpr  ptrdiff_t m_hTargetCamera = 0xFC0;
        constexpr  ptrdiff_t m_Handle = 0x600;
        constexpr  ptrdiff_t m_hTargetC4 = 0x1158;
        constexpr  ptrdiff_t m_hControlPointEnts = 0x11FC;
        constexpr  ptrdiff_t m_hLastWeaponBeforeC4AutoSwitch = 0x48;
        constexpr  ptrdiff_t m_hActivator = 0xFD8;
        constexpr  ptrdiff_t m_PlayerDamager = 0x30;
        constexpr  ptrdiff_t m_PlayerRecipient = 0x34;
        constexpr  ptrdiff_t m_hPlayerControllerDamager = 0x38;
        constexpr  ptrdiff_t m_hPlayerControllerRecipient = 0x3C;
        constexpr  ptrdiff_t m_hViewmodelAttachment = 0x1688;
        constexpr  ptrdiff_t m_hOldProvidee = 0x16A8;
        constexpr  ptrdiff_t m_hRemapLineStart = 0x608;
        constexpr  ptrdiff_t m_hRemapLineEnd = 0x60C;
        constexpr  ptrdiff_t m_hAttachEntity = 0xFF8;
        constexpr  ptrdiff_t m_hEndEntity = 0x1060;
        constexpr  ptrdiff_t m_hBombDefuser = 0x11B8;
        constexpr  ptrdiff_t m_hDefuserMultimeter = 0x1690;
        constexpr  ptrdiff_t m_pBombDefuser = 0x169C;
        constexpr  ptrdiff_t m_hRagdollSource = 0x11A4;
        constexpr  ptrdiff_t m_hActiveWeapon = 0x60;
        constexpr  ptrdiff_t m_hLastWeapon = 0x64;
        constexpr  ptrdiff_t m_hPlayer = 0x630;
        constexpr  ptrdiff_t m_hPingedEntity = 0x634;
        constexpr  ptrdiff_t m_hSkyCamera = 0x604;
        constexpr  ptrdiff_t m_hThrower = 0x1180;
        constexpr  ptrdiff_t m_hOriginalThrower = 0x119C;
        constexpr  ptrdiff_t m_hAttachedToEntity = 0xFB0;
        constexpr  ptrdiff_t m_hEntAttached = 0x600;
        constexpr  ptrdiff_t m_hOldAttached = 0x628;
        constexpr  ptrdiff_t m_hPawn = 0x6BC;
        constexpr  ptrdiff_t m_hPredictedPawn = 0x6C4;
        constexpr  ptrdiff_t m_hSplitOwner = 0x6CC;
        constexpr  ptrdiff_t m_hEnvWind = 0x4B8;
        constexpr  ptrdiff_t m_hEnvSky = 0x4BC;
    }

    // ============================================
    // Context: CHitboxComponent
    // ============================================
    namespace CHitboxComponent
    {
        constexpr  ptrdiff_t m_CHitboxComponent = 0xAF8;
    }

    // ============================================
    // Context: CInButtonState
    // ============================================
    namespace CInButtonState
    {
        constexpr  ptrdiff_t m_nButtons = 0x50;
    }

    // ============================================
    // Context: CLightComponent
    // ============================================
    namespace CLightComponent
    {
        constexpr  ptrdiff_t m_CLightComponent = 0xFA8;
    }

    // ============================================
    // Context: CModelState
    // ============================================
    namespace CModelState
    {
        constexpr  ptrdiff_t m_modelState = 0x150;
    }

    // ============================================
    // Context: CNetworkOriginCellCoordQuantizedVector
    // ============================================
    namespace CNetworkOriginCellCoordQuantizedVector
    {
        constexpr  ptrdiff_t m_vecOrigin = 0x80;
    }

    // ============================================
    // Context: CNetworkTransmitComponent
    // ============================================
    namespace CNetworkTransmitComponent
    {
        constexpr  ptrdiff_t m_NetworkTransmitComponent = 0x38;
    }

    // ============================================
    // Context: CNetworkVarChainer
    // ============================================
    namespace CNetworkVarChainer
    {
        constexpr  ptrdiff_t __m_pChainEntity = 0x10;
    }

    // ============================================
    // Context: CNetworkVelocityVector
    // ============================================
    namespace CNetworkVelocityVector
    {
        constexpr  ptrdiff_t m_vecServerVelocity = 0x408;
        constexpr  ptrdiff_t m_vecVelocity = 0x430;
    }

    // ============================================
    // Context: CNetworkViewOffsetVector
    // ============================================
    namespace CNetworkViewOffsetVector
    {
        constexpr  ptrdiff_t m_vecViewOffset = 0xE70;
    }

    // ============================================
    // Context: CNetworkedQuantizedFloat
    // ============================================
    namespace CNetworkedQuantizedFloat
    {
        constexpr  ptrdiff_t m_flPlaybackRate = 0xC0;
        constexpr  ptrdiff_t m_flWeight = 0x14;
    }

    // ============================================
    // Context: CNmGraphInstance
    // ============================================
    namespace CNmGraphInstance
    {
        constexpr  ptrdiff_t m_pGraphInstanceAG2 = 0x448;
    }

    // ============================================
    // Context: CParticleProperty
    // ============================================
    namespace CParticleProperty
    {
        constexpr  ptrdiff_t m_Particles = 0x578;
    }

    // ============================================
    // Context: CPathQueryComponent
    // ============================================
    namespace CPathQueryComponent
    {
        constexpr  ptrdiff_t m_CPathQueryComponent = 0x610;
    }

    // ============================================
    // Context: CPiecewiseCurve
    // ============================================
    namespace CPiecewiseCurve
    {
        constexpr  ptrdiff_t m_Curve = 0x48;
    }

    // ============================================
    // Context: CPlayerSlot
    // ============================================
    namespace CPlayerSlot
    {
        constexpr  ptrdiff_t m_iRoundEndFunFactPlayerSlot = 0xF20;
    }

    // ============================================
    // Context: CPlayerSprayDecalRenderHelper
    // ============================================
    namespace CPlayerSprayDecalRenderHelper
    {
        constexpr  ptrdiff_t m_SprayRenderHelper = 0x1088;
    }

    // ============================================
    // Context: CPlayer_AutoaimServices
    // ============================================
    namespace CPlayer_AutoaimServices
    {
        constexpr  ptrdiff_t m_pAutoaimServices = 0x11F0;
    }

    // ============================================
    // Context: CPlayer_CameraServices
    // ============================================
    namespace CPlayer_CameraServices
    {
        constexpr  ptrdiff_t m_pCameraServices = 0x1218;
    }

    // ============================================
    // Context: CPlayer_FlashlightServices
    // ============================================
    namespace CPlayer_FlashlightServices
    {
        constexpr  ptrdiff_t m_pFlashlightServices = 0x1210;
    }

    // ============================================
    // Context: CPlayer_ItemServices
    // ============================================
    namespace CPlayer_ItemServices
    {
        constexpr  ptrdiff_t m_pItemServices = 0x11E8;
    }

    // ============================================
    // Context: CPlayer_MovementServices
    // ============================================
    namespace CPlayer_MovementServices
    {
        constexpr  ptrdiff_t m_pMovementServices = 0x1220;
    }

    // ============================================
    // Context: CPlayer_ObserverServices
    // ============================================
    namespace CPlayer_ObserverServices
    {
        constexpr  ptrdiff_t m_pObserverServices = 0x11F8;
    }

    // ============================================
    // Context: CPlayer_UseServices
    // ============================================
    namespace CPlayer_UseServices
    {
        constexpr  ptrdiff_t m_pUseServices = 0x1208;
    }

    // ============================================
    // Context: CPlayer_WaterServices
    // ============================================
    namespace CPlayer_WaterServices
    {
        constexpr  ptrdiff_t m_pWaterServices = 0x1200;
    }

    // ============================================
    // Context: CPlayer_WeaponServices
    // ============================================
    namespace CPlayer_WeaponServices
    {
        constexpr  ptrdiff_t m_pWeaponServices = 0x11E0;
    }

    // ============================================
    // Context: CPointOffScreenIndicatorUi
    // ============================================
    namespace CPointOffScreenIndicatorUi
    {
        constexpr  ptrdiff_t m_pOffScreenIndicator = 0x1180;
    }

    // ============================================
    // Context: CPropDataComponent
    // ============================================
    namespace CPropDataComponent
    {
        constexpr  ptrdiff_t m_CPropDataComponent = 0x1190;
    }

    // ============================================
    // Context: CPulseValueFullType
    // ============================================
    namespace CPulseValueFullType
    {
        constexpr  ptrdiff_t m_DomainSubType = 0x18;
        constexpr  ptrdiff_t m_ExpectedParamType = 0xA0;
        constexpr  ptrdiff_t m_ReturnType = 0xA0;
    }

    // ============================================
    // Context: CPulse_OutflowConnection
    // ============================================
    namespace CPulse_OutflowConnection
    {
        constexpr  ptrdiff_t m_EventOutflow = 0x8;
        constexpr  ptrdiff_t m_Connection = 0x0;
        constexpr  ptrdiff_t m_Always = 0xC0;
        constexpr  ptrdiff_t m_WhenTrue = 0x108;
        constexpr  ptrdiff_t m_WhenFalse = 0x150;
        constexpr  ptrdiff_t m_FailOutflow = 0x68;
        constexpr  ptrdiff_t m_EvaluateConnection = 0x0;
    }

    // ============================================
    // Context: CPulse_ResumePoint
    // ============================================
    namespace CPulse_ResumePoint
    {
        constexpr  ptrdiff_t m_OnFinished = 0x68;
        constexpr  ptrdiff_t m_OnCanceled = 0xB0;
        constexpr  ptrdiff_t m_OnTrue = 0xC0;
        constexpr  ptrdiff_t m_WaitComplete = 0x50;
        constexpr  ptrdiff_t m_Completed = 0x48;
        constexpr  ptrdiff_t m_WakeResume = 0x48;
        constexpr  ptrdiff_t m_UnyieldResume = 0x48;
    }

    // ============================================
    // Context: CRenderComponent
    // ============================================
    namespace CRenderComponent
    {
        constexpr  ptrdiff_t m_CRenderComponent = 0xAF0;
        constexpr  ptrdiff_t m_pRenderComponent = 0x338;
    }

    // ============================================
    // Context: CResourceNameTyped
    // ============================================
    namespace CResourceNameTyped
    {
        constexpr  ptrdiff_t m_szParticlePrecipitationEffect = 0x28;
        constexpr  ptrdiff_t m_szAnimSkeleton = 0x528;
        constexpr  ptrdiff_t m_szTracerParticle = 0x620;
        constexpr  ptrdiff_t m_sPulseFile = 0x8;
        constexpr  ptrdiff_t m_sSceneFile = 0xE8;
        constexpr  ptrdiff_t m_ParticleEffect = 0x10;
        constexpr  ptrdiff_t m_sModelName = 0x28;
        constexpr  ptrdiff_t m_sModelNameAg2Override = 0x108;
        constexpr  ptrdiff_t m_szWorldModel = 0x28;
        constexpr  ptrdiff_t m_szWorldModelAg2Override = 0x108;
        constexpr  ptrdiff_t m_sToolsOnlyOwnerModelName = 0x1E8;
        constexpr  ptrdiff_t m_szMuzzleFlashParticle = 0x2F0;
        constexpr  ptrdiff_t m_szBarrelSmokeParticle = 0x3D8;
        constexpr  ptrdiff_t m_strSpecificContainerMaterial = 0x8;
        constexpr  ptrdiff_t m_strResourceMaterial = 0x98;
        constexpr  ptrdiff_t m_strTextureRuntimeResourcePath = 0x180;
        constexpr  ptrdiff_t m_ModelName = 0x0;
        constexpr  ptrdiff_t m_ChildModelName = 0x100;
    }

    // ============================================
    // Context: CSMatchStats_t
    // ============================================
    namespace CSMatchStats_t
    {
        constexpr  ptrdiff_t m_matchStats = 0xA8;
    }

    // ============================================
    // Context: CSPlayerBlockingUseAction_t
    // ============================================
    namespace CSPlayerBlockingUseAction_t
    {
        constexpr  ptrdiff_t m_iBlockingUseActionInProgress = 0x1C54;
    }

    // ============================================
    // Context: CSPlayerState
    // ============================================
    namespace CSPlayerState
    {
        constexpr  ptrdiff_t m_previousPlayerState = 0x13D0;
        constexpr  ptrdiff_t m_iPlayerState = 0x13D4;
    }

    // ============================================
    // Context: CSWeaponCategory
    // ============================================
    namespace CSWeaponCategory
    {
        constexpr  ptrdiff_t m_WeaponCategory = 0x524;
    }

    // ============================================
    // Context: CSWeaponMode
    // ============================================
    namespace CSWeaponMode
    {
        constexpr  ptrdiff_t m_weaponMode = 0x17B8;
    }

    // ============================================
    // Context: CSWeaponSilencerType
    // ============================================
    namespace CSWeaponSilencerType
    {
        constexpr  ptrdiff_t m_eSilencerType = 0x728;
    }

    // ============================================
    // Context: CSWeaponType
    // ============================================
    namespace CSWeaponType
    {
        constexpr  ptrdiff_t m_WeaponType = 0x520;
    }

    // ============================================
    // Context: CScriptComponent
    // ============================================
    namespace CScriptComponent
    {
        constexpr  ptrdiff_t m_CScriptComponent = 0x28;
    }

    // ============================================
    // Context: CSkeletonInstance
    // ============================================
    namespace CSkeletonInstance
    {
        constexpr  ptrdiff_t m_skeletonInstance = 0x80;
    }

    // ============================================
    // Context: CSkillFloat
    // ============================================
    namespace CSkillFloat
    {
        constexpr  ptrdiff_t m_flHeadDamageMultiplier = 0x1E8;
        constexpr  ptrdiff_t m_flChestDamageMultiplier = 0x1F8;
        constexpr  ptrdiff_t m_flStomachDamageMultiplier = 0x208;
        constexpr  ptrdiff_t m_flArmDamageMultiplier = 0x218;
        constexpr  ptrdiff_t m_flLegDamageMultiplier = 0x228;
    }

    // ============================================
    // Context: CSoundEventName
    // ============================================
    namespace CSoundEventName
    {
        constexpr  ptrdiff_t m_SoundName = 0x0;
    }

    // ============================================
    // Context: CSoundPatch
    // ============================================
    namespace CSoundPatch
    {
        constexpr  ptrdiff_t m_sndCommentary = 0x11A8;
    }

    // ============================================
    // Context: CSplitScreenSlot
    // ============================================
    namespace CSplitScreenSlot
    {
        constexpr  ptrdiff_t m_nSplitScreenSlot = 0x6C8;
    }

    // ============================================
    // Context: CStrongHandle
    // ============================================
    namespace CStrongHandle
    {
        constexpr  ptrdiff_t m_hSkyMaterial = 0x630;
        constexpr  ptrdiff_t m_hFogCubemapTexture = 0x6F0;
        constexpr  ptrdiff_t m_hTextureOverride = 0x1568;
        constexpr  ptrdiff_t m_hLightCookie = 0x1098;
        constexpr  ptrdiff_t m_hPostSettings = 0x1088;
        constexpr  ptrdiff_t m_hFogIndirectTexture = 0x678;
        constexpr  ptrdiff_t m_hGraphDefinitionAG2 = 0x370;
        constexpr  ptrdiff_t m_iEffectIndex = 0x648;
        constexpr  ptrdiff_t m_hMaterialBase = 0x10;
        constexpr  ptrdiff_t m_hMaterialDamageOverlay = 0x18;
        constexpr  ptrdiff_t m_hSkyMaterialLightingOnly = 0xFB0;
        constexpr  ptrdiff_t m_iRopeMaterialModelIndex = 0xFF0;
        constexpr  ptrdiff_t m_hMaterial = 0x1298;
        constexpr  ptrdiff_t m_Entity_hCubemapTexture = 0x1680;
        constexpr  ptrdiff_t m_Entity_hLightProbeTexture_AmbientCube = 0x1690;
        constexpr  ptrdiff_t m_Entity_hLightProbeTexture_SDF = 0x1698;
        constexpr  ptrdiff_t m_Entity_hLightProbeTexture_SH2_DC = 0x16A0;
        constexpr  ptrdiff_t m_Entity_hLightProbeTexture_SH2_R = 0x16A8;
        constexpr  ptrdiff_t m_Entity_hLightProbeTexture_SH2_G = 0x16B0;
        constexpr  ptrdiff_t m_Entity_hLightProbeTexture_SH2_B = 0x16B8;
        constexpr  ptrdiff_t m_Entity_hLightProbeDirectLightIndicesTexture = 0x16C0;
        constexpr  ptrdiff_t m_Entity_hLightProbeDirectLightScalarsTexture = 0x16C8;
        constexpr  ptrdiff_t m_Entity_hLightProbeDirectLightShadowsTexture = 0x16D0;
        constexpr  ptrdiff_t m_hInfernoPointsSnapshot = 0xFF0;
        constexpr  ptrdiff_t m_hInfernoFillerPointsSnapshot = 0xFF8;
        constexpr  ptrdiff_t m_hInfernoOutlinePointsSnapshot = 0x1000;
        constexpr  ptrdiff_t m_hInfernoClimbingOutlinePointsSnapshot = 0x1008;
        constexpr  ptrdiff_t m_hInfernoDecalsSnapshot = 0x1010;
        constexpr  ptrdiff_t m_hModel = 0xA0;
        constexpr  ptrdiff_t m_hPositionKeys = 0xFB0;
        constexpr  ptrdiff_t m_hRotationKeys = 0xFB8;
        constexpr  ptrdiff_t m_hBlackboardResource = 0x0;
        constexpr  ptrdiff_t m_nExplodeEffectIndex = 0x11C0;
        constexpr  ptrdiff_t m_hSnapshotTrajectoryParticleSnapshot = 0x11F8;
        constexpr  ptrdiff_t m_hGradientFogTexture = 0x600;
        constexpr  ptrdiff_t m_hDecalMaterial = 0xFA8;
        constexpr  ptrdiff_t m_hBaseMaterial = 0xFE0;
        constexpr  ptrdiff_t m_nHaloIndex = 0xFE8;
        constexpr  ptrdiff_t m_hSpriteMaterial = 0xFA8;
        constexpr  ptrdiff_t m_FlashlightTexture = 0x60;
        constexpr  ptrdiff_t m_MuzzleFlashTexture = 0x68;
    }

    // ============================================
    // Context: CTransform
    // ============================================
    namespace CTransform
    {
        constexpr  ptrdiff_t m_xWSPrevParent = 0x630;
        constexpr  ptrdiff_t m_mPreferredCatchTransform = 0x1170;
        constexpr  ptrdiff_t m_xInitialPathWorldToLocal = 0x730;
        constexpr  ptrdiff_t m_anchorDeltaTransform = 0xFF0;
    }

    // ============================================
    // Context: CTransformWS
    // ============================================
    namespace CTransformWS
    {
        constexpr  ptrdiff_t m_nodeToWorld = 0x10;
    }

    // ============================================
    // Context: CUtlBinaryBlock
    // ============================================
    namespace CUtlBinaryBlock
    {
        constexpr  ptrdiff_t m_topology = 0x30;
    }

    // ============================================
    // Context: CUtlLeanVector
    // ============================================
    namespace CUtlLeanVector
    {
        constexpr  ptrdiff_t m_Args = 0xB8;
        constexpr  ptrdiff_t m_ExpectedArgs = 0x60;
    }

    // ============================================
    // Context: CUtlOrderedMap
    // ============================================
    namespace CUtlOrderedMap
    {
        constexpr  ptrdiff_t m_bodyGroupChoices = 0xE48;
        constexpr  ptrdiff_t m_aShootSounds = 0x4F8;
    }

    // ============================================
    // Context: CUtlString
    // ============================================
    namespace CUtlString
    {
        constexpr  ptrdiff_t m_SequenceName = 0x48;
        constexpr  ptrdiff_t m_LightStyleString = 0xFE0;
        constexpr  ptrdiff_t m_sClassName = 0x0;
        constexpr  ptrdiff_t m_strBreakableContentsPropGroupOverride = 0x1268;
        constexpr  ptrdiff_t m_strBreakableContentsParticleOverride = 0x1270;
        constexpr  ptrdiff_t m_szModifier = 0x120;
        constexpr  ptrdiff_t m_Input = 0x48;
        constexpr  ptrdiff_t m_strParentPathUniqueID = 0x618;
        constexpr  ptrdiff_t m_strPathNodeParameter = 0x620;
        constexpr  ptrdiff_t m_sUniqueHammerID = 0x5F0;
        constexpr  ptrdiff_t m_szUseRadioSubtitle = 0x7F0;
        constexpr  ptrdiff_t m_sSanitizedPlayerName = 0x860;
        constexpr  ptrdiff_t m_defaultAnim = 0x1158;
        constexpr  ptrdiff_t m_sInitialWeaponState = 0x1168;
        constexpr  ptrdiff_t m_targetCamera = 0xFA8;
        constexpr  ptrdiff_t m_brushModelName = 0xFB8;
        constexpr  ptrdiff_t m_sWeaponName = 0x610;
        constexpr  ptrdiff_t m_Pattern = 0xD8;
        constexpr  ptrdiff_t m_Description = 0x90;
        constexpr  ptrdiff_t m_szPlayerDamagerName = 0x40;
        constexpr  ptrdiff_t m_szPlayerRecipientName = 0x48;
        constexpr  ptrdiff_t m_strNametagString = 0x1160;
        constexpr  ptrdiff_t m_sRoundEndFunFactToken = 0xF18;
        constexpr  ptrdiff_t m_sRoundEndMessage = 0xF30;
        constexpr  ptrdiff_t m_strGraphName = 0x608;
        constexpr  ptrdiff_t m_strStateBlob = 0x610;
        constexpr  ptrdiff_t m_pathString = 0x700;
        constexpr  ptrdiff_t m_ExplosionSound = 0x1178;
        constexpr  ptrdiff_t m_sDMBonusWeapon = 0x38;
        constexpr  ptrdiff_t m_cameraName = 0x600;
        constexpr  ptrdiff_t m_szMuzzleFlashParticleConfig = 0x3D0;
        constexpr  ptrdiff_t m_strBitmapName = 0x0;
        constexpr  ptrdiff_t m_strAttrName = 0xE8;
        constexpr  ptrdiff_t m_strAlias = 0xF0;
        constexpr  ptrdiff_t m_strAttrNameForVar = 0x110;
        constexpr  ptrdiff_t m_strName = 0x0;
        constexpr  ptrdiff_t m_strExposedFriendlyName = 0x10;
        constexpr  ptrdiff_t m_strExposedFriendlyGroupName = 0x18;
        constexpr  ptrdiff_t m_strExposedVisibleWhenTrue = 0x28;
        constexpr  ptrdiff_t m_strExposedHiddenWhenTrue = 0x30;
        constexpr  ptrdiff_t m_strExposedValueList = 0x38;
        constexpr  ptrdiff_t m_strTextureContentAssetPath = 0x178;
        constexpr  ptrdiff_t m_strTextureCompilationVtexTemplate = 0x260;
        constexpr  ptrdiff_t m_strString = 0x270;
        constexpr  ptrdiff_t m_strPanoramaPanelPath = 0x278;
        constexpr  ptrdiff_t map_name = 0x0;
        constexpr  ptrdiff_t pose_sequence = 0x18;
        constexpr  ptrdiff_t name = 0x8;
        constexpr  ptrdiff_t m_strMutatorConditionContainerName = 0x8;
        constexpr  ptrdiff_t m_strMutatorConditionContainerVarName = 0x10;
        constexpr  ptrdiff_t m_strMutatorConditionContainerVarValue = 0x18;
        constexpr  ptrdiff_t m_strInitWith_Container = 0x8;
        constexpr  ptrdiff_t m_strCopyProperty_InputContainerSrc = 0x10;
        constexpr  ptrdiff_t m_strCopyProperty_InputContainerProperty = 0x18;
        constexpr  ptrdiff_t m_strCopyProperty_TargetProperty = 0x20;
        constexpr  ptrdiff_t m_strRandomRollInputVars_SeedInputVar = 0x28;
        constexpr  ptrdiff_t m_strCopyMatchingKeys_InputContainerSrc = 0x48;
        constexpr  ptrdiff_t m_strCopyKeysWithSuffix_InputContainerSrc = 0x50;
        constexpr  ptrdiff_t m_strCopyKeysWithSuffix_FindSuffix = 0x58;
        constexpr  ptrdiff_t m_strCopyKeysWithSuffix_ReplaceSuffix = 0x60;
        constexpr  ptrdiff_t m_strGenerateTexture_TargetParam = 0x2F0;
        constexpr  ptrdiff_t m_strGenerateTexture_InitialContainer = 0x2F8;
        constexpr  ptrdiff_t m_strCompressionFormat = 0x308;
        constexpr  ptrdiff_t m_strPopInputQueue_Container = 0x348;
        constexpr  ptrdiff_t m_strDrawText_InputContainerSrc = 0x350;
        constexpr  ptrdiff_t m_strDrawText_InputContainerProperty = 0x358;
        constexpr  ptrdiff_t m_strDrawText_Font = 0x370;
        constexpr  ptrdiff_t m_strMatchFilter = 0x8;
        constexpr  ptrdiff_t m_strMatchValue = 0x10;
    }

    // ============================================
    // Context: CUtlStringToken
    // ============================================
    namespace CUtlStringToken
    {
        constexpr  ptrdiff_t m_skyboxSlotToken = 0x690;
        constexpr  ptrdiff_t m_nFluidType = 0x18;
        constexpr  ptrdiff_t m_SurfacePropStringToken = 0x78;
        constexpr  ptrdiff_t m_name = 0x10C;
        constexpr  ptrdiff_t m_hierarchyAttachName = 0x120;
        constexpr  ptrdiff_t m_tokLayerMatchID = 0x37C;
        constexpr  ptrdiff_t m_nSubclassID = 0x380;
        constexpr  ptrdiff_t m_materialGroup = 0x3C4;
        constexpr  ptrdiff_t m_surfaceProps = 0x270;
        constexpr  ptrdiff_t m_ID = 0x30;
        constexpr  ptrdiff_t m_nSurfaceProp = 0x4C;
        constexpr  ptrdiff_t m_nAttachmentName = 0x68;
    }

    // ============================================
    // Context: CUtlSymbolLarge
    // ============================================
    namespace CUtlSymbolLarge
    {
        constexpr  ptrdiff_t m_iszStackName = 0x600;
        constexpr  ptrdiff_t m_iszOperatorName = 0x608;
        constexpr  ptrdiff_t m_iszOpvarName = 0x610;
        constexpr  ptrdiff_t m_iszSkyEntity = 0x638;
        constexpr  ptrdiff_t m_DistanceFogCurveString = 0x650;
        constexpr  ptrdiff_t m_HeightFogCurveString = 0x658;
        constexpr  ptrdiff_t m_EffectName = 0xFB0;
        constexpr  ptrdiff_t m_FanForceCurveString = 0x650;
        constexpr  ptrdiff_t m_explosionBuildupSound = 0x1298;
        constexpr  ptrdiff_t m_explosionCustomEffect = 0x12A0;
        constexpr  ptrdiff_t m_explosionCustomSound = 0x12A8;
        constexpr  ptrdiff_t m_explosionModifier = 0x12B0;
        constexpr  ptrdiff_t m_szDisplayText = 0xFB0;
        constexpr  ptrdiff_t m_iFilterName = 0x640;
        constexpr  ptrdiff_t m_soundEventName = 0x620;
        constexpr  ptrdiff_t m_positionNames = 0x638;
        constexpr  ptrdiff_t m_soundscapeName = 0x680;
        constexpr  ptrdiff_t m_iszEffectName = 0x610;
        constexpr  ptrdiff_t m_iszCommentaryFile = 0x1180;
        constexpr  ptrdiff_t m_iszTitle = 0x1188;
        constexpr  ptrdiff_t m_iszSpeakers = 0x1190;
        constexpr  ptrdiff_t m_iszSoundAreaType = 0x610;
        constexpr  ptrdiff_t iAttribHook = 0x8;
        constexpr  ptrdiff_t m_iszPrivateVScripts = 0x8;
        constexpr  ptrdiff_t m_Name = 0x38;
        constexpr  ptrdiff_t m_MainSoundscapeName = 0x690;
        constexpr  ptrdiff_t m_iszSourceEntityName = 0x610;
        constexpr  ptrdiff_t m_iszAttachmentName = 0x618;
        constexpr  ptrdiff_t m_iszSoundName = 0x698;
        constexpr  ptrdiff_t m_DialogXMLName = 0xFB8;
        constexpr  ptrdiff_t m_PanelClassName = 0xFC0;
        constexpr  ptrdiff_t m_PanelID = 0xFC8;
        constexpr  ptrdiff_t m_szPanelType = 0x610;
        constexpr  ptrdiff_t m_szLayoutFileName = 0x618;
        constexpr  ptrdiff_t m_RenderAttrName = 0x620;
        constexpr  ptrdiff_t m_szTargetsName = 0x660;
        constexpr  ptrdiff_t m_sAttributeName = 0x638;
        constexpr  ptrdiff_t m_iszWorldName = 0x600;
        constexpr  ptrdiff_t m_iszSource2EntityLumpName = 0x608;
        constexpr  ptrdiff_t m_iszEntityFilterName = 0x610;
        constexpr  ptrdiff_t m_szCrosshairCodes = 0x838;
        constexpr  ptrdiff_t m_szClan = 0x858;
        constexpr  ptrdiff_t m_iszPhysicsDamageTableName = 0x20;
        constexpr  ptrdiff_t m_iszBasePropData = 0x28;
        constexpr  ptrdiff_t m_iszSpawnTargetName = 0x600;
        constexpr  ptrdiff_t m_iszParameterName = 0x6D0;
        constexpr  ptrdiff_t m_ModelName = 0xA8;
        constexpr  ptrdiff_t m_scriptClassName = 0x30;
        constexpr  ptrdiff_t m_iszIdleAnim = 0x1350;
        constexpr  ptrdiff_t m_worldName = 0x618;
        constexpr  ptrdiff_t m_layerName = 0x620;
        constexpr  ptrdiff_t m_iszControlPointNames = 0x1308;
        constexpr  ptrdiff_t m_source = 0x1078;
        constexpr  ptrdiff_t m_destination = 0x1080;
        constexpr  ptrdiff_t m_iFilterModel = 0x638;
        constexpr  ptrdiff_t m_szParentPathUniqueID = 0x600;
        constexpr  ptrdiff_t m_iFilterClass = 0x638;
        constexpr  ptrdiff_t m_iszBounceSound = 0x1170;
        constexpr  ptrdiff_t m_name = 0x18;
        constexpr  ptrdiff_t m_designerName = 0x20;
        constexpr  ptrdiff_t m_strSceneVDataName = 0x610;
        constexpr  ptrdiff_t m_strPulseVDataName = 0x618;
        constexpr  ptrdiff_t m_strLocalInterestReqTags = 0x648;
        constexpr  ptrdiff_t m_strLocalInterestOptTags = 0x650;
        constexpr  ptrdiff_t m_strLookTarget = 0x658;
    }

    // ============================================
    // Context: CUtlVector
    // ============================================
    namespace CUtlVector
    {
        constexpr  ptrdiff_t m_vecNetworkableLoadout = 0x40;
        constexpr  ptrdiff_t m_Chunks = 0x50;
        constexpr  ptrdiff_t m_Cells = 0x68;
        constexpr  ptrdiff_t m_Vars = 0x80;
        constexpr  ptrdiff_t m_PublicOutputs = 0x98;
        constexpr  ptrdiff_t m_InvokeBindings = 0xB0;
        constexpr  ptrdiff_t m_CallInfos = 0xC8;
        constexpr  ptrdiff_t m_Constants = 0xE0;
        constexpr  ptrdiff_t m_DomainValues = 0xF8;
        constexpr  ptrdiff_t m_BlackboardReferences = 0x110;
        constexpr  ptrdiff_t m_OutputConnections = 0x128;
        constexpr  ptrdiff_t m_vecExternalGraphs = 0x660;
        constexpr  ptrdiff_t m_vecFractionOfWheelSubmergedForWheelFriction = 0x30;
        constexpr  ptrdiff_t m_vecWheelFrictionScales = 0x48;
        constexpr  ptrdiff_t m_vecFractionOfWheelSubmergedForWheelDrag = 0x60;
        constexpr  ptrdiff_t m_vecWheelDrag = 0x78;
        constexpr  ptrdiff_t m_Outflows = 0x48;
        constexpr  ptrdiff_t m_RequirementNodeIDs = 0x50;
        constexpr  ptrdiff_t m_nCursorStateBlockIndex = 0x68;
        constexpr  ptrdiff_t m_PathNodes_Name = 0x618;
        constexpr  ptrdiff_t m_Dismounts = 0xFB8;
        constexpr  ptrdiff_t m_vecBulletHitModels = 0x1C18;
        constexpr  ptrdiff_t m_aThinkFunctions = 0x398;
        constexpr  ptrdiff_t m_dependencies = 0x5B8;
        constexpr  ptrdiff_t m_AdditionalTargetEntities = 0x668;
        constexpr  ptrdiff_t m_Providers = 0x8;
        constexpr  ptrdiff_t m_CachedResults = 0x30;
        constexpr  ptrdiff_t m_TimelineEvents = 0x48;
        constexpr  ptrdiff_t m_createdSpawnGroupHandles = 0x628;
        constexpr  ptrdiff_t m_SpawnedEntityHandles = 0x640;
        constexpr  ptrdiff_t m_vecDamageTakenByHitGroup = 0x48;
        constexpr  ptrdiff_t m_Outputs = 0x48;
        constexpr  ptrdiff_t m_hTouchingEntities = 0x1050;
        constexpr  ptrdiff_t m_QueuedEvents = 0x648;
        constexpr  ptrdiff_t m_vecAttachedParticles = 0x1670;
        constexpr  ptrdiff_t m_vecAttachedModels = 0x16B0;
        constexpr  ptrdiff_t m_arrTrajectoryTrailPoints = 0x1200;
        constexpr  ptrdiff_t m_arrTrajectoryTrailPointCreationTimes = 0x1218;
        constexpr  ptrdiff_t m_aAttachedObjectsFromServer = 0x1158;
        constexpr  ptrdiff_t m_aAttachedObjects = 0x1170;
        constexpr  ptrdiff_t m_parentPhysicsBoneIndices = 0x11B0;
        constexpr  ptrdiff_t m_worldSpaceBoneComputationOrder = 0x11C8;
        constexpr  ptrdiff_t m_DependentObservableVars = 0x48;
        constexpr  ptrdiff_t m_DependentObservableBlackboardReferences = 0x60;
        constexpr  ptrdiff_t m_hSplitScreenPlayers = 0x6D0;
        constexpr  ptrdiff_t m_vecLooseVariables = 0xF8;
        constexpr  ptrdiff_t m_vecCompMatIncludes = 0x0;
        constexpr  ptrdiff_t m_vecMatchFilters = 0x18;
        constexpr  ptrdiff_t m_vecCompositeInputContainers = 0x30;
        constexpr  ptrdiff_t m_vecPropertyMutators = 0x48;
        constexpr  ptrdiff_t m_vecCompositeMaterialAssemblyProcedures = 0x1E0;
        constexpr  ptrdiff_t m_vecCompositeMaterials = 0x1F8;
        constexpr  ptrdiff_t m_vecRandomRollInputVars_InputVarsToRoll = 0x30;
        constexpr  ptrdiff_t m_vecTexGenInstructions = 0x318;
        constexpr  ptrdiff_t m_vecConditionalMutators = 0x330;
        constexpr  ptrdiff_t m_vecConditions = 0x378;
        constexpr  ptrdiff_t m_Points = 0x10;
        constexpr  ptrdiff_t m_vecGeneratedTextures = 0x80;
    }

    // ============================================
    // Context: CUtlVectorFixedGrowable
    // ============================================
    namespace CUtlVectorFixedGrowable
    {
        constexpr  ptrdiff_t m_Shuffle = 0x0;
    }

    // ============================================
    // Context: CWeakHandle
    // ============================================
    namespace CWeakHandle
    {
        constexpr  ptrdiff_t m_nEffectIndex = 0x50;
    }

    // ============================================
    // Context: C_AttributeContainer
    // ============================================
    namespace C_AttributeContainer
    {
        constexpr  ptrdiff_t m_AttributeManager = 0x13B8;
    }

    // ============================================
    // Context: C_BaseCombatCharacter__WaterWakeMode_t
    // ============================================
    namespace C_BaseCombatCharacter__WaterWakeMode_t
    {
        constexpr  ptrdiff_t m_nWaterWakeMode = 0x1174;
    }

    // ============================================
    // Context: C_CSGameRules
    // ============================================
    namespace C_CSGameRules
    {
        constexpr  ptrdiff_t m_pGameRules = 0x600;
    }

    // ============================================
    // Context: C_CommandContext
    // ============================================
    namespace C_CommandContext
    {
        constexpr  ptrdiff_t m_CommandContext = 0x608;
    }

    // ============================================
    // Context: C_EconItemView
    // ============================================
    namespace C_EconItemView
    {
        constexpr  ptrdiff_t m_Item = 0x50;
        constexpr  ptrdiff_t m_EconGloves = 0x1658;
        constexpr  ptrdiff_t m_agentItem = 0x620;
        constexpr  ptrdiff_t m_glovesItem = 0xA90;
        constexpr  ptrdiff_t m_weaponItem = 0xF00;
        constexpr  ptrdiff_t pItem = 0x0;
    }

    // ============================================
    // Context: C_EnvWindShared
    // ============================================
    namespace C_EnvWindShared
    {
        constexpr  ptrdiff_t m_EnvWindShared = 0x600;
    }

    // ============================================
    // Context: C_IronSightController
    // ============================================
    namespace C_IronSightController
    {
        constexpr  ptrdiff_t m_IronSightController = 0x1960;
    }

    // ============================================
    // Context: C_NetworkUtlVectorBase
    // ============================================
    namespace C_NetworkUtlVectorBase
    {
        constexpr  ptrdiff_t m_QueuedLightStyleStrings = 0xFF0;
        constexpr  ptrdiff_t m_LightStyleEvents = 0x1008;
        constexpr  ptrdiff_t m_LightStyleTargets = 0x1020;
        constexpr  ptrdiff_t m_VisClusters = 0x1298;
        constexpr  ptrdiff_t m_aPlayerControllers = 0x600;
        constexpr  ptrdiff_t m_aPlayers = 0x618;
        constexpr  ptrdiff_t m_vecSecondarySkeletonSlotIDs = 0x20;
        constexpr  ptrdiff_t m_vecSecondarySkeletons = 0x38;
        constexpr  ptrdiff_t m_SerializePoseRecipeAG2Dynamic = 0x3E0;
        constexpr  ptrdiff_t m_vecExternalGraphIds = 0x410;
        constexpr  ptrdiff_t m_vecExternalClipIds = 0x428;
        constexpr  ptrdiff_t m_vecCornerPairsNetworked = 0x6C0;
        constexpr  ptrdiff_t m_PathNodes_Position = 0x650;
        constexpr  ptrdiff_t m_PathNodes_TangentIn = 0x668;
        constexpr  ptrdiff_t m_PathNodes_TangentOut = 0x680;
        constexpr  ptrdiff_t m_PathNodes_Color = 0x698;
        constexpr  ptrdiff_t m_PathNodes_PinEnabled = 0x6B0;
        constexpr  ptrdiff_t m_PathNodes_RadiusScale = 0x6C8;
        constexpr  ptrdiff_t m_vecCSSClasses = 0x1188;
        constexpr  ptrdiff_t m_vecPanelVertices = 0x40;
        constexpr  ptrdiff_t m_vInitialPanelVertices = 0x58;
        constexpr  ptrdiff_t m_AssociatedEntities = 0x40;
        constexpr  ptrdiff_t m_AssociatedEntityNames = 0x58;
        constexpr  ptrdiff_t m_TargetEntities = 0x628;
        constexpr  ptrdiff_t m_PostProcessingVolumes = 0x128;
        constexpr  ptrdiff_t m_Transforms = 0x8;
        constexpr  ptrdiff_t m_nBodyGroupChoices = 0x218;
        constexpr  ptrdiff_t m_WeaponSequence = 0x30;
        constexpr  ptrdiff_t m_VoxelFrameData = 0x1278;
        constexpr  ptrdiff_t m_hMyWearables = 0x1158;
        constexpr  ptrdiff_t m_hActorList = 0x620;
        constexpr  ptrdiff_t m_hOutputEntities = 0x628;
        constexpr  ptrdiff_t m_hConveyorModels = 0xFD0;
        constexpr  ptrdiff_t m_networkAnimTiming = 0x1588;
        constexpr  ptrdiff_t m_ragEnabled = 0x1158;
        constexpr  ptrdiff_t m_ragPos = 0x1170;
        constexpr  ptrdiff_t m_ragAngles = 0x1188;
        constexpr  ptrdiff_t m_hMyWeapons = 0x48;
        constexpr  ptrdiff_t m_vecPathNodes = 0x710;
    }

    // ============================================
    // Context: C_PointCamera
    // ============================================
    namespace C_PointCamera
    {
        constexpr  ptrdiff_t m_pNext = 0x658;
    }

    // ============================================
    // Context: C_PointClientUIWorldPanel
    // ============================================
    namespace C_PointClientUIWorldPanel
    {
        constexpr  ptrdiff_t m_pTargetPanel = 0x1208;
    }

    // ============================================
    // Context: C_RetakeGameRules
    // ============================================
    namespace C_RetakeGameRules
    {
        constexpr  ptrdiff_t m_RetakeRules = 0xDA0;
    }

    // ============================================
    // Context: C_RopeKeyframe
    // ============================================
    namespace C_RopeKeyframe
    {
        constexpr  ptrdiff_t m_pKeyframe = 0x8;
    }

    // ============================================
    // Context: C_RopeKeyframe__CPhysicsDelegate
    // ============================================
    namespace C_RopeKeyframe__CPhysicsDelegate
    {
        constexpr  ptrdiff_t m_PhysicsDelegate = 0x1288;
    }

    // ============================================
    // Context: C_SkyCamera
    // ============================================
    namespace C_SkyCamera
    {
        constexpr  ptrdiff_t m_pNext = 0x698;
    }

    // ============================================
    // Context: C_UtlVectorEmbeddedNetworkVar
    // ============================================
    namespace C_UtlVectorEmbeddedNetworkVar
    {
        constexpr  ptrdiff_t m_vecServerAuthoritativeWeaponSlots = 0x88;
        constexpr  ptrdiff_t m_SerializePoseRecipeAG2Slots = 0x378;
        constexpr  ptrdiff_t m_vecRenderAttributes = 0xCA0;
        constexpr  ptrdiff_t m_ServerViewAngleChanges = 0x1230;
        constexpr  ptrdiff_t m_DamageList = 0x48;
        constexpr  ptrdiff_t m_perRoundStats = 0x40;
        constexpr  ptrdiff_t m_vecSellbackPurchaseEntries = 0x48;
        constexpr  ptrdiff_t m_Attributes = 0x8;
        constexpr  ptrdiff_t m_weaponPurchases = 0x8;
    }

    // ============================================
    // Context: C_fogplayerparams_t
    // ============================================
    namespace C_fogplayerparams_t
    {
        constexpr  ptrdiff_t m_PlayerFog = 0x60;
    }

    // ============================================
    // Context: ChangeAccessorFieldPathIndex_t
    // ============================================
    namespace ChangeAccessorFieldPathIndex_t
    {
        constexpr  ptrdiff_t m_PathIndex = 0x40;
    }

    // ============================================
    // Context: Color
    // ============================================
    namespace Color
    {
        constexpr  ptrdiff_t m_ColorTint = 0x1564;
        constexpr  ptrdiff_t m_TintColor = 0x640;
        constexpr  ptrdiff_t m_Color = 0xFB0;
        constexpr  ptrdiff_t m_GunGameImmunityColor = 0x1BC8;
        constexpr  ptrdiff_t m_OldColor = 0x10;
        constexpr  ptrdiff_t m_NewColor = 0x28;
        constexpr  ptrdiff_t m_vTintColor = 0xFB9;
        constexpr  ptrdiff_t m_vTintColorLightingOnly = 0xFBD;
        constexpr  ptrdiff_t m_clrRender = 0xC98;
        constexpr  ptrdiff_t m_ClientOverrideTint = 0xF58;
        constexpr  ptrdiff_t m_Entity_Color = 0x1678;
        constexpr  ptrdiff_t m_OverrideFogColor = 0x1B9;
        constexpr  ptrdiff_t m_glowColor = 0x1370;
        constexpr  ptrdiff_t m_clrTint = 0x151C;
        constexpr  ptrdiff_t m_SecondaryColor = 0x79;
        constexpr  ptrdiff_t m_SkyColor = 0x190;
        constexpr  ptrdiff_t m_SkyAmbientBounce = 0x198;
        constexpr  ptrdiff_t m_glowColorOverride = 0x40;
        constexpr  ptrdiff_t m_fogColor = 0x62C;
        constexpr  ptrdiff_t colorPrimary = 0x14;
        constexpr  ptrdiff_t colorSecondary = 0x18;
        constexpr  ptrdiff_t colorPrimaryLerpTo = 0x1C;
        constexpr  ptrdiff_t colorSecondaryLerpTo = 0x20;
        constexpr  ptrdiff_t m_FogColor = 0x609;
        constexpr  ptrdiff_t m_cValueColor4 = 0x8C;
        constexpr  ptrdiff_t m_colDrawText_Color = 0x368;
        constexpr  ptrdiff_t m_SpecularColor = 0x64;
        constexpr  ptrdiff_t m_LightColor = 0x6A;
        constexpr  ptrdiff_t m_AmbientColor1 = 0x6E;
        constexpr  ptrdiff_t m_AmbientColor2 = 0x72;
        constexpr  ptrdiff_t m_AmbientColor3 = 0x76;
    }

    // ============================================
    // Context: CompMatPropertyMutatorConditionType_t
    // ============================================
    namespace CompMatPropertyMutatorConditionType_t
    {
        constexpr  ptrdiff_t m_nMutatorCondition = 0x0;
    }

    // ============================================
    // Context: CompMatPropertyMutatorType_t
    // ============================================
    namespace CompMatPropertyMutatorType_t
    {
        constexpr  ptrdiff_t m_nMutatorCommandType = 0x4;
    }

    // ============================================
    // Context: CompositeMaterialInputContainerSourceType_t
    // ============================================
    namespace CompositeMaterialInputContainerSourceType_t
    {
        constexpr  ptrdiff_t m_nCompositeMaterialInputContainerSourceType = 0x4;
    }

    // ============================================
    // Context: CompositeMaterialInputLooseVariableType_t
    // ============================================
    namespace CompositeMaterialInputLooseVariableType_t
    {
        constexpr  ptrdiff_t m_nVariableType = 0x40;
    }

    // ============================================
    // Context: CompositeMaterialInputLooseVariable_t
    // ============================================
    namespace CompositeMaterialInputLooseVariable_t
    {
        constexpr  ptrdiff_t m_nSetValue_Value = 0x68;
    }

    // ============================================
    // Context: CompositeMaterialInputTextureType_t
    // ============================================
    namespace CompositeMaterialInputTextureType_t
    {
        constexpr  ptrdiff_t m_nTextureType = 0x268;
    }

    // ============================================
    // Context: CompositeMaterialMatchFilterType_t
    // ============================================
    namespace CompositeMaterialMatchFilterType_t
    {
        constexpr  ptrdiff_t m_nCompositeMaterialMatchFilterType = 0x0;
    }

    // ============================================
    // Context: CompositeMaterialVarSystemVar_t
    // ============================================
    namespace CompositeMaterialVarSystemVar_t
    {
        constexpr  ptrdiff_t m_nValueSystemVar = 0x90;
    }

    // ============================================
    // Context: CountdownTimer
    // ============================================
    namespace CountdownTimer
    {
        constexpr  ptrdiff_t m_RampTimer = 0x10C0;
        constexpr  ptrdiff_t m_wiggleTimer = 0x1190;
        constexpr  ptrdiff_t m_delayTargetIDTimer = 0x3400;
        constexpr  ptrdiff_t m_holdTargetIDTimer = 0x3420;
        constexpr  ptrdiff_t m_reuseTimer = 0x1200;
        constexpr  ptrdiff_t m_blinkTimer = 0x1258;
        constexpr  ptrdiff_t m_lookAroundTimer = 0x1280;
    }

    // ============================================
    // Context: DamageTypes_t
    // ============================================
    namespace DamageTypes_t
    {
        constexpr  ptrdiff_t m_nDamageType = 0x12F0;
    }

    // ============================================
    // Context: DecalRtEncoding_t
    // ============================================
    namespace DecalRtEncoding_t
    {
        constexpr  ptrdiff_t m_nRequiredDecalRtEncoding = 0xE45;
    }

    // ============================================
    // Context: DoorState_t
    // ============================================
    namespace DoorState_t
    {
        constexpr  ptrdiff_t m_eDoorState = 0x13B0;
    }

    // ============================================
    // Context: EKillTypes_t
    // ============================================
    namespace EKillTypes_t
    {
        constexpr  ptrdiff_t m_killType = 0x75;
    }

    // ============================================
    // Context: ENPCBehaviorOverride_t
    // ============================================
    namespace ENPCBehaviorOverride_t
    {
        constexpr  ptrdiff_t m_eNPCBehavior = 0x0;
    }

    // ============================================
    // Context: EntityDisolveType_t
    // ============================================
    namespace EntityDisolveType_t
    {
        constexpr  ptrdiff_t m_nDissolveType = 0xFD0;
    }

    // ============================================
    // Context: EntityPlatformTypes_t
    // ============================================
    namespace EntityPlatformTypes_t
    {
        constexpr  ptrdiff_t m_nPlatformType = 0x360;
    }

    // ============================================
    // Context: EntitySpottedState_t
    // ============================================
    namespace EntitySpottedState_t
    {
        constexpr  ptrdiff_t m_entitySpottedState = 0x1CC8;
    }

    // ============================================
    // Context: ExternalAnimGraphHandle_t
    // ============================================
    namespace ExternalAnimGraphHandle_t
    {
        constexpr  ptrdiff_t m_nNextExternalGraphHandle = 0x1C;
    }

    // ============================================
    // Context: FixAngleSet_t
    // ============================================
    namespace FixAngleSet_t
    {
        constexpr  ptrdiff_t nType = 0x30;
    }

    // ============================================
    // Context: GameTick_t
    // ============================================
    namespace GameTick_t
    {
        constexpr  ptrdiff_t m_nLastActualJumpPressTick = 0x10;
        constexpr  ptrdiff_t m_nLastUsableJumpPressTick = 0x18;
        constexpr  ptrdiff_t m_nLastLandedTick = 0x20;
        constexpr  ptrdiff_t m_nPrevAnimUpdateTick = 0xD4;
        constexpr  ptrdiff_t m_nPostponeFireReadyTicks = 0x17EC;
        constexpr  ptrdiff_t m_nDeployTick = 0x17F8;
        constexpr  ptrdiff_t m_nDropTick = 0x18D4;
        constexpr  ptrdiff_t m_nNextPrimaryAttackTick = 0x16C8;
        constexpr  ptrdiff_t m_nNextSecondaryAttackTick = 0x16D0;
        constexpr  ptrdiff_t m_nLastThinkTick = 0x328;
        constexpr  ptrdiff_t m_nNextThinkTick = 0x3F0;
        constexpr  ptrdiff_t m_nCsViewPunchAngleTick = 0x54;
        constexpr  ptrdiff_t m_nNextHoldTick = 0x1D44;
        constexpr  ptrdiff_t m_nLastJumpTick = 0x708;
        constexpr  ptrdiff_t m_predictableBaseTick = 0x48;
        constexpr  ptrdiff_t m_unpredictableBaseTick = 0xA0;
        constexpr  ptrdiff_t m_nTransitionStartTick = 0xFC0;
    }

    // ============================================
    // Context: GameTime_t
    // ============================================
    namespace GameTime_t
    {
        constexpr  ptrdiff_t m_flStartTime = 0x8;
        constexpr  ptrdiff_t m_flLightStyleStartTime = 0xFE8;
        constexpr  ptrdiff_t m_fArmedTime = 0x1CBC;
        constexpr  ptrdiff_t m_flLastSpawnTimeIndex = 0x13DC;
        constexpr  ptrdiff_t m_flClientDeathTime = 0x13E8;
        constexpr  ptrdiff_t m_flClientHealthFadeChangeTimestamp = 0x1404;
        constexpr  ptrdiff_t m_flPreventDamageBeforeTime = 0x125C;
        constexpr  ptrdiff_t m_flLastPhysicsInfluenceTime = 0x12BC;
        constexpr  ptrdiff_t m_flSeqStartTime = 0x4;
        constexpr  ptrdiff_t m_flStartAnisoTime = 0x650;
        constexpr  ptrdiff_t m_flStartScatterTime = 0x654;
        constexpr  ptrdiff_t m_flStartDrawDistanceTime = 0x658;
        constexpr  ptrdiff_t m_LastEnterTime = 0x107C;
        constexpr  ptrdiff_t m_LastExitTime = 0x1084;
        constexpr  ptrdiff_t m_StartTime = 0x0;
        constexpr  ptrdiff_t m_EndTime = 0x4;
        constexpr  ptrdiff_t m_timestamp = 0x8;
        constexpr  ptrdiff_t m_flTimeParticleEffectSpawn = 0x1260;
        constexpr  ptrdiff_t m_flWeaponGameplayAnimStateTimestamp = 0x175C;
        constexpr  ptrdiff_t m_flInspectCancelCompleteTime = 0x1760;
        constexpr  ptrdiff_t m_flLastAccuracyUpdateTime = 0x17D4;
        constexpr  ptrdiff_t m_flLastBurstModeChangeTime = 0x17E8;
        constexpr  ptrdiff_t m_flDroppedAtTime = 0x17FC;
        constexpr  ptrdiff_t m_flTimeSilencerSwitchComplete = 0x1808;
        constexpr  ptrdiff_t m_nextPrevOwnerUseTime = 0x18CC;
        constexpr  ptrdiff_t m_fLastShotTime = 0x1900;
        constexpr  ptrdiff_t m_flLastLOSTraceFailureTime = 0x1A88;
        constexpr  ptrdiff_t m_flLastShakeTime = 0x1AFC;
        constexpr  ptrdiff_t m_flEndTime = 0x1174;
        constexpr  ptrdiff_t m_flFOVTime = 0x298;
        constexpr  ptrdiff_t m_flHealthShotBoostExpirationTime = 0x14A0;
        constexpr  ptrdiff_t m_flLastFiredWeaponTime = 0x14A4;
        constexpr  ptrdiff_t m_flTimeOfLastInjury = 0x14E4;
        constexpr  ptrdiff_t m_flNextSprayDecalTime = 0x14E8;
        constexpr  ptrdiff_t m_lastLandTime = 0x1B38;
        constexpr  ptrdiff_t m_fSwitchedHandednessTime = 0x1B6C;
        constexpr  ptrdiff_t m_flEmitSoundTime = 0x1C58;
        constexpr  ptrdiff_t m_grenadeParameterStashTime = 0x1CD0;
        constexpr  ptrdiff_t m_fImmuneToGunGameDamageTime = 0x3234;
        constexpr  ptrdiff_t m_fImmuneToGunGameDamageTimeLast = 0x323C;
        constexpr  ptrdiff_t m_arrOldEyeAnglesTimes = 0x33B0;
        constexpr  ptrdiff_t m_fLastGrabTime = 0x1234;
        constexpr  ptrdiff_t m_flRescueStartTime = 0x1244;
        constexpr  ptrdiff_t m_flGrabSuccessTime = 0x1248;
        constexpr  ptrdiff_t m_flDropStartTime = 0x124C;
        constexpr  ptrdiff_t m_flDeadOrRescuedTime = 0x1250;
        constexpr  ptrdiff_t m_fNewestAlphaThinkTime = 0x12A8;
        constexpr  ptrdiff_t m_flObserverChaseDistanceCalcTime = 0x5C;
        constexpr  ptrdiff_t m_flCreateTime = 0x3E0;
        constexpr  ptrdiff_t m_flNavIgnoreUntilTime = 0x54C;
        constexpr  ptrdiff_t m_flDeathTime = 0x1348;
        constexpr  ptrdiff_t m_flPredictionErrorTime = 0x1358;
        constexpr  ptrdiff_t m_flLastCameraSetupTime = 0x1384;
        constexpr  ptrdiff_t m_fThrowTime = 0x1CB8;
        constexpr  ptrdiff_t m_fDropTime = 0x1D38;
        constexpr  ptrdiff_t m_fPinPullTime = 0x1D3C;
        constexpr  ptrdiff_t m_flForceTeamTime = 0x844;
        constexpr  ptrdiff_t m_flPreviousForceJoinTeamTime = 0x850;
        constexpr  ptrdiff_t m_fStashGrenadeParameterWhen = 0x684;
        constexpr  ptrdiff_t m_flLastGameTime = 0x61C;
        constexpr  ptrdiff_t m_flTouchDelta = 0x12D0;
        constexpr  ptrdiff_t m_fDeathTime = 0x12D4;
        constexpr  ptrdiff_t m_flNextSparkTime = 0xFCC;
        constexpr  ptrdiff_t m_flEffectTime = 0x115C;
        constexpr  ptrdiff_t m_gibDespawnTime = 0x1160;
        constexpr  ptrdiff_t m_flScaleTimeStart = 0x11A0;
        constexpr  ptrdiff_t m_flScaleTimeEnd = 0x11C8;
        constexpr  ptrdiff_t m_flPreviousUpdateTickTime = 0x668;
        constexpr  ptrdiff_t m_fWarmupPeriodEnd = 0x44;
        constexpr  ptrdiff_t m_fWarmupPeriodStart = 0x48;
        constexpr  ptrdiff_t m_fRoundStartTime = 0x70;
        constexpr  ptrdiff_t m_flRestartRoundTime = 0x74;
        constexpr  ptrdiff_t m_flCMMItemDropRevealStartTime = 0x8BC;
        constexpr  ptrdiff_t m_flCMMItemDropRevealEndTime = 0x8C0;
        constexpr  ptrdiff_t m_flNextRespawnWave = 0xBA0;
        constexpr  ptrdiff_t m_flSpawnTime = 0x11D8;
        constexpr  ptrdiff_t flNextTrailLineTime = 0x11E8;
        constexpr  ptrdiff_t m_flAllowResponsesEndTime = 0x6C;
        constexpr  ptrdiff_t lerptime = 0x50;
        constexpr  ptrdiff_t m_flFireTime = 0xFB0;
        constexpr  ptrdiff_t m_flNextAttack = 0xD0;
        constexpr  ptrdiff_t m_flNextGlow = 0x1188;
        constexpr  ptrdiff_t m_flNextBeep = 0x118C;
        constexpr  ptrdiff_t m_flC4Blow = 0x1190;
        constexpr  ptrdiff_t m_flDefuseCountDown = 0x11B0;
        constexpr  ptrdiff_t m_flNextRadarFlashTime = 0x1694;
        constexpr  ptrdiff_t m_fLastDefuseTime = 0x16A0;
        constexpr  ptrdiff_t die = 0x115C;
        constexpr  ptrdiff_t m_fFireTime = 0x1CE0;
        constexpr  ptrdiff_t m_flDetonateTime = 0x1160;
        constexpr  ptrdiff_t m_flDMBonusStartTime = 0x30;
        constexpr  ptrdiff_t m_flDieTime = 0xFC0;
        constexpr  ptrdiff_t m_flLastTime = 0xFEC;
        constexpr  ptrdiff_t m_flBrightnessTimeStart = 0x1008;
        constexpr  ptrdiff_t endtime = 0x0;
        constexpr  ptrdiff_t nextShake = 0x10;
        constexpr  ptrdiff_t m_flRenderFxStartTime = 0x1C;
    }

    // ============================================
    // Context: GrenadeType_t
    // ============================================
    namespace GrenadeType_t
    {
        constexpr  ptrdiff_t m_nType = 0xFC4;
    }

    // ============================================
    // Context: HSCRIPT
    // ============================================
    namespace HSCRIPT
    {
        constexpr  ptrdiff_t m_ScriptSpawnCallback = 0x658;
        constexpr  ptrdiff_t m_ScriptCallbackScope = 0x660;
    }

    // ============================================
    // Context: HSequence
    // ============================================
    namespace HSequence
    {
        constexpr  ptrdiff_t m_hSequence = 0x0;
    }

    // ============================================
    // Context: HitGroup_t
    // ============================================
    namespace HitGroup_t
    {
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed0 = 0xB18;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed1 = 0xB1C;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed2 = 0xB20;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed3 = 0xB24;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed4 = 0xB28;
    }

    // ============================================
    // Context: IPhysAggregateInstance
    // ============================================
    namespace IPhysAggregateInstance
    {
        constexpr  ptrdiff_t m_pVPhysicsAggregate = 0xE0;
    }

    // ============================================
    // Context: IPhysicsMotionController
    // ============================================
    namespace IPhysicsMotionController
    {
        constexpr  ptrdiff_t m_pController = 0x8;
    }

    // ============================================
    // Context: IPhysicsRagdollControl
    // ============================================
    namespace IPhysicsRagdollControl
    {
        constexpr  ptrdiff_t m_pRagdollControl = 0x10A0;
    }

    // ============================================
    // Context: InteractionPriority_t
    // ============================================
    namespace InteractionPriority_t
    {
        constexpr  ptrdiff_t m_ePriority = 0x1C8;
    }

    // ============================================
    // Context: InventoryNodeType_t
    // ============================================
    namespace InventoryNodeType_t
    {
        constexpr  ptrdiff_t m_nNodeType = 0x0;
    }

    // ============================================
    // Context: ItemFlagTypes_t
    // ============================================
    namespace ItemFlagTypes_t
    {
        constexpr  ptrdiff_t m_iFlags = 0x4C6;
    }

    // ============================================
    // Context: KeyValues3
    // ============================================
    namespace KeyValues3
    {
        constexpr  ptrdiff_t m_UnknownKeys = 0x48;
        constexpr  ptrdiff_t m_KVModelStateChoices = 0xE8;
        constexpr  ptrdiff_t m_KVthumbnail = 0x28;
        constexpr  ptrdiff_t m_TargetKVs = 0x8;
        constexpr  ptrdiff_t m_PreGenerationKVs = 0x18;
        constexpr  ptrdiff_t m_FinalKVs = 0x58;
    }

    // ============================================
    // Context: MedalRank_t
    // ============================================
    namespace MedalRank_t
    {
        constexpr  ptrdiff_t m_rank = 0x5C;
    }

    // ============================================
    // Context: ModelConfigHandle_t
    // ============================================
    namespace ModelConfigHandle_t
    {
        constexpr  ptrdiff_t m_Handle = 0x30;
    }

    // ============================================
    // Context: MoveCollide_t
    // ============================================
    namespace MoveCollide_t
    {
        constexpr  ptrdiff_t m_MoveCollide = 0x524;
    }

    // ============================================
    // Context: MoveType_t
    // ============================================
    namespace MoveType_t
    {
        constexpr  ptrdiff_t m_MoveType = 0x525;
        constexpr  ptrdiff_t m_nActualMoveType = 0x526;
    }

    // ============================================
    // Context: ObserverInterpState_t
    // ============================================
    namespace ObserverInterpState_t
    {
        constexpr  ptrdiff_t m_obsInterpState = 0x68;
    }

    // ============================================
    // Context: ObserverMode_t
    // ============================================
    namespace ObserverMode_t
    {
        constexpr  ptrdiff_t m_iObserverLastMode = 0x50;
    }

    // ============================================
    // Context: ParticleAttachment_t
    // ============================================
    namespace ParticleAttachment_t
    {
        constexpr  ptrdiff_t m_nAttachType = 0x10C;
    }

    // ============================================
    // Context: ParticleIndex_t
    // ============================================
    namespace ParticleIndex_t
    {
        constexpr  ptrdiff_t m_nAmbientEffect = 0xFA8;
        constexpr  ptrdiff_t m_activeLightParticleIndex = 0x1CB0;
        constexpr  ptrdiff_t m_nPlayerInfernoBodyFx = 0x32AC;
        constexpr  ptrdiff_t m_hWaterWakeParticles = 0x188C;
        constexpr  ptrdiff_t m_nfxFireDamageEffect = 0xFE8;
        constexpr  ptrdiff_t m_nSnapshotTrajectoryEffectIndex = 0x11F0;
    }

    // ============================================
    // Context: PerformanceMode_t
    // ============================================
    namespace PerformanceMode_t
    {
        constexpr  ptrdiff_t m_PerformanceMode = 0x1258;
    }

    // ============================================
    // Context: PhysicsRagdollPose_t
    // ============================================
    namespace PhysicsRagdollPose_t
    {
        constexpr  ptrdiff_t m_RagdollPose = 0x10A8;
    }

    // ============================================
    // Context: PlayerConnectedState
    // ============================================
    namespace PlayerConnectedState
    {
        constexpr  ptrdiff_t m_iConnected = 0x6EC;
        constexpr  ptrdiff_t m_iMostConnected = 0x6F0;
    }

    // ============================================
    // Context: PointCameraSettings_t
    // ============================================
    namespace PointCameraSettings_t
    {
        constexpr  ptrdiff_t m_Start = 0x94;
        constexpr  ptrdiff_t m_End = 0xA4;
        constexpr  ptrdiff_t m_OverlaidStart = 0xC;
        constexpr  ptrdiff_t m_OverlaidEnd = 0x1C;
    }

    // ============================================
    // Context: PointOrientConstraint_t
    // ============================================
    namespace PointOrientConstraint_t
    {
        constexpr  ptrdiff_t m_nConstraint = 0x614;
    }

    // ============================================
    // Context: PointOrientGoalDirectionType_t
    // ============================================
    namespace PointOrientGoalDirectionType_t
    {
        constexpr  ptrdiff_t m_nGoalDirection = 0x610;
    }

    // ============================================
    // Context: PointTemplateClientOnlyEntityBehavior_t
    // ============================================
    namespace PointTemplateClientOnlyEntityBehavior_t
    {
        constexpr  ptrdiff_t m_clientOnlyEntityBehavior = 0x620;
    }

    // ============================================
    // Context: PointTemplateOwnerSpawnGroupType_t
    // ============================================
    namespace PointTemplateOwnerSpawnGroupType_t
    {
        constexpr  ptrdiff_t m_ownerSpawnGroupType = 0x624;
    }

    // ============================================
    // Context: PointWorldTextJustifyHorizontal_t
    // ============================================
    namespace PointWorldTextJustifyHorizontal_t
    {
        constexpr  ptrdiff_t m_nJustifyHorizontal = 0x1274;
    }

    // ============================================
    // Context: PointWorldTextJustifyVertical_t
    // ============================================
    namespace PointWorldTextJustifyVertical_t
    {
        constexpr  ptrdiff_t m_nJustifyVertical = 0x1278;
    }

    // ============================================
    // Context: PointWorldTextReorientMode_t
    // ============================================
    namespace PointWorldTextReorientMode_t
    {
        constexpr  ptrdiff_t m_nReorientMode = 0x127C;
    }

    // ============================================
    // Context: PrecipitationFilter_t
    // ============================================
    namespace PrecipitationFilter_t
    {
        constexpr  ptrdiff_t m_snapshotFilter = 0x12C;
    }

    // ============================================
    // Context: PulseBestOutflowRules_t
    // ============================================
    namespace PulseBestOutflowRules_t
    {
        constexpr  ptrdiff_t m_nCheckType = 0x48;
    }

    // ============================================
    // Context: PulseCursorCancelPriority_t
    // ============================================
    namespace PulseCursorCancelPriority_t
    {
        constexpr  ptrdiff_t m_nDesiredKillPriority = 0x9C;
    }

    // ============================================
    // Context: PulseDocNodeID_t
    // ============================================
    namespace PulseDocNodeID_t
    {
        constexpr  ptrdiff_t m_nEditorNodeID = 0x8;
        constexpr  ptrdiff_t m_DestinationFlowNodeID = 0x48;
        constexpr  ptrdiff_t m_nNodeID = 0x18;
        constexpr  ptrdiff_t m_CallMethodID = 0x48;
        constexpr  ptrdiff_t m_nFlowNodeID = 0x48;
    }

    // ============================================
    // Context: PulseMethodCallMode_t
    // ============================================
    namespace PulseMethodCallMode_t
    {
        constexpr  ptrdiff_t m_nAsyncCallMode = 0x70;
    }

    // ============================================
    // Context: PulseNodeDynamicOutflows_t
    // ============================================
    namespace PulseNodeDynamicOutflows_t
    {
        constexpr  ptrdiff_t m_PulseAnimEvents = 0x50;
    }

    // ============================================
    // Context: PulseObservableBoolExpression_t
    // ============================================
    namespace PulseObservableBoolExpression_t
    {
        constexpr  ptrdiff_t m_Condition = 0x48;
    }

    // ============================================
    // Context: PulseRegisterMap_t
    // ============================================
    namespace PulseRegisterMap_t
    {
        constexpr  ptrdiff_t m_OutflowRegisterMap = 0x18;
        constexpr  ptrdiff_t m_RegisterMap = 0x50;
    }

    // ============================================
    // Context: PulseRuntimeBlackboardReferenceIndex_t
    // ============================================
    namespace PulseRuntimeBlackboardReferenceIndex_t
    {
        constexpr  ptrdiff_t m_nBlackboardReference = 0x80;
        constexpr  ptrdiff_t m_nBlackboardIndex = 0x58;
    }

    // ============================================
    // Context: PulseRuntimeCellIndex_t
    // ============================================
    namespace PulseRuntimeCellIndex_t
    {
        constexpr  ptrdiff_t m_nCellIndex = 0x40;
    }

    // ============================================
    // Context: PulseRuntimeChunkIndex_t
    // ============================================
    namespace PulseRuntimeChunkIndex_t
    {
        constexpr  ptrdiff_t m_nDestChunk = 0x10;
        constexpr  ptrdiff_t m_EntryChunk = 0x48;
        constexpr  ptrdiff_t m_nSrcChunk = 0x44;
    }

    // ============================================
    // Context: PulseRuntimeOutputIndex_t
    // ============================================
    namespace PulseRuntimeOutputIndex_t
    {
        constexpr  ptrdiff_t m_OutputIndex = 0x48;
    }

    // ============================================
    // Context: PulseSelectorOutflowList_t
    // ============================================
    namespace PulseSelectorOutflowList_t
    {
        constexpr  ptrdiff_t m_OutflowList = 0x50;
        constexpr  ptrdiff_t m_PassOutflow = 0x50;
    }

    // ============================================
    // Context: PulseSymbol_t
    // ============================================
    namespace PulseSymbol_t
    {
        constexpr  ptrdiff_t m_SourceOutflowName = 0x0;
        constexpr  ptrdiff_t m_DomainIdentifier = 0x8;
        constexpr  ptrdiff_t m_ParentMapName = 0x30;
        constexpr  ptrdiff_t m_ParentXmlName = 0x40;
        constexpr  ptrdiff_t m_HookName = 0x80;
        constexpr  ptrdiff_t m_FuncName = 0x30;
        constexpr  ptrdiff_t m_EventName = 0x80;
        constexpr  ptrdiff_t m_TagName = 0x0;
        constexpr  ptrdiff_t m_SourceEntity = 0x80;
        constexpr  ptrdiff_t m_SourceOutput = 0x90;
        constexpr  ptrdiff_t m_MethodName = 0x80;
        constexpr  ptrdiff_t m_BlackboardResource = 0x8;
        constexpr  ptrdiff_t m_PortName = 0x0;
    }

    // ============================================
    // Context: QAngle
    // ============================================
    namespace QAngle
    {
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles = 0x1158;
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles0 = 0x1180;
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles1 = 0x11A4;
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles2 = 0x11C8;
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles3 = 0x11EC;
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles4 = 0x1210;
        constexpr  ptrdiff_t m_vPrecomputedOBBAngles5 = 0x1234;
        constexpr  ptrdiff_t m_angles = 0x1170;
        constexpr  ptrdiff_t m_actualAngles = 0x11BC;
        constexpr  ptrdiff_t m_vecOldViewAngles = 0x240;
        constexpr  ptrdiff_t qAngle = 0x34;
        constexpr  ptrdiff_t m_qDeathEyeAngles = 0x1B5C;
        constexpr  ptrdiff_t m_angStashedShootAngles = 0x1CD8;
        constexpr  ptrdiff_t m_angEyeAngles = 0x3320;
        constexpr  ptrdiff_t m_arrOldEyeAngles = 0x33C0;
        constexpr  ptrdiff_t m_angEyeAnglesVelocity = 0x33F0;
        constexpr  ptrdiff_t m_angRotation = 0xB8;
        constexpr  ptrdiff_t m_angAbsRotation = 0xD4;
        constexpr  ptrdiff_t m_angWrappedLocalRotation = 0xF0;
        constexpr  ptrdiff_t m_vCachedEndPointAttachmentAngle = 0x12F8;
        constexpr  ptrdiff_t m_closedAngles = 0x13C4;
        constexpr  ptrdiff_t m_vecAngVelocity = 0x5A8;
        constexpr  ptrdiff_t v_angle = 0x1298;
        constexpr  ptrdiff_t v_anglePrevious = 0x12A4;
        constexpr  ptrdiff_t m_vecCsViewPunchAngle = 0x48;
        constexpr  ptrdiff_t m_angDemoViewAngles = 0x200;
        constexpr  ptrdiff_t m_vAngles = 0x2C;
        constexpr  ptrdiff_t m_predictableBaseAngle = 0x50;
        constexpr  ptrdiff_t m_predictableBaseAngleVel = 0x5C;
        constexpr  ptrdiff_t m_unpredictableBaseAngle = 0xA4;
        constexpr  ptrdiff_t m_vecC4ExplodeSpectateAng = 0x16BC;
        constexpr  ptrdiff_t m_vecTempEntAngVelocity = 0x1188;
        constexpr  ptrdiff_t angle = 0xC;
        constexpr  ptrdiff_t m_angDeltaAverage = 0x30;
        constexpr  ptrdiff_t m_angViewLast = 0x90;
        constexpr  ptrdiff_t m_SpotLightAngles = 0x20;
        constexpr  ptrdiff_t m_ViewAngles = 0xE0;
    }

    // ============================================
    // Context: Quaternion
    // ============================================
    namespace Quaternion
    {
        constexpr  ptrdiff_t m_qNoiseDelta = 0x10A0;
        constexpr  ptrdiff_t m_quatMuzzleFlashOrientation = 0x30;
    }

    // ============================================
    // Context: QuestProgress__Reason
    // ============================================
    namespace QuestProgress__Reason
    {
        constexpr  ptrdiff_t m_nQuestProgressReason = 0x8A4;
    }

    // ============================================
    // Context: RenderFx_t
    // ============================================
    namespace RenderFx_t
    {
        constexpr  ptrdiff_t m_nRenderFX = 0xC79;
    }

    // ============================================
    // Context: RenderMode_t
    // ============================================
    namespace RenderMode_t
    {
        constexpr  ptrdiff_t m_nRenderMode = 0xC78;
    }

    // ============================================
    // Context: ResourceId_t
    // ============================================
    namespace ResourceId_t
    {
        constexpr  ptrdiff_t m_primaryGraphId = 0x408;
    }

    // ============================================
    // Context: RumbleEffect_t
    // ============================================
    namespace RumbleEffect_t
    {
        constexpr  ptrdiff_t m_iRumbleEffect = 0x4E4;
    }

    // ============================================
    // Context: SceneEventId_t
    // ============================================
    namespace SceneEventId_t
    {
        constexpr  ptrdiff_t m_nNextSceneEventId = 0x68;
    }

    // ============================================
    // Context: SceneOpportunityHandle_t
    // ============================================
    namespace SceneOpportunityHandle_t
    {
        constexpr  ptrdiff_t m_hSceneOpportunity = 0x604;
    }

    // ============================================
    // Context: SceneRequestHandle_t
    // ============================================
    namespace SceneRequestHandle_t
    {
        constexpr  ptrdiff_t m_hSceneRequest = 0x600;
    }

    // ============================================
    // Context: SequenceFinishNotifyState_t
    // ============================================
    namespace SequenceFinishNotifyState_t
    {
        constexpr  ptrdiff_t m_nNotifyState = 0xCC;
    }

    // ============================================
    // Context: ShardSolid_t
    // ============================================
    namespace ShardSolid_t
    {
        constexpr  ptrdiff_t m_solid = 0x20;
    }

    // ============================================
    // Context: SignatureOutflow_Continue
    // ============================================
    namespace SignatureOutflow_Continue
    {
        constexpr  ptrdiff_t m_OnInterval = 0x90;
    }

    // ============================================
    // Context: SolidType_t
    // ============================================
    namespace SolidType_t
    {
        constexpr  ptrdiff_t m_nSolidType = 0x5B;
    }

    // ============================================
    // Context: SurroundingBoundsType_t
    // ============================================
    namespace SurroundingBoundsType_t
    {
        constexpr  ptrdiff_t m_nSurroundType = 0x5D;
    }

    // ============================================
    // Context: TakeDamageFlags_t
    // ============================================
    namespace TakeDamageFlags_t
    {
        constexpr  ptrdiff_t m_nTakeDamageFlags = 0x358;
    }

    // ============================================
    // Context: TimedEvent
    // ============================================
    namespace TimedEvent
    {
        constexpr  ptrdiff_t m_tParticlePrecipTraceTimer = 0x109C;
    }

    // ============================================
    // Context: TimelineCompression_t
    // ============================================
    namespace TimelineCompression_t
    {
        constexpr  ptrdiff_t m_nCompressionType = 0x21C;
    }

    // ============================================
    // Context: VPhysicsCollisionAttribute_t
    // ============================================
    namespace VPhysicsCollisionAttribute_t
    {
        constexpr  ptrdiff_t m_collisionAttribute = 0x10;
    }

    // ============================================
    // Context: ValueRemapperHapticsType_t
    // ============================================
    namespace ValueRemapperHapticsType_t
    {
        constexpr  ptrdiff_t m_nHapticsType = 0x640;
    }

    // ============================================
    // Context: ValueRemapperInputType_t
    // ============================================
    namespace ValueRemapperInputType_t
    {
        constexpr  ptrdiff_t m_nInputType = 0x604;
    }

    // ============================================
    // Context: ValueRemapperMomentumType_t
    // ============================================
    namespace ValueRemapperMomentumType_t
    {
        constexpr  ptrdiff_t m_nMomentumType = 0x644;
    }

    // ============================================
    // Context: ValueRemapperOutputType_t
    // ============================================
    namespace ValueRemapperOutputType_t
    {
        constexpr  ptrdiff_t m_nOutputType = 0x620;
    }

    // ============================================
    // Context: ValueRemapperRatchetType_t
    // ============================================
    namespace ValueRemapperRatchetType_t
    {
        constexpr  ptrdiff_t m_nRatchetType = 0x654;
    }

    // ============================================
    // Context: Vector
    // ============================================
    namespace Vector
    {
        constexpr  ptrdiff_t m_vFanOriginOffset = 0x1078;
        constexpr  ptrdiff_t m_vDirection = 0x1084;
        constexpr  ptrdiff_t m_vecStartPos = 0x1198;
        constexpr  ptrdiff_t m_vBoxMins = 0x604;
        constexpr  ptrdiff_t m_vBoxMaxs = 0x610;
        constexpr  ptrdiff_t m_vSizeParams = 0x10B4;
        constexpr  ptrdiff_t m_vShear = 0x10C4;
        constexpr  ptrdiff_t m_vBakeSpecularToCubemapsSize = 0x10D4;
        constexpr  ptrdiff_t m_vAlternateColor = 0x1100;
        constexpr  ptrdiff_t m_vPrecomputedBoundsMins = 0x1134;
        constexpr  ptrdiff_t m_vPrecomputedBoundsMaxs = 0x1140;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin = 0x114C;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent = 0x1164;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin0 = 0x1174;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent0 = 0x118C;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin1 = 0x1198;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent1 = 0x11B0;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin2 = 0x11BC;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent2 = 0x11D4;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin3 = 0x11E0;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent3 = 0x11F8;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin4 = 0x1204;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent4 = 0x121C;
        constexpr  ptrdiff_t m_vPrecomputedOBBOrigin5 = 0x1228;
        constexpr  ptrdiff_t m_vPrecomputedOBBExtent5 = 0x1240;
        constexpr  ptrdiff_t m_vLastSmokeOverlayColor = 0x1428;
        constexpr  ptrdiff_t m_vDefBurstOffset = 0x1248;
        constexpr  ptrdiff_t m_pos = 0x1158;
        constexpr  ptrdiff_t m_vel = 0x1164;
        constexpr  ptrdiff_t m_actualPos = 0x11B0;
        constexpr  ptrdiff_t m_poolOrigin = 0x11C8;
        constexpr  ptrdiff_t m_vNoiseScale = 0x68C;
        constexpr  ptrdiff_t m_vWindDirection = 0x69C;
        constexpr  ptrdiff_t m_vecLastMovementImpulses = 0x1CC;
        constexpr  ptrdiff_t m_vecOrigin = 0x600;
        constexpr  ptrdiff_t m_vClientScopeInaccuracy = 0x2B0;
        constexpr  ptrdiff_t m_vBoxSize = 0x608;
        constexpr  ptrdiff_t localSound = 0x8;
        constexpr  ptrdiff_t m_vecTurningInaccuracyEyeDirLast = 0x17C0;
        constexpr  ptrdiff_t m_vecWaterJumpVel = 0x4C;
        constexpr  ptrdiff_t m_vecLadderDir = 0xFA8;
        constexpr  ptrdiff_t m_vecLocalTop = 0xFD0;
        constexpr  ptrdiff_t m_vRagdollDamageForce = 0x1AD0;
        constexpr  ptrdiff_t m_vRagdollDamagePosition = 0x1ADC;
        constexpr  ptrdiff_t m_vRagdollServerOrigin = 0x1B2C;
        constexpr  ptrdiff_t m_vecDeathInfoOrigin = 0x1C94;
        constexpr  ptrdiff_t m_vecStashedGrenadeThrowPosition = 0x1CE4;
        constexpr  ptrdiff_t m_vecStashedVelocity = 0x1CF0;
        constexpr  ptrdiff_t m_vecGrabbedPos = 0x1238;
        constexpr  ptrdiff_t m_lookAt = 0x1270;
        constexpr  ptrdiff_t m_vecWrappedLocalOrigin = 0xE4;
        constexpr  ptrdiff_t m_vRenderOrigin = 0x128;
        constexpr  ptrdiff_t m_vPos = 0x618;
        constexpr  ptrdiff_t m_vecImpulse = 0x12A4;
        constexpr  ptrdiff_t m_vecPreviousImpulse = 0x12B0;
        constexpr  ptrdiff_t m_vWindDir = 0x12C8;
        constexpr  ptrdiff_t m_vColorMod = 0x12D4;
        constexpr  ptrdiff_t m_vInTangentLocal = 0x600;
        constexpr  ptrdiff_t m_vOutTangentLocal = 0x60C;
        constexpr  ptrdiff_t m_vMins = 0x6C0;
        constexpr  ptrdiff_t m_vMaxs = 0x6CC;
        constexpr  ptrdiff_t m_closedPosition = 0x13B8;
        constexpr  ptrdiff_t m_vWhereToSetLightingOrigin = 0x13D4;
        constexpr  ptrdiff_t m_Entity_vBoxMins = 0x16D8;
        constexpr  ptrdiff_t m_Entity_vBoxMaxs = 0x16E4;
        constexpr  ptrdiff_t m_Entity_vEdgeFadeDists = 0x1708;
        constexpr  ptrdiff_t m_vecAbsVelocity = 0x3FC;
        constexpr  ptrdiff_t m_vecBaseVelocity = 0x510;
        constexpr  ptrdiff_t m_vecPredictionError = 0x134C;
        constexpr  ptrdiff_t m_vecLastCameraSetupLocalOrigin = 0x1378;
        constexpr  ptrdiff_t m_vOldOrigin = 0x1390;
        constexpr  ptrdiff_t m_vecMuzzlePos0 = 0x608;
        constexpr  ptrdiff_t m_vecMuzzlePos1 = 0x614;
        constexpr  ptrdiff_t m_vSmokeColor = 0x864;
        constexpr  ptrdiff_t m_vecLadderNormal = 0x3F8;
        constexpr  ptrdiff_t m_vecForward = 0x65C;
        constexpr  ptrdiff_t m_vecLeft = 0x668;
        constexpr  ptrdiff_t m_vecUp = 0x674;
        constexpr  ptrdiff_t m_firePositions = 0x1018;
        constexpr  ptrdiff_t m_fireParentPositions = 0x1318;
        constexpr  ptrdiff_t m_BurnNormal = 0x1658;
        constexpr  ptrdiff_t m_minBounds = 0x8584;
        constexpr  ptrdiff_t m_maxBounds = 0x8590;
        constexpr  ptrdiff_t origin = 0xC;
        constexpr  ptrdiff_t m_groundNormal = 0x260;
        constexpr  ptrdiff_t m_vecDamageDirection = 0x12E4;
        constexpr  ptrdiff_t m_vecMins = 0x40;
        constexpr  ptrdiff_t m_vecMaxs = 0x4C;
        constexpr  ptrdiff_t m_vecSpecifiedSurroundingMins = 0x64;
        constexpr  ptrdiff_t m_vecSpecifiedSurroundingMaxs = 0x70;
        constexpr  ptrdiff_t m_vecSurroundingMaxs = 0x7C;
        constexpr  ptrdiff_t m_vecSurroundingMins = 0x88;
        constexpr  ptrdiff_t m_vCapsuleCenter1 = 0x94;
        constexpr  ptrdiff_t m_vCapsuleCenter2 = 0xA0;
        constexpr  ptrdiff_t m_vDissolverOrigin = 0xFD4;
        constexpr  ptrdiff_t m_vSmokeDetonationPos = 0x1268;
        constexpr  ptrdiff_t m_vecCachedRenderMins = 0x137C;
        constexpr  ptrdiff_t m_vecCachedRenderMaxs = 0x1388;
        constexpr  ptrdiff_t m_vAnimationBoundsMin = 0xFC0;
        constexpr  ptrdiff_t m_vAnimationBoundsMax = 0xFCC;
        constexpr  ptrdiff_t m_vecLinearForcePointAt = 0x1098;
        constexpr  ptrdiff_t m_vecLinearForcePointAtWorld = 0x10A8;
        constexpr  ptrdiff_t m_vecLinearForceDirection = 0x10B4;
        constexpr  ptrdiff_t m_vNormal = 0x20;
        constexpr  ptrdiff_t m_vServerControlPoints = 0x11C8;
        constexpr  ptrdiff_t m_vecDataCPValue = 0x150C;
        constexpr  ptrdiff_t m_Entity_vBoxProjectMins = 0x690;
        constexpr  ptrdiff_t m_Entity_vBoxProjectMaxs = 0x69C;
        constexpr  ptrdiff_t m_fGlowColor = 0x8;
        constexpr  ptrdiff_t m_vDistanceInnerMins = 0x630;
        constexpr  ptrdiff_t m_vDistanceInnerMaxs = 0x63C;
        constexpr  ptrdiff_t m_vDistanceOuterMins = 0x648;
        constexpr  ptrdiff_t m_vDistanceOuterMaxs = 0x654;
        constexpr  ptrdiff_t m_vecPreviousTestPoint = 0x66C;
        constexpr  ptrdiff_t m_vMinimapMins = 0xC20;
        constexpr  ptrdiff_t m_vMinimapMaxs = 0xC2C;
        constexpr  ptrdiff_t m_vInitialPosition = 0x11A0;
        constexpr  ptrdiff_t m_vInitialVelocity = 0x11AC;
        constexpr  ptrdiff_t m_vecExplodeEffectOrigin = 0x11CC;
        constexpr  ptrdiff_t vecLastTrailLinePos = 0x11DC;
        constexpr  ptrdiff_t m_vMin = 0x628;
        constexpr  ptrdiff_t m_vMax = 0x634;
        constexpr  ptrdiff_t m_attachmentPointBoneSpace = 0x11E8;
        constexpr  ptrdiff_t m_attachmentPointRagdollSpace = 0x11F4;
        constexpr  ptrdiff_t m_vecOffset = 0x1200;
        constexpr  ptrdiff_t dirPrimary = 0x8;
        constexpr  ptrdiff_t m_vecMoveDirEntitySpace = 0xFB0;
        constexpr  ptrdiff_t m_vecC4ExplodeSpectatePos = 0x16B0;
        constexpr  ptrdiff_t m_vecForce = 0x1074;
        constexpr  ptrdiff_t tentOffset = 0x117C;
        constexpr  ptrdiff_t m_vecNormal = 0x1198;
        constexpr  ptrdiff_t m_vLastCollisionOrigin = 0x11D0;
        constexpr  ptrdiff_t m_vecTempEntVelocity = 0x11DC;
        constexpr  ptrdiff_t m_vecPrevAbsOrigin = 0x11E8;
        constexpr  ptrdiff_t m_vecTempEntAcceleration = 0x11F4;
        constexpr  ptrdiff_t m_vInTangentWorld = 0x634;
        constexpr  ptrdiff_t m_vOutTangentWorld = 0x640;
        constexpr  ptrdiff_t m_bombsiteCenterA = 0x648;
        constexpr  ptrdiff_t m_bombsiteCenterB = 0x654;
        constexpr  ptrdiff_t m_vecEndPos = 0xFB8;
        constexpr  ptrdiff_t m_vecStart = 0xFC4;
        constexpr  ptrdiff_t offset = 0x14;
        constexpr  ptrdiff_t direction = 0x28;
        constexpr  ptrdiff_t color = 0x0;
        constexpr  ptrdiff_t position = 0x0;
        constexpr  ptrdiff_t m_vecMuzzleFlashOrigin = 0x40;
        constexpr  ptrdiff_t target = 0x18;
        constexpr  ptrdiff_t target_nudge = 0x24;
        constexpr  ptrdiff_t m_SpotLightOrigin = 0x14;
        constexpr  ptrdiff_t m_ShadowDirection = 0x2C;
        constexpr  ptrdiff_t m_AmbientDirection = 0x38;
        constexpr  ptrdiff_t m_SpecularDirection = 0x44;
        constexpr  ptrdiff_t m_InspectorSpecularDirection = 0x50;
        constexpr  ptrdiff_t m_vFowColor = 0xC8;
        constexpr  ptrdiff_t m_ViewOrigin = 0xD4;
        constexpr  ptrdiff_t m_WorldPoints = 0xF0;
    }

    // ============================================
    // Context: Vector2D
    // ============================================
    namespace Vector2D
    {
        constexpr  ptrdiff_t m_vecPanelSize = 0x24;
        constexpr  ptrdiff_t m_vecStressPositionA = 0x2C;
        constexpr  ptrdiff_t m_vecStressPositionB = 0x34;
        constexpr  ptrdiff_t m_vecLastPositionAtFullCrouchSpeed = 0x430;
        constexpr  ptrdiff_t m_vecWalkWishVel = 0x7AC;
        constexpr  ptrdiff_t m_vecDotCoords = 0x9C;
        constexpr  ptrdiff_t m_vecDrawText_Position = 0x360;
        constexpr  ptrdiff_t m_vFogOffsetLayer0 = 0x4A8;
        constexpr  ptrdiff_t m_vFogOffsetLayer1 = 0x4B0;
    }

    // ============================================
    // Context: Vector4D
    // ============================================
    namespace Vector4D
    {
        constexpr  ptrdiff_t m_Values = 0x34;
    }

    // ============================================
    // Context: VectorWS
    // ============================================
    namespace VectorWS
    {
        constexpr  ptrdiff_t m_location = 0x30;
        constexpr  ptrdiff_t m_vecPlayerMountPositionTop = 0xFDC;
        constexpr  ptrdiff_t m_vecPlayerMountPositionBottom = 0xFE8;
        constexpr  ptrdiff_t m_vecAbsOrigin = 0xC8;
        constexpr  ptrdiff_t m_vPrevEndPointPos = 0xFC8;
        constexpr  ptrdiff_t m_vCachedEndPointAttachmentPos = 0x12E0;
        constexpr  ptrdiff_t m_vecDamagePosition = 0x12D8;
        constexpr  ptrdiff_t m_vOrigin = 0x8;
        constexpr  ptrdiff_t m_vStart = 0x14;
        constexpr  ptrdiff_t m_vecEndPos = 0x1054;
    }

    // ============================================
    // Context: WeaponGameplayAnimState
    // ============================================
    namespace WeaponGameplayAnimState
    {
        constexpr  ptrdiff_t m_iWeaponGameplayAnimState = 0x1758;
    }

    // ============================================
    // Context: WeaponPurchaseTracker_t
    // ============================================
    namespace WeaponPurchaseTracker_t
    {
        constexpr  ptrdiff_t m_weaponPurchasesThisMatch = 0x50;
        constexpr  ptrdiff_t m_weaponPurchasesThisRound = 0xC0;
    }

    // ============================================
    // Context: WorldGroupId_t
    // ============================================
    namespace WorldGroupId_t
    {
        constexpr  ptrdiff_t m_nWorldGroupId = 0xC;
        constexpr  ptrdiff_t m_nWorldGroupID = 0x88;
        constexpr  ptrdiff_t m_worldGroupId = 0x600;
    }

    // ============================================
    // Context: attributeprovidertypes_t
    // ============================================
    namespace attributeprovidertypes_t
    {
        constexpr  ptrdiff_t m_ProviderType = 0x2C;
    }

    // ============================================
    // Context: audioparams_t
    // ============================================
    namespace audioparams_t
    {
        constexpr  ptrdiff_t m_audio = 0xB0;
    }

    // ============================================
    // Context: bitfield_1
    // ============================================
    namespace bitfield_1
    {
        constexpr  ptrdiff_t m_bDirtyHierarchy = 0x0;
        constexpr  ptrdiff_t m_bDirtyBoneMergeInfo = 0x0;
        constexpr  ptrdiff_t m_bNetworkedPositionChanged = 0x0;
        constexpr  ptrdiff_t m_bNetworkedAnglesChanged = 0x0;
        constexpr  ptrdiff_t m_bNetworkedScaleChanged = 0x0;
        constexpr  ptrdiff_t m_bWillBeCallingPostDataUpdate = 0x0;
        constexpr  ptrdiff_t m_bBoneMergeFlex = 0x0;
        constexpr  ptrdiff_t m_bDirtyBoneMergeBoneToRoot = 0x0;
        constexpr  ptrdiff_t m_bEndPointAttachmentPositionsDirty = 0x0;
        constexpr  ptrdiff_t m_bEndPointAttachmentAnglesDirty = 0x0;
        constexpr  ptrdiff_t m_bNewDataThisFrame = 0x0;
        constexpr  ptrdiff_t m_bPhysicsInitted = 0x0;
        constexpr  ptrdiff_t m_bClientSideOnly = 0x0;
        constexpr  ptrdiff_t m_bDirtyMotionType = 0x0;
        constexpr  ptrdiff_t m_bIsGeneratingLatchedParentSpaceState = 0x0;
        constexpr  ptrdiff_t m_bAlphaOverride = 0x0;
        constexpr  ptrdiff_t m_bShadowAlphaOverride = 0x0;
    }

    // ============================================
    // Context: bitfield_14
    // ============================================
    namespace bitfield_14
    {
        constexpr  ptrdiff_t m_nDesyncOffset = 0x0;
    }

    // ============================================
    // Context: bitfield_2
    // ============================================
    namespace bitfield_2
    {
        constexpr  ptrdiff_t m_nLatchAbsOrigin = 0x0;
    }

    // ============================================
    // Context: bitfield_3
    // ============================================
    namespace bitfield_3
    {
        constexpr  ptrdiff_t m_nRenderMode = 0x0;
    }

    // ============================================
    // Context: bitfield_5
    // ============================================
    namespace bitfield_5
    {
        constexpr  ptrdiff_t m_nRenderFX = 0x0;
    }

    // ============================================
    // Context: bool
    // ============================================
    namespace bools
    {
        constexpr  ptrdiff_t m_bTagSelfWhenComplete = 0x98;
        constexpr  ptrdiff_t m_bSetBonus = 0x40;
        constexpr  ptrdiff_t m_bUseAngles = 0x694;
        constexpr  ptrdiff_t m_bUseAutoCompare = 0x61C;
        constexpr  ptrdiff_t m_bFastRefresh = 0x61D;
        constexpr  ptrdiff_t m_bHeightFogEnabled = 0x60C;
        constexpr  ptrdiff_t m_bActive = 0x624;
        constexpr  ptrdiff_t m_bStartDisabled = 0x625;
        constexpr  ptrdiff_t m_bHasHeightFogEnd = 0x6F8;
        constexpr  ptrdiff_t m_bFirstTime = 0x6F9;
        constexpr  ptrdiff_t m_bPushTowardsInfoTarget = 0x1090;
        constexpr  ptrdiff_t m_bPushAwayFromInfoTarget = 0x1091;
        constexpr  ptrdiff_t m_bFalloff = 0x10B8;
        constexpr  ptrdiff_t m_bIsHit = 0x1190;
        constexpr  ptrdiff_t m_bState = 0xFB8;
        constexpr  ptrdiff_t m_bDisabledHud = 0xF44;
        constexpr  ptrdiff_t m_bIndirectUseLPVs = 0x61D;
        constexpr  ptrdiff_t m_bOverrideTintColor = 0x644;
        constexpr  ptrdiff_t m_bOverrideIndirectLightStrength = 0x645;
        constexpr  ptrdiff_t m_bOverrideSunLightStrength = 0x646;
        constexpr  ptrdiff_t m_bOverrideNoiseStrength = 0x647;
        constexpr  ptrdiff_t m_bEnabled = 0xFA8;
        constexpr  ptrdiff_t m_bContactShadow = 0x10F0;
        constexpr  ptrdiff_t m_bForceShadowsEnabled = 0x10F1;
        constexpr  ptrdiff_t m_bPrecomputedFieldsValid = 0x1130;
        constexpr  ptrdiff_t m_bInitialBoneSetup = 0x1290;
        constexpr  ptrdiff_t m_bBeenEnabled = 0x1200;
        constexpr  ptrdiff_t m_bHide = 0x1201;
        constexpr  ptrdiff_t m_bMaster = 0x10B4;
        constexpr  ptrdiff_t m_bExposureControl = 0x10B5;
        constexpr  ptrdiff_t m_bRequired = 0x1C;
        constexpr  ptrdiff_t m_bBasechecked = 0x1D;
        constexpr  ptrdiff_t m_bValid = 0x1E;
        constexpr  ptrdiff_t m_bVotesDirty = 0x630;
        constexpr  ptrdiff_t m_bTypeDirty = 0x631;
        constexpr  ptrdiff_t m_bIsYesNoVote = 0x632;
        constexpr  ptrdiff_t m_bStartedArming = 0x1CB8;
        constexpr  ptrdiff_t m_bBombPlacedAnimation = 0x1CC0;
        constexpr  ptrdiff_t m_bIsPlantingViaUse = 0x1CC1;
        constexpr  ptrdiff_t m_bPlayedArmingBeeps = 0x1CE4;
        constexpr  ptrdiff_t m_bBombPlanted = 0x1CEB;
        constexpr  ptrdiff_t m_bHasMovedSinceSpawn = 0x13D8;
        constexpr  ptrdiff_t m_bFlashBuildUp = 0x13F8;
        constexpr  ptrdiff_t m_bFlashDspHasBeenCleared = 0x13F9;
        constexpr  ptrdiff_t m_bFlashScreenshotHasBeenGrabbed = 0x13FA;
        constexpr  ptrdiff_t m_bDeferStartMusicOnWarmup = 0x141C;
        constexpr  ptrdiff_t m_bHasBreakPiecesOrCommands = 0x1278;
        constexpr  ptrdiff_t m_bBatchSameVolumeType = 0x110;
        constexpr  ptrdiff_t m_bBlockersPresent = 0x13C;
        constexpr  ptrdiff_t m_bRoundInProgress = 0x13D;
        constexpr  ptrdiff_t m_usable = 0xFAC;
        constexpr  ptrdiff_t m_bActiveParticlePrecipEmitter = 0x10A4;
        constexpr  ptrdiff_t m_bParticlePrecipInitialized = 0x10A5;
        constexpr  ptrdiff_t m_bHasSimulatedSinceLastSceneObjectUpdate = 0x10A6;
        constexpr  ptrdiff_t m_bDisabled = 0x630;
        constexpr  ptrdiff_t m_bWaitForRefire = 0x631;
        constexpr  ptrdiff_t m_bTriggerOnce = 0x632;
        constexpr  ptrdiff_t m_bFastRetrigger = 0x633;
        constexpr  ptrdiff_t m_bPassthoughCaller = 0x634;
        constexpr  ptrdiff_t m_gotUpdate = 0x11D8;
        constexpr  ptrdiff_t m_bEnableIndirect = 0x675;
        constexpr  ptrdiff_t m_bIsMaster = 0x676;
        constexpr  ptrdiff_t m_bIsRenderingWithViewModels = 0x50;
        constexpr  ptrdiff_t m_bEnableRendering = 0x58;
        constexpr  ptrdiff_t m_bInterpolationReadyToDraw = 0xA8;
        constexpr  ptrdiff_t m_bOrphanInsteadOfDeletingChildrenOnRemove = 0x600;
        constexpr  ptrdiff_t m_bOldJumpPressed = 0x10;
        constexpr  ptrdiff_t m_bNetworkedAnimationInputsChanged = 0xCD;
        constexpr  ptrdiff_t m_bNetworkedSequenceChanged = 0xCE;
        constexpr  ptrdiff_t m_bLastUpdateSkipped = 0xCF;
        constexpr  ptrdiff_t m_bSequenceFinished = 0xD0;
        constexpr  ptrdiff_t m_bClientSide = 0x826;
        constexpr  ptrdiff_t m_bExclusive = 0x827;
        constexpr  ptrdiff_t m_bEnabledOnClient = 0x828;
        constexpr  ptrdiff_t m_bFadingIn = 0x830;
        constexpr  ptrdiff_t m_bNeutrallyBuoyant = 0x2C;
        constexpr  ptrdiff_t m_bWaitForChildOutflows = 0x60;
        constexpr  ptrdiff_t m_bOverrideWithEvent = 0x628;
        constexpr  ptrdiff_t m_bInventoryImageRgbaRequested = 0x60;
        constexpr  ptrdiff_t m_bInventoryImageTriedCache = 0x61;
        constexpr  ptrdiff_t m_bRestoreCustomMaterialAfterPrecache = 0x1B8;
        constexpr  ptrdiff_t m_bInitialized = 0x1E8;
        constexpr  ptrdiff_t m_bDisallowSOC = 0x1E9;
        constexpr  ptrdiff_t m_bIsStoreItem = 0x1EA;
        constexpr  ptrdiff_t m_bIsTradeItem = 0x1EB;
        constexpr  ptrdiff_t m_bInitializedTags = 0x468;
        constexpr  ptrdiff_t m_bCompleteOnNextWake = 0x10;
        constexpr  ptrdiff_t m_bHasDefuser = 0x48;
        constexpr  ptrdiff_t m_bHasHelmet = 0x49;
        constexpr  ptrdiff_t m_bStartActive = 0x608;
        constexpr  ptrdiff_t m_bInspectPending = 0x1764;
        constexpr  ptrdiff_t m_bInspectShouldLoop = 0x1765;
        constexpr  ptrdiff_t m_bFireOnEmpty = 0x179C;
        constexpr  ptrdiff_t m_bBurstMode = 0x17E4;
        constexpr  ptrdiff_t m_bInReload = 0x17F4;
        constexpr  ptrdiff_t m_bIsHauledBack = 0x1804;
        constexpr  ptrdiff_t m_bSilencerOn = 0x1805;
        constexpr  ptrdiff_t m_bDroppedNearBuyZone = 0x1818;
        constexpr  ptrdiff_t m_bClearWeaponIdentifyingUGC = 0x18B8;
        constexpr  ptrdiff_t m_bVisualsDataSet = 0x18B9;
        constexpr  ptrdiff_t m_bUIWeapon = 0x18BA;
        constexpr  ptrdiff_t m_bCanBePickedUp = 0x18C8;
        constexpr  ptrdiff_t m_bWasActiveWeaponWhenDropped = 0x18D8;
        constexpr  ptrdiff_t m_donated = 0x18FC;
        constexpr  ptrdiff_t m_bWasOwnedByCT = 0x1904;
        constexpr  ptrdiff_t m_bWasOwnedByTerrorist = 0x1905;
        constexpr  ptrdiff_t m_bStopped = 0x220;
        constexpr  ptrdiff_t m_bAdrenalineActive = 0x638;
        constexpr  ptrdiff_t m_bCheckCSSClasses = 0xFE0;
        constexpr  ptrdiff_t m_bIgnoreInput = 0x1158;
        constexpr  ptrdiff_t m_bAllowInteractionFromAllSceneWorlds = 0x1180;
        constexpr  ptrdiff_t m_bWasActive = 0x1171;
        constexpr  ptrdiff_t m_bListenedTo = 0x11A0;
        constexpr  ptrdiff_t m_bRestartAfterRestore = 0x11B4;
        constexpr  ptrdiff_t m_bHasParent = 0x74;
        constexpr  ptrdiff_t m_bParentFrozen = 0x75;
        constexpr  ptrdiff_t m_bFakeLadder = 0xFF9;
        constexpr  ptrdiff_t m_bHasSlack = 0xFFA;
        constexpr  ptrdiff_t m_bHasFemaleVoice = 0x14A8;
        constexpr  ptrdiff_t m_bPrevDefuser = 0x14C6;
        constexpr  ptrdiff_t m_bPrevHelmet = 0x14C7;
        constexpr  ptrdiff_t m_bInBuyZone = 0x14D8;
        constexpr  ptrdiff_t m_bPreviouslyInBuyZone = 0x14D9;
        constexpr  ptrdiff_t m_bInLanding = 0x14DA;
        constexpr  ptrdiff_t m_bInHostageRescueZone = 0x14E0;
        constexpr  ptrdiff_t m_bInBombZone = 0x14E1;
        constexpr  ptrdiff_t m_bIsBuyMenuOpen = 0x14E2;
        constexpr  ptrdiff_t m_bRetakesHasDefuseKit = 0x1648;
        constexpr  ptrdiff_t m_bRetakesMVPLastRound = 0x1649;
        constexpr  ptrdiff_t m_bNeedToReApplyGloves = 0x1655;
        constexpr  ptrdiff_t m_bMustSyncRagdollState = 0x1AC9;
        constexpr  ptrdiff_t m_bRagdollDamageHeadshot = 0x1B28;
        constexpr  ptrdiff_t m_bOnGroundLastTick = 0x1B3C;
        constexpr  ptrdiff_t m_bLeftHanded = 0x1B68;
        constexpr  ptrdiff_t m_bIsWalking = 0x1C30;
        constexpr  ptrdiff_t m_bIsScoped = 0x1C50;
        constexpr  ptrdiff_t m_bResumeZoom = 0x1C51;
        constexpr  ptrdiff_t m_bIsDefusing = 0x1C52;
        constexpr  ptrdiff_t m_bIsGrabbingHostage = 0x1C53;
        constexpr  ptrdiff_t m_bInNoDefuseArea = 0x1C5C;
        constexpr  ptrdiff_t m_bWaitForNoAttack = 0x1C70;
        constexpr  ptrdiff_t m_bKilledByHeadshot = 0x1C79;
        constexpr  ptrdiff_t m_bOldIsScoped = 0x1C8C;
        constexpr  ptrdiff_t m_bHasDeathInfo = 0x1C8D;
        constexpr  ptrdiff_t m_bGrenadeParametersStashed = 0x1CD4;
        constexpr  ptrdiff_t m_bShouldAutobuyDMWeapons = 0x3230;
        constexpr  ptrdiff_t m_bGunGameImmunity = 0x3238;
        constexpr  ptrdiff_t m_isRescued = 0x1224;
        constexpr  ptrdiff_t m_jumpedThisFrame = 0x1225;
        constexpr  ptrdiff_t m_bHandsHaveBeenCut = 0x122C;
        constexpr  ptrdiff_t m_isInit = 0x1298;
        constexpr  ptrdiff_t m_bDebugAbsOriginChanges = 0x102;
        constexpr  ptrdiff_t m_bDormant = 0x103;
        constexpr  ptrdiff_t m_bForceParentToBeNetworked = 0x104;
        constexpr  ptrdiff_t m_bForcedObserverMode = 0x54;
        constexpr  ptrdiff_t m_bWasEnabled = 0x608;
        constexpr  ptrdiff_t m_bIsEnabled = 0x611;
        constexpr  ptrdiff_t m_bGamePaused = 0x38;
        constexpr  ptrdiff_t m_bLoop = 0x608;
        constexpr  ptrdiff_t m_bVerticalFOV = 0x609;
        constexpr  ptrdiff_t m_bConstantSpeed = 0x60A;
        constexpr  ptrdiff_t m_bDofEnabled = 0x66C;
        constexpr  ptrdiff_t m_bForceRecreateNextUpdate = 0xFB0;
        constexpr  ptrdiff_t m_bFullbright = 0x1251;
        constexpr  ptrdiff_t m_bDrawBackground = 0x1260;
        constexpr  ptrdiff_t m_bApplyWind = 0xFB8;
        constexpr  ptrdiff_t m_bPrevEndPointPos = 0xFC4;
        constexpr  ptrdiff_t m_bConstrainBetweenEndpoints = 0x1310;
        constexpr  ptrdiff_t m_modelChanged = 0x13B4;
        constexpr  ptrdiff_t m_bLocked = 0x13B5;
        constexpr  ptrdiff_t m_bNoNPCs = 0x13B6;
        constexpr  ptrdiff_t m_bSequenceChangeNetworked = 0x1C;
        constexpr  ptrdiff_t m_bDiscontinuity = 0x1D;
        constexpr  ptrdiff_t m_bDestructiblePartInitialStateDestructed0_GenerateBreakpieces = 0xB40;
        constexpr  ptrdiff_t m_bDestructiblePartInitialStateDestructed1_GenerateBreakpieces = 0xB41;
        constexpr  ptrdiff_t m_bDestructiblePartInitialStateDestructed2_GenerateBreakpieces = 0xB42;
        constexpr  ptrdiff_t m_bDestructiblePartInitialStateDestructed3_GenerateBreakpieces = 0xB43;
        constexpr  ptrdiff_t m_bDestructiblePartInitialStateDestructed4_GenerateBreakpieces = 0xB44;
        constexpr  ptrdiff_t m_bInitModelEffects = 0xC70;
        constexpr  ptrdiff_t m_bDoingModelEffects = 0xC71;
        constexpr  ptrdiff_t m_bAllowFadeInView = 0xC7A;
        constexpr  ptrdiff_t m_bRenderToCubemaps = 0xD20;
        constexpr  ptrdiff_t m_bNoInterpolate = 0xD21;
        constexpr  ptrdiff_t m_bUseClientOverrideTint = 0xF5C;
        constexpr  ptrdiff_t m_Entity_bCustomCubemapTexture = 0x1688;
        constexpr  ptrdiff_t m_Entity_bMoveable = 0x16F0;
        constexpr  ptrdiff_t m_Entity_bStartDisabled = 0x1700;
        constexpr  ptrdiff_t m_Entity_bEnabled = 0x1741;
        constexpr  ptrdiff_t m_bTakesDamage = 0x355;
        constexpr  ptrdiff_t m_bInterpolateEvenWithNoModel = 0x379;
        constexpr  ptrdiff_t m_bPredictionEligible = 0x37A;
        constexpr  ptrdiff_t m_bApplyLayerMatchIDToModel = 0x37B;
        constexpr  ptrdiff_t m_bDisabledContextThinks = 0x3B0;
        constexpr  ptrdiff_t m_bHasSuccessfullyInterpolated = 0x3BD;
        constexpr  ptrdiff_t m_bHasAddedVarsToInterpolation = 0x3BE;
        constexpr  ptrdiff_t m_bRenderEvenWhenNotSuccessfullyInterpolated = 0x3BF;
        constexpr  ptrdiff_t m_bClientSideRagdoll = 0x3EA;
        constexpr  ptrdiff_t m_bAnimatedEveryTick = 0x548;
        constexpr  ptrdiff_t m_bGravityDisabled = 0x549;
        constexpr  ptrdiff_t m_bGravityActuallyDisabled = 0x568;
        constexpr  ptrdiff_t m_bPredictable = 0x569;
        constexpr  ptrdiff_t m_bRenderWithViewModels = 0x56A;
        constexpr  ptrdiff_t m_bAnimTimeChanged = 0x5E1;
        constexpr  ptrdiff_t m_bSimulationTimeChanged = 0x5E2;
        constexpr  ptrdiff_t m_bAttributesInitialized = 0x1888;
        constexpr  ptrdiff_t m_bIsPreviewModel = 0x1890;
        constexpr  ptrdiff_t m_bIsSwappingToPredictableController = 0x13B0;
        constexpr  ptrdiff_t m_bKnife = 0x1160;
        constexpr  ptrdiff_t m_bStartOnSpawn = 0x600;
        constexpr  ptrdiff_t m_bToLocalPlayer = 0x601;
        constexpr  ptrdiff_t m_bStopOnNew = 0x602;
        constexpr  ptrdiff_t m_bSaveRestore = 0x603;
        constexpr  ptrdiff_t m_bSavedIsPlaying = 0x604;
        constexpr  ptrdiff_t m_bBombPlantedHere = 0x1078;
        constexpr  ptrdiff_t m_bFirstAttack = 0x1CB0;
        constexpr  ptrdiff_t m_bUseParentRenderBounds = 0x3C0;
        constexpr  ptrdiff_t m_bDisableSolidCollisionsForHierarchy = 0x3C1;
        constexpr  ptrdiff_t m_bIsIncGrenade = 0x1238;
        constexpr  ptrdiff_t m_bModelOverrodeBlockLOS = 0x1158;
        constexpr  ptrdiff_t m_bConformToCollisionBounds = 0x1160;
        constexpr  ptrdiff_t m_bMeleeWeapon = 0x71C;
        constexpr  ptrdiff_t m_bHasBurstMode = 0x71D;
        constexpr  ptrdiff_t m_bIsRevolver = 0x71E;
        constexpr  ptrdiff_t m_bCannotShootUnderwater = 0x71F;
        constexpr  ptrdiff_t m_bIsFullAuto = 0x734;
        constexpr  ptrdiff_t m_bReloadsSingleShells = 0x73C;
        constexpr  ptrdiff_t m_bAllowBurstHolster = 0x7D8;
        constexpr  ptrdiff_t m_bUnzoomsAfterShot = 0x7F8;
        constexpr  ptrdiff_t m_bHideViewModelWhenZoomed = 0x7F9;
        constexpr  ptrdiff_t m_bPreventLoopback = 0x28;
        constexpr  ptrdiff_t m_bOverrideFogColor = 0x1B4;
        constexpr  ptrdiff_t m_bOverrideFogStartEnd = 0x1CD;
        constexpr  ptrdiff_t m_bClientPredictDelete = 0x1CB0;
        constexpr  ptrdiff_t m_bRedraw = 0x1CB1;
        constexpr  ptrdiff_t m_bIsHeldByPlayer = 0x1CB2;
        constexpr  ptrdiff_t m_bPinPulled = 0x1CB3;
        constexpr  ptrdiff_t m_bJumpThrow = 0x1CB4;
        constexpr  ptrdiff_t m_bThrowAnimating = 0x1CB5;
        constexpr  ptrdiff_t m_bJustPulledPin = 0x1D40;
        constexpr  ptrdiff_t m_bAsynchronouslySpawnEntities = 0x61C;
        constexpr  ptrdiff_t m_bHasCommunicationAbuseMute = 0x82C;
        constexpr  ptrdiff_t m_bEverPlayedOnTeam = 0x84C;
        constexpr  ptrdiff_t m_bCannotBeKicked = 0x8E8;
        constexpr  ptrdiff_t m_bEverFullyConnected = 0x8E9;
        constexpr  ptrdiff_t m_bAbandonAllowsSurrender = 0x8EA;
        constexpr  ptrdiff_t m_bAbandonOffersInstantSurrender = 0x8EB;
        constexpr  ptrdiff_t m_bDisconnection1MinWarningPrinted = 0x8EC;
        constexpr  ptrdiff_t m_bScoreReported = 0x8ED;
        constexpr  ptrdiff_t m_bControllingBot = 0x900;
        constexpr  ptrdiff_t m_bHasControlledBotThisRound = 0x901;
        constexpr  ptrdiff_t m_bHasBeenControlledByPlayerThisRound = 0x902;
        constexpr  ptrdiff_t m_bCanControlObservedBot = 0x908;
        constexpr  ptrdiff_t m_bPawnIsAlive = 0x914;
        constexpr  ptrdiff_t m_bPawnHasDefuser = 0x920;
        constexpr  ptrdiff_t m_bPawnHasHelmet = 0x921;
        constexpr  ptrdiff_t m_bMvpNoMusic = 0x942;
        constexpr  ptrdiff_t m_bIsPlayerNameDirty = 0x954;
        constexpr  ptrdiff_t m_bFireBulletsSeedSynchronized = 0x955;
        constexpr  ptrdiff_t m_bUsingGroundTopologyOffset = 0x3F0;
        constexpr  ptrdiff_t m_bDucked = 0x408;
        constexpr  ptrdiff_t m_bDuckOverride = 0x414;
        constexpr  ptrdiff_t m_bDesiresDuck = 0x415;
        constexpr  ptrdiff_t m_bDucking = 0x416;
        constexpr  ptrdiff_t m_duckUntilOnGround = 0x438;
        constexpr  ptrdiff_t m_bHasWalkMovedSinceLastJump = 0x439;
        constexpr  ptrdiff_t m_bInStuckTest = 0x43A;
        constexpr  ptrdiff_t m_bSpeedCropped = 0x650;
        constexpr  ptrdiff_t m_bUseFrictionStashedSpeed = 0x690;
        constexpr  ptrdiff_t m_bJumpApexPending = 0x714;
        constexpr  ptrdiff_t m_bWasSurfing = 0x71C;
        constexpr  ptrdiff_t m_bHasEverProcessedCommand = 0xFD8;
        constexpr  ptrdiff_t m_bSequenceInProgress = 0x1CB0;
        constexpr  ptrdiff_t m_bSetFromDebugHistory = 0x24;
        constexpr  ptrdiff_t m_bSpawnMotionDisabled = 0x34;
        constexpr  ptrdiff_t m_bMagazineRemoved = 0x1CE0;
        constexpr  ptrdiff_t m_bFireIsBurning = 0x1618;
        constexpr  ptrdiff_t m_bInPostEffectTime = 0x1964;
        constexpr  ptrdiff_t m_blosCheck = 0x8574;
        constexpr  ptrdiff_t bClip3DSkyBoxNearToWorldFar = 0x18;
        constexpr  ptrdiff_t m_bIsValid = 0x0;
        constexpr  ptrdiff_t m_bIsUsable = 0xFA8;
        constexpr  ptrdiff_t m_bSelfReference = 0x82;
        constexpr  ptrdiff_t m_bClientClothCreationSuppressed = 0x110;
        constexpr  ptrdiff_t m_inPrecache = 0x1CCC;
        constexpr  ptrdiff_t m_bNeedsBoltAction = 0x1CCD;
        constexpr  ptrdiff_t m_bCoreExplode = 0xFE4;
        constexpr  ptrdiff_t m_bLinkedToServerEnt = 0xFE5;
        constexpr  ptrdiff_t m_bRenderShadows = 0xFB4;
        constexpr  ptrdiff_t m_bUseUniqueColorTarget = 0xFB5;
        constexpr  ptrdiff_t m_bDraw3DSkybox = 0xFC5;
        constexpr  ptrdiff_t m_bFadeOut = 0x1158;
        constexpr  ptrdiff_t m_bImportant = 0x1159;
        constexpr  ptrdiff_t m_bReleaseRagdoll = 0x1174;
        constexpr  ptrdiff_t m_bFadingOut = 0x1176;
        constexpr  ptrdiff_t m_bDidSmokeEffect = 0x1254;
        constexpr  ptrdiff_t m_bSmokeVolumeDataReceived = 0x1298;
        constexpr  ptrdiff_t m_bSmokeEffectSpawned = 0x1299;
        constexpr  ptrdiff_t m_bUseHitboxesForRenderBox = 0x12D0;
        constexpr  ptrdiff_t m_bUseAnimGraph = 0x12D1;
        constexpr  ptrdiff_t m_bRandomizeCycle = 0x135C;
        constexpr  ptrdiff_t m_bFiredStartEndOutput = 0x135E;
        constexpr  ptrdiff_t m_bForceNpcExclude = 0x135F;
        constexpr  ptrdiff_t m_bCreateNonSolid = 0x1360;
        constexpr  ptrdiff_t m_bIsOverrideProp = 0x1361;
        constexpr  ptrdiff_t m_bSurrendered = 0x8BC;
        constexpr  ptrdiff_t m_bCollapseToForcePoint = 0x10A4;
        constexpr  ptrdiff_t m_bConvertToDebrisWhenPossible = 0x10C0;
        constexpr  ptrdiff_t m_bSendHandle = 0x604;
        constexpr  ptrdiff_t m_bWorldLayerVisible = 0x628;
        constexpr  ptrdiff_t m_bEntitiesSpawned = 0x629;
        constexpr  ptrdiff_t m_bCreateAsChildSpawnGroup = 0x62A;
        constexpr  ptrdiff_t m_bWorldLayerActuallyVisible = 0x630;
        constexpr  ptrdiff_t m_bFrozen = 0x11A9;
        constexpr  ptrdiff_t m_bAnimateDuringGameplayPause = 0x11B4;
        constexpr  ptrdiff_t m_bNoSave = 0x12FC;
        constexpr  ptrdiff_t m_bNoFreeze = 0x12FD;
        constexpr  ptrdiff_t m_bNoRamp = 0x12FE;
        constexpr  ptrdiff_t m_bOldActive = 0x1540;
        constexpr  ptrdiff_t m_bOldFrozen = 0x1541;
        constexpr  ptrdiff_t m_bRenderDiffuse = 0xC0;
        constexpr  ptrdiff_t m_bRenderTransmissive = 0xC8;
        constexpr  ptrdiff_t m_bUsesBakedShadowing = 0x10C;
        constexpr  ptrdiff_t m_bAllowSSTGeneration = 0x121;
        constexpr  ptrdiff_t m_bFlicker = 0x141;
        constexpr  ptrdiff_t m_bUseSecondaryColor = 0x19C;
        constexpr  ptrdiff_t m_bMixedShadows = 0x19D;
        constexpr  ptrdiff_t m_bIsRescuing = 0x4C;
        constexpr  ptrdiff_t m_Entity_bDefaultEnvMap = 0x6CD;
        constexpr  ptrdiff_t m_Entity_bDefaultSpecEnvMap = 0x6CE;
        constexpr  ptrdiff_t m_Entity_bIndoorCubeMap = 0x6CF;
        constexpr  ptrdiff_t m_Entity_bCopyDiffuseFromDefaultCubemap = 0x6D0;
        constexpr  ptrdiff_t m_bIsPublic = 0x98;
        constexpr  ptrdiff_t m_bFlashing = 0x44;
        constexpr  ptrdiff_t m_bEligibleForScreenHighlight = 0x50;
        constexpr  ptrdiff_t m_bGlowing = 0x51;
        constexpr  ptrdiff_t m_bStartEnabled = 0xFDC;
        constexpr  ptrdiff_t m_bIsOtherEnemy = 0x74;
        constexpr  ptrdiff_t m_bShowLight = 0x12C0;
        constexpr  ptrdiff_t m_bIsPlayingBack = 0x608;
        constexpr  ptrdiff_t m_bPaused = 0x609;
        constexpr  ptrdiff_t m_bMultiplayer = 0x60A;
        constexpr  ptrdiff_t m_bAutogenerated = 0x60B;
        constexpr  ptrdiff_t m_bAllRequirementsComplete = 0x60C;
        constexpr  ptrdiff_t m_bClientOnly = 0x616;
        constexpr  ptrdiff_t m_bWasPlaying = 0x638;
        constexpr  ptrdiff_t m_bClientside = 0x1668;
        constexpr  ptrdiff_t m_bParticleSystemsCreated = 0x1669;
        constexpr  ptrdiff_t m_bAttachmentDirty = 0x1690;
        constexpr  ptrdiff_t m_bDisabledOld = 0x601;
        constexpr  ptrdiff_t m_bUpdateOnClient = 0x602;
        constexpr  ptrdiff_t m_bRequiresUseKey = 0x61C;
        constexpr  ptrdiff_t m_bEngaged = 0x660;
        constexpr  ptrdiff_t m_bFirstUpdate = 0x661;
        constexpr  ptrdiff_t m_bFreezePeriod = 0x40;
        constexpr  ptrdiff_t m_bWarmupPeriod = 0x41;
        constexpr  ptrdiff_t m_bTerroristTimeOutActive = 0x4C;
        constexpr  ptrdiff_t m_bCTTimeOutActive = 0x4D;
        constexpr  ptrdiff_t m_bTechnicalTimeOut = 0x60;
        constexpr  ptrdiff_t m_bMatchWaitingForResume = 0x61;
        constexpr  ptrdiff_t m_bGameRestart = 0x78;
        constexpr  ptrdiff_t m_bAnyHostageReached = 0x98;
        constexpr  ptrdiff_t m_bMapHasBombTarget = 0x99;
        constexpr  ptrdiff_t m_bMapHasRescueZone = 0x9A;
        constexpr  ptrdiff_t m_bMapHasBuyZone = 0x9B;
        constexpr  ptrdiff_t m_bIsQueuedMatchmaking = 0x9C;
        constexpr  ptrdiff_t m_bIsValveDS = 0xA4;
        constexpr  ptrdiff_t m_bLogoMap = 0xA5;
        constexpr  ptrdiff_t m_bPlayAllStepSoundsOnServer = 0xA6;
        constexpr  ptrdiff_t m_bHasMatchStarted = 0xB0;
        constexpr  ptrdiff_t m_bIsDroppingItems = 0x8C4;
        constexpr  ptrdiff_t m_bIsQuestEligible = 0x8C5;
        constexpr  ptrdiff_t m_bIsHltvActive = 0x8C6;
        constexpr  ptrdiff_t m_bBombDropped = 0x9A8;
        constexpr  ptrdiff_t m_bTCantBuy = 0x9B4;
        constexpr  ptrdiff_t m_bCTCantBuy = 0x9B5;
        constexpr  ptrdiff_t m_bHasTriggeredRoundStartMusic = 0xD7C;
        constexpr  ptrdiff_t m_bSwitchingTeamsAtRoundReset = 0xD7D;
        constexpr  ptrdiff_t m_bTeamIntroPeriod = 0xF04;
        constexpr  ptrdiff_t m_bRoundEndShowTimerDefend = 0xF10;
        constexpr  ptrdiff_t m_bRoundEndNoMusic = 0xF3C;
        constexpr  ptrdiff_t m_bExplodeEffectBegan = 0x11EC;
        constexpr  ptrdiff_t m_bCanCreateGrenadeTrail = 0x11ED;
        constexpr  ptrdiff_t m_bGradientFogNeedsTextures = 0x63A;
        constexpr  ptrdiff_t m_bClosedLoop = 0x708;
        constexpr  ptrdiff_t m_bAlwaysAllow = 0x16CC;
        constexpr  ptrdiff_t m_bProjectOnWorld = 0xFC0;
        constexpr  ptrdiff_t m_bProjectOnCharacters = 0xFC1;
        constexpr  ptrdiff_t m_bProjectOnWater = 0xFC2;
        constexpr  ptrdiff_t m_bSpotted = 0x8;
        constexpr  ptrdiff_t enable = 0x64;
        constexpr  ptrdiff_t blend = 0x65;
        constexpr  ptrdiff_t m_bPadding2 = 0x66;
        constexpr  ptrdiff_t m_bPadding = 0x67;
        constexpr  ptrdiff_t m_bTurnedOff = 0x1050;
        constexpr  ptrdiff_t m_bIsIncindiary = 0xF0;
        constexpr  ptrdiff_t m_bHasForces = 0xF1;
        constexpr  ptrdiff_t m_bBlockInspectUntilNextGraphUpdate = 0x15A0;
        constexpr  ptrdiff_t m_bBombTicking = 0x1160;
        constexpr  ptrdiff_t m_bCannotBeDefused = 0x1194;
        constexpr  ptrdiff_t m_bHasExploded = 0x1195;
        constexpr  ptrdiff_t m_bBeingDefused = 0x119C;
        constexpr  ptrdiff_t m_bC4Activated = 0x11A8;
        constexpr  ptrdiff_t m_bTenSecWarning = 0x11A9;
        constexpr  ptrdiff_t m_bBombDefused = 0x11B4;
        constexpr  ptrdiff_t m_bRadarFlash = 0x1698;
        constexpr  ptrdiff_t m_bInitiallyPopulateInterpHistory = 0x1060;
        constexpr  ptrdiff_t m_bSuppressAnimEventSounds = 0x1062;
        constexpr  ptrdiff_t m_bAnimGraphUpdateEnabled = 0x1070;
        constexpr  ptrdiff_t m_bAnimationUpdateScheduled = 0x1071;
        constexpr  ptrdiff_t m_bBuiltRagdoll = 0x1090;
        constexpr  ptrdiff_t m_bRagdollEnabled = 0x10F0;
        constexpr  ptrdiff_t m_bRagdollClientSide = 0x10F1;
        constexpr  ptrdiff_t m_bHasAnimatedMaterialAttributes = 0x1100;
        constexpr  ptrdiff_t m_bAnd = 0x4C;
        constexpr  ptrdiff_t m_bParticleCollision = 0x11C8;
        constexpr  ptrdiff_t m_bUrgent = 0x63C;
        constexpr  ptrdiff_t m_bHostageAlive = 0x600;
        constexpr  ptrdiff_t m_isHostageFollowingSomeone = 0x60C;
        constexpr  ptrdiff_t m_bEndMatchNextMapAllVoted = 0x690;
        constexpr  ptrdiff_t m_foundGoalPositions = 0x691;
        constexpr  ptrdiff_t m_bFogEnable = 0x608;
        constexpr  ptrdiff_t m_bUseScreenAspectRatio = 0x61D;
        constexpr  ptrdiff_t m_bNoSky = 0x624;
        constexpr  ptrdiff_t m_bCanHLTVUse = 0x634;
        constexpr  ptrdiff_t m_bAlignWithParent = 0x635;
        constexpr  ptrdiff_t m_bIsOn = 0x654;
        constexpr  ptrdiff_t m_bNegated = 0x600;
        constexpr  ptrdiff_t m_bUseNormalSpawnsForDM = 0x60C;
        constexpr  ptrdiff_t m_bDisableAutoGeneratedDMSpawns = 0x60D;
        constexpr  ptrdiff_t m_bFadePlayerVisibilityFarZ = 0x618;
        constexpr  ptrdiff_t m_bRainTraceToSkyEnabled = 0x619;
        constexpr  ptrdiff_t m_bGPUCullSkybox = 0x61A;
        constexpr  ptrdiff_t m_bHasWarnedAI = 0x1158;
        constexpr  ptrdiff_t m_bIsSmokeGrenade = 0x1159;
        constexpr  ptrdiff_t m_bIsLive = 0x115A;
        constexpr  ptrdiff_t m_bLimitCountPasses = 0x0;
        constexpr  ptrdiff_t m_bWorldSpaceScale = 0xFE0;
        constexpr  ptrdiff_t m_bAwake = 0x12D0;
        constexpr  ptrdiff_t m_bBuiltRightHanded = 0x2C8;
        constexpr  ptrdiff_t m_bAllowFlipping = 0x2C9;
        constexpr  ptrdiff_t m_bGenerateMuzzleLight = 0x4C4;
        constexpr  ptrdiff_t m_bLinkedCooldowns = 0x4C5;
        constexpr  ptrdiff_t m_bAutoSwitchTo = 0x4CC;
        constexpr  ptrdiff_t m_bAutoSwitchFrom = 0x4CD;
        constexpr  ptrdiff_t m_bReserveAmmoAsClips = 0x4E0;
        constexpr  ptrdiff_t m_bTreatAsSingleClip = 0x4E1;
        constexpr  ptrdiff_t m_bKeepLoadedAmmo = 0x4E2;
        constexpr  ptrdiff_t m_bDisableOnExit = 0x66C;
        constexpr  ptrdiff_t m_bMoveViewToPlayerNextThink = 0xFE1;
        constexpr  ptrdiff_t m_bLit = 0x11A9;
        constexpr  ptrdiff_t m_bFollowPlayerAcrossTeleport = 0x11AA;
        constexpr  ptrdiff_t m_bOpaque = 0x11F0;
        constexpr  ptrdiff_t m_bNoDepth = 0x11F1;
        constexpr  ptrdiff_t m_bVisibleWhenParentNoDraw = 0x11F2;
        constexpr  ptrdiff_t m_bRenderBackface = 0x11F3;
        constexpr  ptrdiff_t m_bUseOffScreenIndicator = 0x11F4;
        constexpr  ptrdiff_t m_bExcludeFromSaveGames = 0x11F5;
        constexpr  ptrdiff_t m_bGrabbable = 0x11F6;
        constexpr  ptrdiff_t m_bOnlyRenderToTexture = 0x11F7;
        constexpr  ptrdiff_t m_bDisableMipGen = 0x11F8;
        constexpr  ptrdiff_t m_bCheapEffect = 0x62C;
        constexpr  ptrdiff_t m_bKnownTeamMismatch = 0x6C0;
        constexpr  ptrdiff_t m_bIsHLTV = 0x6E8;
        constexpr  ptrdiff_t m_bIsLocalPlayerController = 0x788;
        constexpr  ptrdiff_t m_bNoClipEnabled = 0x789;
        constexpr  ptrdiff_t m_bExposeExternally = 0x118;
        constexpr  ptrdiff_t m_bExposedVariableIsFixedRange = 0x20;
        constexpr  ptrdiff_t m_bValueBoolean = 0x44;
        constexpr  ptrdiff_t m_bHasFloatBounds = 0x58;
        constexpr  ptrdiff_t m_bMuzzleFlashEnabled = 0x20;
        constexpr  ptrdiff_t m_bCastsShadows = 0x58;
        constexpr  ptrdiff_t needsprocessing = 0x0;
        constexpr  ptrdiff_t m_bEnableChildModel = 0xF8;
        constexpr  ptrdiff_t m_bIronSightAvailable = 0x10;
        constexpr  ptrdiff_t m_bPassWhenTrue = 0x20;
        constexpr  ptrdiff_t m_bIsScratchTarget = 0x304;
        constexpr  ptrdiff_t m_bSplatDebugInfo = 0x310;
        constexpr  ptrdiff_t m_bCaptureInRenderDoc = 0x311;
        constexpr  ptrdiff_t m_bSpotLight = 0x10;
        constexpr  ptrdiff_t m_bEnableShadows = 0x8C;
        constexpr  ptrdiff_t m_bOldEnableShadows = 0x8D;
        constexpr  ptrdiff_t m_bBackgroundClearNotRequired = 0x8E;
        constexpr  ptrdiff_t m_bEnableSeparateSkyboxFog = 0xC4;
    }

        // ============================================
        // Context: buttons
        // ============================================
        namespace buttons
    {
        constexpr  ptrdiff_t attack = 0x2065A90;
        constexpr  ptrdiff_t attack2 = 0x2065B20;
        constexpr  ptrdiff_t back = 0x2065D60;
        constexpr  ptrdiff_t duck = 0x2066030;
        constexpr  ptrdiff_t forward = 0x2065CD0;
        constexpr  ptrdiff_t jump = 0x2065FA0;
        constexpr  ptrdiff_t left = 0x2065DF0;
        constexpr  ptrdiff_t lookatweapon = 0x2355FE0;
        constexpr  ptrdiff_t reload = 0x2065A00;
        constexpr  ptrdiff_t right = 0x2065E80;
        constexpr  ptrdiff_t showscores = 0x2355EC0;
        constexpr  ptrdiff_t sprint = 0x2065970;
        constexpr  ptrdiff_t turnleft = 0x2065BB0;
        constexpr  ptrdiff_t turnright = 0x2065C40;
        constexpr  ptrdiff_t use = 0x2065F10;
        constexpr  ptrdiff_t zoom = 0x2355F50;
    }

    // ============================================
    // Context: char
    // ============================================
    namespace chars
    {
        constexpr  ptrdiff_t m_pParticleDef = 0x1090;
        constexpr  ptrdiff_t m_szTeamname = 0x634;
        constexpr  ptrdiff_t m_lookupFilename = 0x1098;
        constexpr  ptrdiff_t m_netlookupFilename = 0x624;
        constexpr  ptrdiff_t m_szCurrentLoadCachedFileName = 0x88;
        constexpr  ptrdiff_t m_szCustomName = 0x2F8;
        constexpr  ptrdiff_t m_szCustomNameOverride = 0x399;
        constexpr  ptrdiff_t m_messageText = 0x1200;
        constexpr  ptrdiff_t m_szLastPlaceName = 0x14B4;
        constexpr  ptrdiff_t m_szRagdollDamageWeaponName = 0x1AE8;
        constexpr  ptrdiff_t m_FontName = 0x11D0;
        constexpr  ptrdiff_t m_BackgroundMaterialName = 0x1210;
        constexpr  ptrdiff_t m_szTeamMatchStat = 0x6B8;
        constexpr  ptrdiff_t m_szClanTeamname = 0x8CC;
        constexpr  ptrdiff_t m_szTeamFlagImage = 0x954;
        constexpr  ptrdiff_t m_szTeamLogoImage = 0x95C;
        constexpr  ptrdiff_t m_szSnapshotFileName = 0xFA8;
        constexpr  ptrdiff_t m_szTournamentEventName = 0xB8;
        constexpr  ptrdiff_t m_szTournamentEventStage = 0x2B8;
        constexpr  ptrdiff_t m_szMatchStatTxt = 0x4B8;
        constexpr  ptrdiff_t m_szTournamentPredictionsTxt = 0x6B8;
        constexpr  ptrdiff_t m_pReticleHintTextName = 0x16C8;
        constexpr  ptrdiff_t m_pszImpactEffect = 0x11B8;
        constexpr  ptrdiff_t m_pszParticleEffect = 0x11C0;
        constexpr  ptrdiff_t m_szPlaceName = 0x63D;
        constexpr  ptrdiff_t m_iszPlayerName = 0x6F4;
        constexpr  ptrdiff_t m_textureName = 0x70;
    }

        // ============================================
        // Context: client_dll
        // ============================================
        namespace client_dll
    {
        constexpr  ptrdiff_t dwCSGOInput = 0x23560C0;
        constexpr  ptrdiff_t dwEntityList = 0x24E7680;
        constexpr  ptrdiff_t dwGameEntitySystem = 0x24E7680;
        constexpr  ptrdiff_t dwGameEntitySystem_highestEntityIndex = 0x2090;
        constexpr  ptrdiff_t dwGameRules = 0x2340FE8;
        constexpr  ptrdiff_t dwGlobalVars = 0x20616D0;
        constexpr  ptrdiff_t dwGlowManager = 0x233DDE0;
        constexpr  ptrdiff_t dwLocalPlayerController = 0x2320570;
        constexpr  ptrdiff_t dwLocalPlayerPawn = 0x2341528;
        constexpr  ptrdiff_t dwPlantedC4 = 0x234FE28;
        constexpr  ptrdiff_t dwPrediction = 0x2341430;
        constexpr  ptrdiff_t dwSensitivity = 0x233E8F8;
        constexpr  ptrdiff_t dwSensitivity_sensitivity = 0x58;
        constexpr  ptrdiff_t dwViewAngles = 0x2356748;
        constexpr  ptrdiff_t dwViewMatrix = 0x23469C0;
        constexpr  ptrdiff_t dwViewRender = 0x2346D70;
        constexpr  ptrdiff_t dwWeaponC4 = 0x22BED18;
    }

    // ============================================
    // Context: engine2_dll
    // ============================================
    namespace engine2_dll
    {
        constexpr  ptrdiff_t dwBuildNumber = 0x60CC74;
        constexpr  ptrdiff_t dwNetworkGameClient = 0x90A1A0;
        constexpr  ptrdiff_t dwNetworkGameClient_clientTickCount = 0x378;
        constexpr  ptrdiff_t dwNetworkGameClient_deltaTick = 0x24C;
        constexpr  ptrdiff_t dwNetworkGameClient_isBackgroundMap = 0x2C141F;
        constexpr  ptrdiff_t dwNetworkGameClient_localPlayer = 0xF8;
        constexpr  ptrdiff_t dwNetworkGameClient_maxClients = 0x240;
        constexpr  ptrdiff_t dwNetworkGameClient_serverTickCount = 0x24C;
        constexpr  ptrdiff_t dwNetworkGameClient_signOnState = 0x230;
        constexpr  ptrdiff_t dwWindowHeight = 0x90E5C4;
        constexpr  ptrdiff_t dwWindowWidth = 0x90E5C0;
    }

    // ============================================
    // Context: filter_t
    // ============================================
    namespace filter_t
    {
        constexpr  ptrdiff_t m_nFilterType = 0x638;
    }

    // ============================================
    // Context: float32
    // ============================================
    namespace float32
    {
        constexpr  ptrdiff_t starttime = 0x0;
        constexpr  ptrdiff_t m_flValue = 0x34;
        constexpr  ptrdiff_t m_flInitialValue = 0x38;
        constexpr  ptrdiff_t m_flMinGustDelay = 0x1C;
        constexpr  ptrdiff_t m_flMaxGustDelay = 0x20;
        constexpr  ptrdiff_t m_flGustDuration = 0x24;
        constexpr  ptrdiff_t m_flInitialWindSpeed = 0x2C;
        constexpr  ptrdiff_t m_flEndDistance = 0x600;
        constexpr  ptrdiff_t m_flStartDistance = 0x604;
        constexpr  ptrdiff_t m_flFogFalloffExponent = 0x608;
        constexpr  ptrdiff_t m_flFogHeightWidth = 0x610;
        constexpr  ptrdiff_t m_flFogHeightEnd = 0x614;
        constexpr  ptrdiff_t m_flFogHeightStart = 0x618;
        constexpr  ptrdiff_t m_flFogHeightExponent = 0x61C;
        constexpr  ptrdiff_t m_flLODBias = 0x620;
        constexpr  ptrdiff_t m_flFogMaxOpacity = 0x628;
        constexpr  ptrdiff_t m_flAlphaScale = 0x1558;
        constexpr  ptrdiff_t m_flRadiusScale = 0x155C;
        constexpr  ptrdiff_t m_flSelfIllumScale = 0x1560;
        constexpr  ptrdiff_t m_flLastActualJumpPressFrac = 0x14;
        constexpr  ptrdiff_t m_flLastUsableJumpPressFrac = 0x1C;
        constexpr  ptrdiff_t m_flLastLandedFrac = 0x24;
        constexpr  ptrdiff_t m_flLastLandedVelocityX = 0x28;
        constexpr  ptrdiff_t m_flLastLandedVelocityY = 0x2C;
        constexpr  ptrdiff_t m_flLastLandedVelocityZ = 0x30;
        constexpr  ptrdiff_t m_flForce = 0x10B4;
        constexpr  ptrdiff_t m_flTimeCreated = 0x1194;
        constexpr  ptrdiff_t m_flStrength = 0x620;
        constexpr  ptrdiff_t m_flFalloffExponent = 0x628;
        constexpr  ptrdiff_t m_flHeightFogDepth = 0x62C;
        constexpr  ptrdiff_t m_fHeightFogEdgeWidth = 0x630;
        constexpr  ptrdiff_t m_fIndirectLightStrength = 0x634;
        constexpr  ptrdiff_t m_fSunLightStrength = 0x638;
        constexpr  ptrdiff_t m_fNoiseStrength = 0x63C;
        constexpr  ptrdiff_t m_flColorTemperature = 0xFB4;
        constexpr  ptrdiff_t m_flBrightness = 0xFB8;
        constexpr  ptrdiff_t m_flBrightnessScale = 0xFBC;
        constexpr  ptrdiff_t m_flLuminaireSize = 0xFD4;
        constexpr  ptrdiff_t m_flLuminaireAnisotropy = 0xFD8;
        constexpr  ptrdiff_t m_flShape = 0x10A0;
        constexpr  ptrdiff_t m_flSoftX = 0x10A4;
        constexpr  ptrdiff_t m_flSoftY = 0x10A8;
        constexpr  ptrdiff_t m_flSkirt = 0x10AC;
        constexpr  ptrdiff_t m_flSkirtNear = 0x10B0;
        constexpr  ptrdiff_t m_flRange = 0x10C0;
        constexpr  ptrdiff_t m_flBakeSpecularToCubemapsScale = 0x10E0;
        constexpr  ptrdiff_t m_flBounceScale = 0x10F8;
        constexpr  ptrdiff_t m_flMinRoughness = 0x10FC;
        constexpr  ptrdiff_t m_fAlternateColorBrightness = 0x110C;
        constexpr  ptrdiff_t m_flFogStrength = 0x1114;
        constexpr  ptrdiff_t m_flFogScale = 0x111C;
        constexpr  ptrdiff_t m_flFadeSizeStart = 0x1120;
        constexpr  ptrdiff_t m_flFadeSizeEnd = 0x1124;
        constexpr  ptrdiff_t m_flShadowFadeSizeStart = 0x1128;
        constexpr  ptrdiff_t m_flShadowFadeSizeEnd = 0x112C;
        constexpr  ptrdiff_t m_flSeconds = 0x90;
        constexpr  ptrdiff_t m_flSeenTargetTime = 0x1204;
        constexpr  ptrdiff_t m_flFadeDuration = 0x1090;
        constexpr  ptrdiff_t m_flMinLogExposure = 0x1094;
        constexpr  ptrdiff_t m_flMaxLogExposure = 0x1098;
        constexpr  ptrdiff_t m_flMinExposure = 0x109C;
        constexpr  ptrdiff_t m_flMaxExposure = 0x10A0;
        constexpr  ptrdiff_t m_flExposureCompensation = 0x10A4;
        constexpr  ptrdiff_t m_flExposureFadeSpeedUp = 0x10A8;
        constexpr  ptrdiff_t m_flExposureFadeSpeedDown = 0x10AC;
        constexpr  ptrdiff_t m_flTonemapEVSmoothingRange = 0x10B0;
        constexpr  ptrdiff_t m_flAmount = 0x18;
        constexpr  ptrdiff_t m_fFanForceMaxRadius = 0x640;
        constexpr  ptrdiff_t m_fFanForceMinRadius = 0x644;
        constexpr  ptrdiff_t m_flCurveDistRange = 0x648;
        constexpr  ptrdiff_t m_flProgressBarStartTime = 0x13E4;
        constexpr  ptrdiff_t m_flFlashBangTime = 0x13EC;
        constexpr  ptrdiff_t m_flFlashScreenshotAlpha = 0x13F0;
        constexpr  ptrdiff_t m_flFlashOverlayAlpha = 0x13F4;
        constexpr  ptrdiff_t m_flFlashMaxAlpha = 0x13FC;
        constexpr  ptrdiff_t m_flFlashDuration = 0x1400;
        constexpr  ptrdiff_t m_fNextThinkPushAway = 0x140C;
        constexpr  ptrdiff_t m_flCurrentMusicStartTime = 0x1414;
        constexpr  ptrdiff_t m_flMusicRoundStartTime = 0x1418;
        constexpr  ptrdiff_t m_flLastSmokeOverlayAlpha = 0x1420;
        constexpr  ptrdiff_t m_flLastSmokeAge = 0x1424;
        constexpr  ptrdiff_t m_impactEnergyScale = 0x1238;
        constexpr  ptrdiff_t m_flPressureDelay = 0x1240;
        constexpr  ptrdiff_t m_flDefBurstScale = 0x1244;
        constexpr  ptrdiff_t m_explodeDamage = 0x127C;
        constexpr  ptrdiff_t m_explodeRadius = 0x1280;
        constexpr  ptrdiff_t m_explosionDelay = 0x1290;
        constexpr  ptrdiff_t m_flDefaultFadeScale = 0x12C0;
        constexpr  ptrdiff_t m_flInnerDistance = 0x108;
        constexpr  ptrdiff_t m_flRadius = 0x628;
        constexpr  ptrdiff_t m_flBoundsExpandRadius = 0x14;
        constexpr  ptrdiff_t m_flDensity = 0x1078;
        constexpr  ptrdiff_t m_flParticleInnerDist = 0x1088;
        constexpr  ptrdiff_t m_flSeqFixedCycle = 0x8;
        constexpr  ptrdiff_t m_flPlaybackRate = 0x10;
        constexpr  ptrdiff_t m_flCyclesPerSecond = 0x14;
        constexpr  ptrdiff_t m_flLightScale = 0xFA8;
        constexpr  ptrdiff_t m_Radius = 0xFAC;
        constexpr  ptrdiff_t m_deathDepth = 0x1180;
        constexpr  ptrdiff_t m_deathAngle = 0x1184;
        constexpr  ptrdiff_t m_buoyancy = 0x1188;
        constexpr  ptrdiff_t m_wigglePhase = 0x11A8;
        constexpr  ptrdiff_t m_wiggleRate = 0x11AC;
        constexpr  ptrdiff_t m_waterLevel = 0x11D4;
        constexpr  ptrdiff_t m_x = 0x11DC;
        constexpr  ptrdiff_t m_y = 0x11E0;
        constexpr  ptrdiff_t m_z = 0x11E4;
        constexpr  ptrdiff_t m_angle = 0x11E8;
        constexpr  ptrdiff_t m_errorHistory = 0x11EC;
        constexpr  ptrdiff_t m_averageError = 0x1244;
        constexpr  ptrdiff_t m_flScattering = 0x600;
        constexpr  ptrdiff_t m_flAnisotropy = 0x608;
        constexpr  ptrdiff_t m_flFadeSpeed = 0x60C;
        constexpr  ptrdiff_t m_flDrawDistance = 0x610;
        constexpr  ptrdiff_t m_flFadeInStart = 0x614;
        constexpr  ptrdiff_t m_flFadeInEnd = 0x618;
        constexpr  ptrdiff_t m_flIndirectStrength = 0x61C;
        constexpr  ptrdiff_t m_fFirstVolumeSliceThickness = 0x624;
        constexpr  ptrdiff_t m_flStartAnisotropy = 0x65C;
        constexpr  ptrdiff_t m_flStartScattering = 0x660;
        constexpr  ptrdiff_t m_flStartDrawDistance = 0x664;
        constexpr  ptrdiff_t m_flDefaultAnisotropy = 0x668;
        constexpr  ptrdiff_t m_flDefaultScattering = 0x66C;
        constexpr  ptrdiff_t m_flDefaultDrawDistance = 0x670;
        constexpr  ptrdiff_t m_fNoiseSpeed = 0x684;
        constexpr  ptrdiff_t m_fWindSpeed = 0x698;
        constexpr  ptrdiff_t m_flFadeStartDist = 0x600;
        constexpr  ptrdiff_t m_flFadeEndDist = 0x604;
        constexpr  ptrdiff_t m_fWindSpeedMultiplier = 0x624;
        constexpr  ptrdiff_t m_fWindTurbulenceMultiplier = 0x628;
        constexpr  ptrdiff_t m_fWindSpeedVariationMultiplier = 0x62C;
        constexpr  ptrdiff_t m_fWindDirectionVariationMultiplier = 0x630;
        constexpr  ptrdiff_t m_flJumpPressedTime = 0x14;
        constexpr  ptrdiff_t m_LastEnterWeight = 0x1078;
        constexpr  ptrdiff_t m_LastExitWeight = 0x1080;
        constexpr  ptrdiff_t m_MaxWeight = 0x108C;
        constexpr  ptrdiff_t m_FadeDuration = 0x1090;
        constexpr  ptrdiff_t m_Weight = 0x1094;
        constexpr  ptrdiff_t m_flCmdForwardMove = 0x1A0;
        constexpr  ptrdiff_t m_flCmdLeftMove = 0x1A4;
        constexpr  ptrdiff_t m_flCmdUpMove = 0x1A8;
        constexpr  ptrdiff_t m_flMaxspeed = 0x1AC;
        constexpr  ptrdiff_t m_arrForceSubtickMoveWhen = 0x1B0;
        constexpr  ptrdiff_t m_flForwardMove = 0x1C0;
        constexpr  ptrdiff_t m_flLeftMove = 0x1C4;
        constexpr  ptrdiff_t m_flUpMove = 0x1C8;
        constexpr  ptrdiff_t m_flSoundSyncTime = 0x58;
        constexpr  ptrdiff_t m_MinFalloff = 0x60C;
        constexpr  ptrdiff_t m_MaxFalloff = 0x610;
        constexpr  ptrdiff_t m_flFadeInDuration = 0x614;
        constexpr  ptrdiff_t m_flFadeOutDuration = 0x618;
        constexpr  ptrdiff_t m_flMaxWeight = 0x61C;
        constexpr  ptrdiff_t m_flCurWeight = 0x620;
        constexpr  ptrdiff_t m_flCurWeightOnClient = 0x82C;
        constexpr  ptrdiff_t m_flFadeStartWeight = 0x834;
        constexpr  ptrdiff_t m_flFadeStartTime = 0x838;
        constexpr  ptrdiff_t m_flFluidDensity = 0x1C;
        constexpr  ptrdiff_t m_flNeutrallyBuoyantGravity = 0x20;
        constexpr  ptrdiff_t m_flNeutrallyBuoyantLinearDamping = 0x24;
        constexpr  ptrdiff_t m_flNeutrallyBuoyantAngularDamping = 0x28;
        constexpr  ptrdiff_t m_flDeathCamTilt = 0x2A8;
        constexpr  ptrdiff_t m_flTimeFromPrevious = 0x0;
        constexpr  ptrdiff_t m_flWaitInterval = 0x8;
        constexpr  ptrdiff_t m_flWaitIntervalHigh = 0xC;
        constexpr  ptrdiff_t m_flMaxSimulationTime = 0x60C;
        constexpr  ptrdiff_t m_flParticleSpacing = 0x630;
        constexpr  ptrdiff_t m_flSlack = 0x634;
        constexpr  ptrdiff_t m_flCrosshairDistance = 0x1790;
        constexpr  ptrdiff_t m_flTurningInaccuracyDelta = 0x17BC;
        constexpr  ptrdiff_t m_flTurningInaccuracy = 0x17CC;
        constexpr  ptrdiff_t m_fAccuracyPenalty = 0x17D0;
        constexpr  ptrdiff_t m_fAccuracySmoothedForZoom = 0x17D8;
        constexpr  ptrdiff_t m_flRecoilIndex = 0x17E0;
        constexpr  ptrdiff_t m_flPostponeFireReadyFrac = 0x17F0;
        constexpr  ptrdiff_t m_flWeaponActionPlaybackRate = 0x180C;
        constexpr  ptrdiff_t m_flNextAttackRenderTimeOffset = 0x181C;
        constexpr  ptrdiff_t m_flNextClientFireBulletTime = 0x1908;
        constexpr  ptrdiff_t m_flNextClientFireBulletTime_Repredict = 0x190C;
        constexpr  ptrdiff_t m_flWatTickOffset = 0x1AE8;
        constexpr  ptrdiff_t m_flValues = 0x10;
        constexpr  ptrdiff_t m_flInterval = 0x214;
        constexpr  ptrdiff_t m_flFinalValue = 0x218;
        constexpr  ptrdiff_t m_flAutoExposureMin = 0x600;
        constexpr  ptrdiff_t m_flAutoExposureMax = 0x604;
        constexpr  ptrdiff_t m_flExposureAdaptationSpeedUp = 0x608;
        constexpr  ptrdiff_t m_flExposureAdaptationSpeedDown = 0x60C;
        constexpr  ptrdiff_t m_duration = 0x8;
        constexpr  ptrdiff_t m_timescale = 0x10;
        constexpr  ptrdiff_t m_flWidth = 0x115C;
        constexpr  ptrdiff_t m_flHeight = 0x1160;
        constexpr  ptrdiff_t m_flDPI = 0x1164;
        constexpr  ptrdiff_t m_flInteractDistance = 0x1168;
        constexpr  ptrdiff_t m_flDepthOffset = 0x116C;
        constexpr  ptrdiff_t m_flStartTimeInCommentary = 0x117C;
        constexpr  ptrdiff_t m_flGlassHalfThickness = 0x70;
        constexpr  ptrdiff_t m_flWaterJumpTime = 0x48;
        constexpr  ptrdiff_t m_flSwimSoundTime = 0x58;
        constexpr  ptrdiff_t m_flAutoRideSpeed = 0xFF4;
        constexpr  ptrdiff_t m_flFOVRate = 0x29C;
        constexpr  ptrdiff_t m_flLastShotFOV = 0x2A4;
        constexpr  ptrdiff_t m_flLandingTimeSeconds = 0x14AC;
        constexpr  ptrdiff_t m_flOldFallVelocity = 0x14B0;
        constexpr  ptrdiff_t m_flLandingStartTime = 0x14DC;
        constexpr  ptrdiff_t m_flViewmodelOffsetX = 0x1B70;
        constexpr  ptrdiff_t m_flViewmodelOffsetY = 0x1B74;
        constexpr  ptrdiff_t m_flViewmodelOffsetZ = 0x1B78;
        constexpr  ptrdiff_t m_flViewmodelFOV = 0x1B7C;
        constexpr  ptrdiff_t m_flFlinchStack = 0x1C68;
        constexpr  ptrdiff_t m_flVelocityModifier = 0x1C6C;
        constexpr  ptrdiff_t m_ignoreLadderJumpTime = 0x1C74;
        constexpr  ptrdiff_t m_flDeathInfoTime = 0x1C90;
        constexpr  ptrdiff_t m_fMolotovDamageTime = 0x3240;
        constexpr  ptrdiff_t m_flTransitionTime = 0xC;
        constexpr  ptrdiff_t m_flOldStart = 0x14;
        constexpr  ptrdiff_t m_flOldEnd = 0x18;
        constexpr  ptrdiff_t m_flOldMaxDensity = 0x1C;
        constexpr  ptrdiff_t m_flOldHDRColorScale = 0x20;
        constexpr  ptrdiff_t m_flOldFarZ = 0x24;
        constexpr  ptrdiff_t m_flNewStart = 0x2C;
        constexpr  ptrdiff_t m_flNewEnd = 0x30;
        constexpr  ptrdiff_t m_flNewMaxDensity = 0x34;
        constexpr  ptrdiff_t m_flNewHDRColorScale = 0x38;
        constexpr  ptrdiff_t m_flNewFarZ = 0x3C;
        constexpr  ptrdiff_t m_flScale = 0xC4;
        constexpr  ptrdiff_t m_flAbsScale = 0xE0;
        constexpr  ptrdiff_t m_flWrappedScale = 0xFC;
        constexpr  ptrdiff_t m_flClientLocalScale = 0x124;
        constexpr  ptrdiff_t m_flObserverChaseDistance = 0x58;
        constexpr  ptrdiff_t m_flVisibilityStrength = 0x600;
        constexpr  ptrdiff_t m_flFogDistanceMultiplier = 0x604;
        constexpr  ptrdiff_t m_flFogMaxDensityMultiplier = 0x608;
        constexpr  ptrdiff_t m_flFadeTime = 0x60C;
        constexpr  ptrdiff_t flIn = 0x0;
        constexpr  ptrdiff_t flOut = 0x10;
        constexpr  ptrdiff_t m_flNextPrimaryAttackTickRatio = 0x16CC;
        constexpr  ptrdiff_t m_flNextSecondaryAttackTickRatio = 0x16D4;
        constexpr  ptrdiff_t m_flFogMinStart = 0xFCC;
        constexpr  ptrdiff_t m_flFogMinEnd = 0xFD0;
        constexpr  ptrdiff_t m_flFogMaxStart = 0xFD4;
        constexpr  ptrdiff_t m_flFogMaxEnd = 0xFD8;
        constexpr  ptrdiff_t m_fDirectionVariation = 0x6F8;
        constexpr  ptrdiff_t m_fSpeedVariation = 0x6FC;
        constexpr  ptrdiff_t m_fTurbulence = 0x700;
        constexpr  ptrdiff_t m_fVolumeHalfExtentXY = 0x704;
        constexpr  ptrdiff_t m_fVolumeHalfExtentZ = 0x708;
        constexpr  ptrdiff_t m_flZFar = 0x600;
        constexpr  ptrdiff_t m_flZNear = 0x604;
        constexpr  ptrdiff_t m_flDuration = 0x60C;
        constexpr  ptrdiff_t m_flPathLength = 0x650;
        constexpr  ptrdiff_t m_flPathDuration = 0x654;
        constexpr  ptrdiff_t m_flDofNearBlurry = 0x670;
        constexpr  ptrdiff_t m_flDofNearCrisp = 0x674;
        constexpr  ptrdiff_t m_flDofFarCrisp = 0x678;
        constexpr  ptrdiff_t m_flDofFarBlurry = 0x67C;
        constexpr  ptrdiff_t m_flDofTiltToGround = 0x680;
        constexpr  ptrdiff_t m_flWorldUnitsPerPx = 0x1254;
        constexpr  ptrdiff_t m_flFontSize = 0x1258;
        constexpr  ptrdiff_t m_flBackgroundBorderWidth = 0x1264;
        constexpr  ptrdiff_t m_flBackgroundBorderHeight = 0x1268;
        constexpr  ptrdiff_t m_flBackgroundWorldToUV = 0x126C;
        constexpr  ptrdiff_t m_flCurScroll = 0xFE0;
        constexpr  ptrdiff_t m_flScrollSpeed = 0xFE4;
        constexpr  ptrdiff_t m_TextureScale = 0x127C;
        constexpr  ptrdiff_t m_Width = 0x1284;
        constexpr  ptrdiff_t m_flCurrentGustTimer = 0x12BC;
        constexpr  ptrdiff_t m_flCurrentGustLifetime = 0x12C0;
        constexpr  ptrdiff_t m_flTimeToNextGust = 0x12C4;
        constexpr  ptrdiff_t m_flPrevCycle = 0xC;
        constexpr  ptrdiff_t m_flCycle = 0x10;
        constexpr  ptrdiff_t m_flPrevCycleFromDiscontinuity = 0x20;
        constexpr  ptrdiff_t m_flPrevCycleForAnimEventDetection = 0x24;
        constexpr  ptrdiff_t m_flGlowBackfaceMult = 0xE30;
        constexpr  ptrdiff_t m_fadeMinDist = 0xE34;
        constexpr  ptrdiff_t m_fadeMaxDist = 0xE38;
        constexpr  ptrdiff_t m_flFadeScale = 0xE3C;
        constexpr  ptrdiff_t m_flShadowStrength = 0xE40;
        constexpr  ptrdiff_t m_Entity_flBrightness = 0x167C;
        constexpr  ptrdiff_t m_Entity_flEdgeFadeDist = 0x1704;
        constexpr  ptrdiff_t m_flDamageAccumulator = 0x350;
        constexpr  ptrdiff_t m_flProxyRandomValue = 0x370;
        constexpr  ptrdiff_t m_flAnimTime = 0x3B4;
        constexpr  ptrdiff_t m_flSimulationTime = 0x3B8;
        constexpr  ptrdiff_t m_flSpeed = 0x3E4;
        constexpr  ptrdiff_t m_flWaterLevel = 0x528;
        constexpr  ptrdiff_t m_flFriction = 0x538;
        constexpr  ptrdiff_t m_flElasticity = 0x53C;
        constexpr  ptrdiff_t m_flGravityScale = 0x540;
        constexpr  ptrdiff_t m_flTimeScale = 0x544;
        constexpr  ptrdiff_t m_flActualGravityScale = 0x564;
        constexpr  ptrdiff_t m_flFOVSensitivityAdjust = 0x1388;
        constexpr  ptrdiff_t m_flMouseSensitivity = 0x138C;
        constexpr  ptrdiff_t m_flOldSimulationTime = 0x139C;
        constexpr  ptrdiff_t m_flSavedElapsedTime = 0x608;
        constexpr  ptrdiff_t m_flClientCullRadius = 0x668;
        constexpr  ptrdiff_t m_flCycleTimeWhenInBurstMode = 0x748;
        constexpr  ptrdiff_t m_flTimeBetweenBurstShots = 0x74C;
        constexpr  ptrdiff_t m_flInaccuracyJumpInitial = 0x7C0;
        constexpr  ptrdiff_t m_flInaccuracyJumpApex = 0x7C4;
        constexpr  ptrdiff_t m_flInaccuracyReload = 0x7C8;
        constexpr  ptrdiff_t m_flDeployDuration = 0x7CC;
        constexpr  ptrdiff_t m_flDisallowAttackAfterReloadStartDuration = 0x7D0;
        constexpr  ptrdiff_t m_flAttackMovespeedFactor = 0x7E4;
        constexpr  ptrdiff_t m_flInaccuracyPitchShift = 0x7E8;
        constexpr  ptrdiff_t m_flInaccuracyAltSoundThreshold = 0x7EC;
        constexpr  ptrdiff_t m_flZoomTime0 = 0x808;
        constexpr  ptrdiff_t m_flZoomTime1 = 0x80C;
        constexpr  ptrdiff_t m_flZoomTime2 = 0x810;
        constexpr  ptrdiff_t m_flIronSightPullUpSpeed = 0x814;
        constexpr  ptrdiff_t m_flIronSightPutDownSpeed = 0x818;
        constexpr  ptrdiff_t m_flIronSightFOV = 0x81C;
        constexpr  ptrdiff_t m_flIronSightPivotForward = 0x820;
        constexpr  ptrdiff_t m_flIronSightLooseness = 0x824;
        constexpr  ptrdiff_t m_flHeadshotMultiplier = 0x82C;
        constexpr  ptrdiff_t m_flArmorRatio = 0x830;
        constexpr  ptrdiff_t m_flPenetration = 0x834;
        constexpr  ptrdiff_t m_flRangeModifier = 0x83C;
        constexpr  ptrdiff_t m_flFlinchVelocityModifierLarge = 0x840;
        constexpr  ptrdiff_t m_flFlinchVelocityModifierSmall = 0x844;
        constexpr  ptrdiff_t m_flRecoveryTimeCrouch = 0x848;
        constexpr  ptrdiff_t m_flRecoveryTimeStand = 0x84C;
        constexpr  ptrdiff_t m_flRecoveryTimeCrouchFinal = 0x850;
        constexpr  ptrdiff_t m_flRecoveryTimeStandFinal = 0x854;
        constexpr  ptrdiff_t m_flThrowVelocity = 0x860;
        constexpr  ptrdiff_t m_flCsViewPunchAngleTickRatio = 0x58;
        constexpr  ptrdiff_t m_flOldPlayerZ = 0x140;
        constexpr  ptrdiff_t m_flOldPlayerViewOffsetZ = 0x144;
        constexpr  ptrdiff_t m_fOverrideFogStart = 0x1D4;
        constexpr  ptrdiff_t m_fOverrideFogEnd = 0x1E8;
        constexpr  ptrdiff_t m_flThrowStrength = 0x1CC0;
        constexpr  ptrdiff_t m_flNextHoldFrac = 0x1D48;
        constexpr  ptrdiff_t m_flTimeoutInterval = 0x618;
        constexpr  ptrdiff_t m_flInitialModelScale = 0x1164;
        constexpr  ptrdiff_t m_flUsingGroundTopologyOffsetTransitionSmoothing = 0x3F4;
        constexpr  ptrdiff_t m_flDuckAmount = 0x40C;
        constexpr  ptrdiff_t m_flDuckSpeed = 0x410;
        constexpr  ptrdiff_t m_flDuckRootOffset = 0x418;
        constexpr  ptrdiff_t m_flDuckViewOffset = 0x41C;
        constexpr  ptrdiff_t m_flLastDuckTime = 0x420;
        constexpr  ptrdiff_t m_flBombPlantViewOffset = 0x424;
        constexpr  ptrdiff_t m_flWaterEntryTime = 0x658;
        constexpr  ptrdiff_t m_flUseFrictionStashedSpeedUntilFrac = 0x694;
        constexpr  ptrdiff_t m_flFrictionStashedSpeed = 0x698;
        constexpr  ptrdiff_t m_flStamina = 0x69C;
        constexpr  ptrdiff_t m_flHeightAtJumpStart = 0x6A0;
        constexpr  ptrdiff_t m_flMaxJumpHeightThisJump = 0x6A4;
        constexpr  ptrdiff_t m_flMaxJumpHeightLastJump = 0x6A8;
        constexpr  ptrdiff_t m_flStaminaAtJumpStart = 0x6AC;
        constexpr  ptrdiff_t m_flVelMulAtJumpStart = 0x6B0;
        constexpr  ptrdiff_t m_flAccumulatedJumpError = 0x6B4;
        constexpr  ptrdiff_t m_flLastJumpFrac = 0x70C;
        constexpr  ptrdiff_t m_flLastJumpVelocityZ = 0x710;
        constexpr  ptrdiff_t m_flTicksSinceLastSurfingDetected = 0x718;
        constexpr  ptrdiff_t m_flDmgModBullet = 0x10;
        constexpr  ptrdiff_t m_flDmgModClub = 0x14;
        constexpr  ptrdiff_t m_flDmgModExplosive = 0x18;
        constexpr  ptrdiff_t m_flDmgModFire = 0x1C;
        constexpr  ptrdiff_t m_InnerAngle = 0xFB4;
        constexpr  ptrdiff_t m_OuterAngle = 0xFB8;
        constexpr  ptrdiff_t m_SpotRadius = 0xFBC;
        constexpr  ptrdiff_t m_timestamp = 0xC;
        constexpr  ptrdiff_t m_nFireLifetime = 0x1960;
        constexpr  ptrdiff_t m_maxFireHalfWidth = 0x857C;
        constexpr  ptrdiff_t m_maxFireHeight = 0x8580;
        constexpr  ptrdiff_t m_flLastGrassBurnThink = 0x859C;
        constexpr  ptrdiff_t m_flMaxTurnRate = 0x618;
        constexpr  ptrdiff_t flClip3DSkyBoxNearToWorldFarOffset = 0x1C;
        constexpr  ptrdiff_t m_flEmitterAngle = 0x6C0;
        constexpr  ptrdiff_t m_flSweetSpotAngle = 0x6C4;
        constexpr  ptrdiff_t m_flAttenMin = 0x6C8;
        constexpr  ptrdiff_t m_flAttenMax = 0x6CC;
        constexpr  ptrdiff_t m_flTotalRoundDamageDealt = 0x130;
        constexpr  ptrdiff_t m_flStepSoundTime = 0x258;
        constexpr  ptrdiff_t m_flFallVelocity = 0x25C;
        constexpr  ptrdiff_t m_flSurfaceFriction = 0x26C;
        constexpr  ptrdiff_t m_flRootBoneOffset_x = 0xE8;
        constexpr  ptrdiff_t m_flRootBoneOffset_y = 0xEC;
        constexpr  ptrdiff_t m_flRootBoneOffset_z = 0xF0;
        constexpr  ptrdiff_t m_flBoundingRadius = 0x60;
        constexpr  ptrdiff_t m_flCapsuleRadius = 0xAC;
        constexpr  ptrdiff_t m_fFilterMass = 0x638;
        constexpr  ptrdiff_t m_flFadeInLength = 0xFB8;
        constexpr  ptrdiff_t m_flFadeOutModelStart = 0xFBC;
        constexpr  ptrdiff_t m_flFadeOutModelLength = 0xFC0;
        constexpr  ptrdiff_t m_flFadeOutStart = 0xFC4;
        constexpr  ptrdiff_t m_flFadeOutLength = 0xFC8;
        constexpr  ptrdiff_t m_flScaleEnd = 0x1178;
        constexpr  ptrdiff_t m_flFPS = 0xFAC;
        constexpr  ptrdiff_t m_flStartTime = 0xFD8;
        constexpr  ptrdiff_t m_flStartFrame = 0xFDC;
        constexpr  ptrdiff_t m_gravityScale = 0x1078;
        constexpr  ptrdiff_t m_linearLimit = 0x107C;
        constexpr  ptrdiff_t m_linearDamping = 0x1080;
        constexpr  ptrdiff_t m_angularLimit = 0x1084;
        constexpr  ptrdiff_t m_angularDamping = 0x1088;
        constexpr  ptrdiff_t m_linearForce = 0x108C;
        constexpr  ptrdiff_t m_flFrequency = 0x1090;
        constexpr  ptrdiff_t m_flDampingRatio = 0x1094;
        constexpr  ptrdiff_t m_flMagnitude = 0x44;
        constexpr  ptrdiff_t m_flFreezeTransitionDuration = 0x11AC;
        constexpr  ptrdiff_t m_flPreSimTime = 0x11C4;
        constexpr  ptrdiff_t m_flBrightnessMult = 0x88;
        constexpr  ptrdiff_t m_flFalloff = 0x90;
        constexpr  ptrdiff_t m_flAttenuation0 = 0x94;
        constexpr  ptrdiff_t m_flAttenuation1 = 0x98;
        constexpr  ptrdiff_t m_flAttenuation2 = 0x9C;
        constexpr  ptrdiff_t m_flTheta = 0xA0;
        constexpr  ptrdiff_t m_flPhi = 0xA4;
        constexpr  ptrdiff_t m_flOrthoLightWidth = 0xCC;
        constexpr  ptrdiff_t m_flOrthoLightHeight = 0xD0;
        constexpr  ptrdiff_t m_flShadowCascadeCrossFade = 0xE4;
        constexpr  ptrdiff_t m_flShadowCascadeDistanceFade = 0xE8;
        constexpr  ptrdiff_t m_flShadowCascadeDistance0 = 0xEC;
        constexpr  ptrdiff_t m_flShadowCascadeDistance1 = 0xF0;
        constexpr  ptrdiff_t m_flShadowCascadeDistance2 = 0xF4;
        constexpr  ptrdiff_t m_flShadowCascadeDistance3 = 0xF8;
        constexpr  ptrdiff_t m_flFadeMinDist = 0x130;
        constexpr  ptrdiff_t m_flFadeMaxDist = 0x134;
        constexpr  ptrdiff_t m_flShadowFadeMinDist = 0x138;
        constexpr  ptrdiff_t m_flShadowFadeMaxDist = 0x13C;
        constexpr  ptrdiff_t m_flPrecomputedMaxRange = 0x180;
        constexpr  ptrdiff_t m_flFogContributionStength = 0x188;
        constexpr  ptrdiff_t m_flNearClipPlane = 0x18C;
        constexpr  ptrdiff_t m_flSkyIntensity = 0x194;
        constexpr  ptrdiff_t m_flCapsuleLength = 0x1A4;
        constexpr  ptrdiff_t m_Entity_flInfluenceRadius = 0x68C;
        constexpr  ptrdiff_t m_Entity_flDiffuseScale = 0x6C8;
        constexpr  ptrdiff_t m_flWaterWorldZ = 0x1178;
        constexpr  ptrdiff_t m_flWaterNextTraceTime = 0x117C;
        constexpr  ptrdiff_t m_flGlowTime = 0x48;
        constexpr  ptrdiff_t m_flGlowStartTime = 0x4C;
        constexpr  ptrdiff_t m_flBulletsDamage = 0x60;
        constexpr  ptrdiff_t m_flDamage = 0x64;
        constexpr  ptrdiff_t m_flActualHealthRemoved = 0x68;
        constexpr  ptrdiff_t m_flInnerAngle = 0x12B8;
        constexpr  ptrdiff_t m_flOuterAngle = 0x12BC;
        constexpr  ptrdiff_t m_flForceClientTime = 0x610;
        constexpr  ptrdiff_t m_flCurrentTime = 0x660;
        constexpr  ptrdiff_t m_flFlexDelayTime = 0x1168;
        constexpr  ptrdiff_t m_flFlexDelayedWeight = 0x1170;
        constexpr  ptrdiff_t m_flFallbackWear = 0x1660;
        constexpr  ptrdiff_t m_flMaximumChangePerSecond = 0x610;
        constexpr  ptrdiff_t m_flDisengageDistance = 0x614;
        constexpr  ptrdiff_t m_flEngageDistance = 0x618;
        constexpr  ptrdiff_t m_flMomentumModifier = 0x648;
        constexpr  ptrdiff_t m_flSnapValue = 0x64C;
        constexpr  ptrdiff_t m_flCurrentMomentum = 0x650;
        constexpr  ptrdiff_t m_flRatchetOffset = 0x658;
        constexpr  ptrdiff_t m_flInputOffset = 0x65C;
        constexpr  ptrdiff_t m_flPreviousValue = 0x664;
        constexpr  ptrdiff_t m_flTerroristTimeOutRemaining = 0x50;
        constexpr  ptrdiff_t m_flCTTimeOutRemaining = 0x54;
        constexpr  ptrdiff_t m_fMatchStartTime = 0x6C;
        constexpr  ptrdiff_t m_flGameStartTime = 0x7C;
        constexpr  ptrdiff_t m_timeUntilNextPhaseStarts = 0x80;
        constexpr  ptrdiff_t m_TeamRespawnWaveTimes = 0xB20;
        constexpr  ptrdiff_t m_MinimapVerticalSectionHeights = 0xC38;
        constexpr  ptrdiff_t m_flTracerDuration = 0xFC0;
        constexpr  ptrdiff_t m_flTrajectoryTrailEffectCreationTime = 0x1230;
        constexpr  ptrdiff_t m_flFogStartDistance = 0x608;
        constexpr  ptrdiff_t m_flFogEndDistance = 0x60C;
        constexpr  ptrdiff_t m_flFogStartHeight = 0x614;
        constexpr  ptrdiff_t m_flFogEndHeight = 0x618;
        constexpr  ptrdiff_t m_flFarZ = 0x61C;
        constexpr  ptrdiff_t m_flFogVerticalExponent = 0x628;
        constexpr  ptrdiff_t m_predictableBaseTickInterpAmount = 0x4C;
        constexpr  ptrdiff_t m_parentTime = 0x120C;
        constexpr  ptrdiff_t m_flLineLength = 0xFB0;
        constexpr  ptrdiff_t m_flDepth = 0xFB8;
        constexpr  ptrdiff_t m_flDepthSortBias = 0xFC4;
        constexpr  ptrdiff_t start = 0x24;
        constexpr  ptrdiff_t end = 0x28;
        constexpr  ptrdiff_t farz = 0x2C;
        constexpr  ptrdiff_t maxdensity = 0x30;
        constexpr  ptrdiff_t exponent = 0x34;
        constexpr  ptrdiff_t HDRColorScale = 0x38;
        constexpr  ptrdiff_t skyboxFogFactor = 0x3C;
        constexpr  ptrdiff_t skyboxFogFactorLerpTo = 0x40;
        constexpr  ptrdiff_t startLerpTo = 0x44;
        constexpr  ptrdiff_t endLerpTo = 0x48;
        constexpr  ptrdiff_t maxdensityLerpTo = 0x4C;
        constexpr  ptrdiff_t duration = 0x54;
        constexpr  ptrdiff_t blendtobackground = 0x58;
        constexpr  ptrdiff_t scattering = 0x5C;
        constexpr  ptrdiff_t locallightscale = 0x60;
        constexpr  ptrdiff_t m_flFrameRate = 0xFA8;
        constexpr  ptrdiff_t m_flHDRColorScale = 0xFAC;
        constexpr  ptrdiff_t m_fWidth = 0x102C;
        constexpr  ptrdiff_t m_fEndWidth = 0x1030;
        constexpr  ptrdiff_t m_fFadeLength = 0x1034;
        constexpr  ptrdiff_t m_fHaloScale = 0x1038;
        constexpr  ptrdiff_t m_fAmplitude = 0x103C;
        constexpr  ptrdiff_t m_fStartFrame = 0x1040;
        constexpr  ptrdiff_t m_fSpeed = 0x1044;
        constexpr  ptrdiff_t m_flFrame = 0x1048;
        constexpr  ptrdiff_t m_flTargetSpeed = 0xFBC;
        constexpr  ptrdiff_t m_flTransitionStartSpeed = 0xFC8;
        constexpr  ptrdiff_t m_flCurrentConveyorOffset = 0xFE8;
        constexpr  ptrdiff_t m_flCurrentConveyorSpeed = 0xFEC;
        constexpr  ptrdiff_t m_flTimerLength = 0x1198;
        constexpr  ptrdiff_t m_bTriggerWarning = 0x11A0;
        constexpr  ptrdiff_t m_bExplodeWarning = 0x11A4;
        constexpr  ptrdiff_t m_flDefuseLength = 0x11AC;
        constexpr  ptrdiff_t m_flC4ExplodeSpectateDuration = 0x16C8;
        constexpr  ptrdiff_t m_flBlendWeight = 0x11A0;
        constexpr  ptrdiff_t m_flBlendWeightCurrent = 0x11AC;
        constexpr  ptrdiff_t m_flFrameMax = 0x1160;
        constexpr  ptrdiff_t x = 0x1164;
        constexpr  ptrdiff_t y = 0x1168;
        constexpr  ptrdiff_t fadeSpeed = 0x116C;
        constexpr  ptrdiff_t bounceFactor = 0x1170;
        constexpr  ptrdiff_t m_flSpriteScale = 0x11A4;
        constexpr  ptrdiff_t m_flFOV = 0x624;
        constexpr  ptrdiff_t m_flCameraSpeed = 0x628;
        constexpr  ptrdiff_t m_flEaseIn = 0x62C;
        constexpr  ptrdiff_t m_flEaseOut = 0x630;
        constexpr  ptrdiff_t m_flVerticalFOV = 0x660;
        constexpr  ptrdiff_t m_FOV = 0x600;
        constexpr  ptrdiff_t m_Resolution = 0x604;
        constexpr  ptrdiff_t m_flFogStart = 0x610;
        constexpr  ptrdiff_t m_flFogEnd = 0x614;
        constexpr  ptrdiff_t m_flFogMaxDensity = 0x618;
        constexpr  ptrdiff_t m_flAspectRatio = 0x620;
        constexpr  ptrdiff_t m_fBrightness = 0x628;
        constexpr  ptrdiff_t m_TargetFOV = 0x64C;
        constexpr  ptrdiff_t m_DegreesPerSecond = 0x650;
        constexpr  ptrdiff_t m_flBombRadius = 0x604;
        constexpr  ptrdiff_t m_flBotMaxVisionDistance = 0x610;
        constexpr  ptrdiff_t m_flEnvRainStrength = 0x61C;
        constexpr  ptrdiff_t m_flEnvPuddleRippleStrength = 0x620;
        constexpr  ptrdiff_t m_flEnvPuddleRippleDirection = 0x624;
        constexpr  ptrdiff_t m_flEnvWetnessCoverage = 0x628;
        constexpr  ptrdiff_t m_flEnvWetnessDryingAmount = 0x62C;
        constexpr  ptrdiff_t m_DmgRadius = 0x115C;
        constexpr  ptrdiff_t m_flWarnAITime = 0x1164;
        constexpr  ptrdiff_t m_flCreationTime = 0xFF4;
        constexpr  ptrdiff_t m_flHoldBreathTime = 0x238;
        constexpr  ptrdiff_t m_flDrowningDamageInterval = 0x23C;
        constexpr  ptrdiff_t m_flUseRange = 0x24C;
        constexpr  ptrdiff_t m_flUseAngleTolerance = 0x250;
        constexpr  ptrdiff_t m_flCrouchTime = 0x254;
        constexpr  ptrdiff_t m_flDMBonusTimeLength = 0x34;
        constexpr  ptrdiff_t m_flSpriteFramerate = 0xFB8;
        constexpr  ptrdiff_t m_flBrightnessDuration = 0xFD4;
        constexpr  ptrdiff_t m_flScaleDuration = 0xFDC;
        constexpr  ptrdiff_t m_flGlowProxySize = 0xFE4;
        constexpr  ptrdiff_t m_flMaxFrame = 0xFF0;
        constexpr  ptrdiff_t m_flStartScale = 0xFF4;
        constexpr  ptrdiff_t m_flDestScale = 0xFF8;
        constexpr  ptrdiff_t m_flCsmFovOverrideValue = 0x608;
        constexpr  ptrdiff_t m_flMuzzleSmokeTimeout = 0x4BC;
        constexpr  ptrdiff_t m_flMuzzleSmokeDecrementRate = 0x4C0;
        constexpr  ptrdiff_t m_flDropSpeed = 0x4E8;
        constexpr  ptrdiff_t m_flOwnerFOV = 0x644;
        constexpr  ptrdiff_t m_flCooldown = 0x664;
        constexpr  ptrdiff_t m_flValueFloatX = 0x5C;
        constexpr  ptrdiff_t m_flValueFloatX_Min = 0x60;
        constexpr  ptrdiff_t m_flValueFloatX_Max = 0x64;
        constexpr  ptrdiff_t m_flValueFloatY = 0x68;
        constexpr  ptrdiff_t m_flValueFloatY_Min = 0x6C;
        constexpr  ptrdiff_t m_flValueFloatY_Max = 0x70;
        constexpr  ptrdiff_t m_flValueFloatZ = 0x74;
        constexpr  ptrdiff_t m_flValueFloatZ_Min = 0x78;
        constexpr  ptrdiff_t m_flValueFloatZ_Max = 0x7C;
        constexpr  ptrdiff_t m_flValueFloatW = 0x80;
        constexpr  ptrdiff_t m_flValueFloatW_Min = 0x84;
        constexpr  ptrdiff_t m_flValueFloatW_Max = 0x88;
        constexpr  ptrdiff_t amplitude = 0x8;
        constexpr  ptrdiff_t frequency = 0xC;
        constexpr  ptrdiff_t angle = 0x20;
        constexpr  ptrdiff_t brightness = 0x18;
        constexpr  ptrdiff_t orbit_distance = 0x1C;
        constexpr  ptrdiff_t map_rotation = 0x8;
        constexpr  ptrdiff_t m_flEndTime = 0x4;
        constexpr  ptrdiff_t m_flStartValue = 0x8;
        constexpr  ptrdiff_t m_flEndValue = 0xC;
        constexpr  ptrdiff_t m_TimeBetweenEvents = 0x0;
        constexpr  ptrdiff_t m_fNextEvent = 0x4;
        constexpr  ptrdiff_t m_flMuzzleFlashBrightness = 0x24;
        constexpr  ptrdiff_t m_flFov = 0x4C;
        constexpr  ptrdiff_t m_flLinearAtten = 0x54;
        constexpr  ptrdiff_t m_flCurrentPullBackDist = 0x5C;
        constexpr  ptrdiff_t fov = 0xC;
        constexpr  ptrdiff_t znear = 0x10;
        constexpr  ptrdiff_t zfar = 0x14;
        constexpr  ptrdiff_t m_flIronSightAmount = 0x14;
        constexpr  ptrdiff_t m_flIronSightAmountGained = 0x18;
        constexpr  ptrdiff_t m_flIronSightAmountBiased = 0x1C;
        constexpr  ptrdiff_t m_flIronSightAmount_Interpolated = 0x20;
        constexpr  ptrdiff_t m_flIronSightAmountGained_Interpolated = 0x24;
        constexpr  ptrdiff_t m_flIronSightAmountBiased_Interpolated = 0x28;
        constexpr  ptrdiff_t m_flInterpolationLastUpdated = 0x2C;
        constexpr  ptrdiff_t m_flFiringInaccuracyExtraWidthMultiplier = 0xA4;
        constexpr  ptrdiff_t m_flSpeedRatio = 0xA8;
        constexpr  ptrdiff_t m_flRenderFxDuration = 0x20;
        constexpr  ptrdiff_t Speed = 0x0;
        constexpr  ptrdiff_t End = 0x4;
        constexpr  ptrdiff_t Reset = 0x8;
        constexpr  ptrdiff_t m_flSpecularPower = 0x5C;
        constexpr  ptrdiff_t m_flSpecularIndependence = 0x60;
        constexpr  ptrdiff_t m_flSunDistance = 0x7C;
        constexpr  ptrdiff_t m_flNearZ = 0x84;
        constexpr  ptrdiff_t m_flCloudScale = 0x90;
        constexpr  ptrdiff_t m_flCloud1Speed = 0x94;
        constexpr  ptrdiff_t m_flCloud1Direction = 0x98;
        constexpr  ptrdiff_t m_flCloud2Speed = 0x9C;
        constexpr  ptrdiff_t m_flCloud2Direction = 0xA0;
        constexpr  ptrdiff_t m_flAmbientScale1 = 0xB0;
        constexpr  ptrdiff_t m_flAmbientScale2 = 0xB4;
        constexpr  ptrdiff_t m_flGroundScale = 0xB8;
        constexpr  ptrdiff_t m_flFoWDarkness = 0xC0;
        constexpr  ptrdiff_t m_flViewFoV = 0xEC;
    }

    // ============================================
    // Context: float64
    // ============================================
    namespace float64
    {
        constexpr  ptrdiff_t m_flLastPerfSampleTime = 0x4F58;
    }

    // ============================================
    // Context: fogparams_t
    // ============================================
    namespace fogparams_t
    {
        constexpr  ptrdiff_t m_fog = 0x600;
        constexpr  ptrdiff_t m_CurrentFog = 0x148;
        constexpr  ptrdiff_t fog = 0x20;
    }

    // ============================================
    // Context: gear_slot_t
    // ============================================
    namespace gear_slot_t
    {
        constexpr  ptrdiff_t m_GearSlot = 0x700;
    }

    // ============================================
    // Context: inputsystem_dll
    // ============================================
    namespace inputsystem_dll
    {
        constexpr  ptrdiff_t dwInputSystem = 0x42B50;
    }

    // ============================================
    // Context: int16
    // ============================================
    namespace int16
    {
        constexpr  ptrdiff_t m_nParentAttachmentOrBone = 0x100;
        constexpr  ptrdiff_t m_RopeLength = 0x1278;
        constexpr  ptrdiff_t m_Slack = 0x127A;
        constexpr  ptrdiff_t scale = 0x8;
        constexpr  ptrdiff_t m_nHitBox = 0x60;
    }

    // ============================================
    // Context: int32
    // ============================================
    namespace int32
    {
        constexpr  ptrdiff_t m_nRefundableCurrency = 0x3C;
        constexpr  ptrdiff_t m_windRadius = 0x14;
        constexpr  ptrdiff_t m_iOpvarIndex = 0x618;
        constexpr  ptrdiff_t m_nCubemapSourceType = 0x62C;
        constexpr  ptrdiff_t m_nHeightFogType = 0x640;
        constexpr  ptrdiff_t m_nFogHeightBlendMode = 0x644;
        constexpr  ptrdiff_t m_nFogHeightCoordinateSpace = 0x648;
        constexpr  ptrdiff_t m_nDistanceFogType = 0x64C;
        constexpr  ptrdiff_t m_nPersonaDataPublicLevel = 0x74;
        constexpr  ptrdiff_t m_nPersonaDataPublicCommendsLeader = 0x78;
        constexpr  ptrdiff_t m_nPersonaDataPublicCommendsTeacher = 0x7C;
        constexpr  ptrdiff_t m_nPersonaDataPublicCommendsFriendly = 0x80;
        constexpr  ptrdiff_t m_nPersonaDataXpTrailLevel = 0x84;
        constexpr  ptrdiff_t m_iModelDisplayFlags = 0x0;
        constexpr  ptrdiff_t m_iBoneIndex = 0x1188;
        constexpr  ptrdiff_t m_nDraftType = 0x610;
        constexpr  ptrdiff_t m_nTeamWinningCoinToss = 0x614;
        constexpr  ptrdiff_t m_nTeamWithFirstChoice = 0x618;
        constexpr  ptrdiff_t m_nVoteMapIdsList = 0x718;
        constexpr  ptrdiff_t m_nAccountIDs = 0x734;
        constexpr  ptrdiff_t m_nMapId0 = 0x834;
        constexpr  ptrdiff_t m_nMapId1 = 0x934;
        constexpr  ptrdiff_t m_nMapId2 = 0xA34;
        constexpr  ptrdiff_t m_nMapId3 = 0xB34;
        constexpr  ptrdiff_t m_nMapId4 = 0xC34;
        constexpr  ptrdiff_t m_nMapId5 = 0xD34;
        constexpr  ptrdiff_t m_nStartingSide0 = 0xE34;
        constexpr  ptrdiff_t m_nCurrentPhase = 0xF34;
        constexpr  ptrdiff_t m_nPhaseStartTick = 0xF38;
        constexpr  ptrdiff_t m_nPhaseDurationTicks = 0xF3C;
        constexpr  ptrdiff_t m_nPostDataUpdateTick = 0xF40;
        constexpr  ptrdiff_t m_nFalloffShape = 0x624;
        constexpr  ptrdiff_t m_nColorMode = 0xFAC;
        constexpr  ptrdiff_t m_nDirectLight = 0xFC0;
        constexpr  ptrdiff_t m_nBakedShadowIndex = 0xFC4;
        constexpr  ptrdiff_t m_nLightPathUniqueId = 0xFC8;
        constexpr  ptrdiff_t m_nLightMapUniqueId = 0xFCC;
        constexpr  ptrdiff_t m_nLuminaireShape = 0xFD0;
        constexpr  ptrdiff_t m_nBakeSpecularToCubemaps = 0x10D0;
        constexpr  ptrdiff_t m_nCastShadows = 0x10E4;
        constexpr  ptrdiff_t m_nShadowMapSize = 0x10E8;
        constexpr  ptrdiff_t m_nShadowPriority = 0x10EC;
        constexpr  ptrdiff_t m_nBounceLight = 0x10F4;
        constexpr  ptrdiff_t m_nFog = 0x1110;
        constexpr  ptrdiff_t m_nFogShadows = 0x1118;
        constexpr  ptrdiff_t m_nPrecomputedSubFrusta = 0x1170;
        constexpr  ptrdiff_t m_iActiveIssueIndex = 0x610;
        constexpr  ptrdiff_t m_iOnlyTeamToVote = 0x614;
        constexpr  ptrdiff_t m_nVoteOptionCount = 0x618;
        constexpr  ptrdiff_t m_nPotentialVotes = 0x62C;
        constexpr  ptrdiff_t m_nSpotRules = 0x1CE0;
        constexpr  ptrdiff_t m_iProgressBarDuration = 0x13E0;
        constexpr  ptrdiff_t m_nClientHealthFadeParityValue = 0x1408;
        constexpr  ptrdiff_t m_iMinHealthDmg = 0x123C;
        constexpr  ptrdiff_t m_nRTEnvCP = 0x114;
        constexpr  ptrdiff_t m_nRTEnvCPComponent = 0x118;
        constexpr  ptrdiff_t m_nUseSnapshotFromSurfaceGraph = 0x128;
        constexpr  ptrdiff_t m_nMatchSeed = 0x138;
        constexpr  ptrdiff_t m_iFirstSecondHalfRound = 0x140;
        constexpr  ptrdiff_t m_iBombSite = 0x144;
        constexpr  ptrdiff_t m_nAvailableSheetSequencesMaxIndex = 0x10A8;
        constexpr  ptrdiff_t m_nInstruction = 0x14;
        constexpr  ptrdiff_t m_localLifeState = 0x117C;
        constexpr  ptrdiff_t m_errorHistoryIndex = 0x123C;
        constexpr  ptrdiff_t m_errorHistoryCount = 0x1240;
        constexpr  ptrdiff_t m_nVolumeDepth = 0x620;
        constexpr  ptrdiff_t m_nIndirectTextureDimX = 0x628;
        constexpr  ptrdiff_t m_nIndirectTextureDimY = 0x62C;
        constexpr  ptrdiff_t m_nIndirectTextureDimZ = 0x630;
        constexpr  ptrdiff_t m_nForceRefreshCount = 0x680;
        constexpr  ptrdiff_t m_nShape = 0x620;
        constexpr  ptrdiff_t m_iScore = 0x630;
        constexpr  ptrdiff_t m_nVariant = 0x688;
        constexpr  ptrdiff_t m_nImpulse = 0x48;
        constexpr  ptrdiff_t m_nSecondarySkeletonMasterCount = 0x50;
        constexpr  ptrdiff_t m_nSerializePoseRecipeVersionAG2 = 0x3FC;
        constexpr  ptrdiff_t m_nServerGraphInstanceIteration = 0x400;
        constexpr  ptrdiff_t m_nServerSerializationContextIteration = 0x404;
        constexpr  ptrdiff_t m_soundscapeIndex = 0x62C;
        constexpr  ptrdiff_t m_soundscapeEntityListId = 0x630;
        constexpr  ptrdiff_t m_iChangedVariables = 0x66C;
        constexpr  ptrdiff_t m_nInventoryImageRgbaWidth = 0x80;
        constexpr  ptrdiff_t m_nInventoryImageRgbaHeight = 0x84;
        constexpr  ptrdiff_t m_iEntityQuality = 0x1BC;
        constexpr  ptrdiff_t m_iEntityQuantity = 0x1EC;
        constexpr  ptrdiff_t m_iRarityOverride = 0x1F0;
        constexpr  ptrdiff_t m_iQualityOverride = 0x1F4;
        constexpr  ptrdiff_t m_iOriginOverride = 0x1F8;
        constexpr  ptrdiff_t m_nMode = 0x604;
        constexpr  ptrdiff_t soundscapeIndex = 0x68;
        constexpr  ptrdiff_t soundscapeEntityListIndex = 0x70;
        constexpr  ptrdiff_t m_nEffectState = 0x640;
        constexpr  ptrdiff_t m_nDecoyShotTick = 0x1238;
        constexpr  ptrdiff_t m_nClientLastKnownDecoyShotTick = 0x123C;
        constexpr  ptrdiff_t m_iExternalItemProviderRegisteredToken = 0x4C0;
        constexpr  ptrdiff_t m_iAmmoLastCheck = 0x1794;
        constexpr  ptrdiff_t m_nLastEmptySoundCmdNum = 0x1798;
        constexpr  ptrdiff_t m_iRecoilIndex = 0x17DC;
        constexpr  ptrdiff_t m_iOriginalTeamNumber = 0x1810;
        constexpr  ptrdiff_t m_iMostRecentTeamNumber = 0x1814;
        constexpr  ptrdiff_t m_nCustomEconReloadEventId = 0x18BC;
        constexpr  ptrdiff_t m_iIronSightMode = 0x1A10;
        constexpr  ptrdiff_t m_nValueCounts = 0x110;
        constexpr  ptrdiff_t m_nBucketCount = 0x210;
        constexpr  ptrdiff_t m_iHealthMin = 0x63C;
        constexpr  ptrdiff_t m_iHealthMax = 0x640;
        constexpr  ptrdiff_t m_iNodeNumber = 0x1198;
        constexpr  ptrdiff_t m_iNodeNumberMax = 0x119C;
        constexpr  ptrdiff_t m_nModelID = 0x8;
        constexpr  ptrdiff_t m_nPrevArmorVal = 0x14C8;
        constexpr  ptrdiff_t m_nPrevGrenadeAmmoCount = 0x14CC;
        constexpr  ptrdiff_t m_iRetakesOffering = 0x1640;
        constexpr  ptrdiff_t m_iRetakesOfferingCard = 0x1644;
        constexpr  ptrdiff_t m_iRetakesMVPBoostItem = 0x164C;
        constexpr  ptrdiff_t m_nRagdollDamageBone = 0x1ACC;
        constexpr  ptrdiff_t m_nWhichBombZone = 0x1C60;
        constexpr  ptrdiff_t m_iShotsFired = 0x1C64;
        constexpr  ptrdiff_t m_ArmorValue = 0x1C7C;
        constexpr  ptrdiff_t m_nCursorsAllowedToWait = 0x48;
        constexpr  ptrdiff_t m_nHostageState = 0x1228;
        constexpr  ptrdiff_t m_nCashStackValue = 0xFA8;
        constexpr  ptrdiff_t m_iClip1 = 0x16D8;
        constexpr  ptrdiff_t m_iClip2 = 0x16DC;
        constexpr  ptrdiff_t m_pReserveAmmo = 0x16E0;
        constexpr  ptrdiff_t m_nFogType = 0xFC8;
        constexpr  ptrdiff_t m_nSrcInstruction = 0x48;
        constexpr  ptrdiff_t m_nVolumeResolutionXY = 0x70C;
        constexpr  ptrdiff_t m_nVolumeResolutionZ = 0x710;
        constexpr  ptrdiff_t m_nClipmapLevels = 0x714;
        constexpr  ptrdiff_t m_nTotalPausedTicks = 0x30;
        constexpr  ptrdiff_t m_nPauseStartTick = 0x34;
        constexpr  ptrdiff_t m_nTextWidthPx = 0xFC8;
        constexpr  ptrdiff_t m_nTextHeightPx = 0xFCC;
        constexpr  ptrdiff_t m_nLinksTouchingSomething = 0xFB4;
        constexpr  ptrdiff_t m_fPrevLockedPoints = 0xFBC;
        constexpr  ptrdiff_t m_iForcePointMoveCounter = 0xFC0;
        constexpr  ptrdiff_t m_TextureHeight = 0x12A0;
        constexpr  ptrdiff_t m_nImportance = 0x608;
        constexpr  ptrdiff_t m_nLightChoice = 0x60C;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed0_PartIndex = 0xB2C;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed1_PartIndex = 0xB30;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed2_PartIndex = 0xB34;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed3_PartIndex = 0xB38;
        constexpr  ptrdiff_t m_nDestructiblePartInitialStateDestructed4_PartIndex = 0xB3C;
        constexpr  ptrdiff_t m_iOldHealth = 0xC74;
        constexpr  ptrdiff_t m_totalHitsOnServer = 0x48;
        constexpr  ptrdiff_t m_Entity_nHandshake = 0x16F4;
        constexpr  ptrdiff_t m_Entity_nEnvCubeMapArrayIndex = 0x16F8;
        constexpr  ptrdiff_t m_Entity_nPriority = 0x16FC;
        constexpr  ptrdiff_t m_Entity_nLightProbeSizeX = 0x1714;
        constexpr  ptrdiff_t m_Entity_nLightProbeSizeY = 0x1718;
        constexpr  ptrdiff_t m_Entity_nLightProbeSizeZ = 0x171C;
        constexpr  ptrdiff_t m_Entity_nLightProbeAtlasX = 0x1720;
        constexpr  ptrdiff_t m_Entity_nLightProbeAtlasY = 0x1724;
        constexpr  ptrdiff_t m_Entity_nLightProbeAtlasZ = 0x1728;
        constexpr  ptrdiff_t m_iMaxHealth = 0x348;
        constexpr  ptrdiff_t m_iHealth = 0x34C;
        constexpr  ptrdiff_t m_nNoInterpolationTick = 0x368;
        constexpr  ptrdiff_t m_nVisibilityNoInterpolationTick = 0x36C;
        constexpr  ptrdiff_t m_iEFlags = 0x374;
        constexpr  ptrdiff_t m_nSimulationTick = 0x390;
        constexpr  ptrdiff_t m_iCurrentThinkContext = 0x394;
        constexpr  ptrdiff_t m_nInterpolationLatchDirtyFlags = 0x3C0;
        constexpr  ptrdiff_t m_nGroundBodyIndex = 0x534;
        constexpr  ptrdiff_t m_nFirstPredictableCommand = 0x56C;
        constexpr  ptrdiff_t m_nLastPredictableCommand = 0x570;
        constexpr  ptrdiff_t m_DataChangeEventRef = 0x5B4;
        constexpr  ptrdiff_t m_nCreationTick = 0x5D0;
        constexpr  ptrdiff_t m_nLastExecutedCommandNumber = 0x13A0;
        constexpr  ptrdiff_t m_nLastExecutedCommandTick = 0x13A4;
        constexpr  ptrdiff_t m_nEntityIndexSelection = 0x6B8;
        constexpr  ptrdiff_t m_nNextShuffle = 0x20;
        constexpr  ptrdiff_t m_iShapeType = 0x115C;
        constexpr  ptrdiff_t m_nResolutionX = 0x604;
        constexpr  ptrdiff_t m_nResolutionY = 0x608;
        constexpr  ptrdiff_t m_nTargetChangeCount = 0x640;
        constexpr  ptrdiff_t m_GearSlotPosition = 0x704;
        constexpr  ptrdiff_t m_nPrice = 0x70C;
        constexpr  ptrdiff_t m_nKillAward = 0x710;
        constexpr  ptrdiff_t m_nPrimaryReserveAmmoMax = 0x714;
        constexpr  ptrdiff_t m_nSecondaryReserveAmmoMax = 0x718;
        constexpr  ptrdiff_t m_nCrosshairMinDistance = 0x72C;
        constexpr  ptrdiff_t m_nCrosshairDeltaDistance = 0x730;
        constexpr  ptrdiff_t m_nNumBullets = 0x738;
        constexpr  ptrdiff_t m_nBurstShotCount = 0x7D4;
        constexpr  ptrdiff_t m_nRecoilSeed = 0x7DC;
        constexpr  ptrdiff_t m_nSpreadSeed = 0x7E0;
        constexpr  ptrdiff_t m_nZoomLevels = 0x7FC;
        constexpr  ptrdiff_t m_nZoomFOV1 = 0x800;
        constexpr  ptrdiff_t m_nZoomFOV2 = 0x804;
        constexpr  ptrdiff_t m_nDamage = 0x828;
        constexpr  ptrdiff_t m_nRecoveryTransitionStartBullet = 0x858;
        constexpr  ptrdiff_t m_nRecoveryTransitionEndBullet = 0x85C;
        constexpr  ptrdiff_t m_iReapplyProvisionParity = 0x20;
        constexpr  ptrdiff_t m_iCompTeammateColor = 0x848;
        constexpr  ptrdiff_t m_iCoachingTeam = 0x868;
        constexpr  ptrdiff_t m_iCompetitiveRanking = 0x880;
        constexpr  ptrdiff_t m_iCompetitiveWins = 0x884;
        constexpr  ptrdiff_t m_iCompetitiveRankingPredicted_Win = 0x88C;
        constexpr  ptrdiff_t m_iCompetitiveRankingPredicted_Loss = 0x890;
        constexpr  ptrdiff_t m_iCompetitiveRankingPredicted_Tie = 0x894;
        constexpr  ptrdiff_t m_nEndMatchNextMapVote = 0x898;
        constexpr  ptrdiff_t m_iDraftIndex = 0x8D8;
        constexpr  ptrdiff_t m_nDisconnectionTick = 0x8F0;
        constexpr  ptrdiff_t m_nBotsControlledThisRound = 0x904;
        constexpr  ptrdiff_t m_iPawnArmor = 0x91C;
        constexpr  ptrdiff_t m_iPawnLifetimeStart = 0x924;
        constexpr  ptrdiff_t m_iPawnLifetimeEnd = 0x928;
        constexpr  ptrdiff_t m_iPawnBotDifficulty = 0x92C;
        constexpr  ptrdiff_t m_eMvpReason = 0x944;
        constexpr  ptrdiff_t m_iMusicKitID = 0x948;
        constexpr  ptrdiff_t m_iMusicKitMVPs = 0x94C;
        constexpr  ptrdiff_t m_iMVPs = 0x950;
        constexpr  ptrdiff_t m_nNextIndex = 0x0;
        constexpr  ptrdiff_t m_nLadderSurfacePropIndex = 0x404;
        constexpr  ptrdiff_t m_nTraceCount = 0x648;
        constexpr  ptrdiff_t m_StuckLast = 0x64C;
        constexpr  ptrdiff_t m_nOldWaterLevel = 0x654;
        constexpr  ptrdiff_t m_nGameCodeHasMovedPlayerAfterCommand = 0x680;
        constexpr  ptrdiff_t m_nCost = 0x34;
        constexpr  ptrdiff_t m_nPrevArmor = 0x38;
        constexpr  ptrdiff_t m_nInteractions = 0x30;
        constexpr  ptrdiff_t m_nDisableTakePhysicsDamageSpawnFlag = 0x38;
        constexpr  ptrdiff_t m_nMotionDisabledSpawnFlag = 0x3C;
        constexpr  ptrdiff_t m_nCurrentCount = 0x0;
        constexpr  ptrdiff_t m_Exponent = 0xFB0;
        constexpr  ptrdiff_t m_nSendUpdate = 0x40;
        constexpr  ptrdiff_t m_fireCount = 0x1958;
        constexpr  ptrdiff_t m_nInfernoType = 0x195C;
        constexpr  ptrdiff_t m_lastFireCount = 0x1968;
        constexpr  ptrdiff_t m_nFireEffectTickBegin = 0x196C;
        constexpr  ptrdiff_t m_drawableCount = 0x8570;
        constexpr  ptrdiff_t m_nlosperiod = 0x8578;
        constexpr  ptrdiff_t m_iNumRoundKills = 0x128;
        constexpr  ptrdiff_t m_iNumRoundKillsHeadshots = 0x12C;
        constexpr  ptrdiff_t m_nStepside = 0x280;
        constexpr  ptrdiff_t m_iEnemy5Ks = 0x68;
        constexpr  ptrdiff_t m_iEnemy4Ks = 0x6C;
        constexpr  ptrdiff_t m_iEnemy3Ks = 0x70;
        constexpr  ptrdiff_t m_iEnemyKnifeKills = 0x74;
        constexpr  ptrdiff_t m_iEnemyTaserKills = 0x78;
        constexpr  ptrdiff_t m_zoomLevel = 0x1CB0;
        constexpr  ptrdiff_t m_iBurstShotsRemaining = 0x1CB4;
        constexpr  ptrdiff_t m_iSilencerBodygroup = 0x1CB8;
        constexpr  ptrdiff_t m_silencedModelIndex = 0x1CC8;
        constexpr  ptrdiff_t m_nRevolverCylinderIdx = 0x1CD0;
        constexpr  ptrdiff_t m_nResolutionEnum = 0xFB0;
        constexpr  ptrdiff_t m_iCurrentFriction = 0x1164;
        constexpr  ptrdiff_t m_iMinFriction = 0x1168;
        constexpr  ptrdiff_t m_iMaxFriction = 0x116C;
        constexpr  ptrdiff_t m_iFrictionAnimState = 0x1170;
        constexpr  ptrdiff_t m_nRandom = 0x604;
        constexpr  ptrdiff_t m_nOrdinal = 0x608;
        constexpr  ptrdiff_t m_nSmokeEffectTickBegin = 0x1250;
        constexpr  ptrdiff_t m_nRandomSeed = 0x1258;
        constexpr  ptrdiff_t m_nVoxelFrameDataSize = 0x1290;
        constexpr  ptrdiff_t m_nVoxelUpdate = 0x1294;
        constexpr  ptrdiff_t m_iInitialGlowState = 0x1364;
        constexpr  ptrdiff_t m_nGlowRange = 0x1368;
        constexpr  ptrdiff_t m_nGlowRangeMin = 0x136C;
        constexpr  ptrdiff_t m_nGlowTeam = 0x1374;
        constexpr  ptrdiff_t m_iCachedFrameCount = 0x1378;
        constexpr  ptrdiff_t m_numMapVictories = 0x8B8;
        constexpr  ptrdiff_t m_scoreFirstHalf = 0x8C0;
        constexpr  ptrdiff_t m_scoreSecondHalf = 0x8C4;
        constexpr  ptrdiff_t m_scoreOvertime = 0x8C8;
        constexpr  ptrdiff_t m_iDamageType = 0x638;
        constexpr  ptrdiff_t m_nStopType = 0x11B0;
        constexpr  ptrdiff_t m_nDataCP = 0x1508;
        constexpr  ptrdiff_t m_nTintCP = 0x1518;
        constexpr  ptrdiff_t m_nCascades = 0xB0;
        constexpr  ptrdiff_t m_nShadowWidth = 0xB8;
        constexpr  ptrdiff_t m_nShadowHeight = 0xBC;
        constexpr  ptrdiff_t m_nRenderSpecular = 0xC4;
        constexpr  ptrdiff_t m_nStyle = 0xD4;
        constexpr  ptrdiff_t m_nCascadeRenderStaticObjects = 0xE0;
        constexpr  ptrdiff_t m_nShadowCascadeResolution0 = 0xFC;
        constexpr  ptrdiff_t m_nShadowCascadeResolution1 = 0x100;
        constexpr  ptrdiff_t m_nShadowCascadeResolution2 = 0x104;
        constexpr  ptrdiff_t m_nShadowCascadeResolution3 = 0x108;
        constexpr  ptrdiff_t m_nFogLightingMode = 0x184;
        constexpr  ptrdiff_t m_iGlowType = 0x30;
        constexpr  ptrdiff_t m_iGlowTeam = 0x34;
        constexpr  ptrdiff_t m_nAABBDirection = 0x660;
        constexpr  ptrdiff_t m_iNumHits = 0x6C;
        constexpr  ptrdiff_t m_iLastBulletUpdate = 0x70;
        constexpr  ptrdiff_t m_nFallbackPaintKit = 0x1658;
        constexpr  ptrdiff_t m_nFallbackSeed = 0x165C;
        constexpr  ptrdiff_t m_nFallbackStatTrak = 0x1664;
        constexpr  ptrdiff_t m_iOldTeam = 0x168C;
        constexpr  ptrdiff_t m_nUnloadedModelIndex = 0x1694;
        constexpr  ptrdiff_t m_iNumOwnerValidationRetries = 0x1698;
        constexpr  ptrdiff_t m_iKills = 0x30;
        constexpr  ptrdiff_t m_iDeaths = 0x34;
        constexpr  ptrdiff_t m_iAssists = 0x38;
        constexpr  ptrdiff_t m_iDamage = 0x3C;
        constexpr  ptrdiff_t m_iEquipmentValue = 0x40;
        constexpr  ptrdiff_t m_iMoneySaved = 0x44;
        constexpr  ptrdiff_t m_iKillReward = 0x48;
        constexpr  ptrdiff_t m_iLiveTime = 0x4C;
        constexpr  ptrdiff_t m_iHeadShotKills = 0x50;
        constexpr  ptrdiff_t m_iObjective = 0x54;
        constexpr  ptrdiff_t m_iCashEarned = 0x58;
        constexpr  ptrdiff_t m_iUtilityDamage = 0x5C;
        constexpr  ptrdiff_t m_iEnemiesFlashed = 0x60;
        constexpr  ptrdiff_t m_nTerroristTimeOuts = 0x58;
        constexpr  ptrdiff_t m_nCTTimeOuts = 0x5C;
        constexpr  ptrdiff_t m_iFreezeTime = 0x64;
        constexpr  ptrdiff_t m_iRoundTime = 0x68;
        constexpr  ptrdiff_t m_gamePhase = 0x84;
        constexpr  ptrdiff_t m_totalRoundsPlayed = 0x88;
        constexpr  ptrdiff_t m_nRoundsPlayedThisPhase = 0x8C;
        constexpr  ptrdiff_t m_nOvertimePlaying = 0x90;
        constexpr  ptrdiff_t m_iHostagesRemaining = 0x94;
        constexpr  ptrdiff_t m_nQueuedMatchmakingMode = 0xA0;
        constexpr  ptrdiff_t m_iSpectatorSlotCount = 0xA8;
        constexpr  ptrdiff_t m_MatchDevice = 0xAC;
        constexpr  ptrdiff_t m_nNextMapInMapgroup = 0xB4;
        constexpr  ptrdiff_t m_nTournamentPredictionsPct = 0x8B8;
        constexpr  ptrdiff_t m_numBestOfMaps = 0x9A0;
        constexpr  ptrdiff_t m_nHalloweenMaskListSeed = 0x9A4;
        constexpr  ptrdiff_t m_iRoundWinStatus = 0x9AC;
        constexpr  ptrdiff_t m_eRoundWinReason = 0x9B0;
        constexpr  ptrdiff_t m_iMatchStats_RoundResults = 0x9B8;
        constexpr  ptrdiff_t m_iMatchStats_PlayersAlive_CT = 0xA30;
        constexpr  ptrdiff_t m_iMatchStats_PlayersAlive_T = 0xAA8;
        constexpr  ptrdiff_t m_nEndMatchMapGroupVoteTypes = 0xC60;
        constexpr  ptrdiff_t m_nEndMatchMapGroupVoteOptions = 0xC88;
        constexpr  ptrdiff_t m_nEndMatchMapVoteWinner = 0xCB0;
        constexpr  ptrdiff_t m_iNumConsecutiveCTLoses = 0xCB4;
        constexpr  ptrdiff_t m_iNumConsecutiveTerroristLoses = 0xCB8;
        constexpr  ptrdiff_t m_nMatchAbortedEarlyReason = 0xD78;
        constexpr  ptrdiff_t m_nTTeamIntroVariant = 0xEFC;
        constexpr  ptrdiff_t m_nCTTeamIntroVariant = 0xF00;
        constexpr  ptrdiff_t m_iRoundEndWinnerTeam = 0xF08;
        constexpr  ptrdiff_t m_eRoundEndReason = 0xF0C;
        constexpr  ptrdiff_t m_iRoundEndTimerTime = 0xF14;
        constexpr  ptrdiff_t m_iRoundEndFunFactData1 = 0xF24;
        constexpr  ptrdiff_t m_iRoundEndFunFactData2 = 0xF28;
        constexpr  ptrdiff_t m_iRoundEndFunFactData3 = 0xF2C;
        constexpr  ptrdiff_t m_iRoundEndPlayerCount = 0xF38;
        constexpr  ptrdiff_t m_iRoundEndLegacy = 0xF40;
        constexpr  ptrdiff_t m_iRoundStartRoundNumber = 0xF48;
        constexpr  ptrdiff_t m_nBounces = 0x11B8;
        constexpr  ptrdiff_t m_nExplodeEffectTickBegin = 0x11C8;
        constexpr  ptrdiff_t m_iAccount = 0x40;
        constexpr  ptrdiff_t m_iStartAccount = 0x44;
        constexpr  ptrdiff_t m_iTotalCashSpent = 0x48;
        constexpr  ptrdiff_t m_iCashSpentThisRound = 0x4C;
        constexpr  ptrdiff_t m_nLongAxis = 0xFA8;
        constexpr  ptrdiff_t m_nForceSkin = 0x16C8;
        constexpr  ptrdiff_t m_queryHandleHalo = 0xFBC;
        constexpr  ptrdiff_t m_nTransitionDurationTicks = 0xFC4;
        constexpr  ptrdiff_t m_nBombSite = 0x1164;
        constexpr  ptrdiff_t m_nSourceSoundscapeHash = 0x1168;
        constexpr  ptrdiff_t m_nForceBone = 0x1080;
        constexpr  ptrdiff_t flags = 0x1158;
        constexpr  ptrdiff_t hitSound = 0x1174;
        constexpr  ptrdiff_t priority = 0x1178;
        constexpr  ptrdiff_t tempent_renderamt = 0x1194;
        constexpr  ptrdiff_t m_nFlickerFrame = 0x11A8;
        constexpr  ptrdiff_t m_iLastCollisionFrame = 0x11CC;
        constexpr  ptrdiff_t m_nLastAttackTick = 0x1CE4;
        constexpr  ptrdiff_t m_nLimitCount = 0x48;
        constexpr  ptrdiff_t m_iType = 0x638;
        constexpr  ptrdiff_t m_nPathIndex = 0x608;
        constexpr  ptrdiff_t m_hostageRescueX = 0x660;
        constexpr  ptrdiff_t m_hostageRescueY = 0x670;
        constexpr  ptrdiff_t m_hostageRescueZ = 0x680;
        constexpr  ptrdiff_t m_iBuyingStatus = 0x600;
        constexpr  ptrdiff_t m_iPetPopulation = 0x608;
        constexpr  ptrdiff_t m_iHostageCount = 0x614;
        constexpr  ptrdiff_t m_nUniqueID = 0xFA8;
        constexpr  ptrdiff_t m_nPlayer = 0xFE8;
        constexpr  ptrdiff_t m_nEntity = 0xFEC;
        constexpr  ptrdiff_t m_nHitbox = 0xFF0;
        constexpr  ptrdiff_t m_nTintID = 0xFF8;
        constexpr  ptrdiff_t m_nameStringTableIndex = 0x14;
        constexpr  ptrdiff_t m_nDrowningDamageInitial = 0x240;
        constexpr  ptrdiff_t m_nDrowningDamageMax = 0x244;
        constexpr  ptrdiff_t m_nWaterSpeed = 0x248;
        constexpr  ptrdiff_t m_nCursorsAllowedToRunParallel = 0x98;
        constexpr  ptrdiff_t m_nStartBrightness = 0x1000;
        constexpr  ptrdiff_t m_nDestBrightness = 0x1004;
        constexpr  ptrdiff_t m_nSpriteWidth = 0x1018;
        constexpr  ptrdiff_t m_nSpriteHeight = 0x101C;
        constexpr  ptrdiff_t m_iFilterTeam = 0x638;
        constexpr  ptrdiff_t m_iWeight = 0x4C8;
        constexpr  ptrdiff_t m_iMaxClip1 = 0x4D0;
        constexpr  ptrdiff_t m_iMaxClip2 = 0x4D4;
        constexpr  ptrdiff_t m_iDefaultClip1 = 0x4D8;
        constexpr  ptrdiff_t m_iDefaultClip2 = 0x4DC;
        constexpr  ptrdiff_t m_iSlot = 0x4EC;
        constexpr  ptrdiff_t m_iPosition = 0x4F0;
        constexpr  ptrdiff_t m_nRepeatCount = 0x668;
        constexpr  ptrdiff_t m_nExplicitImageLayout = 0x11FC;
        constexpr  ptrdiff_t m_nValueIntX = 0x48;
        constexpr  ptrdiff_t m_nValueIntY = 0x4C;
        constexpr  ptrdiff_t m_nValueIntZ = 0x50;
        constexpr  ptrdiff_t m_nValueIntW = 0x54;
        constexpr  ptrdiff_t m_nPanoramaRenderRes = 0x280;
        constexpr  ptrdiff_t m_nInterpType = 0x10;
        constexpr  ptrdiff_t command_number = 0xA0;
        constexpr  ptrdiff_t m_nSequenceIndex = 0xE0;
        constexpr  ptrdiff_t m_nResolution = 0x300;
        constexpr  ptrdiff_t m_nVersion = 0x8;
        constexpr  ptrdiff_t Flags = 0x10;
    }

    // ============================================
    // Context: int8
    // ============================================
    namespace int8
    {
        constexpr  ptrdiff_t m_iCurrentMaxRagdollCount = 0x600;
        constexpr  ptrdiff_t m_iCompetitiveRankType = 0x888;
        constexpr  ptrdiff_t m_nIdealMotionType = 0x262;
        constexpr  ptrdiff_t m_nForceLOD = 0x263;
        constexpr  ptrdiff_t m_nClothUpdateFlags = 0x264;
    }

    // ============================================
    // Context: inv_image_camera_t
    // ============================================
    namespace inv_image_camera_t
    {
        constexpr  ptrdiff_t camera = 0x30;
    }

    // ============================================
    // Context: inv_image_clearcolor_t
    // ============================================
    namespace inv_image_clearcolor_t
    {
        constexpr  ptrdiff_t clearcolor = 0xDC;
    }

    // ============================================
    // Context: inv_image_data_t
    // ============================================
    namespace inv_image_data_t
    {
        constexpr  ptrdiff_t inventory_image_data = 0x10;
    }

    // ============================================
    // Context: inv_image_item_t
    // ============================================
    namespace inv_image_item_t
    {
        constexpr  ptrdiff_t item = 0x10;
    }

    // ============================================
    // Context: inv_image_light_barn_t
    // ============================================
    namespace inv_image_light_barn_t
    {
        constexpr  ptrdiff_t light0 = 0x9C;
        constexpr  ptrdiff_t light1 = 0xBC;
    }

    // ============================================
    // Context: inv_image_light_fill_t
    // ============================================
    namespace inv_image_light_fill_t
    {
        constexpr  ptrdiff_t lightfill = 0x80;
    }

    // ============================================
    // Context: inv_image_light_sun_t
    // ============================================
    namespace inv_image_light_sun_t
    {
        constexpr  ptrdiff_t lightsun = 0x64;
    }

    // ============================================
    // Context: inv_image_map_t
    // ============================================
    namespace inv_image_map_t
    {
        constexpr  ptrdiff_t map = 0x0;
    }

    // ============================================
    // Context: loadout_slot_t
    // ============================================
    namespace loadout_slot_t
    {
        constexpr  ptrdiff_t m_RetakesMVPBoostExtraUtility = 0x1650;
        constexpr  ptrdiff_t m_DefaultLoadoutSlot = 0x708;
    }

    // ============================================
    // Context: matchmaking_dll
    // ============================================
    namespace matchmaking_dll
    {
        constexpr  ptrdiff_t dwGameTypes = 0x1B0F80;
    }

    // ============================================
    // Context: matrix3x4_t
    // ============================================
    namespace matrix3x4_t
    {
        constexpr  ptrdiff_t m_matLocal = 0x1158;
    }

    // ============================================
    // Context: shard_model_desc_t
    // ============================================
    namespace shard_model_desc_t
    {
        constexpr  ptrdiff_t m_ShardDesc = 0x12E8;
    }

    // ============================================
    // Context: sky3dparams_t
    // ============================================
    namespace sky3dparams_t
    {
        constexpr  ptrdiff_t m_skyboxData = 0x600;
        constexpr  ptrdiff_t m_skybox3d = 0x12B8;
    }

    // ============================================
    // Context: soundsystem_dll
    // ============================================
    namespace soundsystem_dll
    {
        constexpr  ptrdiff_t dwSoundSystem = 0x512360;
        constexpr  ptrdiff_t dwSoundSystem_engineViewData = 0x7C;
    }

    // ============================================
    // Context: uint16
    // ============================================
    namespace uint16
    {
        constexpr  ptrdiff_t m_iAttributeDefinitionIndex = 0x30;
        constexpr  ptrdiff_t m_iMinWind = 0x10;
        constexpr  ptrdiff_t m_iMaxWind = 0x12;
        constexpr  ptrdiff_t m_iMinGust = 0x18;
        constexpr  ptrdiff_t m_iMaxGust = 0x1A;
        constexpr  ptrdiff_t m_iGustDirChange = 0x28;
        constexpr  ptrdiff_t m_iInitialWindDir = 0x2A;
        constexpr  ptrdiff_t m_unMusicID = 0x58;
        constexpr  ptrdiff_t unClass = 0x30;
        constexpr  ptrdiff_t unSlot = 0x32;
        constexpr  ptrdiff_t unItemDefIdx = 0x34;
        constexpr  ptrdiff_t m_iItemDefinitionIndex = 0x1BA;
        constexpr  ptrdiff_t m_nItemDefIndex = 0x30;
        constexpr  ptrdiff_t m_nCount = 0x32;
        constexpr  ptrdiff_t m_unCurrentEquipmentValue = 0x1C80;
        constexpr  ptrdiff_t m_unRoundStartEquipmentValue = 0x1C82;
        constexpr  ptrdiff_t m_unFreezetimeEndEquipmentValue = 0x1C84;
        constexpr  ptrdiff_t m_RopeFlags = 0xFE8;
        constexpr  ptrdiff_t m_ListEntry = 0x3C8;
        constexpr  ptrdiff_t m_EntClientFlags = 0x3E8;
        constexpr  ptrdiff_t m_hThink = 0x550;
        constexpr  ptrdiff_t m_unActiveQuestId = 0x89C;
        constexpr  ptrdiff_t m_nPawnCharacterDefIndex = 0x922;
        constexpr  ptrdiff_t m_unDefIdx = 0x30;
        constexpr  ptrdiff_t m_WindClothForceHandle = 0xAC0;
        constexpr  ptrdiff_t m_nMaterial = 0x5E;
        constexpr  ptrdiff_t m_iEffectName = 0x6C;
        constexpr  ptrdiff_t team = 0x8;
        constexpr  ptrdiff_t slot = 0xA;
        constexpr  ptrdiff_t m_nHierarchyId = 0x28;
        constexpr  ptrdiff_t m_nDetailLayerMask = 0x2A;
        constexpr  ptrdiff_t m_nSceneStringIndex = 0x614;
        constexpr  ptrdiff_t m_arrProhibitedItemIndices = 0x8C8;
        constexpr  ptrdiff_t m_iAmmo = 0x68;
        constexpr  ptrdiff_t m_nDistFadeStart = 0x10;
        constexpr  ptrdiff_t m_nDistFadeEnd = 0x12;
    }

    // ============================================
    // Context: uint32
    // ============================================
    namespace uint32
    {
        constexpr  ptrdiff_t m_iWindSeed = 0xC;
        constexpr  ptrdiff_t m_nSplitscreenFlags = 0x54;
        constexpr  ptrdiff_t m_pButtonPressedCmdNumber = 0x88;
        constexpr  ptrdiff_t m_nLastCommandNumberProcessed = 0x188;
        constexpr  ptrdiff_t m_nActiveIKChainMask = 0x5C;
        constexpr  ptrdiff_t m_nSerializePoseRecipeAG2ActiveSlot = 0x3F8;
        constexpr  ptrdiff_t m_soundEventHash = 0x688;
        constexpr  ptrdiff_t m_iEntityLevel = 0x1C0;
        constexpr  ptrdiff_t m_iItemIDHigh = 0x1D0;
        constexpr  ptrdiff_t m_iItemIDLow = 0x1D4;
        constexpr  ptrdiff_t m_iAccountID = 0x1D8;
        constexpr  ptrdiff_t m_iInventoryPosition = 0x1DC;
        constexpr  ptrdiff_t soundEventHash = 0x74;
        constexpr  ptrdiff_t m_unOwnerContext = 0x1170;
        constexpr  ptrdiff_t m_unHorizontalAlign = 0x1174;
        constexpr  ptrdiff_t m_unVerticalAlign = 0x1178;
        constexpr  ptrdiff_t m_unOrientation = 0x117C;
        constexpr  ptrdiff_t m_nKeychainDefID = 0x1160;
        constexpr  ptrdiff_t m_nKeychainSeed = 0x1164;
        constexpr  ptrdiff_t nIndex = 0x40;
        constexpr  ptrdiff_t m_iFOV = 0x290;
        constexpr  ptrdiff_t m_iFOVStart = 0x294;
        constexpr  ptrdiff_t m_unPreviousWeaponHash = 0x14D0;
        constexpr  ptrdiff_t m_unWeaponHash = 0x14D4;
        constexpr  ptrdiff_t m_vecPlayerPatchEconIndices = 0x1B80;
        constexpr  ptrdiff_t m_bvDisabledHitGroups = 0xF98;
        constexpr  ptrdiff_t m_spawnflags = 0x3EC;
        constexpr  ptrdiff_t m_fFlags = 0x3F8;
        constexpr  ptrdiff_t m_fEffects = 0x52C;
        constexpr  ptrdiff_t m_iHideHUD = 0x12B0;
        constexpr  ptrdiff_t m_iPing = 0x828;
        constexpr  ptrdiff_t m_uiCommunicationMuteFlags = 0x830;
        constexpr  ptrdiff_t m_rtActiveMissionPeriod = 0x8A0;
        constexpr  ptrdiff_t m_unPlayerTvControlFlags = 0x8A8;
        constexpr  ptrdiff_t m_msQueuedModeDisconnectionTimestamp = 0x8DC;
        constexpr  ptrdiff_t m_uiAbandonRecordedReason = 0x8E0;
        constexpr  ptrdiff_t m_eNetworkDisconnectionReason = 0x8E4;
        constexpr  ptrdiff_t m_iPawnHealth = 0x918;
        constexpr  ptrdiff_t m_nMagnitude = 0xFE0;
        constexpr  ptrdiff_t m_iClanID = 0x950;
        constexpr  ptrdiff_t m_hLayerSpawnGroup = 0x62C;
        constexpr  ptrdiff_t m_nDamageType = 0x58;
        constexpr  ptrdiff_t m_nEntityId = 0x20;
        constexpr  ptrdiff_t m_nOwnerId = 0x24;
        constexpr  ptrdiff_t m_OriginalOwnerXuidLow = 0x1650;
        constexpr  ptrdiff_t m_OriginalOwnerXuidHigh = 0x1654;
        constexpr  ptrdiff_t m_arrTournamentActiveCasterAccounts = 0x990;
        constexpr  ptrdiff_t m_boneIndexAttached = 0x11E0;
        constexpr  ptrdiff_t m_ragdollAttachedObjectIndex = 0x11E4;
        constexpr  ptrdiff_t m_nRenderOrder = 0xFBC;
        constexpr  ptrdiff_t m_bSpottedByMask = 0xC;
        constexpr  ptrdiff_t m_nBeamFlags = 0xFF4;
        constexpr  ptrdiff_t m_nOldTotalShootPositionHistoryCount = 0xD4;
        constexpr  ptrdiff_t m_nOldTotalInputHistoryCount = 0x370;
        constexpr  ptrdiff_t m_unAccountID = 0xFAC;
        constexpr  ptrdiff_t m_unTraceID = 0xFB0;
        constexpr  ptrdiff_t m_rtGcTime = 0xFB4;
        constexpr  ptrdiff_t m_flags = 0x30;
        constexpr  ptrdiff_t m_fDataObjectTypes = 0x3C;
        constexpr  ptrdiff_t m_nBrightness = 0xFD0;
        constexpr  ptrdiff_t m_nTickBase = 0x6B8;
        constexpr  ptrdiff_t m_iDesiredFOV = 0x78C;
    }

    // ============================================
    // Context: uint64
    // ============================================
    namespace uint64
    {
        constexpr  ptrdiff_t m_nQueuedButtonDownMask = 0x70;
        constexpr  ptrdiff_t m_nQueuedButtonChangeMask = 0x78;
        constexpr  ptrdiff_t m_nButtonDoublePressed = 0x80;
        constexpr  ptrdiff_t m_nToggleButtonDownMask = 0x190;
        constexpr  ptrdiff_t m_iItemID = 0x1C8;
        constexpr  ptrdiff_t m_ullRegisteredAsItemID = 0x4C8;
        constexpr  ptrdiff_t m_nPlayerDominated = 0x870;
        constexpr  ptrdiff_t m_nPlayerDominatingMe = 0x878;
        constexpr  ptrdiff_t m_nButtonDownMaskPrev = 0x688;
        constexpr  ptrdiff_t m_MeshGroupMask = 0x1C8;
        constexpr  ptrdiff_t m_xuid = 0x618;
        constexpr  ptrdiff_t m_DamagerXuid = 0x50;
        constexpr  ptrdiff_t m_RecipientXuid = 0x58;
        constexpr  ptrdiff_t m_nInteractsAs = 0x8;
        constexpr  ptrdiff_t m_nInteractsWith = 0x10;
        constexpr  ptrdiff_t m_nInteractsExclude = 0x18;
        constexpr  ptrdiff_t m_ullLocalMatchID = 0xC58;
        constexpr  ptrdiff_t m_nInButtonsWhichAreToggles = 0x6B0;
        constexpr  ptrdiff_t m_steamID = 0x780;
    }

    // ============================================
    // Context: uint8
    // ============================================
    namespace uint8
    {
        constexpr  ptrdiff_t m_ubStyleOverride = 0x1FC;
        constexpr  ptrdiff_t m_unClientFlags = 0x1FD;
        constexpr  ptrdiff_t localBits = 0x6C;
        constexpr  ptrdiff_t m_nEconGlovesChanged = 0x1AC8;
        constexpr  ptrdiff_t m_nHierarchicalDepth = 0x107;
        constexpr  ptrdiff_t m_nHierarchyType = 0x108;
        constexpr  ptrdiff_t m_nDoNotSetAnimTimeInInvalidatePhysicsCount = 0x109;
        constexpr  ptrdiff_t m_iObserverMode = 0x48;
        constexpr  ptrdiff_t m_nSegments = 0x1268;
        constexpr  ptrdiff_t m_Subdiv = 0x1276;
        constexpr  ptrdiff_t m_fLockedPoints = 0x1280;
        constexpr  ptrdiff_t m_nChangeCount = 0x1281;
        constexpr  ptrdiff_t m_nObjectCulling = 0xE44;
        constexpr  ptrdiff_t m_lifeState = 0x354;
        constexpr  ptrdiff_t m_ubInterpolationFrame = 0x361;
        constexpr  ptrdiff_t m_nWaterType = 0x378;
        constexpr  ptrdiff_t m_nSceneObjectOverrideFlags = 0x3BC;
        constexpr  ptrdiff_t m_iTeamNum = 0x3EB;
        constexpr  ptrdiff_t m_fBBoxVisFlags = 0x560;
        constexpr  ptrdiff_t m_nHitboxSet = 0x3C8;
        constexpr  ptrdiff_t m_iPendingTeamNum = 0x840;
        constexpr  ptrdiff_t m_recentKillQueue = 0x938;
        constexpr  ptrdiff_t m_nFirstKill = 0x940;
        constexpr  ptrdiff_t m_nKillCount = 0x941;
        constexpr  ptrdiff_t m_Flags = 0xFA8;
        constexpr  ptrdiff_t m_LightStyle = 0xFA9;
        constexpr  ptrdiff_t m_nRootBoneOffsetResetSerialNumber = 0xF4;
        constexpr  ptrdiff_t m_nAnimStateNoInterpSerialNumber = 0x1C0;
        constexpr  ptrdiff_t m_usSolidFlags = 0x5A;
        constexpr  ptrdiff_t m_triggerBloat = 0x5C;
        constexpr  ptrdiff_t m_CollisionGroup = 0x5E;
        constexpr  ptrdiff_t m_nEnablePhysics = 0x5F;
        constexpr  ptrdiff_t m_nPenetrate = 0x5C;
        constexpr  ptrdiff_t m_nColor = 0x62;
        constexpr  ptrdiff_t m_fFlags = 0x63;
        constexpr  ptrdiff_t m_iServerControlPointAssignments = 0x11F8;
        constexpr  ptrdiff_t m_nDetailLayerMaskType = 0x2C;
        constexpr  ptrdiff_t m_nTargetDetailLayer = 0x2D;
        constexpr  ptrdiff_t m_nCollisionGroup = 0x2E;
        constexpr  ptrdiff_t m_nCollisionFunctionMask = 0x2F;
        constexpr  ptrdiff_t m_nMatchEndCount = 0xEF8;
        constexpr  ptrdiff_t m_nRoundEndCount = 0xF44;
        constexpr  ptrdiff_t m_nRoundStartCount = 0xF4C;
        constexpr  ptrdiff_t m_nNumBeamEnts = 0xFB8;
        constexpr  ptrdiff_t m_nVersion = 0xFFC;
        constexpr  ptrdiff_t m_ubSignature = 0xFFD;
        constexpr  ptrdiff_t m_nMuzzleSmokeShotThreshold = 0x4B8;
        constexpr  ptrdiff_t nShakeType = 0x34;
        constexpr  ptrdiff_t m_nAlpha = 0x17;
    }
}
