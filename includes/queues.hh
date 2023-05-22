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
        Node* head = nullptr;
        Node* tail = nullptr;
        public:
        /**
         * @brief Destroy the Simple object
         * 
         */
        ~Simple();
        /**
         * @brief Add an element to the queue. If the action was succesful return true, otherwise false.
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool enqueue(T value);
        /**
         * @brief Remove and return an element from the queue.
         * 
         * @return T 
         */
        T dequeue();

        /**
         * @brief Empty the queue.
         * 
         */
        void clear();

        /**
         * @brief Search for an element in the list. If present return true otherwise return false. The action happens in O(n) time.
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool has(T value);
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
            /**
             * @brief Construct a new Cyclic queue with a certain capacity
             * 
             * @param capacity 
             */
            Cyclic(size_t capacity);
            /**
             * @brief Add a element to the queue. If the action was succesful return true, otherwise false.
             * 
             * @param value 
             * @return true 
             * @return false 
             */
            /**
             * @brief Destroy the Cyclic object
             * 
             */
            ~Cyclic();

            void enqueue(T value);
            /**
             * @brief Remove an element from the list. The function returns the removed element.
             * 
             * @return T 
             */
            T dequeue();

            /**
            * @brief Search for an element in the list. If present return true otherwise return false. The action happens in O(n) time.
            * 
            * @param value 
            * @return true 
            * @return false 
            */
        bool has(T value);

            /**
             * @brief Empty the queue and set the head and tail at the start of it
             * 
             */
            void reset();
    };
    /**
     * @brief Queue that allows priority enqueueing.
     * 
     */
    template <typename T>
    class Priority{
        private:
        struct Node {
            Node* next;
            T value;
        };
        Node* head = nullptr;
        Node* tail = nullptr;
        bool flag;

        /**
         * @brief Construct a new Priority object.  If the flag passed is true the queue will sort itself in an ascending order and the 
         * first elements to dequeue will be the ones with the highest weight. Otherwise the queue will be sorted in a descending order 
         * and the elements with the lowest weight will be dequeued first.
         * 
         */
        Priority(bool flag);
        /**
         * @brief Destroy the Priority object
         * 
         */
        ~Priority();
        /**
         * @brief Enqueue an element into the queue. The element will be placed in the queue according to its weight.
         * The function return true if succesful. Otherwise false.
         * 
         * @return true 
         * @return false 
         */
        bool enqueue(T value);

        /**
         * @brief Dequeue the element with the highest or lowest priority depending on what the flag is set to.
         * 
         */
        T dequeue();

        /**
         * @brief Return true if queue contains passed value. Otherwise false.
         * 
         * @return true 
         * @return false 
         */
        bool has();

        /**
         * @brief Clear the queue of all its elements.
         * 
         */
        void clear();
    };
    /**
     * @brief Bidirectional queue
     * 
     */
    template <typename T>
    class Dequeue;
}

#endif