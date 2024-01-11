// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "energy_card.hpp"


// -- Constructors ------------------------------------------------------------------------------ //

EnergyCard::EnergyCard(const string& _energyType) :
    Card("Energy"),
    energyType(_energyType)
{}



// -- Methodes ---------------------------------------------------------------------------------- //

void EnergyCard::displayInfo() const {
    cout << endl << "- Carte Name: " << cardName;
    cout << endl << "\tEnergy Type: " << energyType;
}
