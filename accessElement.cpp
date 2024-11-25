#include <ostream>
#include<vector>
#include<string>
#include<iostream>

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v){
    s.put('[');
    for(const auto& e: v){
        s<<e<<", ";
    }
    return s<<"]\n";
}

template <typename T>
void print_pointer(const T* vectorData, std::size_t size){
    std::cout<<"[";
    for (size_t i =0; i<size; i++){
        std::cout<<*(vectorData+i)<<", ";
    }
    std::cout<<"]"<<std::endl;
}

int main(){

// Element access methods of vector 
// ar operator[] front back data

//------------------------------
// ---at--- it returns a reference to the element at specific location {pos} 
//it has boundary checking
// if pos is out of range it will give std::out_of_range exception


std::vector<std::string> strs {"this", "is", "a", "string", "list"};

std::cout<<strs.at(1)<<std::endl; //get the element at specific pos

strs.at(4)="vector";
std::cout<<strs;

/*
strs.at(5) ="!!";  // this will give std::out_of_range exception
*/

//------------------------------
//operator [pos] ->  this returns the reference at the position of the vector
//similar like at method but in this case no error checking.
//this is faster than at() but less safe!!

std::cout<<strs[2]<<std::endl;

// auto text = strs[10];  //this will return blank or garbage value
// std::cout<<text<<std::endl;  
//------------------------------

// front()-> access the first element 
//it is equivalent to *(xx.begin() )

std::cout<<strs.front()<<std::endl;

//-------------------------------

// back() -> access the last element

std::cout<<strs.back()<<std::endl;

//-------------------------------
// data()-> returns a pointer to the underlying array serving as element storage.
auto vectorData = strs.data();
print_pointer(vectorData, strs.size());

}