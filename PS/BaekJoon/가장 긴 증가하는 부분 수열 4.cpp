#include <iostream>

using namespace std;

int A[1001], DP[1001], V[1001];

void print(int index) {
	if(index==0) return;
	
	print(V[index]);
	cout<<A[index]<<" ";
}

int main() {
	int N;
	cin>>N;
	
	int current_max=-1, current_index=-1;
	for(int i=1; i<=N; i++) {
		cin>>A[i];
		
		DP[i]=1; V[i]=0;
		for(int j=i-1; j>=0; j--) {
			if(A[i]>A[j] && DP[i]<=DP[j]) {
				DP[i]=DP[j]+1;
				V[i]=j;
			}
		}
		
		if(DP[i]>current_max) { 
			current_max=DP[i];
			current_index=i;
		}
	}
	
	cout<<current_max<<endl;
	print(current_index);
	
	return 0;
}

/*
boj.kr/14002

INPUT:
6
10 20 10 30 20 50

OUTPUT:
4
10 20 30 50
*/
