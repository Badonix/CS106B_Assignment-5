/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */

#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	// TODO: Fill this in!
	head = nullptr;
	len = 0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	// TODO: Fill this in!
	while (head) {
		Cell* tmp = head->next;
		delete head;
		head = tmp;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	// TODO: Fill this in!
	return len;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return size() == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	len++;
	Cell* curr = new Cell;
	curr->val = value;
	curr->prev = NULL;
	curr->next = NULL;
	if (!head) {
		head = curr;
		return;
	}
	head->prev = curr;
	curr->next = head;
	head = curr;
}


string DoublyLinkedListPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("PQueue is empty");
	}
	return findMinCell()->val;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("PQueue is empty");
	}

	Cell* currMin = findMinCell();
	string minVal = currMin->val;
	len--;

	// If there is only 1 element in the linked list
	if (currMin == head && head->next == nullptr) {
		delete head;
		head = nullptr;
		return minVal;
	}

	// If the minimum is the first element
	if (currMin == head) {
		Cell* tmp = head->next;
		delete head;
		head = tmp;
		head->prev = nullptr;
		return minVal;
	}

	// If the minimum is the last element
	if (currMin->next == nullptr) {
		currMin->prev->next = nullptr;
		delete currMin;
		return minVal;
	}

	// If the last element is in the middle
	currMin->prev->next = currMin->next;
	currMin->next->prev = currMin->prev;
	delete currMin;
	return minVal;
}


DoublyLinkedListPriorityQueue::Cell* DoublyLinkedListPriorityQueue::findMinCell() {
	if (!head) {
		error("Empty queue");
	}
	Cell* minCell = head;
	Cell* i = head;
	while (i) {
		if (i->val < minCell->val) {
			minCell = i;
		}
		i = i->next;
	}
	return minCell;
}
