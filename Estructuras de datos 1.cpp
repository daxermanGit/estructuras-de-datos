// Estructuras de datos:
#include <iostream>
using namespace std;
//Nodo es una estructura:
char menu ();//prototipo de "menu"
struct Nodo{
	int dato;
	//apuntador al siguiente nodo 
	Nodo *sig;
};
//prototipo de la clase
class ListaDinamica{
	Nodo *cab; //apuntador a "cabeza"
	//Metodos:
	public: 
	ListaDinamica();
	void agregar(int);
	int eliminar();//elimina el ultimo
	bool eliminar(int);//elimina un elemento dado
	Nodo *buscar(int);
	void mostrar();	
	void ordenar();		
};
//Constructor:
ListaDinamica::ListaDinamica(){
	cab=NULL;
}
void ListaDinamica::agregar(int dato){
	Nodo *p=new Nodo;
	//se puede asignar de las siguientes formas:
	p->dato=dato;
	(*p).sig=cab;
	cab=p;
}

void ListaDinamica::mostrar(){
	Nodo *p=cab;
	while(p!=NULL){//otra forma de ponerlo: while(p)
		cout<<p->dato<<" ";
		p=p->sig;
	}
}
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
int ListaDinamica::eliminar(){
	int datoEliminado;
	if (cab){
		Nodo *elemento=cab;
		//se puede asignar de las siguientes formas:
		cab=elemento->sig;
		datoEliminado=elemento->dato;
		delete elemento;
		return datoEliminado;
	}
}
//void ListaDinamica::eliminar(int numero){
//		Nodo *conexion,*elemento=cab;
//		for(int i=1;i<numero-1;i++){
//			elemento=elemento->sig;
//		}
//			
//			conexion=elemento->sig;
//			elemento->sig=conexion->sig;
//			delete conexion;
//}
bool ListaDinamica::eliminar(int numero){
	Nodo *p,*q=cab;
	p=this->buscar(numero);
	if(p){
		while (q->sig!=p)
			q=q->sig;
		q->sig=p->sig;
		delete p;
		return true;
	}else return false;
}
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
//main de prueba :v
int main(){
	ListaDinamica lista;
	char opcion;
	int dato;
	do{
		opcion=menu();
		switch(opcion){
			case 'a':
			case 'A':
				cout<<"Digite el elemento a agregar: ";
				cin>>dato;
				lista.agregar(dato);	//agregamos datos
				break;
			case 'u':
			case 'U':
				
				cout<<"se elimino el dato "<<lista.eliminar()<<endl;

				break;
			case 'o':
			case 'O':
				lista.ordenar();
				cout<<"La lista ha sido ordenada \n ";
				//proxima instanciación :v
				break;
			case 'm':
			case 'M':
				cout<<"Los elementos almacenados: "<<endl;
				lista.mostrar();//se llama al metodo mostrar 
				break;
			case 'e':
			case 'E':
				cout<<"Digite el dato a eliminar: ";
				cin>>dato;
				if(lista.eliminar(dato))
					cout<<"Dato eleminado\n";
				else 
					cout<<"dato no eliminado, no se ha encontrado\n";
				
				break;
			case 'b':
			case 'B':
				Nodo *p;
				cout<<"Digite el elemento a buscar ";
				cin>>dato;
				p=lista.buscar(dato);
				if (p)
				cout<<"el elemento buscado esta en "<<p<<endl;	
				else cout<<"el elemento no esta en la lista\n";
				break;
			default:
				cout<<"digitacion incorrecta"<<endl;
		}
		
	}while(opcion!='t' && opcion!='T');
	
	system("pause");
	return 0;
}
char menu(){
	char opcion;
	cout<<"\n MENU\n";
	cout<<"(A)agregar\n";
	cout<<"(U)eliminar (ultimo elemento)\n";
	cout<<"(E)eliminar (el dato dato dado)\n";
	cout<<"(B)buscar\n";
	cout<<"(O)ordenar\n";
	cout<<"(M)mostrar\n";
	cout<<"(T)terminar\n";
	cout<<"Escoja una opcion:";
	cin>>opcion;
	return opcion;
}
