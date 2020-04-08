#include <iostream>
#include <set>

using namespace std;

int n;
int a[101][101];
	
bool check() {
	set<int> nums;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) nums.insert(a[i][j]);
	}
	
	if(nums.size()<n*n) return false;
	
	set<int> sum;
	for(int i=0; i<n; i++) {
		int row_sum=0, col_sum=0;
		for(int j=0; j<n; j++) {
			row_sum+=a[i][j];
			col_sum+=a[j][i];
		}
		
		sum.insert(row_sum);
		sum.insert(col_sum);
	}
	
	int d1=0, d2=0;
	for(int i=0; i<n; i++) d1+=a[0+i][0+i], d2+=a[0+i][n-1-i];

	sum.insert(d1);
	sum.insert(d2);
	
	int total=(n*(n*n+1))/2;
	
	return ((sum.size()==1) && (d1==total));
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}
	
	if(check()) cout<<"TRUE";
	else cout<<"FALSE";

	return 0;
}

/*
INPUT:
3
2 7 6
9 5 1
4 3 8

OUTPUT:
TRUE
*/
