#include <iostream>

using namespace std;

class Estudiante{
    private:
        int rut;
        double promedio;
    public:
        double GetPromedio();
        int GetRut();
        void SetPromedio(double);
        void SetRut(int);
};