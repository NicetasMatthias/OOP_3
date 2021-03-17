#ifndef POLINOM_H
#define POLINOM_H

#include <number.h>

class polinom
{
private:
    number a;
    number b;
    number c;
public:
    polinom();
    void set(number a,number b,number c);
    void roots(short &flag, number &x1, number &x2);
    number value(number x);
    std::string standart();
    std::string canon();
};

#endif // POLINOM_H
