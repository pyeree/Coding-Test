#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

const int INF = 9999;
const int N = 7;

int graph[N][N] = {
    {0,   4,   5,   INF, INF, INF, INF},   // 1
    {4,   0,   6,   5,   10,  INF, INF},   // 2
    {5,   6,   0,   4,   INF, 9,   INF},   // 3
    {INF, 5,   4,   0,   6,   3,   INF},   // 4
    {INF, 10,  INF, 6,   0,   3,   2},     // 5
    {INF, INF, 9,   3,   3,   0,   2},     // 6
    {INF, INF, INF, INF, 2,   2,   0}      // 7
};
struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

void printPath(const vector<int>& prev, int start, int end) {
    vector<int> path;
    for (int at = end; at != -1; at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());

    if (path[0] != start) {
        cout << "No path\n";
        return;
    }

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] + 1;
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << "\n";
}

void printFloydPath(int i, int j, const vector<vector<int>>& next) {
    if (next[i][j] == -1) {
        cout << "No path\n";
        return;
    }
    cout << i + 1;
    while (i != j) {
        i = next[i][j];
        cout << " -> " << i + 1;
    }
    cout << "\n";
}

void printResult(const string& algoName, int start, const vector<int>& dist, const vector<int>& prev) {
    cout << "========== Node " << start + 1 << " ==========\n";
    for (int i = 0; i < N; i++) {
        if (i == start) continue;
        cout << "[" << start + 1 << " → " << i + 1 << "], cost: " << dist[i] << ", path: ";
        printPath(prev, start, i);
    }
    cout << "\n";
}

void bellmanFord(int start) {
    vector<Edge> edges;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (graph[i][j] != INF && i != j)
                edges.emplace_back(i, j, graph[i][j]);

    vector<int> dist(N, INF);
    vector<int> prev(N, -1);
    dist[start] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.src] != INF && dist[e.src] + e.weight < dist[e.dest]) {
                dist[e.dest] = dist[e.src] + e.weight;
                prev[e.dest] = e.src;
            }
        }
    }

    printResult("Bellman-Ford", start, dist, prev);
}

void dijkstra(int start) {
    vector<int> dist(N, INF);
    vector<int> prev(N, -1);
    vector<bool> visited(N, false);
    dist[start] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1, mn = INF;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < mn) {
                mn = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < N; v++) {
            if (graph[u][v] != INF && dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    printResult("Dijkstra", start, dist, prev);
}

void floydWarshall() {
    vector<vector<int>> dist(N, vector<int>(N));
    vector<vector<int>> next(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
            if (i != j && graph[i][j] != INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }

    for (int i = 0; i < N; i++) {
        cout << "========== Node " << i + 1 << " ==========\n";
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            cout << "[" << i + 1 << " → " << j + 1 << "], cost: " << dist[i][j] << ", path: ";
            printFloydPath(i, j, next);
        }
        cout << "\n";
    }
}

int main() {
    cout << "==============================\n";
    cout << " 1) Bellman-Ford\n";
    cout << "==============================\n";
    for (int start = 0; start < N; start++)
        bellmanFord(start);

    cout << "\n==============================\n";
    cout << " 2) Dijkstra\n";
    cout << "==============================\n";
    for (int start = 0; start < N; start++)
        dijkstra(start);

    cout << "\n==============================\n";
    cout << " 3) Floyd-Warshall\n";
    cout << "==============================\n";
    floydWarshall();

    return 0;
}
