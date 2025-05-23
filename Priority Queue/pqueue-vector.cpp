/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */

#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	// TODO: Fill this in!
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}

int VectorPriorityQueue::size() {
	// TODO: Fill this in!
	return v.size();
}

bool VectorPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	v.push_back(value);
}

string VectorPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Queue is empty");
	}
	int idx = indexOfNext();
	return v[idx];
	;
}

string VectorPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("Queue is empty");
	}
	int idx = indexOfNext();
	string answ = v[idx];
	v.remove(idx);
	return answ;
}

int VectorPriorityQueue::indexOfNext() {
	int index = 0;
	string curr = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (curr > v[i]) {
			index = i;
			curr = v[i];
		}
	}
	return index;
}

