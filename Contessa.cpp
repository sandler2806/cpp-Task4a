#include "Contessa.hpp"

namespace coup{
    Contessa::Contessa(Game &game,  const string& name): Player(game,name) {}
    void Contessa::block(Player& player){
        vector<string> lastTurn= coup::Contessa::split(game->lastTurns.at(
                static_cast<unsigned long>(findIndex(game->playersList, player.name))), ',');
        if(game->playersList.size()<2){
            throw invalid_argument( "\ntoo few players" );
        }

        if(lastTurn.at(0)!="coup"||player.role()!="Assassin"||lastTurn.size()>4){
            throw invalid_argument( "\nyou cant block this or it is already blocked");
        }

        game->lastTurns.insert ( game->lastTurns.begin()+ stoi(lastTurn[2]) , lastTurn[3] );
        game->playersList.insert ( game->playersList.begin()+ stoi(lastTurn[2]) , lastTurn[1] );


        game->lastTurns.at(findIndex(game->playersList, player.name))="coup,"+lastTurn[1]+","+lastTurn[2]+","+lastTurn[3]+",blocked";
    }
    string Contessa::role()  {return "Contessa";}


}