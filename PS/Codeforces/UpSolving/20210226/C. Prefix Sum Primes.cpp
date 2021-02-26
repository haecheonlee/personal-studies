#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> one, two;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		
		if(x == 1) one.push_back(x);
		else two.push_back(x);
	}
	
	int sum = 0;
	if(!two.empty()) {
		cout << 2 << ' ';
		two.pop_back();
	}
	
	if(!one.empty()) {
		cout << 1 << ' ';
		one.pop_back();
	}
	
	while(!two.empty()) {
		cout << 2 << ' ';
		two.pop_back();
	}
	
	while(!one.empty()) {
		cout << 1 << ' ';
		one.pop_back();
	}

	return 0;
}
