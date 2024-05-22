#pragma once
#include <iostream>
using namespace std;

class List {
public:
	struct node {
		int id;
		string name;
		node* next;
	} *head, *tail, * ptr;

	List(): head{nullptr}, tail {nullptr}, ptr {nullptr}{}
	~List();

	node* searchName(string);
	node* searchId(int);
	node* initNode(string, int);

	void reverse();
	void addNode(node*);
	void insertNode(node*, int);
	void deleteNode(node*);
	void deleteListBegin(node*);
	void displayNode(node*);
	void displayList();
	void displayList(node*);

};

List::~List() {
	node* current, * temp;

	current = temp = head;

	while (current != nullptr) {
		current = current->next;
		delete temp;
		temp = current;
	}
}
List::node* List::initNode(string name, int id) {
	node *ptr = new node;

	ptr->name = name;
	ptr->id = id;

	return ptr;
}
void List::addNode(node* newNode) {
	if (head == nullptr) {
		head = tail = newNode;
		head->next = nullptr;
	}
	else {
		tail->next = newNode;
		newNode->next = nullptr;
		tail = newNode;
	}
}
void List::insertNode(node* newNode, int id) {
	node* temp, * prev;

	if (head == nullptr) {
		head = tail = newNode;
		head->next = nullptr;
	}
	else {
		temp = head;
		while (temp->id != id) {
			temp = temp->next;
			if (temp == nullptr) break;
		}

		if (temp == head) {
			newNode->next = head;
			head = newNode;
		}
		else {
			prev = head;
			while (prev->next != temp) {
				prev = prev->next;
			}
			prev->next = newNode;
			newNode->next = temp;

			if (tail == prev)
				tail = newNode;
		}
	}
}
List::node* List::searchName(string name) {
	node* temp = head;
	while (temp->name != name) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}
List::node* List::searchId(int id) {
	node* temp = head;
	while (temp->id != id) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}
void List::reverse() {
	if (head == nullptr || head->next == nullptr) return;

	node* parent = head;
	node* me = head->next;
	node* child = me->next;
	tail = head;

	head->next = nullptr;
	me->next = head;
	while (child != nullptr)
	{
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}

	head = me;
	head->next = parent;
	
}
void List::deleteNode(node* delNode) {
	if (head == nullptr) return;
	node* temp, * prev;

	temp = delNode;
	prev = head;

	if (temp == prev) {
		head = head->next;
		if (tail == temp) {
			tail = tail->next;
		}
		delete temp;
	}
	else {
		while (prev->next != temp) {
			prev = prev->next;
		}
		prev->next = temp->next;
		if (tail == temp) {
			tail = prev;
		}
		delete temp;
	}
}
void List::deleteListBegin(node* delNode) {
	if (head == nullptr) return;

	node* temp, *prev;

	if (delNode == head) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		temp = head;
		while (temp != delNode) {
			head = temp->next;
			delete temp;
			temp = head;
		}
	}
}
void List::displayNode(node* dispNode) {
	if (dispNode != nullptr)
		cout << dispNode->id << " " << dispNode->name << endl;
}
void List::displayList() {
	node* temp = head;
	while (temp != nullptr) {
		displayNode(temp);
		temp = temp->next;
	}
}
void List::displayList(node* ptr) {
	displayNode(ptr);
	if (ptr->next != nullptr)
		displayList(ptr->next);
}