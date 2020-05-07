// VJ04 Patricia Cabrero Villar
// Lee un árbol y calcula su altura de manera recursiva

#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

// lee un árbol binario de la entrada estándar
template <typename T>
bintree<T> leerArbol(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    } else { // leer recursivamente los hijos
        auto iz = leerArbol(vacio);
        auto dr = leerArbol(vacio);
        return {iz, raiz, dr};
    }
}

// dado un árbol binario, calcula su altura
// lineal en el número N de nodos del árbol, O(N)
unsigned int altura(bintree<char> const& arbol) {
    if (arbol.empty())
        return 0;
    else
        return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}
// resuelve un caso de prueba
void resuelveCaso() {
    auto arbol = leerArbol('.');
    int sol = altura(arbol);
    std::cout << sol << "\n";
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/datos1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
