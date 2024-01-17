#include <iostream>
#include "Edge.cpp"
template<typename T>
class pqueue { // create priority queue data struct
    private:
    	T* arr;
    	size_t size;
        void swap(size_t a, size_t b) {
        	T temp = arr[a];
        	arr[a] = arr[b];
        	arr[b] = temp;
        }
        void sink(size_t i) {
			// create sink (item moves down)
        	while (i*2 <= size) {
        		T left_child = arr[i*2];
				T right_child = T(); // default object, was big edge
        		if (i*2 + 1 <= size) {			
					right_child = arr[i*2 + 1];
        		}
				if (arr[i] < left_child && arr[i] < right_child) {
					break;
				}
				if (left_child < right_child) {
					swap(i,i*2);
					i = i*2;
				} else {
					swap(i, i*2+1);
					i = i*2 + 1;
				}
        	}
	}
	void swim(size_t i) {
		// creates swim (item moves up)
		while (i > 1) {
			T parent = arr[i/2];
			if (arr[i] < parent) {
				swap(i,i/2);
			}
			else {
				break;
			}
			i/=2;
		}
	}
    public: 
    	pqueue() {
    		arr = new T[100];
    		size = 0;
    	}
        void enqueue(T const& x){
        	size++;
			arr[size] = x;
			this->swim(size);
        }   
        T deque(){
            // deletes front item in queue
			T ret = arr[1];
			swap(1,size);
			size--;
			sink(1);
			return ret;
        }

        int is_empty(){
			return size == 0;
        }
};
