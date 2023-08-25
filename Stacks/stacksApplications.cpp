bool checkinput(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' 
	   || c == '%' || c == '^'||c=='('||c==')')
		return true;
	return false;
}


string postconvertor(string input)
{
	Stack s;
	string output;
	int i = 0;
	try
	{
		while (input[i])
		{
			if (checkinput(input[i]))
			{
				if (s.empty())
				{
					s.push(input[i]);
					i++;
					continue;
				}
				if (input[i] == '(')
				{
					s.push(input[i]);
					i++;
					continue;
				}
				if (input[i] == ')')
				{
					while (s.top() != '(')
					{
						output.push_back(s.top());
						s.pop();
					}
					s.pop();
					i++;
					continue;
				}
				if (prec(input[i]) <= prec(s.top()) && s.top() != '(')
				{
					output.push_back(s.top());
					s.pop();
					s.push(input[i]);
				}
				else
				{
					s.push(input[i]);
				}

			}
			else
			{
				output.push_back(input[i]);
			}
			i++;
		}
		while (!s.empty())
		{
			output.push_back(s.top());
			s.pop();
		}
	}
	catch (const char*msg)
	{
		cout << msg << endl;
	}
	return output;
}	

bool checkinput(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' 
	   || c == '%' || c == '^'||c=='('||c==')')
		return true;
	return false;
}
int prec(char c)
{
	switch (c)
	{
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
	case'%':
		return 2;
	case'^':
		return 3;
	default:
		return 0;
	}
}

string preconvertor(string input)
{
	reverse(input.begin(), input.end());
	input= rep_braces(input, ')', '(');
	input = postconvertor(input);
	reverse(input.begin(), input.end());

	return input;
}

int evaluate(char c, int a, int b)
{
	switch (c)
	{
	case '+':
		return  a + b;
	case '-':
		return  a - b;
	case '*':
		return  a * b;
	case '/':
		return  a / b;
	case '^':
		return  a ^ b;
	case '%':
		return  a % b;
	default:
		return 0;
	}
}


int postevaluation(string input)
{
	Stack s;
	int i = 0;
	try
	{
		while (input[i])
		{
			if (checkinput(input[i]))
			{
				int second = s.top();
				s.pop();
				int first = s.top();
				s.pop();
				int r = evaluate(input[i], first, second);
				s.push(r);
			}
			else
			{
				int p = int(input[i]) - 48;
				s.push(p);
			}
			i++;
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	return s.top();
}

string rep_braces(string str,char r,char rw)
{
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (str[i] == r)
		{
			str[i] = rw;
			continue;
		}
		if (str[i] == rw)
		{
			str[i] = r;
			continue;
		}
	}
	return str;
}