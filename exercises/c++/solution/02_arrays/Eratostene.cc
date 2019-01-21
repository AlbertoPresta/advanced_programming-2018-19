#include<iostream>
#include<cmath>

void Eratostene(std::size_t n);

int main(){
    std::cout<<"Insert an integer!"<<std::endl;
    std::size_t n ;
    std::cin>>n;
	std::cout<< "The list of prime numbers is:\n";
    Eratostene(n);
    
    return 0;
    }

void Eratostene(std:: size_t n){
    // first of all: creation of an array of dimensione n-1 which collects all numbers from 2 to n
    int* era {new int[n - 1]}; // allocated in the heap
    for (unsigned int i = 2;i<=n;i = i+1){    // initialize the array
        *(era+ i - 2) = i;
        
    }
   // idea: if a number is not prime, I will substitute it with 0 in the array
    for (unsigned int i=0; i < n-2;i=i+1){
        if (*(era+i)!=0){
            for(unsigned int k=i+1;k<n-1;k=k+1){  
                if(*(era+ k)!=0 && era[k]%era[i]==0)
                    era[k] = 0;
                 }
             }
        }
    
    // print the prime numbers
    for (unsigned int i=0;i<n-1;i++){
        if(*(era +i)!=0)
            std::cout<< *(era +i)<<std::endl;
    }
}
