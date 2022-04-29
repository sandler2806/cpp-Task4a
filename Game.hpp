
#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
namespace coup{

    class Game{
//        string name;
    public:
        vector<string> playersList;
        vector<string> lastTurns;
        unsigned int turnNum=0;
//        Game();
        string turn();
        [[nodiscard]] vector<string> players() const;
        string winner();



    };

}
