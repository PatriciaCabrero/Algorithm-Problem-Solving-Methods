// VJ04 Patricia Cabrero Villar
/*
 Problema que devuelve el camino mínimo de un punto a otro de una matriz.
 Primero se recorre la matriz para almacenar la entrada y la meta, y se detectan los
 sensores marcándolos en el vector las casillas correspondientes teniendo en
 cuenta los muros. Si la entrada y la salida no están vigiladas por un sensor
 hago una búsqueda en anchura desde la entrada hasta llegar a la meta.
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

#define INFINITO 10000000
using Mapa = std::vector<std::string>;
const std::pair <int,int> dirs[4] = {{-1,0},{0,1},{1,0},{0,-1}};

//El coste es constante 2*F*C por recorrerlas todas dos veces la primera para leer la matriz y la segunda para hacer la búsqueda en anchura
class CaminosMinimos{
public:
    
    CaminosMinimos(Mapa const& g): F(g.size()), C(g[0].size()), marcado(F, std::vector<bool>(C,false)), distTo(F, std::vector<int>(C,INFINITO)){
        leerMatriz(g);
        if(!marcado[entrada.first][entrada.second] && !marcado[salida.first][salida.second]){
            distTo[entrada.first][entrada.second] = 0;
            bfs(g, entrada);
        }
    }
    
    int camino() const{
        return distTo[salida.first][salida.second];
    }
private:
    int F, C;
    std::pair <int,int> entrada, salida;
    std::vector<std::vector<bool>> marcado;
    std::vector<std::vector<int>> distTo;
    void bfs(Mapa const& g, std::pair<int,int> s){
        bool encontrado = false;
        std::queue<std::pair<int, int>> cola;
        marcado[s.first][s.second] = true; // Mark the source
        cola.push(s); // and put it on the queue.
        
        while (!cola.empty() && !encontrado)
        {
            std::pair<int, int> v = cola.front();
            cola.pop(); // Remove next vertex from the queue.
            for (auto w : dirs){
                std::pair<int, int> nPos;
                nPos.first = v.first + w.first;
                nPos.second = v.second + w.second;
                if(nPos.first >=0 && nPos.second >= 0 && nPos.first < F && nPos.second < C &&
                   !marcado[nPos.first][nPos.second] && g[nPos.first][nPos.second] !='#'){
                    
                    distTo[nPos.first][nPos.second] = distTo[v.first][v.second] + 1;
                    marcado[nPos.first][nPos.second] = true;
                    cola.push(nPos);
                }
                if(nPos == salida){
                    encontrado = true;
                    break;
                }
            }
        }
    }
    
    void leerMatriz(Mapa const& g){
        for(int i = 0 ; i < F ; ++i){
            for (int j = 0 ; j < C; ++j){
                //Encontramos la entrada
                if (g[i][j] == 'E'){
                    entrada.first = i;
                    entrada.second = j;
                }
                //Encontramos la salida
                else if (g[i][j] == 'P'){
                    salida.first = i;
                    salida.second = j;
                }
                //Encontramos sensor y cambiamos el vector de marcados
                else if(g[i][j] != '#' && g[i][j] != '.'){
                    marcado[i][j] = true;
                    
                    int tamSensor = g[i][j]-'0';
                    for (auto d : dirs){
                        for (int k = 1; k <= tamSensor ; k++) {
                            int ni = i + k * d.first;
                            int nj = j + k * d.second;
                            if(ni >= 0 && ni < F && nj < C && nj >= 0){
                                if(g[ni][nj] == '#'){
                                    break;
                                }else{
                                    marcado[ni][nj] = true;
                                }
                            }else break;
                        }
                    }
                }
            }
        }
    }
    
};

void resuelveCaso(){
    int F,C;
    std::cin >> C >> F;
    
    std::cin.ignore(1); //quita salto de linea
    Mapa matriz(F);
    for (int i=0; i < F; ++i){
        std::getline(std::cin, matriz[i]);
    }
    CaminosMinimos freeLove(matriz);
    int solucion = freeLove.camino();
    if(solucion == INFINITO){
        std::cout << "NO" << "\n";
    }else
        std::cout << solucion<<"\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ12/datos12.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
   int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
