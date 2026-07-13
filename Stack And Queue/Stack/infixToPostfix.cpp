#include <bits/stdc++.h>
using namespace std;


int precedence(char ch){
  if(ch == '^') return 3;
  else if(ch == '*' || ch == '/') return 2;
  else if(ch == '+' || ch == '-') return 1;
  else return -1;
}

string infixToPostFix(string s){
  int i = 0;
  stack<char> st;
  string ans = "";

  while(i < s.length()){
    if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
      ans = ans + s[i];
    }
    else if(s[i] == '('){
      st.push(s[i]);
    }
    else if(s[i] == ')'){
      while(!st.empty() && st.top() != '(' ){
        ans  += st.top();
        st.pop();
      }
      if(!st.empty()){
        st.pop();
      }
    }
    else
    {
      while (!st.empty() && (precedence(st.top()) > precedence(s[i]) ||
(precedence(st.top()) == precedence(s[i]) && s[i] != '^')))
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
  return ans;
}

int main() {
    string s;

    cout << "Enter Infix Expression: ";
    cin >> s;

    cout << "Postfix Expression: " << infixToPostFix(s) << endl;

    return 0;
}