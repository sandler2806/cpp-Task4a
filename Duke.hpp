#include "Player.hpp"

namespace coup{
    class Duke : public Player{
    private:
    public:
        Duke(Game &game, const string& name);
        void block(Player& player);
        void tax();
        string role() override;


    };
}