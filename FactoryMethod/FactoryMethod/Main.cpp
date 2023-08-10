#include <iostream>
#include <string>
#include <vector>

// abstract class
class Animal
{
public:
	virtual void makeSound() = 0;
};

// concrete animal class
class Lion : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "Lions Roar\n";
	}
};

// concrete animal class
class Elephant : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "Elephants Trumpet\n";
	}
};

// abstract factory
class EnclosureCreator
{
public:
	virtual Animal* createAnimal() = 0;
};

// concrete enclosure creator for lions
class LionEnclosureCreator : public EnclosureCreator 
{
	Animal* createAnimal() override
	{
		return new Lion();
	}
};

// concrete enclosure creator for elephants
class ElephantEnclosureCreator : public EnclosureCreator
{
	Animal* createAnimal() override
	{
		return new Elephant();
	}
};

int main()
{
	std::vector<EnclosureCreator*> enclosures;

	enclosures.push_back(new LionEnclosureCreator());
	enclosures.push_back(new ElephantEnclosureCreator());

	for (EnclosureCreator* enclosure : enclosures)
	{
		Animal* animal = enclosure->createAnimal();
		animal->makeSound();
		delete animal;
	}

	for (EnclosureCreator* enclosure : enclosures) 
	{
		delete enclosure;
	}

	return 0;
}