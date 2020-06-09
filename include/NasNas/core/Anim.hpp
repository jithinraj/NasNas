/**
* Created by Modar Nasser on 25/04/2020.
**/

#pragma once

#include "SFML/Graphics.hpp"
#include "NasNas/data/Rect.hpp"
#include <vector>

namespace ns {

    class AnimFrame {
    public:
        AnimFrame(const IntRect& rectangle, int duration, const sf::Vector2i& origin={0, 0});
        const IntRect rectangle;
        const int duration;
        const sf::Vector2i origin;
    };

    class Anim {
    public:
        Anim();
        Anim(const std::string& name, std::vector<AnimFrame> frames, bool loop=true);
        void add(const AnimFrame& frame);
        auto getName() -> const std::string&;
        auto getFrame(int index) -> const AnimFrame&;
        auto frameCount() -> int;

        bool loop = true;

    private:
        std::string m_name;
        std::vector<AnimFrame> m_frames;
    };

}
