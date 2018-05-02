#include "dni.hpp"

dni::dni() {
	key.resize(9);
	for (int i = 0; i < 8; i++) {
		key[i] = '0' + rand() % 10;
	}
	key[8] = 'A' + rand() % 24;
}

dni::~dni() {
	key.resize(0);
}

string dni::get_key() {
	return key;
}

dni::operator unsigned long() const {
	unsigned long num = 0;
	num = atoi(key.c_str());
	return num;
}

std::ostream& operator<<(std::ostream& os, dni& M) {
	os << M.get_key() << " ";
	return os;
}

void dni::operator =(const dni& d) {
	key = d.key;
}

bool dni::operator ==(const dni& d) {
	return (d.key == key);
}