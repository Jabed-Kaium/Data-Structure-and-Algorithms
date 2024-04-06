#include<iostream>
using namespace std;

//TC: O(n)
void heapify(int a[], int n) {
	for(int k=n; k>=1; k--) {	//start from right to left of the array
		
		int i=k;
		int j = 2*i;	//left child of k

		//going towards leaf by comparing
		while(j <= n) {
			if(a[j+1] > a[j] && j+1 <= n)	//if right child exists and right child > left child
				j++;
			if(a[j] > a[i]) {	//if child > parent, swap
				int x = a[i];
				a[i] = a[j];
				a[j] = x;
			}

			i = j;	//move downwards
			j = j*2;
		}
	}
}

//TC: O(logn)
int deleteFromHeap(int a[], int n) {
	int tmp = a[1];	//delete the root
	a[1] = a[n];	//move last element to the root
	int i=1;
	int j=2*i;

	//move towards leaf and swap by comparing
	while(j <= n-1) {
		if(a[j+1] > a[j] && j+1 <= n-1)	//if right child exists and right child > left child (n-1, because we deleted one element)
			j++;
		if(a[j] > a[i]) {	//if child > parent, swap
			int x = a[i];
			a[i] = a[j];
			a[j] = x;
		}

		i = j;	//move downwards
		j = j*2;
	}

	return tmp;
}

//TC: O(logn)
void insert(int a[], int n) {
	int i=n;

	//insert in the last place and move upwards and swap by comparing to build max-heap
	while(i>1 && a[i]>a[i/2]) {
		int tmp = a[i];	//swap
		a[i] = a[i/2];
		a[i/2] = tmp;

		i /= 2;
	}
}

//TC: O(nlogn)
void createHeap() {
	int a[] = {0,1,4,2,3,9,7,8,10,14,16};

	//insert element one by one
	for(int i=2; i<=10; i++) {
		insert(a, i);
	}

	//heapify the array
	//heapify(a,10);

	//delete element one by one
	// for(int i=10; i>=1; i--) {
	// 	cout << deleteFromHeap(a,i) << "\n";
	// }

	//print the heap
	for(int i=1; i<=10; i++) {
		cout << a[i] << " ";
	}
}

int main()
{
	createHeap();
}