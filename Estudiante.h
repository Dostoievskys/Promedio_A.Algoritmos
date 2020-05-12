#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>

class Estudiante{
    private:
        int rut;
        double promedio;
    public:
        Estudiante();
        double GetPromedio();
        int GetRut();
        void SetPromedio(double);
        void SetRut(int);
};

#endif