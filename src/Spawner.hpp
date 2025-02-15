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
    uint32_t m_UpdateCount;

    void spawnFallingEntity();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};