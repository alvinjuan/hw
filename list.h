#ifndef LIST_H
#define LIST_H
#include "inheritance.h"
#include <iostream>

using namespace std;

class LinkedList{
    private:
        class Node {
            public: 
                athlete * data;
                Node *next, *prev;
        };
        Node *head;
        // function to merge sort list
        Node *mergeSort(Node *head){  
            if (!head || !head->next){
                return head; 
            }   
            Node *other = split(head);  
            // recurse for both left and right
            head = mergeSort(head);  
            other = mergeSort(other);  
            return merge(head,other); 
        }

    public: 
    
        // Node *split(Node *head);

        // inserts a new node in front of the list
        void insert(athlete *ath){  
            Node *tmp = new Node(); 
            tmp->data = ath;
            tmp->next = head;
            head = tmp;
        }

        // searches for a value in the list
        // returns true or false if found or not
        bool search(athlete *ath){
            if (head->data == ath){
                return true;
            }
            if (head == NULL){
                return false;
            }
            return search(ath);
        }

        // splits doubly linked list to 2 doubly linked list
        Node *split(Node *head){  
            Node *first = head;
            Node *second = head;
            while (first->next && first->next->next)  
            {  
                first = first->next->next;  
                second = second->next;  
            }  
            Node *tmp = second->next;  
            second->next = NULL;  
            return tmp;  
        }

        // combine linked lists
        Node *merge(Node *firstList, Node *otherList){  
            if (firstList == NULL){
                return otherList; 
            }
            if (otherList == NULL){
                return firstList;
            }  
            if (otherList->data->getHeight() < firstList->data->getHeight()){    
                otherList->next = merge(firstList,otherList->next);  
                otherList->next->prev = otherList;  
                otherList->prev = NULL;  
                return otherList;  
            }  
            else {  
                firstList->next = merge(firstList->next,otherList);  
                firstList->next->prev = firstList;  
                firstList->prev = NULL;  
                return firstList;  
            }  
        } 

        void mergeSort(){
            this->head = mergeSort(this->head);
        }

        // prints nonsorted linked list
        void printList(){
            Node *curr = head;
            if (head == NULL){
                cout << "List is empty";
            }
            while(curr != NULL){
                cout << curr->data << "  ";
                curr = curr->next;
            }
        }

        // prints linked list ascend and descend order
        void printSorted(Node *head){  
            Node *tmp = head;  
            cout << "Ascending order(cm): ";  
            while (head){  
                cout << head->data << " ";  
                tmp = head;  
                head = head->next;  
            }  
            cout << "\nDescending Order(cm): ";  
            while (tmp){  
                cout << tmp->data << " ";  
                tmp = tmp->prev;  
            }  
        } 
        
};

#endif