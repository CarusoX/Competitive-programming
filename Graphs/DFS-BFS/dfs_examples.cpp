#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb push_back
#define fst first
#define snd second

const int N = 100000;

int n;

// Tree //

vector<int> tree[N];
int depth[N];
int sz[N];

// Depth of every vertex
void leveldfs(int node, int father = -1, int level = 0) {
    depth[node] = level;
    for(int child : tree[node]) if(child != father) {
        leveldfs(child, node, level + 1);
    }
}

// Size of the subtree of every vertex (including the vertex)
int szdfs(int node, int father = -1) {
    int r = 1;
    for(int child : tree[node]) if(child != father) {
        r += szdfs(child, node);
    }
    return r;
}

int main() {
    // Input is 1-based but we process them 0-based (vertex 1 is vertex 0)
    cin >> n;
    fore(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    leveldfs(0);
    szdfs(0);

    // q querys about depth and size
    int q; cin >> q;

    while(q--) {
        int option, vertex; cin >> option >> vertex;
        if(option == 1) cout << depth[vertex - 1] << endl;
        else cout << sz[vertex - 1] << endl;
    }
    return 0;
}

