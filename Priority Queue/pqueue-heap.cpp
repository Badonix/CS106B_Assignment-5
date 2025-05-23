/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */

#include "pqueue-heap.h"
#include "error.h"

HeapPriorityQueue::HeapPriorityQueue() {
	len = 0;
	capacity = 5;
	arr = new string[capacity];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] arr;
}

int HeapPriorityQueue::size() {
	return len;
}

bool HeapPriorityQueue::isEmpty() {
	return size() == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	if (size() == capacity) {
		extendArray();
	}
	arr[size()] = value;
	len++;
	bubbleUp();
}

string HeapPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("PQueue is empty");
	}
	return arr[0];
}

string HeapPriorityQueue::dequeueMin() {
	if (isEmpty()) {
		error("PQueue is empty");
	}
	string answ = arr[0];
	swap(arr[0], arr[size() - 1]);
	len--;
	if (!isEmpty()) {
		bubbleDown();
	}
	return answ;
}

void HeapPriorityQueue::extendArray() {
	string* newArr = new string[capacity * 2];
	copy(arr, arr + capacity, newArr);
	delete[] arr;
	arr = newArr;
	capacity *= 2;
}

void HeapPriorityQueue::bubbleUp() {
	// Parent - (n/2)
	int currentId = size();
	string currentValue = arr[currentId - 1];
	if (currentId == 1) {
		return;
	}
	while (currentId > 1) {
		string parent = arr[(currentId / 2) - 1];
		if (parent <= currentValue) {
			return;
		}
		swap(arr[(currentId / 2) - 1], arr[currentId - 1]);
		currentId /= 2;
	}
}
void HeapPriorityQueue::bubbleDown() {
	// Child - (2n) and (2n+1) 
	string curr = arr[0];
	int currentId = 1;
	while (2 * currentId - 1 < size()) {
		int left = 2 * currentId - 1;
		int right = 2 * currentId;
		bool hasRight = right < size();
		if ((left >= size() || arr[left] >= curr) && (!hasRight || arr[right] >= curr)) {
			return;
		}
		if (hasRight && arr[right] < arr[left]) {
			swap(arr[right], arr[currentId - 1]);
			currentId = right + 1;
		}
		else {
			swap(arr[left], arr[currentId - 1]);
			currentId = left + 1;
		}
	}
}