#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<string> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	int ans=0;
	
	for(int x1=0; x1<n; x1++) {
		for(int y1=0; y1<m; y1++) {
			for(int s1=0;;s1++) {
				if(x1-s1<0 || x1+s1>=n) break;
				if(y1-s1<0 || y1+s1>=m) break;
				if(a[x1-s1][y1]!='#' || a[x1+s1][y1]!='#') break;
				if(a[x1][y1-s1]!='#' || a[x1][y1+s1]!='#') break;
				a[x1-s1][y1]='*'; a[x1+s1][y1]='*';
				a[x1][y1-s1]='*'; a[x1][y1+s1]='*';
				
				for(int x2=0; x2<n; x2++) {
					for(int y2=0; y2<m; y2++) {
						for(int s2=0;;s2++) {
							if(x2-s2<0 || x2+s2>=n) break;
							if(y2-s2<0 || y2+s2>=m) break;
							
							if(a[x2-s2][y2]!='#' || a[x2+s2][y2]!='#') break;
							if(a[x2][y2-s2]!='#' || a[x2][y2+s2]!='#') break;
							
							int area=(4*s1+1)*(4*s2+1);
							if(ans<area) ans=area;
						}
					}
				}
			}
			
			for(int s1=0;;s1++) {
				if(x1-s1<0 || x1+s1>=n) break;
				if(y1-s1<0 || y1+s1>=m) break;
				
				if(a[x1-s1][y1]!='*' || a[x1+s1][y1]!='*') break;
				if(a[x1][y1-s1]!='*' || a[x1][y1+s1]!='*') break;
				a[x1-s1][y1]='#'; a[x1+s1][y1]='#';
				a[x1][y1-s1]='#'; a[x1][y1+s1]='#';
			}
		}
	}

	cout<<ans;

	return 0;
}
