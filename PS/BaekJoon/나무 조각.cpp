#include <iostream>
#include <vector>

using namespace std;
const int N=5;

vector<int> a(N);

bool is_done() {
	for(int i=0; i<N; i++) {
		if(a[i]!=i+1) return false;
	}
	
	return true;
}

void print() {
	for(auto &x : a) cout<<x<<" ";
	cout<<'\n';
}

int main() {
	for(int i=0; i<N; i++) cin>>a[i];

	while(is_done()==false) {
		for(int i=0; i<N-1; i++) {
			if(a[i]>a[i+1]) {
				swap(a[i],a[i+1]);
				print();
			}
		}
	}
	
	return 0;
}
