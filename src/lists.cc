#include <cstddef>
#include <stdexcept>
#include "..\agalib\includes\lists.hh"


namespace Lists{

    template <typename T> Linked<T>::~Linked(){}
    

    template <typename T> bool Linked<T>::push(T value){
        size++;
        Node *newNode = new Node;
        newNode->value = value;

        if(!head){
            head = newNode;
            newNode->next = nullptr;
            return true;
        }else{
            newnode->next = head;
            head = newNode;
            return true;
        }

        return false;

    }

    template <typename T> T Linked<T>::pop(){
        if(!head) throw std::runtime_error("Poping from empty list!");
        Node *temp = head;
        T value = temp->value;
        head = head->next;
        delete temp;
        return value;
    }

    template <typename T> bool Linked<T>::remove(T value){
        Node *iterator = head;
        
    }
    

    template <typename T> size_t Linked<T>::find(T value){
        Node *iterator = head;

        for(int i = 1; i < size; i++){
            if(iterator->value == value) return i;
            iterator = iterator->next;
        }
        return -1;
    }

    template <typename T> bool Linked<T>::has(T value){
        Node *iterator = head;

        for(int i = 0; i < size; i++){
            if(iterator->value == value) return true;
            iterator = iterator->next;
        }
        return false
    }

    template <typename T> void Linked<T>::clear(){
        Node *iterator = head;
        Node *temp;

        for(int i = 0; i < size; i++){
            temp = iterator;
            iterator = iterator->next;
            delete temp;
        } 

        head = nullptr;
        return;
    }

}
