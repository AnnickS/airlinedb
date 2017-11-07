/*
 * OrderedLinkedList.h
 *
 *  Created on: Nov 1, 2017
 *      Author: annic
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_
#include "LinkedList.h"
#include "Passenger.h"

template<class T>
class OrderedLinkedList: public LinkedList<T>{
	node<T>* head, last;
	int count;
public:
	OrderedLinkedList();
	T& search(T& item) override;
	void insertNode(T& item);
	void deleteNode(T& item);
	void listNodes();
};

template<class T>
T& OrderedLinkedList<T>::search(T& item){
	node<T>* p = head;

	for(int i = 0; i < count; i++){
		if(p->data > item)
			break;
		if(p->data == item){
			return p->data;
		}
		else
			p = p->next;
	}
}

template<class T>
void OrderedLinkedList<T>::insertNode(T& item){
	node<T>* p;
	p->data = item;

	if(count == 0){
		head = p;
		count++;
	}
	if(item <= head->data){
		p->next = head;
		head = p;
		count++;
	}
	else if(item >= last.data){
		last.next = p;
		last = p;
		count++;
	}
	else{
		node<T>* temp = head;
		for(int i = 0; i < count-1; i++){
			if((temp->next->data >= item) &&
					(temp->data < item)){
				p->next = temp->next;
				temp->next = p;
				count++;
			}
			else
				temp = temp->next;
		}
	}
}

template<class T>
void OrderedLinkedList<T>::deleteNode(T& item){
	node<T>* p = head;

	if(count == 0){
		cout<<"Item does not exist."<<endl;
	}
	else if(head->data == item){
		head = p->next;
		delete p;
		count--;
	}
	else{
		for(int i = 0; i < count-1; i++){
			if(p->next->data == item){
				node<T>* temp = p->next;
				p->next = p->next->next;
				delete temp;
				count--;
			}
			else if(i == count -1){
				cout<<"Item does not exist."<<endl;
			}
		}
	}
}

template<class T>
void OrderedLinkedList<T>::listNodes(){
	node<T>* p = head;
	for(int i = 0; i < count; i++){
		cout<<p->data;
		p = p->next;
	}
}


#endif /* ORDEREDLINKEDLIST_H_ */
