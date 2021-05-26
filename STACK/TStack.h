#pragma once
#include "TDataRoot.h"
#include <iostream>
#include<conio.h>
#define StackID 101 // ������������ ������ ������ ��� �����
#define MemSize 25 // ������������ ������ ������ ��� �����
using namespace std;
class TStack:public TDataRoot {
protected: // ����
  int Hi; // ������ ������� �����
  int Mem[MemSize]; // ������ ������ ��� ��
  int Top; // ���������� ��������� � ��
  virtual int GetNextIndex(int index); // �������� ��������� ������
public:
  TStack(int Size = DefMemSize) : TDataRoot(Size) { Hi = -1; }//�����������
  virtual void Put(const TData &Val);// �������� � ����
  virtual TData Get(void);   //����� �� ����� � ���������
  virtual void Print();
protected:

  virtual int IsValid();

  virtual void CopyToVector(TElem v[]);
};

