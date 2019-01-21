#include<iostream>             //I/O screen. std::cout
#include<memory>               //std::unique_ptr


//Describe a vector

template<typename T>    // you can write also clas despite typename
class Vector{
	std::unique_ptr<T[]> elem;     // the real data will be store in the heap
	std::size_t _size;
    std::size_t _free_slots = 0;
	
	void check_and_alloc();
	
public:
	Vector(const std::size_t length):   // constructor
	elem {new T[length]},      // the new operator can throw an exception
	_size{ length }
	{}
auto size() const noexcept { return _size;} 



T& operator [](const std::size_t i) noexcept{     // for changing value I need ref. or pointrs-->i can not use this function if I deal with const stuff
	 return elem[i];
 }   

 const T& operator [](const std::size_t i) const noexcept{       // only reading 
	 return elem[i];
 }
 
 void push_back(const T& e);
 void push_back(T&& e);  
 
 /*
 if I have a vector<vector<double>> v;
 vector<double> v0 {10};
 v.push_back(v0);
 vv.push_back(vector<double>{77})// it calls the second one,but I don't know why.
 
 
 */
 
};


template<class T>
void Vector<T>::check_and_alloc(){
	    if (_free_slots==0){
		auto tmp = new T[size()*2];
		_free_slots=size(); 
		for(auto i=0llu; i< size();++i)
			tmp[i]= std::move ((*this)[i]); //do I need to copy?
		elem.reset(tmp); 
	}
}
template <class T>
void Vector<T>::push_back(const T& e){
	check_and_alloc();
(*this)[size()]=e;  //copy semantic
_size++;
_free_slots--;
}

template<class T>
void Vector<T>::push_back(T&& e){
	check_and_alloc();
	(*this)[size()]=std::move(e);  //copy semantic
	_size++;
	_free_slots--;
}

  // end of class definition
template<class T>		
auto& operator<<(std::ostream &os, const Vector<T>& v){
	for (auto i=0llu; i<v.size();++i)
		os <<v[i]<< " ";
	os << std::endl;
	return os;
}


int main(){
	Vector<int> v{4};
	
		auto i = v.size();
		while(--i)
			v[i]=i;
	
	std::cout << v;
	v.push_back(7);
	std::cout << v;
	
	
	return 0;
	
}
