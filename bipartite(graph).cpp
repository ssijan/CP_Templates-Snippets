const int N = 1e5 + 5;
vector<int> g[N];
int color[N]; 
bool is_bipartite = true;

void dfs(int u, int c) {
    color[u] = c;
    for (int v : g[u]) {
        if (color[v] == -1) {
            dfs(v, c ^ 1);
        } else if (color[v] == color[u]) {
            is_bipartite = false;
        }
    }
}
