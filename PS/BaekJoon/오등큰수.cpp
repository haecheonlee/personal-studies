#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int f[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	vector<int> list(N), result(N);
	for(int i=0; i<N; i++) {
		cin>>list[i];
		f[list[i]]++;
		result[i]=-1;
	}
	
	stack<int> st;
	for(int i=0; i<N; i++) {
		if(!st.empty()) {
			while(!st.empty()) {
				if(f[list[st.top()]] < f[list[i]]) {
					result[st.top()]=list[i];
					st.pop();
				} else {
					break;
				}
			}
			
		}
		st.push(i);
	}
	
	for(int i=0; i<N; i++) {
		cout<<result[i]<<" ";
	}

	return 0;
}

/*
boj.kr/17299

INPUT:
7
1 1 2 3 4 2 1

OUTPUT:
-1 -1 1 2 2 1 -1
*/
