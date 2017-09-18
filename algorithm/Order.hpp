#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include "Node.hpp"

using namespace std;

struct Order {

    static const int maxn = 100;

    vector<int> G[maxn];
    int vis[maxn];
    vector<int> ret;

    void dfs(int x) {
        ret.push_back(x);
        vis[x] = 0;
        for (int i = 0; i < G[x].size(); i++) {
            if (vis[G[x][i]])
                dfs(G[x][i]);
        }
    }

    vector<int> getOrder(int begin) {
        memset(vis, 1, sizeof(vis));
        ret.clear();
        dfs(begin);
        return ret;
    }

    void add(int from, int to) {
        G[from].push_back(to);
    }

    vector<node> get_all_edges() {
        vector<node> ret;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < G[i].size(); j++) {
                ret.push_back(node(i, G[i][j], 1));
            }
        }
        return ret;
    }

};
