//
//  main.cpp
//  CoinCollecting
//
//  Created by Kyla Wilson on 10/14/20.
//
#include <iostream>
#include <vector>

using namespace std;

const int ROW_COUNT = 7, COL_COUNT = 7;

typedef vector<int> Row; // One row of the matrix
typedef vector<Row> Matrix; // Matrix: a vector of rows


const int RobotCoinCollection(Matrix& c) {
    Matrix f(ROW_COUNT,Row(COL_COUNT));
    
    for(int j = 0; j < COL_COUNT; j++)
        f[0][j]= 0;

    for (int i = 0; i < ROW_COUNT; i++)
        f[i][0] = 0;
    
    for(int i = 1; i < ROW_COUNT; i++) {
        for(int j = 1; j < COL_COUNT; j++) {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]) + c[i][j];
        }
    }
    
    return f[ROW_COUNT-1][COL_COUNT-1];
}



int main(int argc, const char * argv[]) {
    Matrix matrix {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 0}
    };

    const int sum =  RobotCoinCollection(matrix);
    std::cout << "Sum: " << sum << std::endl;
    system("pause");
    return 0;

}

//#include <iostream>
//#include <vector>
//
//const int ROW_COUNT = 6, COL_COUNT = 6;
//
//typedef std::vector<std::vector<int>> Matrix;
//
//const int RobotCoinCollection(Matrix& c) {
//    Matrix f;
//    f[1][1] = c[1][1];
//
//    for(int j = 2; j < COL_COUNT; j++)
//        f[1][j]= (f[1][j-1] + c[1][j]);
//
//    for(int i = 2; i < ROW_COUNT; i++) {
//        f[i][1] = f[i - 1][1] + c[i][1];
//        for(int j = 2; j < COL_COUNT; j++) {
//            f[i][j] = std::max(f[i - 1][j], f[i][j - 1] + c[i][j]);
//        }
//    }
//
//    return f[ROW_COUNT - 1][COL_COUNT - 1];
//}
//
//int main(int argc, const char * argv[]) {
//    Matrix matrix {
//        {0, 0, 1, 0, 1, 0},
//        {0, 1, 0, 0, 1, 0},
//        {1, 0, 0, 1, 0, 1},
//        {0, 0, 1, 0, 1, 0},
//        {0, 1, 0, 0, 0, 1},
//        {1, 0, 1, 0, 0, 0}
//    };
//
//    std::cout << "Sum: " << RobotCoinCollection(matrix) << std::endl;
//
//    return 0;
//}
//




