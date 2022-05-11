#pragma once
#include <iostream>
#include <vector>
#include "Player.hpp"

using namespace std;

namespace coup {
    class Player;
    class Game {
        public:
            bool _start;
            int _turn;
            vector<Player*> _players;
            string _winner;
        public:
            Game();
            ~Game();

            int startGame();
            string turn();
            vector<string> players();
            string winner();

            int addPlayer(Player &player);
            
    };
    
}