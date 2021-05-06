#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> a;
	
	for(int i = 19; i <= 15000000; i++) {
		string s = to_string(i);
		int sum = 0;
		for(auto& x : s) sum += (x - '0');
		if(sum == 10) a.push_back(i);
	}
	
	int N; cin >> N;
	cout << a[N - 1] << '\n';
	
	return 0;
}
