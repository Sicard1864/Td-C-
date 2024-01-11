// ---------------------------------------------------------------------------------------------- //
//  Arthur SICARD - 2A IR Alt
//
//      g++ -std=c++17 -Wall -Wextra -Werror *.cpp -o prog && ./prog
//
//
// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <string>

#include "player.hpp"
#include "card.hpp"
#include "pokemon_card.hpp"
#include "energy_card.hpp"
#include "trainer_card.hpp"

using namespace std;


// -- Main -------------------------------------------------------------------------------------- //

int main()
{
    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pichu", 2, 100, 2, "Thunder Bolt", 20, 3, "Thunder Storm", 30));
    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);
    player1.displayInfo();

    cout << endl;
    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "Leech Seed", 15, 3, "Vine Whip", 25));
    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);
    player2.displayInfo();
    player1.attack(0, 0, player2, 0);
    cout << endl;
    player2.displayAction();
    cout << endl;
    player1.displayAction();
    player2.useTrainer(0);
    cout << endl;
    player2.displayAction();

    cout << endl << endl;
    return 0;
}