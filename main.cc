#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T>
struct Node {
	T data;
	Node<T>* next;
};

template <typename T>
using List = Node<T>*;

/// Empty list is null
template <typename T>
List<T> init() {
	return nullptr;
}

template <typename T>
void deinit(List<T> list) {
	
	if (list != nullptr) {

		List<T> copy = list;
		deinit (list: list ->next);
		delete copy;
		copy = nullptr;
	}
}

/// Requirements:
/// input: Φ [a, b, c, ...]
/// output: [Φ, a, b, c, ...]
template <typename T>
List<T> prepend (List<T> old, T elem) {

	Node<T>* node = new Node<T> ();
	node -> data = elem;
	node -> next = old;
	return node;
}

/// Requirements:
/// input: [a, Φ, c, ...] Φ
/// output: true
///
/// input: [a, b, c, ...] Φ
/// output: false

/// Requirements:
/// input: [a, b, c, ...] 2
/// output: c
///
/// input: [a, b, c, ...] 0
/// output: a

/// Requirements:
/// input: [a, b, c] 0
/// output: [b, c]
///
/// input: [a, b, c] 2
/// output: [a, b]
///
/// input: [a, b, c] 10000
/// output: [a, b, c]

// Helper function for printing the entire list

int main() {
	/*
	List<int> list = init<int>();

	// build list: [1 .. 13]
	for (int i = 1; i < 13; ++i) list = prepend(i, list);

	cout << "Initial list: ";
	print(list);

	// indexing
	int* m = index(list, 0);
	cout << "index 0: ";
	if (m != nullptr) cout << *m;
	else cout << "not found";
	cout << endl;

	m = index(list, 100);
	cout << "index 100: ";
	if (m != nullptr) cout << *m;
	else cout << "not found";
	cout << endl;

	m = index(list, 12);
	cout << "index 12: ";
	if (m != nullptr) cout << *m;
	else cout << "not found";
	cout << endl;

	// contains
	cout << "contains 2: " << (contains(list, 2) ? "true" : "false") << endl;
	cout << "contains 5: " << (contains(list, 5) ? "true" : "false") << endl;
	cout << "contains 13: " << (contains(list, 13) ? "true" : "false") << endl;

	// removal
	list = remove_at(list, 2);
	cout << "After removing at index 2: ";
	print(list);

	list = remove_at(list, 0);
	cout << "After removing at index 0: ";
	print(list);

	list = remove_at(list, 10);
	cout << "After removing at index 10: ";
	print(list);

	list = remove_at(list, 100);
	cout << "After removing at index 100: ";
	print(list);

	deinit(list);
	*/
}
