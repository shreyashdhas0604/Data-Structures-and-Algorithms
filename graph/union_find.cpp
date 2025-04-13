#include <bits/stdc++.h>
using namespace std;

// Union-Find (Disjoint Set Union) implementation
class UnionFind {
    public:
        vector<int> parent, size;
        UnionFind(int n) : parent(n), size(n, 1) {
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        }
        
        bool unite(int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb) return false;
            if (size[pa] < size[pb]) {
                parent[pa] = pb;
                size[pb] += size[pa];
            } else {
                parent[pb] = pa;
                size[pa] += size[pb];
            }
            return true;
        }
};

// Example usage
int main() {
    int n = 10; // Number of elements
    UnionFind uf(n);

    // Union some elements
    uf.unite(1, 2);
    uf.unite(2, 3);
    uf.unite(4, 5);
    uf.unite(6, 7);
    uf.unite(7, 8);

    // Find the root of each element
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i << " is in set: " << uf.find(i) << endl;
    }

    return 0;
}