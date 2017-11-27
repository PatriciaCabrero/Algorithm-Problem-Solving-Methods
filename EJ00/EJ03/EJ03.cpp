// VJ04, Patricia Cabrero Villar
// Construye un árbol AVL a partir de la entrada y después
// calcula los valores entre las claves k1 y k2
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

#include "TreeMap_AVL.h"
//#include "bintree_eda.h"


// dado un árbol AVL, calcula las claves entre min y max
// lineal en el número N de nodos del árbol, O(N)
std::vector<int> resolver(map<int, int> arbol, int const min, int const max) {
    return arbol.range(min, max);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioÌ n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux, max, min;
    std::cin >> aux;
    if (aux == 0)
        return false;
    map<int, int> arbol;
    for (int i = 0; i<aux; i++) {
        std::cin >> max;
        arbol.insert(max);
    }
    std::cin >> min >> max;
    std::vector<int> sol;
    sol= resolver(arbol, min, max);
    
    // escribir sol
    for (unsigned int i = 0; i < sol.size(); i++)
    {
        std::cout << sol[i] << " ";
    }
    std::cout << "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ03/datos3.txt");
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
