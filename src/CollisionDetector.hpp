#pragma once

#include "IFallingEntity.hpp"
#include "Bullet.hpp"

inline uint32_t g_Score = 0;

void checkCollision(const std::vector<std::unique_ptr<IFallingEntity>>& fallingEntities, IEntity& entity)
{
    for (const std::unique_ptr<IFallingEntity>& fallingEntity : fallingEntities)
        if (fallingEntity->collidingWithEntity(entity))
        {
            Bullet* bullet = dynamic_cast<Bullet*>(&entity);
            
            if (bullet != nullptr)
            {
                fallingEntity->destroy();
                bullet->destroy();
                g_Score = g_Score + fallingEntity->getScore();
            }

            Ship* ship = dynamic_cast<Ship*>(&entity);

            if (ship != nullptr)
            {
                if (fallingEntity->isDangerous())
                    ship->destroy();
            }
        }
}