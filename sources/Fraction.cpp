#include "Fraction.hpp"
#include <cstring>
#include <cmath>
#include <typeinfo>
using namespace std;


namespace ariel{

bool addOverflow(Fraction x, Fraction y)
{
    Fraction temp = x + y;
    if(x>0 && y>0 && temp<0)
        return 1;
    if(x<0 && y<0 && temp>0)
        return 1;
    
    return 0;
}
 
    //Fraction::~Fraction(){}
    
   Fraction::Fraction():_numerator(1),_denomirator(1){}

   Fraction::Fraction(int numerator,int denomirator):_numerator(numerator),_denomirator(denomirator){

         
            if(this->_denomirator==0)
                throw invalid_argument("Error,the denomirator is zero!!");
            

            if((numerator>0&&denomirator<0)||(numerator<0&&denomirator<0)){
                this->_numerator=numerator*(-1);
                this->_denomirator=denomirator*(-1);
            }

            
        };

    Fraction::Fraction(const Fraction& frac){

        if(frac.getDenominator()==0)
            throw runtime_error("the deno is zero here!! ");
        
        // **this = frac;

        this->_numerator = frac.getNumerator();
        this->_denomirator = frac.getDenominator();
        
    }

    Fraction::Fraction(double number):_numerator(number*1000),_denomirator(1000){}

    

    Fraction::~Fraction()
            {

            };



// return GCD of a and b

int gcd(int aNumber, int bNumber) {

    aNumber = std::abs(aNumber);
    bNumber= std::abs(bNumber);

   int minN = min(aNumber,bNumber);
    int res = 1;

    for(int i=1; i<=minN; i++){
        if(aNumber%i==0 && bNumber%i==0)
            res =i;
    }

    return res;

}


Fraction decimalToFraction(double number, int cycles = 10, double precision = 5e-2){
    int sign  = number > 0 ? 1 : -1;
    number = number * sign; //abs(number);
    double new_number,whole_part;
    double decimal_part =  number - (int)number;
    int counter = 0;
    
    valarray<double> vec_1{double((int) number), 1}, vec_2{1,0}, temporary;
    
    while(decimal_part > precision & counter < cycles){
        new_number = 1 / decimal_part;
        whole_part = (int) new_number;
        
        temporary = vec_1;
        vec_1 = whole_part * vec_1 + vec_2;
        vec_2 = temporary;
        
        decimal_part = new_number - whole_part;
        counter += 1;
    }

    double nur = sign * vec_1[0];
    double deno = vec_1[1];
   
    return  Fraction(nur,deno);
}



///////////////////////////////



    Fraction& Fraction::operator++(){ // ++n
            
            this->_numerator = this->_numerator + this->_denomirator;

            return *this;

         }
            
           
    Fraction Fraction::operator++(int){ // n++

            Fraction cpy = *this;
            this->_numerator = this->_numerator + this->_denomirator;
            return cpy;

         } 


    Fraction& Fraction::operator--(){ // --n
            
            this->_numerator = this->_numerator - this->_denomirator;

            return *this;

         }
            
           
    Fraction Fraction::operator--(int){ // n--

            Fraction cpy = *this;
            this->_numerator = this->_numerator - this->_denomirator;
            return cpy;

         } 




//////////////////////////////  operator +


   Fraction Fraction::operator+(const Fraction  &frac)const{

       if(!(frac.getNumerator() <= std::numeric_limits<int>::min()+1 && this->getNumerator() <= std::numeric_limits<int>::min()+1
            && frac.getDenominator() <= std::numeric_limits<int>::min()+1 && this->getDenominator() <= std::numeric_limits<int>::min()+1)){


        if((frac.getNumerator() <= std::numeric_limits<int>::min()+1 && this->getNumerator() <= std::numeric_limits<int>::min()+1))
       
                throw overflow_error("error min");

            }

        if(!(frac.getNumerator() >= std::numeric_limits<int>::max()-100 && this->getNumerator()>= std::numeric_limits<int>::max() -100 
            && frac.getDenominator() >= std::numeric_limits<int>::max()-100 && this->getDenominator()>= std::numeric_limits<int>::max() -100)){


        if((frac.getNumerator() >= std::numeric_limits<int>::max()-100 && this->getNumerator()>= std::numeric_limits<int>::max() -100))
       
                throw overflow_error("error");

            }

            int new_numerator1 = this->getNumerator()  * frac.getDenominator();
            int new_numerator2 = frac.getNumerator()* this->getDenominator();
            int new_numerator = new_numerator1 + new_numerator2;
            int new_denomirator = this->getDenominator() * frac.getDenominator();

           int l_gcd = gcd(new_denomirator,new_numerator);



        return Fraction(new_numerator/l_gcd,new_denomirator/l_gcd);

         }

