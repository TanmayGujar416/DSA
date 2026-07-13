#include <bits/stdc++.h>
using namespace std;


int precedence(char ch){
  if(ch == '^') return 3;
  else if(ch == '*' || ch == '/') return 2;
  else if(ch == '+' || ch == '-') return 1;
  else return -1;
}

string infixToPrefix(string s){
  reverse(s.begin(), s.end());
  stack<char> st;
  int i = 0;
  string ans = "";
  while(i < s.length()){
    if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ) {
      ans+= s[i];
    }
    else if(s[i] == ')'){
      st.push(s[i]);
    }
    else if(s[i] == '('){
      while(!st.empty() && st.top() != ')'){
        ans += st.top();
        st.pop();
      }
      if(!st.empty()){
        st.pop();
      }
    }
    else{
      while (!st.empty() &&
       (precedence(st.top()) > precedence(s[i]) ||
       (precedence(st.top()) == precedence(s[i]) && s[i] == '^')))
      {
          ans += st.top();
          st.pop();
      }
      st.push(s[i]);
    }
    i++;
  }
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;

}

// int main() {
//     string s;

//     cout << "Enter Infix Expression: ";
//     cin >> s;

//     cout << "Pretfix Expression: " << infixToPrefix(s) << endl;

//     return 0;
// }


int main() {
    vector<string> testCases = {
        "A+B",
        "A-B",
        "A*B",
        "A/B",
        "A^B",

        "A+B*C",
        "A*B+C",
        "A*B/C",
        "A+B-C",
        "A+B*C-D",

        "(A+B)",
        "(A+B)*C",
        "A*(B+C)",
        "(A+B)*(C+D)",
        "A+B*(C+D)",
        "(A+B*C)",
        "((A+B))",

        "A+B*C-D/E",
        "(A+B)*(C-D)",
        "(A+B)/(C-D)",
        "A*(B+C*D)",
        "(A+B*C)-(D/E)",

        "A^B^C",
        "(A^B)^C",
        "A^(B^C)",

        "((A+B)*(C-D))/E",
        "A+(B*C-(D/E^F)*G)*H"
    };

    cout << left << setw(30) << "Infix"
         << "Prefix\n";
    cout << string(60, '-') << "\n";

    for (const string &exp : testCases) {
        cout << left << setw(30) << exp
             << infixToPrefix(exp) << "\n";
    }

    return 0;
}