#pragma once

#include "IFallingEntity.hpp"

enum class PowerUp : int32_t
{
    NONE = -1, DOUBLE_SHOT, SHIELD, SPEED_BOOST
};

class IPowerUp : public IFallingEntity
{
public:
    virtual ~IPowerUp() = default;
    virtual void update() = 0;
    virtual void destroy() { s_PowerUpSound.play(); };
    virtual PowerUp givePowerUp() const = 0;
    bool isEnemy() const { return false; };
    virtual bool isDestroyed() const = 0;
    virtual uint32_t getScore() const { return 0; };
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual sf::Vector2f getPosition() const = 0;
protected:
    static constexpr float s_POWERUP_SPEED = 0.5F;

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;
private:
    static inline const sf::SoundBuffer s_POWERUP_SOUND_BUFFER = sf::SoundBuffer(std::filesystem::path("res/sounds/powerup.ogg"));
    static inline sf::Sound s_PowerUpSound = sf::Sound(s_POWERUP_SOUND_BUFFER);
};