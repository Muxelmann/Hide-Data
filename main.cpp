/* 
 * File:   main.cpp
 * Author: Zangs
 *
 * Created on 11 August 2014, 16:19
 */

#include <iostream>

#include "caesar.h"
#include "binaryCaesar.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc != 3)
    {
        cout << "No correct input arguments (" << argc << ")" << endl;
        return 0;
    }
    
    
    if ('c' == argv[2][0])
        // Apply caesar cypher
        Caesar *caesar = new Caesar(argv[1], 1, 'y');
    
    if ('b' == argv[2][0])
        // Apply binray caesar cypher
        BinaryCaesar *binaryCaesar = new BinaryCaesar(argv[1], 4, 'y');
    
    
    return 0;
}

