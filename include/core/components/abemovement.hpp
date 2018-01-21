#pragma once

#include "input.hpp"
#include "core/component.hpp"

class PhysicsComponent;
class AnimationComponent;

class AbeMovementComponent final : public Component
{
public:
    void Load();
    void Update() override;
public:
    bool mLeft = false;
    bool mRight = false;
    bool mChant = false;
private:
    const Actions* mInputMappingActions = nullptr;
    PhysicsComponent* mPhysicsComponent = nullptr;
    AnimationComponent* mAnimationComponent = nullptr;
};

class AbePlayerControllerComponent final : public Component
{
public:
    void Load(const InputState& state); // TODO: Input is wired here
    void Update() override;
private:
    const Actions* mInputMappingActions = nullptr;
    AbeMovementComponent* mAbeMovement = nullptr;
};