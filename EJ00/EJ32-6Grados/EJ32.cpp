// Grupo VJ04, Patricia Cabrero Villar
/*
	Se utiliza el algoritmo de Floyd para la búsqueda de los caminos mínimos entre dos puntos.
	La recursion utilizada es:
					0 si i = j
	G[i, j] =		coste si hay arista de i a j
					+∞ si no hay arista de i a j

	COSTE
		C^k(k, j) = mín{Ck−1(k, j),Ck−1(k, k) + Ck−1(k, j)}
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "Matriz.h"

using namespace std;
const int INF = 1000000000;
// función que resuelve el problema
//Θ(n^3) en tiempo y Θ(1) en espacio adicional.
void Floyd( Matriz<int> & C) {
	size_t n = C.numfils()- 1;
	// inicialización
	// actualizaciones de la matriz
	for (size_t k = 1; k <= n; ++k)
		for (size_t i = 1; i <= n; ++i)
			for (size_t j = 1; j <= n; ++j) {
				int temp = C[i][k] + C[k][j];
				if (temp < C[i][j]) { // es mejor pasar por k
					C[i][j] = temp;
				}
			}

}int buscaMax(Matriz<int> & C){
	int max = 0;
	for (size_t i = 1; i < C.numcols(); i++)
	{
		for (size_t j = i; j < C.numcols(); j++)
		{
			if (C[i][j] > max) max = C[i][j];
		}
	}
	return max;
}

bool resuelveCaso() {
	size_t V; 
	cin >> V;
	if (!cin) return false;
	size_t E; cin >> E;
	Matriz<int> grafo(V + 1, V + 1, INF);
	for (size_t i = 1; i <= V; ++i)
		grafo[i][i] = 0;
	string u, v;
	int identificador=1;
	std::unordered_map<string, int> amigos;
	for (size_t i = 1; i <= E; ++i) { // leer aristas
		std::cin >> u >> v;
		auto aux = amigos.insert(std::pair<string, int>{ u, identificador });
		if (aux.second)
			identificador++;
		auto aux1 = amigos.insert(std::pair<string, int>{ v, identificador });
		if (aux1.second)
			identificador++;
		grafo[aux.first->second][aux1.first->second] = 1;
		grafo[aux1.first->second][aux.first->second] = 1;

	}
	Floyd(grafo);
	int sol = buscaMax(grafo);
	if (sol<INF)
		std::cout << sol << endl;
	else
		std::cout << "DESCONECTADA" << endl;

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos33.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}