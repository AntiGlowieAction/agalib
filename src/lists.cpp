#include "../includes/lists.hh"

namespace Lists {

    template <typename T> Linked<T>::~Linked() {
        this->clear();
    }

    template <typename T> bool Linked<T>::push(T value){
        Node *node = new Node{value, head};
        if (!node) {
            return true;
        }
        head = node;
        size++;
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
        Node *prev = nullptr;

        while(iterator){
            if(iterator->value == value){
                prev->next = iterator->next;
                delete iterator;
                return true
            }
            prev = iterator;
            iterator = iterator->next;
        }
        return false;
        
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

        while (iterator){
            if(iterator->value == value) return true;
            iterator = iterator->next;
        }
        
        return false
    }

    template <typename T> void Linked<T>::clear(){
        Node *iterator = head;
        Node *temp;

        while (iterator){
            temp = iterator;
            iterator = iterator->next;
            delete temp;
        }

        head = nullptr;
        return;
    }

    template <typename T> Array<T>::Array(size_t cap){
       this->array = new T[cap];
       this->capacity = cap;
    }

    template <typename T> bool Array<T>::expand(size_t cap){
        T *newArray = new T[this->capacity + cap];
        if(!newArray) return false;
        memcpy(newArray, this->array, this->capacity);
        this->capacity += cap;
        delete this->array;
        this->array = newArray;
        return true;
    }

    template <typename T> bool Array<T>::push(T value){
        if(length == capacity){
            if(!expand(capacity)){
                return false;
            }
        }
        this->array[this->length++] = value;
        length++;
        return true; 
    }

    template <typename T> T Array<T>::pop(){
        if(length == 0) throw std::runtime_error("Poping from empty array!")
        return this->array[--(this->length)];
    }

    template <typename T> size_t Array<T>::find(T value){
        for(int i = 0; i < length; i++){
            if(this->array[i] == value) return i;
        }
        return -1;
    }

    template <typename T> bool Array<T>::has(T value){
        for(int i = 0; i < length; i++){
            if(this->array[i] == value) return true;
        }
        return false;
    }

    template <typename T> void Array<T>::clear(){
        this->length = 0;
    }
    
}
