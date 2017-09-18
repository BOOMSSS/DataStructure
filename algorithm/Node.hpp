#ifndef NODE
struct node {
  int s, t, weight;
  node(){}
  node(int _s, int _t, int _weight):s(_s), t(_t), weight(_weight){}
};
#define NODE
#endif
