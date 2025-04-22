#pragma once
#include <iostream>
using namespace std;
template <class T> class clsDblLinkedList
{
protected:
	int _Size = 0;
public:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};

	Node*head=NULL;
	
	void InsertAtBeginning(T value)
	{
		Node* new_node = new Node();
		new_node->prev = NULL;
		new_node->value = value;
		new_node->next = head;

		if (head != NULL)
		{
			head->prev = new_node;
		}
		head = new_node;
		_Size++;
	}

	void PrintList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	Node* Find(T value)
	{
		Node* temp = head;
		while (temp != NULL) {
			if (temp->value == value)
			{
				return temp;
			}
			temp = temp->next;
		}return NULL;
		
	}

	void InsertAfter(Node * Current,T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = Current->next;
		new_node->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = new_node;
		}
		Current->next = new_node;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* new_node = new Node();
		new_node->value = value;
		new_node->next = NULL;

		//In case the linked list is empty
		if (head == NULL)
		{
			new_node->prev = NULL;
			head = new_node;
		}
		//In case the linked list contains already nodes
		else {
			Node* Current = head;
			while (Current->next != NULL)
			{
				Current = Current->next;
			}
			new_node->prev = Current;
			Current->next = new_node;
		}
		_Size++;
	}

	void DeleteNode(Node*&NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL)
		{
			return;
		}
		Node* temp = head;
		head = head->next;

		//check if the linked list will contains nodes
		if (head != NULL)
		{
			head->prev = NULL;
		}
		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}
		//in case we have one node
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}
		Node* current = head;
		//we need to find the node before the laste node
		while (current->next->next != NULL)
		{
			current = current->next;
		}
		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0 ? true : false;
	}

	void Clear()
	{
		while (_Size > 0) {
			DeleteFirstNode();
		}
		
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp!=nullptr)
		{
			head = temp->prev;
		}
	}

	Node* GetNode(short index)
	{
		if (index > _Size - 1 || index < 0)
		{
			return NULL;
		}

		short Counter = 0;
		Node* Current = head;

		while (Current != NULL && (Current->next != NULL))
		{
			if (Counter == index)
			{
				break;
			}
			Current = Current->next;
			Counter++;
		}
		return Current;
		/*Node* current = head;
		for (short i = 0; i < _Size; i++)
		{
			if (current==NULL)
			{
				return NULL;
			}
			if (i== index)
			{
				return current;
			}
			current = current->next;
		}*/
	}
	
	T GetItem(short index)
	{
		Node* ItemNode = GetNode(index);
		
		if (ItemNode == NULL)
			NULL;
		else
			return ItemNode->value;
		
	}
	
	bool UpdateItem(short index, T NewValue)
	{
		Node* ItemNode = GetNode(index);
		
		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}
		else
		{
			return false;
		}
		
	}

	bool InsertAfter(short index, T value)
	{
		Node* ItemNode = GetNode(index);
		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		else
		{
			return false;
		}
	}


};


