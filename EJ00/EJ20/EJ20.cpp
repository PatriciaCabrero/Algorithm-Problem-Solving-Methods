// VJ04, Patricia Cabrero Villar
/*
 Se almacenan los agujeros de la manguera de menor a mayor (orden dado por el enunciado) en un vector.
 Se recorrerá el vector poniendo en el primer agujero un parche y inicializando el valor de fin que
 representará el final del parche si los siguientes agujeros que visitamos son menores que fin se
 continuará, sino es así se añade un nuevo parche y se actualiza la variable fin.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

// El coste será O(N) siendo N el número de agujeros de la manguera, correspondiente a recorrer el vector.
int resolver(std::vector<int> const & v, int L) {
	int ini,fin, numParches=1;
	ini = v[0];
	fin = v[0] + L;
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] > fin)
		{
			numParches++;
			ini = v[i];
			fin = v[i] + L;
		}
	}
	return numParches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nA, L;
	std::cin >> nA >> L;
	if (!std::cin)return false;

	std::vector<int> manguera(nA);
	for (int i = 0; i < nA; i++)
	{
		std::cin >> manguera[i];
	}
	
	//Resuelve el problema

	int sol = resolver(manguera, L);

	// escribir sol
	std::cout << sol << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ20/datos20.txt");
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
