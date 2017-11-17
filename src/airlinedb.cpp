//============================================================================
// Name        : airlinedb.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : A databank and data manipulator
//============================================================================

#include <iostream>
#include "Passenger.h"
#include "LinkedList.h"
#include "OrderedLinkedList.h"
using namespace std;


void mainMenu();
void addPas(OrderedLinkedList<Passenger>&);

int main() {

	cout<<"***DELTA AIRLINES ***"<<endl;
	cout<<"Please choose an operation:"<<endl;

	mainMenu();

	return 0;
}

//Controls the user input and main program functions
void mainMenu(){
	OrderedLinkedList<Passenger> one;
	OrderedLinkedList<Passenger> two;
	OrderedLinkedList<Passenger> three;
	OrderedLinkedList<Passenger> four;

	char input;
	string flight;
	string first;
	string last;
	Passenger pasSearch;
	Passenger* pasFound;
	int flightNum = 0;

	cout<<"A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit):"<<endl;
	cin>>input;

	do{
		switch(input)
		{
		case 'A':
		case 'a':
			cout<<"Enter flight number: ";
			cin>>flight;

			if(flight == "100"){
				addPas(one);
			}
			else if(flight == "200"){
				addPas(two);
			}
			else if(flight == "300"){
				addPas(three);
			}
			else if(flight == "400"){
				addPas(four);
			}
			else
				cout<<"Invalid input"<<endl;

			flight.clear();

			break;
		case 'S':
		case 's':
			cout<<"Enter first name: ";
			cin>>first;
			cout<<"Enter last name: ";
			cin>>last;

			pasSearch.setFirst(first);
			pasSearch.setLast(last);

			pasFound = one.search(pasSearch);

			if(pasFound != NULL){
				flightNum = 100;
			} else
			{
				pasFound = two.search(pasSearch);

				if(pasFound != NULL){
					flightNum = 200;
				}
				else{
					pasFound = three.search(pasSearch);

					if(pasFound != NULL){
						flightNum = 300;
					}
					else{
						pasFound = four.search(pasSearch);

						if(pasFound != NULL){
							flightNum = 400;
						}
					}
				}
			}

			if(pasFound == NULL){
				cout<<"Cannot find passenger on any flight."<<endl;
			}
			else{
				cout<<"Flight Number: "<<flightNum<<endl;
				pasFound->printPas();
			}

			first.clear();
			last.clear();

			break;
		case 'D':
		case 'd':
			cout<<"Enter flight number: ";
			cin>>flight;
			if(flight != "100" && flight != "200" && flight != "300"
					&& flight != "400"){
				cout<<"Invalid input."<<endl;

				flight.clear();
				break;
			}
			else{
				cout<<"Enter first name: ";
				cin>>first;
				cout<<"Enter last name: ";
				cin>>last;

				Passenger pas;
				pas.setFirst(first);
				pas.setLast(last);

				if(flight == "100"){
					one.deleteNode(pas);
				}
				else if(flight == "200"){
					two.deleteNode(pas);
				}
				else if(flight == "300"){
					three.deleteNode(pas);
				}
				else if(flight == "400"){
					four.deleteNode(pas);
				}

				flight.clear();
				break;
			}
		case 'L':
		case 'l':
			cout<<"Enter flight number: ";
			cin>>flight;
			if(flight == "100"){
				one.listNodes();
			}
			else if(flight == "200"){
				two.listNodes();
			}
			else if(flight == "300"){
				three.listNodes();
			}
			else if(flight == "400"){
				four.listNodes();
			}
			else
				cout<<"Invalid input."<<endl;

			flight.clear();

			break;
		case 'Q':
		case 'q':
			break;
		}

		cout<<"A(Add) | S (Search) | D(Delete) |L(List) |Q(Quit):"<<endl;
		cin>>input;

	}while(input != 'Q' && input != 'q');

	one.destroy();
	two.destroy();
	three.destroy();
	four.destroy();
}

//adds a passenger to one of the linked lists
void addPas(OrderedLinkedList<Passenger>& list){
	Passenger newPas;
	string input;

	cout<<"Enter first name: ";
	cin>>input;
	/*if(std::any_of(input.begin(), input.end(), ::isdigit)){
		cout<<"Invalid input."<<endl;
		return;
	}*/
	newPas.setFirst(input);

	cout<<"Enter last name: ";
	cin>>input;
	/*if(std::any_of(input.begin(), input.end(), ::isdigit)){
		cout<<"Invalid input."<<endl;
		return;
	}*/
	newPas.setLast(input);
	input.clear();
	cin.ignore(1000, '\n');
	cout<<"Enter address: ";
	getline(cin, input);
	newPas.setAddress(input);

	cout<<"Enter phone: ";
	cin>>input;
	newPas.setPhone(input);

	list.insertNode(newPas);
}
