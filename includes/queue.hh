#ifndef AGALIB_QUEUE_HH
#define AGALIB_QUEUE_HH

#include <cstddef>

namespace Queue {
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
        bool enqueue(T value);
        T dequeue();
    };
    /**
     * @brief Set size Queue which loops around itself.
     * 
     */
    template <typename T>
    class Cyclic;
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