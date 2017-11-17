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
public:
	OrderedLinkedList(){}
	T* search(T& item) override;
	void insertNode(T& item);
	void deleteNode(T& item);
	void listNodes();
};

template<class T>
T* OrderedLinkedList<T>::search(T& item){
	node<T>* p = this->head;

	for(int i = 0; i < this->count; i++){
		if(p->data > item){
			break;
		}if(p->data == item){
			return &(p->data);
		}
		else
			p = p->next;
	}

	return NULL;
}

template<class T>
void OrderedLinkedList<T>::insertNode(T& item){
	node<T>* p = new node<T>();
	p->data = item;

	if(this->count == 0){
		this->head = p;
		this->last = p;
		this->count++;
	}
	else if(item <= this->head->data){
		p->next = this->head;
		this->head = p;
		this->count++;
	}
	else if(item > this->last->data){
		this->last->next = p;
		this->last = p;
		this->count++;
	}
	else{
		node<T>* temp = this->head;

		for(int i = 0; i < this->count; i++){
			if((temp->next->data > item) &&
					(temp->data <= item)){
				p->next = temp->next;
				temp->next = p;
				this->count++;
				break;
			}
			else
				temp = temp->next;
		}
	}
}

template<class T>
void OrderedLinkedList<T>::deleteNode(T& item){
	node<T>* p = this->head;

	if(this->count == 0){
		cout<<"Item does not exist."<<endl;
	}
	else if((this->head->data == item) && (this->count == 1)){
		this->head = NULL;
		this->last = NULL;
		delete p;
		this->count--;
	}
	else if(this->head->data == item){
		this->head = this->head->next;
		delete p;
		this->count--;
	}
	else{
		for(int i = 0; i < this->count; i++){
			if(p->next->data == item){
				if(i == this->count-1){
					this->last = p;
				}
				node<T>* temp = p->next;
				p->next = p->next->next;
				delete temp;
				this->count--;
			}
			else if(i == this->count-1){
				cout<<"Item does not exist."<<endl;
			}
		}
	}
}

template<class T>
void OrderedLinkedList<T>::listNodes(){
	node<T>* p = this->head;
	for(int i = 0; i < this->count; i++){
		cout<<p->data;
		p = p->next;
	}
}


#endif /* ORDEREDLINKEDLIST_H_ */
