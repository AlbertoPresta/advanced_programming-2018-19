#include <iostream>


template <typename T>
T* create(const std::size_t n);
template<typename T>
void reverse(T*a,size_t n);




int main(){
    std::cout<<"insert the dimension of the array!"<<std::endl;
    int n;
    std::cin>>n;
    auto pointer = create<double>(n);
    std::cout<<"The reverse order is: " <<std::endl;
    reverse(pointer,n);
    delete[] pointer;
    return 0;
}

//function template that allocates on the heap one array of given size n and initialize its elements
// and returns the pointer to the first element.
template <typename T>
T* create(const std::size_t n){
    T* a {new T[n]}; // create an array allocated to the heap--now the pointer points to the first  element
    std::cout<<" Insert the value of the array!"<<std::endl;
    for (unsigned int i=0;i<n;++i){
        T value;
        std::cin>>value;
        *(a+i)= value ; // a[i]=value is equivalent
    }
    return a;
    }
// This function creates a fixed sentinel fixed before the first element of the array, then we pass thorugh the array given in input in a reverse order using the sentinel to stop usa in the right place
template<typename T>
void reverse(T* a,::size_t n){// input: puntatore al primo elemento!
    const T* const end =a-1; // creo una sentinella fissa prima del primo elemento
    for(auto i=a+n-1;i!=end;--i)
        std::cout<<*i<<std::endl;
    }
