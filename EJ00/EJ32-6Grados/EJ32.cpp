// VJ04, Patricia Cabrero Villar
/*
SEIS GRADOS DE SEPARACIÓN

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

const int INF = 1000000000;
// COSTE O(n^2) en tiempo y O(2n) en espacio
int Floyd(Matriz<int> const& G, Matriz<int> & C,
           Matriz<size_t> & camino) {
    size_t n = G.numfils() - 1;
    // inicialización
    C = G;
    camino = Matriz<size_t>(n+1,n+1,0);
    // actualizaciones de la matriz
    for (size_t k = 1; k <= n; ++k)
        for (size_t i = 1; i <= n; ++i)
            for (size_t j = 1; j <= n; ++j) {
                int temp = C[i][k] + C[k][j];
                if (temp < C[i][j]) { // es mejor pasar por k
                    C[i][j] = temp;
                    camino[i][j] = k;
                }
            }
    int valor = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j < n; j++) {
            if(valor<C[i][j])
                valor=C[i][j];
        }
    }
    return valor;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
    size_t V;
    cin >> V;
    if (!cin) return false;
    size_t E;
    cin >> E;
    
    Matriz<int> grafo(V+1,V+1,INF);
    for (size_t i = 1; i <= V; ++i)
        grafo[i][i] = 0;
    size_t u, v;
    for (size_t i = 1; i <= E; ++i) { // leer aristas
        cin >> u >> v ;
        grafo[u][v] = 1;
        grafo[v][u] = 1;
    }
    Matriz<int> C(0,0); Matriz<size_t> camino(0,0);
    int sol = Floyd(grafo, C, camino);
    if(sol==0)cout<<"DESCONECTADO"<<endl;
    else cout<<sol<< endl;
    //imprimir_caminos(C, camino);
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ32-6Grados/datos32.txt");
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
