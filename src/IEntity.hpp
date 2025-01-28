#pragma once

class IEntity
{
public:
    virtual void update() = 0;
protected:
    static constexpr float s_SCALE_FACTOR = 2.0f;
};