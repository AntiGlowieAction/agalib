#include <cstddef>
#include "..\agalib\includes\lists.hh"

namespace Lists{

    template <class T> Linked<T>::~Linked(){}
    

    template <class T> bool Linked<T>::push(T value){
        size++;
        Node *newNode = new Node;
        newNode->value = value;

        if(head == nullptr){
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

    template <class T> bool Linked<T>::insert(T value, size_t pos){
        Node *newNode = new Node;
        newNode->value = value;
        Node *iterrator = head;

        if(pos > size || pos < 0){
            throw std::invalid_argument("Index out of bounds!");
        }else{
            for(int i = 0; i < pos; i++){
                *iterrator = iterrator->next;
            }

            if(pos == 0) head = newNode;
            newNode->next = iterrator;
            iterrator->next = newNode;
            return true;
        }  
    	return false;
    }

    template <class T> bool Linked<T>::remove(size_t pos){
        Node *iterator = head;
        if(pos > size - 1){
            throw std::invalid_argument("Index out of bounds!");
        }
        if(pos == 0){
            head = head->next;
            delete iterator;
            return true;
        }else{
            for(int i = 0; i < pos; i++){
                iterator = iterator->next;
            }
            Node *help = iterator;
            iterator->next = iterator->next->next;
            delete help;
            return true;
        }
        return false;
    }


}
