#include"Heap.h"

int main() {
	// Create a min-heap with a size of 10 (you can change the size as needed)
	minHeap h(10);

	// Add some elements to the heap
	h.Add(10);
	h.Add(20);
	h.Add(5);
	h.Add(30);
	h.Add(15);

	cout << "Heap after adding elements: " << endl;
	h.display();

	cout << "\nPeek (top element): " << h.peek() << endl;

	cout << "\nRemove (min element): " << h.Remove() << endl;

	cout << "Heap after removing the root: " << endl;
	h.display();

	cout<<"Heap After Sorting :"<<endl;
	int size=0;
	int*arr=h.heapSort(size);
	for(int i=0; i<size; i++) {
		cout<<arr[i]<<endl;
	}
	delete[]  arr;
	arr=nullptr;
	return 0;
}
