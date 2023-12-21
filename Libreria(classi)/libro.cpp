#include <string>
#include <iostream>
#include "libro.h"

using namespace std;

libro::libro(string a, string b, string c, string d, bool e){
    titolo = a;
    autore = b;
    editrice = c;
    anno = d;
    prestito = e;
}

string libro::get_titolo()const{
    return titolo;
}
string libro::get_autore()const{
    return autore;
}
string libro::get_editrice()const{
    return editrice;
}
string libro::get_anno()const{
    return anno;
}
bool libro::get_prestito()const{
    return prestito;
}
void libro::set_prestito(){
    prestito = !prestito;
}