#include <ostream>
#include <vector>
#include <iostream>
#include <ranges>

using namespace std;
template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v){
    s.put('[');
    for(const auto& e: v){
        s<<e<<", ";
    }
    return s<<"]\n";
}

int main(){
    // contruct vector
    std::vector<int> vec1{1,3,4,5,3}; // initializer syntax of type int
    std::cout<<"1. "<<vec1;

    std::vector<std::string> words1 {"Ram", "Sham", "sona", "mona","golu", "dholu"}; // initializer syntax of type string
    cout<<"2. "<<words1;


    //form one vector to another vector
    vector<string> words2 (words1.begin()+2, words1.end()-2);
    cout<<"3. "<<words2;

    //vector with same element
    vector<string> words3 (5, "Surajit");
    cout<<"3. "<<words3;

    const auto rg = {"cat", "cow", "crow"};

    // #ifdef __cpp_lib_container_ranges
        std::vector<std::string> words4( std::from_range, rg);
        // std::cout<<"Range class observed!!";
    // #else
    //     std::vector<string> words4(rg.begin(), rg.end());
    // #endif
        std::cout<<"4. "<<words4;
}
