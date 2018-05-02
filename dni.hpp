#pragma once
#include <string>
#include <time.h>
#include <iostream>

using namespace std;

class dni {

	private:
		string key;
		
	public:

		dni();
		~dni();
		string get_key();
		operator unsigned long() const;
		friend std::ostream& operator<<(std::ostream& os, dni& M);
		void operator =(const dni& d);
		bool operator ==(const dni& d);

};
