
#include "NasNas.h"

#include "example/Game.hpp"

auto main() -> int {

    ns::Res::load("assets");
    ns::Res::printTree();

    ns::Config::Window::vertical_sync = true;
    ns::Config::Window::style = sf::Style::Default;

    Game game;
    game.run();

    ns::Res::dispose();

    return 0;
}
