#include"Matriz.hpp"

#include<cstdlib>

#include<iostream>
using namespace std;

Matriz::Matriz(){

    asignarElemento();
    for (int i = 0; i < fila; ++i) {
        for (int j = 0; j < columna; ++j) {
            elemento[i][j] =0;
        }
    }
    srand(time(0));
}

Matriz::Matriz(int f, int c){
    fila=f;
    columna=c;
    srand(time(0));
    llenar_matriz(f,c);
}

void Matriz::asignarElemento()
{
    elemento = new double*[fila];
    for (int i = 0; i < fila; ++i) {
        elemento[i] = new double[columna];
    }
}

void Matriz::llenar_matriz(int f1, int c1){

    for(int i=0;i<f1;i++){
        for(int j=0;j<c1;j++){
            elemento[i][j]=rand()%10;
            } 
    }
}

void Matriz::mostrar_matriz(Matriz M){

    for(int i=0;i<M.fila;i++){
        for(int j=0;j<M.columna;j++){
           cout<<"\t"<< elemento[i][j];

        }
        cout<<"\n";
       
    }
}

Matriz Matriz::multiplicar(Matriz a, Matriz b){
    Matriz respuesta(a.fila,b.columna);
  for(int i=1; i<=respuesta.fila; i++){
    for(int j=1; j<=respuesta.columna; j++){

    respuesta.elemento[i][j]=0;
    {            
    for (int k=0; k<=respuesta.columna; k++)
       respuesta.elemento[i][j] += a.elemento[i][k]*b.elemento[k][j];
    }
  }
  }
  
  return respuesta;
  mostrar_matriz(respuesta);
}
