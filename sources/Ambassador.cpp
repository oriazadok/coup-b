#include "Ambassador.hpp"
    
namespace coup {
    Ambassador::Ambassador(Game &game, string const &name) 
    : Player(game, name, "Ambassador") {
    }

    Ambassador::~Ambassador() {
        
    }

    int Ambassador::transfer(Player &from, Player &to) {
        if(from._numOfCoins == 0) {
            throw runtime_error("roknu oti hakakot");
        }
        from._numOfCoins -= 1;
        to._numOfCoins += 1;
        this->_Laction = none;
        this->_game->_turn++;
        return 0;
    }

    int Ambassador::block(Player &player) {
        if (player._Laction != ganav) {
            throw runtime_error("cant block hjdhdgh");
        }
        int x = player._zimbarti->_stolenCoins;
        player._numOfCoins -= x;
        player._zimbarti->_numOfCoins += x;
        player._Laction = none;
        return 0;
    }
}   
