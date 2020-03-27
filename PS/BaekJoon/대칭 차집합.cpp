#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	int a[n],b[m];
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	
	sort(a,a+n);
	sort(b,b+m);
	
	int ap=0, bp=0, cnt=0;
	while(ap<n && bp<m) {
		if(a[ap]==b[bp]) ap++, cnt++, bp++;
		else if(a[ap]<b[bp]) ap++;
		else bp++;
	}
	
	cout<<(m-cnt)+(n-cnt);
	
	return 0;
}

/*
INPUT:
3 5
1 2 4
2 3 4 5 6

OUTPUT:
4
*/
