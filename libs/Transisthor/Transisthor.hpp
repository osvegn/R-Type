/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Transisthor
*/

/// @file libs/Transisthor/Transisthor.hpp

#ifndef TRANSISTHOR_HPP_
#define TRANSISTHOR_HPP_

#include "Communicator/Communicator.hpp"
#include "World/World.hpp"

using namespace ecs;
using namespace communicator_lib;

namespace transisthor_lib
{
    /// @brief Bridge between Communicator data and ECS data
    class Transisthor {
      public:
        /// @brief Construct a new Transisthor object
        /// @param communicator A reference to a working communicator
        /// @param ecsWorld A reference to a working ecs
        Transisthor(Communicator &communicator, World &ecsWorld);

        /// @brief Destroy a Transisthor object (Default value)
        ~Transisthor() = default;

        /// @brief Function called by the Communicator. The transfered data will be converted to an ECS object and send
        /// to the ecs.
        /// @param networkData Content of the network data (Refer to communicator lib document for more details)
        /// @return Return value will be removed when transitor have been finished.
        void *transitNetworkDataToEcsData(Message networkData);

        /// @brief Function called by the ECS. The transfered data will be converted to a Network object and send to the
        /// communicator.
        /// @tparam C Type of the component
        /// @param id Id of the transfered component
        /// @param type Type id of the component
        /// @param component The transfered component
        /// @return Return value will be removed when transitor have been finished.
        template <std::derived_from<Component> C>
        void *transitEcsDataToNetworkData(unsigned short id, unsigned short type, C component)
        {
            void *networkObject = std::malloc(sizeof(void *) * ((sizeof(C)) + sizeof(unsigned short) * 2));

            if (networkObject == nullptr)
                throw std::system_error();
            std::memcpy(networkObject, &id, sizeof(unsigned short));
            std::memcpy((void *)((char *)networkObject + sizeof(unsigned short)), &type, sizeof(unsigned short));
            std::memcpy((void *)((char *)networkObject + sizeof(unsigned short) * 2), &component, sizeof(C));
            /// CALL NETWORK FUNCTION FOR SENDING
            return networkObject;
        }

        /// @brief Function called by the ECS. The transfered data will be converted to a Network object and send to the
        /// communicator.
        /// @tparam C Type of the resource
        /// @param id Id of the transfered resource
        /// @param type Type id of the resource
        /// @param resource The transfered resource
        template <std::derived_from<Resource> C>
        void transitEcsDataToNetworkData(unsigned short id, unsigned short type, C component)
        {
            (void)id;
            (void)component;
            (void)type;
        }

        /// @brief Function called by the ECS. The transfered data will be converted to a Network object and send to the
        /// communicator.
        /// @tparam ...Args This allow to send multiple Component (Used for an entity)
        /// @tparam C Type of the component
        /// @param id Id of the transfered entity
        /// @param type Type id of the transfered entity
        /// @param ...args All components used inside the wanted entity.
        template <std::derived_from<Component>... C>
        void transitEcsDataToNetworkData(unsigned short id, unsigned short type, C &&...args)
        {
            (void)id;
            (void)type;
        }

      private:
        /// @brief A reference to a communicator
        Communicator &_communicator;

        /// @brief A reference to a Ecs World
        World &_ecsWorld;

        /// @brief Convert a byteCode data into a Position component and send it to the ECS
        /// @param id Entity ID attached to the component
        /// @param byteCode byte value of the Position component
        void componentConvertPositionType(unsigned short id, void *byteCode);

        /// @brief List of all the Convert function for Component. Ordered by the component type value (Refer to RFC for
        /// more informations)
        std::map<unsigned short, std::function<void(unsigned short, void *)>> _componentConvertFunctionList;
    };
} // namespace transisthor_lib

#endif /* !TRANSISTHOR_HPP_ */
