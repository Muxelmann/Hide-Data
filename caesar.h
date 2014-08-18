/* 
 * File:   caesar.h
 * Author: Zangs
 *
 * Created on 15 August 2014, 12:17
 */

#ifndef CAESAR_H
#define	CAESAR_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Caesar {
public:
    Caesar(char *path, int letters, char encrypt = 'y');
private:
    int _letters;
    char *_path;
    
    void cipher();

};

#endif	/* CAESAR_H */

