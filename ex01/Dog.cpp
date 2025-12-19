#include "Dog.hpp"

/**
 * @brief Default constructor for Dog. Sets type to "Dog".
 */
Dog::Dog()
{
	type = "Dog";
	std::cout << "[Dog] default constructor called\n";
}

/**
 * @brief Copy constructor for Dog.
 * @param other The Dog object to copy from.
 */
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] copy constructor called\n";
}

/**
 * @brief Copy assignment operator for Dog.
 * @param other The Dog object to assign from.
 * @return Reference to the assigned Dog object.
 */
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] copy assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

/**
 * @brief Destructor for Dog.
 */
Dog::~Dog()
{
	std::cout << "[Dog] destructor called\n";
}

/**
 * @brief Makes a sound. Prints "Woof!".
 */
void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
