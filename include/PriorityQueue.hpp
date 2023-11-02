#include <exceptions/EmptyException.hpp>

template <typename T>
class PriorityQueue {
  public:
    /**
     * Insert a value.
     * 
     * @param t Value to insert.
     */
    virtual void insert(T t) = 0;
    
    /**
     * Remove best value.
     * 
     * @throws EmptyException If queue is empty.
     */
    virtual void remove() = 0;
    
    /**
     * Return best value.
     * 
     * <p>The best value is the largest value in the queue as determined
     * by the queue's comparator. </p>
     *
     * @return best value in the queue.
     * @throws EmptyException if the queue is empty.
     */
    virtual T best() = 0;
    
    /**
     * Check if no elements present.
     * 
     * @return True if queue is empty, false otherwise.
     */
    virtual bool empty() = 0;
};