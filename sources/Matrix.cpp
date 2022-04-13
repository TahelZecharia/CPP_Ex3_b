#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector> 
#include <string>
using namespace std;

#include "Matrix.hpp"
namespace zich{

// the constructor of the matrix
Matrix::Matrix(vector<double> mat, int m, int n){

    if (m < 0 || n < 0) {

            throw invalid_argument("Incorrect matrix initialization: negative input");
    }

    if (m * n != mat.size()) {

            throw std::invalid_argument("Incorrect matrix initialization: incorrect dimensions");
    }

    vector<double> matrix;
    int size = m*n;
        
    for(unsigned long i = 0; i<size; i++){

        matrix.push_back(mat.at(i));
    }

    this->_mat = matrix;
    this->_m = m;
    this->_n = n;
}

Matrix Matrix:: operator + (Matrix const &other) const{
    
    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) + other._mat.at(i) );
    }

    Matrix new_mat{mat, m, n};
    return new_mat;
    
}

Matrix& Matrix:: operator += (Matrix const &other){

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) += other._mat.at(i);
    }

    return *this;
   
}

Matrix Matrix:: operator + (){
 
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) );
    }

    Matrix new_mat{mat, m, n};
    
    return new_mat;
}
        
Matrix Matrix:: operator - (Matrix const &other) const{

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) - other._mat.at(i) );

    }

    Matrix new_mat{mat, m, n};
    return new_mat;

}

Matrix& Matrix:: operator -= (Matrix const &other){

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) -= other._mat.at(i);
    }

    return *this;
}
        
Matrix Matrix:: operator - (){

    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( - this->_mat.at(i) );
    }

    Matrix new_mat{mat, m, n};
    
    return new_mat; 

}

bool Matrix:: operator > (Matrix const &other) const{

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    bool ans = true;

    int mat_size = 0;
    int other_size = 0;

    for ( unsigned long i = 0; i < size; i++){

        mat_size += this->_mat.at(i);
        other_size += other._mat.at(i);

    }

    ans = mat_size > other_size;

    return ans;
}  // big
    
bool Matrix:: operator >= (Matrix const &other) const{

    return (*this > other || *this == other);
} // big-or-equal
        
bool Matrix:: operator < (Matrix const &other) const{

        if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    bool ans = true;

    int mat_size = 0;
    int other_size = 0;

    for ( unsigned long i = 0; i < size; i++){

        mat_size += this->_mat.at(i);
        other_size += other._mat.at(i);

    }

    ans = mat_size < other_size;

    return ans;
}  // small
        
bool Matrix:: operator <= (Matrix const &other) const{

    return (*this < other || *this == other);
} // small-or-equal
        
bool operator == (Matrix const &mat, Matrix const &other){  // equal

    if (mat._m != other._m || mat._n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    int m = mat._m;
    int n = mat._n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        if ( mat._mat.at(i) != other._mat.at(i) ){

            return false;
        }
    }

    return true;
} 

bool Matrix:: operator != (Matrix const &other) const{ // not-equal

    if (this->_m != other._m || this->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        if ( this->_mat.at(i) != other._mat.at(i) ){

            return true;
        }
    }

    return false;
} 
// Increase by 1 (++) and decrease by 1 (--) before and after the number:

Matrix Matrix:: operator ++ (){
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) += 1;
    }
    
    return *this;
} // +prefix

Matrix Matrix:: operator ++ (int){

    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) );
        this->_mat.at(i) += 1; 
    }

    Matrix new_mat{mat, m, n};
    
    return new_mat;
} // postfix++

Matrix Matrix:: operator -- (){

    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) -= 1;
    }
    
    return *this;
} // --prefix

Matrix Matrix:: operator -- (int){

    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) );
        this->_mat.at(i) -= 1;
    }

    Matrix new_mat{mat, m, n};
    
    return new_mat;
} // postfix--

// Real scalar multiplication:

Matrix operator * (double scalar, const Matrix& mat){
    
    int m = mat._m;
    int n = mat._n;
    int size = m * n;
    vector<double> matrix;

    for ( unsigned long i = 0; i < size; i++){

        matrix.push_back( mat._mat.at(i) * scalar );

    }

    Matrix new_mat{matrix, m, n};
    return new_mat;

}

