#include<iostream>
using namespace std;

class Graph {
    int* nodes;
    int n_nodes;
    int** edges;

    public:
        Graph(int n_nodes) {
            this->n_nodes = n_nodes;
            this->nodes = new int[n_nodes];
            this->edges = new int*[n_nodes];
            for(int i = 0; i < n_nodes; i++) {
                this->nodes[i] = i;
                this->edges[i] = new int[n_nodes];

                for(int j = 0; j < n_nodes; j++) {
                    this->edges[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v) {
            this->edges[u][v] = 1;
            this->edges[v][u] = 1;
        }

        bool isEdge(int u, int v) {
            return this->edges[u][v] == 1;
        }

        void previsit() {
            return;
        }

        void postvisit() {
            return;
        }

        void explore(int node, bool *visited) {
            visited[node] = true;
            cout<<node<<endl;
            
            previsit();

            for(int i = 0; i < this->n_nodes; i++) {
                if((isEdge(node, i)) && (!visited[i])) {
                    explore(i, visited);
                }
            }

            postvisit();
        }

        void dfs() {
            bool *visited = new bool[this->n_nodes];

            for(int i = 0; i < this->n_nodes; i++) {
                visited[i] = false;
            }

            for(int i = 0; i < this->n_nodes; i++) {
                if(!visited[i]) {
                    explore(i, visited);
                }
            }
        }
};

int main() {
    Graph* g = new Graph(12);
    // A = 0
    // B = 1
    // C = 2
    // D = 3
    // E = 4
    // F = 5
    // G = 6
    // H = 7
    // I = 8
    // J = 9
    // K = 10
    // L = 11
    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(4, 8);
    g->addEdge(8, 9);
    g->addEdge(4, 9);
    g->addEdge(2, 3);
    g->addEdge(2, 7);
    g->addEdge(2, 6);
    g->addEdge(6, 7);
    g->addEdge(6, 10);
    g->addEdge(10, 7);
    g->addEdge(3, 7);
    g->addEdge(7, 11);

    g->dfs();
    return 0;
}