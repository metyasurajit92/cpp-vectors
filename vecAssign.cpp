#include<vector>
#include<string>
#include<iostream>

template<typename T>
void print_vec(std::string name, std::vector<T>& vec){
    std::cout<<name<<" [";
    for(const auto& item: vec){
        std::cout<<item<<", ";
    }
    std::cout<<"]"<<std::endl;
}


int main(){

//vector method: assign

//this operator is use for replaceing the element of container.
//same thing is done by = operator 
/*
1.
    = operator  -> copy entire vector or initialize via copy;
    assign      -> Replace contents with range/value assignments
2. 
    = operator  -> matches the size of the source vector
    assign      -> matches the number of assigned elements
3.
    = operator  -> Does not support ranges
    assign      -> Support ranges
4.
    = operator  -> Does not support specific value
    assign      -> Support specific value
5.
    = operator  -> copying value from another vector
    assign      -> Assigning or copying value from a range
*/
    std::vector<std::string> vec1 {};
    print_vec("vec1", vec1);

    vec1.assign(4, "Man"); //initialize with repeat of same element
    print_vec("vec1 modified: ", vec1);

    vec1.assign(2,"Woman");  //replace the entire vector and assign new element with new range
    print_vec("vec1 modified 2: ", vec1);


    auto const source= {3,2,1,3};
    auto destination = std::vector{1,2,4,3};
    print_vec("Destination before", destination);
    destination.assign( source.begin()+3, source.end()); //same thing can be done with assign_range in C++23
    print_vec("Destination after", destination);

    // ----- For only c++23 assign_range ---//

    destination.assign_range(source);
    print_vec("Destination after range assign", destination);

}