     Fraction operator+(float number,const Fraction  &frac){

       
         Fraction frac2(number*1000,1000);

          int new_numerator1 = frac2.getNumerator()  * frac.getDenominator();
          int new_numerator2 = frac.getNumerator()* frac2.getDenominator();

            int new_numerator = new_numerator1 + new_numerator2;
            int new_denomirator = frac2.getDenominator() * frac.getDenominator();

           int l_gcd = gcd(new_denomirator,new_numerator);

        return Fraction(new_numerator/l_gcd,new_denomirator/l_gcd);


     }

     Fraction operator+(const Fraction  &frac,float number){

        
        return operator+(number,frac);

     }


///////////////////////////////////////// operator -
      Fraction Fraction::operator-(const Fraction &frac)const{

    if((frac.getNumerator() <= std::numeric_limits<int>::min()+1 || this->getNumerator() < std::numeric_limits<int>::min()+1)){
       
                throw overflow_error("error min");

            }

    if(!(frac.getNumerator() >= std::numeric_limits<int>::max()-100 && this->getNumerator()>= std::numeric_limits<int>::max() -100 
            && frac.getDenominator() >= std::numeric_limits<int>::max()-100 && this->getDenominator()>= std::numeric_limits<int>::max() -100)){


        if((frac.getNumerator() >= std::numeric_limits<int>::max()-100 && this->getNumerator()>= std::numeric_limits<int>::max() -100))
       
                throw overflow_error("error");

            }
        // bool res = addOverflow(frac,*this);
       
        // if(res==1)
        //     throw overflow_error("error");
            
            int new_numerator1 = this->getNumerator()  * frac.getDenominator();
            int new_numerator2 = frac.getNumerator()* this->getDenominator();
            int new_numerator = new_numerator1 - new_numerator2;
            int new_denomirator = this->getDenominator() * frac.getDenominator();

           
            int l_gcd = gcd(new_denomirator,new_numerator);


           
        return Fraction(new_numerator/l_gcd,new_denomirator/l_gcd);
}

    Fraction operator-(float number,const Fraction  &frac){

            Fraction frac2(number*1000,1000);


        return  (frac2).operator-(frac);

     }

   Fraction operator-(const Fraction  &frac,float number){

        Fraction res =  operator-(number,frac);
        Fraction meunsOne (-1,1);

       return res.operator*(meunsOne);

     }



///////////////////////////////////////// operator *




    Fraction Fraction::operator*(const Fraction  &frac)const{


        if((*this).getDenominator()==0 || frac.getDenominator()==0)
                    throw runtime_error("Error get denomrator equal to zero!! ");


        bool res = addOverflow(frac,*this);
       
        if(res==1)
            throw overflow_error("error");


           int l_gcd = gcd(this->getNumerator()*frac.getNumerator(),this->getDenominator()*frac.getDenominator());

           return Fraction((this->getNumerator()*frac.getNumerator())/l_gcd,(this->getDenominator()*frac.getDenominator())/l_gcd);

         }


    Fraction operator*(float number,const Fraction  &frac){

            Fraction frac2(number*1000,1000);
            
            return (frac2).operator*(frac);

        }

    Fraction operator*(const Fraction  &frac,float number){

            return operator*(number,frac);
            
        }


///////////////////////////////////////// operator /





    Fraction Fraction::operator/(const Fraction  &frac)const{

           if(this->getDenominator()*frac.getNumerator()==0)
                throw runtime_error("divide by zero!! ");

    bool res = addOverflow(frac,*this);
       
        if(res==1)
            throw overflow_error("error");


            int l_gcd = gcd(this->getNumerator()*frac.getDenominator(),this->getDenominator()*frac.getNumerator());


            return Fraction((this->getNumerator()*frac.getDenominator())/l_gcd,(this->getDenominator()*frac.getNumerator())/l_gcd);

         }

   
    Fraction operator/(float number,const Fraction  &frac){

            Fraction frac2(number*1000,1000);

        return (frac2).operator/(frac);

     }

