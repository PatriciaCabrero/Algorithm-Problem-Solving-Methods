// VJ04, Patricia Cabrero Villar
/*  Se crea una clase instrumento donde se almacena un int para los musicos
    totales con ese instrumento, el número de partituras asignadas y el grupo
    mayor que corresponde a una partitura. Además tiene un método añade partitura
    que recalculará la variable grupo cuando se sume una partitura. Con esta clase
    se crea una cola de prioridad que como operador antes utilizará las variables
    de los grupos que posee la clase instrumento. De esta manera una vez repartidas
    las partituras el que este situado en la cima de la cola será el grupo que más
    músicos tenga alrededor de una partitura.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

#include "PriorityQueue.h"
#include "Instrumento.h"

//Se cambia el operador menor para que sea una cola de prioridad ordenada de mayor a menor
class antes{
public:
    bool operator () (Instrumento a, Instrumento b){
        return a.grupo > b.grupo;
    }
};

// Dado una cola de prioridad se devuelve atril con más músicos.
// El coste será N*log N al meter los N grupos de instrumentos al inicio en la cola de prioridad.
// Dado que se asgura que hay una partitura para cada grupo de instrumentos el bucle que las asigna dará
// k vueltas = partituras - colaPrioridad.size(), en este bucle se realizará un pop, top y push siendo el coste k*logN

// El coste total será O(N*log N + k*log N)

int resolver(PriorityQueue<Instrumento, antes> & colaPrioridad, int partituras) {
    partituras -= colaPrioridad.size();
    Instrumento sol;
    for (int i = 0; i < partituras; i++) {
        colaPrioridad.pop(sol);
        sol.sumaPartitura();
        colaPrioridad.push(sol);
    }
    sol=colaPrioridad.top();
    return sol.grupo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux, musicos, partituras;
    aux = musicos = partituras = 0;
    std::cin >> partituras>>aux;
    
    if (!std::cin)
        return false;

    
    //Recibe la entrada y la mete en una cola de prioridad
    PriorityQueue<Instrumento,antes> colaPrioridad;
    Instrumento inst;
    for (int i = 0; i<aux; i++) {
        std::cin >> musicos;
        inst.set(musicos);
        colaPrioridad.push(inst);
    }
    
    int sol = resolver(colaPrioridad,partituras);
    // escribir sol
    Instrumento escribir;
    size_t tam = colaPrioridad.size();
    //std::cout <<"ESCRIBE COLA ";
    for (int i = 0; i<tam; i++) {
        colaPrioridad.pop(escribir);
        //std::cout << escribir.grupo<< " ";
    }
    //std::cout<< "\n";
    std::cout << sol << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ08/datos8.txt");
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


