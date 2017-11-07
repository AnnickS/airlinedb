/*
 * Passenger.h
 *
 *  Created on: Nov 1, 2017
 *      Author: annic
 */

#include <iostream>
using namespace std;

#ifndef PASSENGER_H_
#define PASSENGER_H_

struct Passenger{
	string firstName;
	string lastName;
	string address;
	string phone;
public:
	Passenger(string first, string last, string address, string phone);
	Passenger();
	void setFirst(string first);
	void setLast(string last);
	void setAddress(string address);
	void setPhone(string phone);
	string getFirst();
	string getLast();
	string getAddress();
	string getPhone();
	void printPas();
	void listPas();
	friend bool operator!=(const Passenger& p1, const Passenger& p2);
	friend bool operator==(const Passenger& p1, const Passenger& p2);
	friend bool operator>(const Passenger& p1, const Passenger& p2);
	friend bool operator<(const Passenger& p1, const Passenger& p2);
	friend bool operator>=(const Passenger& p1, const Passenger& p2);
	friend bool operator<=(const Passenger& p1, const Passenger& p2);
};

Passenger::Passenger(){
}

Passenger::Passenger(string first, string last, string address, string phone){
	firstName = first;
	lastName = last;
	this->address = address;
	this->phone = phone;
}

void Passenger::setFirst(string first){
	firstName = first;
}

void Passenger::setLast(string last){
	lastName = last;
}

void Passenger::setAddress(string address){
	this->address = address;
}

void Passenger::setPhone(string phone){
	this->phone = phone;
}

string Passenger::getFirst(){
	return firstName;
}

string Passenger::getLast(){
	return lastName;
}

string Passenger::getAddress(){
	return address;
}

void Passenger::printPas(){
	cout<<"First Name: "<<firstName<<endl;
	cout<<"Last Name: "<<lastName<<endl;
	cout<<"Address: "<<address<<endl;
	cout<<"Phone: "<<phone<<endl;
}

ostream& operator<<(ostream& os, const Passenger& pas)
{
	os<< pas.firstName << " " << pas.lastName << " ["
			<< pas.address << "] [" << pas.phone << "]" << endl;
	return os;
}

bool operator!=(const Passenger& p1, const Passenger& p2){
	int i = p1.lastName.compare(p2.lastName);
	if(i == 0){
		return false;
	}
	else
		return true;
}

bool operator==(const Passenger& p1, const Passenger& p2){
	int i = p1.lastName.compare(p2.lastName);
	if(i == 0){
		return true;
	}
	else
		return false;
}

bool operator>(const Passenger& p1, const Passenger& p2){
	int i = p1.lastName.compare(p2.lastName);
	if(i > 0){
		return true;
	}
	else
		return false;
}

bool operator<(const Passenger& p1, const Passenger& p2){
	int i = p1.lastName.compare(p2.lastName);
	if(i < 0){
		return true;
	}
	else
		return false;
}

bool operator>=(const Passenger& p1, const Passenger& p2){
	int i = p1.lastName.compare(p2.lastName);
	if(i >= 0){
		return true;
	}
	else
		return false;
}

bool operator<=(const Passenger& p1, const Passenger& p2){
	int i = p1.lastName.compare(p2.lastName);
	if(i <= 0){
		return true;
	}
	else
		return false;
}

#endif /* PASSENGER_H_ */
