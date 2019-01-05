#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>

extern unsigned char FLUSH_BUFFER;
extern short BUFFER_SIZE;
extern std::basic_string<unsigned char> OUTPUT;
extern unsigned char PREV_SIZE;

void ClearBuffer();
void PushBuffer(unsigned char bit);
void WriteBuffer();

#endif