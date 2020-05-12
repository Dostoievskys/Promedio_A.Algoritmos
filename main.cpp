#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <Estudiante.h>

using namespace std;

/**
 * Función que muestra los participantes del grupo
 */
void participantes();


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
int main(int argc, char** argv) {

    if (argc > 1) {
        std::string archivo(argv[1]);
        
        std::ifstream lectura(archivo);
        std::ofstream escritura("promedio.csv");
        
        if (lectura) {
            for (std::string linea; getline(lectura,linea) ; ) {
                std::vector<int> puntajes = obtenerPuntajes(linea);
                int rut = puntajes.at(0);
                double promedio = promediar(puntajes);
                
                std::string salida = std::to_string(rut) + ";" + std::to_string(promedio);
                escritura << salida << std::endl;
                puntajes.clear();
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