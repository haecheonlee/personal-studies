#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

vector<pii> a;
int d[10];

int main() {
	int N;
	cin >> N;

	memset(d, -1, sizeof(d));
	for(int i = 0; i < N; i++) {
		int p;
		string type;
		
		cin >> p >> type;
		
		int state = 0;
		for(auto& s : type) {
			if(s == 'A') state |= (1 << 0);
			if(s == 'B') state |= (1 << 1);
			if(s == 'C') state |= (1 << 2);
		}
		
		if(d[state] == -1 || d[state] > p) d[state] = p;
	}
	
	for(int i = 1; i < (1 << 3); i++) {
		if(d[i] == -1) continue;
		for(int j = 1; j < (1 << 3); j++) {
			if(i == j || d[j] == -1) continue;
			if(d[i | j] == -1 || d[i | j] > d[i] + d[j]) 
				d[i | j] = d[i] + d[j];
		}
	}
	cout << d[7];

	return 0;
}
