// VJ04, Patricia Cabrero Villar
/*
 Los Broncos de Boston

 Se ordena el vector de los broncos de mayor a menor y el de los resultados contrarios de menor a
 mayor. Se irán emparejando los partidos en orden hasta que los resultados de los broncos no puedan
 superar al contrario.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>


// El coste será la ordenación de los vectores de partidos 2N log N, más N el caso que tengan todos
// los pares mejor puntuación los broncos. Siendo N el número de partidos.
// Coste total O(N log N + N)
int resolver(std::vector<int> const & b, std::vector<int> const & c) {
    int resultado = 0;
    int ini = 0;
    
    while (b[ini] >= c[ini] && ini < b.size())
    {
        resultado += b[ini] - c[ini];
        ini++;
    }
    
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int partidos;
    std::cin >> partidos;
    if (partidos==0)return false;
    
    std::vector<int> broncos(partidos);
    std::vector<int> contrarios(partidos);
    
    for (int i = 0; i < partidos; i++)
    {
        std::cin >> contrarios[i];
    }
    
    for (int i = 0; i < partidos; i++)
    {
        std::cin >> broncos[i];
    }

    //COSTE 2N log N
    std::sort(broncos.begin(), broncos.end(), std::greater<int>());
    std::sort(contrarios.begin(), contrarios.end());
    //Resuelve el problema
    
    int sol = resolver(broncos, contrarios);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ22/datos22.txt");
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
