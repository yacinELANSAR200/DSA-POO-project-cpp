#pragma once
#include "clsDblLinkedList.h"

template <class T> class clsMyQueue
{
protected:
//composition:when a class contains an instance of another class as a part of its attributes
	clsDblLinkedList <T> _MyList;
public :

	void push(T item)
	{
		_MyList.InsertAtEnd(item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}
	
	short Size()
	{
		return _MyList.Size();
	}
	
	T front()
	{
		return _MyList.GetItem(0);
	}
	
	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(short index)
	{
		return _MyList.GetItem(index);
	}

	void Reverse()
	{
		 _MyList.Reverse();
	}

	bool UpdateItem(short index, T value)
	{
		return _MyList.UpdateItem(index, value);
	}

	bool InsertAfter(short index, T value)
	{
		return _MyList.InsertAfter(index, value);
	}

	void InsertAtFront(T value)
	{
		 _MyList.InsertAtBeginning(value);
	}

	void InsertAtBack(T value)
	{
		 _MyList.InsertAtEnd(value);
	}

	void Clear()
	{
		 _MyList.Clear();
	}

};

