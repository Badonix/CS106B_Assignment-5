/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */

#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	// TODO: Fill this in!
	len = 0;
	head = NULL;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	// TODO: Fill this in!
	while (head) {
		Cell* temp = head->next;
		delete head;
		head = temp;
	}
}

int LinkedListPriorityQueue::size() {
	// TODO: Fill this in!
	return len;
}

bool LinkedListPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return size() == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	Cell* curr = new Cell;
	curr->val = value;
	curr->next = NULL;
	len++;
	// If the list is empty
	if (size() == 1) {
		head = curr;
		return;
	}

	// If needs to be placed first
	if (head->val >= value) {
		curr->next = head;
		head = curr;
		return;
	}

	// Needs to be placed in the middle
	Cell* i = head;
	while (i->next) {
		if (i->next->val >= value) {
			curr->next = i->next;
			i->next = curr;
			return;
		}
		i = i->next;
	}

	// Needs to be placed in the end
	i->next = curr;
}


string LinkedListPriorityQueue::peek() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("PQueue is Empty");
	}
	return head->val;
}

string LinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if (isEmpty()) {
		error("PQueue is Empty");
	}
	len--;
	string answ = head->val;

	if (isEmpty()) {
		delete head;
		head = NULL;
		return answ;
	}
	Cell* tmp = head->next;
	delete head;
	head = tmp;
	return answ;
}
