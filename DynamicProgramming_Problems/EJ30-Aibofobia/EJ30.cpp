// VJ04, Patricia Cabrero Villar
/*
 Aibofobia
 Se busca el número de letras mínimo que hay que insertar en una palabra para convertirla
 en palíndroma. Se resolverá con programación dinámica
                    pal(i + 1, j - 1)           si pi = pj
 pal(i, j) = 
                    min(pal(i,j-1), pal(i+1,j)) + 1  si i ≤ j
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
//#include "Matriz.h"

using namespace std;

// COSTE O(n^2) en tiempo y O(n) en espacio
void resolver(string const& P, int & valor) {
    int ant = 0;
    size_t n = P.size();
    std::vector<int> prueba(n+1,0);
    size_t i,j;
    for (size_t d = n-1; d >= 1; --d, ant = 0) //FILA QUE VOY A RECORRER
        for (i = d, j = d+1; j <= n; ++j) {
            int temp = ant;
            ant = prueba[j];
            if (P[i-1] == P[j-1])
                prueba[j] = temp;
            else
                prueba[j] = min(prueba[j-1], prueba[j]) + 1;
        }
    valor = prueba[n];
    /*  Matriz<int> tabla(n+1, n+1, 0);
     
     size_t i, j;
     // Rellenar la tabla en diagonal
     for (size_t d = 1; d <= n-1; ++d) // recorre diagonales
     for (i = 1, j = i + d; i <= n - d; ++i, ++j) {
     if (P[i-1] == P[j-1])
     tabla[i][j] = tabla[i+1][j-1];
     else
     tabla[i][j] = min(tabla[i][j-1], tabla[i+1][j]) + 1;
     }
     valor = tabla[1][n];*/
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string palindromo;
    std::cin >> palindromo;
    if (!std::cin) return false;
    
    //Resuelve el problema
    int sol;
    resolver(palindromo,sol);
    
    // escribir sol
    std::cout<< sol << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ30-Aibofobia/datos30.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    while (resuelveCaso())
        ;
    
    // Para restablacer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

