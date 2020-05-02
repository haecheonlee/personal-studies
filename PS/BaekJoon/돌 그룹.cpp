#include <iostream>

using namespace std;

bool check[501][501];
int sum;

void go(int x, int y) {
	if(check[x][y]) return;
    
    check[x][y]=true;
	int a[3]={x,y,sum-x-y};
    
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(a[i]<a[j]) {
				int b[3]={x,y,sum-x-y};
				b[i]+=a[i];
				b[j]-=a[i];
				go(b[0],b[1]);
			}
		}
	}
}

int main() {
	int x,y,z;
	cin>>x>>y>>z;
	
	sum=x+y+z;
	
	if(sum%3!=0) {
		cout<<0;
	} else {
		go(x,y);
		
		if(check[sum/3][sum/3]) cout<<1;
		else cout<<0;
	}

	return 0;
}

/*
INPUT:
10 15 35

OUTPUT:
1
*/
