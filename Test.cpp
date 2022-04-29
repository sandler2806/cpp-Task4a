#include "doctest.h"
#include "Player.hpp"
#include <string>

#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"

#include <vector>
using namespace coup;
using namespace std;


TEST_CASE("valid input") {

    Game game_1{};
    Duke duke(game_1, "Moshe");
    CHECK_THROWS(duke.income());
    CHECK_THROWS(duke.tax());

    CHECK_NOTHROW(Duke duke2(game_1, "Moshe"));
    CHECK_NOTHROW(Assassin assassin(game_1, "Yossi"));
    CHECK_NOTHROW(Ambassador ambassador(game_1, "Meirav"));
    CHECK_NOTHROW(Captain captain(game_1, "Reut"));
    CHECK_NOTHROW(Contessa contessa(game_1, "Gilad"));
    CHECK_THROWS(Contessa contessa2(game_1, "Gilad2"));
    CHECK_NOTHROW(duke.income());
    CHECK_THROWS(Contessa contessa(game_1, "Gilad2"));



    Game game_2{};
    Duke duke2{game_2, "Moshe"};
    Assassin assassin{game_2, "Yossi"};
    Ambassador ambassador{game_2, "Meirav"};
    Captain captain{game_2, "Reut"};
    Contessa contessa{game_2, "Gilad"};

    vector<string> players = game_2.players();

            CHECK_THROWS(assassin.income());
            CHECK_NOTHROW(duke2.income());
            CHECK_NOTHROW(assassin.foreign_aid());
            CHECK_THROWS(ambassador.block(assassin));
            CHECK_NOTHROW(duke2.block(assassin));
            CHECK_THROWS(ambassador.coup(assassin));
            CHECK_NOTHROW(ambassador.transfer(duke2,captain));
            CHECK_THROWS(captain.steal(duke2));
            CHECK_NOTHROW(captain.foreign_aid());
            CHECK_NOTHROW(contessa.income());










}
