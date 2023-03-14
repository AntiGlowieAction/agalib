#ifndef AGALIB_QUEUE_HH
#define AGALIB_QUEUE_HH

#include <stdexcept>
#include <cstddef>

namespace Queues {
    /**
     * @brief Basic Queue structure.
     * 
     */
    template <typename T>
    class Simple {
        private:
        struct Node {
            Node* next;
            T value;
        };
        Node* head;
        Node* tail;
        public:
        /**
         * @brief Add an element to the queue. If the action was succesful return true, otherwise false.
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool enqueue(T value);
        T dequeue();
    };
    /**
     * @brief Set size Queue which loops around itself.
     * 
     */
    template <typename T>
    class Cyclic{
        private:
            T *cycle = nullptr;
            size_t head = 0;
            size_t tail = 0;
            size_t capacity = 0;
            size_t length = 0;
        public:
            Cyclic(size_t capacity);
            bool enqueue(T value);
            T dequeue();
    };
    /**
     * @brief Queue that allows priority enqueueing.
     * 
     */
    template <typename T>
    class Priority;
    /**
     * @brief Bidirectional queue
     * 
     */
    template <typename T>
    class Dequeue;
}

#endif