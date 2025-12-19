#include "WrongCat.hpp"

/**
 * @brief Default constructor for WrongCat. Sets type to "WrongCat".
 */
WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "[WrongCat] default constructor called\n";
}

/**
 * @brief Copy constructor for WrongCat.
 * @param other The WrongCat object to copy from.
 */
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "[WrongCat] copy constructor called\n";
}

/**
 * @brief Copy assignment operator for WrongCat.
 * @param other The WrongCat object to assign from.
 * @return Reference to the assigned WrongCat object.
 */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] copy assignment operator called\n";
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

/**
 * @brief Destructor for WrongCat.
 */
WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called\n";
}

/**
 * @brief Makes a sound. Prints a confusing meow.
 */
void WrongCat::makeSound() const
{
	std::cout << "Meeeow? (but you won't hear this through WrongAnimal*) \n";
}
