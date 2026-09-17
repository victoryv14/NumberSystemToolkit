#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class NumberSystem
{
   protected:
      string value;
      int base;
      int decimal;
   public:
      NumberSystem(int base_val) {
         base = base_val;
         decimal = 0;
      }
      void GetInput(){
         cin >> value;
      }
      void display(){
         cout << "Value in given Base: " << value << endl;
         cout << "Base : " << base << endl;
      }
      void prime_check(){
         decimal_conversion();
         bool prime = true;
         if( decimal <= 1 ){
            prime = false;
         }
         else{
            for( int i = 2; i <= sqrt(decimal); i++ ){
               if( decimal % i == 0 ){
                  prime = false;
                  break;
               }
            }
         }
         if( prime )
            cout << decimal << " is a Prime number!" << endl;
         else
            cout << decimal << " is not a Prime number!" << endl;
      }
      void palindrome_check(){
         string reversed = "";
         for( int i = value.length() - 1; i >= 0; i-- ){
            reversed += value[i];
         }
         if( value == reversed )
            cout << value << " is a Palindrome!" << endl;
         else
            cout << value << " is not a Palindrome!" << endl;
      }
      virtual bool validate() = 0;
      virtual void convert() = 0;
      virtual void decimal_conversion() = 0;
};

class BinarySystem : public NumberSystem
{
   public :
      BinarySystem() : NumberSystem(2){ }
      bool validate(){
         bool validation = true;
         for( int i = 0; i < value.length(); i++ ){
            if( value[i] != '0' && value[i] != '1' ){
               validation = false;
               break;
            }
         }
         return validation;
      }
      void convert(){
         cout << "Converting to Decimal....." << endl;
         decimal_conversion();
         display();
         cout << "The Decimal value is : " << decimal << endl;
      }
      void decimal_conversion(){
         decimal = 0;
         int position = 0;
         for( int i = value.length() - 1; i >= 0; i-- ){
            decimal += (value[i] - '0') * pow(2,position);
            position++;
         }
      }
};

class DecimalSystem : public NumberSystem
{
   public :
      DecimalSystem() : NumberSystem(10){ }
      bool validate(){
         bool validation = true;
         for( int i = 0; i < value.length(); i++ ){
            if( value[i] < '0' || value[i] > '9' ){
               validation = false;
               break;
            }
         }
         return validation;
      }
      void convert(){
         cout << "Converting to Binary....." << endl;
         decimal_conversion();
         string binary = binary_conversion();
         display();
         cout << "The Binary value is : " << binary << endl;
      }
      void decimal_conversion(){
         decimal = 0;
         for( int i = 0; i < value.length(); i++ ){
            decimal = decimal * 10 + (value[i] - '0');
         }
      }
   private :
      string binary_conversion(){
         string binary = "";
         int temp = decimal;
         while( temp > 0 ){
            int remainder = temp % 2;
            binary = to_string(remainder) + binary;
            temp /= 2;
         }
         return binary;
      }
};

// ─── Separate Menu Function ───
void displayMenu(){
    cout << "==============================================" << endl;
    cout << "           NUMBER SYSTEM TOOLKIT              " << endl;
    cout << "==============================================" << endl;
    cout << " MENU : " << endl;
    cout << "        1. BINARY\n";
    cout << "        2. DECIMAL\n";
    cout << "        3. EXIT\n";
    cout << "==============================================" << endl;
}

int main(){
    char choice;
    displayMenu();
    do{
        cout << "Enter your choice (M for MENU): ";
        cin >> choice;
        switch ( choice ){
            case '1' : {
               BinarySystem b;
               cout << "Enter Binary number: ";
               b.GetInput();
               if( b.validate() ){
                  cout << "=================================" << endl;
                  cout << "1. Convert to Decimal\n";
                  cout << "2. Check Prime\n";
                  cout << "3. Check Palindrome\n";
                  cout << "=================================" << endl;
                  cout << "Enter choice: ";
                  char op;
                  cin >> op;
                  if( op == '1' )
                     b.convert();
                  else if( op == '2' )
                     b.prime_check();
                  else if( op == '3' )
                     b.palindrome_check();
                  else
                     cout << "Invalid choice!\n";
               }
               else{
                  cout << "Invalid Binary number!\n";
               }
               break;
            }
            case '2' : {
               DecimalSystem d;
               cout << "Enter Decimal number: ";
               d.GetInput();
               if( d.validate() ){
                  cout << "=================================" << endl;
                  cout << "1. Convert to Binary\n";
                  cout << "2. Check Prime\n";
                  cout << "3. Check Palindrome\n";
                  cout << "=================================" << endl;
                  cout << "Enter choice: ";
                  char op;
                  cin >> op;
                  if( op == '1' )
                     d.convert();
                  else if( op == '2' )
                     d.prime_check();
                  else if( op == '3' )
                     d.palindrome_check();
                  else
                     cout << "Invalid choice!\n";
               }
               else{
                  cout << "Invalid Decimal number!\n";
               }
               break;
            }
            case '3' :
               cout << "Have a nice day!\nSee you again!\n";
               break;
            case 'M' :
            case 'm' :
               displayMenu();
               break;
            default :
               cout << " Invalid choice !\n";
        }
    } while ( choice != '3' );
    return 0;
}