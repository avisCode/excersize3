#include<sstream>
#include"mytypes.h"
using namespace std;


char * numberToString(int number) {
	stringstream s;
	s << number;
	char * res = new char[s.str().size()+1];
	s>> res ;
	return res;
}
