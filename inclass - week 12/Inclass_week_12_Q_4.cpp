#include <iostream>
#include <limits>
#include <vector>
#include <numeric>
#include <algorithm>

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

float dijkstra(const std::vector<std::vector<int>>& graph, int start) {
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

    
    float average_distance = (accumulate(dist.begin(), dist.end(), 0))/5.0;
    return average_distance;
}

vector<int> findMinIndexes(const std::vector<float>& numbers) {
    vector<int> minIndexes;
    auto minElement = min_element(numbers.begin(), numbers.end());
    auto minValue = *minElement;

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it == minValue) {
            minIndexes.push_back(distance(numbers.begin(), it));
        }
    }
    cout << "Average Minimum Time: " << minValue;
    return minIndexes;
}


int main() {
    
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0 ,10 , 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    vector<float> average_dist_list;
    for (int i =0 ; i <= 5 ; i++){
        average_dist_list.push_back(dijkstra(adjacencyMatrix, i));
    }
    
    cout<<endl;
    vector<int> minimum_dist_city = findMinIndexes(average_dist_list);
    cout<<endl;
    cout << "The city with the smallest average time: "<< endl;

    for (auto i:minimum_dist_city){
        cout << "City " << i << endl;
    }
    cout<<endl;
    return 0;
}
