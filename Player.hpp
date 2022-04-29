
#pragma once
#include <string>
#include "Game.hpp"
#include <algorithm>
#include "sstream"

using namespace std;

namespace coup{
    class Player{
    protected:
            Game* game;
            static vector<string> split (const string &s, char delim);
            static unsigned long findIndex(vector<string> &vec, const string& item);
    public:
        unsigned int coinsNum;
        unsigned const int maxCoins=10;
        string name;
        Player* effected;
        Player(Game &game,const string &name);
//        virtual string role()=0;
        virtual string role(){return "";};
        void income();
        void foreign_aid();
        virtual void coup(const Player &player);
        [[nodiscard]] unsigned int coins() const;


    };

}

