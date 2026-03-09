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

template <typename T>
List<T> init() {
	return nullptr;
}

template <typename T>
void deinit(List<T>& list) {
	if (list != nullptr) {
		deinit(list->next);
		delete list;
		list = nullptr;
	}
}

template <typename T>
List<T> prepend(T elem, List<T> list) {
	Node<T>* n = new Node<T>();
	n->data = elem;
	n->next = list;
	return n;
}

template <typename T>
T* index(List<T> list, unsigned int offset) {
	for (; list != nullptr;list = list->next) {
		if (offset == 0)
			return &list->data;
		offset -= 1;
	}

	return nullptr;
}

template <typename T>
bool contains(List<T> list, T elem) {
	for(; list != nullptr; list = list->next) {
		if (list->data == elem)
			return true;
	}

	return false;
}

template <typename T>
List<T> remove_at(List<T> list, unsigned int offset) {
	List<T> orig = list;
	if (list == nullptr)
		return nullptr;

	List<T> prev = list;
	list = list->next;

	for(List<T> ptr = list; ptr != nullptr;) {
		if (offset == 0)
			break;

		prev = ptr;
		ptr = ptr->next;
	}

	if (prev->next != nullptr) {
		Node<T>* kod = prev->next;
		prev->next = prev->next->next;
		delete kod;
	}

	return orig;
}

// Helper function for printing the entire list
template <typename T>
void print(List<T> l) {
	cout << "[";
	for (string s = ""; l != nullptr; l = l->next) {
		cout << s << l->data;
		s = ", ";
	}
	cout << "]\n";
}

int main() {
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
	cout << "contains 13: " << (contains(list, 42) ? "true" : "false") << endl;

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
}
