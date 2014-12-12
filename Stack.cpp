/*
*
* @author : Ganesh Joshi
* Date    :10/08/2013
* CSCI 511
* File : Template Class
*/

#include<iostream>
#include<string>
using namespace std;


template<class Type>
class Stack
{

public:
	Stack();
	Stack(const Stack<Type>&);
	~Stack();
	Stack<Type>& operator=(const Stack<Type>&);
	int count();
	void push(Type data);
	Type pop();
   
private:
	static const int chunk_size;
	unsigned maximum_size;
	int current_size;
	Type* base;

};

 
template <class Type> const int Stack<Type>::chunk_size=10;

template <class Type> Stack<Type>::Stack():current_size(-1),maximum_size(chunk_size),base(new Type[chunk_size])
{
    if(base==0)	
	throw "No more memory!";
}

template <class Type> Stack<Type>::Stack(const Stack<Type>& s):maximum_size(s.maximum_size), base(new Type[s.maximum_size])
{
      if(base==0)
	  throw "No more memory!";
      if(s.current_size>-1)
      {
		for(current_size=0; current_size<=s.current_size; current_size++)
		base[current_size]=s.base[current_size];
		current_size--;
      }
}

template <class Type>Stack<Type>::~Stack()
{
		delete [] base;
}

template <class Type>Stack<Type>& Stack<Type>::operator=(const Stack<Type>& s)
{
      delete [] base;
      maximum_size=s.maximum_size;
      base=new Type[maximum_size];
      if(base==0)
	  throw "No more memory!";
      current_size=s.current_size;
      if(current_size>-1)
      {
				for(int x=0; x<=current_size; x++)
				base[x]=s.base[x];
      }
			  return *this;
}
   
template <class Type>
void Stack<Type>::push(Type element)
{
      current_size++;
      if(current_size==maximum_size-1)
      {
 			maximum_size+=chunk_size;
			Type* new_buffer = new Type[maximum_size];
			
			if(new_buffer==0)
			throw "No more memory!";
			for(int x=0; x<current_size; x++)
			new_buffer[x]=base[x];
			delete [] base;
			base=new_buffer;
      }
      base[current_size]=element;
    }

template <class Type>Type Stack<Type>::pop()
    {
      if(current_size<0)
		throw "Nothing to pop!";
      return base[current_size--];
    }

template <class Type>
int Stack<Type>::count()
{
      return current_size+1;
}

