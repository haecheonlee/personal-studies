#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,m,c,num,l;
	cin>>n>>m>>c;
	
	vector<int> h,v;
	for(int i=0; i<c; i++) {
		cin>>num>>l;
		
		if(num==0) h.push_back(l);
		else v.push_back(l);
	}
	
	sort(v.begin(), v.end());
	sort(h.begin(), h.end());

	int result=0;
	for(int i=0; i<v.size()+1; i++) {
		for(int j=0; j<h.size()+1; j++) {
			int start_x=0, start_y=0;
			int end_x=0, end_y=0;
			
			if(i==0) {
				start_x=0;
				end_x=((v.size()>0) ? v[i] : n);
			} else {
				start_x=v[i-1];
				end_x=((v.size()>i) ? v[i] : n);
			}
			
			if(j==0) {
				start_y=0;
				end_y=((h.size()>0) ? h[j] : m);
			} else {
				start_y=h[j-1];
				end_y=((h.size()>j)? h[j] : m);
			}
			
			int size=(end_x-start_x)*(end_y-start_y);
			result=max(result,size);
		}
	}
	cout<<result;

	return 0;
}

/*
boj.kr/2628

INPUT:
10 8
3
0 3
1 4
0 2

OUTPUT:
30
*/
