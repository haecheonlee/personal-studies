#include <iostream>

using namespace std;

int main() {
	int n,b,h,w;
	int min,p,sum,a;
	cin>>n>>b>>h>>w;
	
	min=b+1;
	for(int i=0; i<h; i++) {
		cin>>p;
		sum=0;
		for(int k=0; k<w; k++) {
			cin>>a;
			if(a>=n) sum=p*n;
		}
		if(min>sum && sum>0) min=sum;
	}
	
	if(min>b) cout<<"stay home";
	else cout<<min;
	
	return 0;
}

/*
boj.kr/5046

INPUT:
3 1000 2 3
200
0 2 2
300
27 3 20

OUTPUT:
900
*/
