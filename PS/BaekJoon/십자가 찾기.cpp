#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool check[100][100];

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<string> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	vector<tuple<int,int,int>> ans;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]=='*') {
				int l=0;
				for(int k=1;;k++) {
					if(i+k<n && i-k>=0 && j+k<m && j-k>=0) {
						if(a[i+k][j]=='*' && a[i-k][j]=='*' && a[i][j+k]=='*' && a[i][j-k]=='*') l=k;
						else break;
					} else {
                        break;
                    }
				}
                
                if(l>0) {
				    ans.push_back(make_tuple(i+1,j+1,l));
				    check[i][j]=true;
				
				    for(int k=1; k<=l; k++) {
					    check[i+k][j]=true;
					    check[i-k][j]=true;
					    check[i][j+k]=true;
					    check[i][j-k]=true;
				    }
			    }
			}			
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]=='*' && check[i][j]==false) {
				cout<<-1<<'\n';
				return 0;
			}
		}
	}

	cout<<ans.size()<<'\n';
	for(auto &t : ans) {
		int x,y,len;
		tie(x,y,len)=t;
		cout<<x<<" "<<y<<" "<<len<<'\n';
	}

	return 0;
}

/*
INPUT:
6 8
....*...
...**...
..*****.
...**...
....*...
........

OUTPUT:
3
3 4 1
3 5 2
3 5 1
*/
