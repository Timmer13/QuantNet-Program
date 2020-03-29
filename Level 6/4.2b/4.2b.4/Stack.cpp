#ifndef STACK_H
#define STACK_H
#include "Stack.h"
#endif
namespace Cluster
{
	namespace Containers
	{
		//constructors and destructor
		template<typename T>
		Stack<T>::Stack():current(0){}//default constructor

		template<typename T>
		Stack<T>::Stack(int s):arr(Array<T>(s)),current(0){}//constructor with parameter

		template<typename T>
		Stack<T>::Stack(const Stack<T>& source):arr(source.arr),current(source.current){}//copy constructor

		template<typename T>
		Stack<T>::~Stack(){}//destructor

		//operator
		template<typename T>
		Stack<T>& Stack<T>::operator = (const Stack<T>& source)//assignment operator
		{
			if(this!=&source)//handle self-assignment
			{
				arr=source.arr;//copy the embedded array
				current=source.current;//copy the current index
			}
			return *this;
		}

		//getter(for debug use)
		template<typename T>
		int Stack<T>::GetCurrent() const
		{return current-1;}//get the index of first "non-empty" element from the top

		template<typename T>
		T Stack<T>::GetEle() const
		{return arr[current-1];}//return the first "non-empty" element from the top

		//functions
		template<typename T>
		void Stack<T>::Push(T CurrentEle)//store current object and push one place forward
		{
			arr[current]=CurrentEle;//store the current object(and to make sure that the first element can be initialized)
			/*T temp=arr[current+1;]*///add this line if data member current's upper bound is 9(check if the next place is empty)
			current++;//push one place forward
		}

		template<typename T>
		T Stack<T>::Pop()//push one place backward and return object at that place
		{
			T ThrowAwayEle=arr[current-1];//return the element on that position
			current--;//decrement the current position
			return ThrowAwayEle;
		}
	}
}