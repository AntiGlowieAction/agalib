#include <cstddef>
#include <stdexcept>

#include "..\agalib\includes\queues.hh"

namespace Queues{

    template <typename T> bool Simple<T>::enqueue(T value){
        Node *newNode = new Node;
        newNode->value = value;
        if(head == tail == nullptr){
            head = tail = newNode;
            newNode->next = nullptr;
            return true;
        }else{
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
            return true
        }
        return false;
    }

    template <typename T> T Simple<T>::dequeue(){
        T temp;
        if(head == tail == nullptr) throw std::runtime_error("Dequeuing from empty Queue!");
        if(head == tail){
            temp = head->value;
            delete head;
            head = tail = nullptr;
            return temp;
        }
    }

    template <typename T> Cyclic<T>::Cyclic(size_t capacity){
        this->cycle = new T[size];
        this->head = 0;
        this->tail = 0;
    }

    template <typename T> bool Cyclic<T>::enqueue(T value){
        
    }

}