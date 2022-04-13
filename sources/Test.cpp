// #include "doctest.h"
// #include "Matrix.hpp"
// using namespace zich;

// #include <string>
// #include <algorithm>
// #include <stdexcept>
// #include <vector> 
// using namespace std;


// TEST_CASE("Constructor"){

//     SUBCASE("Bad Input"){

//         vector<double> small_mat = {1,2,3,4,5,6,7,8,9};
//         vector<double> large_mat(10000, 0.3); 

//         // check that exception is thrown if the dimensions of the matrix are incorrect.
//         CHECK_THROWS(Matrix m1(small_mat,2,2));   // smaller dimensions
//         CHECK_THROWS(Matrix m2(small_mat,3,4));   // larger dimensions 

//         CHECK_THROWS(Matrix m3(large_mat,50,66));   // smaller dimensions
//         CHECK_THROWS(Matrix m4(large_mat,301,402)); // larger dimensions 
        
//         // check that exception is thrown if the input of the row or colsum is a negative num.
//         CHECK_THROWS(Matrix m5(small_mat,-3,3));  // negative input
//         CHECK_THROWS(Matrix m6(small_mat,3,-3));  // negative input
//         CHECK_THROWS(Matrix m7(small_mat,-3,-3)); // negative input

//         CHECK_THROWS(Matrix m8(large_mat,100,-100));    // negative input
//         CHECK_THROWS(Matrix m9(large_mat,-100,100));    // negative input
//         CHECK_THROWS(Matrix m10(large_mat,-100,-100));  // negative input
//     }

//     SUBCASE("Good Input"){

//         vector<double> small_mat = {1,2,3,4,5,6,7,8,9}; // small mat
//         CHECK_NOTHROW(Matrix m1(small_mat,3,3));
    
//         vector<double> large_mat(10000, 0.0);          // large mat
//         CHECK_NOTHROW(Matrix m2(large_mat,100,100));

//     }
// }

// TEST_CASE("Operator +"){

//     SUBCASE("Bad Input"){

//         vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9,10};
//         vector<double> small_mat2 = {1,2,3,4,5,6,7,8,9,10};

//         vector<double> large_mat1(10000, 1.8); 
//         vector<double> large_mat2(10000, 3.4); 

//         Matrix mat1{small_mat1,2,5};
//         Matrix mat2{small_mat2,5,2};

//         Matrix mat3(large_mat1,100,100);
//         Matrix mat4(large_mat1,10,1000);

//         // check that exception is thrown if the matrices are not of the same size mXn.
//         CHECK_THROWS(mat1 + mat2);
//         CHECK_THROWS(mat3 + mat4);
//     }

//     SUBCASE("Good Input"){

//         vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9};
//         vector<double> small_mat2 = {9,8,7,6,5,4,3,2,1};
//         vector<double> small_mat3 = {10,10,10,10,10,10,10,10,10};

//         vector<double> large_mat1(10000, 8.23); 
//         vector<double> large_mat2(10000, 3.3);
//         vector<double> large_mat3(10000, 11.53); 

//         Matrix mat1{small_mat1,3,3};
//         Matrix mat2{small_mat2,3,3};
//         Matrix mat3{small_mat3,3,3};

//         Matrix mat4(large_mat1,10,1000);
//         Matrix mat5(large_mat2,10,1000);
//         Matrix mat6(large_mat3,10,1000);

//         CHECK((mat1 + mat2 == mat3));
//         CHECK((mat3 + mat1 != mat2));
        
//         CHECK((mat4 + mat5 == mat6));
//         CHECK((mat5 + mat5 != mat6));
//     }

// }

// TEST_CASE("Operator +="){

//     SUBCASE("Bad Input"){

//         vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9,10};
//         vector<double> small_mat2 = {1,2,3,4,5,6,7,8,9,10};

//         vector<double> large_mat1(10000, 9.3); 
//         vector<double> large_mat2(10000, 1.2); 

//         Matrix mat1{small_mat1,2,5};
//         Matrix mat2{small_mat2,5,2};

//         Matrix mat3(large_mat1,100,100);
//         Matrix mat4(large_mat1,10,1000);

//         // check that exception is thrown if the matrices are not of the same size mXn.
//         CHECK_THROWS(mat1 += mat2);
//         CHECK_THROWS(mat3 += mat4);
//     }

//     SUBCASE("Good Input"){

