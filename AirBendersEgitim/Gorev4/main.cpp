#include <iostream> //for std::cout
#include <string>  //for std::string

struct Province;
/*
* Data type for holding country informations
* name and capital.
* @var name -> (std::string) name of the country
* @var capital -> (Province*) struct for capital
*/
struct Country
{
	std::string name{ "" };
	Province* capital;
};

/*
* Data type for holding province informations
* name and capital.
* @var name -> (std::string) name of the province
* @var domain -> (Country*) struct for domain
*/
struct Province
{
	std::string name{ "" };
	Country* domain;
};

int main()
{
	Province ankara{ "Ankara" };
	Country turkey{ "Türkiye", &ankara };
	ankara.domain = &turkey;
	Province istanbul{ "istanbul", &turkey };
	std::cout << "Capital of Istanbul's domain: " 
			  << istanbul.domain->capital->name << '\n';
}