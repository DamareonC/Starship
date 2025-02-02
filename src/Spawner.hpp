#pragma once

#include "IFallingEntity.hpp"

#include <random>

class Spawner : public sf::Drawable
{
public:
    Spawner();
    void spawnFallingEntity();
    const std::vector<std::unique_ptr<IFallingEntity>>& getFallingEntities() { return m_FallingEntities; };
private:
    std::mt19937 m_Mt;
    std::uniform_int_distribution<uint32_t> m_SpawnRange;
    std::vector<std::unique_ptr<IFallingEntity>> m_FallingEntities;
    uint32_t m_UpdateCount;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};