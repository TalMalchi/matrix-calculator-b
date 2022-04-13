#include <iostream>
#include <vector>
using namespace std;




namespace zich
{
    class Matrix
    {
    private:
        int col;
        int row;
        vector<vector<double>> matrix;

    public:
        
        Matrix(){};
        
        //constructor 
        Matrix(vector<double> arr, int rows, int cols)
        { 
            if(rows<=0 || cols<=0 || rows*cols != arr.size()){
                throw invalid_argument("Matrix size can't be Negative");
            }    
            matrix.resize((size_t)rows);
            row=(size_t)rows;
            col=(size_t)cols;
            for (size_t i = 0; i < row; i++){
                vector<double> v((size_t)col);
                for (size_t j = 0; j < col; j++){
                    v[j]=arr[i * (size_t)col + j];  
                }
                matrix[i]=v;
            }
        }

        //constructor gets just row and col and initializes matrix by 0
        Matrix (int rows,  int cols){
            if(rows<=0 || cols<=0){
                throw invalid_argument("Matrix size is can't be Negative");
            } 
            row=(size_t)rows;
            col=(size_t)cols;
            matrix.resize((size_t)row);
            for (size_t i = 0; i < row; i++){
                vector<double> v((size_t)col);
                for (size_t j = 0; j < col; j++){
                    v[j]=0;
                }
                matrix[i]=v;
            }
        }

        //copy constructor
        Matrix(const Matrix &m){
            col = m.col;
            row = m.row;
            matrix = m.matrix;
              
        }
        
        
        
            

        friend ostream &operator<<(ostream &a, const Matrix &b);
        friend istream &operator>>(istream &a, Matrix &b);

        // 6 math operators
        Matrix &operator+=(const Matrix &a);
        Matrix operator+(const Matrix &b);
        friend Matrix operator+(const Matrix &a);
        friend Matrix operator-(const Matrix &a, const Matrix &b);
        Matrix &operator-=(const Matrix &a);
        friend Matrix operator-(const Matrix &a);

        // 6 compartion operatorsS
        friend bool operator==(const Matrix &a,const Matrix &b);
        friend bool operator!=(const Matrix &a,const Matrix &b);
        friend bool operator<=(const Matrix &a,const Matrix &b);
        friend bool operator<(const Matrix &a,const Matrix &b);
        friend bool operator>=(const Matrix &a,const Matrix &b);
        friend bool operator>(const Matrix &a,const Matrix &b);

        // multiplications
        Matrix operator*(const Matrix &b);
        friend Matrix operator*(const double b, const Matrix &a);
        friend Matrix operator*(const Matrix &a,const double b);
        Matrix &operator*=(int b);
        Matrix &operator*=(const Matrix &a);


        // increcment decrecment
        Matrix operator++(int); //postfix i++
        Matrix &operator++();  //prefix ++i
        Matrix operator--(int); //postfix  i--
        Matrix &operator--(); //prefix --i


        
    };

    

}
