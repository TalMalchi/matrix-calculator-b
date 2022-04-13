
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "Matrix.hpp"
using namespace zich;


     
        ostream& zich::operator<<(ostream &a, const zich::Matrix &b){    
            for (size_t i = 0; i < b.row; i++){  
                a << "[";
                for (size_t j = 0; j < b.col; j++){
                    if (j==b.col-1){
                        a<<b.matrix[i][j];
                    }
                   
                    else{a << b.matrix[i][j] << " ";
                    }
                }
            if (i==b.row-1){
                a<<"]";
                    }
                   
            else{ a <<"]\n";
                    }
                }    

            return a;

        }
        istream& zich::operator>>(istream &a, zich::Matrix &b){
            string ans;   
            int col_num=0;
            int col_max=0;
            int row_num=0;
            unsigned int min_index=1;
            unsigned int max_index=0;
            vector<double> temp;
            getline(a,ans);
            //cout << ans << endl;
            if (ans[0]!='[' || ans[ans.size()-1]!=']'){
                cout << ans << endl;
                throw invalid_argument("WORNG INPUT - not the right format");
            }
                for (size_t i = 0; i < ans.size(); i++)
                {
                    if(ans[i] == ']' && (ans[i+1] ==',' && ans[i+2]=='[' )){
                        throw invalid_argument("WORNG INPUT - Bad input");

                    }
                    
                    if((ans[i] == ' ' && ans[i+1] !='[') ||  ans[i]==']' ){
                        col_num ++;
                        max_index= i-1;
                        temp.push_back(stod(ans.substr(min_index,max_index)));
                        if(ans[i]==']'){
                        min_index= i+4; 
                        }
                    }

                    if(col_num>0 && ans[i]==']'){
                        if(col_max==0){
                            col_max=col_num;
                        }
                        if(col_num!=col_max){
                            cout << ans << endl;
                            throw invalid_argument("WRONG INPUT -  Col numbers isn't equal");
                        }
                        
                        row_num++;
                        col_num=0;
                        
                    }
                }
                // for (size_t i = 0; i < temp.size(); i++)
                // {
                //     cout << temp[i] ;
                // }
                
                
                //cout << endl <<row_num << " "<< col_max << " " << temp.size()<<endl;
                b = Matrix(temp,row_num,col_max);
               return a; 
            }
        


    /*---------------------------MATH OPERATORS--------------------------*/
         
        
        Matrix& zich::Matrix::operator+=(const zich::Matrix &a){
            if(a.row != row || a.col != col){
                throw invalid_argument("Matrix size isn't equal");
            }
            
            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < col; j++){
                    matrix[i][j] += a.matrix[i][j];
                }
            }
            return *this;
            
            
        }
         Matrix zich::operator+(const zich::Matrix &a){
            return 1*a; 

        }
         Matrix zich::Matrix::operator+(const zich::Matrix &b){
            if(row != b.row || col != b.col){
                throw invalid_argument("Matrix size isn't equal");
            }
            
            Matrix new_mat(row, col);
            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < col; j++){
                    new_mat.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
                }
            }
            return new_mat;
            
            
           
        }

        Matrix zich::operator-(const zich::Matrix &a, const zich::Matrix &b){
            if(a.row != b.row || a.col != b.col){
                throw invalid_argument("Matrix size isn't equal");
            }
            
            
                Matrix new_mat(a.row, a.col);
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    new_mat.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
                }
            }
            return new_mat;
            
        }
        Matrix& zich::Matrix::operator-=(const zich::Matrix &a){
            if(a.row != this->row || a.col != this->col){
                throw invalid_argument("Matrix size isn't equal");
            }
            
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    matrix[i][j] = matrix[i][j] - a.matrix[i][j];
                }
            }
            return *this;

        }
        Matrix zich::operator-(const zich::Matrix &a){
            return -1*a; 

        }

        /*---------------------------EQUALS--------------------------*/

        bool zich::operator==(const zich::Matrix &a,const zich::Matrix &b){
            if (a.row != b.row || a.col != b.col){
                throw invalid_argument("Matrix size isn't equal");
            }
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    if (a.matrix[i][j] != b.matrix[i][j]){
                        return false;
                    }
                }
            }

            return true; 
        }

        bool zich::operator!=(const zich::Matrix &a,const zich::Matrix &b){
            return !(a == b);
            
        }

        bool zich::operator<=(const zich::Matrix &a,const zich::Matrix &b){
            return (!(a >b));
              
            }

        bool zich::operator<(const zich::Matrix &a,const zich::Matrix &b){
            if (a.row != b.row || a.col != b.col){
                throw invalid_argument("Matrix size isn't equal");
            }
            int sum_a=0;
            int sum_b=0;
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    sum_a += a.matrix[i][j];
                    sum_b += b.matrix[i][j];
                }
                    
            }
            return (sum_a < sum_b);
        }

        bool zich::operator>=(const zich::Matrix &a,const zich::Matrix &b){
            

                return (!(a < b));
            
        }

        bool zich::operator>(const zich::Matrix &a,const zich::Matrix &b){
            if (a.row != b.row || a.col != b.col){
                throw invalid_argument("Matrix size isn't equal");
            }
            int sum_a=0;
            int sum_b=0;
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    sum_a +=a.matrix[i][j];
                    sum_b += b.matrix[i][j];
                }
            }

        
            return sum_a>sum_b ;
    
        
        }
        /*---------------------------MULTIPLICATIONS--------------------------*/
    
        Matrix Matrix::operator*( const zich::Matrix &b){
            if(this->col!=b.row)
            {
                throw invalid_argument("Matrix size isn't equal");
            }
            Matrix new_mat(row, b.col);
            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < b.col; j++){
                    for (size_t k = 0; k < col; k++){
                        new_mat.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
                    }
                }
            }
            return new_mat;

        }
        Matrix zich::operator*(const double b, const zich::Matrix &a){
            Matrix new_mat(a.row, a.col);
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    new_mat.matrix[i][j] = b * a.matrix[i][j] ;
                }
            }
            return new_mat;
        }
       
       Matrix zich::operator*( const zich::Matrix &a,const double b){
            Matrix new_mat(a.row, a.col);
            for (size_t i = 0; i < a.row; i++){
                for (size_t j = 0; j < a.col; j++){
                    new_mat.matrix[i][j] =  a.matrix[i][j] *b;
                }
            }
            return new_mat;
        }
        Matrix& Matrix::operator*=(int b){

            for (size_t i = 0; i < this->row; i++){
                for (size_t j = 0; j < this->col; j++){
                    matrix[i][j] *= b;
                }
            }   
            return *this;
            }

            Matrix& Matrix::operator*=(const zich::Matrix &a){

                if(this->col!=a.row)
            {
                throw invalid_argument("Matrix size isn't equal");
            }
            
                Matrix temp =(*this)*a;
                this->matrix=temp.matrix;
                this->row= temp.row;
                this->col= temp.col;
                
  
              return *this;
            
            }
                        
            
               

/*---------------------------increcment decrecment--------------------------*/

        //prefix- the value increase and then returns
        Matrix& Matrix::operator++(){
            if (row<=0 || col<=0){
                throw invalid_argument("Matrix size isn't equal");
            }
            
            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < col; j++){
                    this->matrix[i][j]++;
                }
            }
            return *this;

           
        }

        //postfix -the value return and then increase 
        Matrix Matrix::operator++(int){
            Matrix new_mat(*this);
            for (size_t i = 0; i < this->row; i++){
                for (size_t j = 0; j < this->col; j++){
                    matrix[i][j]++;;
                }
            }
            return new_mat;     
        }
        
        Matrix Matrix::operator--(int){
            Matrix new_mat(*this);
            for (size_t i = 0; i < this->row; i++){
                for (size_t j = 0; j < this->col; j++){
                    matrix[i][j]--;
                }
            }
            return new_mat;
     
           
        }

        Matrix& Matrix::operator--(){
            if (row<=0 || col<=0){
                throw invalid_argument("Matrix size isn't equal");
            }
            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < col; j++){
                    this->matrix[i][j]--;
                }
            }
            return *this;
            
        }

