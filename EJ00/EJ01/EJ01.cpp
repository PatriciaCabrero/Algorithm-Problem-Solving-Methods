// VJ04 Patricia Cabrero Villar
// Construye un árbol binario a partir de la entrada y después
// calcula si está equilibrado de forma recursiva
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "TreeMap_AVL.h"
#include "bintree_eda.h"

template <typename T>
bintree<T> leerArbol(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return{};
    }
    else { // leer recursivamente los hijos
        auto iz = leerArbol(vacio);
        auto dr = leerArbol(vacio);
        return{ iz, raiz, dr };
    }
}
// dado un árbol binario, calcula si está equilibrado
// lineal en el número N de nodos del árbol, O(N)
bool resolver(bintree<char> arbol, int & altura) {
    if(arbol.empty())return true;
    else{
        int altdch=altura, altizq=altura; //auxiliares
        
        if(resolver(arbol.left(), altizq)){
            altizq++;
            if(resolver(arbol.right(), altdch)){
                altdch++;
                altura = std::max(altizq, altdch);
                if(std::abs(altdch - altizq) <= 1)
                    return true;
            }
        }
    }
    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<char> arbol = leerArbol('.');
    
    // escribir sol
    int altura = 0;
    if (resolver(arbol, altura)) std::cout << "SI";
    else std::cout << "NO";
    std::cout << "\n";
    
    
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ01/datos1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

