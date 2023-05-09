//
// Created by super on 4/15/23.
//

#include "Fraction.hpp"
#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
namespace ariel{

    Fraction::Fraction(int numerator, int denominator){
        if(are_you_valid(numerator, denominator) == -1){
            throw overflow_error("the number is too big");
        }

        if((numerator == INT_MAX && denominator == INT_MAX) || (numerator == INT_MIN && denominator == INT_MIN)){
            num = 1;
            den = 1;
            return;
        }

        if((numerator == INT_MAX && denominator == INT_MIN) || (numerator == INT_MIN && denominator == INT_MAX)){
            num = -999;
            den = 1000;
            return;
        }

        if(numerator == 0 && denominator == 0){
            num = 0;
            den = 1;
            return;
        }

        if(denominator == 0){
            throw invalid_argument("denominator can't be 0");
        }

        if(numerator == 0){
            num = 0;
            den = 1;
            return;
        }

        if(numerator < 0 && denominator < 0){
            den = abs(denominator);
            num = abs(numerator);/////?????
        }
        else if(denominator < 0){
            den = abs(denominator);
            num = -numerator;
        }
        else{
            den = denominator;
            num = numerator;
        }
        reduce();
    }

    /*Fraction::Fraction(const Fraction& frc){
        this->num = frc.get_num();
        this->den = frc.get_den();
        reduce();
    }*/

    /*Fraction::Fraction(int numerator){
        Fraction(numerator, 1);
    }*/

    Fraction::Fraction(float num1){
        if(num1 == 0){
            num = 0;
            den = 1;
            return;
        }
        num = (int)(num1*1000);
        den = 1000;
        reduce();
    }

    int Fraction::getNumerator() const{
        return num;
    }

    int Fraction::getDenominator() const{
        return den;
    }

    int Fraction::are_you_valid(int num1, int den1) const{
        if(num1 > INT_MAX || num1 < INT_MIN || den1 > INT_MAX || den1 < INT_MIN){
            return -1;
        }
        return 0;
    }

    const Fraction dub_to_frc(float num1){
        return Fraction((int)(num1*1000), 1000);
    }

    const Fraction Fraction::operator+(const Fraction& frc) const{
        long long this_num = num;
        long long this_den = den;
        long long frc_num = frc.getNumerator();
        long long frc_den = frc.getDenominator();
        long long num1 = this_num*frc_den + frc_num*this_den;
        long long num2 = this_den*frc_den;
        if(num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN)
            throw overflow_error("overflow");
        int num3 = num*frc.getDenominator() + frc.getNumerator()*den; //for the case of 0
        if(num3 == 0) return Fraction(0, 1);
        return Fraction(num3, den*frc.getDenominator());
    }

    const Fraction Fraction::operator-(const Fraction& frc) const{
        long long this_num = num;
        long long this_den = den;
        long long frc_num = frc.getNumerator();
        long long frc_den = frc.getDenominator();
        long long num1 = this_num*frc_den - frc_num*this_den;
        long long num2 = this_den*frc_den;
        if(num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN)
            throw overflow_error("overflow");
        int num3 = num*frc.getDenominator() - frc.getNumerator()*den; //for the case of 0
        if(num3 == 0) return Fraction(0,1);
        return Fraction(num3, den*frc.getDenominator());
    }

    const Fraction Fraction::operator*(const Fraction& frc) const{
        long long this_num = num;
        long long this_den = den;
        long long frc_num = frc.getNumerator();
        long long frc_den = frc.getDenominator();
        long long num1 = this_num*frc_num;
        long long num2 = this_den*frc_den;
        if(num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN)
            throw overflow_error("overflow");
        int num3 = num*frc.getNumerator();
        if(num3 == 0) return Fraction(0,1);
        return Fraction(num3, den*frc.getDenominator());
    }

    const Fraction Fraction::operator/(const Fraction& frc) const{
        // long long this_num = num;
        // long long this_den = den;
        // long long frc_num = frc.getNumerator();
        // long long frc_den = frc.getDenominator();
        int num1 = this->num*frc.getDenominator();
        int num2 = this->den*frc.getNumerator();
        if(num1 > INT_MAX || num1 < INT_MIN || num2 > INT_MAX || num2 < INT_MIN)
            throw overflow_error("overflow");
        if(frc.getNumerator()*this->den == 0) throw std::runtime_error("division by 0"); //???
        if(num == 0) return Fraction(0, 1);
        return Fraction(num1, num2);
    }

    Fraction& Fraction::operator+=(const Fraction& frc){
        *this = *this + frc;
        this->reduce();
        return *this;
    }

    Fraction& Fraction::operator-=(const Fraction& frc){
        *this = *this - frc;
        this->reduce();
        return *this;
    }

    Fraction& Fraction::operator+=(float num1){
        Fraction f = dub_to_frc(num1);
        *this = *this + f;
        this->reduce();
        return *this;
    }

