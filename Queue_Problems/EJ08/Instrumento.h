//
//  Instrumento.h
//  MARP
//
//  Created by Patricia Cabrero on 16/10/17.
//  Copyright © 2017 Patricia Cabrero Villar. All rights reserved.
//

#ifndef Instrumento_h
#define Instrumento_h
class Instrumento{
public:
    Instrumento():grupo(0), partituras(1), musicos(0){};
    ~Instrumento() = default;
    int grupo;
protected:
    int musicos;
    int partituras;
public:
    void sumaPartitura(){
        partituras++;
        if(musicos % partituras > 0)
            grupo = (musicos / partituras) + 1;
        else grupo = musicos / partituras;
    };
    void set(int music){
        musicos=grupo = music;
    }
};
#endif /* Instrumento_h */
