// VJ04, Patricia Cabrero Villar
/*
 CARPINTERO
 Se busca que orden es el idóneo para cortar una tabla teniendo en cuenta que los cortes cuestan
 el doble de la longitud de la tabla.
 
                0          si pi = pj
 coste(i, j) = 
                min(i<k<j) (coste(i,k), coste(k,j)) + 2*(j-i)  si i ≤ j
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Matriz.h"

using namespace std;
const int INF = 1000000000;
// COSTE O(n^3) en tiempo y O(n^2) en espacio
void resolver(std::vector<int> const& mad, int & valor) {
    
    size_t n = mad.size();
    Matriz<int> tabla(n, n, 0);
    Matriz<size_t> P = Matriz<size_t>(n,n,0);

    // Rellenar la tabla en diagonal
    for (size_t d = 2; d <= n-1; ++d) // recorre diagonales
        for (size_t i = 0; i < n - d; ++i) { // recorre elementos de diagonal
            size_t j = i + d;
            // calcular mínimo
            tabla[i][j] = INF;
            for (size_t k = i+1; k < j; ++k) {
                int temp = tabla[i][k] + tabla[k][j] + 2*(mad[j]-mad[i]);
                if (temp < tabla[i][j]) { // es mejor pasar por k
                    tabla[i][j] = temp;
                    P[i][j] = k;
                }
            }
        }
    valor = tabla[0][n-1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int lmad, cortes;
    std::cin >> lmad >> cortes;
    if (lmad == 0 && cortes == 0) return false;
    std::vector<int> tabla(cortes+2);
    tabla[0]=0;
    tabla[cortes+1]=lmad;
    for (int i=1; i<=cortes; i++) {
        std::cin >> tabla[i];
    }
    //Resuelve el problema
    int sol=0;
    resolver(tabla,sol);
    
    // escribir sol
    std::cout<< sol << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ33-Carpintero/datos33.txt");
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
