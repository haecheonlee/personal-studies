#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n,a,d;
	cin>>n>>a>>d;
	
	int arr[n],l[n]{0};
	for(int i=0; i<n; i++) cin>>arr[i];
	
	stack<int> st;
	for(int i=0; i<n; i++) {
		if(st.empty()) {
			if(arr[i]==a) st.push(a);
		} else {
			int top=st.top();
			if(arr[i]==top+d) st.push(arr[i]);
		}
	}
	
	int count=0;
	while(!st.empty()) {
		st.pop();
		count++;
	}
	
	cout<<count;

	return 0;
}

/*
boj.kr/16162

INPUT:
7 3 3
3 3 9 7 2 6 9

OUTPUT:
3
*/
