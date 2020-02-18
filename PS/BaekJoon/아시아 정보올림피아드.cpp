#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
	int country_code;
	int student_code;
	int grade;
	Student(){}
	Student(int c, int s, int g) : country_code{c}, student_code{s}, grade{g} {}
};

int main() {
	int n;
	cin>>n;
	
	vector<Student> vec(n);
	int country_size=0;
	for(int i=0; i<n; i++) {
		Student s;
		cin>>s.country_code>>s.student_code>>s.grade;
		
		country_size=max(country_size,s.country_code);
		vec.push_back(s);
	}

	vector<Student> result;
	int check[country_size+1]{0};
	
	while(result.size()<3) {
		int largest=0, idx=-1;
		for(int i=0; i<vec.size(); i++) {
			if(check[vec[i].country_code]==2) continue;
			if(largest<vec[i].grade) {
				largest=vec[i].grade;
				idx=i;
			}
		}
		
		check[vec[idx].country_code]++;
		result.push_back(vec[idx]);
		vec.erase(vec.begin()+idx);
	}
	
	for(int i=0; i<result.size(); i++) cout<<result[i].country_code<<" "<<result[i].student_code<<endl;
	
	return 0;
}

/*
boj.kr/2535

INPUT:
9
1 1 230
1 2 210
1 3 205
2 1 100
2 2 150
3 1 175
3 2 190
3 3 180
3 4 195

OUTPUT:
1 1
1 2
3 4
*/
