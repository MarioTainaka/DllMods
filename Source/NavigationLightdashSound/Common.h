#pragma once

enum SonicContextEnum
{
    Modern,
    Classic,
    Super,
    Any
};

inline void* GetCurrentSonicContext(SonicContextEnum contextEnum = SonicContextEnum::Any)
{
    void* const pModernSonicContext = *(void**)0x1E5E2F8;
    void* const pClassicSonicContext = *(void**)0x1E5E304;
    void* const pSuperSonicContext = *(void**)0x1E5E310;

    switch (contextEnum)
    {
    case Modern:    return pModernSonicContext;
    case Classic:   return pClassicSonicContext;
    case Super:     return pSuperSonicContext;
    default:        break;
    }

    void* pSonicContext = pModernSonicContext;
    if (!pSonicContext) pSonicContext = pClassicSonicContext;
    if (!pSonicContext) pSonicContext = pSuperSonicContext;
    return pSonicContext;
}

// Sonic state flags have been taken from: https://github.com/ChimeraReyat/3D-Spindash
struct CSonicStateFlags
{
	bool EarthGround;
	bool HeadToVelocity;
	bool HeadUpOnly;
	bool SlowHeadToUpDirection;
	bool OutOfControl;
	bool NoLandOutOfControl;
	bool DisableForwardPathInterpolation;
	bool ChangePath;
	bool ChangePathCameraChange;
	bool WallWalkJump;
	bool SupportWalkOnCeiling;
	bool NotifyWalkOnCeiling;
	bool AlwaysDownForce;
	bool DisableDownForce;
	bool Dead;
	bool Goal;
	bool Boost;
	bool FloatingBoost;
	bool StartingBoost;
	bool EndBoost;
	bool DummyBoost;
	bool EndDummyBoost;
	bool Homing;
	bool EnableHomingAttack;
	bool EnableHomingAttackOnDiving;
	bool EnableHomingAttackOutOfControl;
	bool DisableAirBoost;
	bool EnableAirOnceAction;
	bool DisableStomping;
	bool ForceShoesSliding;
	bool DisableShoesSliding;
	bool OnWater;
	bool OnNoDeadWater;
	bool OnAboveWater;
	bool OnSurfaceWater;
	bool OnShallowWater;
	bool OnWaterSeEnabled;
	bool TerrainCollisionEnable;
	bool AirOutOfControl;
	bool NoPadStopWalk;
	bool DisableAirAutoDec;
	bool DisableWallJumpReady;
	bool GroundDistanceZero;
	bool NoPitchRollHorzOnAir;
	bool DisableMoonsault;
	bool KeepRunning;
	bool KeepRunningEnableBackForce;
	bool KeepRunningOnSpiral;
	bool KeepRunningPause;
	bool SShapeRunning;
	bool MoveOnPath;
	bool IgnoreTerrain;
	bool UpdateYawByVelocity;
	bool NoPitchRoll;
	bool NoUpdateYaw;
	bool NoUpdateYawRef;
	bool UpdateYawOnAir;
	bool NoUpdateAdvancedDirection;
	bool CameraChagedPadCorrection;
	bool EnableCameraChagedPadCorrect;
	bool CameraToCullingBasePosEnabled;
	bool NoDamage;
	bool NoDead;
	bool Damaging;
	bool Paralyzing;
	bool ReactinJumpPathChange;
	bool ForcePitchRollGround;
	bool EnableAttenuateJump;
	bool NoGroundFall;
	bool OnStairs;
	bool OnBeltConveyor;
	bool MoveToPositionAndWait;
	bool StopPositionCount;
	bool OnNoWallWalkGround;
	bool ForceLandForCaught;
	bool Restarting;
	bool SlidingAndSquatPressOnly;
	bool SideViewNoPathMove;
	bool Pushing;
	bool NoChange2DPath;
	bool PrepreRestart;
	bool SetDirectRotation;
	bool IsTakingBreath;
	bool OnSpiralGound;
	bool OnMovableGround;
	bool OnFakeMovableGround;
	bool OnMoonsaltDisableGround;
	bool EnableExceptionalBoost;
	bool AcceptSlidingCollision;
	bool AcceptBuoyancyForce;
	bool AcceptEnvForce;
	bool DisableAdlibTrick;
	bool StandbyAdlibTrick;
	bool StandbyChangeToSpin;
	bool Pressing;
	bool FallEnabledInPressing;
	bool OnIntersectionalWay;
	bool ObserveBoostInExternalControl;
	bool ObserveSpinInExternalControl;
	bool ObserveInputInExternalControl;
	bool EscapeEnabledInExternalControl;
	bool NoDamageInExternalControl;
	bool Slipping;
	bool InvokeFlameBarrier;
	bool InvokeAquaBarrier;
	bool InvokeThunderBarrier;
	bool InvokeBarrier;
	bool InvokePreciousTime;
	bool InvokeHighSpeed;
	bool InvokeTimeBreak;
	bool InvokeSkateBoard;
	bool InvokeSuperSonic;
	bool InvokePtmRocket;
	bool InvokePtmSpike;
	bool InvokeUnbeaten;
	bool DoubleJumping;
	bool InvokeFixedMoveOn3D;
	bool KeepStateAfterChangeDimension;
	bool KeepPostureAfterChangeDimension;
	bool CalibrateFrontDir;
	bool EnableAnimationVelocityDirect;
	bool EnableGravityControl;
	bool EnableAirBoostOnGravityControl;
	bool EnableChaosEnergySetting;
	bool ChaosEnergySubstractDisabled;
	bool EnableAutoAim;
	bool ThroughGoalSignboard;
	bool AutoBoost;
	bool MaxSpeedLimited;
	bool Pause;
	bool SkateBoardSlowDown;
	bool ChangeCollisionLocked;
	bool ReadyGoOpened;
	bool SpikeSpin;
	bool ChangePostureInDeadAirEnabled;
	bool DisableGroundSmoke;
	bool Drifting;
	bool DriftingLowSpeed;
	bool DriftRight;
	bool Squat;
	bool LightSpeedDashReady;
	bool BoostKeep;
	bool DisableCrashWall;
	bool WallCorrection;
	bool Diving;
	bool DivingFloat;
	bool HipSliding;
	bool GrindFullBalance;
	bool GrindSideJump;
	bool Freeze;
	bool DisableBoost;
	bool NoSquatToSliding;
	bool IgnorePadInput;
	bool Rising;
	bool SpinChargeSliding;
	bool CombinationAttacking;
	bool SpinDash;
	bool LightAttack;
	bool AtomicSpin;
	bool Binding;
	bool ChgPlayerDisabled;
	bool EndReflection;
	bool CorrectOnPath;
	bool DebugDrawGroundHitPosition;
	bool DebugDrawVelocity;
	bool DebugDrawPath;
	bool DebugDrawSpikeInfo;
	bool DebugExceptionalMove;
};

inline CSonicStateFlags* GetSonicStateFlags()
{
	auto* const context = reinterpret_cast<int*>(*(int*)0x1E5E2F0);
	if (!context) return nullptr;
    return reinterpret_cast<CSonicStateFlags*>(*reinterpret_cast<int*>(context[0x14D] + 4));
}

using SharedPtrTypeless = boost::shared_ptr<void>;
typedef void* __fastcall CSonicSpeedContextPlaySound(void*, void*, SharedPtrTypeless&, uint32_t cueId, uint32_t);

inline void PlaySound(void* pSonicContext, SharedPtrTypeless& soundHandle, uint32_t cueID)
{
    if (!pSonicContext) return;

    // Original code by Skyth: https://github.com/blueskythlikesclouds
    CSonicSpeedContextPlaySound* playSoundFunc = *(CSonicSpeedContextPlaySound**)(*(uint32_t*)pSonicContext + 116);
    playSoundFunc(pSonicContext, nullptr, soundHandle, cueID, 0);
}
