#include "Player.hpp"



namespace coup
{
    const int conisToCoup=7;
    const int maxPlayers=6;

    Player::Player(Game &game,const string  &name) : name(name) ,coinsNum(0),effected(nullptr) {
        this->game=&game;
        if(game.playersList.size()>=maxPlayers){
            throw invalid_argument( "\ntoo many players" );
        }
        game.playersList.push_back(name);
        game.lastTurns.emplace_back("");
    }

    void Player::income() {
        if(game->turn()!=name|| this->coinsNum>= this->maxCoins||game->playersList.size()<2){
            throw invalid_argument( "\nit is not your turn" );
        }
        coinsNum++;
        game->lastTurns.at(game->turnNum)="income";
        game->turnNum=(game->turnNum+1)%game->playersList.size();

    }
    void Player::foreign_aid() {
        if(game->turn()!=name|| this->coinsNum>= this->maxCoins||game->playersList.size()<2){
            throw invalid_argument( "\nit is not your turn" );
        }
        coinsNum+=2;
        game->lastTurns.at(game->turnNum)="foreign_aid";
        game->turnNum=(game->turnNum+1)%game->playersList.size();
    }

    void Player::coup(const Player &player) {
        if(game->turn()!=name){
            throw invalid_argument( "\nit is not your turn" );
        }
        if (coinsNum<conisToCoup){
            throw invalid_argument( "\nyou dont have enough coins" );
        }
        if (count(game->playersList.begin(), game->playersList.end(), player.name)!=0){
            game->lastTurns.at(game->turnNum)="coup,"+player.name;
            game->playersList.erase(std::remove(game->playersList.begin(), game->playersList.end(), player.name), game->playersList.end());
            game->lastTurns.erase(game->lastTurns.begin() + int(findIndex(game->playersList, player.name)));
            if (game->turnNum>game->playersList.size() ||game->turn()!=name){//if im the last player or bigger than the erased player
                game->turnNum=(game->turnNum)%game->playersList.size();
            }
            else{
                game->turnNum=(game->turnNum+1)%game->playersList.size();
            }
            this->coinsNum-=conisToCoup;
        } else{
            throw invalid_argument( "\nthe player does not exist" );
        }
    }
    unsigned int Player::coins() const {return coinsNum; }

    vector<string> Player::split (const string &s, char delim) {
        vector<string> result;
        stringstream ss (s);
        string item;

        while (getline (ss, item, delim)) {
            result.push_back (item);
        }

        return result;
    }
    unsigned long Player::findIndex(vector<string> &vec, const string& item) {
        const int notFound=100;
        std::vector<string>::iterator it;
        it = find (vec.begin(), vec.end(), item);
        if (it != vec.end())
        {
            return static_cast<unsigned long>(int(it - vec.begin()));
        }
        return notFound;

    }

};