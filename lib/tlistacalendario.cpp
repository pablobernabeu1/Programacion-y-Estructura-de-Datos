#include "tlistacalendario.h"

TNodoCalendario::TNodoCalendario(): c(){
  this->siguiente=NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &nc): c(nc.c){
  this->siguiente=NULL;
}

TNodoCalendario::~TNodoCalendario(){
  this->siguiente=NULL;
  c.~TCalendario();
}

TNodoCalendario&
TNodoCalendario::operator=(const TNodoCalendario &nc){
  if(this != &nc){
    (*this).~TNodoCalendario();

    this->c = nc.c;
    this->siguiente = nc.siguiente;
  }

  return *this;
}




// Metodos de TListaPos




TListaPos::TListaPos() {
  pos = NULL;
}

TListaPos::TListaPos(const TListaPos &lp){
  pos = lp.pos;
}

TListaPos::~TListaPos(){
  if(pos!=NULL){
		pos=NULL;
	}
}

TListaPos&
TListaPos::operator=(const TListaPos &lp){

  if(this->pos!=lp.pos){
    (*this).~TListaPos();
    this->pos = lp.pos;
  }

  return *this;
}

bool
TListaPos::operator==(const TListaPos &lp){
  if(this->pos==lp.pos){
    return true;
  }
  return false;
}

bool
TListaPos::operator!=(const TListaPos &lp){
  if(this->pos==lp.pos){
    return false;
  }
  return true;
}

TListaPos
TListaPos::Siguiente(){
  if(this->pos->siguiente==NULL){
    TListaPos lp;
    return lp;
  }
  else{
    this->pos=this->pos->siguiente;
    return *this;
  }
}

bool
TListaPos::EsVacia() const {
  return this->pos ==NULL;
}



// Metodos de tlistacalendario



TListaCalendario::TListaCalendario(){
  this->primero=NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &lc){
  this->primero=lc.primero;
}

TListaCalendario::~TListaCalendario(){

  TNodoCalendario *nc = NULL;

  while(!EsVacia()){
    nc = primero;
    primero = primero->siguiente;

    if(nc!=NULL){
      //cout<<nc->c<<endl;
      delete nc;
      nc = NULL;
    }
  }

}

TListaCalendario&
TListaCalendario::operator=(const TListaCalendario &lc){
  TListaPos prev;
  if(this!=&lc){
    (*this).~TListaCalendario();
    prev = lc.Primera();
    for(int i=0; i<lc.Longitud(); i++){
      Insertar(prev.pos->c);
      prev = prev.Siguiente();
    }
  }

  return *this;
}

bool
TListaCalendario::operator==(const TListaCalendario &lc){

  TNodoCalendario *nc1 = this->primero;
  TNodoCalendario *nc2 = lc.primero;

  for(int i=0; i<Longitud(); i++){
    if(nc1!=nc2){
      return false;
    }
    nc1 = nc1->siguiente;
    nc2 = nc2->siguiente;
  }

  return true;
}

TListaCalendario
TListaCalendario::operator+(const TListaCalendario &lc){

  TListaCalendario lcSuma;
  TListaPos lp(Primera());
  TListaPos lp2(lc.Primera());

  for(int i=0; i<Longitud(); i++){
    lcSuma.Insertar(lp.pos->c);
    lp = lp.Siguiente();
  }
  for(int i=0; i<lc.Longitud(); i++){
    lcSuma.Insertar(lp2.pos->c);
    lp2 = lp2.Siguiente();
  }

  return lcSuma;
}

TListaCalendario
TListaCalendario::operator-(const TListaCalendario &lc){

  TListaCalendario lcSuma(*this);
  TListaPos lp;

  while(!lp.EsVacia()){
    lcSuma.Borrar(Obtener(lp));
    lp = lp.Siguiente();
  }

  return lcSuma;
}

bool
TListaCalendario::Insertar(const TCalendario &cal){
	bool encontrado=false;

	if(EsVacia()) {
		TNodoCalendario *nodo=new TNodoCalendario();
		nodo->c=cal;
		primero=nodo;
		return true;
	} else if(!Buscar(cal)){
		TListaPos aux;
		TListaPos prev;
		aux=Primera();

		while(!encontrado && !aux.EsVacia()) {
			if(Obtener(aux)>cal) {
				encontrado=true;
			} else {
				prev=aux;
				aux=aux.Siguiente();
			}
		}
		if(encontrado || prev==Ultima()) {
			if(prev.EsVacia()) {
				TNodoCalendario *nodo=new TNodoCalendario();
				nodo->c=cal;
				nodo->siguiente=aux.pos;
				primero=nodo;
				return true;
			} else if(prev==Ultima()) {
				TNodoCalendario *nodo=new TNodoCalendario();
				nodo->c=cal;
				nodo->siguiente=NULL;
				prev.pos->siguiente=nodo;
				return true;
			} else {
				TNodoCalendario *nodo=new TNodoCalendario();
				nodo->c=cal;
				nodo->siguiente=aux.pos;
				prev.pos->siguiente=nodo;
				return true;
			}
		}
	}
	return false;
}

