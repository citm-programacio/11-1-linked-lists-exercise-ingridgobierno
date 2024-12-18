
#include <iostream>
#include <cassert>
using namespace std;


class List {
public:
	int size = 0;
	int capacity;

	int* array;

	List() {
		capacity = 10;
		array = new int[capacity];
	}
	List(int cap) {
		capacity = cap;
		array = new int[capacity];
	}
	List(int cap, int* init, int init_size) {
		capacity = cap;
		size = init_size;
		array = new int[capacity];
		for (int i = 0; i < init_size; i++) {
			array[i] = init[i];
		}
	}

	void push_back(const int& value) {
		
		Node* node = new Node;
		node->value = value;
		node->next = nullptr;

		if (num_elems == 0) {
			node->prev = nullptr;
			first = last = node; 
		}
		else {
			node->prev = last;
			last->next = node;
			last = node;
		}

		num_elems++; 
	}

	void insert(unsigned int position, const int& value) {
		if (capacity <= size) {
			capacity *= 2;
		}
		int* newArray = new int[capacity];
		size++;
		int i;
		for (i = 0; i < position; i++) {
			newArray[i] = array[i];
		}
		newArray[i] = value;
		i++;
		while (i < size) {
			newArray[i] = array[i - 1];
			i++;
		}
		delete[] array;
		array = newArray;
	

	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << ", ";
		}

		Node* current = first;
		while (current != nullptr) {
			cout << current->value << ", ";
			current = current->next;
		}
		cout << endl;
	}

		


private:
	
	struct Node {
		int value;
		Node* next;
		Node* prev;
	};

	
	Node* first = nullptr;
	Node* last = nullptr;
	int num_elems = 0;
};


int main()
{
	string start[10];

	List a(10);


	a.insert(0, 1);
	a.print();
	a.insert(1,2);
	a.print();
	a.insert(2, 3);
	a.print();
	a.insert(3, 4);
	a.print();
	a.push_back(2);
	a.print();

}
