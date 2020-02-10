#include <iostream>
#include <algorithm>

using namespace std;

int lcd(int a, int b) {
	if(b==0) return a;
	
	return lcd(b, a%b);
}

int main() {
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr, arr+n);
	
	int diff[n-1];
	for(int i=0; i<n-1; i++) diff[i]=abs(arr[i]-arr[i+1]);
	
	int common_div=lcd(diff[0], diff[1]);
	for(int i=2; i<n-1; i++) common_div=lcd(common_div, diff[i]);
	
	int cnt=0;
	for(int i=0; i<n-1; i++) cnt+=(diff[i]-common_div)/common_div;	
	
	cout<<cnt;

	return 0;
}

/*
boj.kr/2485

INPUT:
4
1
3
7
13

OUTPUT:
3
*/
