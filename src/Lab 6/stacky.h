#pragma once
#include <exception>
#define MAX_SIZE 50


template <class T, int max_size>
class stacky
{
private:
	int length = 0;
	T* data[max_size];
public:
	stacky();

	T* getArray() { return data; }
	T* pop();
	void push(T* data);
	void empty();
	T* top();
	int getLength();
	bool isEmpty();
	bool isFull();
	int getCapacity();
};

struct StackyOverflow : public std::exception
{
	const char* what() const throw ()
	{
		return "Stacky Overflow";
	}
};

struct StackyUnderflow : public std::exception
{
	const char* what() const throw ()
	{
		return "Stacky Underflow";
	}
};

template<class T, int max_size>
inline stacky<T, max_size>::stacky()
{
}

template<class T, int max_size>
inline T* stacky<T, max_size>::pop()
{
	if (this->getLength() <= 0)
		throw StackyUnderflow();
	return this->data[--length];
}

template<class T, int max_size>
inline void stacky<T, max_size>::push(T* val)
{
	if (this->getLength() >= this->getCapacity())
		throw StackyOverflow();
	this->data[length++] = val;
}

template<class T, int max_size>
inline void stacky<T, max_size>::empty()
{
	while (this->getLength() > 0) {
		delete this->data[--length];
	}
}

template<class T, int max_size>
inline T* stacky<T, max_size>::top()
{
	if (this->isEmpty())
		throw StackyUnderflow();
	return this->data[length-1];
}

template<class T, int max_size>
inline int stacky<T, max_size>::getLength()
{
	return length;
}

template<class T, int max_size>
inline bool stacky<T, max_size>::isEmpty()
{
	return length <= 0;
}

template<class T, int max_size>
inline bool stacky<T, max_size>::isFull()
{
	return this->lenth >= max_size;
}

template<class T, int max_size>
inline int stacky<T, max_size>::getCapacity()
{
	return max_size;
}
