#include "dll.h"
DLL::DLL(){
    m_head=nullptr;
    m_tail=nullptr;

}
DLL::~DLL(){
    while(m_head!=nullptr){
        Node* temp=m_head;
        m_head=m_head->m_next;
        delete temp;
    }
    m_head=nullptr;
    m_tail=nullptr;

}
void DLL::insertAtHead(string toInsert){
        Node* newN= new Node;
        newN->m_data=toInsert;
    if(empty()){
        newN->m_previous=nullptr;
        newN->m_next=nullptr;
        m_head=newN;
        m_tail=newN;
    }else{
        newN->m_next=m_head;
        m_head->m_previous=newN;
        newN->m_previous=nullptr;
        m_head=newN;
    }
}
void DLL::addInBetween(string location, string toInsert){
    if(!empty()){
        Node* temp= m_head;
        while(temp!=nullptr && temp->m_data!=location){
            temp=temp->m_next;
        }
        if(temp!=nullptr){
            Node* newNode= new Node;
            newNode->m_data=toInsert;
            if(temp==m_tail){
                temp->m_next=newNode;
                newNode->m_previous=temp;
                newNode->m_next=nullptr;
                m_tail=newNode;          
            }else{
                temp->m_next->m_previous=newNode;
                newNode->m_next=temp->m_next;
                temp->m_next=newNode;
                newNode->m_previous=temp;
            }
        }else{
            cout<<"Sorry, "<<location<<" was not found in the list"<<endl;
        }

    }

}
bool DLL::empty() const {
    if(m_head==nullptr){
        return true;
    }
    return false;
}

void DLL::dump() const {
    if(!empty()){
        Node* temp=m_head;
        while(temp!=nullptr){
            cout<<temp->m_data<<" ";
            temp=temp->m_next;
        }
        cout<<endl;
    }

}
