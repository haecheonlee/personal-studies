#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N, K, M;
	cin >> N >> K >> M;
	
	deque<int> dq;
	for(int i = 1; i <= N; i++) dq.push_back(i);

	int cnt = 0, removed = 0;
	bool dir = 0;			// 0: going right, 1: going left
	while(!dq.empty()) {
		int x = (dir ? dq.back() : dq.front());
		cnt++;
		
		if(cnt % K == 0) {
			cout << x << ' ';
			cnt = 0;
			removed++;
			if(dir) dq.pop_back(); else dq.pop_front();
		} else {
			if(dir) {
				dq.pop_back();
				dq.push_front(x);
			} else {
				dq.pop_front();
				dq.push_back(x);
			}
		}
		
		if (removed == M) removed = 0, dir = !dir;
	}

	return 0;
}
