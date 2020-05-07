// VJ04, Patricia Cabrero Villar
// Se utilizan dos colas de prioridad las cuales representan los menores y los mayores quedando almacenado
// el pajaro del medio en la cima de los menores. En la pila menor se modifica el comparador para que sea una cola de máximos.
// Según si la pareja que entra van los dos a un lado o se reparten se actualizarán ambas colas.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

#include "PriorityQueue.h"

class antes{
public:
    bool operator () (const int a, const int b){
        return a > b;
    }
};
class Pareja{
public:
    int a;//menor
    int b;//mayor
    void actualiza(){
        if(a > b){
            int aux = a;
            a=b;
            b=aux;
        }
    }
};
// Se utilizan dos colas de prioridad las cuales representan los menores y los mayores quedando almacenado
// el pajaro del medio en la cima de los menores. Según si la pareja que entra van los dos a un lado o se
// reparten se actualizarán ambas colas.
// Tenemos dos colas una con N elementos y otra con N+1=M, cada vez que insertamos una pareja tendremos dos
// opciones si corresponde que un miembro de una pareja va a una cola y el otro a la otra el coste será log N + log M
// en el peor caso los dos miembros irán a la misma cola haciendo necesario pasar el primer elemento a la cola opuesta
// con lo que se harán 2 push y un pop en la cola con M; y un push en N. Teniendo como coste logM + log N.
// A esta funcion se le llamará k numero de veces correspondientes a el numero de parejas que se unen.

//El coste total será k(logN + log M)

int resolver(PriorityQueue<int, antes> & menor, PriorityQueue<int> & mayor,Pareja a ) {
    int pajAct = menor.top();
    int aux;
    if(a.a < pajAct && a.b > pajAct){
        menor.push(a.a);
        mayor.push(a.b);
    }else if(a.a > pajAct && a.b > pajAct){
        mayor.push(a.a);
        mayor.push(a.b);
        mayor.pop(aux);
        menor.push(aux);
    }else{
        menor.push(a.a);
        menor.push(a.b);
        menor.pop(aux);
        mayor.push(aux);
    }
    return menor.top();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux, pajaro;
    std::cin >> pajaro >> aux;
    if (aux == 0 && pajaro == 0)
        return false;
    
    //Recibe la entrada y la mete en una cola de prioridad
    PriorityQueue<int, antes> menor;
    PriorityQueue<int> mayor;
    Pareja pareja;
    menor.push(pajaro);
    for (int i = 0; i < aux; i++) {
        std::cin >> pareja.a >> pareja.b;
        pareja.actualiza();
        int sol = resolver(menor, mayor, pareja);
        // escribir sol
        std::cout << sol << " ";
    }
    std::cout << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ07/datos7.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    while (resuelveCaso())
        ;
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

