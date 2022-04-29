#include "Ambassador.hpp"

#include <iostream>
#include <utility>
namespace coup{
    Ambassador::Ambassador(Game &game,  const string& name): Player(game,name) {}
    void Ambassador::block(Player& player){
        vector<string> lastTurn= coup::Ambassador::split(game->lastTurns.at((findIndex(game->playersList, player.name))), ',');
        if(game->playersList.size()<2){
            throw invalid_argument( "\ntoo few players" );
        }
        if(lastTurn.at(0)!="steal"||lastTurn.size()>1|| player.coinsNum<2){
            throw invalid_argument( "\nyou cant block this or it is already blocked");
        }
        player.coinsNum-=2;
        player.effected->coinsNum+=2;

        game->lastTurns.at(findIndex(game->playersList, player.name))="steal,blocked";

    }
    void Ambassador:: transfer(Player& player1,Player& player2){
        if(game->turn()!=name|| this->coinsNum>= this->maxCoins||game->playersList.size()<2|| player1.coinsNum<1){
            throw invalid_argument( "\nit is not your turn" );
        }
        player1.coinsNum--;
        player2.coinsNum++;
        game->lastTurns.at(game->turnNum)="transfer";
        game->turnNum=(game->turnNum+1)%game->playersList.size();

    }

    string Ambassador::role()  {return "Ambassador";}


}