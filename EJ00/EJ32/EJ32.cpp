// VJ04, Patricia Cabrero Villar
/*
 Subsecuencia común más larga
 Se busca subsecuencia común más larga en dos palabras. Se resolverá con programación dinámica
                    tabla(i-1,j-1)+1   si P1i == P2j
 tabla(i,j) =
                    max(tabla(i-1,j), tabla(i,j - 1) si i<n y j< m
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include "Matriz.h"
#include "Grafo.h"
using namespace std;

// COSTE O(n^2) en tiempo y O(2n) en espacio
void resolver(string const& P1,string const& P2, int & valor) {
    
    size_t n = P1.size();
    size_t m = P2.size();
    Matriz<int> subsec(2,n+1, 0);
    int i,j;
    // rellenar la matriz
    for (j = 1; j <= m; ++j)
        for (i = 1; i <= n; ++i) {
            if (P1[i-1] == P2[j-1])
                subsec[j%2][i] = subsec[abs(j%2-1)][i-1]+1;
            else
                subsec[j%2][i] = max(subsec[j%2][i-1], subsec[abs(j%2-1)][i]);
        }
    valor = subsec[abs(j%2 -1)][n];
    //CON TABLA PARA LA SOLUCION
    /*Matriz<int> tabla(n+1, m+1, 0);
     // rellenar la matriz
     for (int i = 1; i <= n; ++i) {
     for (int j = 1; j <= m; ++j) {
     if (P1[i-1] == P2[j-1])
     tabla[i][j] = tabla[i-1][j-1]+1;
     else
     tabla[i][j] = max(tabla[i-1][j], tabla[i][j - 1]);
     }
     }*/
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
    // leer los datos de la entrada
    int nV, nA;
    std::cin >> nV >> nA;
    if(!std::cin)return false;
    string aux,aux1;
    map<string, int> prueba;
    
    Matriz<int> saltos(nV+1,nV+1,0);
    int n = 1;
    for (int i = 0; i < nA; i++)
    {
        pair<std::map<string,int>::iterator,bool> sol;
        std::cin >> aux >> aux1;
        sol = prueba.emplace(aux,n);
            if(!sol.second)
                ++n;
        sol = prueba.emplace(aux1,n);
            if(!sol.second)
                ++n;
        saltos[prueba[aux]][prueba[aux1]]++;
    }
    
    // leer los datos de la entrada
    Matriz<string> a (2,2);
    string p1,p2;
    std::cin >> p1 >>p2;
    if (!std::cin) return false;
    
    //Resuelve el problema
    int sol;
    resolver(p1,p2,sol);
    
    // escribir sol
    std::cout<< sol << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ32/datos32.txt");
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
