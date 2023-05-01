// #include "doctest.h"
// #include <stdexcept>
// #include "sources/Fraction.hpp"
// using namespace std;
// using namespace ariel;




// TEST_CASE("The evaluation of good object Fraction") 
// {
//     Fraction f(1,2);
//     CHECK(f.getNumerator()==1);
//     CHECK(f.getDenomirator()==2);
    
//     CHECK_THROWS(Fraction(0,0));
    

// }

// TEST_CASE("IsbiggerSmaller 3 points after . "){

//      Fraction f(617,500), g(1233,1000);
    
//     CHECK(f.operator>=(g));
//     CHECK(f.operator>(g));

//     float number = 1.2345;
//     CHECK(operator<=(f,number));
//     CHECK_FALSE(operator>=(f,number));

// }


// TEST_CASE("Divde by zero! ") 
// {
//     Fraction f(5,2);
//     Fraction g(6,0);
//     CHECK_THROWS(f.operator/(g));
    

//     Fraction f2(5,0);
//     Fraction g2(4,3);
//     CHECK_THROWS(f2.operator/(g2));
//     float number = (float)5/2;

//     Fraction res = operator-(f,number);
//     CHECK_THROWS(g2.operator/(res));

//     Fraction f3(0,1);
//     Fraction g3(0,3);

//     CHECK_THROWS(f3.operator/(g3));

//     Fraction f4(0,1);
//     Fraction g4(5,5);

//     CHECK_NOTHROW(f4.operator/(g4));

//     CHECK_THROWS(g4.operator/(f4));


// }



// TEST_CASE("Sub Fractions"){

//     Fraction f(1,1);
//     Fraction g(1,1);
//     Fraction res2(0,1);

//     Fraction resSub = f.operator-(g);

//     CHECK(resSub==res2);

//     float number = 1/1;
//     Fraction resSubN = operator-(f,number);

//     CHECK(resSubN==resSub);
//     CHECK(resSubN==res2);

// }


// TEST_CASE("Add Fractions"){


//     Fraction f(1,2);
//     Fraction g(1,3);
//     Fraction resAdd = f.operator+(g);
//     CHECK(resAdd==Fraction(5,6));

//     float number = (float)1/3;
//     Fraction resAddN = operator+(f,number);
//     Fraction resAddN2 = operator+(number,f);

//     CHECK(resAddN==resAdd);
//     CHECK(resAddN==resAddN2);
//     CHECK(resAddN2==resAdd);

// }


// TEST_CASE("Mul Fractions"){

//     Fraction f(1,2);
//     Fraction g(1,3);
//     Fraction resAdd = f.operator*(g);
//     CHECK(resAdd==Fraction(1,6));

//     float number = (float)1/3;
//     Fraction resAddN = operator*(f,number);
//     Fraction resAddN2 = operator*(number,f);

//     CHECK(resAddN==resAdd);
//     CHECK(resAddN==resAddN2);
//     CHECK(resAddN2==resAdd);

//     Fraction f2(0,2);
//     Fraction g2(3,5);
//     Fraction resAdd1 = f2.operator*(g2);
//     CHECK(resAdd1==Fraction(0,10));

// }


// TEST_CASE(" Operators > & >= Fractions"){

//     Fraction f(1,2);
//     Fraction g(1,3);
//     Fraction resAdd = f.operator*(g);

//     CHECK(f.operator>=(g));
//     CHECK(f.operator>(g));
//     CHECK(resAdd>=Fraction(1,6));
//     CHECK_FALSE(resAdd>Fraction(1,6));


//     float number = (float)1/2;
//     CHECK(operator>=(number,f));
//     CHECK_FALSE(operator>(number,f));
//     CHECK(f.operator>(g));


// }

// TEST_CASE(" Operators < & <= Fractions"){

//     Fraction f(1,2);
//     Fraction g(1,3);
//     Fraction resAdd = g.operator-(f);

//     CHECK(g.operator<=(f));
//     CHECK(g.operator<(f));
//     CHECK(resAdd<=Fraction(0,6));
//     CHECK(resAdd<Fraction(0,6));

//     float number = (float)1/2;
//     CHECK(operator<=(f,number));
//     CHECK_FALSE(operator<(f,number));
//     CHECK(g.operator<(f));

// }

// TEST_CASE(" Operators == Fractions"){

//     Fraction f(1,2);
//     Fraction g(1,2);
    
//     CHECK(g.operator==(f));
//     float number =(float)1/2;
//     CHECK(operator==(f,number));
//     CHECK(operator==(number,f));


// }



// TEST_CASE(" ++ -- operators "){

    
//     Fraction a(0,1);   

//     Fraction len(20,1);
//     Fraction flag(19,1);
//     Fraction i(0,1);

//    while(i <len)
//     {

//         CHECK(a.operator==(i));

//         a++;

//         CHECK_FALSE(a.operator==(i));
      
//       i++;
        
//     }

//     CHECK(i.operator==(len));
//     CHECK(a.operator==(len));


// }





