
#pragma once

#include <iostream>
#include <vector> 

namespace zich
{
    class Matrix
    {
        std::vector<double> _mat; 
        int _m; // represents the rows.
        int _n; // represents the culsumes.

        public:
        // Constructor
        
        // Matrix(std::vector<double> &mat, int m, int n);
        Matrix(std::vector<double> mat, int m, int n);
        
        // Destructor
        // Matrix::~Matrix();

        // Six arithmetic operators:
        Matrix operator + (Matrix const &other) const;
        Matrix& operator += (Matrix const &other);
        Matrix operator + ();
        
        Matrix operator - (Matrix const &other) const;
        Matrix& operator -= (Matrix const &other);
        Matrix operator - ();

        // Six comparison operators:
        bool operator > (Matrix const &other) const;  // big
        bool operator >= (Matrix const &other) const; // big-or-equal
        bool operator < (Matrix const &other) const;  // small
        bool operator <= (Matrix const &other) const; // small-or-equal
        friend bool operator == (Matrix const &mat, Matrix const &other); // equal
        bool operator != (Matrix const &other) const; // not-equal

        // Increase by 1 (++) and decrease by 1 (--) before and after the number:
        Matrix operator ++ (); // +prefix
        Matrix operator ++ (int); // postfix++
        Matrix operator -- (); // --prefix
        Matrix operator -- (int); // postfix--

        // Real scalar multiplication:
        friend Matrix operator * (double scalar, const Matrix& mat);
        Matrix& operator *= (double scalar); 
        Matrix operator * (double scalar);

        // Multiplying a matrix by a matrix:
        Matrix operator * (Matrix const &other) const;
        Matrix& operator *= (const Matrix& other); 

        // Input operator and output operator:
        friend std::ostream& operator << (std::ostream& out, const Matrix& mat); //cout
        friend std::istream & operator >> (std::istream& in,  Matrix& mat); //cin
    };
}