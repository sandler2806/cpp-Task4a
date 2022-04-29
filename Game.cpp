#include "Game.hpp"


namespace coup
{
//    Game::Game() : {}
    string Game::turn() {return playersList.at(turnNum);}
    vector<string> Game::players() const {return playersList;}
    string Game::winner() {
        if(playersList.size()==1){
            return playersList.at(0);
        }
        throw invalid_argument( "\nThere isn't a winner" );
    }




};