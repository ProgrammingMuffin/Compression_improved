#include<iostream>
#include "storage.h"
#include "compress.h"
#include "manipulate.h"

char FLUSH_BUFFER = 0;
short BUFFER_SIZE = 0;
short PREV_SIZE = 0;

void ClearBuffer()
{
    FLUSH_BUFFER = 0;
    BUFFER_SIZE = 0;
}

void PushBuffer(char bit)
{
    FLUSH_BUFFER<<1;
    FLUSH_BUFFER = FLUSH_BUFFER | bit;
    BUFFER_SIZE++;
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