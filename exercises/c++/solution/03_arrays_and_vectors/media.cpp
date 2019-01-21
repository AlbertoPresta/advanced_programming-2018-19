#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream> //it needs to store "temperature.txt"


template<typename T>
double mean(std::vector<T>& vec);
template <typename T>
T median(std::vector<T>& vec);

int main(){
	std::vector<double> temperatures;
    std::ifstream inputfile("temperatures.txt");
	if (inputfile){
		double value;
		while(inputfile >> value){
		      temperatures.push_back(value);
		  }
	  }
  	  std::cout<<"The number of elements in the file is: "<<std::endl;
      std::cout<<temperatures.size()<<std::endl;
	  
      std::cout<<"the elements of the file are: "<<std::endl;
	  for (auto i=0u;i<temperatures.size();++i){
		  std::cout<<temperatures[i]<<std::endl;
	  }
	  std::cout<<"the mean is: " << std::endl;
    double ris = mean(temperatures);
    std::cout<< ris<<std::endl;
	std::cout<<"The median is: "<<std::endl;
    auto ris2 = median(temperatures);
	std::cout<<ris2<<std::endl;
	
    return 0;
    
}


// create a function which calculate the mean of a vector
template <typename T>
double mean(std::vector<T>& vec){
     unsigned int totale_elementi = vec.size();
    int cont = 0;
    for (const auto& x : vec){
        cont +=  x;
    }
    
    double ris = (double) cont/totale_elementi;
    return ris;
}
// function which calculate the median of a vector
template <typename T>
T median(std::vector<T>& vec){
    std::sort(vec.begin(),vec.end());
    unsigned int totale_elementi = vec.size();
    if(totale_elementi%2==1)
        return vec[totale_elementi/2];
    else
        return (vec[totale_elementi/2 - 1 ] + vec[totale_elementi/2])/2;
    
    
    
}
