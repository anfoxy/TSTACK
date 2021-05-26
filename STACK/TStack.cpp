#include "TStack.h"
#include<stdio.h>
#include<stdlib.h>

int TStack::GetNextIndex(int index) { // получить следующий индекс
  return ++index;
}


void TStack::Put(const TData &Val) { // добавить значение
  if (pMem == NULL)SetRetCode(DataNoMem);
  else if (IsFull())SetRetCode(DataFull);
  else {
    Hi = GetNextIndex(Hi);
    pMem[Hi] = Val;
    DataCount++;
  }
}
TElem TStack::Get(void) { // извлечь значение
  TData temp = -1;
  if (pMem == NULL)SetRetCode(DataNoMem);
  else if (IsEmpty())SetRetCode(DataEmpty);
  else {

    temp = pMem[Hi--];
    DataCount--;
  }
    return temp;
}void TStack::Print() {
  for (int i = 0; i < DataCount; i++) cout << pMem[i] << endl;}int TStack::IsValid() {
  int res = 0;  if (pMem == NULL)   res = 1;  if (MemSize<DataCount)   res += 2;  return res;}void TStack::CopyToVector(TElem v[]) {
  for (int i = 0; i < DataCount; i++)      v[i]=pMem[i];}