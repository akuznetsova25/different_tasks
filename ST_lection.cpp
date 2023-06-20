#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> segment_tree;
std::vector<int> arr;

//1-ый int - значение, 2-й - обещание

void update(int v, int a, int b, int l, int r, int d) {
    if ((l <= a) && (r >= b)) {
        segment_tree[v].second += d;
        return;
    }
    if (a > r || b < l) {
        return;
    }
    int m = (a + b) / 2;
    update(2*v, a, m, l, r, d);
    update(2 * v + 1, m + 1, b, l, r, d);
}


int get(int v, int a, int b, int pos) {
    if (a == b) {
        return segment_tree[v].first + segment_tree[v].second;
    }
    int m = (a + b) / 2;
    int res = 0;
    if (pos <= m) {
        res += get(2*v, a, m, pos);
    }
    else {
        res += get(2 * v + 1, m + 1, b, pos);
    }
}


void build(int v, int l, int r) {
    if (l == r) {
        segment_tree[v].first = arr[l - 1];
        return;
    }
}


void push(int v) {
    if (2 * v >= segment_tree.size()) {
        return;
    }
    segment_tree[v].first += segment_tree[v].second;
    segment_tree[2 * v].second += segment_tree[v].second;
    segment_tree[2 * v + 1].second += segment_tree[v].second;
    segment_tree[v].second = 0;
}

void build() {
    for (int i = 0; i < arr.size(); ++i) {
        segment_tree[i + segment_tree.size() / 2].first = arr[i];
    }
    //for(int i = segment_tree)
}


int get(int v, int a, int b, int l, int r) {
    if ((b < l) || (a > r)) {
        return;
    }
    if ((l <= a) && (r >= b)) {
        push(v);
        return segment_tree[v].first;
    }
    int m = (a + b) / 2;
    return max(get(2*v, a, m, l, r), get(2*v + 1, m + 1, b, l, r));
}

int main()
{
    std::cout << "Hello World!\n";
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
