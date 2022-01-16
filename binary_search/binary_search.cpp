#include <iostream>

using namespace std;

int bsearch(int *arr, int key, int lower, int upper, int n) {
	int middle = upper / 2 ;
	if (middle == n) middle -= 1;
	if (arr[middle] == key) return middle;
	else if (arr[middle] > key) return bsearch(arr, key, lower, lower+middle, n);
	else return  bsearch(arr, key, middle, upper+middle, n);
}

int main()
{
	int key =5;
	int *arr = new int[7] { 1,2,3,4,5, 6,7};
	int index = bsearch(arr, key, 0, 7, 7);
    cout << index; 
}
