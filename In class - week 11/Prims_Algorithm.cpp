#include <iostream>
#include <vector>
using namespace std;

#define INF 9999999

// number of vertices in graph
#define V 6

int main() {
    int no_edge;  // number of edges

    // create an array to track selected vertex
    // selected will become true otherwise false
    vector<bool> selected(V, false);

    // set number of edges to 0
    no_edge = 0;

    int startVertex;
    cout << "Enter the starting node: ";
    cin >> startVertex;

    // choose the starting vertex and make it true
    selected[startVertex] = true;

    size_t x;  // row number
    size_t y;  // col number

    // create a 2D vector for adjacency matrix to represent graph
    vector<vector<int>> G = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    // print for edge and weight
    cout << endl;
    while (no_edge < V - 1) {
        // For every vertex in the set S, find all adjacent vertices
        // and calculate the distance from the vertex selected at step 1.
        // If the vertex is already in the set S, discard it, otherwise
        // choose another vertex nearest to the selected vertex at step 1.

        int min = INF;
        x = 0;
        y = 0;

        for (size_t i = 0; i < V; i++) {
            if (selected[i]) {
                for (size_t j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << "Edge (" << x << " - " << y << ") : weight - " << G[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }
    cout<<endl;

    return 0;
}
