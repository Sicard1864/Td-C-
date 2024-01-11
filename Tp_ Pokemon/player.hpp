// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "card.hpp"
#include "pokemon_card.hpp"
#include "energy_card.hpp"
#include "trainer_card.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class Player
{
    public:
        Player(const string& _playerName);
        Player(const string& _playerName, const vector<Card*>& _benchCards, 
                const vector<PokemonCard*>& _actionCards);

        void displayBench() const;
        void displayAction() const;
        void displayInfo() const;

        void addCardToBench(Card* card);
        void activatePokemonCard(size_t pokemonInBench);
        void attachEnergyCard(size_t energyInBench, size_t pokemonInAction);
        void attack(size_t myPokemon, size_t numAttack, Player& opponent, size_t opponentPokemon);
        void healt();
        void useTrainer(size_t numTrainer);
        //useTrainer(0)

    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
};


// -- END --------------------------------------------------------------------------------------- //

#endif