    ariel::Fraction operator/(const Fraction  &frac, float number){

        if(number==0)
            throw runtime_error("Divide by zero!! (float)");
            
         Fraction frac2 =  decimalToFraction(number);


         int l_gcd = gcd(frac.getNumerator()*frac2.getDenominator(),frac.getDenominator()*frac2.getNumerator());


    return Fraction((frac.getNumerator()*frac2.getDenominator())/l_gcd,(frac.getDenominator()*frac2.getNumerator())/l_gcd);

        
     }

/////////////////////////////////////////  operator==


 

 bool Fraction::operator==(const Fraction &frac)const{


        if(this->getNumerator()==0 && frac.getNumerator()==0)
            return true;


           int a = ((float)this->_numerator / (float)this->_denomirator) * 1000;
           int b = ((float)frac._numerator / (float)frac._denomirator) * 1000;
            return a == b;
        
         }

  bool operator==(const Fraction &frac, float number){

        Fraction frac2(number*1000,1000);

         return frac2.operator==(frac);
           
         }


    bool operator==(float number,const Fraction &frac){

        Fraction frac2(number*1000,1000);

            return frac2.operator==(frac);
           
         }


/////////////////////////////////////// operator>

    bool Fraction::operator>(const Fraction  &frac)const{

         Fraction res = (*this).operator-(frac);
         
        Fraction orgN(this->getNumerator()*frac.getDenominator(),this->getDenominator()*frac.getDenominator());
        Fraction num(frac.getNumerator()*this->getDenominator(),this->getDenominator()*frac.getDenominator());

    return orgN.getNumerator()>num.getNumerator() ? true : false;


    }


    bool operator>(const Fraction &frac, float number){

         Fraction frac2 =  decimalToFraction(number);

        Fraction orgN(frac.getNumerator()*frac2.getDenominator(),frac.getDenominator()*frac2.getDenominator());
        Fraction num(frac2.getNumerator()*frac.getDenominator(),frac.getDenominator()*frac2.getDenominator());

         
     return orgN.getNumerator()>num.getNumerator() ? true : false;
           
         }


    bool operator>(float number,const Fraction &frac){

            Fraction frac2 =  decimalToFraction(number);

            return operator>(frac2,((float)frac.getNumerator()/(float)frac.getDenominator()));
           
         }



/////////////////////////////////////////////// operator >=

    bool Fraction::operator>=(const Fraction  &frac)const{

        Fraction num(frac.getNumerator()*(*this).getDenominator(),frac.getDenominator()*(*this).getDenominator());
        Fraction orgN((*this).getNumerator()*frac.getDenominator(),frac.getDenominator()*(*this).getDenominator());

    
          if(orgN.operator==(num))
                return true;

     return orgN.getNumerator() > num.getNumerator() ? true : false;


    }



     bool operator>=(const Fraction &frac, float number){

         Fraction frac2 =  decimalToFraction(number);

        Fraction orgN(frac.getNumerator()*frac2.getDenominator(),frac.getDenominator()*frac2.getDenominator());
        Fraction num(frac2.getNumerator()*frac.getDenominator(),frac.getDenominator()*frac2.getDenominator());


          if(orgN.operator==(num))
            return true;

     return orgN.getNumerator()>num.getNumerator() ? true : false;
           
         }


    bool operator>=(float number,const Fraction &frac){

            Fraction frac2 =  decimalToFraction(number);

          if(frac2.operator==(frac))
             return true;

         return operator>(frac2,((float)frac.getNumerator()/(float)frac.getDenominator()));
           
         }

/////////////////////////////////// operator <

    
    bool Fraction::operator<(const Fraction  &frac)const{

         Fraction res = (*this).operator-(frac);
         
        Fraction orgN(this->getNumerator()*frac.getDenominator(),this->getDenominator()*frac.getDenominator());
        Fraction num(frac.getNumerator()*this->getDenominator(),this->getDenominator()*frac.getDenominator());

    return orgN.getNumerator()<num.getNumerator() ? true : false;

    }


