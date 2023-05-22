#include "../includes/queues.hh"

namespace Queues {

	template <typename T> Simple<T>::~Simple(){
		this->clear();
	}

    template <typename T> bool Simple<T>::enqueue(T value){
        Node *node = new Node{value, nullptr};
		if (!node) {
		    return false;
		}
		if (!tail) {
		    head = node;
		    tail = node;
		}
		else {
		    tail->next = node;
			tail = node;
		}
		return true;
    }

    template <typename T> T Simple<T>::dequeue(){
        if(!head) {
		    throw std::runtime_error("Dequeuing from empty Queue!");
		}
		if (head == tail) {
		    tail = nullptr;
		}
		Node* next = head->next;
		T value = head->value;
		delete head;
		head = next;
		return value;
    }

	template <typename T> bool Simple<T>::has(T value){
		Node *iterator = head;

        while (iterator){
            if(iterator->value == value) return true;
            iterator = iterator->next;
        }
        
        return false
	}

	template <typename T> void Simple<T>::clear(){
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

    template <typename T> Cyclic<T>::Cyclic(size_t capacity){
        this->cycle = new T[capacity];
        this->head = 0;
        this->tail = 0;
    }

	template <typename T> Cyclic<T>::~Cyclic(){
		delete this->cycle;
	}

    template <typename T> void Cyclic<T>::enqueue(T value){
		this->cycle[(head++)%capacity] = value;
    }

	template <typename T> T Cyclic<T>::dequeue(){
		return this->cycle[(tail++)%capacity];
	}

	template <typename T> bool Cyclic<T>::has(T value){
		for(int i = 0; i < length; i++){
            if(this->array[i] == value) return true;
        }
        return false;
	}

	template <typename T> void Cyclic<T>::reset(){
		for(int i = 0; i < this->capacity; i++){
			this->cycle[i] = NULL;
		}
		head = 0;
		tail = 0;
		return;
	}

	template <typename T> Priority<T>::Priority(bool flag){
		this->flag = flag;
	}

	template <typename T> Priority<T>::~Priority(){} 

	template <typename T> bool Priority<T>::enqueue(T value){
		//TODO: Finish this function
		Node *newNode = new Node;
		newNode->value = value;
		Node *iterator = &head;

		while(iterator)
		
	}



}
