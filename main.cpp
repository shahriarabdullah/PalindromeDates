// Abdullah Shahriar
// 10.10.18
#include <iostream>

using namespace std;
// Variable for counting number of palindrome dates in a year
int c=0;

// Function for generating palindrome date for specific year
void palindrome(int year){

    // If we input 18 as year, the digit 8 will be stored in
    // first_digit  and the digit 1 will be stored in second
    // digit.
    // Because the reverse of 18 is 81 where 8 is first digit
    // and 1 is second digit.
    int first_digit=year%10;
    int second_digit=year/10;

    // Case-1:
    // Input XY
    // Output YX.11.XY
    // XY<31
    // Six digit Palindrome

    // If the reverse of year is less than 31 than we can
    // generate six digit palindrome.
    // For example- If 21 is input, the reverse is 12 which is
    // less than 31. Thus a palindrome date will be 12.11.21

    // The month is always 11 (November), otherwise it won't be
    // palindrome. As November have 30 days, so the condition is <31
    if((first_digit*10)+second_digit<31){
            if(second_digit==0){
    // If 01 is input, the following line outputs 10.11.01

                cout << first_digit << second_digit << ".11.0" << year << endl;
                c++;
            } else {
    // If 41 is input, the following line outputs 14.11.41
                cout << first_digit << second_digit << ".11." << year << endl;
                c++;
            }

    }

    // Case-2:
    // Input 0Y
    // Output Y.0M.0Y
    // 0Y<=9
    // Five digit palindrome
    if(second_digit==0){

    // If 04 is input the following loop will output 4.0M.04
    // where M=1,2,3,4,5,6,7,8,9
    for(int i=1;i<=9;i++){
        cout <<  year << ".0" << i << "." << "0" << year << endl;
        c++;
    }

    }

    // Case-3:
    // Input 1Y
    // Output Y.1M.1Y
    // Y!=0
    // Five digit palindrome

    // If 19 is input the following loop will output 9.1X.19
    // where X=1=0,1,2
    if(second_digit==1 && first_digit!=0){
        for(int i=0;i<=2;i++){
            cout << first_digit << ".1" << i << "." << year << endl;
            c++;
            }
    }

}


int main()
{
    int y_start,y_end;

    // The range of years to generate palindrome dates
    // y_start=1 y_end=99 will generate all palindrome
    // dates from year 2001 to 2099
    cout << "Enter starting year: "; cin>>y_start;
    cout << "Enter ending year: "; cin>>y_end;
    cout << endl;

    // Passing the values of years to palindrome function
    // to generate all palindrome date in that year.
    for(int i=y_start;i<=y_end;i++){
        palindrome(i);

    // A little bit of text formatting to make the output
    // look a little better.
        if(c>0){
            cout << endl;
        }
        c=0;
    }


    return 0;
}
