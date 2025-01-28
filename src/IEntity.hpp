#pragma once

#include <SFML/Graphics.hpp>

class IEntity : public sf::Drawable
{
protected:
    virtual void update() = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
protected:
    static constexpr float s_SCALE_FACTOR = 2.0f;
};