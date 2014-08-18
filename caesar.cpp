/* 
 * File:   caesar.cpp
 * Author: Zangs
 * 
 * Created on 15 August 2014, 12:17
 */

#include "caesar.h"

Caesar::Caesar(char *path, int letters, char encrypt)
{
    _path = path;
    _letters = letters%26;
    
    while (_letters < 0)
        _letters += 26;
    
    if (encrypt == 'n')
        _letters *= -1;
    
    switch (encrypt)
    {
        case 'y':
        case 'n':
            cipher();
            break;
        default:
            cout << "Don\'t know what to do..." << endl;
    }
}

void Caesar::cipher()
{
    cout << "ciphering..." << endl;
    ifstream file;
    file.open(_path, ios::binary | ios::in);
    
    if (file.is_open())
    {
        char byte;
        stringstream out;
        
        while (file.read(&byte, 1))
        {
            cout << byte;
            if ('A' <= byte && 'Z' >= byte)
            {
                byte = ( (byte - 'A' + _letters) % 26 ) + 'A';
            }
            else if ('a' <= byte && 'z' >= byte)
            {
                byte = ( (byte - 'a' + _letters) % 26 ) + 'a';
            }
            out << byte;
        }
        
        file.close();
        
        cout << endl << out.str() << endl;
        
        ofstream outFile;
        outFile.open(_path, ios::binary | ios::out);
        
        if (outFile.is_open())
        {
            outFile << out.str();
            outFile.close();
        }
        else
        {
            cout << "Output file not created" << endl;
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
}
