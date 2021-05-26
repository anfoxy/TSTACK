#pragma once
#include "TDataRoot.h"
#include <iostream>
#include<conio.h>
#define StackID 101 // максимальный размер пам€ти дл€ стека
#define MemSize 25 // максимальный размер пам€ти дл€ стека
using namespace std;
class TStack:public TDataRoot {
protected: // пол€
  int Hi; // индекс вершины стека
  int Mem[MemSize]; // размер пам€ти дл€ —ƒ
  int Top; // количество элементов в —ƒ
  virtual int GetNextIndex(int index); // получить следующий индекс
public:
  TStack(int Size = DefMemSize) : TDataRoot(Size) { Hi = -1; }//конструктор
  virtual void Put(const TData &Val);// положить в стек
  virtual TData Get(void);   //вз€ть из стека с удалением
  virtual void Print();
protected:

  virtual int IsValid();

  virtual void CopyToVector(TElem v[]);
};

