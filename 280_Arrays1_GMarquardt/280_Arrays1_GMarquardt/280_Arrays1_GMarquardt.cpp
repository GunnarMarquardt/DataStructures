/*
280
Arrays 1
gmarquardt
*/

#include <iostream>

using namespace std;

void load(int a[], int c)
{
	for (int i = 0; i < c; i++) 
	{
		cout << "Enter number " << i + 1 << ":" << endl;
		cin >> a[i];
	}
}

void display(int a[], int c)
{
	cout << "{ ";
	for (int i = 0; i < c; i++) {
		cout << a[i] << " ";
	}
	cout << "}" << endl;
}

int get(int a[], int n)
{
	return a[n];
}

int main()
{
	int array[] = {0,0,0,0,0,0,0,0,0,0}, choice, count = 0;
	bool done = false;
	do
	{
		cout << "1: load" << endl
			<< "2: display" << endl
			<< "3: get" << endl
			<< "4: set" << endl
			<< "5: delete" << endl
			<< "6: insert" << endl
			<< "7: findMin" << endl
			<< "8: findAve" << endl
			<< "9: sort" << endl
			<< "10: exit" << endl;
	
		cin >> choice;
	
		switch (choice)
		{
		case 1:
			int check;
			cout << "How many?" << endl;
			cin >> check;
			if (check > 0 && check <= 10)
			{
				load(array, count);
			}
			else
			{
				cout << "Invalid input" << endl;
			}
			break;
		case 2:
			display(array, count);
			break;
		case 3:
			int n;
			cout << " Which element?" << endl;
			cin >> n;
			if (n > count - 1)
			{
				cout << "Invalid element" << endl;
			}
			else
			{
				get(array, n);
			}
			break;
		}
	} while (done == false);
}
