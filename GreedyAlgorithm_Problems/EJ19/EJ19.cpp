// VJ04, Patricia Cabrero Villar
/*
 Se almacenan los precios de los libros de mayor a menor en un vector.
 Se calcula el número de packs de tres que podemos hacer con los libros que tenemos, con este número
 recorreremos las posiciones correspondientes al libro más barato de cada pack. Se escogerán los libros
 de manera que siempre escojamos los tres más caros juntos, según avanzamos por el vector.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

// El coste será O(N log N + N/3) siendo N el número de libros.
// N log N coste de ordenar el vector y N/3 será el número de llamadas del bucle for.
int resolver(std::vector<int> const & v) {
    int descuento=0;
    int nLib = v.size() / 3;
    for (int i = 1; i <= nLib ; i++) {
        descuento += v[i*3 - 1];
    }
    return descuento;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nL;
    std::cin >> nL;
    if (!std::cin)return false;
    
    std::vector<int> libros(nL);
    for (int i = 0; i < nL; i++)
    {
        std::cin >> libros[i];
    }
   
    std::sort(libros.begin(), libros.end(),std::greater<int>());

    //Resuelve el problema
    
    int sol = resolver(libros);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ19/datos19.txt");
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
