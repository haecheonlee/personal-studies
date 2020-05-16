#include <iostream>
#include <vector>

using namespace std;


struct Question {
	string answer;
	int strike;
	int ball;
};

/* initialization */
vector<Question> q;
int n;

bool check(string s) {
	bool isRight=true;
	
	for(auto &each : q) {
		int ball=0;
		int strike=0;
		
		for(int i=0; i<3; i++) {
			if(each.answer[i]==s[i]) {
				strike++;
			} else if(each.answer.find(s[i])!=string::npos) {
				// different position but contains
				ball++;
			}
		}
		
		if(ball!=each.ball || strike!=each.strike) {
			isRight=false;
			break;
		}
	}
	
	return isRight;
}

int main() {
	cin>>n;
	
	q.resize(n);
	for(int i=0; i<n; i++) cin>>q[i].answer>>q[i].strike>>q[i].ball;
	
	int cnt=0;
	for(int i=1; i<=9; i++) {
		for(int j=1; j<=9; j++) {
			if(i==j) continue;
			for(int k=1; k<=9; k++) {
				if(j==k || k==i) continue;
				string s=to_string(i)+to_string(j)+to_string(k);
				if(check(s)) cnt++;
			}
		}
	}
	cout<<cnt;

	return 0;
}
