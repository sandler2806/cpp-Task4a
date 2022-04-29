#include "Player.hpp"

namespace coup{
    class Contessa : public Player{
    private:
    public:
        Contessa(Game &game, const string& name);
        void block(Player& player);
        string role() override;


    };
}