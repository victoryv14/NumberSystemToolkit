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
         cin >> value ;
      }
      void display(){
         cout <<"Value : " << value << endl;
         cout <<"Base : " << base << endl;
      }
      virtual  bool validate() = 0;
      virtual void convert() = 0;
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
         char converting_base;
         cout << "=================================" << endl;
         cout << "Convert Binary to:" << endl;
         cout << "1. Decimal\n";
         cout << "2. Octal\n";
         cout << "3. Hexadecimal\n";
         cout << "=================================" << endl;
         cin >> converting_base;
         switch( converting_base ){
            case '1' : {
               cout << "Converting to Decimal....." << endl;
               decimal_conversion();
               cout << "The Decimal value is : " << decimal << endl;
               break;
            }
            case '2' : {
               decimal_conversion();
               cout << "Converting to Octal....." << endl;
               string octal = octal_conversion();
               cout << "The Octal value is : " << octal << endl;
               break;
            }
            case '3' : {
               cout << "Coverting to Hexadecimal....." << endl;
               decimal_conversion();
               string hex = hex_conversion();
               cout << "The Hexadecimal value is : " << hex << endl;
               break;
            }
            default : {
               cout << "Invalid Choice !" << endl;
               break;
            }
         }
      }
   private :
      void decimal_conversion(){
         decimal = 0;
         int position = 0;
         for( int i = value.length() - 1; i >= 0; i-- ){
            decimal += (value[i] - '0') * pow(2,position);
            position++;
         }
      }
      string octal_conversion(){
         string octal = "";
         while( decimal > 0 ){
            int remainder = decimal % 8;
            octal = to_string(remainder) + octal;
            decimal /= 8;
         }
         return octal;
      }
      string hex_conversion(){
         string hex = "";
         while(decimal > 0){
            int remainder = decimal % 16;
            if(remainder < 10)
               hex = to_string(remainder) + hex;
            else
               hex = char('A' + remainder - 10) + hex;
            decimal /= 16;
         }
         return hex;
      }
};
int main(){
    char choice;
    cout << "==============================================" << endl;
    cout << "           NUMBER SYSTEM TOOLKIT              " << endl;
    cout << "==============================================" << endl;
    cout << " MENU : " << endl;
    cout << "        1. BINARY\n";
    cout << "        2. OCTAL\n";
    cout << "        3. DECIMAL\n";
    cout << "        4. HEXADECIMAL\n";
    cout << "        5. EXIT\n";
    cout << "==============================================" << endl;
    do{
        cout << "Enter your choice (M for MENU): ";
        cin >> choice;
        
        switch ( choice ){
            case '1' : 
               cout << "1\n";
               break;
            case '2' :
               cout << "2\n";
               break;
            case '3' : 
               cout << "3\n";
               break;
            case '4' :
               cout << "4\n";
               break;
            case '5' : 
               cout << "Have a nice day!\nSee you again!\n";
               break;
            case 'M' :
            case 'm' :
                cout << "==============================================" << endl;
                cout << "           NUMBER SYSTEM TOOLKIT              " << endl;
                cout << "==============================================" << endl;
                cout << " MENU : " << endl;
                cout << "        1. BINARY\n";
                cout << "        2. OCTAL\n";
                cout << "        3. DECIMAL\n";
                cout << "        4. HEXADECIMAL\n";
                cout << "        5. EXIT\n";
                cout << "==============================================" << endl;
                break;
            default :
               cout << " Invalid choice !\n";
        }
    } while ( choice != '5' );
    return 0;
}