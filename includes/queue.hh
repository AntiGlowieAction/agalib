#ifndef AGALIB_QUEUE_HH
#define AGALIB_QUEUE_HH

namespace Queue {
    /**
     * @brief Basic Queue structure.
     * 
     */
    template <typename T>
    class Simple;
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