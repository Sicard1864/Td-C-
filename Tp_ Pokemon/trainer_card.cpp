// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "trainer_card.hpp"


// -- Constructors ------------------------------------------------------------------------------ //

TrainerCard::TrainerCard(const string& _trainerName, const string& _trainerEffect) :
    Card(_trainerName),
    trainerEffect(_trainerEffect)
{}



// -- Methodes ---------------------------------------------------------------------------------- //

void TrainerCard::displayInfo() const {
    cout << endl << "- Carte Name: " << cardName;
    cout << endl << "\tEffect: " << trainerEffect;
}

string TrainerCard::use() {
    return "Brock";
}