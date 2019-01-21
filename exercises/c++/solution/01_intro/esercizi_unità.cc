#include<cmath>
#include<string>
#include <iostream>
#include<cstdlib>
#include<fstream>

double inch_to_meters(double p);
double miles_to_meters(double p);

using namespace std;
int main(){
    
	cout<<"scrivi 'inch' se vuoi convertire i pollici in metri oppure 'miles' se vuoi convertire le miglia in metri!"<<endl;
	string answer;
	cin>>answer;
	if(answer == "inch"){
	cout<< "inserisci i pollici" <<endl;
	double p;
	cin>>p;
	double metri = inch_to_meters(p);
	cout<<"I corrispettivi metri sono: "<<endl;
	cout<< metri << endl;
    }
	if(answer == "miles"){
		cout<< "inserisci le miglia"<<endl;
		double p;
		cin>>p;
		double metri = miles_to_meters(p);
		cout<<"I corrispettivi metri sono: "<<endl;
		cout<< metri << endl;
	}
	
	return 0;
}
// program which converts inch or miles to meters.
// in the first part, the program asks to you if you want to converts inch or miles. 
// In the second part there is the conversion to meters
double inch_to_meters(double p){
	double res; 
	res = p/39.370;
	return res;
	   }
double miles_to_meters(double p){
	   	double res; 
	   	res = p/39.370;
	   	return res;
	   	   }

	   
	   


