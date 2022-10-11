/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** CreateProjectile_test
*/

#include <criterion/criterion.h>
#include "World/World.hpp"
#include "CreateProjectile.hpp"

using namespace ecs;

Test(CreateProjectile_test, CreateAlliedProjectile)
{
    World world(1);


    std::size_t id_new_entity = createNewProjectile(world, 5, 5, 10, 10, 10);

    cr_assert_eq(1, id_new_entity);
    cr_assert_eq(5, world.getEntity(1).getComponent<Position>().x);
}
