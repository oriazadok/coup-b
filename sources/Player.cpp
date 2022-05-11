#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace coup {

    const int max_coins = 10;
    const int coupable = 7;
    
    Player::Player(Game &game, string const &name, string const &role) 
    : _numOfCoins(0), _name(name), _role(role) {
        
        this->_game = &game;
        this->_status = true;
        this->_game->addPlayer(*this);
        this->_Laction = none;
        this->_stolenCoins = 0;
        this->_zimbarti = NULL;
        if(this->_game->_start) {
            throw runtime_error("capara kvar hethalnu");
        }
       
    }
    
    Player::~Player() {
    }

    bool Player::ismyturn() const {
        string t = this->_game->turn();
        return t == this->_name;
    }

    int Player::income() {
        if(this->_game->_players.size() < 2) {
            throw runtime_error("lama ata mathil levad yamanyak");
        }

        if(!this->ismyturn()) {
            throw runtime_error("Not your turn");
        }
        if(this->_numOfCoins >= max_coins) {
            throw runtime_error("yabunker");
        }
        this->_game->startGame();
        this->_numOfCoins++;
        this->_Laction = take1;
        this->_game->_turn++;

        return 0;
    }

    int Player::foreign_aid() {

        if(this->_game->_players.size() < 2) {
            throw runtime_error("lama ata mathil levad yamanyak");
        }

        if(!this->ismyturn()) {
            throw runtime_error("Not your turn");
        }
        if(this->_numOfCoins >= max_coins) {
            throw runtime_error("yabunker");
        }
        this->_game->startGame();

        this->_numOfCoins += 2;

        this->_Laction = take2;

        this->_game->_turn++;

        return 0;
    }
    
    int Player::coup(Player &player) {
        
        if(!this->ismyturn()) {
            throw runtime_error("Not your turn");
        }
        if(!player._status) {
            throw runtime_error("hu met capara");
        }
        if(this->_numOfCoins < coupable) {
            throw runtime_error("no money");
        }

        this->_game->startGame();

        this->_numOfCoins -= coupable;

        player._status = false;
        this->_Laction = dead;
        this->_zimbarti = &player;

        this->_game->_turn++;
        return 0;
    }
    
    
    string Player::role() const {
        return this->_role;
    }

    int Player::coins() const {
        return this->_numOfCoins;
    }

    


}