/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** DrawComponents
*/

#include "DrawComponents.hpp"
#include <algorithm>
#include "GraphicECS/SFML/Resources/RenderWindowResource.hpp"
#include "GraphicsRectangleComponent.hpp"
#include "GraphicsTextComponent.hpp"
#include "GraphicsTextureResource.hpp"
#include "TextureName.hpp"
#include "R-TypeLogic/Global/Components/AlliedProjectileComponent.hpp"
#include "R-TypeLogic/Global/Components/EnemyProjectileComponent.hpp"
#include "R-TypeLogic/Global/Components/LayerLvL.hpp"
#include "R-TypeLogic/Global/Components/PositionComponent.hpp"
#include "R-TypeLogic/Global/Components/SizeComponent.hpp"

using namespace ecs;
using namespace graphicECS::SFML::Resources;
using namespace graphicECS::SFML::Components;

bool DrawComponents::compareLayer(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2)
{
    return (e1->getComponent<LayerLvL>().layer < e2->getComponent<LayerLvL>().layer);
}

void DrawComponents::run(World &world)
{
    std::vector<std::shared_ptr<Entity>> Inputs = world.joinEntities<LayerLvL>();

    if (world.getResource<RenderWindowResource>().window.isOpen()) {
        world.getResource<RenderWindowResource>().window.clear(sf::Color(0x151123));
        std::sort(Inputs.begin(), Inputs.end(), compareLayer);
        auto layer = [&world](std::shared_ptr<Entity> entityPtr) {
            if (entityPtr->contains<GraphicsRectangleComponent>()) {
                if (world.containsResource<GraphicsTextureResource>()) {
                    entityPtr->getComponent<GraphicsRectangleComponent>().shape.setTexture(
                        world.getResource<GraphicsTextureResource>()
                            ._texturesList[entityPtr->getComponent<TextureName>().textureName]
                            .get());
                } else {
                    entityPtr->getComponent<GraphicsRectangleComponent>().shape.setFillColor(sf::Color::White);
                }
                world.getResource<RenderWindowResource>().window.draw(
                    entityPtr->getComponent<GraphicsRectangleComponent>().shape);
                return;
            }
            if (entityPtr->contains<GraphicsTextComponent>()) {
                world.getResource<RenderWindowResource>().window.draw(
                    entityPtr->getComponent<GraphicsTextComponent>().text);
                return;
            }
            auto layerType = entityPtr->getComponent<LayerLvL>();
            if (layerType.layer == LayerLvL::layer_e::OBSTACLE || layerType.layer == LayerLvL::layer_e::ENEMY
                || layerType.layer == LayerLvL::layer_e::PLAYER || layerType.layer == LayerLvL::layer_e::PROJECTILE ||
                layerType.layer == LayerLvL::EXIT_BUTTON) {
                auto entityPos = entityPtr->getComponent<Position>();
                auto entitySize = entityPtr->getComponent<Size>();

                entityPtr->addComponent<GraphicsRectangleComponent>(
                    entityPos.x, entityPos.y, entitySize.x, entitySize.y);
                if (layerType.layer == LayerLvL::layer_e::PLAYER)
                    entityPtr->addComponent<TextureName>(GraphicsTextureResource::PLAYER_STATIC);
                if (layerType.layer == LayerLvL::layer_e::ENEMY)
                    entityPtr->addComponent<TextureName>(GraphicsTextureResource::ENEMY_STATIC);
                if (layerType.layer == LayerLvL::layer_e::PROJECTILE) {
                    if (entityPtr->contains<EnemyProjectile>()) {
                        entityPtr->addComponent<TextureName>(GraphicsTextureResource::PROJECTILE_ENEMY);
                    }
                    if (entityPtr->contains<AlliedProjectile>()) {
                        entityPtr->addComponent<TextureName>(GraphicsTextureResource::PROJECTILE_ALLY);
                    }
                }
                if (layerType.layer == LayerLvL::EXIT_BUTTON)
                    entityPtr->addComponent<TextureName>(GraphicsTextureResource::EXIT_BUTTON);
            }
        };
        std::for_each(Inputs.begin(), Inputs.end(), layer);
        world.getResource<RenderWindowResource>().window.display();
    }
}
