#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

int main(){

    //--begin()-> it returns an iterator 
    //iterator is a pointer which points to the first element

    std::vector<float> myNumber{1.2, 2.1, 1.3, 1.5, 2.3, 3.1};
    std::cout<<*(myNumber.begin())<<std::endl;

    //--end()-> it also return an iterator pointer points to the next space of the end element

    std::cout<<*(myNumber.end())<<std::endl; //it will return 0
    //to get last element
    std::cout<<*(myNumber.end()-1)<<std::endl;

    *(myNumber.begin())=10.1; //allowed to modify the element with this

    //--cbegin() and cend() -> these iterators are constant -> return a const value 

    //-- *(myNumber.cbegin()+2)=11.1; //this gives error!!

    std::for_each(myNumber.cbegin(), myNumber.cend(), [](const float& n){
        std::cout<<n<<" ";
    });
    std::cout<<std::endl;
    
    //.. rbegin() and redn()-> return reverse of the begin() and end() 

    std::cout<<*(myNumber.rbegin())<<std::endl; //return the last element

        std::for_each(myNumber.rbegin(), myNumber.rend(), [](const float& n){
        std::cout<<n<<" ";
    });
    std::cout<<std::endl;

    //..crbegin() crend()-> return const reverse iterators 

    
}