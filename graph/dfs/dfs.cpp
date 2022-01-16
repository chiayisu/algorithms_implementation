#include <iostream>

using namespace std;

void dfs(int **adj, bool *traversed, int start, int nvertex ) {
	if (!traversed[start]) {
		traversed[start] = true;
		cout << start;
		cout << "\n";
		for (int i = 0;i < nvertex;i++) if (adj[start][i] == 1 && !traversed[i]) dfs(adj, traversed, i, nvertex);
	}
}

int main()
{
	int nvertex = 8;
	int **adj_matrix = new int *[nvertex];
	bool * traversed = new bool[nvertex]{ false };
	for (int i = 0;i < nvertex;i++) {
		int *temp = new int[nvertex]{ 0 };
		adj_matrix[i] = temp;
	}
	adj_matrix[0][1] = 1;
	adj_matrix[1][0] = 1;
	adj_matrix[0][6] = 1;
	adj_matrix[6][0] = 1;
	adj_matrix[0][7] = 1;
	adj_matrix[7][0] = 1;
	adj_matrix[1][2] = 1;
	adj_matrix[2][1] = 1;
	adj_matrix[1][4] = 1;
	adj_matrix[4][1] = 1;
	adj_matrix[2][3] = 1;
	adj_matrix[3][2] = 1;
	adj_matrix[4][5] = 1;
	adj_matrix[5][4] = 1;
	for (int i = 0;i < nvertex;i++)
		dfs(adj_matrix, traversed, 0, nvertex);
	return 0;
}