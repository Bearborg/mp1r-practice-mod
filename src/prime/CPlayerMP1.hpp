#pragma once

#include "prime/Math.hpp"
#include "program/GetField.hpp"

class CActorMP1 {
public:
  CTransform4f &GetTransform() const;
  CTransform4f SetTransform(const CTransform4f &transform);
};

class CStateManager;
class CPhysicsActorMP1 : public CActorMP1 {
public:
  CVector3f *GetVelocityWR(const CStateManager &mgr) const;
  //_ZN16CPhysicsActorMP113SetVelocityWRER13CStateManagerRK9CVector3f
  //_ZN16CPhysicsActorMP113SetVelocityWRERK13CStateManagerRK9CVector3f
  void SetVelocityWR(CStateManager &mgr, const CVector3f &vel);

  CAxisAngle *GetAngularVelocityWR(const CStateManager &mgr) const;
  void SetAngularVelocityWR(CStateManager &mgr, const CAxisAngle &vel);
};

enum class EPlayerMovementState: uint32_t { OnGround, Jump, ApplyJump, Falling, FallingMorphed };
inline const char* stateToName(EPlayerMovementState state) {
  switch (state) {
    case EPlayerMovementState::OnGround: return "OnGround";
    case EPlayerMovementState::Jump: return "Jump";
    case EPlayerMovementState::ApplyJump: return "ApplyJump";
    case EPlayerMovementState::Falling: return "Falling";
    case EPlayerMovementState::FallingMorphed: return "FallingMorphed";
    default: return "Unknown";
  }
}

class CMorphBallMP1 {
public:
  uint32_t GetBombJumpState() const;
  bool GetIsInHalfPipeMode() const;
  bool GetIsInHalfPipeModeInAir() const;
  bool GetTouchedHalfPipeRecently() const;
};

class CHealthInfoMP1 {
public:
  float heatlh;
//  inline float &GetA() const { return *GetField<float>(this, 0x0); }
//  inline float &GetB() const { return *GetField<float>(this, 0x4); }
};

class CFinalInput;
class CPlayerMP1 : public CPhysicsActorMP1 {
public:
  inline CMorphBallMP1 *GetMorphBall() { return *GetField<CMorphBallMP1*>(this, 0x9d0); }
  inline EPlayerMovementState GetMoveState() { return *GetField<EPlayerMovementState>(this, 0x3f0); }
  CHealthInfoMP1 &HealthInfo(CStateManager &mgr);
  void ProcessInput(const CFinalInput&, CStateManager&);
};
