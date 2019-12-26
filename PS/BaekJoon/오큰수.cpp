#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	int list[N], result[N] {0};
	for(int i=0; i<N; i++) {
		cin>>list[i];
		result[i]=-1;
	}

	stack<int> st;
	for(int i=0; i<N; i++) {
		if(!st.empty()) {
			while(!st.empty()) {
				int index = st.top();
				if(list[index] < list[i]) {
					result[index] = list[i];
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
boj.kr/17298

INPUT:
4
3 5 2 7

OUTPUT:
5 7 7 -1
*/
