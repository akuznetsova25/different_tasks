#include <vector>
#include <iostream>
#include <queue>
#include <utility>

template <typename T>
using matr = std::vector<std::vector<T>>;
struct Chart {
    matr<int> subs;
    int height;
    int width;

    Chart(int N, int M) :
        subs{ N },
        height(N),
        width(M) {
        for (int i = 0; i < N; ++i) {
            subs[i].resize(M);
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int value;
                std::cin >> value;
                if (value == 1 || value == 0) {
                    subs[i][j] = value;
                }
            }
        }
    }
};

void bfs(Chart& chart, std::pair<int, int> start, matr<int> &result) {
    int N = chart.subs.size();
    int M = chart.subs[0].size();

    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, -1, 0, 1 };

    std::queue<std::pair<int, int>> neighbours;

    matr<bool> visited(N);
    for (int i = 0; i < N; ++i) {
        visited[i].resize(M, false);
    }

    neighbours.push(start);
    result[start.first][start.second] = 0;
    visited[start.first][start.second] = true;

    while (!neighbours.empty()) {
        auto n = neighbours.front();
        neighbours.pop();

        for (int i = 0; i < 4; ++i) {
            std::pair next{ n.first + dx[i], n.second + dy[i] };
            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) {
                continue;
            }
            else if (visited[next.first][next.second]) {
                continue;
            }
            else {
                neighbours.push(next);
                visited[next.first][next.second] = true;
                int distance = result[n.first][n.second] + 1;
                if (result[next.first][next.second] == -1) {
                    result[next.first][next.second] = distance;
                }
                else if (result[next.first][next.second] > distance) {
                    result[next.first][next.second] = distance;
                }
            }
        }
    }
}

void print(matr<int>& matr) {
    for (int i = 0; i < matr.size(); ++i) {
        for (int j = 0; j < matr[i].size(); ++j) {
            std::cout << matr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int h, w;
    std::cin >> h >> w;
    Chart map(h, w);

    std::vector<std::pair<int, int>> subways;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (map.subs[i][j] == 1) {
                subways.push_back(std::pair{ i, j });
                
            }
        }
    }
    std::vector<matr<int>> separate(subways.size());
    matr<int> result(h);
    for (int i = 0; i < h; ++i) {
        result[i].resize(w, -1);
    }

    for (int i = 0; i < subways.size(); ++i) {
        bfs(map, subways[i], result);
    }

    print(result);

    return 0;
}