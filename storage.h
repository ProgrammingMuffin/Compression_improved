#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>

extern char FLUSH_BUFFER;
extern short BUFFER_SIZE;
extern std::string OUTPUT;

void ClearBuffer();
void PushBuffer(char bit);
void WriteBuffer();

#endif