#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int korean;
	int english;
	int math;
};

bool compare(Student a, Student b) {
	if (a.korean != b.korean)
		return a.korean > b.korean;
	if (a.english != b.english)
		return a.english < b.english;
	if (a.math != b.math)
		return a.math > b.math;

	return a.name < b.name;
}

int main() {
	int n;
	cin >> n;

	vector<Student> students(n);
	for (int i = 0; i < n; i++) {
		cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
	}

	sort(students.begin(), students.end(), compare);

	for (Student student : students) {
		cout << student.name << "\n";
	}

	return 0;
}