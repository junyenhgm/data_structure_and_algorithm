int find_root(int *parent, int n)
{
    // If input is the root, then return itself.
    if (n == parent[n]) {
        return n;
    }

    /* Compress the path during traversal */
    // find the root of n's parent
    parent[n] = find_root(parent, parent[n]);

    return parent[n];
}

void union_set(int *parent, int *rank, int x, int y)
{
    int root_x = find_root(parent, x);
    int root_y = find_root(parent, y);

    if (root_x != root_y) {
        // Meger low rank tree into high rank tree
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {  // rank_x == rank_y
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
}

int main(void)
{
    int root[100] = {0};
    int rank[100] = {0};

    for (int i = 0; i < 100; i++) {
        root[i] = i;
    }
}
