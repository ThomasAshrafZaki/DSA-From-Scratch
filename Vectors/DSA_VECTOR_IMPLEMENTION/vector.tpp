#include "vector.hpp"
#include <iostream>
using namespace std;

// Template function to extend the capacity of the vector if it's full
template <typename arrType>
void vector<arrType>::extend_capacity(){
    cout << "vector capacity expended \n"; 
    this->capacity = this->capacity * 2; // Double the capacity value
    arrType * arr2 {nullptr};
    arr2 = new arrType [this->capacity] {}; // Allocate new array with larger capacity
    for (int i = 0 ; i < size ; i++ ){ 
        arr2[i]= arr[i]; // Copy old elements to the new array
    }
    swap(arr , arr2); // Swap old array with new array
    delete [] arr2 ; // Delete the temporary (old) array
}

// Default constructor - creates vector with initial capacity of 10
template <typename arrType>
vector<arrType>::vector() {
    capacity = 10;      
    size = 0;          
    arr = new arrType[capacity] {}; // Allocate array with default values
}

// Constructor with custom initial size
template <typename arrType> 
vector<arrType>::vector(int size_v) : size(size_v){
    if (size < 0 ){
        size = 0; // Avoid negative sizes
    }
    capacity = size + 10 ; // Give some extra capacity
    arr = new arrType [capacity] {}; // Allocate array with default values
}

// Destructor - frees the memory used by the array
template <typename arrType> 
vector<arrType>::~vector(){
    delete[] arr ; // Free allocated memory
    arr = nullptr; // Avoid dangling pointer
    cout<<"Thanks\n"; // Message for confirmation
}

// Print all elements of the vector
template <typename arrType>
void vector<arrType>:: print () const {
    cout << "the vector is : { ";
    for (int i = 0 ; i < size ; i++ ){
        cout << arr[i] <<" " ;
        if (!(i == size-1)){
          cout <<", ";  // Add comma between values
        }
    }
    cout << "}\n";
}

// Find and print all indices that match a given value
template <typename arrType>
void vector<arrType>:: find_indices (arrType val){
    cout << "the value was found in indices {  ";
    bool check = false;
    for (int i = 0 ; i < size ; i++ ){ 
            if (val == arr[i]){
                cout << i <<"   " ; // Print matching index
                check = true;
            }
        }
    if(!check){
        cout<<"nothing"; // If value not found
    }    
    cout << "}\n";    
}

//get size
template <typename arrType>
int vector<arrType>:: get_size (){
    return size;
}

// Return the first index where the value is found
template <typename arrType>
arrType vector<arrType>:: find_first_index (arrType val){
    for (int i = 0 ; i < size ; i++ ){ 
            if (val == arr[i]){
                return i; // Return the index if found
            }
        }
    // if not found
    throw std::out_of_range ("Not Found"); // Throw exception if not found
}

// Append value at the end of the vector
template <typename arrType>
void vector<arrType>:: push_back (arrType val){
    if(size==capacity){
        extend_capacity(); // Resize if full
    }
    arr[size ++] = val; // Add value and increment size
}

// Insert value at specific index
template <typename arrType>
 void vector<arrType>:: insert_val (int index , arrType val){
    if(size==capacity){
        extend_capacity(); // Resize if needed
    }
    if(index <= size && index >= 0){ // Valid index check
        // Shift elements to make space
        for(int i = size-1 ; i >= index ; i--){
            arr[i+1] = arr[i];
        }
        arr[index]=val; // Insert value
        size++;
    }
    else{
        throw std::out_of_range("Invalid index"); // Throw if index is wrong
    }
 }
 template <typename arrType>
 void vector<arrType>::delete_val (int index){
    if(index <= size && index >= 0){ // Valid index check
        // Shift elements to make space
        for(int i = index ; i <size-1 ; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    else{
        throw std::out_of_range("Invalid index"); // Throw if index is wrong
    }
 }

// Set a value at a specific index
template <typename arrType>
void vector<arrType>::set_val(int index , arrType val){
    if(index < size && index >= 0){
        arr[index]= val; // Set the value
    }
    else 
        cout<<"the index not found \n"; // Invalid index
}

// Return the value at a specific index
template <typename arrType>
arrType vector<arrType>::get_val (int index){
    if(index < size && index >= 0){
        return arr[index]; // Return the value
    }
    else {
        throw std::out_of_range("Invalid index"); // Error for invalid access
    }
}
