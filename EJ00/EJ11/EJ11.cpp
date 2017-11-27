// VJ04, Patricia Cabrero Villar
// Buscamos detectar si un grafo es arborescencia o no.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "GrafoDirigido.h"


/* El coste O(2*(V+E)) será recorrer el grafo y realizar un dfs(V+E) con el posible candidato si hay dos o más
 se pararía ya que sería inconexo.
 Detecta si un grafo es arborescencia y si lo es almacena la raiz.
*/
class Arborescencia {
public:
	Arborescencia(GrafoDirigido const& G) : marked(G.V(), false), grado(G.V(), 0), arborescencia(true), raiz(-1){
        
        //Recorremos el grafo para saber el grado de cada vertice
        // Coste V+E
        for(auto v = 0; arborescencia && v < G.V(); v++){
            for (auto w : G.adj(v)) {
                grado[w]++;
                if (grado[w] > 1) // Hay un vertice con dos aristas apuntándole con lo que no es arborescencia, terminamos
                    arborescencia = false;
            }
        }
        
        // Coste V+E
        int numCand=0;
        for (auto w = 0; arborescencia && w < grado.size(); w++) {
            if(grado[w] == 0){ // CANDIDATO
                ++numCand;
                if(numCand > 1) //Si hay mas de un candidato a raiz es inconexo con lo que no es arborescencia
                    arborescencia = false;
                else{
                    int aux = 0;
                    dfs(G, w, aux);
                    if (aux == G.V()) {
                        raiz = w;
                    }
                }
            }
        }
        if (raiz == -1) {
            arborescencia = false;
        }
	}

    bool isArbores(int & raizD) const {
        raizD = raiz;
        return arborescencia;
    };
    
private:
	std::vector<bool> marked;        // marked[v] = ¿se ha alcanzado a v en el dfs?
	std::vector<int> grado;       // onStack[v] = ¿está el vértice v en la pila?
	bool arborescencia;
    int raiz;
    
	void dfs(GrafoDirigido const& G, size_t v, int &tam) {
        ++tam;
        marked[v] = true;
		for (auto w : G.adj(v)) {
			if (!arborescencia) // si no es arborescencia terminamos
				return;
			else if (!marked[w]) { // encontrado un nuevo vértice, seguimos
				dfs(G, w, tam);
			}else if(marked[w])     //si ya estaba marcado tiene dos aristas apuntando al mismo vértice
                arborescencia = false;
		}
	}
};

//  Coste O(2*(V+E))
bool resolver(GrafoDirigido const& datos, int & raiz) {
	Arborescencia prueba(datos);
	return prueba.isArbores(raiz);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nV, nA, aux, aux1;
	std::cin >> nV >> nA;
	if (!std::cin)return false;

	GrafoDirigido arborescencia(nV);                    // Coste O(nV)
	for (int i = 0; i < nA; i++)
	{
		std::cin >> aux >> aux1;
		arborescencia.ponArista(aux, aux1);
	}                                   // Coste O(nA)
	
	//Resuelve el problema
    int raiz;
	bool sol = resolver(arborescencia, raiz);
	
	// escribir sol
	if (sol)
		std::cout << "SI "<<raiz << "\n";
	else
		std::cout << "NO\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ11/datos11.txt");
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
