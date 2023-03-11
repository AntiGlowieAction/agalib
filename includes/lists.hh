#include <cstddef>
#ifndef AGALIB_LISTS_HH
#define AGALIB_LISTS_HH


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
         * If there are multiple copies of the element it returns the position of the first one it finds.
         * It returns -1 if it did not find the element.
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


        void expand(size_t len);
        bool push(T value);
        bool set(T value, size_t pos);
        T pop();
        T get(size_t pos);
        size_t find(T value);
        bool has(T value);
        void clear();
    };
}

#endif