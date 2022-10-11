/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** CreateAlliedProjectile_test
*/

#include <criterion/criterion.h>
#include "World/World.hpp"
#include "CreateAlliedProjectile.hpp"

using namespace ecs;

Test(CreateAlliedProjectile_test, CreateAlliedProjectile)
{
    World world(1);
    
    std::size_t allied = world.addEntity()
                            .addComponent<Position>(1, 1)
                            .addComponent<Damage>(10)
                            .addComponent<Velocity>(1, 1)
                            .getId();

    std::size_t id_new_entity = createNewAlliedProjectile(world, world.getEntity(allied));
    
    cr_assert_eq(1, allied);
    cr_assert_eq(2, id_new_entity);
    cr_assert_eq(1, world.getEntity(1).getComponent<Position>().x);
}
