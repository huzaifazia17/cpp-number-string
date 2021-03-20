#include <iostream>
#include <string>

using namespace std;

string num_one[] = { " zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string num_teen[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
string num_ten[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string convert_num_string(int num);
string convert_num_dec_string(int dec_num);
string convert_toupp_tolow(string message);

int main()
{
    double test_num;

        string message;
        cout << "Enter a message to transform to the opposite case" << endl;
        getline(cin, message); // gets the whole line of input including 'white' space

        cout << convert_toupp_tolow(message) << endl;
        cout << " "<< endl;

        //-----------------------QUESTION 2---------------------------------//

        cout << "Please enter a positive integer to convert to its string equivalent: ";
        cin >> test_num;

        while (test_num < 0 || test_num > 999999.99) {
            cout << "Invalid Number:Please enter a positive integer less than 999,999.99 to convert to its string equivalent  ";
            cin >> test_num;
        }
 
        int num = (int)test_num;
        double dec_num = test_num - num; // get the decimal value; 100.65 - 100 = 0.65
        dec_num = dec_num * 100; // have the decimal value as an int; 0.65*100 = 65
        dec_num = (int)dec_num;

        cout << "\n" << convert_num_string(num) << " dollars " << "and " << convert_num_dec_string(dec_num) << " cents " << endl;

    return 0;
}

string convert_toupp_tolow(string message) {
    for (int i = 0; i < message.length(); i++) {
        if (islower(message[i])) {
            message[i] = toupper(message[i]);
        }
        else if (isupper(message[i])) {
            message[i] = tolower(message[i]);
        }
    }
    return message;
}

string convert_num_dec_string(int dec_num) {
    if (dec_num < 10) {
        return num_one[dec_num];
    }
    else if (dec_num < 20) {
        return num_teen[dec_num - 10];
    }
    else if (dec_num < 100) {
        return num_ten[dec_num / 10] + ((dec_num % 10 != 0) ? " " + convert_num_dec_string(dec_num % 10) : "");
    }
    return "";
    
}

string convert_num_string(int num) {
    if (num < 10) {
        return num_one[num];
    }
    else if (num < 20) {
        return num_teen[num - 10];
    }
    else if (num < 100) {
        return num_ten[num / 10] + ((num % 10 != 0) ? " " + convert_num_string(num % 10) : "");
    }
    else if (num < 1000) {
        return convert_num_string(num / 100) + " hundred" + ((num % 100 != 0) ? " " + convert_num_string(num % 100) : "");
    }
    else if (num < 1000000) {
        return convert_num_string(num / 1000) + " thousand" + ((num % 1000 != 0) ? " " + convert_num_string(num % 1000) : "");
    }
    return "";
}



