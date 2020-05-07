// VJ04 Patricia Cabrero Villar
/*
 El problema consiste en pavimentar BarroCity con un coste mínimo de manera que una
 todas las intersecciones de la ciudad. Para resolver este problema se crea un grafo
 valorado que representará las intersecciones y sus distancias, se implementará el
 algoritmo de Prim obteniendo el árbol de recubrimiento mínimo y por tanto sabremos
 si es posible pavimentarla de esta manera y su coste.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "GrafoValorado.h"
#include "IndexPQ.h"

#define INFINITO 10000000

/*
 El coste será O(V(E log V)) donde E es el número de aristas o uniones entre
 localizaciones de barrocity y V el número de vértices o intersecciones de barrocity.
 Se hace como mucho V llamadas en el bucle principal a Visit que hará E llamadas
 totales por el coste de update log V.
*/
class primsMethod{
public:
    primsMethod(GrafoValorado<int> const& G): distTo(G.V(), INFINITO), marked(G.V(),false),pq(G.V()), edgeTo(G.V()), coste(0), marcados(0){
        distTo[0] = 0.0;
        pq.push(0, 0.0); // Initialize pq with 0, weight 0.
        numLlamadas = 0;
        while (!pq.empty()){
            numLlamadas++;
            auto aux = pq.top();
            pq.pop();
            visit(G, aux.elem); // Add closest vertex to tree.
        }
        if (marcados < G.V()) {
            coste = -1;
        }
    }
    int costePavimentar(){
        return coste;
    }
private:
    std::vector<Arista<int>> edgeTo;// shortest edge from tree vertex
    std::vector<int> distTo; // distTo[w] = edgeTo[w].weight()
    std::vector<bool> marked; // true if v on tree
    IndexPQ<int> pq; // eligible crossing edges
    int coste;
    int marcados;
    int numLlamadas;
    
    void visit(GrafoValorado<int> const& G, int v)
    {
        // Add v to tree; update data structures.
        marked[v] = true;
        marcados++;
        for ( auto e : G.adj(v))
        {
            int w = e.otro(v);
            if (marked[w]) continue; // v-w is ineligible.
            if (e.valor() < distTo[w])
            {
                if (distTo[w] != INFINITO)
                    coste -= distTo[w];
                coste+=e.valor();
                // Edge e is new best connection from tree to w.
                edgeTo[w] = e;
                distTo[w] = e.valor();
                pq.update(w, distTo[w]);
            }
        }
    }
};

bool resuelveCaso(){
    int V,E;
    std::cin >> V >> E;
    if (!std::cin) {
        return false;
    }
    
    GrafoValorado<int> grafo(V);                            // Coste O(nV)
    int A, B, valor;
    for (int i=0; i < E; ++i){
        std::cin >> A >> B >> valor;
        Arista<int>aux(A-1, B-1, valor);
        grafo.ponArista(aux);
    }                                                       // Coste O(nE)
    
    //Resolver el problema
    primsMethod Solucion(grafo);
    if(Solucion.costePavimentar()==-1)
        std::cout << "Imposible" <<"\n";
    else
        std::cout << Solucion.costePavimentar() << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ15/datos15.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while(resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
