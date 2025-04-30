#pragma once

#include "IFallingEntity.hpp"

#include <random>

class Spawner : public sf::Drawable
{
public:
    Spawner();
    void update();
    void reset();
    void setSpawnRange();
    const std::vector<std::unique_ptr<IFallingEntity>>& getFallingEntities() const { return m_FallingEntities; };
private:
    std::mt19937 m_Mt = std::mt19937(static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<uint32_t> m_SpawnRange, m_FallingEntityType, m_EnemyType, m_PowerUpType;
    std::vector<std::unique_ptr<IFallingEntity>> m_FallingEntities;
    uint32_t m_UpdateCount = 0U, m_SecondCount = 0U;
    float m_GlobalBaseSpeed = 3.0F;

    void increaseSpeed();
    void spawnFallingEntity();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};