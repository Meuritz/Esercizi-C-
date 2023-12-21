#include <string>
#include <iostream>
#include <fstream>
#include "bookshelf.h"
#include "libro.h"
#include <iomanip>

using namespace std;

bookshelf::bookshelf(string nome_file){ //costruttore che prende i dati da un file
    //dichiaro una variabile file chiamata file (sono originale)
    fstream file;
    //apro il file passato al costruttore
    file.open(nome_file, ios::in);
    //controllo che il file sia stato aperto con successo
    if (file.fail() == true){
        cerr << "il file non si apre :(" << nome_file;
        exit(1);
    }
    // ciclo tutti gli elementi del file fino a che non sono finiti
    while (file.eof() == false)
    {
        //dichiaro le variabili che usero per mettere i dati che leggo da file
        string t, a, e, an;
        bool pr;
        //estraggo dal file i dati
        file >> t >> a >> e >> an >> pr;
        //dichiaro una variabile puntatore di tipo oggetto "libro"
        //e creo con "new" un oggetto dinamico 
        libro *p = new libro(t, a, e, an, pr);
        //aggiungo il puntatore p che punta all'oggetto "libro" appena creato al vector "lib_vec"(vector di obj)
        lib_vec.push_back(p);

    }
}
void bookshelf::visualizza_dati() const{
    cout << "Manga in libreria" << endl;

    cout << left << setw(7) << "INDICE" <<
     setw(20) << "TITOLO" <<
     setw(20) << "AUTORE" <<
     setw(10) << "EDITRICE" <<
     setw(10) << "ANNO" <<
     setw(10) << "STATO";
     cout << endl;

    cout << "------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < lib_vec.size(); i++){
        cout << left << setw(7) << i << 
        setw(20) << lib_vec[i]->get_titolo() << 
        setw(20) << lib_vec[i]->get_autore() << 
        setw(10) << lib_vec[i]->get_editrice() << 
        setw(10) << lib_vec[i]->get_anno() <<
        // operatore condizionale per stampare, da booleano a testo
        setw(10) << (lib_vec[i]->get_prestito() ? "Disponibile" : "Non disponibile") << endl;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
}
//visualizza i dati di tutti i libri che contengono la stringa passata nel titolo
void bookshelf::cerca(string ricerca){
    for (int i = 0; i < lib_vec.size(); i++){
        string titolo = lib_vec[i]->get_titolo();
        //cerca la prima occorenza da sx a dx nella stringa se non ce ne seno ritorna npos
        // se ce ne sono stampo tutti i dati del libro in posizione
        if (titolo.find(ricerca) != std::string::npos)
        {   
            cout << left << setw(7) << i << 
            setw(20) << lib_vec[i]->get_titolo() << 
            setw(20) << lib_vec[i]->get_autore() << 
            setw(10) << lib_vec[i]->get_editrice() << 
            setw(10) << lib_vec[i]->get_anno() <<
            setw(10) << lib_vec[i]->get_prestito() << endl;
        }
    }
}
//test

void bookshelf::test(){
    
}
//funzione per prendere in prestito
void bookshelf::borrow(int INDEX){
    //condizione per controllare se il libro è disponibile (get_prestito è bool)
    if (lib_vec[INDEX]->get_prestito())
    {
        //se è disponibile segno che non è più disponibile
        lib_vec[INDEX]->set_prestito();
    }
}
//funzione per restituire
void bookshelf::give_back(int INDEX){
    //condizione per controllare se il libro non è presente (get_prestito è bool)
    if (!lib_vec[INDEX]->get_prestito())
    {
        //se non è disponibile segno che è disponibile
        lib_vec[INDEX]->set_prestito();
    }
}
