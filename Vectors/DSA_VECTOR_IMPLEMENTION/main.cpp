#include <iostream>
#include "vector.hpp"
using namespace std;

int main() {
    vector<int> numbers ;
    for(int i = 0 ; i< 40 ; i++){
      numbers.push_back(10);
    }
    numbers.push_back(11);
    numbers.push_back(11);
    numbers.push_back(12);
    //numbers.find_indices(11);
    //cout<<numbers.find_first_index(11);
    //numbers.set_val(6 , 3);
    //cout<<numbers.get_val(12);
    numbers.insert_val(1 , 6);
    //numbers.print();
    return 0;
}