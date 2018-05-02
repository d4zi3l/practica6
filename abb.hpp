#pragma once
#include "nodebb.hpp"


using namespace std;

template<class T>

class abb {
private:
	nodebb<T>* root_ = NULL;
public:
	abb();
	abb(T dato);
	~abb();
	int insert(T data);
	void extract(T data);
	ostream& write(ostream& os);
	int search(T dato);
	void eliminar(T dato) {
		eliminarRama(root_, dato);
	}
	void eliminarRama(nodebb<T>* &nodo, T dato);
	nodebb<T>* buscarRama(nodebb<T>* nodo, T dato);
	void sustituye(nodebb<T>* &eliminado, nodebb<T>* &sust);
	friend ostream& operator<<(ostream& os, const abb<T>& arbol) {
		queue<pair<nodebb<T>*, int> > Q;
		nodebb<T>* nodo;
		int nivel, nivel_actual = 0;

		Q.push(make_pair(arbol.root_, nivel_actual));

		os << '\n' << nivel_actual << ": ";
		while (!Q.empty()) {
			pair<nodebb<T>*, int> tmp = Q.front();
			Q.pop();

			nivel = get<1>(tmp);

			if (nivel > nivel_actual) {
				nivel_actual = nivel;  //Incremento de nivel
				os << '\n' << nivel_actual << ": ";
			}

			nodebb<T>* nodo_tmp = get<0>(tmp);

			if (nodo_tmp != NULL) {
				os << *nodo_tmp << " ";

				Q.push(make_pair(nodo_tmp->get_left(), nivel_actual + 1));
				Q.push(make_pair(nodo_tmp->get_right(), nivel_actual + 1));
			}

			else {
				os << "[.] ";
			}

		}
		os << endl << endl;
		return os;
	}

};

template<class T>
abb<T>::abb() {
	root_ = NULL;
}

template<class T>
abb<T>::abb(T dato) {
	root_ = new nodebb<T>(dato);
}

template<class T>
abb<T>::~abb() {
	root_ = NULL;
	delete root_;
}

template<class T>
int abb<T>::insert(T data) {
	int compare = 0;
	if (root_ == NULL) {
		root_ = new nodebb<T>(data);
		compare++;
	}
	else {
		compare++;
		compare += root_->insert(data);
	}

	return compare;
}

template<class T>
void abb<T>::extract(T data) {
	root_->extract(T data);
}

template<class T>
ostream& abb<T>::write(ostream& os) {
	os << "[" << root_->get_data() << "]";
	os << endl;
	root_->write(os);
	return os;
}

template<class T>
void abb<T>::eliminarRama(nodebb<T>* &nodo, T dato) {
	if (nodo == NULL) return;

	if (dato < nodo->get_data())
		eliminarRama(nodo->get_left(), dato);


	else if (nodo->get_data() < dato)
		eliminarRama(nodo->get_right(), dato);

	else
	{
		nodebb<T>* eliminado = nodo;

		if (nodo->get_right() == NULL)
			nodo = nodo->get_left();

		else if (nodo->get_left() == NULL)
			nodo = nodo->get_right();

		else
			sustituye(eliminado, nodo->get_left());

		delete eliminado;


	}

}

template<class T>
void abb<T>::sustituye(nodebb<T>* &eliminado, nodebb<T>* &sust)
{
	if (sust->get_right() != NULL)
		sustituye(eliminado, sust->get_right());

	else
	{
		eliminado->set_data(sust->get_data());
		eliminado = sust;
		sust = sust->get_left();
	}
}

template<class T>
int abb<T>::search(T dato)
{	
	int comp = 1;
	comp += root_->search(dato);
	return comp;
}
