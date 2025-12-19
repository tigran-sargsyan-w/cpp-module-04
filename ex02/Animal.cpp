#include "Animal.hpp"

/**
 * @brief Default constructor for Animal.
 * Initializes type to "Animal".
 */
Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] default constructor called\n";
}

/**
 * @brief Copy constructor for Animal.
 * @param other The Animal object to copy from.
 */
Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "[Animal] copy constructor called\n";
}

/**
 * @brief Copy assignment operator for Animal.
 * @param other The Animal object to assign from.
 * @return Reference to the assigned Animal object.
 */
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] copy assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

/**
 * @brief Destructor for Animal.
 */
Animal::~Animal()
{
	std::cout << "[Animal] destructor called\n";
}

/**
 * @brief Gets the type of the animal.
 * @return The type of the animal.
 */
std::string Animal::getType() const
{
	return type;
}
