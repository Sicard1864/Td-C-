// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include <iostream>
#include <string>
#include <vector>

#include "player.hpp"
#include "card.hpp"
#include "pokemon_card.hpp"
#include "energy_card.hpp"
#include "trainer_card.hpp"


// -- Constructors ------------------------------------------------------------------------------ //

Player::Player(const string& _playerName) :
    playerName(_playerName),
    benchCards(),
    actionCards()
{}

Player::Player(const string& _playerName, const vector<Card*>& _benchCards, 
                const vector<PokemonCard*>& _actionCards) :
    playerName(_playerName),
    benchCards(_benchCards),
    actionCards(_actionCards)
{}


// -- Display ----------------------------------------------------------------------------------- //

void Player::displayBench() const {
    cout << endl << "Display of Bench Cards:";
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
 }

 void Player::displayAction() const {
    cout << endl << "Display of Action Cards:";
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
 }

void Player::displayInfo() const {
    cout << endl << "\tPlayer Name: " << playerName;
    Player::displayBench();
    Player::displayAction();
 }


// -- Methodes ---------------------------------------------------------------------------------- //

 void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
    //cout << endl << "Added Card to Bench.";
 }

void Player::activatePokemonCard(size_t pokemonInBench) {
    PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[pokemonInBench]);
    if (pokemonCard) {
        actionCards.push_back(pokemonCard);
        benchCards.erase(benchCards.begin() + pokemonInBench);
        //cout << endl << "Activated PokemonCard and moved to Action.";    
    }
}

void Player::attachEnergyCard(size_t energyInBench, size_t pokemonInAction) {
    if (energyInBench < benchCards.size() && pokemonInAction < actionCards.size()) {

        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyInBench]);
        if (energyCard) {
            actionCards[pokemonInAction]->addEnergy();
            benchCards.erase(benchCards.begin() + energyInBench);
            //cout << "Attached EnergyCard to Pokemon in Action." << endl;
        }
    }
}

void Player::attack(size_t myPokemon, size_t numAttack, Player& opponent, size_t opponentPokemon) {
    actionCards[myPokemon]->attack(numAttack, *(opponent.actionCards[opponentPokemon]));
}

void Player::healt() {
    for (auto pokemon : actionCards) {
        pokemon->takeHealt();
    }
    
}

void Player::useTrainer(size_t numTrainer) {
    if (numTrainer < benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[numTrainer]);
        if (trainerCard) {
            if (trainerCard->use() == "Brock") {
                healt();
            } else {
                std::cout << "non-Brock trainer card";
            }
            benchCards.erase(benchCards.begin() + numTrainer);
        }
    }
}