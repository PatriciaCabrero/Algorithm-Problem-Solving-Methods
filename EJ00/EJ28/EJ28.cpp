// VJ04, Patricia Cabrero Villar
/*
 El cazatesoros
 Se busca el número máximo de oro que podemos ganar con el oxígeno de la botella.
 Se almacenarán las soluciones recursivas en una matriz solución.
                    tesoro(i − 1, j)            si pi > j
 tesoro(i, j) = 
                    máx{tesoro(i − 1, j), tesoro(i − 1, j − pi) + vi}   si pi ≤ j
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
struct tesoro{
	int profundidad;
	int oro;
	int tiempo;
	void actTiempo(){
		tiempo = profundidad * 3;
	}
};
// COSTE O(nM) tanto en espacio como en tiempo
// No se optimiza más el espacio ya que queremos saber los cofres que se recogerán.
void resolver(vector<tesoro> const& P, int T,
                int & valor, vector<bool> & cuales, int & cuantos) {
    size_t n = P.size()-1;
    Matriz<int> tesoros(n+1, T+1, 0);
    // rellenar la matriz
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (P[i].tiempo > j)
                tesoros[i][j] = tesoros[i-1][j];
            else
                tesoros[i][j] = max(tesoros[i-1][j],
                                    tesoros[i-1][j - P[i].tiempo] + P[i].oro);
        }
    }
    valor = tesoros[n][T];
    cuantos = 0;
    // cálculo de los objetos
    int resto = T;
    for (size_t i = n; i >= 1; --i) {
        if (tesoros[i][resto] == tesoros[i-1][resto]) {
            // no cogemos objeto i
            cuales[i] = false;
        } else { // sí cogemos objeto i
            cuantos++;
            cuales[i] = true;
            resto = resto - P[i].tiempo;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int T, cofres;
	std::cin >> T >> cofres;
	if (!std::cin) return false;

	std::vector<tesoro> bTesoro(cofres+1);
	for (int i = 1; i <= cofres; i++)
	{
		std::cin >> bTesoro[i].profundidad >> bTesoro[i].oro;
		bTesoro[i].actTiempo();
	}
    
    
	//Resuelve el problema
    int sol, cuantos;
    vector<bool> cuales(cofres);
    resolver(bTesoro, T, sol, cuales, cuantos);
    
    // escribir sol
    std::cout<< sol << endl << cuantos << endl;
    for (int i = 1; i <= cofres; i++) {
        if (cuales[i]) {
            std::cout<< bTesoro[i].profundidad <<" "<< bTesoro[i].oro << endl;
        }
    }
    std::cout<< "----"<< endl;

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ28/datos28.txt");
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
