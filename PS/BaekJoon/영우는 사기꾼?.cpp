#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e6+1;

vector<int> a[MAX];
int in[MAX];
bool check[MAX];

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0; i<m; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x].push_back(y);
		in[y]++;
	}


	for(int i=0; i<k; i++) {
		int order, x;
		cin>>order>>x;
		
		if(order==1) {
			// to construct
			if(in[x]!=0) {
				cout<<"Lier!";
				return 0;
			} else {
				check[x]=true;
				for(int y : a[x]) {
					if(in[y]>0) in[y]--;
				}
			}
		} else {
			// to destroy
			if(in[x]>0 || check[x]==false) {
				cout<<"Lier!";
				return 0;
			} 
		}
	}

	cout<<"King-God-Emperor";

	return 0;
}
