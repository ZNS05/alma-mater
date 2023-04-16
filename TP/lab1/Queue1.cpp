#include "Queue1.h"
int Queue1::average()
{
	int averageValue(0);
	node* viewPtr(get_head());
	int elemCount(0);
	int sum(0); 

	if (!get_head())
		return 0; 
				
	while (viewPtr)
	{
		elemCount++;
		sum += viewPtr->value;
		
		viewPtr = viewPtr->prev;
	}
	averageValue = sum / elemCount;
	return averageValue;
}

int Queue1::findNumber()
{
	node* viewPtr(get_head());
	
	int count(0);

	if (!get_head())
		return 0; 
					
	int aver = average();
	int number; 
	while (viewPtr)
	{
		if (viewPtr->value < aver) 
			number = viewPtr->value;
		viewPtr = viewPtr->prev;
	}
	return number;
}