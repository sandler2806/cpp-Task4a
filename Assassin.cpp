#include "Assassin.hpp"

#include <iostream>
#include <utility>
namespace coup{
    const int conisToCoup=7;
    Assassin::Assassin(Game &game,  const string& name): Player(game,name) {}
    string Assassin::role()  {return "Assassin";}
    void Assassin:: coup(const Player &player){

        if(game->turn()!=name){
            throw invalid_argument( "\nit is not your turn" );
        }
        if (coinsNum<3){
            throw invalid_argument( "\nyou dont have enough coins");
        }

        if (count(game->playersList.begin(), game->playersList.end(), player.name)!=0){
            unsigned long index=findIndex(game->playersList, player.name);
            if(coinsNum>=conisToCoup){
                game->lastTurns.at(game->turnNum)="coup,"+player.name+","+ to_string(index)+","+game->lastTurns.at(index)+",blocked";
                this->coinsNum-=conisToCoup;
            }
            else{
                game->lastTurns.at(game->turnNum)="coup,"+player.name+","+ to_string(index)+","+game->lastTurns.at(index);
                this->coinsNum-=3;
            }
            game->playersList.erase(std::remove(game->playersList.begin(), game->playersList.end(), player.name), game->playersList.end());
            game->lastTurns.erase(game->lastTurns.begin() + int(index));

            if (game->turnNum>game->playersList.size() ||game->turn()!=name){//if im the last player or bigger than the erased player
                game->turnNum=(game->turnNum)%game->playersList.size();
            }
            else{
                game->turnNum=(game->turnNum+1)%game->playersList.size();
            }
        } else{
            throw invalid_argument( "\nthe player does not exist" );
        }
    }



}