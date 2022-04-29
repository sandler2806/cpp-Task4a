#include "Player.hpp"

namespace coup{
    class Captain : public Player{
    private:
    public:
        Captain(Game &game,const string &name);
        void block(Player& player);
        void steal(Player& player);
        string role() override;


    };
}