#include<iostream>
#include "storage.h"
#include "compress.h"
#include "manipulate.h"

unsigned char FLUSH_BUFFER = 0;
short BUFFER_SIZE;

void ClearBuffer()
{
    FLUSH_BUFFER = 0;
}

void PushBuffer(short bit)
{
    FLUSH_BUFFER<<1
}