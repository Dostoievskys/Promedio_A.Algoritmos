#include "Estudiante.h"
#include <iostream>

using namespace std;

Estudiante::Estudiante(){
}

double Estudiante::GetPromedio(){
    return promedio;
}

int Estudiante::GetRut(){
    return rut;
}

void Estudiante::SetPromedio(double y){
    promedio=y;
}

void Estudiante::SetRut(int x){
    rut=x;
}