    Fraction& Fraction::operator-=(float num1){
        Fraction f = dub_to_frc(num1);
        *this = *this - f;
        this->reduce();
        return *this;
    }

//prefix
    Fraction& Fraction::operator++(){
        *this += Fraction(1, 1);
        return *this;
    }

//postfix
    const Fraction Fraction::operator++(int){
        Fraction frc(this->getNumerator(), this->getDenominator());
        *this += Fraction(1, 1);
        return frc;

    }

//prefix
    Fraction& Fraction::operator--(){
        *this -= Fraction(1, 1);
        return *this;
    }

//postfix
    const Fraction Fraction::operator--(int){
        Fraction frc(this->getNumerator(), this->getDenominator());
        *this -= Fraction(1, 1);
        return frc;
    }

    bool Fraction::operator>(const Fraction& frc) const{
        float this_frc = ((float)this->getNumerator())/((float)this->getDenominator());
        float other_frc = ((float)frc.getNumerator())/((float)frc.getDenominator());
        if(this_frc > other_frc) return true;
        return false;
    }

    bool Fraction::operator<(const Fraction& frc) const{
        float this_frc = ((float)this->getNumerator())/((float)this->getDenominator());
        float other_frc = ((float)frc.getNumerator())/((float)frc.getDenominator());
        if(this_frc < other_frc) return true;
        return false;
    }

    bool Fraction::operator>=(const Fraction& frc) const{
        float this_frc = ((float)this->getNumerator())/((float)this->getDenominator());
        float other_frc = ((float)frc.getNumerator())/((float)frc.getDenominator());
        if(this_frc >= other_frc) return true;
        return false;
    }

    bool Fraction::operator<=(const Fraction& frc) const{
        float this_frc = ((float)this->getNumerator())/((float)this->getDenominator());
        float other_frc = ((float)frc.getNumerator())/((float)frc.getDenominator());
        if(this_frc <= other_frc) return true;
        return false;
    }

    bool Fraction::operator==(Fraction frc) const{
        if(num == frc.getNumerator() && den == frc.getDenominator()) return true;
        float this_frc = (this->getNumerator())/(this->getDenominator());
        float other_frc = (frc.getNumerator())/(frc.getDenominator());
        this_frc = round(this_frc*1000)/1000;
        other_frc = round(other_frc*1000)/1000;
        if(this_frc == other_frc) return true;
        return false;
    }

    bool Fraction::operator!=(const Fraction& frc) const{
        return (this->getNumerator() != frc.getNumerator() || this->getDenominator() != frc.getDenominator());
    }

    /*Fraction& Fraction::operator=(const Fraction& frc){
        if(*this != frc){
            num = frc.get_num();
            den = frc.get_den();
        }
        return *this;
    }*/

    ostream& operator<<(ostream& ost, const Fraction& fraction) {
        ost << "" << fraction.getNumerator() << "/" << fraction.getDenominator();
        return ost;
    }

    istream& operator>>(istream& ist, Fraction& fraction) {
        int num1 = 0, den1 = 0;
        ist >> num1 >> den1;

        //please throw exception if den1 wasnt valid
        if(den1 == 0) throw std::runtime_error("denominator can't be 0");
        fraction = Fraction(num1, den1);
        return ist;
    }

    void Fraction::reduce(){
        int gcd_val = gcd(abs(num), abs(den));
        num = ((int)(num))/gcd_val;
        den = ((int)(den))/gcd_val;
    }

    //i got help in this function from my friend Mohanad Sefi 208113381
    int Fraction::gcd(int anum, int bnum) const{
        int min_res = min(abs(anum), abs(bnum));
        int res = 1;

        for(int i = 1; i <= min_res; i++){
            if(abs(anum) % i==0 && abs(bnum) % i==0)
                res =i;
        }
        return res;
    }

    const Fraction operator+(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        f += frc;
        f.reduce();
        return f;
    }

    const Fraction operator-(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return f - frc;
    }

    const Fraction operator*(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return f * frc;
    }

    const Fraction operator/(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return f / frc;
    }

    const Fraction Fraction::operator+(float num1) const{
        Fraction f = dub_to_frc(num1);
        return *this + f;
    }

    const Fraction Fraction::operator-(float num1) const{
        Fraction f = dub_to_frc(num1);
        return *this - f;
    }

    const Fraction Fraction::operator*(float num1) const{
        Fraction f = dub_to_frc(num1);
        return *this * f;
    }

    const Fraction Fraction::operator/(float num1) const{
        Fraction f = dub_to_frc(num1);
        return *this / f;
    }

    bool Fraction::operator>(float num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this > f);
    }

    bool Fraction::operator<(float num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this < f);
    }

    bool Fraction::operator>=(float num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this >= f);
    }

    bool Fraction::operator<=(float num1) const{
        Fraction f = dub_to_frc(num1);
        return (*this <= f);
    }

    bool Fraction::operator==(float num1) const{
        float this_frc = (float)(this->getNumerator())/(this->getDenominator());
        this_frc = round(this_frc * 1000) / 1000;
        return (this_frc == num1);
    }

    bool operator>(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f > frc);
    }

    bool operator<(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f < frc);
    }

    bool operator>=(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f >= frc);
    }

    bool operator<=(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f <= frc);
    }

    bool operator==(float num1, const Fraction& frc){
        Fraction f = dub_to_frc(num1);
        return (f == frc);
    }
}