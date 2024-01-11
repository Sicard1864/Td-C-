// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef TRAINER_CARD_HPP
#define TRAINER_CARD_HPP

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class TrainerCard : public Card
{
    public:
        TrainerCard(const string& _trainerName, const string& _trainerEffect);
        void displayInfo() const override;
        string use();

    private:
        string trainerEffect;
};


// -- END --------------------------------------------------------------------------------------- //

#endif