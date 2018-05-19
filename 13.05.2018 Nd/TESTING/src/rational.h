#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational{
    int m_numerator;
    int m_denominator;
public:
    Rational(int num, int denom = 1): m_numerator(num), m_denominator(denom){}

    int num() const {return m_numerator;}
    int denom() const {return m_denominator;}

    Rational& operator += (Rational a){
        //modyfikacja
        return *this;
    }

    //Rational operator + (const Rational r) const;
};

inline bool operator == (Rational a, Rational b);
inline bool operator != (Rational a, Rational b);
inline bool operator < (Rational a, Rational b);
inline bool operator <= (Rational a, Rational b);
inline bool operator >= (Rational a, Rational b);

inline Rational operator - (Rational a, Rational b) {}

inline Rational operator + (Rational a, Rational b) {}

std::ostream& operator << (std::ostream& os, Rational a){
    os << a.num() << "/" << a.denom() << "\n";
}

#endif // RATIONAL_H
