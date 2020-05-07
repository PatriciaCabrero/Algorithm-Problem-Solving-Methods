// VJ04, Patricia Cabrero Villar

// Construye un árbol AVL a partir de la entrada y después calcula el k-ésimo elemento
// El método recibe un entero de consulta y tiene un auxiliar que lleva la cuenta de los tam_i.
// Se llama recursivamente al hijo derecho o al izquierdo dependiendo de si la consulta es mayor
// o menor que el auxiliar, actualizándolo en cada vuelta. Cuando es igual devuelve la clave.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

#include "TreeMap_AVL.h"


// dado un árbol AVL, calcula el k-ésimo elemento
// logarítmico en el número N de nodos del árbol, log(N)
int resolver(map<int, int> & arbol, int const consulta) {
    return arbol.findk(consulta);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux, valor, consultas;
    std::cin >> aux;
    if (aux == 0)
        return false;
    map<int, int> arbol;
    for (int i = 0; i<aux; i++) {
        std::cin >> valor;
        arbol.insert(valor);
    }
    std::cin >> consultas;
    for (int i = 0; i<consultas; i++) {
        std::cin >> valor;
        int sol = resolver(arbol, valor);
        // escribir sol
        if(sol == -1){
            std::cout <<"??";
        }else{
            std::cout << sol;
        }
        std::cout << "\n";
    }
    
    std::cout <<"----"<< "\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos4.txt");
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

