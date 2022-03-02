#pragma once
#include <exception>

template <class T, int max_size>
class Queuey
{
private:
	T* data[max_size];
	int length = 0;
public:
	void enqueue(T* inData);
	T* dequeue();
	T* peek();
	bool isFull();
	bool isEmpty();
	void makeEmpty();
	int getLength();
};

struct QueueyOverflow : public std::exception
{
	const char* what() const throw ()
	{
		return "Queue is full";
	}
};

struct QueueyUnderflow : public std::exception
{
	const char* what() const throw ()
	{
		return "Queue is empty";
	}
};


template<class T, int max_size>
inline void Queuey<T, max_size>::enqueue(T* inData)
{
	if (this->isFull())
		throw QueueyOverflow();
	this->data[length++] = inData;
}

template<class T, int max_size>
inline T* Queuey<T, max_size>::dequeue()
{
	if (this->isEmpty())
		throw QueueyUnderflow();
	T* retVal = this->data[0];
	for (int i = 0; i < length - 1; i++) {
		this->data[i] = this->data[i + 1];
	}
	length--;
	return retVal;
}

template<class T, int max_size>
inline T* Queuey<T, max_size>::peek()
{
	if (this->isEmpty())
		throw QueueyUnderflow();
	return this->data[length - 1];
}

template<class T, int max_size>
inline bool Queuey<T, max_size>::isFull()
{
	return this->getLength() >= max_size;
}

template<class T, int max_size>
inline bool Queuey<T, max_size>::isEmpty()
{
	return this->getLength() <= 0;
}

template<class T, int max_size>
inline void Queuey<T, max_size>::makeEmpty()
{
	while (this->length > 0) {
		delete this->data[--length];
	}
}

template<class T, int max_size>
inline int Queuey<T, max_size>::getLength()
{
	return this->length;
}