    bool operator<(const Fraction &frac, float number){

         Fraction frac2 =  decimalToFraction(number);

        Fraction orgN(frac.getNumerator()*frac2.getDenominator(),frac.getDenominator()*frac2.getDenominator());
        Fraction num(frac2.getNumerator()*frac.getDenominator(),frac.getDenominator()*frac2.getDenominator());

         
     return orgN.getNumerator()<num.getNumerator() ? true : false;
           
         }


    bool operator<(float number,const Fraction &frac){


            Fraction frac2 =  decimalToFraction(number);

     return operator<(frac2,((float)frac.getNumerator()/(float)frac.getDenominator()));
           
    }

////////////////////////////////////////////////// operator <=


    bool Fraction::operator<=(const Fraction &frac)const{

        Fraction num(frac.getNumerator()*(*this).getDenominator(),frac.getDenominator()*(*this).getDenominator());
        Fraction orgN((*this).getNumerator()*frac.getDenominator(),frac.getDenominator()*(*this).getDenominator());

          if(orgN.operator==(num))
                return true;

     return orgN.getNumerator()<num.getNumerator() ? true : false;


    }

     bool operator<=(const Fraction &frac, float number){

         Fraction frac2 =  decimalToFraction(number);

        Fraction orgN(frac.getNumerator()*frac2.getDenominator(),frac.getDenominator()*frac2.getDenominator());
        Fraction num(frac2.getNumerator()*frac.getDenominator(),frac.getDenominator()*frac2.getDenominator());

          if(orgN.operator==(num))
            return true;
         
     return orgN.getNumerator()<num.getNumerator() ? true : false;
           
         }


    bool operator<=(float number,const Fraction &frac){

     Fraction frac2 =  decimalToFraction(number);

        if(frac2.operator==(frac))
             return true;

     return operator<(frac2,((float)frac.getNumerator()/(float)frac.getDenominator()));
           
    }
///////////////////////////////////////////////

    bool Fraction::operator!=(const Fraction &frac){

        return (this->getNumerator()!= frac.getNumerator() || this->getDenominator() != frac.getDenominator());

    }
////////////////////////////////////////////////

    // Fraction& Fraction::operator=(Fraction&&  frac)noexcept{

    //     if(*this != frac){
    //         _numerator = frac.getNumerator();
    //         _denomirator = frac.getDenominator();
    //     }

    //     return *this;

    // }

 Fraction& Fraction::operator=(Fraction const &frac){

        if(*this != frac){
            _numerator = frac.getNumerator();
            _denomirator = frac.getDenominator();
        }

        return *this;

    }


///////////////////////////////////////////////



    ostream& operator<<(ostream& output, const Fraction& frac){

        int l_gcd = gcd(frac.getDenominator(),frac.getNumerator());

        if(frac.getDenominator()<0 && frac.getNumerator()>0){

                  return (output << (-1)*frac._numerator/l_gcd << "/" << (-1)*frac._denomirator/l_gcd);

        }

        return (output << frac._numerator/l_gcd << "/" << frac._denomirator/l_gcd);

    }

      istream& operator>>(istream& input, Fraction& frac) {

        int numerator;
        int denominator;
        if (!(input >> numerator)) {
            throw std::runtime_error("Invalid input format for Fraction numerator");
        }
        
        if (!(input >> denominator)) {
            throw std::runtime_error("Invalid input format for Fraction denominator");
        }
        if(denominator==0){
            throw std::runtime_error("a/0");
        }

        frac = Fraction(numerator, denominator);

        return input;

    }

   
    // istream& operator>>(istream& input,Fraction& frac){

    //     char c;  
    //     float i;
    //     int j;
    //     int neme , deno;
    //        const type_info& ti1 = typeid(i);
    //        const type_info& ti2 = typeid(frac.getDenominator());
    //        const type_info& ti3 = typeid(frac.getNumerator());
    //        const type_info& ti4 = typeid(j);

    //            if((ti4 == ti2 && ti4 == ti3)){

    //          input >> neme;
    //          input >> c;
    //          input >> deno;

    //  }
    //  else{

    //         throw runtime_error("Float Int var , error!!");
    //  }  

    //  if(deno==0)
    //         throw runtime_error("denoooo is zero");

    //     frac = Fraction(neme,deno);

    //     return input;   

    // }


};