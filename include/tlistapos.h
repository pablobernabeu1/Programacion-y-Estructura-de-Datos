#include<iostream>
#include<cstring>

using namespace std;

class TListaPos {

  private:
    TNodoCalendario *pos;

  public:
    TListaPos();
    TListaPos(ListaPos &);
    ~ListaPos();
    ListaPos & operator=(ListaPos &);

};
