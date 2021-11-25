#include "function.h"
using namespace std;

Dish::~Dish()
{
    delete food;
}

void IdiotSandwich::print(std::ostream &out)
{
    out << "An idiot sandwich with intelligence level " << this->intelligence << " only.";
}

void NormalSandwich::print(std::ostream &out)
{
    out << this->name << ". Masterpiece of sandwiches.";
}

std::istream & operator >> (std::istream &in, Dish &d)
{
    string s;
    int l;
    in >> s;
    if(s.compare("Ramsay")==0)
    {
        in >> l;
        d.food = new IdiotSandwich(l);
    }
    else
    {
        d.food = new NormalSandwich(s);
    }
    return in;
}
