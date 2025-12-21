#include "Ice.hpp"
#include "ICharacter.hpp"

/**
 * @brief Default constructor
 * Initializes Ice with type "ice".
 */
Ice::Ice() : AMateria("ice") {}

/**
 * @brief Copy constructor
 * Creates a copy of an existing Ice.
 * @param other - The Ice object to copy
 */
Ice::Ice(const Ice & other) : AMateria(other) {}

/**
 * @brief Destructor
 */
Ice::~Ice() {}

/**
 * @brief Assignment operator
 * Assigns the state of another Ice to this one.
 * @param other - The Ice object to assign from
 * @return Reference to this Ice
 */
Ice & Ice::operator=(const Ice & other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

/**
 * @brief Clone the Ice
 * Creates a new instance of Ice.
 * @return Pointer to the new Ice instance
 */
AMateria* Ice::clone() const
{
	return new Ice(*this);
}

/**
 * @brief Use the Ice on a target
 * Prints the ice bolt message.
 * @param target - The character to shoot at
 */
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
