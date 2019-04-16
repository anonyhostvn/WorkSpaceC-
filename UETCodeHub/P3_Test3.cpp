#include <bits/stdc++.h>

using namespace std ;


int test(int day , int month) {
    if (month == 1) {
        if (day >= 20) return 10 ; else return 9 ;
    } else if (month == 2) {
        if (day >= 19) return 11 ; else return 10 ;
    } else if (month == 3) {
        if (day >= 21) return 0 ; else return 11 ;
    } else if (month == 4) {
        if (day >= 20) return 1 ; else return 0 ;
    } else if (month == 5) {
        if (day >= 21) return 2 ; else return 1 ;
    } else if (month == 6) {
        if (day >= 22) return 3 ; else return 2 ;
    } else if (month == 7) {
        if (day >= 23) return 4 ; else return 3 ;
    } else if (month == 8) {
        if (day >= 23) return 5 ; else return 4 ;
    } else if (month == 9) {
        if (day >= 23) return 6 ; else return 5 ;
    } else if (month == 10) {
        if (day >= 24) return 7 ; else return 6 ;
    } else if (month == 11) {
        if (day >= 23) return 8 ; else return 7 ;
    } else if (month = 12) {
        if (day >= 22) return 9 ; else return 8 ;
    }
}

int main () {
    int day , month ;
    cin >> day >> month ;
    switch (test(day,month)) {
        case 0 :
            cout << "Bach Duong" << endl ;
            break ;
        case 1 :
            cout << "Kim Nguu" << endl ;
            break ;
        case 2 :
            cout << "Song Tu" << endl ;
            break ;
        case 3 :
            cout << "Cu Giai" << endl ;
            break ;
        case 4 :
            cout << "Su Tu" << endl ;
            break ;
        case 5 :
            cout << "Xu Nu" << endl ;
            break ;
        case 6 :
            cout << "Thien Binh" << endl ;
            break ;
        case 7 :
            cout << "Thien Yet" << endl ;
            break ;
        case 8 :
            cout << "Nhan Ma" << endl ;
            break ;
        case 9 :
            cout << "Ma Ket" << endl ;
            break ;
        case 10 :
            cout << "Bao Binh" << endl ;
            break ;
        case 11 :
            cout << "Song Ngu" << endl ;
            break ;
    }
    return 0 ;
}


