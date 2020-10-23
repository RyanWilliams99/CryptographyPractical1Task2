#include <ctype.h>      // For isalnum()
#include <iostream>     // For console output
#include <string>       // For std::string
#include <vector>       // For std::vector
using namespace std;

vector<char> split(const string& str)
{
	vector<char> result;

	// For each character in the string
	for (char ch : str)
	{
		// Copy only alphabetical characters and numeric digits
		if (isalnum(ch))
		{
			result.push_back(ch);
		}
	}

	return result;
}

int GetISBNSum(vector<char> isbn)
{
	int sum = 0;

	if (isbn[9] == 'x' || isbn[9] == 'X')
	{
		sum += (isbn[0] - '0');
		sum += 2 * (isbn[1] - '0');
		sum += 3 * (isbn[2] - '0');
		sum += 4 * (isbn[3] - '0');
		sum += 5 * (isbn[4] - '0');
		sum += 6 * (isbn[5] - '0');
		sum += 7 * (isbn[6] - '0');
		sum += 8 * (isbn[7] - '0');
		sum += 9 * (isbn[8] - '0');

	}
	else
	{
		sum += (isbn[0] - '0');
		sum += 2 * (isbn[1] - '0');
		sum += 3 * (isbn[2] - '0');
		sum += 4 * (isbn[3] - '0');
		sum += 5 * (isbn[4] - '0');
		sum += 6 * (isbn[5] - '0');
		sum += 7 * (isbn[6] - '0');
		sum += 8 * (isbn[7] - '0');
		sum += 9 * (isbn[8] - '0');
		sum += 10 * (isbn[9] - '0');

	}

	return sum;
}


bool validate(vector<char> isbn)
{
	int sum, checkValue;

	if (isbn.size() != 10)
		return false;

	sum = GetISBNSum(isbn);

	checkValue = 0;

	if (isbn[9] == 'x' || isbn[9] == 'X')
		checkValue = 10;
	else
		checkValue = isbn[9] - '0';


	cout << "Sum of isbn: " << sum << " " << endl;
	cout << "Sum of isbn mod 11: " << sum % 11 << " " << endl;
	cout << "To be valid must equal " << checkValue << " or 0 " << endl;


	if (sum % 11 == 0) //Dont use check digit
	{
		return true;
	}
	if (sum % 11 == checkValue) //use check digit
	{
		return true;
	}


	return false;
}


int main()
{

	while (true)
	{
		string s;
		cout << "Enter ISBN: ";
		getline(cin, s);
		vector<char> result = split(s);


		if (validate(result))
		{
			cout << "Valid ISBN" << "\n" << "-------------------------------------------" << "\n";
		}
		else
		{
			cout << "Invalid ISBN" << "\n" << "-------------------------------------------" << "\n";
		}

		/*cout << "{ ";
		for (char ch : result)
		{
			cout << "'" << ch << "' ";
		}
		cout << "}" << endl;*/
	}

}
