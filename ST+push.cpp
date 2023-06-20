#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> segment_tree;
std::vector<int> arr;

void push(int v) {
    if (2 * v >= segment_tree.size()) {
        return;
    }
    segment_tree[v].first += segment_tree[v].second;
    segment_tree[2 * v].second += segment_tree[v].second;
    segment_tree[2 * v + 1].second += segment_tree[v].second;
    segment_tree[v].second = 0;
}

void build(int n) { //n - st size
    for (int i = 0; i < n; ++i) {
        segment_tree[i + n/2].first = arr[i];
    }
    for (int i = n/2 - 1; i > 0; --i) {
        segment_tree[i].first = std::max(segment_tree[2*i].first, segment_tree[2*i+1].first);
    }
}

void update(int v, int a, int b, int l, int r, int delta) {
    if (l <= a && r >= b) {
        segment_tree[v].second += delta;
        return;
    }
    if (a > r || b < l) {
        return;
    }
    int m = (a + b) / 2;
    update(2 * v, a, m, l, r, delta);
    update(2 * v + 1, m + 1, b, l, r, delta);
}

int get(int v, int a, int b, int l, int r) {
    if (b < l || a > r) {
        return 0;
    }
    if (l <= a && r >= b) {
        push(v);
        return segment_tree[v].first;
    }

    int m = (a + b) / 2;
    return std::max(get(2 * v, a, m, l, r), get(2 * v + 1, m + 1, b, l, r));
}

int main() {
    size_t n, m;
    std::cin >> n;

    arr.resize(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    size_t degree = 0;
    size_t vector_length = arr.size();
    while((1 << degree) < vector_length) {
        ++degree;
    }
    int tree_size = 1 << (degree + 1);

    segment_tree.resize(tree_size);
    build(tree_size);
    // Show(tree_size);

    std::cin >> m;
    char query;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> query;
        if (query == 'a') {
            size_t left, right, value;
            std::cin >> left >> right >> value;
            update(1, tree_size / 2, tree_size - 1, (left - 1) + tree_size / 2, (right - 1)  + tree_size / 2, value);
        } else {
            size_t l, r;
            std::cin >> l >> r;
            std::cout << get(1, tree_size / 2, tree_size - 1, l - 1 + tree_size / 2, r - 1 + tree_size / 2) << '\n';
        }
        // Show(tree_size);
    }
    return 0;
}