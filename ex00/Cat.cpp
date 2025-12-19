#include "Cat.hpp"

/**
 * @brief Default constructor for Cat. Sets type to "Cat".
 */
Cat::Cat()
{
	type = "Cat";
	std::cout << "[Cat] default constructor called\n";
}

/**
 * @brief Copy constructor for Cat.
 * @param other The Cat object to copy from.
 */
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "[Cat] copy constructor called\n";
}

/**
 * @brief Copy assignment operator for Cat.
 * @param other The Cat object to assign from.
 * @return Reference to the assigned Cat object.
 */
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] copy assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

/**
 * @brief Destructor for Cat.
 */
Cat::~Cat()
{
	std::cout << "[Cat] destructor called\n";
}

/**
 * @brief Makes a sound. Prints "Meow!".
 */
void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}
