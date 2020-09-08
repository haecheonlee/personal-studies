#include <iostream>

using namespace std;

const int MAX=5e5+1;

char a[MAX];
int R[MAX], B[MAX];
int R_start=-1, R_end=-1, B_start=-1, B_end=-1;

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		cin>>a[i];
		
		R[i]=R[i-1];
		B[i]=B[i-1];
		
		if(a[i]=='R') {
			if(R_start==-1) R_start=i;
			R_end=i;
			R[i]++;
		} else {
			if(B_start==-1) B_start=i;
			B_end=i;
			B[i]++;
		}
	}
	
	if(R_end==-1 || B_end==-1) {
		cout<<0;
	}
	else {
		// moving right, left
		int mR=min(R[B_end-1], B[R_end-1]);
		int mL=min(R[N]-R[B_start], B[N]-B[R_start]);
		
		cout<<min(mR, mL);
	}
	
	return 0;
}
