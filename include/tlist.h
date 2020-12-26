#pragma once

#include <iostream>

template <class T>
class List {
public:
	class Node {
	public:
		T data;
		Node* next;
		Node(T value = 0, Node* next_ = NULL): next(next_), data(value){}
	};
	Node* first;
	size_t size;
public:
	class iterator {
	private:
		Node* ptr;
	public:
		iterator() : ptr(NULL){}
		iterator(Node* ptr_) : ptr(ptr_) {}
		iterator(const iterator& iter) : ptr(iter.ptr){}
		iterator& operator++ () {
			ptr = ptr->next;
			return *this;
		}
		iterator operator++ (int) {
			iterator iter(*this);
			++(*this);
			return iter;
		}

		Node*& operator*() {
				return ptr;
		}
		Node* operator->() {
			return ptr;
		}
		bool operator== (iterator iter) const {
			return ptr == iter.ptr;
		}
		bool operator!= (iterator iter) const {
			return !(*this == iter);
		}
	};
	List() {
		first = NULL;
		size = 0;
	}
	List(const List<T>& lst) {
		first = NULL;
		Node* pcurr = first;
		size = lst.size;
		for (iterator it_curr = lst.begin(); it_curr != lst.end(); ++it_curr) {
			Insert(pcurr, it_curr->data);
			pcurr = pcurr->next;
		}
	}
	~List() {
		while (first)
			DeleteFirst();
	}
	void Print() {
		iterator iter = begin();
		while (iter != end()) {
			std::cout << iter->data << " ";
			iter++;
		}
		std::cout << std::endl;
	}
	Node* get_first() {
		return first;
	}
	iterator Search(T& value) {
		iterator it = begin();
		while (it!=end()) {
			if (it->data == value)
				break;
			it++;
		}
		return it;
	}
	void Delete(Node* pos) {
		if (pos == NULL) {
			DeleteFirst();
		}
		else {
			Node* p = pos->next;
			pos->next = p->next;
			delete p;
		}
	}

	iterator begin() const {
		iterator it(first);
		return it;
	}
	iterator end() const {
		iterator it(NULL);
		return it;
	}
	bool empty() {
		return size == 0;
	}
	size_t get_size() {
		return size;
	}
	void InsertFirst(const T& value) {
		Node* tmp = new Node(value, first);
		first = tmp;
		size++;
	}
	void DeleteFirst() {
		if (!size) { throw "list is empty"; }
		Node* tmp = first;
		first = tmp->next;
		delete tmp;
		size--;
	}
	void Insert(Node* pos, const T& value) 
	{
		if (pos == NULL) {
			InsertFirst(value);
		}
		else {
			Node* tmp = new Node(value, pos->next);
			pos->next = tmp;
			size++;
		}
	}
};




