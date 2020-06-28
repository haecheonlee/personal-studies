#include <iostream>
#include <algorithm>

using namespace std;

int d1[3];
int d2[3];

int main() {
	int n;
	cin>>n;

	for(int i=0; i<n; i++) {
		int a,b,c;
		cin>>a>>b>>c;
		
		if(i==0) {
			d1[0]=d2[0]=a;
			d1[1]=d2[1]=b;
			d1[2]=d2[2]=c;
		} else {
			int mx_a=d1[0], mx_b=d1[1], mx_c=d1[2];
			int mn_a=d2[0], mn_b=d2[1], mn_c=d2[2];
			
			d1[0]=max(mx_a,mx_b)+a;
			d1[1]=max({mx_a,mx_b,mx_c})+b;
			d1[2]=max(mx_b,mx_c)+c;

			d2[0]=min(mn_a,mn_b)+a;
			d2[1]=min({mn_a,mn_b,mn_c})+b;
			d2[2]=min(mn_b,mn_c)+c;
		}
	}
	
	cout<<max({d1[0],d1[1],d1[2]})<<" "<<min({d2[0],d2[1],d2[2]});

	return 0;
}
