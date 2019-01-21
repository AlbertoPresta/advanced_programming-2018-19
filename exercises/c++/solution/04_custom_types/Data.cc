/*
SPIEGAZIONE DELL'ESERCIZIO: questa classe vuole rappresentare la data (giorno, mese e anno); i mesi sono contenuti in una enum 
class di modo da non avere sorprese.
Oltre ai contruttori canonici, Ho scritto una funzione (pubblica) chiamata "set_month" la quale serve per settare il mese durante il 
runtime (quindi utilizzando la tastiera)
Ho introdotto anche le eccezioni (tramite struct invalid_day) che permettono di non avere date senza senso
PROBLEMA 1: ho dovuto introdurre le eccezioni due volte;la prima nel cotruttore  (nel caso il mese venga definito direttamente nel codice)
La seconda nel metodo set_month nel caso si usasse quest'ultimo per impostare il mese.
PROBLEMA 2: Non conosco un modo per accedere agli elementi di enum, quindi ho dovuto scrivere una funzione print_month per l'operatore cout
*/



#include <iostream>
#include <string>

enum class Month_enum {Gennaio = 1, Febbraio, Marzo, Aprile, Maggio, Giugno, Luglio, Agosto, Settembre, Ottobre, Novembre, Dicembre};


//I define an operator of the class Month_enum which augmented one month
Month_enum operator++(Month_enum& m){
	m =(m==Month_enum::Dicembre)? Month_enum::Gennaio : Month_enum(int(m) + 1);   // arithmetic syntax
	return m;
}
//define the struct related to the exception of the day
struct invalid_day {
	std::string message;
	invalid_day(const std::string& s) : message{s} {}
};
	
	
	
	
class Date {
	unsigned int day;
	Month_enum month ;
	unsigned int year;
	
public:
	Date(); //Default contructor
	Date(  unsigned int day,  Month_enum month, unsigned  int year);
	unsigned int Day() const;
	Month_enum Month()  const;
	unsigned int Year() const;
	void add_days( const unsigned int n) ;
	void set_month(unsigned int n);
	std::string print_month() const;
	
private:
	unsigned int Month_side()const ;
	void Add_one_day() ;
	void Add_one_month();
	bool is_leap() const;
~Date();
};
Date::Date(){}

Date::Date( unsigned int day,  Month_enum month, unsigned  int year)
	: day{day},
    month{month},
    year{year}
	{
	if (this->day>31 )
		 throw invalid_day{"A day can't be grater than 31"};
	 if (this->day>30 ){
		  switch(this->month){
	           case Month_enum:: Novembre : case	Month_enum:: Aprile : case Month_enum::Giugno : case Month_enum::Settembre: case Month_enum::Febbraio:
			       throw invalid_day{"November, june, April and September have got only 30 days"};
			   default:
				   break; 
		}
	}
	if (this->day==29 && Date::is_leap()==false ){
		switch(this->month){
			case Month_enum:: Febbraio:
			    throw invalid_day{"February has got only 28 days"};
				default:
				break;
		}
	  }
	  if(this->day==30 && Date::is_leap()==true){
  		switch(this->month){
  			case Month_enum:: Febbraio:
  			    throw invalid_day{"Even if we are in a lap year, we have only 29 days in February"};
  				default:
  				break;
	  }
}
}
unsigned int Date::Day() const{   // implementation of the constructor Day()
	return this->day;
}	

Month_enum Date::Month() const{ // implementation of the constructor Month()
	return this->month;
}

unsigned int Date::Year() const{ // implementation  of the constructor Year()
	return this->year;
}
unsigned int Date::Month_side() const { // implementation of the method Mont_side()
	switch(this->month){
		
		case Month_enum:: Gennaio : case Month_enum:: Marzo : case Month_enum:: Maggio : case Month_enum:: Luglio : case Month_enum:: Agosto :  case Month_enum:: Ottobre :  case Month_enum:: Dicembre:
		     return 31;
		     break;
		case Month_enum:: Febbraio: 
		     if(Date::is_leap()){
				 return 29;
				 break;
			     }
			else{
				 return 28;
			     break;
			     }
		case Month_enum:: Novembre : case	Month_enum:: Aprile : case Month_enum::Giugno : case Month_enum::Settembre:
		    return 30;
			break;
        default:
            return 0;
            break;
	}
   
}
// too long program, but It should works
void Date::Add_one_day() {
	if (Date::Month_side()==29 && Date::Day()==29){   //caso dedicato all'anno bisestile
		this->day = 0;
		Date::Add_one_month();
	}
	if (Date::Month_side()==28 && Date::Day()==28){
		this->day = 0;
		Date::Add_one_month();
	}
	if (Date::Month_side()==31 && Date::Day()==31){
		this->day = 0;
		switch(this->month){
	 	 	case Month_enum:: Dicembre:
			     Date::Add_one_month();
	 	 		 //this->month = Month_enum:: Gennaio;
				 this->year += 1; 
	 	 		 break;
			default:
			     Date::Add_one_month();
				 break;
			 }
		 }
	if (Date::Month_side()==30 && Date::Day()==30){
		this->day=0;
		Date::Add_one_month();
	       }
		this->day+=1;
      }

