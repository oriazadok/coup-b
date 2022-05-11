#pragma once
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup {
    class Ambassador : public Player {
        public:
            Ambassador(Game &game, string const &name);
            ~Ambassador();
            
            int transfer(Player &from, Player &to);
            static int block(Player &p);
        };
}