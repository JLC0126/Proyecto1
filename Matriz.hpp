
class Matriz{
    public:
        Matriz(int, int);
        Matriz multiplicar(Matriz *, Matriz * );
        Matriz suma(Matriz *, Matriz *);
        Matriz escalar(Matriz * );
        double ProductoPunto(Matriz *, Matriz * );

    private:
        double fila,columna;
};