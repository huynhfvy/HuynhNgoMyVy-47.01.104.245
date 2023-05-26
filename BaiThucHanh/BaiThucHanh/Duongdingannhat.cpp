#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<vector<int> > floyd(int n, int u, int v, vector<vector<int> >& graph) {
    vector<vector<int> > dist(n, vector<int>(n, INF));
    vector<vector<int> > next(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j) {
                next[i][j] = j;
            }
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }


    if (dist[u][v] == INF) {
        return { {-1} };
    }


    vector<int> path;
    int curr = u;
    while (curr != v) {
        path.push_back(curr);
        curr = next[curr][v];
    }
    path.push_back(v);

    return { path, {dist[u][v]} };
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;

    vector<vector<int> > graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    vector<vector<int>> result = floyd(n, u - 1, v - 1, graph);

    if (result[0][0] == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << result[1][0] << endl;
        for (int i = 0; i < result[0].size(); i++) {
            cout << result[0][i] + 1;
            if (i != result[0].size() - 1) {
                cout << "->";
            }
        }
        cout << endl;
    }

    return 0;
}
