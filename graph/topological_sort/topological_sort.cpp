#include <iostream>
#include <stack>

using namespace std;


void topological_sort(int **adj, bool *traversed, int start, int nvertex, stack<int> &sorted){
    if(!traversed[start]){
        traversed[start] = true;
        for(int i = 0;i <nvertex ;i++)if(adj[start][i] == 1&&!traversed[i]) topological_sort(adj, traversed, i, nvertex, sorted);
        sorted.push(start);
    }
    
}

int main(){
    stack<int> sorted;
    int nvertex = 6;
    int **adj_matrix =  new int *[nvertex];
    bool * traversed = new bool [nvertex]{false};
    for (int i = 0;i<nvertex;i++){
        int *temp = new int [nvertex]{0};
        adj_matrix[i] = temp;
    }

    adj_matrix[5][4] = 1;
    adj_matrix[4][3] = 1;
    adj_matrix[3][2] = 1;
    adj_matrix[2][1] = 1;
    adj_matrix[1][0] = 1;

    for(int i = nvertex-1; i>=0;i--)
        topological_sort(adj_matrix, traversed, 5, nvertex, sorted);
    
    while(!sorted.empty()){
        cout<< sorted.top();
        cout<< "\n";
        sorted.pop();
    }
    
    return 0;
}
