#include<iostream>
#include "compress.h"
#include "manipulate.h"
#include "storage.h"

unsigned char FLUSH_BUFFER = 0;
short BUFFER_SIZE = 0;
unsigned char PREV_SIZE = 0;
std::basic_string<unsigned char> OUTPUT;

void ClearBuffer()
{
    FLUSH_BUFFER = 0;
    BUFFER_SIZE = 0;
}

void PushBuffer(unsigned char bit)
{
    FLUSH_BUFFER = FLUSH_BUFFER<<1;
    FLUSH_BUFFER = FLUSH_BUFFER | bit;
    std::cout<<"FLUSH BUFF: "<<(int)FLUSH_BUFFER<<std::endl;
    BUFFER_SIZE++;
    std::cout<<"Prefix bit: "<<(int)bit<<std::endl;
    if(BUFFER_SIZE == 8)
    {
        WriteBuffer();
        PREV_SIZE = BUFFER_SIZE;
        ClearBuffer();
    }
}

void WriteBuffer()
{
    OUTPUT.push_back(FLUSH_BUFFER);
}