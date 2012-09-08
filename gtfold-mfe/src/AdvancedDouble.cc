#ifndef _MY_DOUBLE_H_
#define _MY_DOUBLE_H_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "gmp.h"
using namespace std;

const int PRECISION = 32;//1024;
const int PRINT_DIGITS_AFTER_DECIMAL = 10;

class AdvancedDouble{
	private: 
		double value;
	public:
		AdvancedDouble(){
			value=0.0;
		}
		AdvancedDouble(double val){
			value=val;
		}
		AdvancedDouble(const AdvancedDouble &obj1) {
			value=obj1.value;
		}
		void init(){
			value=0.0;
		}
		void deallocate(){
			
		}
		~AdvancedDouble(){
			deallocate();	
		}
		bool isInitialized(){
			return true;
		}
		void reset(){
			value=0.0;
		}
		void print()const{
			printf("%f", value);
		}
		void printInt()const{
			printf("%d", (int)(value));
		}
		void print(FILE* outFile)const{
			fprintf(outFile, "%f", value);
		}
		AdvancedDouble operator*(const AdvancedDouble &obj1) const {
			return value*obj1.value;
		}
		AdvancedDouble operator*(const double &obj1_double) const {
			return value*obj1_double;
		}
		AdvancedDouble operator+(const AdvancedDouble &obj1) const {
			return value+obj1.value;
		}
		AdvancedDouble operator+(const double &obj1_double) const {
			return value+obj1_double;
		}
		AdvancedDouble operator-(const AdvancedDouble &obj1) const {
			return value-obj1.value;
		}
		AdvancedDouble operator-(const double &obj1_double) const {
			return value-obj1_double;
		}
		AdvancedDouble operator/(const AdvancedDouble &obj1) const {
			return value/obj1.value;
		}
		AdvancedDouble operator/(const double &obj1_double) const {
			return value/obj1_double;
		}
		int compare(const AdvancedDouble &obj1) const{
			return value-obj1.value;
		}
		int compare(const double &obj1) const{
			return value-obj1;
		}
		bool operator==(const AdvancedDouble &obj1) const {
			return value==obj1.value;		
		}
		bool operator==(const double &obj1) const {
			return value==obj1;		
		}
		bool operator!=(const AdvancedDouble &obj1) const {
			return value!=obj1.value;		
		}
		bool operator!=(const double &obj1) const {
			return value!=obj1;		
		}
		bool operator<(const AdvancedDouble &obj1) const {
			return value<obj1.value;		
		}
		bool operator<(const double &obj1) const {
			return value<obj1;		
		}
		bool operator>(const AdvancedDouble &obj1) const {
			return value>obj1.value;		
		}
		bool operator>(const double &obj1) const {
			return value>obj1;		
		}
		bool operator<=(const AdvancedDouble &obj1) const {
			return value<=obj1.value;		
		}
		bool operator<=(const double &obj1) const {
			return value<=obj1;		
		}
		bool operator>=(const AdvancedDouble &obj1) const {
			return value>=obj1.value;		
		}
		bool operator>=(const double &obj1) const {
			return value>=obj1;		
		}
		AdvancedDouble& operator=(const AdvancedDouble &obj1) {
			if(this==&obj1) return *this;
			//if(isInitialized())this->deallocate();//TODO
			//else {bigValue=0;}
			value=obj1.value;
			return *this;
		}
		AdvancedDouble& operator=(const double &obj1) {
			//if(isInitialized())this->deallocate();//TODO
			//else {bigValue=0; smallValue=0;}
			value=obj1;
			return *this;
		}

};
#endif

