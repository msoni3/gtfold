#include "pf-shel-check.h"
#include <stdio.h>

/* Documentation of type codes:
0 = u
1 = up
2 = s1
3 = upm
4 = s2
5 = s3
6 = u1
7 = 
8 = 
*/

//int main(){
//	pf_shel_check test = pf_shel_check(7);
//	test.add(0, 1, 7, false);
//	test.add(1, 1, 3, false);
//	printf("%d", (int)test.count());
//	return 0;
//}

pf_shel_check::pf_shel_check() {};

pf_shel_check::pf_shel_check(int len) 
{
	//printf("Hello world\n You wont really see me\n");
	add(0, 1, len, true);
}

int pf_shel_check::count() {
	int numNumerator = 0;
	int numDenominator = 0;
	for(std::map<Key, int>::iterator check = myMap.begin(); check != myMap.end(); ++check) {
		if(check->second > 0) {
			numNumerator += check->second;
			printf("Element in numerator %d time(s): ", check->second);
			(check->first).print();
		}
		if(check->second < 0) {
			numDenominator -= check->second;				
			printf("Element in denominator %d time(s): ", -1 * check->second);
			(check->first).print();
		}
	}
	printf("There are %d elements in the numerator.\nThere are %d elements in the denominator.\n", numNumerator, numDenominator);
	return numNumerator + numDenominator;
}

void pf_shel_check::add(unsigned char type, int i, int j, bool isNumerator) {
	Key key = Key(type, i, j);
	std::map<Key, int>::iterator check = myMap.find(key);
	if(check == myMap.end()) {	
		myMap.insert(std::make_pair(key, isNumerator ? 1 : -1));
		if(!isNumerator) {
			printf("Added to denominator first\n");
			key.print();
		}
	}
	else {
		int value = check -> second;
		value = value + (isNumerator ? 1 : -1);
		myMap.erase(key);
		if(value != 0) myMap.insert(std::make_pair(key, value));
	}
}
/*
int getNumNumerator() {
	int count = 0;
	//for(std::map<Key, int>::iterator check = myMap.begin(); check != myMap.end(); ++check) {
	//	if(check->second > 0) count += check->second;	
	//}
	return count;
}

int getNumDenominator() {
	int count = 0;
	//for(std::map<Key, int>::iterator check = myMap.begin(); check != myMap.end(); ++check) {
	//	if(check->second < 0) count += check->second;	
	//}
	return count;
}*/

