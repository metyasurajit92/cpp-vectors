#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include<list>

template <typename T> 
//print any vector 
void print_vec(std::string comment, std::vector<T>& vec){
    std::cout<<comment;
    for(const auto& el: vec){
        std::cout<<el<<", ";
    }
    std::cout<<std::endl;
}
//for understanding the emplace_back
  struct DemoCode
    {
        int age;
        std::string name;

        DemoCode(int a, std::string b): age(a), name(std::move(b)){
            std::cout<<"Constructed with copy"<<std::endl;
 
        }
        DemoCode(DemoCode&& others): age(others.age), name(std::move(others.name)){
         std::cout<<"Constructed with move"<<std::endl;
 
        }
        DemoCode& operator=(const DemoCode& others)=default;
    };

int main(){

    std::vector<int>v1{2,3,1,4,7,5};//construct vector

    //clear()->erase all the element from the container.
    std::cout<<"Size: "<<v1.size()<<" Capacity: "<<v1.capacity()<<std::endl; //6, 6
    v1.clear();
    std::cout<<"Size: "<<v1.size()<<" Capacity: "<<v1.capacity()<<std::endl;//0, 6


    //insert()-> insert has 5 overload functions
    //1. insert a copy of value before pos
    std::vector<int>v2{2,3,1,4,7,5};
    print_vec("original vector", v2);
    auto pos = v2.begin()+3; //pointer is pointing this element  in v2 it is 4. 11 will be inserted before 4.
    pos = v2.insert(pos, 11); //this will also update the pos : pointer will point the inserted element
    print_vec("overload 1: ", v2);

    // 2. insert a copy of rvalue (&&val) before pos
    int a = 25;
    pos = v2.insert(pos, std::move(a)); //a will be free of memory  it will be added before 11.

    print_vec("overload 2: ", v2);

    //3. insert a multiple number of element of same value
    pos = v2.insert(pos, 2, 20); // first parameter position , second parameter count , third parameter value.
    print_vec("overload 3: ", v2);

    //4. insert another vector 
    std::vector<int> v_add { 45, 78, 90};
    pos = v2.insert(pos, v_add.begin(), v_add.end()); //entire vector can be added or part of the vector using iterators.
    print_vec("overload 4: ", v2);

    //5. insert the value from a range;
    int arr[]={31,32,33,34};
    pos = v2.insert(pos, arr, arr + std::size(arr)); //to add entire array
    pos = v2.insert(pos, arr, arr +2); //add two element from the first 
    print_vec("overload 5a: ", v2);

    //also it can be added from a initializer list 

    pos = v2.insert(pos, {100, 101, 102, 104});
    print_vec("overload 5b: ", v2);

    //insert_range() introduce only in c++23;

    std::vector<std::string> v_str{"this", "is", "a", "vector"};//initialize string vector
    auto add_items = std::list{ "this", "is", "a", "list"};

    v_str.insert_range(v_str.end(), add_items); //v_str.end()<- the position of adding range
    print_vec("Range added: " , v_str);

    //emplace()-> it work similar like insert
    //advantages: it directly place the element in vector does not make a copy

    v_str.emplace(v_str.begin()+4, "and"); //no copy 
    print_vec("Emplace: " , v_str);

    //erase()-> remove element at the pos;
    //two overload
    //1. erase single element at pos;

    v_str.erase(v_str.begin()+2); //remove 3rd element element
    print_vec("Erase single: " , v_str);

    //2. erase element in a range(first, last)

    v_str.erase(v_str.begin()+1, v_str.end()-2);
    print_vec("Erase range: " , v_str);

    // the most used function in vector
    //push_back()-> if vector has no element it initialized or append the given element at the end of the element!!
    v1.push_back(11); //initialize from empty vector
    v1.push_back(12);  // append at the end
    v1.push_back(13);

    print_vec("Push_Back: ",v1); 
    //also can be added using std::move;
    std::string author{"Surajit"} ;
    v_str.push_back(std::move(author));
    print_vec("populated with std::move", v_str);


    //emplace_back()->append a new element at the end of the container
    //push_back() vs emplace_back()
    //1. push_back() require an existing object or rvalue tp add where as emplace_back directly construct the object in the container.
    //2. push_back use copy or move, emplace_back doesnot require copy or move. 
    //push_back is less efficient for complex data system than emplace_back().
    //push_back -> primitive data type.
    //emplace_back -> complex data type.

    std::vector<DemoCode>v_dc;
    std::vector<DemoCode>v_dc2;
    
    v_dc.push_back(DemoCode(2,"Second")); //need to create object first
    v_dc2.emplace_back(3, "Third"); //oject will be directly constructed at vector
    
    //c++23 features
    //append_range()->insert a range of element at the end
    std::vector<int>int_vec{3,1,2,5,9,4};
    print_vec("original: ", int_vec);
    auto add_range = {3,2,1,1};
    int_vec.append_range(add_range); //append at the end 
    print_vec("appended: ", int_vec);

    //

    //pop_back()-> remove the last element of the container
    int_vec.pop_back();
    print_vec("pop_back(): ", int_vec);

    //resize(count)-> changes the number of element according to count
    //if container.size() == count ->do nothing
    //if container.size() > count -> reduce from the front
    //if container.size() < count -> add default value at the end

    int_vec.resize(4); //reduce to 4 element-vector
    print_vec("resize: ", int_vec); 

    int_vec.resize(7); // add extra three 0(default) at the end
    print_vec("resize: ", int_vec);

    //overload
    int_vec.resize(10,6); //2nd arg is the default value now instead of 0
    print_vec("resize: ", int_vec);

    //swap() -> args another vector
    //swap between two vectors

    std::vector<float> a_v {1,2,3,4,5};
    std::vector<float> b_v {6,7,8,9,10};
    print_vec("a (before swap): ", a_v);
    print_vec("b (before swap): ",b_v);
    a_v.swap(b_v);          //a_v will be b_v and b_v will be a_v
    print_vec("a (after swap): ", a_v);
    print_vec("b (after swap): ",b_v);



}
