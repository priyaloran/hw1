#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// 1. push back: Adds a new value to the back of the list O(1)
void ULListStr::push_back(const std::string& val) {
  // First check that the list is empty from the back
  if (tail_ == nullptr) {
    // If it is empty, we allocate another node item
    // Size will be updated at the end
    head_ = tail_ = new Item();
  }
  // Also check if the list is full from the back
  // Since there are 10 items, last would point to index 10
  if (tail_->last == 10) {
    Item* add = new Item();
    add->prev = tail_;
    tail_->next = add;
    tail_ = add;
  }
  // Update last to the next index of the array after we established
  // of we were at the end or not
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}

// 2. push front: Adds a new value to the front of the list O(1)
void ULListStr::push_front(const std::string& val) {
  // First check if the list is empty from the front
  if (head_ == nullptr) {
    // Did this a little different
    // Add a new node item, manually assign first and last variables
    // with values in this new node, and increase size because we have
    // another value
    head_ = tail_ = new Item();
    head_->val[head_->first] = val;
    head_->last++;
    size_++;
    return;
  }
  // Then check that the head item has no room before the first item
  // Since first points to the first item, check if it is at index zero
  // Again, manually change the new node item's first and last to the
  // last/one past the last of the new front node
  if (head_->first == 0) {
    Item* add = new Item();
    add->val[9] = val;
    add->first = 9;
    add->last = 10;
    add->next = head_;
    head_->prev = add;
    head_ = add;
    size_++;

  }
  // Update first to the first index that there is a value
  else  {
    head_->first--;
    head_->val[head_->first] = val;
    size_++;
  }
}

// 3. pop front: Removes a value from the front of the list O(1)
void ULListStr::pop_front() {
  // Check that the list is not empty all together, use given function
  // We just return the list
  if (empty())  {
    return;
  }
  // Then check if individual nodes/items have empty arrays
  // If the first and last index point to the same location, it is empty
  // Since last is one past the last value index, update first
  head_->first++;
  if (head_->first == head_->last) {
    // Here we must deallocate this item
      Item* temp = head_;
      head_ = head_->next;
      // This may have been the only item, so fix head and tail_
      // to null because list is now empty
      if (head_ == nullptr) {
        tail_ = nullptr;
      }
      else  {
        head_->prev = nullptr;
      }
      delete temp; 
  }
  size_--;
}

// 4. pop back: Removes a value from the back of the list O(1)
void ULListStr::pop_back() {
  // Check that the list is not empty all together
  // We just return the list
  if (empty())  {
    return;
  }
  // Check that the array is not empty
  // Since first is on the actually index value, update last
  tail_->last--;
  if (tail_->first == tail_->last) {
    // Here we must deallocate this item
      Item* temp = tail_;
      tail_ = tail_->prev;
      // If after deallocation, tail is null, the list must be empty
      // so update head
      if (tail_ == nullptr) {
        head_ = nullptr;
      }
      else  {
        tail_->next = nullptr;
      }
      delete temp; 
  }
  size_--;
}

// 5. back: Returns a const reference to the back element O(1)
std::string const & ULListStr::back() const  {
  // On the slides it says we can assume the list is not empty
  std::string const& lastItem = tail_->val[tail_->last - 1];
  return lastItem;
}

// 6. front: Returns a const reference to the front element O(1)
std::string const & ULListStr::front() const  {
  // On the slides it says we can assume the list is not empty
  std::string const& firstItem = head_->val[head_->first];
  return firstItem;
}

// 7. getValAtLoc: Returns a pointer to the item at index, loc,
// if loc is valid and NULL otherwise O(n)
std::string* ULListStr::getValAtLoc(size_t loc) const {
  // We must check for cases that the location is above 9 since 
  // the max size of an array in a node is 10

  // First check if the list is empty
  if (empty())  {
    return NULL;
  }

  // The specific index of the given node of the location
  int indexNum = 0;
  // Number of elements traversed
  size_t count = 0;

  Item* temp = head_;

  // Go through each node until the end is hit 
  // in which case the location is not valid
  while (temp != nullptr) {
    // Tells us how many nodes there are to determine
    // valid location because it is used in an expression to
    // calculate is loc is in bounds
    size_t nodeCount = temp->last - temp->first;

    // This means the location is in this node and
    // is valid
    if (loc < count + nodeCount)  {
      indexNum = temp->first + (loc - count);
      return &(temp->val[indexNum]);
    }
    // Otherwise, the location may be in another node
    // or may not be valid
    count += nodeCount;
    temp = temp->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}