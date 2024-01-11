// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

using namespace std;


// -- Class ------------------------------------------------------------------------------------- //

class Card 
{
    public:
        // Constructeur
        Card(const string& name);

        // Fonction virtuelle pure
        virtual void displayInfo() const = 0;

    protected:
        string cardName;
};


// -- END --------------------------------------------------------------------------------------- //

#endif