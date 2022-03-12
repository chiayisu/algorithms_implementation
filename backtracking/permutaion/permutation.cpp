#include <iostream>
#include <vector>

using namespace std;

void printresult(vector<int> &result, vector <vector<int>> &answer_list);
void permutation(int n, vector<int> result, int max, vector <vector<int>> &answer_list);
vector<int> construct_answer(int n, vector<int> result, int max);

int main()
{
	int n = 3;
	vector<int> result;
	vector <vector<int>> answer_list;
	for (int i = 0;i < n;i++)
		permutation(i, result, n, answer_list);
	return 0;
}

void permutation(int n, vector<int>result, int max, vector <vector<int>> &answer_list) {
	if (result.size() == max) printresult(result, answer_list);
	else {
		vector<int> answer = construct_answer(n, result, max);
		if (find(result.begin(), result.end(), n) == result.end())
			result.push_back(n);
		for (int i = 0;i < answer.size();i++) {
			permutation(answer[i], result, max, answer_list);
		}
	}
}

void printresult(vector<int> &result, vector <vector<int>> &answer_list) {
	if (find(answer_list.begin(), answer_list.end(), result) == answer_list.end()) {
		answer_list.push_back(result);
		for (int i = 0;i < result.size();i++)
			cout << result[i] << " ";
		cout << "\n";
	}
	result.clear();
}

vector<int> construct_answer(int n, vector<int> result, int max) {
	vector<int>answer;
	for (int i = 0;i < max;i++)
		if (find(result.begin(), result.end(), i) == result.end()) answer.push_back(i);

	return answer;
}
