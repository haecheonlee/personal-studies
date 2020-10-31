/* reference: newdeal's idea */

#include <iostream>
#include <cstring>
#include <set>

using namespace std;

const int MAX = 1e3 + 1;

int a[MAX];
int d[10001];

int main() {
	int N,M;
	cin>>N>>M;
	
	set<int> list;
	for(int i = 0; i < M; i++) {
		cin>>a[i];
		list.insert(a[i]);	
	}
	
	for(int i = 0; i < M; i++) {
		for(int j = i + 1; j < M; j++) {
			if(a[i] + a[j] <= N) list.insert(a[i] + a[j]);
		}
	}
	
	memset(d, -1, sizeof(d));
	d[0] = 0;
	for(auto& x : list) {
		for(int i = 1; i <= N; i++) {
			if(i - x >= 0 && d[i - x] != -1) {
				if(d[i] == -1 || d[i] > d[i - x] + 1) d[i] = d[i - x] + 1;
			}
		}
	}
	
	cout<<d[N];
	
	return 0;
}
