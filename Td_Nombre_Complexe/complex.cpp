// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include <sstream>
#include <cmath>
#include "complex.h"

// -- Constructors ------------------------------------------------------------------------------ //

Complex2D::Complex2D() : r(0), i(0) {}

Complex2D::Complex2D(double _r, double _i) : r(_r), i(_i) {}

Complex2D::Complex2D(double z) : r(z), i(z) {}

Complex2D::Complex2D(const Complex2D& c) : r(c.r), i(c.i) {}

Complex2D::~Complex2D() {};


// -- Accesors and Mutators --------------------------------------------------------------------- //

void Complex2D::setR(double _r) {
    r = _r;
}

void Complex2D::setI(double _i) {
    i = _i;
}

void Complex2D::setZ(double _r, double _i) {
    r = _r;
    i = _i;
}

double Complex2D::getR() const {
    return r;
}

double Complex2D::getI() const {
    return i;
}


// -- Methodes ---------------------------------------------------------------------------------- //

double Complex2D::getModulus() const {
    return sqrt(r*r + i*i);          // sqrt(pow(r, 2) + pow(i, 2))
}

double Complex2D::getArguments() const {
    return atan2(i, r);
}

Complex2D Complex2D::getBar() const {
    return Complex2D(r, -i);
}

Complex2D Complex2D::getInverse() const {
    double a = r / (r*r + i*i);
    double b = -i / (r*r + i*i);
    return Complex2D(a, b);
}

void Complex2D::Translate(const Complex2D& z) {
    r += z.getR();
    i += z.getI();
}

void Complex2D::Homothety(double h) {
    r *= h;
    i *= h;
}

void Complex2D::Rotate(double theta) {
    double x = getModulus();
    double y = getArguments();
    r = x * cos(y + theta);
    i = x * sin(y + theta);
}

string Complex2D::toString() const {
    ostringstream strs;
    strs << r;
    if (i >= 0)
        strs << "+";
    strs << i << "i";
    return strs.str();
}


// -- Operators --------------------------------------------------------------------------------- //

Complex2D operator + (const Complex2D& z1, const Complex2D& z2) {
    double a = z1.r + z2.r;
    double b = z1.i + z2.i;
    return Complex2D(a, b);
}

Complex2D operator - (const Complex2D& z1, const Complex2D& z2) {
    double a = z1.r - z2.r;
    double b = z1.i - z2.i;
    return Complex2D(a, b);
}

Complex2D operator * (const Complex2D& z1, const Complex2D& z2) {
    double a = z1.r * z2.r - z1.i * z2.i;
    double b = z1.r * z2.i + z1.i - z2.r;
    return Complex2D(a, b);
}

Complex2D operator / (const Complex2D& z1, const Complex2D& z2) {
    return z1 * z2.getInverse();
}

Complex2D& Complex2D::operator = (const Complex2D& z) {
    if(&z != this) {
        r=z.r;
        i=z.i;
    }
    return *this;
}

bool operator < (const Complex2D& z1, const Complex2D& z2) {
    return (z1.getModulus() < z2.getModulus());
}

bool operator > (const Complex2D& z1, const Complex2D& z2) {
    return (z1.getModulus() > z2.getModulus());
}

bool operator <= (const Complex2D& z1, const Complex2D& z2) {
    return (z1.getModulus() <= z2.getModulus());
}

bool operator >= (const Complex2D& z1, const Complex2D& z2) {
    return (z1.getModulus() >= z2.getModulus());
}

bool operator == (const Complex2D& z1, const Complex2D& z2) {
    return (z1.getModulus() == z2.getModulus());
}


// -- Prints ------------------------------------------------------------------------------------ //

ostream& Complex2D::printOn(ostream& os) const {
    os << endl << this << " : " << toString();
    return os;
}

void Complex2D::print() const {
    cout << endl <<  this << " : " << toString();
}