//         vector<double> m1 = {1,2,3,4,5,6,7,8,9};
//         vector<double> m2 = {9,8,7,6,5,4,3,2,1};
//         vector<double> m3 = {10,10,10,10,10,10,10,10,10};
//         vector<double> m4 = {20,20,20,20,20,20,20,20,20};
//         vector<double> m5 = {-20,-20,-20,-20,-20,-20,-20,-20,-20};
//         vector<double> m6 = {0,0,0,0,0,0,0,0,0};

//         Matrix mat1{m1,3,3};
//         Matrix mat2{m2,3,3};
//         Matrix mat3{m3,3,3};
//         Matrix mat4{m4,3,3};
//         Matrix mat5{m5,3,3};
//         Matrix mat6{m6,3,3};

//         mat1 += mat2;
//         CHECK(mat1 == mat3);
//         mat1 += mat3;
//         CHECK(mat1 == mat4);
//         mat1 += mat6;
//         CHECK(mat1 == mat4);
//         mat1 += mat5;
//         CHECK(mat1 == mat6);
//     }
// }

// TEST_CASE("Operator + (unary)"){

//     vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9};

//     vector<double> large_mat1(10000, 57.2); 
   
//     Matrix mat1{small_mat1,3,3};

//     Matrix mat2(large_mat1,10,1000);
    
//     CHECK(( + mat1 == mat1 ));
//     CHECK(( + mat2 == mat2 ));
// }

// TEST_CASE("Operator -"){

//      SUBCASE("Bad Input"){

//         vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9,10};
//         vector<double> small_mat2 = {1,2,3,4,5,6,7,8,9,10};

//         vector<double> large_mat1(10000, 1.8); 
//         vector<double> large_mat2(10000, 3.4); 

//         Matrix mat1{small_mat1,2,5};
//         Matrix mat2{small_mat2,5,2};

//         Matrix mat3(large_mat1,100,100);
//         Matrix mat4(large_mat1,10,1000);

//         // check that exception is thrown if the matrices are not of the same size mXn.
//         CHECK_THROWS(mat1 + mat2);
//         CHECK_THROWS(mat3 + mat4);
//     }

//     SUBCASE("Good Input"){

//         vector<double> small_mat1 = {10,10,10,10,10,10,10,10,10};
//         vector<double> small_mat2 = {9,8,7,6,5,4,3,2,1};
//         vector<double> small_mat3 = {1,2,3,4,5,6,7,8,9};

//         vector<double> large_mat1(10000, 356.77); 
//         vector<double> large_mat2(10000, 222.3);
//         vector<double> large_mat3(10000, 134.47); 

//         Matrix mat1{small_mat1,3,3};
//         Matrix mat2{small_mat2,3,3};
//         Matrix mat3{small_mat3,3,3};

//         Matrix mat4(large_mat1,10,1000);
//         Matrix mat5(large_mat2,10,1000);
//         Matrix mat6(large_mat3,10,1000);

//         CHECK((mat1 - mat2 == mat3));
//         CHECK((mat3 - (-mat2) == mat1));
        
//         CHECK((mat4 - mat5 == mat6));
        
//     }
// }

// TEST_CASE("Operator -="){

//     SUBCASE("Bad Input"){

//         vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9,10};
//         vector<double> small_mat2 = {1,2,3,4,5,6,7,8,9,10};

//         vector<double> large_mat1(10000, 9.3); 
//         vector<double> large_mat2(10000, 1.2); 

//         Matrix mat1{small_mat1,2,5};
//         Matrix mat2{small_mat2,5,2};

//         Matrix mat3(large_mat1,100,100);
//         Matrix mat4(large_mat1,10,1000);

//         // check that exception is thrown if the matrices are not of the same size mXn.
//         CHECK_THROWS(mat1 += mat2);
//         CHECK_THROWS(mat3 += mat4);
//     }

//     SUBCASE("Good Input"){

//         vector<double> m1 = {9,8,7,6,5,4,3,2,1};
//         vector<double> m2 = {9,8,7,6,5,4,3,2,1};
//         vector<double> m3 = {10,10,10,10,10,10,10,10,10};
//         vector<double> m4 = {20,20,20,20,20,20,20,20,20};
//         vector<double> m5 = {-20,-20,-20,-20,-20,-20,-20,-20,-20};
//         vector<double> m6 = {0,0,0,0,0,0,0,0,0};

