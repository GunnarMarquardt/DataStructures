/*
280
Arrays 1
gmarquardt
*/

#include <iostream>

using namespace std;

void load(int a[], int c)
{
	if (c <= 0 || c > 10)
	{
		cout << "Invalid input" << endl;
		return;
	}
	for (int i = 0; i < c; i++) 
	{
		cout << "Enter number " << i + 1 << ":" << endl;
		cin >> a[i];
	}
}

void display(int a[], int c)
{
	cout << "{ ";
	for (int i = 0; i < c; i++) 
	{
		cout << a[i] << " ";
	}
	cout << "}" << endl;
}

int get(int a[], int c, int n)
{
	if (n > c - 1)
	{
		return NULL;
	}
	else
	{
		return a[n];
	}
}

void set(int a[], int c, int n, int v) 
{
	a[n] = v;
}

void deleteElement(int a[], int& c, int n) 
{
	for (int i = n; i < c - 1; i++) 
	{
		a[i] = a[i + 1];
	}
	a[c - 1] = 0;
	c -= 1;
}

void insert(int a[], int& c, int n, int v) 
{
	if (c < 10)
	{
		c += 1;
	}
	for (int i = c - 1; i > n; i--) 
	{
		a[i] = a[i - 1];
	}
	a[n] = v;
}

int findMin(int a[], int c)
{
	int min = a[0];
	for (int i = 1; i < c; i++) 
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}

int findAve(int a[], int c)
{
	double ave;
	double total = 0.0;
	for (int i = 0; i < c; i++)
	{
		total += a[i];
	}
	ave = total / c;
	return ave;
}

void sort(int a[], int c)
{
	int temp;
	for (int pass = 0; pass < c - 1; pass++)
	{
		for (int pos = 0; pos < c - pass - 1; pos++)
		{
			if (a[pos] > a[pos + 1])
			{
				temp = a[pos];
				a[pos] = a[pos + 1];
				a[pos + 1] = temp;
			}
		}
	}
}

int main()
{
	int array[] = {0,0,0,0,0,0,0,0,0,0}, choice, count = 0, n, v;
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
			cout << "How many?" << endl;
			cin >> count;
			load(array, count);
			break;
		case 2:
			display(array, count);
			break;
		case 3:
			cout << "Which element?" << endl;
			cin >> n;
			if (get(array, count, n) != NULL) {
				cout << get(array, count, n) << endl;
			}
			else
			{
				cout << "Invalid Element" << endl;
			}
			break;
		case 4:
			cout << "Which element?" << endl;
			cin >> n;
			cout << "What value?" << endl;
			cin >> v;
			if (n > count - 1)
			{
				cout << "Invalid element" << endl;
				break;
			}
			set(array, count, n, v);
			display(array, count);
			break;
		case 5:
			cout << "Which element?" << endl;
			cin >> n;
			if (n > count - 1)
			{
				cout << "Invalid element" << endl;
				break;
			}
			deleteElement(array, count, n);
			display(array, count);
			break;
		case 6:
			cout << "Which element?" << endl;
			cin >> n;
			cout << "What value?" << endl;
			cin >> v;
			if (n > count - 1)
			{
				cout << "Invalid element" << endl;
				break;
			}
			insert(array, count, n, v);
			display(array, count);
			break;
		case 7:
			cout << findMin(array, count) << endl;
			break;
		case 8:
			cout << findAve(array, count) << endl;
			break;
		case 9:
			sort(array, count);
			display(array, count);
			break;
		case 10:
			done = true;
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	} while (done == false);
}
