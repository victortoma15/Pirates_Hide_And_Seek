//
//  tilemaps.h
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 09.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//
#include <SFML/Graphics.hpp>
#ifndef tilemaps_h
#define tilemaps_h




class tilemaps {
    public:
    Tilemap map;
    Tilemap map2;
    Tilemap map3;
    Tilemap map4;
    Tilemap sol1;
    Tilemap sol2;
    Tilemap sol3;
    Tilemap sol4;
    Tilemap legenda;
    
    void StartGame(int level[4][9], int solt[4][9], int legend[4]){
        
        if (!map.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level[0], 3, 3))
            return -1;
        map.setPosition(188, 172);

        //------------------------
        
        if (!map2.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level[1], 3, 3))
            return -1;
        map2.setPosition(300, 172);
        //
        
        if (!map3.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level[2], 3, 3))
            return -1;
        map3.setPosition(188, 300);
        //
  
        if (!map4.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), level[3], 3, 3))
            return -1;
        map4.setPosition(300, 300);
        
        // Sol 1
    
        if (!sol1.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), solt[0], 3, 3))
            return -1;
        sol1.setPosition(450, 100);
        if (!sol2.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), solt[1], 3, 3))
            return -1;
        sol2.setPosition(450, 200);
        if (!sol3.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), solt[2], 3, 3))
            return -1;
        sol3.setPosition(450, 300);
        if (!sol4.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), solt[3], 3, 3))
            return -1;
        sol4.setPosition(450, 400);
        if (!legenda.load("/Users/fabian-andreihirjan/Desktop/SFML/SetupSFML/tlm.png", sf::Vector2u(32, 32), legend, 1, 4))
            return -1;
        legenda.setPosition(100, 225);
    }
    bool champion(int matchedPieces[4]){
        int ok = 1;
        for(int i = 0; i<=3; i++){
            if(matchedPieces[i] != 0)
                ok = 0;
        }
        return ok;
    }
    void resetGame(int matchedPieces[4]){
        for(int i = 0; i<=3; i++){
            matchedPieces[i] = 1;
        }
    }
    
};

#endif /* tilemaps_h */
