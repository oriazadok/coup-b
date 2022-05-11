#pragma once
// #include <iostream>
#include "Game.hpp"
// #ifndef PLAYER_HPP
// #define PLAYER_HPP
#include "Player.hpp"
// #endif

namespace coup {
    class Contessa : public Player {
    public:
        Contessa(Game &game, string const &name);
        ~Contessa();
    
        static int block(Player &target);
    };
    
}