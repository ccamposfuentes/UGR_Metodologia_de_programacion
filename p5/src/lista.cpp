#include <string>
#include <fstream>
#include "../lista.h"

using namespace std;

Lista::Lista(){
	cabecera = 0;
}
   
Lista::Lista(string valor){
	cabecera = new Celda();
  cabecera->dato = valor;
  cabecera->siguiente = 0;
}
	

void Lista::destruir(){
	delete cabecera;
}  

void Lista::insertar(string valor){

  if (cabecera != 0) {
    Celda *aux = cabecera;

    while (aux->siguiente != 0) {
      aux = aux->siguiente;
    }

    aux->dato = valor;
    aux->siguiente = 0;
  }
  else
    Lista(valor);


}

string Lista::getCelda(int pos) const{
  Celda * aux = cabecera;

  for (int i=0; i<pos; i++) {
    aux = aux->siguiente;
  }

  return aux->dato;
}

int Lista::longitud() const{
  int cont = 0;
  Celda * aux = cabecera;

  while(cabecera->siguiente != 0) {
    aux = aux->siguiente;
    cont++;
  }

  return cont;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
		}
		fin.close();
	}
	return true;
}
