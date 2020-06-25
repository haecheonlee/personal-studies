#include <iostream>
#include <cstring>

using namespace std;

int a[]={1,2,5,7};
int d[100001];

int main() {
	int n;
	cin>>n;

	memset(d,-1,sizeof(d));
	d[0]=0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<=n; j++) {
			if(j-a[i]>=0 && d[j-a[i]]!=-1) {
				if(d[j]==-1 || d[j]>d[j-a[i]]+1) d[j]=d[j-a[i]]+1;
			}	
		}
	}
	cout<<d[n];
	
	return 0;
}
