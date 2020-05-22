#include <iostream>

using namespace std;

int n,m;
int cnt=0;
bool check[10];

void go(int index, int used) {
	if(index==n) {
		if(used==m) cnt++;
		return;
	}
	
	for(int i=0; i<=9; i++) {
		if(check[i]) {
			check[i]=false;
			go(index+1, used+1);
			check[i]=true;
		} else {
			go(index+1, used);
		}
	}
}

int main() {
	cin>>n>>m;
	
	int x;
	for(int i=0; i<m; i++) {
		cin>>x;
		check[x]=true;
	}
	
	go(0,0);
	cout<<cnt;

	return 0;
}
