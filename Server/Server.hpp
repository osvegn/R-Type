/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Server
*/

/// @file Server/Server.hpp

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <vector>
#include "Communicator/Client.hpp"
#include "Communicator/Communicator.hpp"
#include "Room.hpp"

using namespace communicator_lib;

namespace server_data
{
    /// @brief Main class of the server part. Hold room process.
    class Server {
      public:
        /// @brief All the possible state of a room
        enum HubState { UNDEFINED, HUB, ENDED };

        /// @brief Construct a new server object
        /// @param address Ip address of the server
        /// @param port Listening port for network process
        Server(std::string address, unsigned short port);

        /// @brief Construct a new server object with default value
        Server();

        /// @brief Destroy the Server object
        ~Server() = default;

        /// @brief Create and add a new Room inside the room list
        /// @param name of the room
        /// @return Id of the newly created room
        unsigned short createANewRoom(std::string name);

        /// @brief Start the hub global loop
        void startHubLoop();

        /// @brief Remove and delete a room of the list
        /// @param id of the room to be deleted
        void deleteARoom(unsigned short id);

      private:
        /// @brief Current state of the server
        HubState _state;

        /// @brief List of all the active room.
        std::vector<Room> _activeRoomList;

        /// @brief Network information of the server. Setup at the construction
        Client _networkInformations;

        /// @brief Instance of the communicator library
        std::shared_ptr<Communicator> _communicatorInstance;

        /// @brief Start the connexion protocol and ask the server for a place inside the room
        void _startConnexionProtocol();

        /// @brief Handle a connection request. Send all rooms informations (id + name) to the client.
        /// @param connectionDemand actual message data
        void _holdANewConnectionRequest(CommunicatorMessage connectionDemand);

        /// @brief Handle a disconnection request. Send a protocol 13.
        /// @param connectionDemand actual message data
        void _holdADisconnectionRequest(CommunicatorMessage disconnectionDemand);

        /// @brief Send to all clients the disconnection signal
        void _disconnectionProcess();
    };
} // namespace server_data

#endif /* !SERVER_HPP_ */