//         Matrix mat1{m1,3,3};
//         Matrix mat2{m2,3,3};
//         Matrix mat3{m3,3,3};
//         Matrix mat4{m4,3,3};
//         Matrix mat5{m5,3,3};
//         Matrix mat6{m6,3,3};

//         mat1 -= mat6;
//         CHECK(mat1 == mat2);
//         mat1 -= mat2;
//         CHECK(mat1 == mat6);
//         mat1 -= mat5;
//         CHECK(mat1 == mat4);
//         mat1 -= mat4;
//         CHECK(mat1 == mat6);
//     }
// }

// TEST_CASE("Operator - (unary)"){

//     vector<double> small_mat1 = {1,2,3,4,5,6,7,8,9};
//     vector<double> small_mat2 = {-1,-2,-3,-4,-5,-6,-7,-8,-9};

//     vector<double> large_mat1(30000, 63.99); 
//     vector<double> large_mat2(30000, -63.99);

//     Matrix mat1{small_mat1,3,3};
//     Matrix mat2{small_mat2,3,3};

//     Matrix mat3(large_mat1,300,100);
//     Matrix mat4(large_mat2,300,100);
    
//     CHECK(( - mat1 == mat2));
//     CHECK(( - mat2 == mat1));
//     CHECK(( - mat3 == mat4));
//     CHECK(( - mat4 == mat3));
//     CHECK(( - ( - mat1 ) == mat1));
// }

// // TEST_CASE("Operator >"){

// //     SUBCASE("Bad Input"){

// //     }

// //     SUBCASE("Good Input"){

// //     }
// // }

// // TEST_CASE("Operator >="){

// //     SUBCASE("Bad Input"){

// //     }

// //     SUBCASE("Good Input"){

// //     }
// // }

// // TEST_CASE("Operator <"){

// //     SUBCASE("Bad Input"){

// //     }

// //     SUBCASE("Good Input"){

// //     }
// // }

// // TEST_CASE("Operator <="){

// //     SUBCASE("Bad Input"){

// //     }

// //     SUBCASE("Good Input"){

// //     }
// // }

// TEST_CASE("Operator =="){

//     SUBCASE("Good Input"){

//         vector<double> m1 = {9,8,7,6,5,4,3,2,1};
//         vector<double> m2 = {9,8,7,6,5,4,3,2,1};
//         vector<double> m3 = {9,8,7,6,4.9,4,3,2,1};

//         vector<double> large_mat1(10000, 9.3); 
//         vector<double> large_mat2(10000, 9.33); 

//         Matrix mat1{m1,3,3};
//         Matrix mat2{m2,3,3};
//         Matrix mat3{m3,3,3};

//         Matrix mat4(large_mat1,100,100);
//         Matrix mat5(large_mat1,100,100);

//         CHECK(mat1 == mat2);
//         CHECK_FALSE(mat1 == mat3);

//         CHECK(mat4 == mat4);
//         CHECK_FALSE(mat4 == mat5);
//     }
// }

// //     TEST_CASE("Operator !="){}

//     // TEST_CASE("Operator ++ (prefix)"){

//     //     vector<double> m1 = {10,10,10,10,10,10,10,10,10};
//     //     vector<double> m2 = {11,11,11,11,11,11,11,11,11};

//     //     Matrix mat1{m1,3,3};
//     //     Matrix mat2{m2,3,3};

//     //     ++mat1;
//     //     CHECK(m1 == m2);
//     //     ++mat1;
//     //     CHECK(m1 != m2);
//     //     ++mat2;
//     //     CHECK(m1 == m2);
//     // }

//     // TEST_CASE("Operator ++ (postfix)"){

//     //     vector<double> m1 = {10,10,10,10,10,10,10,10,10};
//     //     vector<double> m2 = {11,11,11,11,11,11,11,11,11};

//     //     Matrix mat1{m1,3,3};
//     //     Matrix mat2{m2,3,3};

//     //     mat1++;
//     //     CHECK(m1 == m2);
//     //     mat1++;
//     //     CHECK(m1 != m2);
//     //     mat2++;
//     //     CHECK(m1 == m2);
//     // }

// //     TEST_CASE("Operator -- (prefix)"){}

// //     TEST_CASE("Operator -- (postfix)"){}

// //     TEST_CASE("Operator * (scalar multiplication)"){}

// //     TEST_CASE("Operator *= (scalar multiplication)"){}

// //     TEST_CASE("Operator * (matrix multiplication)"){}

// //     TEST_CASE("Operator *= (matrix multiplication)"){}


