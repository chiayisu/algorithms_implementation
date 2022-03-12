#include <iostream>
#include <vector>


using namespace std;

void subset(int k, vector<int> result, int count, vector<int> answer_vector);
void process_result(vector<int> result, int &count) ;

int main() {
	int k = 4;
	int count = 0;
	vector<int> result;
	vector<int>answer_vector = { 0, 1 };
	int c = 0;
	subset(k, result, count, answer_vector);
	return 0;
}

void subset(int k, vector<int> result, int count, vector<int> answer_vector) {
	
	if (result.size() == k) {
		process_result(result, count);
		
	}
	else {
		for (int i = 0;i < 2;i++) {
			result.push_back(answer_vector[i]);
			subset(k, result, count, answer_vector);
			result.erase(result.begin() + (result.size() - 1), result.begin() + result.size());
		}
	}
}

void process_result(vector<int> result, int &count) {
	for (int i = 0;i < result.size();i++) {
		cout << result[i]<<" ";
	}
	cout << "\n";
}
