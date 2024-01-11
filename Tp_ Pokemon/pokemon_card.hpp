// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef POKEMON_CARD_HPP
#define POKEMON_CARD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "card.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class PokemonCard : public Card
{
    public:
        PokemonCard(const string& _pokemonName,
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
                    );
        void displayInfo() const override;
        void addEnergy();
        void useEnergy();
        void takeDamage(int damage);
        void attack(size_t numAttack, PokemonCard& target);
        void takeHealt();

    private:
        string pokemonType;
        // dark, fire, water, steel, grass, fight, electric, psy
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        int currentEnergy;
        vector<tuple<int, string, int>> attacks;
        // energyCost, description, damage               
};


// -- END --------------------------------------------------------------------------------------- //

#endif