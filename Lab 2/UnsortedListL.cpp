#include "UnsortedListL.h"

UnsortedListL::UnsortedListL()
{
	head = nullptr;
	loc = nullptr;
	listSize = 0;
}

UnsortedListL::~UnsortedListL()
{
	MakeEmpty();
}

void UnsortedListL::MakeEmpty()
{
	Node* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	
}

bool UnsortedListL::IsFull()
{
	try
	{
		Node* temp = new Node;
	}
	catch (bad_alloc)
	{
		return true;
	}
	return false;
}

int UnsortedListL::GetLength()
{														  
	return listSize;
}

ItemType UnsortedListL::GetItem(ItemType item, bool& found)		   //ask what david thinks
{
	ResetList();
	for(int i =1 ; i<listSize; i++)
	{
		if (item.ComparedTo(loc->item) == RelationType::EQUAL)
		{
			found = true;
			return loc->item;
		}
		loc = loc->next;
	}
	found = false;
	return item;
}

bool UnsortedListL::PutItem(ItemType item)
{
	if (!IsFull())
	{
		Node* temp = new Node;
		temp->item = item;

		if (head == nullptr)
		{
			temp->next = nullptr;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		listSize++;
		return true;
	}

	return false;
}

bool UnsortedListL::DeleteItem(ItemType item) 
{
	ResetList();
	Node* temp = loc;
	for  (int i = 1; i < listSize; i++)
	{
		if (item.ComparedTo(temp->item) == RelationType::EQUAL)
		{
			//if the deleted item is at the end
			if (temp->next == nullptr)
			{
				delete temp;
				loc->next = nullptr;
			}
			else if (temp->next == head->next)
			{
				head = head->next;
				delete temp;
			}
			else
			{
				loc->next = loc->next->next;
				delete temp;
			}
			listSize--;
			return true;
		}
		temp = loc->next;
	}
	
	return false;
}

void UnsortedListL::ResetList() 
{
	loc = head;
}

ItemType UnsortedListL::GetNextItem()
{
	if (loc->next != NULL)
	{
		loc = loc->next;
		return loc->item;
	}
	else 
		return loc->item;
}