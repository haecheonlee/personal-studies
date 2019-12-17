#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin>>N>>M;
	
	int friends[N] {0};
	
	vector<int> answers;
	int answer = 0;
	for(int i=0; i<M; i++) {
		cin>>answer;
		answers.push_back(answer);
	}

	for(int i=0; i<M; i++) {
		int nums[N], count = N;
		for(int j=0; j<N; j++) {
			cin>>nums[j];
			
			if(answers[i] == nums[j]) {
				friends[j]++;
				count--;
			}
		}
		
		friends[answers[i]-1] += count;
	}

	for(int i=0; i<N; i++) {
		cout<<friends[i]<<endl;
	}

	return 0;
}

/*
boj.kr/10708

INPUT:
5
3
3 3 1
2 4 3 3 3
4 3 3 3 1
1 3 4 1 1

OUTPUT:
3
1
6
3
2
*/
