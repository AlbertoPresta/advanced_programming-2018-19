#include<iostream>

/*
Grazie alla funzione getline si potrà scrivere una stringa iniziale, la quale verrà salvata nella
variabile line.
Dopo di che ci sarà un controllo: se line è uguale a pre_line (inizializzata a stringa vuota " ") allora verrà ignorata la line appena scritta; 
in caso contrario la line appena scritta verrà aggiunta al file text e poi verrà salvata nella variabile per_line (servirà per il controllo successivo)
*/

int main(){
	int contatore = 0;
    std::cout<<" Inizia a scrivere una linea di parole:"<<std::endl;
    std::string line{""};
    std::string pre_line{""};
    std::string text{""};
    while(std::getline(std::cin,line)){
        if (line!=pre_line){
            text+=line;
            pre_line=line;
        }
		else
			contatore = contatore + 1;
		
        std::cout<<text<<std::endl;
		
		
    }
	std::cout<<"Hai ripetuto lo stesso testo esattamente " << contatore << " volte. " << std::endl;
	std::cout<<"il testo finale è il seguente: " << std::endl;
	std::cout<<text<<std::endl;
    return 0;
}
