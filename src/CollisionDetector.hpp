#pragma once

#include "IFallingEntity.hpp"
#include "IPowerUp.hpp"
#include "Bullet.hpp"

//g_Score will be included from Score.hpp in Game.cpp

static void checkCollision(const std::vector<std::unique_ptr<IFallingEntity>>& fallingEntities, IEntity& entity)
{
    for (const std::unique_ptr<IFallingEntity>& fallingEntity : fallingEntities)
    {
        if (fallingEntity->collidingWithEntity(entity))
        {
            Bullet* bullet = dynamic_cast<Bullet*>(&entity);
            
            if (bullet != nullptr && fallingEntity->isEnemy())
            {
                fallingEntity->destroy();
                bullet->destroy();
                g_Score += fallingEntity->getScore();
            }

            Ship* ship = dynamic_cast<Ship*>(&entity);

            if (ship != nullptr)
            {
                if (fallingEntity->isEnemy())
                {
                    ship->destroy();
                }
                else
                {
                    IPowerUp* powerUp = dynamic_cast<IPowerUp*>(fallingEntity.get());

                    if (powerUp != nullptr)
                    {
                        ship->setPowerUp(powerUp->givePowerUp());
                    }
                }

                fallingEntity->destroy();
            }
        }
    }
}