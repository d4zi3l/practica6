#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <queue>

using namespace std;

template<class T>

class nodebb {

private:
	T data_;
	nodebb<T>* left_;
	nodebb<T>* right_;

public:
	nodebb();
	nodebb(T data);
	~nodebb();
	nodebb<T>*& get_left();
	nodebb<T>*& get_right();
	
	int insert(T data);
	void set_data(T data);
	T& get_data();
	bool empty();
	ostream& write(ostream& os);
	int search(T dato);

	friend std::ostream& operator<<(std::ostream& os, nodebb<T>& nodo)
	{
		os << nodo.get_data();
		return os;
	}
	
};

template<class T>
nodebb<T>::nodebb() {
	data_ = NULL;
	left_ = NULL;
	right_ = NULL;
}

template<class T>
nodebb<T>::nodebb(T data) {
	data_ = data;
	left_ = NULL;
	right_ = NULL;
}

template<class T>
nodebb<T>::~nodebb() {
	left_ = NULL;
	right_ = NULL;
	delete left_;
	delete right_;
}

template<class T>
nodebb<T>*& nodebb<T>::get_left() {
	return left_;
}

template<class T>
nodebb<T>*& nodebb<T>::get_right() {
	return right_;
}

template<class T>
int nodebb<T>::insert(T data) {
	int compare = 0;
		if (data < data_) {
			if (get_left() == NULL) {
				left_ = new nodebb<T>(data);
				
			}
			else {
				compare += get_left()->insert(data);
			}
			compare++;
		}
		else if (data > data_){
			if (get_right() == NULL) {
				right_ = new nodebb<T>(data);
			}
			else {
				compare += get_right()->insert(data);
			}
			compare++;
		}
		else {
			cout << "ERROR: Elemento ya insertado" << endl;
		}

		return compare;
	
}



template<class T>
bool nodebb<T>::empty() {
	return((get_left() == NULL) && (get_right() == NULL));
}

template<class T>
void nodebb<T>::set_data(T data) {
	data_ = data;
}

template<class T>
T& nodebb<T>::get_data() {
	return data_;
}

template<class T>
ostream& nodebb<T>::write(ostream& os) {
	/*if ((get_right() != NULL) && (get_right() != NULL)) {
		if (get_left() != NULL) {
			os << "[" << get_left()->get_data() << "]";
		}
		else {
			cout << "[.]";
		}
		if (get_right() != NULL) {
			os << "[" << get_right()->get_data() << "]";
		}
		else {
			cout << "[.]";
		}
		if (get_left() != NULL) {
			get_left()->write(os);
		}
		
		if (get_right() != NULL) {
			get_right()->write(os);
		}
		cout << endl;
	}
	return os;*/
}

template<class T>
int nodebb<T>::search(T dato) {

	

	int comparation = 0;

	

	if (data_ == dato) {
		comparation++;
		return comparation;
	}
	else if (dato > data_) {
		comparation++;
		comparation += get_right()->search(dato);
		
	}
	else {
		comparation++;
		comparation += get_left()->search(dato);
		
	}

	return comparation;
}