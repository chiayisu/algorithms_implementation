#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &s, int low, int middle, int high){
	int left = low;
	int right = middle + 1;
	vector<int>sorted;
	while (left <= middle && right <= high){
		if (s[left] > s[right]){
			sorted.push_back(s[right]);
			right++;
		}
		else{
			sorted.push_back(s[left]);
			left++;
		}
	}
	for (int i = left; i <= middle; i++){
		sorted.push_back(s[i]);
	}
	for (int i = right; i <= high; i++){
		sorted.push_back(s[i]);
	}
	int count = 0;
	for (int i = low; i <= middle; i++){
		s[i] = sorted[count];
		count++;
	}
	for (int i = middle + 1; i <= high; i++){
		s[i] = sorted[count];
		count++;
	}
}

void mergesort(vector<int> &s, int low, int high){
	if (low < high){
		int middle = (low + high) / 2;
		mergesort(s, low, middle);
		mergesort(s, middle + 1, high);
		merge(s, low, middle, high);
	}
}


int main(){
	vector <int> s{ 7, 3, 0, 5, 4, 2, 1 };
	int high = s.size() - 1;
	cout << "before sorting: ";
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	mergesort(s, 0, high);
	cout << "\nafter sorting: ";
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	system("pause");
	return 0;
}