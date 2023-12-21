#include "libro.h"
#include "bookshelf.h"

using namespace std;
int main() {
    bookshelf lib("archivio.txt");
    lib.visualizza_dati();
    lib.cerca(" ");
    return 0;
}