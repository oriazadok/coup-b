#include "Assassin.hpp"

namespace coup {
    const int coupable = 7;

    Assassin::Assassin(Game &game, string const &name) 
    : Player(game, name, "Assassin") {

    }
    
    Assassin::~Assassin() {
    }

    int Assassin::coup(Player &player) {
        if(this->_numOfCoins < 3) {
            throw runtime_error("no money");
        }
        if(!player._status) {
            throw runtime_error("hu met capara");
        }
        if(this->_numOfCoins >= coupable) {
            player._status = false;
            this->_numOfCoins -= coupable;
            this->_Laction = dead;
            this->_zimbarti = &player;
        } else {
            player._status = false;
            this->_Laction = assasinate;
            this->_zimbarti = &player;
            this->_numOfCoins -= 3;
        }
        
        this->_game->_turn++;
        return 0;
    }
    
}