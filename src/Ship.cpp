#include "Ship.hpp"

inline unsigned int g_WindowWidth, g_WindowHeight;

Ship::Ship() :
    m_Sprite(m_TEXTURE),
    m_ShootSound(m_SHOOT_SOUND_BUFFER)
{
    const sf::Vector2f spawnPoint = sf::Vector2f((g_WindowWidth / 2.0f) - m_Sprite.getTextureRect().size.x, g_WindowHeight - m_Sprite.getTextureRect().size.y * s_SCALE_FACTOR);

    m_Sprite.setPosition(spawnPoint);
    m_Sprite.scale(sf::Vector2f(s_SCALE_FACTOR, s_SCALE_FACTOR));

    m_Shield.setFillColor(sf::Color(0U, 127U, 255U, 127U));
    m_Shield.setOutlineColor(sf::Color(0U, 127U, 255U));
    m_Shield.setOutlineThickness(1.0F);
    m_Shield.setRadius(m_Sprite.getTextureRect().size.x / 2.0F);
    m_Shield.setPosition(m_Sprite.getPosition());
    m_Shield.setScale(sf::Vector2f(s_SCALE_FACTOR, s_SCALE_FACTOR));

    m_Bullets.reserve(50);
}

void Ship::update()
{
    if (m_CooldownUpdates > 0U)
    {
        m_CooldownUpdates--;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && m_Sprite.getPosition().y >= 0.0F)
    {
        m_Sprite.move(sf::Vector2f(0.0F, -m_Speed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && m_Sprite.getPosition().x >= 0.0F)
    {
        m_Sprite.move(sf::Vector2f(-m_Speed, 0.0F));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && m_Sprite.getPosition().y <= (g_WindowHeight - (m_Sprite.getTextureRect().size.x * s_SCALE_FACTOR)))
    {
        m_Sprite.move(sf::Vector2f(0.0F, m_Speed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && m_Sprite.getPosition().x <= (g_WindowWidth - (m_Sprite.getTextureRect().size.x * s_SCALE_FACTOR)))
    {
        m_Sprite.move(sf::Vector2f(m_Speed, 0.0F));
    }

    m_Shield.setPosition(m_Sprite.getPosition());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_CooldownUpdates == 0.0F)
    {
        shoot();
        m_CooldownUpdates = 20U;
    }

    updateBullets();
}

void Ship::updateBullets()
{
    for (size_t i = 0U; i < m_Bullets.size(); i++)
    {
        m_Bullets[i].update();

        if (m_Bullets[i].getPosition().y < 0.0F || m_Bullets[i].isDestroyed())
        {
            m_Bullets.erase(m_Bullets.begin() + i);
        }
    }
}

void Ship::shoot()
{
    if (m_DoubleShotsLeft > 0)
    {
        m_Bullets.emplace_back(sf::Vector2f(m_Sprite.getPosition().x, m_Sprite.getPosition().y - (3.0F * s_SCALE_FACTOR)));
        m_Bullets.emplace_back(sf::Vector2f(m_Sprite.getPosition().x + (12.0F * s_SCALE_FACTOR), m_Sprite.getPosition().y - (3.0F * s_SCALE_FACTOR)));

        m_DoubleShotsLeft--;
    }
    else
    {
        m_Bullets.emplace_back(sf::Vector2f(m_Sprite.getPosition().x + (6.0F * s_SCALE_FACTOR), m_Sprite.getPosition().y - (3.0F * s_SCALE_FACTOR)));
    }

    m_ShootSound.play();
}

void Ship::reset()
{
    m_CooldownUpdates = 0U;
    m_DoubleShotsLeft = 0U;
    m_Speed = 3.0F;
    m_Destroyed = false;
    m_Shielded = false;

    const sf::Vector2f spawnPoint = sf::Vector2f((g_WindowWidth / 2.0f) - m_Sprite.getTextureRect().size.x, g_WindowHeight - m_Sprite.getTextureRect().size.y * s_SCALE_FACTOR);

    m_Sprite.setPosition(spawnPoint);
    m_ShootSound.stop();
    m_Bullets.clear();
}

void Ship::setPowerUp(PowerUp powerUp)
{
    switch (powerUp)
    {
        case PowerUp::DOUBLE_SHOT:
            m_DoubleShotsLeft = 30U;
            m_Shielded = false;
            m_Speed = 3.0F;
            break;
        case PowerUp::SHIELD:
            m_DoubleShotsLeft = 0U;
            m_Shielded = true;
            m_Speed = 3.0F;
            break;
        case PowerUp::SPEED_BOOST:
            m_DoubleShotsLeft = 0U;
            m_Shielded = false;
            m_Speed = 4.5F;
            break;
        default:
            break;
    }
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_Sprite, states);

    if (m_Shielded)
    {
        target.draw(m_Shield, states);
    }

    drawBullets(target, states);
}

void Ship::drawBullets(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const Bullet& bullet : m_Bullets)
    {
        target.draw(bullet, states);
    }
}