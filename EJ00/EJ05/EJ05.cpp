// VJ04, Patricia Cabrero Villar
// Construye una cola de prioridad, se van emparejando los menores de la cola para jugar cada partido
// Almacenando las gorras del equipo nuevo en gorrasEquipo y sumando las a las gorras repartidas en el torneo.
// Con cada partido se suprimen dos equipos de la cola y se introduce el nuevo como conjunto  de ambos.

// Queremos organizar una competición en la que participan N equipos, cada
//uno de los cuales cuenta inicialmente con Si seguidores, 1 ≤ i ≤ N. Cada vez
//que se juega un partido, el equipo que gana sigue compitiendo, y el perdedor
//desaparece de la competición. Se reparten gorras a todos en cada partido jugado
//y los perdedores pasan a ser del equipo ganador.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

#include "PriorityQueue.h"


// Dado una cola de prioridad se recorren los nodos
// y se añade el nuevo equipo.
// El coste de meter en la cola de prioridad N equipos en el inicio será N log N
// Por otra parte el coste del bucle será N*log N ya que hacemos top pop y push N veces siendo N el numero de equipos.
// En cada iteracion N será una unidad menor hasta estar la lista vacia.
// El coste total será O(N log N + N log N)


long int resolver(PriorityQueue<long int> colaPrioridad) {
    if(colaPrioridad.size() == 1){
        return 0;
    }else{

        long int gorrasEquipo, gorrasPartido;
        gorrasEquipo = gorrasPartido = 0;

        while (!colaPrioridad.empty()) {

            gorrasEquipo = colaPrioridad.top();
            colaPrioridad.pop();
            if(!colaPrioridad.empty()){
                gorrasEquipo += colaPrioridad.top();
                colaPrioridad.pop();
                colaPrioridad.push(gorrasEquipo);
                gorrasPartido += gorrasEquipo;
            }
        }
        return gorrasPartido;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux, valor;
    std::cin >> aux;
    if (aux == 0)
        return false;
    PriorityQueue<long int> colaPrioridad;
    
    for (int i = 0; i<aux; i++) {
        std::cin >> valor;
        colaPrioridad.push(valor);
    }

    long int sol = resolver(colaPrioridad);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ05/datos5.txt");
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
