#include<iostream>
#include "tvectorcalendario.h"
using namespace std;

/*
int main(){

    TCalendario c1;

    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;

    return 0;
}*/

/*
int main(){

    TCalendario c1, c4;
    TCalendario c2(19,4,2001, (char *)"Fecha de nacimiento.");

    c4 = c1 - 10;

    //TCalendario c1(c2);

    cout<<c1.Dia()<<endl;
    cout<<c1.Mes()<<endl;
    cout<<c1.Anyo()<<endl;
    cout<<c1.Mensaje()<<endl;




    return 0;
}
*/
/*
int main(){

    TCalendario c1(19, 4, 2001, (char *)"Mi fecha de cumpleaños.");
    TCalendario c3=c1;

    //TCalendario c2 = c1+2;

    //cout<<c2+2<<endl;

    cout<<c1<<endl;
    cout<<c3<<endl;

    if(c3==c1){
      cout<<"Hola"<<endl;
    }
    else{
      cout<<"Adios"<<endl;
    }

    return 0;
}
*/
/*
int main(){

    TCalendario c1(31, 12, 2001, (char *)"Mi fecha de cumpleaños.");
    TVectorCalendario vc;

    //cout<<(c1++)<<endl;


    return 0;
}
*/


int main(){

  TVectorCalendario a, b(-3), c(4);
  cout << a.Tamano() << endl;
  cout << b.Tamano() << endl;
  cout << c.Tamano() << endl;
  cout << c.Ocupadas() << endl;
  return 0;

}
