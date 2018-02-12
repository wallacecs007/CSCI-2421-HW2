//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"
//#include <iostream>

ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove


void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

// private

int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

////////////////////////////////////////////////////////////////////////*
/*
Here begins my code I have added to this file to overload operators.

Beginning will be the overloading of the + operator and then the - operator.

The goal of the + is to combine 2 array bags into 1 object and then remove any duplicates

The goal of the - is to remove any of the items from the second arraybag, from the first
*/

//Overloading this function to combine to ArrayBags
//Creates a blank ArrayBag and pushes both of the other ArrayBags into
//it and then clears out any duplicates.
ArrayBag ArrayBag::operator + (const ArrayBag& target)
{

	int myIndex;
	ArrayBag combined;

	//Adding in the left operand into the combined ArrayBag
	for (int myIndex = 0; myIndex < this->getCurrentSize(); myIndex++)
	{
		combined.add(this->items[myIndex]);
	}

	//Adding in the right operand into the combined ArrayBag
	for (int myIndex = 0; myIndex < target.getCurrentSize(); myIndex++)
	{
		combined.add(target.items[myIndex]);
	}

	//This for loop is here to clear out any duplicates
	//The idea behind it is that it will run through the
	//ArrayBag element by element and if there is a duplicate
	//It will delete it. If there is a duplicate it will also
	//Deincrement i, in order to check the next element that
	//Shifted into its place 
	for (int i = 0; i < combined.getCurrentSize(); i++)
	{

		if (combined.getFrequencyOf(i) > 1)
		{
			combined.remove(i);
			i--;
		}
		else {}
	}//End of for loop
	

	return combined;
	
}//End of overload +

ArrayBag ArrayBag::operator - (const ArrayBag& target)
{
	
	ArrayBag subtracted;
	int myIndex;

	for (int i = 0; i < this->getCurrentSize(); i++)
	{
		subtracted.add(this->items[i]);
	}

	for (int i = 0; i < target.getCurrentSize(); i++)
	{

		if (subtracted.contains(target.items[i]) == target.contains(target.items[i]))
		{
			subtracted.remove(target.items[i]);
		}

	}

	/*
	//Making a copy of the ArrayBag so the program doesn't
	//Remove the items from the original ArrayBag.
	for (int i = 0; i < this->getCurrentSize(); i++)
	{
		subtracted.add(this->items[i]);
	}

	for (int i = 0; i < target.getCurrentSize(); i++)
	{
		
		int getIndex = subtracted.getIndexOf(target.items[i]);

		if(getIndex == -1)
		{ }
		else
		{
			subtracted.remove(getIndex); 
		}

	}
	*/

	return subtracted;

}

std::ostream& operator<<(std::ostream& out, const ArrayBag& target)
{
	for (int i = 0; i < target.getCurrentSize(); i++)
		out << target.items[i] << " ";

	return out;
}