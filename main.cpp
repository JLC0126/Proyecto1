#include"Matriz.hpp"

#include<iostream>
using namespace std;

#include <chrono>
using namespace::chrono;

int main(){

    Matriz matriz1(3,3), matriz2(3,3),matrizResultado;
    matriz1.llenar_matriz();
    cout<<"Matriz1: "<<endl;
    matriz1.mostrar_matriz();
    cout<<endl;

    matriz2.llenar_matriz();
    cout<<"matriz2: "<<endl;
    matriz2.mostrar_matriz();
    cout<<endl;


    cout<<"Multiplicando matriz1 con matriz2: "<<endl;

    auto inicio = high_resolution_clock::now();
    matrizResultado= matriz1 - matriz2;
    auto final = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(final - inicio);
    cout<<"Tiempo de ejecucion del calculo mult es:" <<duration.count()<<" mcs"<<endl;
    
    matrizResultado.mostrar_matriz();
    
 
    return 0;
}
