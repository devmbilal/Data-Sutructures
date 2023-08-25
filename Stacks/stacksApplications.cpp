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