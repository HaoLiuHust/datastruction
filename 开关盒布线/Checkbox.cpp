#include "Checkbox.h"

bool CheckBox(int net[],int n)
{
	LinkedStack<int> S;
	if (n<=0)
	{
		throw OutofBounds();
	}

	for (int i = 0; i < n;++i)
	{
		if (S.IsEmpty())
		{
			S.Add(net[i]);
			continue;
		}

		if (S.Top()==net[i])
		{
			int temp;
			S.Delete(temp);
		}
		else
		{
			S.Add(net[i]);
		}
	}

	return S.IsEmpty();
}