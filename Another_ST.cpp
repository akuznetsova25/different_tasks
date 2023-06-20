#include <iostream>
#include <vector>

class SegmentTree {
public:
    explicit SegmentTree(const std::vector<size_t> &arr);
    unsigned long GetSum(size_t left, size_t right) const;
    void Update(size_t ind, size_t delta);
private:
    size_t size_;
    std::vector<size_t> tree_;
};

SegmentTree::SegmentTree(const std::vector<size_t> &arr) {
    size_t degree = 0;
    size_t vector_length = arr.size();
    while((1 << degree) < vector_length) {
        ++degree;
    }
    size_ = 1 << (degree + 1);
    tree_.resize(size_);
    for (size_t i = 0; i < size_ / 2; ++i) {
        tree_[i] = 0;
    }
    for (size_t i = size_ / 2; i < size_ / 2 + vector_length; ++i) {
        tree_[i] = arr[i - size_ / 2];
    }
    for (size_t i = size_ / 2 + vector_length; i < size_; ++i) {
        tree_[i] = 0;
    }
    for (size_t i = size_ / 2 - 1; i > 0; --i) {
        tree_[i] = tree_[i * 2] + tree_[i * 2 + 1];
    }
}

unsigned long SegmentTree::GetSum(size_t left, size_t right) const {
    left += size_ / 2;
    right += size_ / 2;
    size_t left_res = 0;
    size_t right_res = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            left_res = left_res + tree_[left];
        }
        left = (left + 1) / 2;
        if (right % 2 == 0) {
            right_res = right_res + tree_[right];
        }
        right = (right - 1) / 2;
    }
    return left_res + right_res;
}

void SegmentTree::Update(size_t ind, size_t delta) {
    ind += size_ / 2;
    tree_[ind] = delta;
    while (ind /= 2) {
        tree_[ind] = tree_[ind * 2] + tree_[ind * 2 + 1];
    }
}

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n;

    std::vector<size_t> arr;
    arr.resize(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    SegmentTree tree(arr);

    std::cin >> m;
    char query = 0;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> query;
        if (query == 's') {
            size_t left = 0;
            size_t right = 0;
            std::cin >> left >> right;
            std::cout << tree.GetSum(left - 1, right - 1) << ' ';
        } else {
            size_t ind = 0;
            size_t delta = 0;
            std::cin >> ind >> delta;
            tree.Update(ind - 1, delta);
        }
    }
    return 0;
}