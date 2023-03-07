#include <cstddef>

namespace List {
    template <typename T>
    class Linked {
        private:
        struct Node {
            T value;
            Node* next; 
        };
        Node* head = nullptr;
        public:
        size_t size = 0;
        bool push(T value);
        bool insert(T value, size_t pos);
        bool remove(size_t pos);
        T pop();
        T get(size_t pos);
        size_t find(T value);
        bool has(T value);
        void clear();
    };

    template <typename T>
    class Array {
        public:
        T* array = nullptr;
        void expand(size_t len);
        bool push(T value);
        bool set(T value, size_t pos);
        T pop;
        T get(size_t pos);
        size_t find(T value);
        bool has(T value);
        void clear();
    };
}