void Date::add_days(unsigned int n){
    unsigned int i = 0;
	while(i<n){
		Date::Add_one_day();
		i= i +1;
     }
}
// this is a "set function": I can decide the month in input
void Date::set_month( unsigned int n){
	switch(n){
		case 1 :
	         this->month = Month_enum:: Gennaio;
			 
				 break;
	    case 2 :
	 	     this->month = Month_enum:: Febbraio;
			   if (this->day>28 && Date::is_leap()==false)
				   throw invalid_day{"we are not in a lap year, so February ha got only 28 days"};
			   if (this->day>29 && Date::is_leap())
				   throw invalid_day{"Even if we are  in a lap year,  February ha got only 29 days"};
			   break;
		case 3 :
		 	this->month = Month_enum:: Marzo;
		 	break;
		case 4 :
			this->month = Month_enum:: Aprile;
			if(this->day>30)
				throw invalid_day{"April has got only 30 days"};
			break;
		case 5 :
			this->month = Month_enum:: Maggio;
			break;
		case 6:
			this->month = Month_enum:: Giugno;
			if(this->day>30)
				throw invalid_day{"June has got only 30 days"};
			break;
		case 7 :
			this->month = Month_enum:: Luglio;
			break;
		case 8 :
			this->month = Month_enum:: Agosto;
			break;
		case 9 :
			this->month = Month_enum:: Settembre;
			if(this->day>30)
				throw invalid_day{"September has got only 30 days"};
			break;
		case 10:
			this->month = Month_enum:: Ottobre;
			break;
		case 11 :
			this->month = Month_enum:: Novembre;
			if(this->day>30)
				throw invalid_day{"November has got only 30 days"};
			break;
		case 12 :
		    this->month = Month_enum:: Dicembre;
		    break;
		default:
		    throw invalid_day{"Not accepted month"};
		    break;
     }
   }
// Implementation of the function which prints the month
std::string Date::print_month() const{
	 switch(this->month){
		case Month_enum::Gennaio:
		          return "Gennaio";
		          break;
	 	case Month_enum::Febbraio:
		          return "Febbraio";
		          break;
		case Month_enum::Marzo:
		          return "Marzo";
		          break;
		case Month_enum::Aprile:
		          return "Aprile";
			 	  break;
		case Month_enum::Maggio:
		          return "Maggio";
				  break;
		case Month_enum::Giugno:
		          return "Giugno";
				  break;
		case Month_enum::Luglio:
		          return "Luglio";
				  break;				 
		case Month_enum::Agosto:
		          return "Agosto";
				  break;
	    case Month_enum::Settembre:
		          return "Settembre";
				  break;
		case Month_enum::Ottobre:
		          return "Ottobre";
				  break;
		case Month_enum::Novembre:
		          return "Novembre";
		  		  break;
		case Month_enum::Dicembre:
		          return "Dicembre";
			 	  break;
         default:
             return 0;
             break;
			  }
		  }	

void Date::Add_one_month(){
	++this->month;
}

bool Date::is_leap() const{
	if (this->year%4==0 && this->year%400!=0)
		return true;
	return false;
}   

Date::~Date(){} // destructor
// I want to write a boolean  operator which is used to verify if two dates are equal
bool operator==(const Date& data1, const Date& data2){
	if (data1.Day()== data2.Day() && data1.Month()== data2.Month() && data1.Year()== data2.Year())
	    return true;
	else
		return false;
}
// boolean operator which control if two dates are different
bool operator!=(const Date& data1, const Date& data2){
	if(!(data1==data2))
		return true;
	else
		return false;
}
std::ostream& operator<<(std::ostream& os , const Date& data){
    return os << "giorno: " << data.Day() << std::endl<< "Mese: "<< data.print_month() <<std::endl<<   "anno: " << data.Year()<<std::endl; 
   
 
   
}
int main(){
 try{
	std::cout<<" Insert a day"<<std::endl;
	int n ;
	std::cin>> n ;
	std::cout<<" Insert an year "<<std::endl;
	int m ;
	std::cin>> m;
	Month_enum mesi;
	
	std::cout<<"insert a month, where 1 stands for January, 2 for February and so on"<<std::endl;
	int k ;
	std::cin>>k;
	
     Date* data = new Date(n,mesi,m);
	data->set_month(k);
	std::cout<<*data<<std::endl;
	
	if (m%4==0 && m%400!=0){
		std::cout<<"You have chosen a leap year, so there will be 29 days in February." <<std::endl;
	}
	std::cout<<"Insert the number of the days you want to add!\n";
	int add;
	std::cin>>add;
	data->add_days(add);
     std::cout<<"you have skipped to the following day:\n";
     std::cout<<*data<<std::endl;
	return 0;
 }
 catch(const invalid_day& d){
 	std::cerr << d.message << std::endl;
 }
 catch(...){
 	std::cerr << "Unknown exception. Aborting.\n";
	return 3;
 }
 
 
 
 
 
 
 
 
 
 
 
}
