#include <string>
#include <iostream>
#include "lib.h"

using namespace std;

void SUBD::insertAtFirstPos(string str){
        Node* newNode = new Node();
        newNode->str = str;
        head = newNode;
}

void SUBD::insertAtEndPos(string str){
        
        Node* newNode = new Node();
        newNode->str = str;
        if(!head){
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
            newNode->n++;
        }
        
        temp->next = newNode;
}

void SUBD::insertAtPos(string str, int pos){
        
        if(pos<1){
            cout << "Out of range" << endl;
            return;
        }

        if(pos==1){
            insertAtFirstPos(str);
            return;
        }
        Node* newNode = new Node();
        Node* temp = head;
        newNode->str = str;
        newNode->n = pos;

        for(int i = 1; i < pos - 1; ++i)
            temp = temp->next;

        if(!temp){
            cout << "Out of range" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        
}


    void SUBD::deleteAtFirstPos() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }

    void SUBD::deleteAtEndPos() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (!head->next) {
            delete head;   
            head = NULL;   
            return;
        }

        
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        
        
        delete temp->next; 
        
        temp->next = NULL; 
    }

    
    void SUBD::deleteAtPos(int pos) {
        if (pos < 1) {
            cout << "Out of range" << endl;
            return;
        }

        if (pos == 1) {
            deleteAtFirstPos();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            cout << "Position out of range." << endl;
            return;
        }
        
        Node* nodeToDelete = temp->next; 
       
        temp->next = temp->next->next;   
         
        delete nodeToDelete;            
    }

    
    void SUBD::printList() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->n << " -> " << temp->str << endl; 
            temp = temp->next;
        }
        cout << "NULL" << endl; 
    }







SUBD::SUBD(struct Node* headX) 
{
    head = headX;
}
SUBD::~SUBD()
{
}