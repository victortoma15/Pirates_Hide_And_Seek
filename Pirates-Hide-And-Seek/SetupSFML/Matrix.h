//
//  Matrix.h
//  SetupSFML
//
//  Created by Fabian-Andrei Hirjan on 04.01.2022.
//  Copyright © 2022 Fabian-Andrei Hirjan. All rights reserved.
//

#pragma once
#include<iostream>
using namespace std;



class matrix
{
public:
    matrix();
    
    void drawMatrix(int arr[49]);
    void pickElements(int arr[9]);
    void generateSolutions(int arr[9], int searched, int mat[9], int lgd[4], int i);
    int pickLegend(int arr[9], int i);
    void rotateMatrix(int arr[9]);
    
};
