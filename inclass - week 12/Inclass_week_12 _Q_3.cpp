#include <iostream>
#include <limits>
#include <vector>

using namespace std;

#define INF 999

int findMinDistance(const std::vector<int>& dist, const std::vector<bool>& visited) {
    int minDist = INF;
    int minIndex = -1;
    for (int i = 0; i < dist.size(); ++i) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();

    std::vector<int> dist(n, INF);
    std::vector<bool> visited(n, false);

    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = findMinDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    
    for (int i = 0; i < n; ++i) {
        std::cout << "from City "<< start << " to City "<<i << "\t" <<"->"<<"\t"<< "Distance: "<< dist[i] << "\n";
    }
}

int main() {
    
    int startNode ;
    cout << "Starting City: ";
    cin >>  startNode ;
    cout<<endl;

    std::vector<std::vector<int>> adjacencyMatrix = {
        {0 ,10 , 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    dijkstra(adjacencyMatrix, startNode);

    return 0;
}
