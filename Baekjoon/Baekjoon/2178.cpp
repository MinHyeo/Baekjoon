#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Coordinate {
public:
	int x, y;
	int lenght;

	Coordinate() {
		x = 0;
		y = 0;
		lenght = 1;
	}

	Coordinate(int x, int y, int length) {
		this->x = x;
		this->y = y;
		this->lenght = length;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	string maze[100];
	
	//미로 입력
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	//시작점과 도착점
	Coordinate start;
	Coordinate end(n - 1, m - 1, 0);

	//시작점 찾기
	maze[0][0] = '0';

	queue<Coordinate> q;
	q.push(start);

	while (!q.empty()) {
		Coordinate current = q.front();
		q.pop();

		//도착점에 도착하면 종료
		if (current.x == end.x && current.y == end.y) {
			cout << current.lenght << endl;
			break;
		}

		//상하좌우 이동
		if (current.x - 1 >= 0 && maze[current.x - 1][current.y] == '1') {
			q.push(Coordinate(current.x - 1, current.y, current.lenght + 1));
			maze[current.x - 1][current.y] = '0';
		}
		if (current.x + 1 < n && maze[current.x + 1][current.y] == '1') {
			q.push(Coordinate(current.x + 1, current.y, current.lenght + 1));
			maze[current.x + 1][current.y] = '0';
		}
		if (current.y - 1 >= 0 && maze[current.x][current.y - 1] == '1') {
			q.push(Coordinate(current.x, current.y - 1, current.lenght + 1));
			maze[current.x][current.y - 1] = '0';
		}
		if (current.y + 1 < m && maze[current.x][current.y + 1] == '1') {
			q.push(Coordinate(current.x, current.y + 1, current.lenght + 1));
			maze[current.x][current.y + 1] = '0';
		}
	}
}