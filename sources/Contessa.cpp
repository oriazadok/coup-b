#include "Contessa.hpp"

namespace coup {
    Contessa::Contessa(Game &game, string const &name) 
    : Player(game, name, "Contessa") {
    }
    
    Contessa::~Contessa() {
    }

    int Contessa::block(Player &target) {
        if(target._Laction != assasinate) {
            throw runtime_error("cant block cxcx");
        }
        target._zimbarti->_status = true;
        target._Laction = none;
        
        return 0;
    }
}