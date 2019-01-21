
#include<string>
#include <iostream>


//dichiarazione delle due funzioni 
void get_int();
void get_double();

int main() {
	get_int();
	get_double();
	return 0;
}
			
			
// riceve con cin (dall'utente) un valore double i : nel if si controlla se (int)i sia uguale a i:
// in tal caso abbiamo a che fare con un integer e quindi possiamo stamparlo.
// finchè non si scriverà un intero il programma ti chiedarà altri valori in maniera ricorsiva	
void get_int(){
std::cout << "Insert an integer number please:\n";
double i;
while(std::cin>>i){
   if(i!=(int)i){
   std::cin.clear();
   std::cin.ignore();
   std::cout<<"this is not an integer, try again!"<<std::endl;
      }
	else{
		std::cout<<"this is an integer!"<<std::endl;
		std::cout<<i<<std::endl;
		break;
	    }
	}
}

//  analogo alla funzione get_int()
void get_double(){
std::cout << "Insert a double please:\n";
double i;
while(std::cin>>i){
   if(i!=(int)i){
	std::cout<<"this is a double!"<<std::endl;
	std::cout<<i<<std::endl;
	break;
      }
	else{
		std::cin.clear();
		std::cin.ignore();
		std::cout<<"this is not a double, try again!"<<std::endl;
		
	    }
	}
}

			  
		
   
