#include <iostream>

using namespace std;

int V[16]{0}, T[16]{0}, P[16]{0};
int main() {
	int N;
	cin>>N;
	
	int m=0;
	for(int i=1; i<=N; i++) {
		cin>>T[i]>>P[i];
		
		if(i+T[i]<=N+1){
			V[i]=P[i];
			for(int j=1; j<=i; j++) {
				if(j+T[j]<=i) V[i]=max(V[i], P[i]+V[j]);
			}
		}
		
		m=max(V[i], m);;
	}
	
	cout<<m;
	return 0;
}

/*
boj.kr/14501

INPUT:
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200

OUTPUT:
45
*/
