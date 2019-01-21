
#include <iostream>
void trasp_not_square(double*p,int n, int m);
void fill(double*p, int row,int col);
double* transpose(double*matrix,int row, int col);
void print(double*matrix,int row, int col);

double* opt(double* matrix, int n, int m);

int main() {
    std::cout<<"insert the number of rows of your matrix"<<std::endl;
    int n;
    std::cin>>n;
    std::cout<<"insert the number of columns of your matrix"<<std::endl;
    int m;
    std::cin>>m;
    double* matrix= new double[n*m]{};
    std::cout<<"Insert the values of the array!"<<std::endl;
    fill(matrix,n,m);
    std::cout<<"the matrix is the following one!"<<std::endl;
    print(matrix,n,m);
    
    if (n==m){
        std::cout<< "Siccome la matrice è quadrata, utilizzo un algoritmo ottimizzato per il calcolo della matrice trasposta"<<std::endl;
         double* trasposta = transpose(matrix,n,m);
        std::cout<<"its transpose is the following!"<<std::endl;
        print(trasposta,m,n);
    }
    else{
    //double* trasposta = transpose(matrix,n,m)
    double* trasposta = transpose(matrix,n,m);
    std::cout<<"its transpose is the following!"<<std::endl;
    print(trasposta,m,n);
    
}
    return 0;
}

// void funtion which print a matrix
void print(double* p, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
            std::cout << p[i * col + j] << " ";
        std::cout << std::endl;
    }
}



// void funtion which initializes the matrix with double value
void fill(double* p , int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j){
            std::cin>> p[i * col + j];
            }
       }
}




// function which calculate the transpose of the matrix
//void transpose(double* matrix, int n , int m){}

 double*  transpose(double* matrix, int n, int m){
    double* b = new double[n*m]{};
     int cont=0;
     for(int j{0}; j<n;j++) {
         for(int i{0};i<m;i++) {
            b[i*n+j]=matrix[cont];
             cont+=1;
                }
             }
     return b;
    }

//metodo che calcolca la matrice trasposta di una matrice quadrata  in modo ottimale, dividendola in blocchi
double* opt(double* matrix, int n, int blocksize){
    double* AT = new double[n*n]{};
    for (int i = 0 ; i < n/blocksize; i++ ) {
        int blocco_i=blocksize*i ; //inizio del blocco viaggiando verticalmente
        int blocco_if= blocco_i + blocksize; // fine del blocco viaggiando verticalmente
        for (int j=0 ; j <n/blocksize ; j++ ) {
            int blocco_j=blocksize*j; //inizio del blocco viaggiando
            int blocco_jf=blocco_j + blocksize; // fine del blocco
            for(int k=blocco_i;k<blocco_if;k++){
                int viaggiatore=n*k;//viaggiator lungo i blocchi
                for(int h=blocco_j;h<blocco_jf;h++){
                AT[( viaggiatore+h)]=matrix[(n*h+k) ]; }
        }
    }
}

    return AT;
}
