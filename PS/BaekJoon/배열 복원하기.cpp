#include <iostream>

using namespace std;

int main() {
	int H,W,X,Y;
	cin>>H>>W>>X>>Y;
	
	int H2=H+X, W2=W+Y;
	
	int B[H2][W2];
	for(int i=0; i<H2; i++) {
		for(int j=0; j<W2; j++) cin>>B[i][j];
	}

	int A[H][W] {0};
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			A[i][j]=B[i][j];
			if(i-X>=0 && j-Y>=0) A[i][j]-=A[i-X][j-Y];
		}
	}
	
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) cout<<A[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}
