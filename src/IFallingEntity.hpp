#pragma once

#include "IEntity.hpp"

class IFallingEntity : public IEntity
{
public:
    virtual ~IFallingEntity() = default;
    virtual void update() = 0;
    virtual void destroy() = 0;
    virtual bool isDangerous() const = 0;
    virtual bool isDestroyed() const = 0;
    bool collidingWithEntity(const IEntity& entity) const { return this->getGlobalBounds().findIntersection(entity.getGlobalBounds()).has_value(); };
    virtual uint32_t getScore() const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
protected:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
};