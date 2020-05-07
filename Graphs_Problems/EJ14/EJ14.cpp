// VJ04 Patricia Cabrero Villar
/*
 Problema que devuelve la mancha de petróleo más grande. Se traduce la matriz de petroleo en conjuntos
 disjuntos con lo que una vez generado si aparecen nuevas manchas solo tendremos que unir una mancha a
 otra
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
#include <cstdlib>
#include "ConjuntosDisjuntos.h"

#define INFINITO 10000000
using Mapa = std::vector<std::string>;
const std::pair <int,int> dirs[8] = {{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};

//El coste es constante F*C por recorrerlas todas dos veces la primera para leer la matriz y la segunda para hacer la búsqueda en anchura
class Petroleo{
public:
    Petroleo(Mapa const& g): F(g.size()), C(g[0].size()), marcado(F, std::vector<bool>(C,false)), conDis(g.size()*g[0].size()), petroleo(F, std::vector<bool>(C,false)),manchaMax(0){
        int tam = 1;
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if (!marcado[i][j] && g[i][j]=='#') {
                    petroleo[i][j] = true;
                    int padre = valoresMatriztoGrafo(i, j);
                    dfs(g,i,j,tam, padre);
                    if (manchaMax<tam) {
                        manchaMax = tam;
                    }
                    tam = 1;
                }
            }
        }    }
    
    int maximo() const{
        return manchaMax;
    }
    void nuevaMancha(int i, int j){
        petroleo[i][j]=true;
        int num = valoresMatriztoGrafo(i, j);
        for (auto d : dirs){
            int ni = i + d.first;
            int nj = j + d.second;
            int q = valoresMatriztoGrafo(ni, nj);
            if( 0 <= ni && ni < F && nj >= 0 && nj < C && petroleo[ni][nj]){
                conDis.unir(q,num);
            }
        }
        if (conDis.size(num)>manchaMax) {
            manchaMax = conDis.size(num);
        }
    }
private:
    ConjuntosDisjuntos conDis;
    int F, C;
    std::vector<std::vector<bool>> marcado;
    std::vector<std::vector<bool>> petroleo;
    int manchaMax;

    
    void dfs(Mapa const& g, int i, int j, int &tam, int padre){
        marcado[i][j] = true;
        petroleo[i][j] = true;
        for (auto d : dirs){
            int ni = i + d.first;
            int nj = j + d.second;
            if(0 <= ni && ni < F && nj >= 0 && nj < C && g[ni][nj] == '#' && !marcado[ni][nj]){
                tam++;
                int q = valoresMatriztoGrafo(ni, nj);
                dfs(g,ni,nj,tam, padre);
                conDis.unir(padre,q);
            }
        }
    }
    
    int valoresMatriztoGrafo(int i, int j){
        return i*C+j;
    }
};

bool resuelveCaso(){
    int F,C;
    std::cin >> F >> C;
    if(!std::cin) return false;
    
    std::cin.ignore(1); //quita salto de linea
    Mapa matriz(F);
    for (int i=0; i < F; ++i){
        std::getline(std::cin, matriz[i]);
    }
    Petroleo solucion(matriz);
    std::cout << solucion.maximo() << " ";
    int numManchas,i,j;
    std::cin >> numManchas;
    for (int t=0; t<numManchas; t++) {
        std::cin >> i >> j;
        solucion.nuevaMancha(i-1,j-1);
        std::cout << solucion.maximo() << " ";
    }
    std::cout << std::endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ14/datos14.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
