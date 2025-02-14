#include "Spawner.hpp"
#include "Asteroid.hpp"
#include "Missle.hpp"

#include <chrono>

inline unsigned int g_WindowWidth, g_WindowHeight;

Spawner::Spawner() :
    m_Mt(static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())),
    m_SpawnRange(0, g_WindowWidth),
    m_FallingEntityType(0, 9)
{
    m_FallingEntities.reserve(20);
}

void Spawner::update()
{
    if (m_UpdateCount == 0)
        this->spawnFallingEntity();

    if (m_FallingEntities.size() > 0)
    {
        for (size_t i = 0; i < m_FallingEntities.size(); i++)
        {
            m_FallingEntities[i]->update();

            if (m_FallingEntities[i]->getPosition().y > g_WindowHeight || m_FallingEntities[i]->isDestroyed())
                m_FallingEntities.erase(m_FallingEntities.begin() + i);
        }
    }
    
    if (m_UpdateCount >= 60)
        m_UpdateCount = 0;
    else
        m_UpdateCount++;
}

void Spawner::spawnFallingEntity()
{
    switch (m_FallingEntityType(m_Mt))
    {
        case 0:
            m_FallingEntities.emplace_back(std::make_unique<Missle>(sf::Vector2f(m_SpawnRange(m_Mt), -32.0f), 3.0f));
            break;
        default:
            m_FallingEntities.emplace_back(std::make_unique<Asteroid>(sf::Vector2f(m_SpawnRange(m_Mt), -32.0f), 3.0f));
            break;
    }
}

void Spawner::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (const std::unique_ptr<IFallingEntity>& fallingEntity : m_FallingEntities)
        target.draw(*fallingEntity, states);
}