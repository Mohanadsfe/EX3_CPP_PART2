#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;




namespace ariel{

    class Fraction
    {
    private:
        /* data */

        int _denomirator; // mekhni
        int _numerator; // moni

    public:

        Fraction(int numerator,int denomirator);
        Fraction(const Fraction& frac);
        Fraction( Fraction && ) = default; 	
        explicit Fraction(double number);
        ~Fraction();
         Fraction();
        
        

        int getDenominator() const{
            return this->_denomirator;
        }

        int getNumerator() const{
            return this->_numerator;
        }


        Fraction& operator++();    
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        Fraction operator+(const Fraction  &frac)const;
        Fraction operator-(const Fraction  &frac)const;
        Fraction operator* (const Fraction  &frac)const;
        Fraction operator/ (const Fraction  &frac)const;


      


        friend Fraction operator*(float number,const Fraction  &frac);
        friend Fraction operator*(const Fraction  &frac,float number);
        friend Fraction operator+(float number,const Fraction  &frac);
        friend Fraction operator+(const Fraction  &frac,float number);
        friend Fraction operator-(float number,const Fraction  &frac);
        friend Fraction operator-(const Fraction  &frac,float number);
        friend Fraction operator/(float number,const Fraction  &frac);
        friend Fraction operator/(const Fraction  &frac,float number);

        // bool compare_float(float x, float y, float epsilon);

        bool operator== (const Fraction &frac)const;
        bool operator>= (const Fraction  &frac)const;
        bool operator> (const Fraction  &frac)const;
        bool operator<(const Fraction  &frac)const;
        bool operator<= (const Fraction  &frac)const;

        friend bool operator>(const Fraction  &frac,float number);
        friend bool operator>(float number ,const Fraction  &frac);

        friend bool operator<(const Fraction  &frac, float number);
        friend bool operator<(float number,const Fraction  &frac);

        friend bool operator<=(float number,const Fraction  &frac);
        friend bool operator<=(const Fraction  &frac,float number);
        friend bool operator>=(float number,const Fraction   &frac);
        friend bool operator>=(const Fraction  &frac, float number);
        friend bool operator==(float number,const Fraction  &frac);
        friend bool operator==(const Fraction  &frac,float number);
        //Fraction&  operator=(Fraction&&  frac)noexcept;
        Fraction& operator=(Fraction const &frac);
        bool operator!=(const Fraction& frac);
        Fraction& operator=(Fraction&&  frac) = default;

        friend ostream& operator<<(ostream& output, const Fraction& frac);
        friend istream& operator>>(istream& input,Fraction& frac);



    };
    
   

};
#endif