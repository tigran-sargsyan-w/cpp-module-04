#include "WrongAnimal.hpp"

/**
 * @brief Default constructor for WrongAnimal.
 * Initializes type to "WrongAnimal".
 */
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "[WrongAnimal] default constructor called\n";
}

/**
 * @brief Copy constructor for WrongAnimal.
 * @param other The WrongAnimal object to copy from.
 */
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "[WrongAnimal] copy constructor called\n";
}

/**
 * @brief Copy assignment operator for WrongAnimal.
 * @param other The WrongAnimal object to assign from.
 * @return Reference to the assigned WrongAnimal object.
 */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] copy assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

/**
 * @brief Destructor for WrongAnimal.
 */
WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor called\n";
}

/**
 * @brief Gets the type of the wrong animal.
 * @return The type of the wrong animal.
 */
std::string WrongAnimal::getType() const
{
	return type;
}

/**
 * @brief Makes a sound. Prints a wrong generic sound.
 */
void WrongAnimal::makeSound() const
{
	std::cout << "* wrong generic sound *\n";
}
