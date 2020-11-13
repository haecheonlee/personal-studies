#include <iostream>
#include <set>

using namespace std;

const int MAX = 1e5 + 1;

int cnt[MAX];

int main() {
	int N;
	cin >> N;

	set<int> list;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;

		list.insert(x);
		cnt[x]++;
	}

	bool check = true;
	for(auto it : list) {
		if((cnt[it] & 1)) check = false;
	}
	cout << ((!check) ? "Conan" : "Agasa");

	return 0;
}
