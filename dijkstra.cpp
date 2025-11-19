const int N = 1e5 + 5; 
const int INF = 1e9;

vector<pair<int, int>> g[N]; 
int dist[N];                 
bool vis[N];             

void dijkstra(int source, int n) {
    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}
