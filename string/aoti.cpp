#include <bits/stdc++.h>
using namespace std;
/*
Write the atoi() function (ASCII to Integer) similar to the one available in the C language.

The function should convert a numeric string into an integer value.

Examples:-
    "42"         -> 42
    "-42"        -> -42
    "1445and90"  -> 1445
    "0-9"        -> 0
*/

int myAtoi(string s){
  int i = 0;
  int n = s.length();

  while (i<n && s[i] == ' ')
    i++;

  int sign = 1;
  if(i < n && (s[i] == '+' || s[i] == '-')){
    if(s[i]== '-')
    sign = -1;
  i++;
  }
  long long num = 0;

    while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');

        if (sign * num > INT_MAX)
            return INT_MAX;
        if (sign * num < INT_MIN)
            return INT_MIN;

        i++;
    }

    return sign * num;
}

int main() {
    vector<string> testCases = {
        "42",
        "-42",
        "1445and90",
        "0-9",
        "words123",
        "2147483648"
    };

    for (string s : testCases) {
        cout << "\"" << s << "\" -> "
             << myAtoi(s) << endl;
    }

    return 0;
}
