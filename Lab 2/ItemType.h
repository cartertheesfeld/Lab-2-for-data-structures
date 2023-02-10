#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <ostream>

using namespace std;

const int Max_Items = 100;

enum RelationType
{
	LESS,
	GREATER,
	EQUAL
};

class ItemType
{
public:

	ItemType();										 //done
	~ItemType();									 //done
													 //done
	void Initialize(int item_) { SetItem(item_); };	 //done
	void SetItem(int item_) { item = item_; };		 //done
	int GetItem() { return item; };					 //done
													 //done
	void Print(ostream& Stream);					 //done
													 //done
	RelationType ComparedTo(ItemType item_);		 //done

private:
	int item;
};

#endif // !ITEMTYPE_H