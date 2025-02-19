#pragma once

#include "IEntity.hpp"

#include <SFML/Audio.hpp>

class IFallingEntity : public IEntity
{
public:
    virtual ~IFallingEntity() = default;
    virtual void update() = 0;
    virtual void destroy() { s_DestroySound.play(); };
    virtual bool isDangerous() const = 0;
    virtual bool isDestroyed() const = 0;
    bool collidingWithEntity(const IEntity& entity) const { return this->getGlobalBounds().findIntersection(entity.getGlobalBounds()).has_value(); };
    virtual uint32_t getScore() const = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
protected:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
private:
    static inline const sf::SoundBuffer s_DESTROY_SOUND_BUFFER = sf::SoundBuffer(std::filesystem::path("res/sounds/destroy.ogg"));
    static inline sf::Sound s_DestroySound = sf::Sound(s_DESTROY_SOUND_BUFFER);
};