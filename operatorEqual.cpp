#include<vector>
#include<iostream>
#include<string>

//print function to make print the vector easily
 template<typename T>
 void print_vec(std::string name, std::vector<T>& vec){
    std::cout<<name<<" [";
    for(const auto& ele: vec){
        std::cout<<ele<<", ";
    }
    std::cout<<"]"<<std::endl;
 }


int main(){

    // operator = 
    // this replaces the contents of the container.

    std::vector<int> vec1 { 4,2,1,5,3}; //define and initialized vector of int element : 5
    std::vector<int> vec2 {}; //another vector element 0
    std::vector<int> vec3 {}; //another empty vector;

    //printing vector
    print_vec("vec1", vec1);
    print_vec("vec2", vec2);
    print_vec("vec3", vec3);

    //copy
    vec2 = vec1;
    std::cout<<" copy -----------\n";
    print_vec("vec1", vec1);
    print_vec("vec2", vec2);
    print_vec("vec3", vec3);

    //move from one vector to another 
    vec3 = std::move(vec1);
    std::cout<<" move -----------\n";
    print_vec("vec1", vec1);
    print_vec("vec2", vec2);
    print_vec("vec3", vec3);

    //copy from another container
    auto const v ={ 0,2,1,2}; //type of initializer_list

    vec1 = v;
    std::cout<<" copy from container-----------\n";
    print_vec("vec1", vec1);
    print_vec("vec2", vec2);
    print_vec("vec3", vec3);


}