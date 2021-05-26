#pragma once
#include "TDataCom.h"
#define DefMemSize 25 //������ ������ �� ��������� 
#define DataEmpty  -101//�� ����
#define DataFull   -102//�� ����������
#define DataNoMem  -103//��� ������
typedef int TData;//��� �������� � ��
typedef int TElem; // ��� �������� ��
typedef TElem *PTElem;// ��� ��������� �� ��
enum TMemType { MEM_HOLDER, MEM_RENTER };
class TDataRoot :public TDataCom {

protected: // ����
  PTElem pMem; // ��������� �� ������ ���������
  int MemSize; // ������ ������ ��� ��
  int DataCount; // ���������� ��������� � ��
  TMemType MemType; // ����� ���������� ������� 
protected:
  void SetMem(void *pMem, int Size);
public:
  TDataRoot();//�����������
  ~TDataRoot();
  TDataRoot(int size = DefMemSize); //����������
  virtual int IsEmpty(void) const; // �������� �������
  virtual int IsFull(void) const; // �������� ������������
  virtual void Put(const TData &Val) = 0;// �������� ��������
  virtual TData Get(void) = 0; // ������� ��������
  //��������� ������
  virtual int IsValid() = 0;
  virtual void Print() = 0;
  //����������� ������
  friend class TMultiStack;
  friend class TSuperMultiStack;
  friend class TComplexMultiStack;
};