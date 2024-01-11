// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "pokemon_card.hpp"


// -- Constructors ------------------------------------------------------------------------------- //

PokemonCard::PokemonCard(const string& _pokemonName,
                        const string& _pokemonType,
                        const string& _familyName, 
                        int _evolutionLevel,
                        int _maxHP,
                        int _energyCost1,
                        const string& _description1,
                        int _damage1,
                        int _energyCost2,
                        const string& _description2,
                        int _damage2
                        ) :
    Card(_pokemonName),
    pokemonType(_pokemonType),
    familyName(_familyName),
    evolutionLevel(_evolutionLevel),
    maxHP(_maxHP),
    hp(_maxHP),
    currentEnergy(0),
    attacks{{_energyCost1, _description1, _damage1}, {_energyCost2, _description2, _damage2}}
{}


// -- Methodes ---------------------------------------------------------------------------------- //

void PokemonCard::displayInfo() const {
    cout << endl << "- Pokemon Name: " << cardName;
    cout << endl << "\tPokemon Type: " << pokemonType;
    cout << endl << "\tFamily Name: " << familyName;
    cout << endl << "\tEvolution Level: " << evolutionLevel;
    cout << endl << "\tMax HP: " << maxHP;
    cout << endl << "\tCurrent HP: " << hp;
    cout << endl << "\tCurrent Energy: " << currentEnergy;

    cout << endl << "\tAttacks:";
    for (const auto& attack : attacks) {
        int energyCost, damage;
        string description;
        tie(energyCost, description, damage) = attack;

        cout << endl << "\t- Description: " << description;
        cout << endl << "\t  Energy Cost: " << energyCost;
        cout << endl << "\t  Damage: " << damage;
    }
}

void PokemonCard::addEnergy() {
    currentEnergy++;
}

void PokemonCard::useEnergy() {
    currentEnergy--;
}

void PokemonCard::takeDamage(int damage) {
    hp -= damage;
}

void PokemonCard::attack(size_t numAttack, PokemonCard& target) {
    int costAttack = get<0>(attacks[numAttack]);
    if (costAttack <= currentEnergy) {
        int damage = get<2>(attacks[numAttack]);
        for (int i = 0; i < costAttack; ++i) useEnergy();
        target.takeDamage(damage);
    } else {
        cout << endl << "l'attaque à échoué";
    }
}

void PokemonCard::takeHealt() {
    hp = maxHP;
}