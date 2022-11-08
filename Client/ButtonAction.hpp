/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** ButtonAction
*/

#ifndef BUTTONACTION_HPP_
#define BUTTONACTION_HPP_

#include "World/World.hpp"

/// @brief Exit the windows by disconecting the client
/// @param world the world where the window will be closed
/// @param entityPtr the entity who actioned the called
void exitWindow(World &world, Entity &entityPtr);

/// @brief Pause the game, changing the menu state resource
/// @param world the world where the game will be paused
/// @param entityPtr the entity who actioned the called
void pauseGame(World &world, Entity &entityPtr);

/// @brief Resume the game, changing the menu state resource
/// @param world the world where the game will be resumed
/// @param entityPtr the entity whoe's actioned the called
void resumeGame(World &world, Entity &entityPtr);

/// @brief Select a writable entity, add / remove a selected component
/// @param world the world where the entity is
/// @param entityPtr the entity who actioned the called
void selectAWritable(World &world, Entity &entityPtr);

/// @brief Get the content of associated writable entity and called the action function
/// @param world the world where the entity is
/// @param entityPtr the entity who actioned the called
void writableButtonAction(World &world, Entity &entityPtr);

/// @brief publish a new message in the room chat
/// @param world the world where the entity is
/// @param entityPtr the entity who actioned the called
/// @param message message to send
void publishNewChatMessage(World &world, Entity &entityPtr, std::string &message);

/// @brief It sends a room configuration to the server, and then changes the menu state to
/// the lobby menu
/// @param world The world that contains the entity.
/// @param entityPtr The entity that is calling the function.
/// @return A function pointer.
void connectToARoom(World &world, Entity &entityPtr);

void launchSoloGame(World &world, Entity &entityPtr);

#endif /* !BUTTONACTION_HPP_ */
