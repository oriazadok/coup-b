#include "Duke.hpp"

namespace coup {
    const int max_coins = 10;

    Duke::Duke(Game &game, string const &name) 
    : Player(game, name, "Duke") {
    }
    
    Duke::~Duke() {
    }

    int Duke::block(Player &player) {
        if (player._Laction != take2) {
            throw runtime_error("cant block");
        }

        player._numOfCoins -= 2;
        player._Laction = none;
        return 0;
    }
    
    int Duke::tax() {
        if(this->_numOfCoins >= max_coins) {
            throw runtime_error("yabunker");
        }
        this->_numOfCoins += 3;
        this->_Laction = none;
        this->_game->_turn++;
        
        return 0;
    }

}