bool
TListaCalendario::Borrar(const TCalendario &cal){
  bool correcto=false;

  TListaPos prev = Primera();
  TListaPos aux = Primera();

  if(!EsVacia() && Buscar(cal)){
    if(Obtener(aux)==cal){
      primero = primero->siguiente;
      delete aux.pos;
      return true;
    }
    else{
      aux = aux.Siguiente();
      while(aux.pos!=NULL && !correcto){
        if(Obtener(aux)==cal){
          prev.pos->siguiente = aux.pos->siguiente;
          delete aux.pos;
          return true;
        }
        else{
          aux=aux.Siguiente();
          prev=aux;
        }
      }
    }
  }

  return false;
}

bool
TListaCalendario::Borrar(const TListaPos &lp){
  return Borrar(Obtener(lp));
}

bool
TListaCalendario::Borrar(int d, int m, int a){
  TCalendario c(d, m, a, (char *)"");
  bool exit=false;

  TListaPos lp;
  lp.pos=primero;
  TListaPos ant;

  if(!EsVacia()){
    if(c>primero->c){
      primero = primero->siguiente;
      delete lp.pos;
      return true;
    }
    else{
      ant = lp;
      lp = lp.Siguiente();

      while(lp.pos!=NULL){
        if(c>lp.pos->c && exit==false){
          ant.pos->siguiente = lp.pos->siguiente;
          delete lp.pos;
          ant = lp;
          lp.pos = lp.pos->siguiente;
          return true;
        }
        else{
          exit=true;
        }
      }
    }
  }

  return false;
}

bool
TListaCalendario::EsVacia() const {
	if(primero==NULL){
		return true;
	}
	return false;
}

TCalendario
TListaCalendario::Obtener(const TListaPos &lp) const {

  if(!lp.EsVacia()){
    return lp.pos->c;
  }
  TCalendario cal;

  return cal;
}

bool
TListaCalendario::Buscar(const TCalendario &cal) const {
  TListaPos lp;
  lp.pos = primero;

  for(int i=0;i<Longitud(); i++){
    if(lp.pos->c==cal){
      return true;
    }
    else{
      lp = lp.Siguiente();
    }
  }
  return false;
}

int
TListaCalendario::Longitud() const {
  int longitud=0;
  TListaPos lp ;
  lp = Primera();

  while(!lp.EsVacia()){
    lp = lp.Siguiente();
    longitud++;
  };

  return longitud;
}

TListaPos TListaCalendario::Primera() const {
	TListaPos lp;
	lp.pos=primero;
	return lp;
}

TListaPos TListaCalendario::Ultima() const{
	TListaPos lp;
	lp=Primera();
	for(int i=1;i<Longitud();i++){//Empiezas en la primera posicion por lo que i se inicializa a 1
		lp=lp.Siguiente();
	}
	return lp;
}

TListaCalendario
SumarSubl(int I_L1, int F_L1, TListaCalendario &L2, int I_L2, int F_L2){
  TListaCalendario lcSuma;


  return lcSuma;
}

TListaCalendario
TListaCalendario::ExtraerRango(int n1, int n2){
  TListaCalendario lc;
  TListaPos lp, aux;
  lp = Primera();

  if(n1<=0){
    n1=1;
  }
  if(n2>Longitud()){
    n2 = Longitud();
  }
  if(n2>=n1){
    for(int i=1; i<=n2; i++){
      if(i>=n1){
        lc.Insertar(lp.pos->c);
        aux=lp.Siguiente();
        Borrar(lp.pos->c);
        lp = aux;
      }
      else{
        lp = lp.Siguiente();
      }

    }
  }

  return lc;
}

ostream & operator<<(ostream &o,const TListaCalendario &lc){
	TListaPos lp;
	lp=lc.Primera();
	if(lp.EsVacia()){
		o<<"<>";
	}
	else{
		o<<"<";
		for(int i=0;i<lc.Longitud();i++){
			if(i==0){
				o<< lc.Obtener(lp);
			}
			else{
				o<< " " << lc.Obtener(lp);
			}
			lp=lp.Siguiente();
		}
		o<<">";
	}
	return o;
}
