class Estudiante{
    private:
        int rut;
        double promedio;
    public:
        double GetPromedio;
        int GetRut;
        void SetPromedio(double y);
        void SetRut(int x);
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