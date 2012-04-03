#include "key.h"
#include <stdio.h>

unsigned char type;
int i;
int j;

Key::Key(unsigned char type, int i, int j) {
	this->type = type;
	this->i = i;
	this->j = j;
}

bool Key::operator<(const Key& other) const {
	return (this->type != other.type ? this->type < other.type : this->i != other.i ? this->i < other.i : this->j < other.j);
}

bool Key::operator==(const Key& other) const {
	return (this->type == other.type && this->i == other.i && this->j == other.j);
}

unsigned char Key::getType() {
	return type;
}

int Key::getI() {
	return i;
}

int Key::getJ() {
	return j;
}

void Key::print() const {
	/*0 = u
	1 = up
	2 = s1
	3 = upm
	4 = s2
	5 = s3
	6 = u1*/
	switch(type){
	case 0: printf("u(%d, %d)", i, j); break;
	case 1: printf("up(%d, %d)", i, j); break;
	case 2: printf("s1(%d, %d)", i, j); break;
	case 3: printf("upm(%d, %d)", i, j); break;
	case 4: printf("s2(%d, %d)", i, j); break;
	case 5: printf("s3(%d, %d)", i, j); break;
	case 6: printf("u1(%d, %d)", i, j); break;
	}
	printf("\n");
}
