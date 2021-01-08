// DataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main(){
    int numbers[5] = { 7, 5, 6, 12, 35 };

    for (const int& n : numbers) {
        cout << n << "  ";
    }


    cout << "\nThe numbers are: ";

    for (int i = 0; i < 5; ++i) {
        cout << numbers[i] << "  ";
    }

    cout << "\ninsert into array...";
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        cout << i;
        cin >> arr[i];
    }

    cout << "The numbers are: ";

    //  print array elements
    for (int n = 0; n < 5; ++n) {
        cout << arr[n] << "  ";
    }

    return 0;
}
