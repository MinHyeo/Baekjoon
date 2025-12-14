#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	int num;
	int cnt;
	int order;
};

bool CompareForDelete(const Student& a, const Student& b) {
	if (a.cnt == b.cnt) {
		return a.order < b.order;
	}
	return a.cnt < b.cnt;
}

bool CompareByNum(const Student& a, const Student& b) {
	return a.num < b.num;
}

int main() {
	int n;
	cin >> n;

	int students;
	cin >> students;

	vector<Student> v;
	for (int i = 0; i < students; i++) {
		int num;
		cin >> num;

		bool is_found = false;
		for (Student& student : v) {
			if (student.num == num) {
				is_found = true;
				student.cnt++;
				break;
			}
		}
		if (is_found)
			continue;

		if (v.size() >= n) {
			sort(v.begin(), v.end(), CompareForDelete);
			v.erase(v.begin());
		}
		v.push_back({ num, 1, i });
	}

	sort(v.begin(), v.end(), CompareByNum);
	for (Student student : v) {
		cout << student.num << " ";
	}
	cout << "\n";

	return 0;
}