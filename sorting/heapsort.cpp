#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void Insert(int value, vector<int> &heap){
	heap.push_back(value);
	int current = heap.size() - 1;
	for (int i = heap.size() / 2; i >= 0; i--){
		if (heap[current] < heap[i]){
			swap(heap[current], heap[i]);
			current = i;
		}
		
		if (current >= 1){
			if (heap[i] > heap[current - 1]){
				swap(heap[current - 1], heap[i]);
				current = i;
			}
		}
	}
}

int FindMinimum(vector<int> heap){
	int minimum = heap[0];
	return minimum;
}

void DeleteMinimum(vector<int> &heap){
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	int current = 0;
	for (int i = 1; i < heap.size() / 2; i++){
		if (heap[current] > heap[i * 2 - 1]){
			swap(heap[current], heap[i * 2 - 1]);
			current = i;
		}
		if (i * 2 < heap.size()){
			if (heap[current] > heap[i * 2]){
				swap(heap[current], heap[i * 2]);
				current = i;
			}
		}
	}
}

int main(){
	vector<int> input{900, 2005, 500, 1783,1200, 1000, 2001};
	vector<int> heap;

	for (int i = 0; i < input.size(); i++){
		Insert(input[i], heap);
	}
	
	cout << "Original heap: ";
	for (int i = 0; i < heap.size(); i++){
		cout << heap[i] << " ";
	}
	cout << "\n";

	cout << "Minimum value: ";

	cout << heap[0];

	cout << "\n";

	cout << "After deleting minimum: ";
	DeleteMinimum(heap);

	for (int i = 0; i < heap.size(); i++){
		cout << heap[i] << " ";
	}

	cout << "\n";
	system("pause");
	return 0;
}