/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** SoundName
*/

#ifndef SOUNDNAME_HPP_
#define SOUNDNAME_HPP_

#include "Component/Component.hpp"
#include "GraphicECS/SFML/Resources/SoundResource.hpp"

namespace ecs
{
    /// @brief SoundName stores the key as enum to the corresponding sound stored in shared resource SoundResource.
    class SoundName : public Component {
      public:
        /// @brief The sound name stores an enum to find which sound it needs in SoundResources shared resource.
        SoundResource::soundName_e soundName;

        /// @brief Constructor of the SoundName component
        /// @param newSoundName The value to set in the soundName, corresponding
        /// on the sf::Sound load in shared resource Sound.
        SoundName(SoundResource::soundName_e newSoundName = SoundResource::UNDEFINED)
            : soundName(newSoundName){};

        /// @brief Default destructor of SoundName component.
        ~SoundName() = default;
    };
} // namespace ecs


#endif /* !SOUNDNAME_HPP_ */
