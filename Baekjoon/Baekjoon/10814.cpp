#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Member {
	int age;
	string name;
	int order;
};

bool compare(const Member& a, const Member& b) {
	if (a.age == b.age) {
		return a.order < b.order;
	}
	return a.age < b.age;
}

int main() {
	int n;
	cin >> n;

	vector<Member> members(n);

	for (int i = 0; i < n; i++) {
		cin >> members[i].age >> members[i].name;
		members[i].order = i;
	}
	stable_sort(members.begin(), members.end(), compare);

	for (const auto& member : members) {
		cout << member.age << " " << member.name << "\n";
	}

	return 0;
}