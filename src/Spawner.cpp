#include "Spawner.hpp"
#include "Asteroid.hpp"

#include <chrono>

inline unsigned int g_WindowWidth, g_WindowHeight;

Spawner::Spawner() :
    m_Mt(static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())),
    m_SpawnRange(0, g_WindowWidth)
{
    m_FallingEntities.reserve(20);
}

void Spawner::spawnFallingEntity()
{
    m_UpdateCount++;
    
    if (m_UpdateCount == 10)
        m_FallingEntities.emplace_back(std::make_unique<Asteroid>(sf::Vector2f(m_SpawnRange(m_Mt), 0.0f), 3.0f));

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
}

void Spawner::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (size_t i = 0; i < m_FallingEntities.size(); i++)
        target.draw(*m_FallingEntities[i], states);
}