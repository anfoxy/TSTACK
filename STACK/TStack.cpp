#include "TStack.h"
#include<stdio.h>
#include<stdlib.h>

int TStack::GetNextIndex(int index) { // �������� ��������� ������
  return ++index;
}


void TStack::Put(const TData &Val) { // �������� ��������
  if (pMem == NULL)SetRetCode(DataNoMem);
  else if (IsFull())SetRetCode(DataFull);
  else {
    Hi = GetNextIndex(Hi);
    pMem[Hi] = Val;
    DataCount++;
  }
}
TElem TStack::Get(void) { // ������� ��������
  TData temp = -1;
  if (pMem == NULL)SetRetCode(DataNoMem);
  else if (IsEmpty())SetRetCode(DataEmpty);
  else {

    temp = pMem[Hi--];
    DataCount--;
  }
    return temp;
}
  for (int i = 0; i < DataCount; i++) cout << pMem[i] << endl;
  int res = 0;
  for (int i = 0; i < DataCount; i++) 