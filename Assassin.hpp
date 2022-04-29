#include "Player.hpp"

namespace coup{
    class Assassin : public Player{
    private:
    public:
        Assassin(Game &game,const string &name);
        string role() override;
        void coup(const Player& player) override;


    };
}