/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** CreateEnemy
*/

#ifndef CREATEENEMY_HPP_
#define CREATEENEMY_HPP_

#include "GameComponents/CollidableComponent.hpp"
#include "GameComponents/DamageComponent.hpp"
#include "GameComponents/DamageRadiusComponent.hpp"
#include "GameComponents/EnemyComponent.hpp"
#include "GameComponents/LifeComponent.hpp"
#include "GameComponents/LifeTimeComponent.hpp"
#include "GameComponents/PositionComponent.hpp"
#include "GameComponents/SizeComponent.hpp"
#include "GameComponents/VelocityComponent.hpp"
#include "GameComponents/WeightComponent.hpp"
#include "GameSharedResources/Random.hpp"
#include "GameComponents/TextureNameComponent.hpp"
#include "World/World.hpp"

#define MINIMUM_WIDTH  1400
#define MAXIMUM_WIDTH  1920
#define MINIMUM_HEIGTH 0
#define MAXIMUM_HEIGTH 1080

namespace ecs
{

    /// @brief This function creates a new Enemy Entity with these parameters
    /// @param world The world in which the Enemy must be created
    /// @param pos_x Position x of the Enemy
    /// @param pos_y Position y of the Enemy
    /// @param multiplierAbscissa The Velocity multiplierAbscissa for the new Enemy
    /// @param multiplierOrdinate The Velocity multiplierOrdinate for the new Enemy
    /// @param weight Weight of the Enemy
    /// @param size_x Size x of the Enemy
    /// @param size_y Size y of the Enemy
    /// @param life Life of the Enemy
    /// @param damage Damage of projectiles fired by this Enemy
    /// @param damageRadius DamageRadius of projectiles fired by this Enemy
    /// @return Id of the new Enemy in std::size_t
    inline std::size_t createNewEnemy(World &world, const int pos_x, const int pos_y, const double multiplierAbscissa,
        const double multiplierOrdinate, const short weight, const int size_x, const int size_y,
        const unsigned short life, const unsigned short damage, const unsigned short damageRadius)
    {
        return world.addEntity()
            .addComponent<Position>(pos_x, pos_y)
            .addComponent<Weight>(weight)
            .addComponent<Size>(size_x, size_y)
            .addComponent<Lifetime>()
            .addComponent<Life>(life)
            .addComponent<Damage>(damage)
            .addComponent<DamageRadius>(damageRadius)
            .addComponent<Collidable>()
            .addComponent<Velocity>(multiplierAbscissa, multiplierOrdinate)
            .addComponent<Enemy>()
            .addComponent<TextureName>()
            .getId();
    }

    /// @brief This function creates a new Enemy Entity with random position and with these parameters
    /// @param world The world in which the Enemy must be created
    /// @param multiplierAbscissa The Velocity multiplierAbscissa for the new Enemy
    /// @param multiplierOrdinate The Velocity multiplierOrdinate for the new Enemy
    /// @param weight Weight of the Enemy
    /// @param size_x Size x of the Enemy
    /// @param size_y Size y of the Enemy
    /// @param life Life of the Enemy
    /// @param damage Damage of projectiles fired by this Enemy
    /// @param damageRadius DamageRadius of projectiles fired by this Enemy
    /// @return Id of the new Enemy in std::size_t
    inline std::size_t createNewEnemyRandom(World &world, const double multiplierAbscissa,
        const double multiplierOrdinate, const short weight, const int size_x, const int size_y,
        const unsigned short life, const unsigned short damage, const unsigned short damageRadius)
    {
        return createNewEnemy(world, world.getResource<RandomDevice>().randInt(MINIMUM_WIDTH, MAXIMUM_WIDTH),
            world.getResource<RandomDevice>().randInt(MINIMUM_HEIGTH, MAXIMUM_HEIGTH), multiplierAbscissa,
            multiplierOrdinate, weight, size_x, size_y, life, damage, damageRadius);
    }

} // namespace ecs
#endif /* !CREATEENEMY_HPP_ */