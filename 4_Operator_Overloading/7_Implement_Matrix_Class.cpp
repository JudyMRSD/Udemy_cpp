#include <iostream>
#include <vector>
using namespace std;



class MyMatrix {
private:
    vector<vector<int>> mat;
public:
    MyMatrix(int num_rows, int num_cols) {
        mat = vector<vector<int>>(num_rows, vector<int>(num_cols, 0));
    }

    //return by reference, so at(row, col) can be used to set value at row, col, and
    //print output at row, col
    int& at(int row_id, int col_id) {
        return mat[row_id][col_id];
    }

    //overload <<
    /*
     * When you use these as stream operators (rather than binary shift) the first parameter
     * is a stream. Since you do not have access to the stream object (its not yours to modify)
     * these can not be member operators they have to be external to the class.
     * Thus they need be friends of the class: A friend function of a class is defined outside that class' scope but
     * it has the right to access all private and protected members of the class.
     */
    friend ostream& operator<<(ostream& os, const MyMatrix& m) {
        for (size_t r = 0; r < m.mat.size(); r++) {
            for (size_t c = 0; c < m.mat[0].size(); c++) {
                os << m.mat[r][c];
            }
            os << endl;
        }
        return os;
    }

    void print() {
        for (size_t r = 0; r < mat.size(); r++) {
            for (size_t c = 0; c < mat[0].size(); c++) {
                cout << to_string(mat[r][c]);
            }
            cout << endl;
        }
    }

    //only works for square matrix
    /*
     * 1 2       1 3
     * 3 4   --> 2 4
     */
    void transpose() {
        for (size_t r = 0; r < mat.size(); r++) {
            for (size_t c = 0; c < mat[0].size(); c++) {
                swap(mat[r][c], mat[c][r]);
            }
        }
    }

};

// To execute C++, please define "int main()"
int main() {
    MyMatrix m(2, 2);
    m.at(0, 0) = 1;
    m.at(0, 1) = 2;
    m.at(1, 0) = 3;
    m.at(1, 1) = 4;
    cout<<m.at(1,1)<<endl;
    cout<<"before transpose"<<endl;
    cout<<m<<endl;
    m.transpose();
    cout<<"after transpose"<<endl;
    m.print();


    return 0;
}

