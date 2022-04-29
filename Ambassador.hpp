#include "Player.hpp"

namespace coup{
    class Ambassador : public Player{
    private:
    public:
        Ambassador(Game &game,const string &name);
        void block(Player& player);
        void transfer(Player& player1,Player& player2);
        string role() override;

    };
}