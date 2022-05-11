
#include "Captain.hpp"

namespace coup {
    Captain::Captain(Game &game, string const &name) 
    : Player(game, name, "Captain") {
    }
    
    Captain::~Captain() {
    }

    int Captain::block(Player &player) {
        if (player._Laction != ganav) {
            throw runtime_error("cant block hjdhdgh");
        }
        int x = player._zimbarti->_stolenCoins;
        player._numOfCoins -= x;
        player._zimbarti->_numOfCoins += x;
        player._Laction = none;

        return 0;
    }
    
    int Captain::steal(Player &target) {

        if(!this->ismyturn()) {
            throw runtime_error("Not your turneeeeeee");
        }

        if(target._numOfCoins == 0) {
            target._stolenCoins = 0;
            this->_game->_turn++;
        } else if(target._numOfCoins == 1) {
            target._numOfCoins -= 1;
            this->_numOfCoins += 1;
            target._stolenCoins = 1;
            this->_game->_turn++;
        } else {
            target._numOfCoins -= 2;
            this->_numOfCoins += 2;
            target._stolenCoins = 2;
            this->_game->_turn++;
        }
        this->_zimbarti = &target;
        this->_Laction = ganav;
        return 0;
    }
}