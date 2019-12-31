#include <iostream>
#include <stack>

using namespace std;
bool isOperand(char character);
string preToPost(string exp);
string postToPre(string exp);
string preToPostRecursively (string exp,stack <string> postFixExp);
string preToInRecursively(string exp, stack <string> postFixExp);

int main()
{
    string exp;
    stack <string> postFixRecursively;
    cin>>exp;
    cout << "postFix : " <<preToPost(exp)<< endl;
    cout << "postFix recursively : " <<preToPostRecursively(exp,postFixRecursively)<< endl;
    cout << "inFix recursively : " <<preToInRecursively(exp,postFixRecursively)<< endl;
    //cin>>exp;
    //cout << "preFix : "  <<postToPre(exp)<< endl;
    return 0;
}
bool isOperand(char character){
    switch(character){
      case '+':
      case '-':
      case '/':
      case '*':
        return false;
    }
    return true;
}
string preToPost(string exp){
    stack <string>postFixStack;
    int length;
    string firstOperand,secondOperand;
    string temp;
    length = exp.size();
    //Read the Prefix expression in reverse order (from right to left)
    for(int i=length-1 ; i>=0 ; i--){
    //If the symbol is an operand, then push it onto the Stack
    if(isOperand(exp[i])){
        postFixStack.push(string(1,exp[i]));
    }
    else{
    //If the symbol is an operator, then pop two operands from the Stack
        firstOperand  = postFixStack.top(); postFixStack.pop();
        secondOperand = postFixStack.top(); postFixStack.pop();
    //Create a string by concatenating the two operands and the operator after them.
        temp = firstOperand + secondOperand + exp[i];
        postFixStack.push(temp);
    }


    }
return postFixStack.top();

}
string postToPre(string exp){
    stack <string>postFixStack;
    int length;
    string firstOperand,secondOperand;
    string temp;
    length = exp.size();
    //Read the Prefix expression (from left to write)
    for(int i=0 ; i<length ; i++){
    //If the symbol is an operand, then push it onto the Stack
    if(isOperand(exp[i])){
        postFixStack.push(string(1,exp[i]));
    }
    else{
    //If the symbol is an operator, then pop two operands from the Stack
        firstOperand  = postFixStack.top(); postFixStack.pop();
        secondOperand = postFixStack.top(); postFixStack.pop();
    //Create a string by concatenating the two operands and the operator after them.
        temp = exp[i] + secondOperand +firstOperand ;
        postFixStack.push(temp);
    }


    }
return postFixStack.top();

}

string preToPostRecursively(string exp, stack <string> postFixExp){
    int length = exp.size();
    //basecase
        if(length==0){
            string postExp = postFixExp.top();
            postFixExp.pop();
            return postExp;
        }
    string firstOperand,secondOperand;
    string temp;

    //Read the Prefix expression in reverse order (from right to left)
    //If the symbol is an operand, then push it onto the Stack
    if(isOperand(exp[length-1])){
        postFixExp.push(string(1,exp[length-1]));

    }
    else{
    int postFixExplength = postFixExp.size();
    //If the symbol is an operator, then pop two operands from the Stack
        firstOperand  = postFixExp.top();postFixExp.pop();
        secondOperand = postFixExp.top();postFixExp.pop();
    //Create a string by concatenating the two operands and the operator after them.
        temp = firstOperand + secondOperand + exp[length-1];
        postFixExp.push(temp);
    }
return preToPostRecursively(exp.erase(length-1,1),postFixExp);
}
string preToInRecursively(string exp, stack <string> postFixExp){
    int length = exp.size();
    //basecase
        if(length==0)
            return postFixExp.top();
    string firstOperand,secondOperand;
    string temp;

    //Read the Prefix expression in reverse order (from right to left)
    //If the symbol is an operand, then push it onto the Stack
    if(isOperand(exp[length-1])){
        postFixExp.push(string(1,exp[length-1]));

    }
    else{
    int postFixExplength = postFixExp.size();
    //If the symbol is an operator, then pop two operands from the Stack
        firstOperand  = postFixExp.top();postFixExp.pop();
        secondOperand = postFixExp.top();postFixExp.pop();
    //Create a string by concatenating the two operands and the operator after them.
        temp = "("+firstOperand + exp[length-1] + secondOperand +")";
        postFixExp.push(temp);
    }
return preToInRecursively(exp.erase(length-1,1),postFixExp);
}
