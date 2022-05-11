#include "Game.hpp"
#include "Player.hpp"

const int maxPlayers = 6;

namespace coup {
    Game::Game() {
        this->_start = false;
        this->_turn = 0;
    }
    
    Game::~Game() {
    }

    int Game::startGame() {
        this->_start = true;
        return 0;
    }

    string Game::turn() {
        while(true) {
            size_t i = (size_t)this->_turn % this->_players.size();
            if(!this->_players.at(i)->_status) {
                this->_turn++;
            } else {
                return this->_players.at(i)->_name;
            }
        }
    }

    vector<string> Game::players() {
        vector<string> ans;
        for(size_t i=0; i < _players.size(); i++) {
            if (this->_players.at(i)->_status) {
                ans.push_back(this->_players.at(i)->_name);
            }
            
        }
        return ans;
    }
    
    string Game::winner() {
        if(!this->_start) {
            throw runtime_error("ma nihya");
        }
        if(this->players().size() > 1) {
            throw runtime_error("tambal");
        }
        if(this->players().size() == 1) {
            this->_winner = this->players().at(0);
        }
        return this->_winner;
    }

    int Game::addPlayer(Player &player) {
        if(this->_players.size() >= maxPlayers) {
            throw runtime_error("Too Many players");
        }
        this->_players.push_back(&player);
        return 0;
    }


}