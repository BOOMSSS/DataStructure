#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.hpp"

#define pr(x) cout << #x << " = " << x << " $";

using namespace std;

/* #define scan(x) scanf("%d", &x) */
/* #define scan2(x, y) scanf("%d%d", &x, &y) */

// support at most 100 points

struct MST{

static const int maxn = 10000 + 1000;
int m, n, p[maxn], r[maxn], u[maxn], v[maxn];
static int w[maxn];
int ans, cnt;
int graph[110][110];
vector<node> ansq;

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

static bool cmp(int i, int j) {
	return w[i] < w[j];
}

void merge(int i, int j) {
	int x = find(i);
	int y = find(j);
	if (x > y) p[y] = x;
	else p[x] = y;
}

void build_graph() {
    cnt = 0;
    ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            int x = graph[i][j];
            if (j > i) {
                w[cnt] = x;
                u[cnt] = i;
                v[cnt] = j;
                cnt++;
            }
        }
    }
}

pair<int, vector<node> > getMST() {
  build_graph();
	sort(r, r + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		int e = r[i];
		int x = find(u[e]);
		int y = find(v[e]);
		if (x != y) {
			ans += w[e];
			p[x] = y;
            ansq.push_back(node(x, y, graph[x][y]));
		}
	}
    return make_pair(ans, ansq);
}

MST() {
    init();
}

void init() {
    ansq.clear();
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < cnt; i++) r[i] = i;
    memset(graph, 0x3e, sizeof(graph));
}

void add(int from, int to, int weight) {
    graph[from][to] = weight;
}

vector<node> get_all_edges() {
    vector<node> ret;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (graph[i][j] < 1e7)
                ret.push_back(node(i, j, graph[i][j]));
        }
    }
    return ret;
}

};


// doc:
// addedge()
// getMST()
