#ifndef BOOKSHELF_H
#define BOOKSHELF_H
#include <vector>
#include <string>
#include "libro.h"
using namespace std;

class bookshelf
{
private:
    vector<libro*> lib_vec;
public:
    bookshelf();

    bookshelf(string);

    void visualizza_dati() const;

    void cerca(string);

    void test();
    
    void borrow(int);

    void give_back(int);
};

#endif