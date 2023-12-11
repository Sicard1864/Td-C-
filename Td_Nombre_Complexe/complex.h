// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef COMPLEX_H
#define COMPLEX_H


// -- Macro ------------------------------------------------------------------------------------- //

#include <iostream>
#include <string>
using namespace std;

// -- Class ------------------------------------------------------------------------------------- //

class Complex2D
{
            
    private:
        // attributs
        double r, i;

    public:
        // constructors
        Complex2D();
        Complex2D(double, double);
        Complex2D(double);
        Complex2D(const Complex2D&);
        ~Complex2D();
        
        // accessors
        void setR(double);
        void setI(double);
        void setZ(double, double);
        double getR() const;
        double getI() const;

        // methodes
        double getModulus() const;
        double getArguments() const;
        Complex2D getBar() const;
        Complex2D getInverse() const;
        void Translate(const Complex2D&);
        void Homothety(double);
        void Rotate(double);
        string toString() const;

        // operators
        friend Complex2D operator + (const Complex2D&, const Complex2D&);
        friend Complex2D operator * (const Complex2D&, const Complex2D&);
        friend Complex2D operator - (const Complex2D&, const Complex2D&);
        friend Complex2D operator / (const Complex2D&, const Complex2D&);
        Complex2D& operator = (const Complex2D&);
        friend bool operator > (const Complex2D&, const Complex2D&);
        friend bool operator < (const Complex2D&, const Complex2D&);
        friend bool operator <= (const Complex2D&, const Complex2D&);
        friend bool operator >= (const Complex2D&, const Complex2D&);
        friend bool operator == (const Complex2D&, const Complex2D&);

        // prints
        ostream& printOn(ostream&) const;
        void print() const;
};


// -- END --------------------------------------------------------------------------------------- //

#endif