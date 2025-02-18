#pragma once

#include "IFallingEntity.hpp"

#include <random>

class Spawner : public sf::Drawable
{
public:
    Spawner();
    void update();
    const std::vector<std::unique_ptr<IFallingEntity>>& getFallingEntities() { return m_FallingEntities; };
private:
    std::mt19937 m_Mt;
    std::uniform_int_distribution<uint32_t> m_SpawnRange, m_FallingEntityType;
    std::vector<std::unique_ptr<IFallingEntity>> m_FallingEntities;
    uint32_t m_UpdateCount = 0U, m_SecondCount = 0U;
    float m_GlobalBaseSpeed = 3.0F;

    void increaseSpeed();
    void spawnFallingEntity();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};