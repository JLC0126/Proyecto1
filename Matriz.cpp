#include "Matriz.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include<time.h>
#include <cstdlib>
using std::rand;
using std::srand;

Matriz::Matriz()
{

    fila = 2;
    columna = 2;
}

Matriz::Matriz(int f, int c)
{
    fila = f;
    columna = c;

    this->elemento = new int *[this->fila];

    for (int i = 0; i < this->fila; i++)
    {
        this->elemento[i] = new int[this->columna];
    }

    this->elementos = new float *[this->fila];

    for (int i = 0; i < this->fila; i++)
    {
        this->elementos[i] = new float[this->columna];
    }
}

Matriz::~Matriz()
{
}

void Matriz::llenar_matriz()
{   
    srand(time(NULL));
    for (int i = 0; i < this->fila; i++)
    {
        for (int j = 0; j < this->columna; j++)
        {
            *(*(this->elemento + i) + j) = rand() % 9;
        }
    }
}

void Matriz::mostrar_matriz()
{

    for (int i = 0; i < this->fila; i++)
    {
        for (int j = 0; j < this->columna; j++)
        {
            cout << *(*(this->elemento + i) + j) << " ";
        }
        cout << endl;
    }
}

//----------IMPLENETANDO SOBRECARGA DE LOS OPERADORES----------

Matriz &operator*(const Matriz &m1, const Matriz &m2)
{
    int resultado = 0;
    int f;
    int c;
    if (m1.columna == m2.fila)
    {
        f = m1.fila;
        c = m2.columna;
    }
    else
    {
        cout << "No se pueden multiplicar las matrices, la dimension de la columna del primer objeto ";
        cout << "tiene que ser igual a la dimension de la fila del segundo objeto" << endl;
    }

    Matriz *mResp = new Matriz(f, c);

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            resultado = 0;
            for (int k = 0; k < c; k++)
            {
                resultado += m1.elemento[i][k] * m2.elemento[k][j];
            }
            mResp->elemento[i][j] = resultado;
        }
    }

    return *mResp;
}

Matriz &operator+(const Matriz &m1, const Matriz &m2)
{
    int f;
    int c;
    if ((m1.fila == m2.fila) && (m1.columna == m2.columna))
    {
        f = m1.fila;
        c = m2.columna;
    }
    else
    {
        cout << "No se pueden sumar las matrices, no tienen la misma dimension " << endl;
    }

    Matriz *mSuma = new Matriz(f, c);

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mSuma->elemento[i][j] = m1.elemento[i][j] + m2.elemento[i][j];
        }
    }

    cout << endl;

    return *mSuma;
}

Matriz &operator-(const Matriz &m1, const Matriz &m2)
{
    int f;
    int c;
    if ((m1.fila == m2.fila) && (m1.columna == m2.columna))
    {
        f = m1.fila;
        c = m2.columna;
    }
    else
    {
        cout << "No se pueden restar las matrices, no tienen la misma dimension " << endl;
    }

    Matriz *mResta = new Matriz(f, c);

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mResta->elemento[i][j] = m1.elemento[i][j] - m2.elemento[i][j];
        }
    }

    cout << endl;

    return *mResta;
}

Matriz &operator*(const int &escalar, const Matriz &m)
{
    int fil;
    int col;
    fil = m.fila;
    col = m.columna;

    Matriz *RespEscalar = new Matriz(fil, col);

    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            RespEscalar->elemento[i][j] = (escalar) * (m.elemento[i][j]);
        }
    }
    cout << endl;

    return *RespEscalar;
}

void Matriz::gauss_jordan()
{
    int n;
    float temp, pivote;
    cout << "Ingrese el numero de incognitas: ";
    cin >> n;

    Matriz *Ecuacion = new Matriz(n, n + 1);
    float Solucion[n];

    cout << "Ingrese los elementos de la matriz aumentada fila a fila: ";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> Ecuacion->elementos[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (Ecuacion->elementos[i][i] < Ecuacion->elementos[k][i])
                for (int j = 0; j < n; j++)
                {
                    temp = Ecuacion->elementos[i][j];
                    Ecuacion->elementos[i][j] = Ecuacion->elementos[k][j];
                    Ecuacion->elementos[k][j] = temp;
                }

    for (int i = 0; i < n - 1; i++)
        for (int k = i + 1; k < n; k++)
        {
            pivote = (Ecuacion->elementos[k][i] / Ecuacion->elementos[i][i]);
            for (int j = 0; j < n + 1; j++)
                Ecuacion->elementos[k][j] = Ecuacion->elementos[k][j] - pivote * Ecuacion->elementos[i][i];
        }

    cout << "\n Matriz aumentada despues de aplicar eliminacion gaussiana: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << Ecuacion->elementos[i][j] << "\t";
        cout << endl;
    }
    // sustitucion hacia atras

    for (int i = n - 1; i >= 0; i--)
    {
        Solucion[i] = Ecuacion->elementos[i][n];
        for (int j = i + 1; j < n; j++)
            if (j != i)
                Solucion[i] = Solucion[i] - Ecuacion->elementos[i][j] * Solucion[j];
        Solucion[i] = Solucion[i] / Ecuacion->elementos[i][i];
    }

    cout << "Las Soluciones del sistema son: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "X" << i << " = " << Solucion[i] << endl;
    }
}