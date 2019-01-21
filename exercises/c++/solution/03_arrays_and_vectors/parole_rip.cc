#include <string>
#include <iostream>
#include<vector>


//Nel main si scrivono parole,salvate nella variabile s; le parole uniche vengono stampate nel main.
bool is_uniq(int k,std::string s,std::vector<std::string>& v);

int main() {
    std::string s{" "};
    std::vector<std::string> parole;
    std::cout<<"inserisci le parole"<<std::endl;
    while(std::cin>>s){
        parole.push_back(s);
        }
    std::cout<< " Le parole che ho ripetuto senza ripetizioni sono: "<<std::endl;
    for(unsigned int i = 0; i<parole.size();i++){
       if(is_uniq(i,parole[i],parole))
          std::cout<<parole[i] + " " ;
        
    }
    std::cout<<" " << std::endl;   
    return 0;
    }
        
// funzione bool che ritorna vero se la parola è unica: il controllo viene fatto all'indietro: la parola viene confrontata con le parole che si trovano nelle posizioni precedenti rispetto ad essa, in questo modo si mantiene l'ordine di scrittura delle parole e non è necessario riordinarle.
// Inoltre in questo modo la prima volta che viene incontrata una parola essa viene salvata (perché visto come unica), mentre le volte successive viene ignorata 
bool is_uniq(int k,std::string s,std::vector<std::string>& v){
    for (int i=k-1; i>=0;i--){
        if(s==v[i]){
            return false;
        }
    }
    return true;
    }

