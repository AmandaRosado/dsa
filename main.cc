#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename T>
struct Node {
	T data;
	Node<T>* tail;
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
		deinit(list->tail);
		delete list;
		list = nullptr;
	}
}

// prepend :: a -> [a] -> [a]
// prepend a l = a:l
template <typename T>
List<T> prepend(T elem, List<T> list) {
	Node<T>* n = new Node<T>();
	n->data = elem;
	n->tail = list;
	return n;
}

// index :: [a] -> Int -> Maybe a
// index [] _ = Nothing
// index (x:xs) i = if i == 0 then Just x else index xs (i - 1)
template <typename T>
T* index(List<T> list, unsigned int i) {
	if (list == nullptr)
		return nullptr;

	if (i == 0)
		return &list->data;

	return index(list->tail, i - 1);
}

// contains :: Eq a => [a] -> a -> Bool
// contains [] _ = False
// contains (x:xs) a = if x == a then True else contains xs a
template <typename T>
bool contains(List<T> list, T elem) {
	if (list == nullptr)
		return false;

	if (list->data == elem)
		return true;

	return contains(list->tail, elem);
}

// remove_at :: [a] -> Int -> [a]
// remove_at [] _ = []
// remove_at (x:xs) i = if i == 0 then xs else x : remove_at xs (i - 1)
template <typename T>
List<T> remove_at(List<T> list, unsigned int i) {
	if (list == nullptr)
		return nullptr;

	if (i == 0) {
		List<T> l = list->tail;
		delete list;
		return l;
	}

	list->tail = remove_at(list->tail, i - 1);
	return list;
}

// Helper function for printing the entire list
template <typename T>
void print(List<T> l) {
	cout << "[";
	for (string s = ""; l != nullptr; l = l->tail) {
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
