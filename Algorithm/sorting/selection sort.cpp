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

	for(int i=0; i<SIZE; i++) {
		int smallest = list[i], position = i;
		for(int j=i+1; j<SIZE; j++) {
			if(smallest > list[j]) {
				smallest = list[j];
				position = j;
			}
		}
		
		int temp = list[i];
		list[i] = smallest;
		list[position] = temp;
	}

	// after sorting
	print(list, SIZE);

	return 0;
}

/*
  Time Complexity: O(n^2)
*/
