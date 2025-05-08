#include <iostream>
using namespace std;

// min heap
void minInsert(int arr[], int i)
{
	int parent = (i - 1) / 2;
	int cur = i;
	while (parent >= 0 && arr[parent] > arr[cur])
	{
		swap(arr[parent], arr[cur]);
		cur = parent;
		parent = (cur - 1) / 2;
	}
}

// max heap
void maxInsert(int arr[], int i)
{
	int parent = (i - 1) / 2;
	int cur = i;
	while (parent >= 0 && arr[parent] < arr[cur])
	{
		swap(arr[parent], arr[cur]);
		cur = parent;
		parent = (cur - 1) / 2;
	}
}

int main()
{
	int arr[] = {20, 30, 15, 2, 5, 10};

	for (int i = 1; i < 6; i++)
	{
		minInsert(arr, i);
	}

	// cout << "After inserting all: ";
	// for(int i = 0; i < 6; i++){
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	cout << "Minimum value is " << arr[0] << endl;

	for (int i = 1; i < 6; i++)
	{
		maxInsert(arr, i);
	}

	cout << "Maximum value is " << arr[0] << endl;
}