#include <iostream>

using namespace std;

bool broken[100001];
int main() {
	int n,b,k,num;
	cin>>n>>b>>k;
	
	for(int i=0; i<k; i++) {
		cin>>num;
		broken[num]=true;
	}

	int least=k;
	int cnt=0;
	for(int i=1; i<=b; i++) {
		if(broken[i]) cnt++;
	}
	
	for(int i=2; i<=n; i++) {
		if(i+b-1>n) break;
		
		if(broken[i-1]) if(cnt>0) cnt--;
		if(broken[i+b-1]) cnt++;
		
		least=min(cnt,least);
	}
	
	cout<<least;
	
	return 0;
}

/*
boj.kr/14465

INPUT:
10 6 5
2
10
1
5
9

OUTPUT:
1
*/
