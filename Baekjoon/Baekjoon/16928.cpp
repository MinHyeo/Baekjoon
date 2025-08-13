#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int map[100] = { 0 };
    vector<pair<int, int>> ladder(n), snake(m);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ladder[i] = { a, b };
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        snake[i] = { a, b };
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int index = q.front();
        q.pop();

        if (index == 99) {
            break;
        }
        int count = map[index];

        count++;
        for (int i = 1; i <= 6; i++) {
            int next = index + i;
            if (next >= 100)
                continue;

            for (int j = 0; j < n; j++) {
                if (ladder[j].first - 1 == next) {
                    next = ladder[j].second - 1;
                }
            }
            for (int j = 0; j < m; j++) {
                if (snake[j].first - 1 == next) {
                    next = snake[j].second - 1;
                }
            }
            if (map[next] > count || map[next] == 0) {
                map[next] = count;
                q.push(next);
            }
        }
    }
    cout << map[99] << "\n";

    return 0;
}