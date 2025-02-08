#pragma once

#include "IFallingEntity.hpp"
#include "Bullet.hpp"

#include <iostream>

inline uint32_t g_Score = 0;

void checkCollision(const std::vector<std::unique_ptr<IFallingEntity>>& fallingEntities, IEntity& entity)
{
    for (size_t i = 0; i < fallingEntities.size(); i++)
        if (fallingEntities[i]->collidingWithEntity(entity))
        {
            Bullet* bullet = dynamic_cast<Bullet*>(&entity);
            
            if (bullet != nullptr)
            {
                fallingEntities[i]->destroy();
                bullet->destroy();
                g_Score++;
                std::printf("%u\n", g_Score);
            }

            Ship* ship = dynamic_cast<Ship*>(&entity);

            if (ship != nullptr)
            {
                ship->destroy();
            }
        }
}