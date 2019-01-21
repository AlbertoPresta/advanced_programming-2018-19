#include<string>
#include <iostream>


bool is_prime(int n);


int main(){
	int prime[51]; //we create an array of int of dimension = 51 because we are sure that we don't have 51 prime numbers from 1 to 100
	prime[0]=2;
	int contatore = 1;
	for (int i=3;i<100;i++){
		if(is_prime(i)){
			prime[contatore]=i;
			contatore=contatore + 1;
		   }
	   }
    std::cout<<"tra 1 e 100 ci sono esattamente " << contatore << " numeri primi. "<< std::endl;
		for (int i=0; i<50;i++){
			std::cout<<prime[i]<< " " <<std::endl;
		}
    std::cout<<"Ecco qua la lista di numeri primi!"<<std::endl;
	for(int i=0;i<contatore;i++){
		std::cout<<"prime"<<"[ "<< i <<" ] "<< " = " <<prime[i] << std::endl;
	}
   
	return 0;
}




// I want to write a funtion which control if a number is prime or not
bool is_prime(int n){
	if (n==2 || n==1){
		return true;
	}
	if (n%2==0){       // when n is even and different from zero
		return false;
	}
	for (int i=3; i<n;i++){
		if(n%i==0){
		return false;}
		else{
			continue;
		}
	}
	return true;
}



