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
/**
 * 
 * @param fila una línea del archivo
 * @return vector con los puntajes. (0 -> rut)
 */
vector<int> obtenerPuntajes(std::string fila);
/**
 * 
 * @param puntajes Arreglo con los valores
 * @return el promedio del elemento 1 - 7 (Recordar que 0 -> rut)
 */
double promediar(std::vector<int> puntajes);
/**
 * Ejemplo Factorial
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
void Ordenamiento(std::vector<Estudiante> &x,int n);

int main(int argc, char** argv) {
    std::vector<Estudiante> E; //Se crea un vector de tipo Estudiante
    Estudiante A,B;
    int cont=0;
    if (argc > 1) {
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);
        std::ofstream escritura("promedio.csv");
    
        if (lectura) {
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<int> puntajes = obtenerPuntajes(linea);
                //Se llenan los datos en el vector E
                A.SetRut(puntajes.at(0)); 
                A.SetPromedio(promediar(puntajes));
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

vector<int> obtenerPuntajes(std::string fila) {
    vector<int> arreglo;
    std::stringstream ss(fila);
    std::string item;

    // 17424518;639;654;500;583;714;724 -> ss

    while (std::getline(ss, item, ';')) {
        int valor = atoi(item.c_str());
        arreglo.push_back(valor);
    }
    return arreglo;
}

double promediar(std::vector<int> puntajes) {
    double promedio = 0.0;
    if (puntajes.size() >= 6) {
        // int rut = puntajes.at(0);
        int nem = puntajes.at(1);
        int ranking = puntajes.at(2);
        int matematica = puntajes.at(3);
        int lenguaje = puntajes.at(4);
        int ciencias = puntajes.at(5);
        int historia = puntajes.at(6);

        promedio = (nem + ranking + matematica + lenguaje + ciencias + historia) / 6.0;
    }
    return promedio;
}

void Ordenamiento(std::vector<Estudiante> &x, int n){ //Ordenamiento por Seleccion
    int k;
    Estudiante aux;
    //swap(x[0],x[1]);
    for(int i=0;i<n;i++){
        k=i;
        for(int j=i+1 ; j<n;j++){
            if(x[j].GetPromedio() < x[k].GetPromedio()){
                k=j;
            }
        }
        swap(x[i],x[k]);
    }
}