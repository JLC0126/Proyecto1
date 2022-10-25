#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz{
    //____Sobrecargando operadores (+,-,*)__________

    friend Matriz &operator*(const Matriz &, const Matriz &);//producto matricial
    friend Matriz &operator+(const Matriz &, const Matriz &);
    friend Matriz &operator-(const Matriz &, const Matriz &);
    friend Matriz &operator*( const int &, const Matriz &); //producto por escalar


    public:
        Matriz();//ctor por defecto matriz1.mostrar_matriz()
        Matriz(int, int);//ctor por parametros
        void llenar_matriz();
        void mostrar_matriz();


    private:
        int fila, columna;
        int **elemento;
};

#endif