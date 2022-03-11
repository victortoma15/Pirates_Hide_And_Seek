//
//  Matrix.cpp
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 04.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#include "Matrix.h"
#include <SFML/Graphics.hpp>
#include "calculus.hpp"
#include <time.h>

matrix::matrix(){

}
calculus clc;
void matrix::pickElements(int arr[9]){
    //v2 = rand() % 100 + 1;
    int picked;
    for(int i = 0; i<=8; i++){
        picked = clc.pickProb(1, 9);
        arr[i] = picked;
    }
}

int matrix::pickLegend(int arr[9], int i){
    int picked = 1;
    while(picked < 9){
        for(int i = rand()%9+1; i<9; i++){
            if(picked == arr[i]){
                return picked;
            }
               
            }
        picked++;
    }
    return picked;
    }
        
    
    
    



void matrix::generateSolutions(int arr[9], int searched, int mat[9], int lgd[4], int index){
    int isFound = 0;
    for(int i = 0; i<=8; i++){
        if((arr[i] != searched && arr[i] != 0) || (arr[i] == searched && isFound == 1))
            mat[i] = 0;
        else if(arr[i] == searched || arr[i] == 0){
            if(arr[i] == searched){
                isFound = 1;
                lgd[index] = searched;
            }
                
            mat[i] = 69;
    }
    
}
    
}

void matrix::rotateMatrix(int arr[9]){
    int temp;
    int i,j;
    for (i = 0, j = 9 - 1; i < 9/2; i++, j--)
      {
          temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
      }
}
