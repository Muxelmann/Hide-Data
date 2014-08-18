/* 
 * File:   binaryCaesar.h
 * Author: Zangs
 *
 * Created on 15 August 2014, 12:22
 */

#ifndef BINARYCAESAR_H
#define	BINARYCAESAR_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BinaryCaesar {
public:
    BinaryCaesar(char *path, int bit, char encrypt = 'y');
private:
    int _bit;
    char *_path;
    
    void hide();
    void reveal();
};

#endif	/* BINARYCAESAR_H */

