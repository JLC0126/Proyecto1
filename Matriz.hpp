#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{

    public:
        Matriz();
        Matriz(int, int);
        void llenar_matriz(int , int);
        void mostrar_matriz(Matriz );
        Matriz multiplicar(Matriz, Matriz);
        int getfila();
        int getcolumna();


    private:
        int fila, columna;
        double **elemento;
        void asignarElemento();

};

#endif