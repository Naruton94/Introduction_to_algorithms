#pragma once
#include <vector>
#include <memory>
using std::vector;
using std::swap;
using std::shared_ptr;
using std::make_shared;

template<typename T>
class heap {
public:
	heap(vector<T> a) :A(a), heapSize(a.size()) {
		buildMaxHeap(*this);
	}
	T &operator[] (int i) {
		if (i < A.size())
			return A[i];
	}
	int size() {
		return heapSize;
	}
	vector<T> data() {
		return A;
	}
	void heapIncreaseKey(int i, T key);
	void insert(T key);
	void sortH();
	void printH();
	T heapMaximum();
	T heapExtractMax();
private:
	vector<T> A;
	int heapSize;
	void maxHeapify (heap &, const int);
	void buildMaxHeap(heap &);
	void sortH(heap &);
	T heapExtractMax(heap&);
	inline int PARENT(int i) {
		return (i - 1) / 2;
	}
	inline int LEFT(int i) {
		return i * 2 + 1;
	}
	inline int RIGHT(int i) {
		return i * 2 + 2;
	}

};

template<typename T>
void heap<T>::maxHeapify(heap<T> &a, const int i) {
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = 0;
	if (l < a.size() && a[l] > a[i]) {
		largest = l;
	}
	else
		largest = i;
	if (r < a.size() && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		maxHeapify(a, largest);
	}
}

template<typename T>
void heap<T>::buildMaxHeap(heap<T> &a) {
	int n = (a.size() + 1) / 2 - 1;
	for (int i = n; i >= 0; --i) {
		maxHeapify(a, i);
	}
}


template<typename T>
void heap<T>::sortH() {
	sortH(*this);
}

template<typename T>
void heap<T>::sortH(heap<T> &a) {
	for (int i = a.heapSize - 1; i >= 1; i--) {
		swap(a[0], a[i]);
		a.heapSize -= 1;
		a.A.pop_back();
		maxHeapify(a, 0);
	}
}

template<typename T> 
void heapSort(vector<T> &a) {
	heap<T>* tmp = new heap<T>(a);
	tmp->sortH();
	a = tmp->data();
	delete tmp;
}

template<typename T>
T heap<T>::heapMaximum() {
	return this->data()[0];
}

template<typename T>
T heap<T>::heapExtractMax(heap<T>& A) {
	if (A.heapSize < 1)
		throw "Heap underflow";
	int max = A[0];
	A[0] = A[A.heapSize - 1];
	A.heapSize -= 1;
	A.A.pop_back();
	maxHeapify(A, 0);
	return max;
}

template<typename T>
T heap<T>::heapExtractMax() {
	return heapExtractMax(*this);
}

template<typename T>
void heap<T>::printH() {
	for (int i = 0; i < heapSize; ++i) {
		std::cout << A[i] << std::endl;
	}
}


template<typename T>
void heap<T>::heapIncreaseKey(int i, T key) {
	if (i >= heapSize) {
		std::cerr << "Subscript crossover" << std::endl;
		return;
	}
	if (key < A[i]) {
		std::cerr << "new key is smaller than current key!\n";
		return;
	}
	A[i] = key;
	while (i > 0 && A[PARENT(i)] < A[i]) {
		swap(A[i], A[PARENT(i)]);
		i = PARENT(i);
	}
}

template <typename T>
void heap<T>::insert(T key) {
	heapSize += 1;
	A.push_back(static_cast<T> (INT_MIN));
	heapIncreaseKey(heapSize - 1, key);
}


