#include <PriorityQueue.hpp>
#include <functional>
#include <iostream>

template <typename T>
class BinaryHeapPriorityQueue : public PriorityQueue<T> {
  public:
    /**
     * Default constructor. Uses the less() comparator by default.
     */
    BinaryHeapPriorityQueue(): comparator(std::less<T>()), heap({}) {}

    /**
     * Non-default constructor that takes in a comparator arg.
     * @param comp the comparator function the heap should use for sorting.
     */
    BinaryHeapPriorityQueue(std::function<bool(const T&, const T&)> comp): comparator(comp), heap({}) {}

    /**
     * Insert a value.
     * 
     * @param t Value to insert.
     */
    
    void insert(T t) override {
      if (this->empty()) {
        this->heap.push_back(NULL); //For easier indexing starting at 1.
        this->heap.push_back(t);
      } else {
        this->heap.push_back(t);
        int curr = this->heap.size() - 1;
        int parent_curr = curr / 2;
        // Swim "up" if the next inserted value is better than its parent.
        while (parent_curr > 0 && this->compare(t, this->heap[parent_curr]) == true) {
          swap(parent_curr, curr);
          curr = parent_curr;
          parent_curr = curr / 2;
        }
      }
    }

    /**
     * Remove best value.
     * 
     * @throws EmptyException If queue is empty.
     */
    void remove() override {
      if (this->empty()) {
        throw EmptyException("Your heap is empty lol");
      } else {
        int last = this->heap.size() - 1;
        int root = 1;

        // Check if there is only 1 element
        if (root == last) {
          this->heap.pop_back();
          this->heap.pop_back(); // Pop the NULL so empty() works property.
          return;
        }
        
        // If not, we proceed with swapping the root and last element.
        swap(last, root);
        this->heap.pop_back();

        // Check if there are only 2 elements and return if so.
        if (root == last - 1) {
          return;
        }

        T curr = this->heap[root];
        int left_child_index = root * 2;
        T left_child = this->heap[left_child_index];
        // If heap after removal has 2 elements (size 3)...
        if (this->heap.size() == 3) {
          if (this->compare(left_child, curr)) {
            swap(left_child_index, root);
            return;
          }
        }

        int right_child_index = left_child_index + 1;
        T right_child = this->heap[right_child_index];
        do {
          bool left_better = this->compare(left_child, right_child);
          if (left_better) {
            swap(left_child_index, root);
            root = left_child_index;
          } else {
            swap(right_child_index, root);
            root = right_child_index;
          }
            curr = this->heap[root];
            left_child_index = root * 2;
            left_child = this->heap[left_child_index];
            // If there is no right child...
            if (left_child_index == this->heap.size() - 1) {
              if (this->compare(left_child, curr)) {
                swap(left_child_index, root);
                break;
              } 
            }
            right_child_index = left_child_index + 1;
            right_child = this->heap[right_child_index];
        } while (this->compare(left_child, curr)); 
      }
    }

    /**
     * Return best value.
     * 
     * <p>The best value is the largest value in the queue as determined
     * by the queue's comparator. </p>
     *
     * @return best value in the queue.
     * @throws EmptyException if the queue is empty.
     */
    T best() override {
      if (this->empty()) {
        throw EmptyException("Your heap is empty lol");
      }

      return this->heap[1];
    }

    /**
     * Check if no elements present.
     * 
     * @return True if queue is empty, false otherwise.
     */
    bool empty() override {
      return this->heap.empty();
    }

    /**
     * Compares two values based on the comparator associated with the heap.
     * @param a the first value to compare.
     * @param b the second value to compare.
     * @return true if a is "better" than b, false otherwise.
     */
    bool compare(const T& a, const T& b) {
      return this->comparator(a, b);
    }

    /**
     * A helper function to print the heap.
     */
    void print_heap() {
      std::cout << "{ ";
      for (int i = 1; i < this->heap.size(); i++) {
        if (i == heap.size() - 1) {
          std::cout << this->heap[i] << " }" << std::endl;
        } else {
          std::cout << this->heap[i] << ", "; 
        }
      }
    }

  private:
    std::function<bool(const T&, const T&)> comparator;
    std::vector<T> heap;
    void swap(const int& lhs_index, const int& rhs_index) {
      T temp = this->heap[rhs_index];
      this->heap[rhs_index] = this->heap[lhs_index];
      this->heap[lhs_index] = temp;
    }
};