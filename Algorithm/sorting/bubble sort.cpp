#include <iostream>

using namespace std;

#define SIZE 10

void print(const int array[], const int &size) {
	for(int i=0; i<size; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int list[SIZE] {5,8,1,7,3,0,9,2,6,4};
	
	// before sorting
	print(list, SIZE);

	for(int i=SIZE-1; i>0; i--) {
		for(int j=0; j<i; j++) {
			if(list[j] > list[j+1]) {
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}

	// after sorting
	print(list, SIZE);

	return 0;
}

/*
  Time Complexity: O(n^2)
*/
