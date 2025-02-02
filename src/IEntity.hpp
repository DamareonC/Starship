#pragma once

#include <SFML/Graphics.hpp>

class IEntity : public sf::Drawable
{
public:
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
protected:
    static constexpr float s_SCALE_FACTOR = 2.0f;

    virtual ~IEntity() = default;
    virtual void update() = 0;
    virtual void destroy() = 0;
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
    virtual bool isDestroyed() = 0;
};