// VJ04, Patricia Cabrero Villar
/*
 Se almacenan los pesos de las personas en un vector y se ordena de menor a mayor, de esta manera
 intentaremos emparejar siempre al más pesado con el más flaco, sino caben juntos se reservará un
 telesilla para el más pesado(modificando únicamente el identificador fin) y si caben ambos se reservará
 uno para los dos(modificando ini y fin) y seguiremos recorriendo el vector tratando de emparejar de esta
 manera los pesos. Se parará la búsqueda cuando ini y fin sean iguales o ini mayor que fin (ya se han
 recorrido todas las posibilidades).
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


// El coste será la ordenación del vector de personas esperando al telesilla N log N, más N en el peor
// caso que todas las personas necesiten un telesilla para ellos solos. Siendo N el número de personas.
// Coste total O(N log N + N)
int resolver(std::vector<int> const & v, int P) {
    int ini = 0, fin=v.size() - 1;
    int telesillas = 0;
    while (ini < fin)
    {
        if (v[fin] >= P || v[fin] + v[ini] > P){
            fin--;
        }
        else{
            ini++;
            fin--;
        }
        telesillas++;
    }
    if (ini == fin)telesillas++;
    return telesillas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int peso, nU;
    std::cin >> peso >> nU;
    if (!std::cin)return false;
    
    std::vector<int> telesilla(nU);
    int aux;
    for (int i = 0; i < nU; i++)
    {
        std::cin >> telesilla[i];
    }
    //COSTE N log N
    std::sort(telesilla.begin(), telesilla.end());
    //Resuelve el problema
    
    int sol = resolver(telesilla, peso);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ21/datos21.txt");
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
