#include <iostream>
#include <queue>
#include <climits>


using namespace std;

int *BFS(int **graph, queue<int> que, int nvertex, bool *visited) {
	int weight = INT_MAX;
	int connected = 0;
	int * edge = new int[2]{ 0 };
	int vertex = 0;
	while (!que.empty()) {
		int cur = que.front();
		for (int i = 0;i < nvertex;i++) {
			if (graph[cur][i] < weight && graph[cur][i] != 0 && !visited[i]) {
				vertex = cur;
				weight = graph[cur][i];
				connected = i;
			}
		}
		que.pop();
	}
	cout << "weight: " << weight<< " ";
	edge[0] = vertex;
	edge[1] = connected;
	return edge;
}

void prim(int **graph, int start, int nvertex) {
	bool *visited = new bool [nvertex] {false};
	visited[start] = true;
	queue<int> que;
	que.push(start);
	bool all_visited = false;
	while (!all_visited) {
		int *edge = BFS(graph, que, nvertex, visited);
		int count = 0;
		cout << "edge: ";
		cout << edge[0] << "-" << edge[1];
		cout << "\n";
		visited[edge[1]] = true;
		for (int i = 0;i < nvertex;i++) {
			if (visited[i]){
				que.push(i);
				count += 1;
			}
		}
		if (count >= nvertex) all_visited = true;
	}
}

int main() {
	int V = 5;
	int **graph = new int*[V];
	for (int i = 0;i < V;i++) {
		int *temp = new int [V] {0};
		
		graph[i] = temp;
	}

	graph[0][1] = 2;
	graph[0][3] = 6;
	graph[1][0] = 2;
	graph[1][2] = 3;
	graph[1][3] = 8;
	graph[1][4] = 5;
	graph[2][1] = 3;
	graph[2][4] = 7;
	graph[3][0] = 6;
	graph[3][1] = 8;
	graph[3][4] = 9;
	graph[4][1] = 5;
	graph[4][2] = 7;
	graph[4][3] = 9;

	prim(graph, 0, V);

}
