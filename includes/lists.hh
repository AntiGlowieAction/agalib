#ifndef AGALIB_LISTS_HH
#define AGALIB_LISTS_HH

#include <stdexcept>
#include <cstddef>

namespace Lists {
    /**
     * @brief A singly linked list.
     * A singly linked list of nodes each of which contains a value to which the list was parameterised and a pointer to the next node.
     * The list is unsorted.
     */
    template <typename T>
    class Linked {
        private:
        struct Node {
            T value;
            Node* next; 
        };

        /**
         * @brief Destructor for Linked object.
         * 
         */
        ~Linked();
        /**
         * @brief Pointer to head of list.
         * 
         */
        Node* head = nullptr;
        public:
        /**
         * @brief Variable which keeps track of the number of elements in the list
         * 
         */
        size_t size = 0;
        /**
         * @brief Push new element to the beginning of the list.
         * Adds a new node with value passed as argument to the beginning of the list in O(1) time.
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool push(T value);
        /**
         * @brief Removes and return first element of the list.
         * The action is performed in O(1).
         * 
         * @throws todo: add which error is thrown
         * @return T 
         */
        T pop();
        /**
         * @brief 
         * 
         */
        bool remove(T value);
        /**
         * @brief Search for an element in the list and if it is present return its index. The index of the
         * first element in the list is equal to 0.The action happens in O(n) time.
         * If there are multiple copies of the element, return the position of the first one found.
         * Return true if removal is succesful, false if the element was not found. 
         * @throws todo: add which error is thrown
         * @param value 
         * @return size_t 
         */
        size_t find(T value);
        /**
         * @brief Search for an element in the list. If present return true otherwise return false. The action happens in O(n) time.
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool has(T value);
        /**
         * @brief Removes every element from the list, making it empty. It also deletes the elements from memory. 
         * The action happens in O(n) time.
         * 
         */
        void clear();
    };

    template <typename T>
    class Array {
        public:
        /**
         * @brief Pointer to the start of the array
         * 
         */
        T* array = nullptr;
        size_t capacity = 0;
        size_t length = 0;
        /**
         * @brief Construct a new Array object.
         * 
         * @param len 
         */
        Array(size_t len);
        /**
         * @brief Adds len number of spaces to the arraylist
         * 
         * @param len 
         */
        bool expand(size_t len);
        /**
         * @brief Add an value to the end of the list:
         * 
         * @warning This is ment to be used in conjunction with the poped method to add and remove elements i O(1) time.
         * @param value 
         * @return true 
         * @return false 
         */
        bool push(T value);
        /**
         * @brief Return and removes the element at the last index.
         * 
         * @return T 
         */
        T pop();
        /**
         * @brief Return the index of the first element with passed value.
         * 
         * @param value 
         * @return size_t 
         */
        size_t find(T value);
        /**
         * @brief Check whether there is an element with a certain value in array. 
         * 
         * @param value 
         * @return true 
         * @return false 
         */
        bool has(T value);
        /**
         * @brief Empty the array.
         * 
         */
        void clear();
    };
}

#endif