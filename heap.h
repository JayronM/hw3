#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> data; //storing heap
	int chld;//children/node
	PComparator Cmp; //comparator
	void heapifyTop(size_t index); //used to insert
	void heapifyDown(size_t index); //usaed to remove

};

// Add implementation of member functions here

//Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int ch, PComparator Cp) : chld(ch), Cmp(Cp){}

//deconstructor

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}
//size
template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
		return data.size();
}

//emput
template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
		return data.empty();
}
//push
template<typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
		data.push_back(item);
		heapifyTop(data.size()-1); //restore property/structure 
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty, cannot get top");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

	return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty, cannot pop.");
		}
	data[0] =data.back(); //replacement of root
		data.pop_back(); //last element gone
		if(!empty()){
			heapifyDown(0); //restore property/structure
  }

}


//heapifyTop
template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyTop(size_t index) {
		if(index == 0) return; //at root
		size_t ParentNode = (index-1)/ chld;
		if(Cmp(data[index], data[ParentNode])){ //comparing them
			std::swap(data[index], data[ParentNode]); //swap
			heapifyTop(ParentNode);//recursively compare to rstore structure
		}
}

//heapifyDown
template<typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index) {
	size_t BestIdx = index;
	size_t leftchild = index * chld+1;

	for(size_t i =0; i< static_cast<size_t>(chld); i++){
		size_t Truechild = leftchild +i;
		if(Truechild < data.size() && Cmp(data[Truechild], data[BestIdx])){
			BestIdx = Truechild;
		}
	}
		
		if(BestIdx != index){ //comparing them
			std::swap(data[index], data[BestIdx]); //swap
			heapifyDown(BestIdx);//recursively compare to rstore structure
		}
}



#endif

