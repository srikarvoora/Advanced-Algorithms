#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <sstream> // Include this for stringstream
using namespace std;

// Function to convert int to string
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Structure to represent a node and its distance from the source
struct Node {
    int vertex;
    int distance;

    // Add this operator for comparison in the priority queue
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Function to implement Dijkstra's Algorithm
void dijkstra(vector<vector<pair<int, int> > >& graph, int source) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    distances[source] = 0;
    pq.push({source, 0});

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        // Replace range-based for loop with traditional for loop
        for (size_t i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({v, distances[v]});
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << (distances[i] == INT_MAX ? "INF" : intToString(distances[i])) << "\n";
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<pair<int, int> > > graph(numVertices);

    cout << "Enter the edges and their weights (format: u v weight):\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}

