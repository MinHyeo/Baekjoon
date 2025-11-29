#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	int country, number, score;
};

bool cmp(const Student& a, const Student& b) {
	return a.score > b.score;
}

int main() {
	int n;
	cin >> n;

	vector<Student> students(n);

	for (int i = 0; i < n; i++) {
		cin >> students[i].country >> students[i].number >> students[i].score;
	}

	sort(students.begin(), students.end(), cmp);
	vector<int> selected(101, 0);
	int count = 0;

	for (Student student : students) {
		if (selected[student.country] < 2) {
			cout << student.country << " " << student.number << "\n";
			selected[student.country]++;
			count++;

			if (count >= 3)
				break;
		}
	}

	return 0;
}