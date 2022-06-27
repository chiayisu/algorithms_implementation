#include <iostream>
#include <climits>
#include <vector>

using namespace std;


void selection_sort(vector<int> &input){
	for (int i = 0; i < input.size(); i++){
		int index = 0;
		int minimum = INT_MAX;
		for (int j = i; j < input.size(); j++){
			if (input[j] < minimum){
				minimum = input[j];
				index = j;
			}
		}
		int temp = input[i];
		input[i] = minimum;
		input[index] = temp;
	}
}


int main(){
	vector <int> input{ 2, 5, 1, 100, 0, 6 };
	selection_sort(input);
	for (int i = 0; i < input.size(); i++)
		cout << input[i] << " ";
	system("pause");
}