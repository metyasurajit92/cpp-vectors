#include<iostream>
#include<vector>
#include<string>
#include<locale>


int main(int argc, char const *argv[]) {
 
    //--------- Capacity -----------
    //empty() -> it checks if container has no elements
    //true -> container is empty
    //false-> otherwise not

    std::cout<<std::boolalpha;
    std::vector<int> myNumber {1,2,3,4,5,2,1}; //not empty
    std::vector<float> yourNumber {}; //empty

    std::cout<<myNumber.empty()<<std::endl; //false
    std::cout<<yourNumber.empty()<<std::endl; //true


    //size()-> return the number of elements 
    std::cout<<"myNumber: "<<myNumber.size()<<std::endl;
    std::cout<<"yourNumber: "<<yourNumber.size()<<std::endl;

   

    //max_size()-> returns the maximum number of elements in a vector of that data type
    std::vector<char>charVector{};
    std::vector<int>intVector{};
    std::vector<double>doubleVector{};

    // std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout<<"char: "<<std::dec<<charVector.max_size()<<std::endl;
    std::cout<<"int: "<<std::dec<<intVector.max_size()<<std::endl;
    std::cout<<"double: "<<std::dec<<doubleVector.max_size()<<std::endl;

    //capacity()->return the current allocated space  (number of elements)
    //
    std::cout<<myNumber.capacity()<<std::endl;

    //shrink_to_fit()->Request to remove unused capacity

    myNumber.shrink_to_fit();
    std::cout<<myNumber.capacity()<<std::endl;
}
