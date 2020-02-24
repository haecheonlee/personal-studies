#include <iostream>

using namespace std;

bool check[10000001] {false};
int main() {
	int n,m,num;
	cin>>n>>m;
	
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		check[arr[i]]=true;
	}
	
	int cnt=0;
	for(int i=0; i<n; i++) {
		if(m-arr[i]>0) {
			if(check[m-arr[i]] && arr[i]!=m-arr[i]) {
				check[arr[i]]=check[m-arr[i]]=false;
				cnt++;
			}
		}
	}
	cout<<cnt;
	
	return 0;
}

/*
boj.kr/1940

INPUT:
6
9
2 7 4 1 5 3

OUTPUT:
2
*/
