#include <iostream>

using namespace std;

#include "tlistacalendario.h"

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

/*
int main(){

  TVectorCalendario a(3), b(3);
  TCalendario ca1(1,1,2006, (char*) "uno"), ca2(1,2,2006, (char*) "dos"), ca3(1,3,2006, (char*) "tres");
  a[3] = ca3;

  b[1] = ca1;
  b[3] = ca3;

  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  if(a.ExisteCal(ca1))
     cout << "Existe" << endl;
  else
     cout << "No existe" << endl;

  if(b.ExisteCal(ca1))
     cout << "Existe" << endl;
  else
     cout << "No existe" << endl;

  return 0;

}
*/

int
main(void)
{
   TListaCalendario l1;

   //TCalendario c1(14, 12, 1966, (char*) "Fecha Correcta");
   //TCalendario c2(1, 1, 1954, (char*) "Fecha Correcta");

   cout << l1 << endl;

   //cout<<"Termino"<<endl;
   /*
   l1.Insertar(c1);
   cout << l1 << endl;
   l1.Insertar(c2);
   cout << l1 << endl;
   */
   return 0;
}
