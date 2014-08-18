/* 
 * File:   binaryCaesar.cpp
 * Author: Zangs
 * 
 * Created on 15 August 2014, 12:22
 */

#include "binaryCaesar.h"

BinaryCaesar::BinaryCaesar(char *path, int bit, char encrypt)
{
    // Check if file can be accessed
    _path = path;
    _bit = bit%8;
    
    switch (encrypt)
    {
        case 'y':
            hide();
            break;
        case 'n':
            reveal();
            break;
        default:
            cout << "Don\'t know what to do..." << endl;
    }
}

/*
 * This is to hide or cyclic left-shift the bits
 */
void BinaryCaesar::hide()
{
    cout << "hiding..." << endl;
    ifstream file;
    file.open(_path, ios::binary | ios::in);
    
    if (file.is_open())
    {
        char byte, buf;
        char start;
        char first =  0;
        stringstream out;
        
        char low = ~(0xff << _bit);
        char hig = (0xff << _bit);
        
        printf("h 0x%02x  l 0x%02x\n", hig, low);
        
        while (file.read(&byte, 1))
        {
            cout << byte;
            if (first == 0)
            {
                start = (byte >> (8-_bit)) & low;
                buf =   (byte << _bit) & hig;
                first = 1;
            }
            else
            {
                buf |=  (byte >> (8-_bit)) & low;
                out << buf;
                buf =   (byte << _bit) & hig;
            }
        }
        
        buf |=  start;
        out << buf;
        
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

/*
 * This is to hide or cyclic right-shift the bits
 */
void BinaryCaesar::reveal()
{
    cout << "revealing..." << endl;
    ifstream file;
    file.open(_path, ios::binary | ios::in);
    
    if (file.is_open())
    {
        char byte, buf;
        char end;
        char first =  0;
        stringstream out;
        
        char low = ~(0xff << (8-_bit));
        char hig = 0xff << (8-_bit);
        
        printf("h 0x%02x  l 0x%02x\n", hig, low);
        
        while (file.read(&byte, 1))
        {
            cout << byte;
            if (first == 0)
            {
                buf =   (byte >> _bit) & low;
                end =  buf;
                out << buf;
                buf =   (byte << (8-_bit)) & hig;
                first = 1;
            }
            else
            {
                buf |=  (byte >> _bit) & low;
                out << buf;
                buf =   (byte << (8-_bit)) & hig;
            }
        }
        
        end |= buf;
        string output = out.str();
        output[0] = end;
                
        file.close();
        
        cout << endl << output << endl;
        
        ofstream outFile;
        outFile.open(_path, ios::binary | ios::out);
        
        if (outFile.is_open())
        {
            outFile << output;
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
