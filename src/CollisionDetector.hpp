#pragma once

#include "IFallingEntity.hpp"
#include "Bullet.hpp"

#include <SFML/Graphics.hpp>

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
            }
        }
}