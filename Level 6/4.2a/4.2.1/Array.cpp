//Array.cpp
//Class of array of points created on the heap
//09-27-2016 AM
#ifndef ARRAY_CPP//prevent double declarations of functions
#define ARRAY_CPP
#ifndef ARRAY_H
#define ARRAY_H
#include "Array.h"
#endif
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
namespace Cluster
{
	namespace Containers
	{
		//constructors and destructor
		template<typename T>
		Array<T>::Array()//default constructor
		{
			size=10;//default size is 10
			data=new T[size];//create an array of 10 points
		}
		
		template<typename T>
		Array<T>::Array(int s)//constructor with size
		{
			size=s;//size is s
			data=new T[s];//create an array of s points
		}
		
		template<typename T>
		Array<T>::Array(const Array& a)//copy constructor
		{
			size=a.size;//assign size
			data=new T[a.size];//create an array on the heap
			for(int i=0;i<size;i++)//initialize elements in the array
			{
				data[i]=a.data[i];//assign corresponding element in the operand
			}
		}

		template<typename T>
		Array<T>::~Array()//destructor
		{
			delete []data;//free the memories allocated
		}

		//operators
		template<typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source)
		{
			if(&source==this)//handle self-assignment
			{return *this;}
			else//not the same object
			{
				delete []this->data;//free the memory in data of this object
				size=source.size;// re-assign the size
				data=new T[source.size];//re-assign the data
				for(int i=0;i<size;i++)//initialize every element this->data with the corresponding element in source.data
				{
					data[i]=source.data[i];
				}
				return *this;
			}
		}

		template<typename T>
		T& Array<T>::operator [](int index)
		{
			if (index>size-1||index<0)//if the index is out of bound
			{throw OutOfBoundsException(index);}//throw an error information
			else 
			{return data[index];}//otherwise return the corresponding element of the index
		}

		template<typename T>
		const T& Array<T>::operator [] (int index) const// use to handle const objects
		{
			if (index>size-1||index<0)//if the index is out of bound
			{throw OutOfBoundsException(index);}//throw an error information
			else 
			{return data[index];}//otherwise return the corresponding element of the index
		}

		//Getters
		template<typename T>
		int Array<T>::Size() const
		{return size;}

		template<typename T>
		T& Array<T>::GetElement(int i) const
		{
			if(i>size-1||i<0)//if the index is out of bound
			{throw OutOfBoundsException(i);}//throw an error information
			else
			{return data[i];}//otherwise return the corresponding element of the index
		}

		//Setter
		template<typename T>
		void Array<T>::SetElement(int& i, T& t)
		{
			if(i>=0&&i<size)//if the index is inside the bound
			{data[i]=t;}//set the corresponding element
			else
			{throw OutOfBoundsException(i);}//otherwise throw an error information
		}
	}
}
