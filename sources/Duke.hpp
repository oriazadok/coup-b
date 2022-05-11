#pragma once
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup {
    class Duke : public Player {
        public:
            Duke(Game &game, string const &name);
            ~Duke();

            static int block(Player &player);
            int tax();
        };
}

