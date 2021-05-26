#pragma once
#include "TDataCom.h"
#define DefMemSize 25 //размер памяти по умолчанию 
#define DataEmpty  -101//СД пуст
#define DataFull   -102//СД переполнен
#define DataNoMem  -103//нет памяти
typedef int TData;//тип значения в СД
typedef int TElem; // тип элемента СД
typedef TElem *PTElem;// тип указателя на СД
enum TMemType { MEM_HOLDER, MEM_RENTER };
class TDataRoot :public TDataCom {

protected: // поля
  PTElem pMem; // указатель на массив элементов
  int MemSize; // размер памяти для СД
  int DataCount; // количество элементов в СД
  TMemType MemType; // режим управления памятью 
protected:
  void SetMem(void *pMem, int Size);
public:
  TDataRoot();//конструктор
  ~TDataRoot();
  TDataRoot(int size = DefMemSize); //деструктор
  virtual int IsEmpty(void) const; // контроль пустоты
  virtual int IsFull(void) const; // контроль переполнения
  virtual void Put(const TData &Val) = 0;// добавить значение
  virtual TData Get(void) = 0; // извлечь значение
  //служебные методы
  virtual int IsValid() = 0;
  virtual void Print() = 0;
  //дружелюбные классы
  friend class TMultiStack;
  friend class TSuperMultiStack;
  friend class TComplexMultiStack;
};