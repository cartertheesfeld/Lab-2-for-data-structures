#ifndef UNSORTEDLISTL_H
#define UNSORTEDLISTL_H

#include "ItemType.h"

struct Node
{
	ItemType item;
	Node* next;
};

class UnsortedListL
{
public:
	UnsortedListL();			   						   //done
	~UnsortedListL();              				           //done
	void MakeEmpty();              				           //done
	bool IsFull();				   				           //done
	int GetLength();			   				           //done
	ItemType GetItem(ItemType item, bool& found);          //done
	bool PutItem(ItemType item);				           //done
	bool DeleteItem(ItemType item); 			           //done
	void ResetList();							           //done
	ItemType GetNextItem();			

private:
	Node* head;
	Node* loc;
	int listSize;
};

#endif // !UNSORTEDLISTL_H

