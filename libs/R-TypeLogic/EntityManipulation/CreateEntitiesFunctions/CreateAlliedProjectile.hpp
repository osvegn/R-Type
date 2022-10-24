/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** CreateAlliedProjectile
*/

#ifndef CREATEALLYPROJECTILE_HPP_
#define CREATEALLYPROJECTILE_HPP_

#include "Transisthor/TransisthorECSLogic/Both/Components/Networkable.hpp"
#include "World/World.hpp"
#include "R-TypeLogic/Global/Components/AlliedProjectileComponent.hpp"
#include "R-TypeLogic/Global/Components/CollidableComponent.hpp"
#include "R-TypeLogic/Global/Components/DamageComponent.hpp"
#include "R-TypeLogic/Global/Components/DamageRadiusComponent.hpp"
#include "R-TypeLogic/Global/Components/LayerLvL.hpp"
#include "R-TypeLogic/Global/Components/LifeComponent.hpp"
#include "R-TypeLogic/Global/Components/LifeTimeComponent.hpp"
#include "R-TypeLogic/Global/Components/NewlyCreated.hpp"
#include "R-TypeLogic/Global/Components/PositionComponent.hpp"
#include "R-TypeLogic/Global/Components/SizeComponent.hpp"
#include "R-TypeLogic/Global/Components/VelocityComponent.hpp"
#include "R-TypeLogic/Global/Components/WeightComponent.hpp"
#include "R-TypeLogic/Global/SharedResources/Random.hpp"

namespace ecs
{
    /// @brief This function creates a new Entity projectile_ally when an ally shoot
    /// @param world The world in which the Enemy must be created
    /// @param ally Entity who fired an ally projectile
    /// @param uuid The uuid of the entity. Can be empty.
    /// @param networkId The id of the Networkable Component. In the client instance, it MUST NOT be filled in.
    /// @return Id in size_t of the new Entity
    inline std::size_t createNewAlliedProjectile(
        World &world, Entity &ally, const std::string uuid = "", unsigned short networkId = 0)
    {
        Position pos = ally.getComponent<Position>();
        Damage damage = ally.getComponent<Damage>();
        Velocity velocity = ally.getComponent<Velocity>();

        Entity &entity = world.addEntity()
                             .addComponent<Position>(pos.x + 102, pos.y + 45)
                             .addComponent<Velocity>(300, 0)
                             .addComponent<Weight>(1)
                             .addComponent<Size>(40, 40)
                             .addComponent<LifeTime>(3)
                             .addComponent<Life>(1)
                             .addComponent<Damage>(damage)
                             .addComponent<DamageRadius>(5)
                             .addComponent<Collidable>()
                             .addComponent<AlliedProjectile>(ally.getComponent<Networkable>().id);

        if (networkId) {
            // Case : Creation in a server instance
            entity.addComponent<NewlyCreated>(uuid, false);
            entity.addComponent<Networkable>(networkId);
        } else {
            entity.addComponent<Networkable>(0);
            // Case : Creation in a Client instance
            if (uuid != "") {
                // Special case : the client created the entity and not the server
                entity.addComponent<NewlyCreated>(uuid, true);
            }
            entity.addComponent<LayerLvL>(LayerLvL::layer_e::PROJECTILE);
        }
        return entity.getId();
    }
} // namespace ecs
#endif /* !CREATEALLYPROJECTILE_HPP_ */
