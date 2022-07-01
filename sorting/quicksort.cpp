#include<iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &s, int l, int r){
	int p = l;
	int count = 0;
	if ((r - l) > 1 && l >= 0){
		for (int i = l; i <= r; i++){
			if (s[i] < s[p]){
				s.insert(s.begin() + p, s[i]);
				s.erase(s.begin() + i + 1, s.begin() + i + 2);
				count++;
			}
		}
		quicksort(s, l, p + count - 1);
		quicksort(s, p + count + 1, r);
	}
}

int main(){
	vector<int> s{ 2, 3, 1, 7, 6, 5, 0 };
	cout << "before sorting: ";
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	quicksort(s, 0, s.size() - 1);
	cout << "\nafter sorting: ";
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << " ";
	system("pause");
	return 0;
}