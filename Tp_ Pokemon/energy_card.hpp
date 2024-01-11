// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef ENERGY_CARD_HPP
#define ENERGY_CARD_HPP

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class EnergyCard : public Card
{
    public:
        EnergyCard(const string& _energyType);
        void displayInfo() const override;

    private:
        string energyType;
};


// -- END --------------------------------------------------------------------------------------- //

#endif