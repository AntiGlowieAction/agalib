#include "../includes/queues.hh"

namespace Queues {

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

    template <typename T> Cyclic<T>::Cyclic(size_t capacity){
        this->cycle = new T[capacity];
		// TODO: Implement.
        this->head = 0;
        this->tail = 0;
    }

    template <typename T> bool Cyclic<T>::enqueue(T value){
        
    }

}
