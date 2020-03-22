int upper_bound(const vector<int> &list, int size, int to_find) {
	int l=0, h=size;
	
	while(l<h) {
		int mid=(l+h)/2;
		
		if(to_find>=list[mid]) {
			l=mid+1;
		} else {
			h=mid;
		}
	}
	
	return l;
}

int lower_bound(const vector<int> &list, int size, int to_find) {
	int l=0;
	int h=size;
	
	while(l<h) {
		int mid=(l+h)/2;
		if(to_find<=a[mid]) {
			h=mid;
		} else {
			l=mid+1;
		}
	}
}
