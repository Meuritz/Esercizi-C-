#ifndef LIBRO_H
#define LIBRO_H
#include <string>

using namespace std;

class libro
{
private:
    string titolo, editrice, autore, anno;
    bool prestito;
public:
    libro(){ };

    libro(string, string, string, string, bool);

    string get_titolo()const;

    string get_autore()const;

    string get_editrice()const;

    string get_anno()const;

    bool get_prestito()const;


    void set_prestito();

    ~libro();
};

#endif