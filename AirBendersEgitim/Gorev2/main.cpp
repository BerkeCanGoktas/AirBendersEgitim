#include <clocale> //for setlocale function
#include <iostream> //for std::cout and std::cin
#include <string> //for std::string

/*
* Chooses the correct case for Turkish versions
* of numbers considering digits and figures.
* @param num -> (int) given number
* @return (std::string) given number in letters
*/
std::string identifyNumber(int num)
{
	bool isTensDigit = num > 9;
	int digit = (isTensDigit) ? num / 10 : num;
	switch (digit)
	{
	case 0:
		return "";
	case 1:
		return (isTensDigit) ? "on" : "bir";
	case 2: 
		return (isTensDigit) ? "yirmi" : "iki";
	case 3:
		return (isTensDigit) ? "otuz" : "üç";
	case 4: 
		return (isTensDigit) ? "kýrk" : "dört";
	case 5: 
		return (isTensDigit) ? "elli" : "beþ";
	case 6: 
		return (isTensDigit) ? "altmýþ" : "altý";
	case 7: 
		return (isTensDigit) ? "yetmiþ" : "yedi";
	case 8:
		return (isTensDigit) ? "seksen" : "sekiz";
	case 9:
		return (isTensDigit) ? "doksan" : "dokuz";
	default:
		std::cerr << "An error occured while number "
					 "identification" << '\n';
		break;
	}
}

/*
* Calculates the correct Turkish interpretation of
* the given number for ones digit
* @param num -> (int) given number
* @return (std::string) given number in letters
*/
std::string calculateOnesDigit(int num)
{
	int ones{ num % 10 };
	return identifyNumber(ones);

}

/*
* Calculates the correct Turkish interpretation of
* the given number for tens digit
* @param num -> (int) given number
* @return (std::string) given number in letters
*/
std::string calculateTensDigit(int num)
{
		int tens{ num % 100 - num % 10};
		return identifyNumber(tens);
}

/*
* Calculates the correct Turkish interpretation of
* the given number for hundreds digit
* @param num -> (int) given number
* @return (std::string) given number in letters
*/
std::string calculateHundredsDigit(int num)
{
	int hundreds{ num / 100 };
	std::string digit = identifyNumber(hundreds);
	if (digit == "")
	{
		return digit;
	}
	else if (digit == "bir")
	{
		return "yüz";
	}
	else
	{
		return digit + "yüz";
	}
}

/*
* Calculates the correct Turkish interpretation of
* the given number
* @param num -> (int) given number
* @return (std::string) given number in letters
*/
std::string transformNumberToLetters(int num)
{
	return calculateHundredsDigit(num) + calculateTensDigit(num) + calculateOnesDigit(num);
}

/*
* Takes input from the user
* @return (float) user input in correct format
*/
int getInput()
{
	while (true)
	{
		int num{};
		std::cin >> num;
		if (!std::cin)
		{
			std::cin.clear();
			std::cerr << "Please enter a valid input and try again!" << '\n';
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if(num > 999)
		{
			std::cin.clear();
			std::cerr << "Please enter a value smaller than 999!" << '\n';
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return num;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish"); //allows the use of Turkish characters in terminal output
	std::cout << "Please enter the number you wish to see in Turkish letters." << '\n';
	std::cout << "The number you entered must be between 0-999!" << '\n';
	int num{ getInput() };
	std::cout << transformNumberToLetters(num) << '\n';
}