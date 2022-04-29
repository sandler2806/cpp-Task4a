#include "Captain.hpp"

#include <iostream>
namespace coup{
    Captain::Captain(Game &game,  const string& name): Player(game,name) {}
    void Captain::block(Player& player){
        vector<string> lastTurn= coup::Captain::split(game->lastTurns.at((findIndex(game->playersList, player.name))), ',');
        if(game->playersList.size()<2){
            throw invalid_argument( "\ntoo few players" );
        }

        if(lastTurn.at(0)!="steal"||lastTurn.size()>1){
            throw invalid_argument( "\nyou cant block this or it is already blocked");
        }

        player.coinsNum-=2;
        player.effected->coinsNum+=2;

        game->lastTurns.at(findIndex(game->playersList, player.name))="steal,blocked";

    }
    void Captain:: steal(Player& player){
        if(game->turn()!=name|| this->coinsNum>= this->maxCoins||game->playersList.size()<2|| player.coinsNum<2){
            throw invalid_argument( "\nit is not your turn" );
        }
        player.coinsNum-=2;
        this->coinsNum+=2;
        this->effected=&player;
        game->lastTurns.at(game->turnNum)="steal,";
        game->turnNum=(game->turnNum+1)%game->playersList.size();
    }
    string Captain::role()  {return "Captain";}


}