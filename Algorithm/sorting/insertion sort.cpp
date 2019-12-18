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
	for(int i=1; i<SIZE; i++) {
		int key = list[i], j = i-1;
		while(j >= 0 && list[j] > key) {
			list[j+1] = list[j];
			j--;
		}
		list[j+1] = key;
	}

	// after sorting
	print(list, SIZE);

	return 0;
}

/*
  Time Complexity: O(n^2)
*/
