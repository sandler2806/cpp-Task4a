#include "Duke.hpp"

#include <iostream>
namespace coup{
    Duke::Duke(Game &game,  const string& name): Player(game,name) {}

    void Duke::tax(){
        if(game->turn()!=name|| this->coinsNum>= this->maxCoins||game->playersList.size()<2){
            throw invalid_argument( "\nit is not your turn" );
        }
        coinsNum+=3;
        game->lastTurns.at(game->turnNum)="tax";
        game->turnNum=(game->turnNum+1)%game->playersList.size();
    }
    void Duke::block(Player& player){
        vector<string> lastTurn= coup::Duke::split(game->lastTurns.at((findIndex(game->playersList, player.name))), ',');
        if(game->playersList.size()<2){
            throw invalid_argument( "\ntoo few players" );
        }
        if(lastTurn.at(0)!="foreign_aid"||lastTurn.size()>1|| player.coinsNum<2){
            throw invalid_argument( "\nyou cant block this or it is already blocked");
        }
        player.coinsNum-=2;
        game->lastTurns.at(findIndex(game->playersList, player.name))="foreign_aid,blocked";
    }
    string Duke::role()  {return "Duke";}

}