#include <iostream>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 10;

int a[MAX_N];
bool received[MAX_N];
set<int> sender, receiver;

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		
		received[a[i]] = 1;
		if(!a[i]) sender.insert(i);
	}

	for(int i = 1; i <= N; i++) {
		if(!received[i]) receiver.insert(i);
	}
	
	for(auto it = sender.begin(); it != sender.end(); it++) {
		if(received[*it]) continue;
		
		auto it2 = receiver.upper_bound(*it);
		if(it2 == receiver.end()) it2 = receiver.begin();
		a[*it] = *it2;
		receiver.erase(it2);
	}
	
	for(auto it = sender.begin(); it != sender.end(); it++) {
		if(a[*it]) continue;
		
		auto it2 = receiver.upper_bound(*it);
		if(it2 == receiver.end()) it2 = receiver.begin();
		a[*it] = *it2;
		receiver.erase(it2);
	}
	
	for(int i = 1; i <= N; i++) cout << a[i] << ' ';
	
	return 0;
}
