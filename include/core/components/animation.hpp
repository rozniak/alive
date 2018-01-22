#pragma once

#include "core/component.hpp"
#include "resourcemapper.hpp"

class TransformComponent;

class AnimationComponent final : public Component
{
public:
    DECLARE_COMPONENT(AnimationComponent)
public:
    void Load(ResourceLocator& resLoc, const char* animationName);
    void Change(const char* animationName);
    bool Complete() const;
    s32 FrameNumber() const;
    void Update();
    void Render(AbstractRenderer& rend) const;
public:
    bool mFlipX = false;
    std::unique_ptr<Animation> mAnimation;
private:
    ResourceLocator *mResourceLocator = nullptr;
    TransformComponent* mTransformComponent = nullptr;
};