#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "Estudiante.h"
#include "Estudiante.cpp"

using namespace std;

void participantes(); //Función que muestra los participantes del grupo
vector<int> obtenerPuntajes(std::string fila);
void Ordenamiento(std::vector<Estudiante> &x,int n);

int main(int argc, char** argv) {
    std::vector<Estudiante> E; //Se crea un vector de tipo Estudiante
    Estudiante A,B;
    int cont=0;
    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        std::ofstream escritura("promedioOrdenado.csv");
    
        if (lectura) {
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<int> puntajes = obtenerPuntajes(linea);
                //Se llenan los datos en el vector E
                A.SetRut(puntajes.at(0)); 
                A.SetPromedio(puntajes.at(1));
                E.push_back(A);
                cont++;
                puntajes.clear();
            }
            Ordenamiento(E,cont);
            for(int i=0; i<cont;i++){ //Creamos el archivo ordenado
                B=E[i];

                std::string salida = std::to_string(B.GetRut()) + ";" + std::to_string(B.GetPromedio());
                escritura << salida << std::endl;
            }
        }
    }
    
    /**
     * Despliegue de participantes
     */
    participantes();
    return EXIT_SUCCESS;
}

void participantes() {
    std::cout << std::endl << "=== Ejemplo de Promediar ===" << std::endl;
    std::cout << std::endl << "Braulio Argandoña"  << std::endl;
    std::cout << std::endl << "Fanny Rivero"  << std::endl;
    std::cout << std::endl << "Jennifer Portiño"  << std::endl;
}

vector<int> obtenerPuntajes(std::string fila){
    vector<int> arreglo;
    std::stringstream ss(fila);
    std::string item;

    // 17424518;639.66667 -> ss

    while (std::getline(ss, item, ';')){ //Lo que quiero separar, donde lo guardo, que lo separa
        int valor = atoi(item.c_str());
        arreglo.push_back(valor);
    }
    return arreglo;
}

void Ordenamiento(std::vector<Estudiante> &x, int n){ //Ordenamiento por Seleccion
    int k;
    Estudiante aux;
    for(int i=0;i<n;i++){
        k=i;
        for(int j=i+1 ; j<n;j++){
            if(x[j].GetPromedio() < x[k].GetPromedio()){
                k=j;
            }
        }
        swap(x[i],x[k]); //Hace el intercambio
    }
}