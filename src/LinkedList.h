/*
 * LinkedList.h
 *
 *  Created on: Oct 5, 2017
 *      Author: fatma.serce
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <assert.h>
#include <iostream>

template <class T>
struct node{
	T data;
	node* next;
};

template <class T>
class LinkedList{
   protected:
		node<T> *head, *last;
		int count;
   public:
		LinkedList();
		bool isEmpty();
		int length();

		void insertFirst(T& item);
//		T back();
//		T front();
		virtual T& search(T& item);
		void insertLast(T& item);
		virtual void deleteNode(T& item);
		virtual void destroy();
		~LinkedList() {destroy();}

};
template <class T>
LinkedList<T>::LinkedList(){
	head = last = NULL;
	count = 0;
}
template <class T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}

template <class T>
int LinkedList<T>::length(){
	return count;
}
template <class T>
void LinkedList<T>::insertFirst(T& item){
	node<T> *p = new node<T>;
	p->data = item;
	p->next = head;
	head = p;
	if(last==NULL)
		last = p;
	count++;
}
template <class T>
void LinkedList<T>::insertLast(T& item){
	node<T> *p = new node<T>;
	p->data = item;
	last->next = p;
	last = p;
	if(head==NULL)
		head = p;
	count++;
}
template<class T>
T& LinkedList<T>::search(T& item){
	node<T>* p = head;

	for(int i = 0; i < count; i++){
		if(p->data == item){
			return p->data;
		}
		else
			p = p->next;
	}
}
template<class T>
void LinkedList<T>::deleteNode(T& item){
	/*if((head == last) && (head->data = item)){
		head = last = NULL;
	}
	else if(last->data == item){

	}
	else
	{
		node<T> p = head;

		for(int i = 1; i < count; i++){
			if(p->next != NULL){
				if(p->next->data == item){
					node<T> temp = p->next;
					if(p->next == last)
						last = p;
					p->next = temp->next;
					delete temp;
				}
			}
		}
	}*/
}
template<class T>
void LinkedList<T>::destroy(){
	node<T>* p = head;
	node<T>* temp = p->next;

	for(int i = 0; i < count; i++){
		delete p;
		p = temp;
		temp = temp->next;
	}

	delete temp;
	delete head;
	delete last;
}


#endif /* LINKEDLIST_H_ */
