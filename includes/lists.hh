#include <cstddef>

namespace Lists {
    template <typename T>
    /**
     * @brief A singly linked list.
     * A singly linked list of nodes each of which contains a value to which the list was parameterised and a pointer to the next node.
     */
    class Linked {
        private:
        struct Node {
            T value;
            Node* next; 
        };
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
         * @brief Adds an element to the list at a declared index.
         * Adds an element somewhere in the middle of the list. The number of elements before the new element in the list is determined by the pos
         * argument. The element is added in O(n) time. Singly linked lists are not great for index specific operations. For such uses see Lists::Array.
         * 
         * @see Lists::Array
         * @param value 
         * @param pos 
         * @return true 
         * @return false 
         */
        bool insert(T value, size_t pos);

        /**
         * @brief Removes element at certain index from the list.
         * Index is determined by pos argument. The element is removed in O(n) time.
         * 
         * @param pos 
         * @return true 
         * @return false 
         */
        bool remove(size_t pos);

        /**
         * @brief Removes and return first element of the list.
         * The action is performed in O(1).
         * 
         * @throws todo: add which error is thrown
         * @return T 
         */
        T pop();

        /**
         * @brief Returns a pointer to an element at certein index in the list. It does not remove the element from the list.
         *The action happens in O(n) time. Singly linked lists are not great for index specific operations. For such uses see Lists::Array. 
         * 
         * @param pos 
         * @return T 
         */
        T get(size_t pos);

        /**
         * @brief Search for an element in the list and if it is present return its index.The action happens in O(n) time
         * 
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