#include<iostream>
using namespace std;
// Pirioty Queue
class Heap {
protected:
	int * arr;
	int size;
public:
	Heap(int s):size(s) {
		arr=new int[size];
		arr[0]=1;//Next inserting index
	}
	virtual void Add(int)=0;
	virtual int Remove()=0;
	virtual bool isEmpty()=0;
	virtual void heapify(int index)=0;
	virtual  int* heapSort(int & newsize)=0;
	virtual int peek()=0;
	virtual void display()=0;
	~Heap() {
		if(arr!=nullptr) {
			delete[] arr;
		}
	}
};
class maxHeap: public Heap {
	void swap(int & a,int & b) {
		int temp=a;
		a=b;
		b=temp;
	}
public:
	maxHeap(int s):Heap(s) {

	}
	bool isEmpty() {
		return arr[0]==1;
	}
	void Add(int a) {
		if(arr[0]==size) {
			cout<<"Heap is Full"<<endl;
		}
		else {
			int index=arr[0];
			arr[index]=a;
			arr[0]++;
			while(index>1&&(arr[index]>arr[index/2])) {
				swap(arr[index],arr[index/2]);
				index/=2;

			}

		}
	}
	int Remove() {
		if(isEmpty()) {
			return -1;
		}
		int size1=arr[0]-1;
		int data=arr[1];
		swap(arr[1],arr[size1]);
		arr[0]--;
		heapify(1);
		return data;
	}
	int peek() {
		if(isEmpty()) {
			return -1;
		}
		return arr[1];
	}
	void heapify(int index) {
		int largest=index;
		int left=2*index;
		int right=2*index+1;
		if(left<arr[0] && arr[largest]<arr[left]) {
			largest=left;
		}
		if(right<arr[0] && arr[largest]<arr[right]) {
			largest=right;
		}
		if(largest!=index) {
			swap(arr[largest],arr[index]);
			heapify(largest);
		}
	}
	int* heapSort(int & newsize) {
		int heapsize=arr[0]-1;
		int*newarr=new int[heapsize];
		newsize=0;
		while(arr[0]>1) {
			newarr[newsize++]=arr[1];
			Remove();
		}
		return newarr;
	}
	void display() {
		for(int i=1; i<arr[0]; i++) {
			cout<<arr[i]<<endl;
		}
	}
};