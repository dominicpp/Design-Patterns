#include <iostream>

class Singleton
{
public:
	static Singleton& getInstance()
	{
		if (!instance) instance = new Singleton();
		return *instance;
	}

	~Singleton()
	{
		delete instance;
		instance = nullptr;
	}

private:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

void main()
{
	Singleton& singleton = Singleton::getInstance();
	std::cout << "Singleton address: " << &singleton << std::endl;
	std::cin.get();
}