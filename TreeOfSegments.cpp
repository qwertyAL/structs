#include <iostream>
#include <vector>

struct Node {
    int sum, l, r;

    Node(int l, int r, int sum) {
        this -> l = l;
        this -> r = r;
        this -> sum = sum;
    }
};

std::vector<int> a;
std::vector<Node> Tree;

void rep(int pos, int i, int val) {
    if(Tree[i].r - Tree[i].l == 1 && Tree[i].l == pos) {
        Tree[i].sum = val;
    }

    int m = (Tree[i].r + Tree[i].l) / 2;

    if(pos < m) {
        rep(pos, 2 * i + 1, val);
    }
    else {
        rep(pos, 2 * i + 2, val);
    }

    Tree[i].sum = Tree[2 * i + 1].sum + Tree[2 * i + 2].sum;
}

void build(int i, int l, int r) {
    if(r-l == 1) {
        Tree[i] = Node(l, r, a[l]);
    }
    else {
        int m = (l+r)/2;
        build(2*i+1, l, m);
        build(2*i+2, m, r);
        Tree[i] = Node(l, r, Tree[2*i+1].sum + Tree[2*i+2].sum);
    }
}

int get(int i, int l, int r) {
    if(Tree[i].l >= r || Tree[i].r <= l) {
        return 0;
    }
    if(Tree[i].l >= l && Tree[i].r <= r) {
        return Tree[i].sum;
    }
    return get(2*i+1, l, r) + get(2*i+2, l, r);
}



void solve() {
    int n;
    std::cin >> n;

    a.resize(n);
    Tree.resize(n * 4, Node(-1, -1, 0));

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    build(0, 0, n);

    int l, r;
    std::cin >> l >> r;
    std::cout << get(0, l-1, r);
}

signed main() {
    solve();
    return 0;
}