Matrix Matrix:: operator * (double scalar){

    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) * scalar );
    }

    Matrix new_mat{mat, m, n};
    return new_mat;

}

Matrix& Matrix:: operator *= (double scalar){
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) *= scalar;
    }

    return *this;
} 

// Multiplying a matrix by a matrix:

Matrix Matrix:: operator * (Matrix const &other) const{

    if (this->_n != other._m) {

        throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    unsigned long m = (unsigned long) this->_m;
    unsigned long n = (unsigned long) this->_n;
    unsigned long w = (unsigned long) other._n;
    double num  = 0;
    unsigned long index1 = 0;
    unsigned long index2 = 0;
    vector<double> matrix;

    for ( unsigned long i = 0; i < m; i++){

        for(unsigned long j = 0; j < w; j++){
        
             num = 0;

            for(unsigned long k = 0; k < n; k++){
                
                index1 = (unsigned long) i*n + k;
                index2 = (unsigned long) k*w + j;
                num += this->_mat.at(index1) * other._mat.at(index2);
                
            }
            matrix.push_back(num);
        }
    }

    Matrix new_mat{matrix, this->_m, other._n};
    return new_mat;
}

Matrix& Matrix:: operator *= (const Matrix& other){

    if (this->_n != other._m) {

        throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    unsigned long m = (unsigned long) this->_m;
    unsigned long n = (unsigned long) this->_n;
    unsigned long w = (unsigned long) other._n;
    double num  = 0;
    double num1  = 0;
    double num2  = 0;
    unsigned long index1 = 0;
    unsigned long index2 = 0;
    vector<double> matrix;

    for ( unsigned long i = 0; i < m; i++){

        for(unsigned long j = 0; j < w; j++){
        
            num = 0;

            for(unsigned long k = 0; k < n; k++){
                
                index1 = (unsigned long) i*n + k;
                index2 = (unsigned long) k*w + j;
                num += this->_mat.at(index1) * other._mat.at(index2);
                
            }
            matrix.push_back(num);
        }
    }

    this->_mat = matrix;
    this->_n = other._n;

    return *this;
} 

ostream& operator<<(ostream& out, const Matrix& mat) {

    int m = mat._m;
    int n = mat._n;     
    unsigned long index = 0;

    for (int i = 0; i < m; i++) {
            
        out <<  '[' ;
            
        for (int j = 0; j < n; j++) {
                
            out <<  mat._mat.at(index);

            if ( j != n-1 ){

                out << ' ';
            } 
                
            index++;
        }
        
        out << ']';
            
        if ( i != m-1 ){
                
                out << '\n';
        }
    }
    
    return out;
}

istream& operator >> (std::istream& in,  Matrix& mat){

    string input;
    getline(in, input);

    int size = input.size();
    int open_num = 0;
    int close_num = 0;
    int psik_num = 1;
    int m = 0;
    int n = 0;

    vector<double> matrix;
        
    for (unsigned int i = 0; i < size; i++){

        if (input[i] == '['){

            n = 0;    
            open_num++;
                
            if (i + 1 < size && isdigit(input.at(i + 1)) == 0){

                throw invalid_argument("bad input");
            }
        }

        if (input[i] == ']'){
                
            close_num++;

            if ( (i + 1 < size && input[i + 1] != ',' ) || ( isdigit(input[i - 1]) ) == 0){
                    
                throw invalid_argument("bad input");
            }
        }
        
        if (input[i] == ','){
            
            psik_num++;
                
            if (i + 1 < size && input[i + 1] != ' ') {
                    
                    throw invalid_argument("bad input");
                }
        }

        if (isdigit(input[i]) != 0){

            n++;
            matrix.push_back(input[i]);

        }
    }

    if (open_num != close_num || open_num != psik_num){

            throw invalid_argument("bad input");
    }

    m = psik_num;

    Matrix new_mat{matrix, m, n};
    
    return in; 
} //cin

}
