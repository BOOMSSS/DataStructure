＃ 数据结构课程总结


公共基础类：

node

公共接口：
vector<node> get_all_edges();
void add(int from, int to, int weight);

最短路：

vector<vector<int> > GetAns()
返回一个vector<vector<int> >作为答案。

最小生成树：

pair<int, vector<node > > getMST();
前者是最小生成树的路径长度，后者是最小生成树中的边。

顺序：

void add(int from, int to); from 依赖 to
vector<int> getOrder(); 得到装配顺序
