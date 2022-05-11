#pragma once
#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

namespace coup {
    enum Laction{
            take1 = 0, 
            take2 = 1, 
            ganav = 2,
            assasinate = 3,
            dead = 4,
            none = -1
        };
    class Game;
    class Player {
        public:
            Game* _game;
            int _numOfCoins;
            string _name;
            string _role;
            bool _status;
            
            Laction _Laction;
            int _stolenCoins;
            Player* _zimbarti;


        public:
            Player(Game &game, string const &name, string const &role);
            ~Player();

            bool ismyturn() const;

            int income();
            int foreign_aid();
            virtual int coup(Player &player);

            string role() const;
            int coins() const;
        };
}