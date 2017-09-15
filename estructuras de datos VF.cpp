//David Hernando Castro Santiago 20152020018
//ciencias de la computaciòn grupo 020-81 Profesor Luis Emilio Montenegro
// Taller estructuras de datos:
#include <iostream>
using namespace std;
//VARIABLES:
//------------------------------------------------------------------------
//EStructura "Nodo":
struct Nodo{
	int dato;
	//apuntador al siguiente nodo 
	Nodo *sig;
};
//------------------------------------------------------------------------
char menu;
//PROTOTIPOS DE LAS CLASES:
//------------------------------------------------------------------------
//Clase Lista dinamica:
class ListaDinamica{
	protected:
	Nodo *cab; //apuntador a "cabeza"
	//Metodos:
	public: 
	ListaDinamica();
	void agregar(int);
	void mostrar();	
	int eliminar();//elimina el ultimo
	void eliminar(int);//elimina un elemento dado	
	void insertarIzq(int,int);//inserta un elemento a la izquierda de un elemento dado
	void insertarDer(int,int);//inserta un elemento a la derecha de un elemento dado
	Nodo *buscar(int);
	void ordenar();
	bool estaVacia();
};
//------------------------------------------------------------------------
//Clase Pila:
class Pila: public ListaDinamica{
	public:
		Pila();
		int eliminar();
};
//------------------------------------------------------------------------
//Clase Cola:
class Cola: public ListaDinamica{
	private:
		Nodo *fin;
	public:
		Cola();
		void agregar(int);
		int eliminar();
};
//------------------------------------------------------------------------
//Clase Vista:
class Vista{
	private:
		char opcion;
	public:
		Vista();
		char menuPrincipal();
		char menuLista();
		char menuCola();
		char menuPila();
		char menuEliminar();
		char menuInsertar();
		
};
//------------------------------------------------------------------------
//Clase ControlOpciones:
class ControlVista{
	private:
		Vista vista;
		char opcion;
		int dato;
	public:
		ControlVista();
		void menuPrincipal();
		void menuLista();
		void menuCola();
		void menuPila();
		void menuEliminar(ListaDinamica);
		void menuInsertar(ListaDinamica);
};
//DESARROLLO DE LOS METODOS DE LAS CLASES:
//------------------------------------------------------------------------
//Clase Lista dinamica:
//consstructor:
ListaDinamica::ListaDinamica(){
	cab=NULL;
}
//metodo agregar:
void ListaDinamica::agregar(int dato){
	Nodo *p=new Nodo;
	//se puede asignar de las siguientes formas:
	p->dato=dato;
	(*p).sig=cab;
	cab=p;
}
//metodo mostrar (muestra los datos de los elementos de la estructura dinamica)
void ListaDinamica::mostrar(){
	Nodo *p=cab;
	while(p!=NULL){//otra forma de ponerlo: while(p)
		cout<<p->dato<<" ";
		p=p->sig;
	}
}
//metodo eliminar (elimina el ultimo)
int ListaDinamica::eliminar(){
	int dato;
	Nodo *p=cab,*q;
	while (p->sig){
		q=p;
		p=p->sig;
	}
	q->sig=NULL;
	dato=p->dato;
	
	delete p;
	return dato;
}
//metodo eliminar (elimina un elemento dado)
void ListaDinamica::eliminar(int numero){
	Nodo *p,*q=cab;
	p=this->buscar(numero);
		while (q->sig!=p)
			q=q->sig;
		q->sig=p->sig;
		delete p;
	;
}
//metodo insertar (inserta un elemento a la izquierda de una referencia)
void ListaDinamica::insertarIzq(int referencia,int dato){
	Nodo *p,*q=cab,*r=new Nodo;
	p=this->buscar(referencia);
		while(q->sig!=p)
			q=q->sig;
		r->dato=dato;
		r->sig=p;
		q->sig=r;
}

