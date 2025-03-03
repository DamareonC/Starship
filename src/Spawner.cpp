#include "Spawner.hpp"
#include "Asteroid.hpp"
#include "Missle.hpp"

#include <chrono>

inline unsigned int g_WindowWidth, g_WindowHeight;
inline uint32_t g_Score;

Spawner::Spawner() :
    m_SpawnRange(0U, g_WindowWidth),
    m_FallingEntityType(0U, 9U)
{
    m_FallingEntities.reserve(20U);
}

void Spawner::update()
{
    if (m_UpdateCount == 0U)
        spawnFallingEntity();

    if (m_FallingEntities.size() > 0U)
    {
        for (size_t i = 0U; i < m_FallingEntities.size(); i++)
        {
            m_FallingEntities[i]->update();

            if (m_FallingEntities[i]->getPosition().y > g_WindowHeight || m_FallingEntities[i]->isDestroyed())
                m_FallingEntities.erase(m_FallingEntities.begin() + i);
        }
    }
    
    if (m_UpdateCount >= 60U)
    {
        m_UpdateCount = 0U;
        m_SecondCount++;
        increaseSpeed();
    }
    else
        m_UpdateCount++;
}

void Spawner::increaseSpeed()
{
    if (m_SecondCount == 5U)
    {
        m_SecondCount = 0U;
        m_GlobalBaseSpeed = m_GlobalBaseSpeed + 0.01F;

        if (g_Score != 0U)
            m_GlobalBaseSpeed += (g_Score / 10U) * 0.02F;
    }
}

void Spawner::spawnFallingEntity()
{
    switch (m_FallingEntityType(m_Mt))
    {
        case 0:
            m_FallingEntities.emplace_back(std::make_unique<Missle>(sf::Vector2f(m_SpawnRange(m_Mt), -32.0F), m_GlobalBaseSpeed));
            break;
        default:
            m_FallingEntities.emplace_back(std::make_unique<Asteroid>(sf::Vector2f(m_SpawnRange(m_Mt), -32.0F), m_GlobalBaseSpeed));
            break;
    }
}

void Spawner::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const std::unique_ptr<IFallingEntity>& fallingEntity : m_FallingEntities)
        target.draw(*fallingEntity, states);
}