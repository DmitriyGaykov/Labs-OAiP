using namespace std;
bool isProved(string num)
{
	char nums[] = "-0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{   
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && num.size() == 1)
					return false;

				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}

bool isProved(string num, string should_Be)
{
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < should_Be.size(); j++)
		{
			if (num[i] == should_Be[j])
			{
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}

bool isProved(char* num, string should_Be)
{
	bool isNotNum = false;

	for (int i = 0; num[i] != '\0'; i++)
	{
		for (int j = 0; j < should_Be.size(); j++)
		{
			if (num[i] == should_Be[j])
			{
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	return true;
}

bool isProved(string num, int start, int end)
{
	char nums[] = "-0123456789";
	bool isNotNum = false;

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{
				isNotNum = false;
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && num.size() == 1)
					return false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	if (stoi(num) < start || stoi(num) > end)
	{
		return false;
	}

	return true;
}
bool isProved(char* num, int start, int end)
{
	char nums[] = "-0123456789";
	bool isNotNum = false;

	for (int i = 0; num[i] != '\0'; i++)
	{
		for (int j = 0; j < strlen(nums); j++)
		{
			if (num[i] == nums[j])
			{
				if (num[i] == '-' && i != 0)
					return false;
				if (num[i] == '-' && i == 0 && strlen(num) == 1)
					return false;
				isNotNum = false;
				break;
			}
			else
			{
				isNotNum = true;
			}
		}

		if (isNotNum)
		{
			return false;
		}
	}

	if (atoi(num) < start || atoi(num) > end)
	{
		return false;
	}

	return true;
}

void correctFIO(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i + 1; j < strlen(str); j++)
			{
				if (str[j] == ' ')
				{
					for (int k = j; k < strlen(str); k++)
					{
						str[k] = str[k + 1];
					}

					j--;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void correctFIO(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i + 1; j < str.size(); j++)
			{
				if (str[j] == ' ')
				{
					for (int k = j; k < str.size(); k++)
					{
						str[k] = str[k + 1];
					}

					j--;
				}
				else
				{
					break;
				}
			}
		}
	}
}

int CountWord(string str)
{
	int cnt = 0;

	bool isOnlySpace = false;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			isOnlySpace = false;
			break;
		}
		else
		{
			isOnlySpace = true;
		}

	}

	if (isOnlySpace)
	{
		return 0;
	}

	bool isWord = false,
		isSpace = true;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ' && !isWord)
		{
			cnt++;
			isWord = true;
		}
		else if (str[i] == ' ' && isWord)
		{
			isWord = false;
		}
	}

	return cnt;
}

int CountWord(char* str)
{
	int cnt = 0;

	bool isOnlySpace = false;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			isOnlySpace = false;
			break;
		}
		else
		{
			isOnlySpace = true;
		}

	}

	if (isOnlySpace)
	{
		return 0;
	}

	bool isWord = false,
		isSpace = true;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ' && !isWord)
		{
			cnt++;
			isWord = true;
		}
		else if (str[i] == ' ' && isWord)
		{
			isWord = false;
		}
	}

	return cnt;
}

void assignStr(char* str1, char* str2)
{
	for (int i = 0; i <= strlen(str2); i++)
	{
		str1[i] = str2[i];
	}
}

bool checkDate(char* date)
{
	if (strlen(date) != 10)
		return false;

	if (!isProved(date, "1234567890."))
		return false;

	string cash1,
		cash2,
		cash3;

	string day,
		mon,
		year;

	for (int i = 0; i < strlen(date); i++)
	{
		if (i == 0)
		{
			cash1 = date[i];
			cash2 = date[i + 1];
			day = cash1 + cash2;
			cash3 = date[i + 2];

			if (!isProved(day, 1, 30) || cash3 != ".")
				return false;
		}

		else if (i == 3)
		{
			cash1 = date[i];
			cash2 = date[i + 1];
			mon = cash1 + cash2;
			cash3 = date[i + 2];
			if (!isProved(mon, 1, 12) || cash3 != ".")
				return false;
		}

		else if (i == 6)
		{
			cash1 = date[i];
			cash2 = date[i + 1];
			year = cash1 + cash2;
			cash1 = date[i + 2];
			cash2 = date[i + 3];
			year += cash1 + cash2;

			if (!isProved(year, 1900, 2022))
				return false;
		}

	}
	return true;
}