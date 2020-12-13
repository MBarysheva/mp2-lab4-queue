#include<iostream>
template <class T>
class TQueue
{
public:
	int MaxSize;
	int head;
	int tail;
	int DataCount;
	T* pMem;
public:
   TQueue(int s = 100)
   {
	head = 0;
	tail = -1;
	DataCount = 0;
	MaxSize = s;
	pMem = new T[MaxSize];
	for (int i = 0; i < s; i++)
	{
		pMem[i] = 0;
	}
   }
   ~TQueue()
   {
	   if (pMem)
	   {
		   delete[] pMem;
	   }
   }
   TQueue(const TQueue<T>& q)
   {
	  
	   MaxSize = q.MaxSize;
	   DataCount = q.DataCount;
	   head = q.head;
	   tail = q.tail;
	   pMem = new T[MaxSize];
	   int tmp = head;
	   int _DataCount = 0;
	   while (_DataCount != DataCount)
	   {
		   pMem[tmp] = q.pMem[tmp];
		   tmp = (tmp + 1) % MaxSize;
		   _DataCount++;
	   }
   }
   TQueue<T>& operator = (const TQueue<T>& q)
   {
	   if (this != &q)
	   {
		   if (MaxSize != q.MaxSize)
		   {
			   MaxSize = q.MaxSize;
			   delete[]pMem;
			   pMem = new T[MaxSize];
		   }
		   DataCount = q.DataCount;
		   head = q.head;
		   tail = q.tail;
		   int tmp = head;
		   int _DataCount = 0;
		   while (_DataCount != DataCount)
		   {
			   pMem[tmp] = q.pMem[tmp];
			   tmp = (tmp + 1) % MaxSize;
			   _DataCount++;
		   }
	   }
	   return (*this);
   }
   int GetDataCount()
   { 
	   return DataCount;
   }
   int GetMaxSize()
   { 
	   return MaxSize; 
   }
   bool Empty() 
   {
	   if (DataCount == 0)
	   {
		   return true;
	   }
	   return false;
   }
   bool Full()
   {
	   if (DataCount == MaxSize)
	   {
		   return true;
	   }
	   return false;
   }
   void Push(T a)
   {
	   if (DataCount == MaxSize)
	   {
		   throw DataCount;
	   }
	   DataCount++;
	   tail = (tail + 1) % MaxSize;
	   pMem[tail] = a;
   }
   T GetHead()
   {
	   if (DataCount == 0)
	   {
		   throw DataCount;
	   }
	   DataCount--;
	   head = (head + 1) % MaxSize;
	   if (head == 0)
	   {
		   return pMem[MaxSize - 1];
	   }
	   return pMem[head - 1];
   }
   T SeeHead() 
   {
	   if (Empty())
	   {
		   throw 0;
	   }
	   return pMem[head];
   }
   T GetNumberHead()
   { 
	   return head; 
   }
};