//metodo insertar (inserta un elemento a la derecha de una referencia)
void ListaDinamica::insertarDer(int referencia,int dato){
	Nodo *p,*r=new Nodo;
	p=this->buscar(referencia);
		r->dato=dato;
		r->sig=p->sig;
		p->sig=r;
}
//metodo buscar (busca un elemento dado en la estructura)
Nodo* ListaDinamica::buscar(int numero){
int k=0; //indice en la posici? cero
	Nodo *p=cab;
	while(p){
		if(p->dato==numero)
			return p;
		p=p->sig;
	}
	return NULL;
}
//metodo ordenar (ordena la estructura)
void ListaDinamica::ordenar(){//ordenamiento por burbuja :V
	Nodo *p=cab,*q;
	int aux;
	while(p){
		q=p->sig;
		while(q){
			if((p->dato)>(q->dato)){
				aux=p->dato;
				p->dato=q->dato;
				q->dato=aux;
			}
			q=q->sig;
		}
		p=p->sig;
	}
}
//metodo estaVacia (dice si la estructura esta vacia mediante un booleano)
bool ListaDinamica::estaVacia(){
	return cab==NULL;
}
//------------------------------------------------------------------------
//Clase Pila:
//consstructor:
Pila::Pila(){
	cab=NULL;
}
//metodo eliminar sobre escrito:
int Pila::eliminar(){
	int dato;
	Nodo *p=cab;
	dato=cab->dato;
	cab=p->sig;
	delete p;
	return dato;
}
//------------------------------------------------------------------------
//Clase Cola:
//consstructor:
Cola::Cola(){
	cab=fin=NULL;//cola vacia
}
//metodo agregar sobre escrito:
void Cola::agregar(int dato){
	Nodo *p=new Nodo;
	p->dato=dato;
	p->sig=NULL;
	if(!cab)//"no cabeza=null"
		cab=p;
	else
		fin->sig=p;
		fin=p;
}
//metodo eliminar sobre escrito:
int Cola::eliminar(){
	int dato;
	Nodo *p=cab;
	dato=cab->dato;
	cab=p->sig;
	delete p;
	return dato;
}
//------------------------------------------------------------------------
//Clase Vista:
//constructor:
Vista::Vista(){
	opcion=' ';
}
//metodo menuPrincipal que solo muestra el menu principal
char Vista::menuPrincipal(){
	cout<<"\n MENU Principal\n"; 
	cout<<"(L)crear nueva Lista Dinamica\n";
	cout<<"(C)crear nueva Cola\n";
	cout<<"(P)crear nueva Pila\n";
	cout<<"(T)Terminar\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
//metodo menuLista que solo muestra el menu de opciones a realizar en lista 
char Vista::menuLista(){
	cout<<"\n MENU Lista\n"; 
	cout<<"(A)agregar\n";
	cout<<"(E)eliminar\n";
	cout<<"(I)insertar\n";
	cout<<"(B)buscar\n";
	cout<<"(O)ordenar\n";
	cout<<"(M)mostrar\n";
	cout<<"(R)regresar\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
//metodo menuEliminar que muestra las opciones de eliminado de la lista
char Vista::menuEliminar(){
	cout<<"\n MENU Eliminar\n"; 
	cout<<"(U)eliminar el ultimo\n";
	cout<<"(E)eliminar uno dado\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
//metodo menuInsertar que muestra las opciones de insertado de la lsta
char Vista::menuInsertar(){
	cout<<"\n MENU Insertar\n"; 
	cout<<"(D)insertar a la derecha de un elemento dado\n";
	cout<<"(I)insertar a la izquierda de un elemento dado\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
//metodo menuCola que muestra que solo muestra el menu de opciones a realizar en la cola 
char Vista::menuCola(){
	cout<<"\n MENU Cola\n"; 
	cout<<"(A)agregar\n";
	cout<<"(E)eliminar\n";
	cout<<"(B)buscar\n";
	cout<<"(M)mostrar\n";
	cout<<"(R)regresar\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
//metodo menuCola que muestra que solo muestra el menu de opciones a realizar en la pila
char Vista::menuPila(){
	cout<<"\n MENU Pila\n"; 
	cout<<"(A)agregar\n";
	cout<<"(E)eliminar\n";
	cout<<"(B)buscar\n";
	cout<<"(M)mostrar\n";
	cout<<"(R)regresar\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
//------------------------------------------------------------------------
//Clase ControlVista:
//constructor:
ControlVista::ControlVista(){
	opcion=' ';
}
//metodo menuPrncipal del control vista que controla las opciones recibidas del menuPrincipal de la clase vista
void ControlVista::menuPrincipal(){
	do{
		opcion=vista.menuPrincipal();
		switch(opcion){
			case 'l':
			case 'L':
				this->menuLista();
				break;
			case 'c':
			case 'C':
				this->menuCola();
				break;
			case 'p':
			case 'P':
				this->menuPila();
				
				break;
		}
		
	}while(opcion!='t' && opcion!='T');
}
//metodo menuLista del control vista que controla las opciones recibidas del menuLista de la clase vista
void ControlVista::menuLista(){
 	ListaDinamica lista;
	do{
		opcion=vista.menuLista();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Digite el elemento a agregar: ";
				cin>>dato;
				lista.agregar(dato);	//agregamos datos
				break;
			case 'e':
			case 'E':
				this->menuEliminar(lista);
				break;
			case 'i':
			case 'I':
				this->menuInsertar(lista);
				break;

			case 'b':
			case 'B':
				Nodo *p;
				cout<<"Digite el elemento a buscar ";
				cin>>dato;
				p=lista.buscar(dato);
				if (p)
				cout<<"el elemento buscado esta en la lista"<<endl;	
				else cout<<"el elemento no esta en la lista\n";
				break;
			case 'o':
			case 'O':
				lista.ordenar();
				cout<<"La lista ha sido ordenada \n ";

				break;
			case 'm':
			case 'M':
				cout<<"Los elementos almacenados: "<<endl;
				lista.mostrar();
				break;

		}
		
	}while(opcion!='r' && opcion!='R');
}
//metodo menuEliminar del control vista que controla las opciones recibidas del menuEliminar de la clase vista
void ControlVista::menuEliminar(ListaDinamica lista){
	opcion=vista.menuEliminar();
	switch(opcion){
		case 'u':
		case 'U':
			if(lista.estaVacia())
				cout<<"no hay elementos para eliminar"<<endl;
			else{
				dato=lista.eliminar();
				cout<<"se elimino el elemento "<<dato<<endl;
			}
			break;
		case 'e':
		case 'E':
			cout<<"Digite el dato a eliminar: ";
			cin>>dato;
			if(lista.buscar(dato)){
				lista.eliminar(dato);
				cout<<"Dato eliminado\n";
			}
			else 
				cout<<"dato no eliminado, no se ha encontrado\n";
			break;
	}
}
//metodo menuInsertar del control vista que controla las opciones recibidas del menuInsertar de la clase vista
void ControlVista::menuInsertar(ListaDinamica lista){
	int referencia;
	opcion=vista.menuInsertar();
	switch(opcion){
		case 'd':
		case 'D':
			cout<<"Digite el elemento referencia: ";
			cin>>referencia;
			if(lista.buscar(referencia)){
				cout<<"Digite el elemento a insertar: ";
				cin>>dato;
				lista.insertarDer(referencia,dato);
				cout<<"Dato insertado\n";
			}
			else 
				cout<<"no se ha encontrado la referencia\n";
			break;
		case 'i':
		case 'I':
			cout<<"Digite el elemento referencia: ";
			cin>>referencia;
			if(lista.buscar(referencia)){
				cout<<"Digite el elemento a insertar: ";
				cin>>dato;
				lista.insertarIzq(referencia,dato);
				cout<<"Dato insertado\n";
			}
			else 
				cout<<"no se ha encontrado la referencia\n";
			break;
		}
}
//metodo menuCola del control vista que controla las opciones recibidas del menuCola de la clase vista
void ControlVista::menuCola(){
	Cola cola;
	do{
		opcion=vista.menuCola();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Digite el elemento a agregar: ";
				cin>>dato;
				cola.agregar(dato);	//agregamos datos
				break;
			case 'e':
			case 'E':
				if(cola.estaVacia())
					cout<<"no hay elementos para eliminar"<<endl;
				else{
					dato=cola.eliminar();
					cout<<"se elimino el elemento "<<dato<<endl;
				}
				break;

			case 'b':
			case 'B':
				Nodo *p;
				cout<<"Digite el elemento a buscar ";
				cin>>dato;
				p=cola.buscar(dato);
				if (p)
				cout<<"el elemento buscado esta en la cola"<<endl;	
				else cout<<"el elemento no esta en la cola\n";
				break;
			case 'm':
			case 'M':
				cout<<"Los elementos almacenados: "<<endl;
				cola.mostrar();//se llama al metodo mostrar 
				break;


		}
		
	}while(opcion!='r' && opcion!='R');
}
//metodo menuPila del control vista que controla las opciones recibidas del menuPila de la clase vista
void ControlVista::menuPila(){
	Pila pila;
	do{
		opcion=vista.menuPila();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Digite el elemento a agregar: ";
				cin>>dato;
				pila.agregar(dato);	//agregamos datos
				break;
			case 'e':
			case 'E':
				if(pila.estaVacia())
					cout<<"no hay elementos para eliminar"<<endl;
				else{
					dato=pila.eliminar();
					cout<<"se elimino el elemento "<<dato<<endl;
				}
				break;

			case 'b':
			case 'B':
				Nodo *p;
				cout<<"Digite el elemento a buscar ";
				cin>>dato;
				p=pila.buscar(dato);
				if (p)
				cout<<"el elemento buscado esta en la pila"<<endl;	
				else cout<<"el elemento no esta en la pila\n";
				break;
			case 'm':
			case 'M':
				cout<<"Los elementos almacenados: "<<endl;
				pila.mostrar();//se llama al metodo mostrar 
				break;


		}
		
	}while(opcion!='r' && opcion!='R');
}
//-----------------------------------------------------------------------------
//main;
int main(){
	ControlVista menu;
	menu.menuPrincipal();
	return 0;
}
