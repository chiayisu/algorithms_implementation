#include <iostream>
#include <map>


using namespace std;

struct Graph{
	pair<char, char> edge;
	int weight;
};

char find(char *parent, char node, map<char, int> hash_table){
	if (node == parent[hash_table[node]])
		return node;
	else{
		node = parent[hash_table[node]];
		return find(parent, node, hash_table);
	}
}

void Kruskal(Graph *graph, char *parent, int nvertex, int nedge, map<char, int> hash_table){
	int count = 0;
		for (int i = 0; i < nedge; i++){
			int node = hash_table[graph[i].edge.second];
			char a = parent[hash_table[graph[i].edge.second]];
			char root = find(parent, graph[i].edge.first, hash_table);
			if (find(parent,graph[i].edge.second, hash_table) != root){
				int index = hash_table[graph[i].edge.second];
				parent[index] = root;
				count++;
				cout << graph[i].edge.first << "-" << graph[i].edge.second;
				cout << "\n";
			}
			if (count == nvertex - 1) break;
		
	}

}



int main(){
	Graph graph;
	int nedge = 12;
	Graph *all_graph = new Graph[nedge];
	int nvertex = 7;
	map<char, int> hash_table = { { 'A', 0 }, { 'B', 1 }, { 'C', 2 }, { 'D', 3 }, { 'E', 4 }, { 'F', 5 }, { 'G', 6 } };
	char *parent = new char[nvertex]{'A', 'B', 'C', 'D', 'E', 'F', 'G'};

	

	graph.edge.first = 'G';
	graph.edge.second = 'F';
	graph.weight = 2;
	all_graph[0] = graph;

	graph.edge.first = 'F';
	graph.edge.second = 'E';
	graph.weight = 2;
	all_graph[1] = graph;

	graph.edge.first = 'F';
	graph.edge.second = 'C';
	graph.weight = 3;
	all_graph[2] = graph;

	graph.edge.first = 'C';
	graph.edge.second = 'E';
	graph.weight = 4;
	all_graph[3] = graph;

	graph.edge.first = 'C';
	graph.edge.second = 'D';
	graph.weight = 4;
	all_graph[4] = graph;

	graph.edge.first = 'G';
	graph.edge.second = 'E';
	graph.weight = 5;
	all_graph[5] = graph;

	graph.edge.first = 'B';
	graph.edge.second = 'A';
	graph.weight = 5;
	all_graph[6] = graph;

	graph.edge.first = 'C';
	graph.edge.second = 'A';
	graph.weight = 7;
	all_graph[7] = graph;

	graph.edge.first = 'F';
	graph.edge.second = 'D';
	graph.weight = 7;
	all_graph[8] = graph;

	graph.edge.first = 'E';
	graph.edge.second = 'B';
	graph.weight = 8;
	all_graph[9] = graph;

	graph.edge.first = 'C';
	graph.edge.second = 'B';
	graph.weight = 9;
	all_graph[10] = graph;

	graph.edge.first = 'D';
	graph.edge.second = 'A';
	graph.weight = 12;
	all_graph[11] = graph;

	Kruskal(all_graph, parent, nvertex, nedge, hash_table);

	return 0;
}
