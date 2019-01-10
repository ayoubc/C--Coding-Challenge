#include <bits/stdc++.h> 
using namespace std;
const int N = 100007;
//operation : +, -, x, /.
int priority(string oper){
	int res;
	if(oper == "+" || oper == "-")
	{
		res = 1;
	}
	else if(oper == "*" || oper == "/")
	{
		res = 2;
	}
	else
	{
		res = 0;
	}
	return res;
}
int to_int(string str)
{
	stringstream ss;
	int num;
	ss << str;
	ss >> num;
	return num;
}
string to_string(char c){
	string s = "";
	s += c;
	return s;
}
bool is_digit(char c){
	return c>='0' && c<='9';
}
queue<string> postfix_notation(string expr)
{
	queue<string> rpn;
	stack<string> operators;
	string number = "";
	for(int i=0;i<expr.size();i++){
		if(is_digit(expr[i]))
		{
			number += expr[i];
		}
		else if(expr[i] == '(')
		{
			operators.push(to_string(expr[i]));
		}
		else if(expr[i] == ')'){
			if(number != "")
			{
				rpn.push(number);
				number = "";
			}
			while(!operators.empty()){
				string oper = operators.top();
				operators.pop();
				if(oper == "(")
				{
					break;
				}
				else
				{
					rpn.push(oper);
				}
			}
		}
		else
		{
			if(number != "")
			{
				rpn.push(number);
				number = "";
			}	
			if(operators.empty()){
				operators.push(to_string(expr[i]));
			}
			else
			{
				string oper = operators.top();
				if(priority(to_string(expr[i])) <= priority(oper))
				{
					operators.pop();
					rpn.push(oper);
				}
				operators.push(to_string(expr[i]));
			}
		}
	}
	if(number != "")
	{
		rpn.push(number);
	}
	while(!operators.empty())
	{
		rpn.push(operators.top());
		operators.pop();
	}
	return rpn;
}
int left_to_right_algo(queue<string> Q)
{
	
}
int main()
{
    ifstream cin("input.txt");
    string expression;
    cin >> expression;
    queue<string> rpn = postfix_notation(expression);
    //cout<<Q.size()<<endl;
    
}
