#pragma once
#include "Game.hpp"
// #ifndef PLAYER_HPP
// #define PLAYER_HPP
#include "Player.hpp"
// #endif


namespace coup {
    class Captain : public Player {
    public:
        Captain(Game &game, string const &name);
        ~Captain();

        
        static int block(Player &player);
        int steal(Player &target);
    };
}