// VJ04, Patricia Cabrero Villar
// Construye una cola de prioridad.
// Busca el primer usuario suscrito y en cada consulta aumenta el periodo
// de este usuario de manera que reciba en el siguiente periodo su notificacion

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

#include "PriorityQueue.h"
#include "Usuario.h"

class antes{
public:
    bool operator () (const Usuario a, const Usuario b){
        if(a.periodo < b.periodo){
            return true;
        }else if(a.periodo > b.periodo)
            return false;
        else
            return a.usuario < b.usuario;
    }
};

// Dado una cola de prioridad se devuelve el primero que recibirá un mensaje.
// Y se suma de nuevo su periodo para que continue suscrito.
// El coste de añadir a la cola inicialmente N suscriptores será N*log N.
// Después se realizará un bucle con el número de consultas a realizar k, llamando
// al método resolver que llama una vez a top, pop y push teniendo coste k*log N
// Coste total O(N log N + K log N)
long int resolver(PriorityQueue<Usuario, antes> & colaPrioridad) {
    Usuario sol;
    colaPrioridad.pop(sol);
    sol.sumaPeriodo();
    colaPrioridad.push(sol);
    return sol.usuario;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int aux, usuario, periodo;
    std::cin >> aux;
    if (aux == 0)
        return false;
    
    //Recibe la entrada y la mete en una cola de prioridad
    PriorityQueue<Usuario, antes> colaPrioridad;
    Usuario auxUsuario;
    for (int i = 0; i<aux; i++) {
        std::cin >> usuario >> periodo;
        auxUsuario.setUsuarioPeriodo(usuario, periodo);
        colaPrioridad.push(auxUsuario);
    }
    
    //Realiza el numero de consultas a resolver.
    int numconsultas;
    std::cin >> numconsultas;
    for (int i=0; i<numconsultas; i++) {
        long int sol = resolver(colaPrioridad);
        // escribir sol
        std::cout << sol << "\n";
    }
    std::cout <<"----"<< "\n";
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ06/datos6.txt");
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
