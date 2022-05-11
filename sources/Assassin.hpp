#pragma once
#include <iostream>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;
using namespace coup;



namespace coup {
    class Assassin : public Player {
        public:
            Assassin(Game &game, string const &name);
            ~Assassin();

            int coup(Player &player);
    };
    
}