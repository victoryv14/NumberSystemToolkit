#include<iostream>
using namespace std;
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
               cout << " Inavlid choice !\n";
        }
    } while ( choice != '5' );
    return 0;
}