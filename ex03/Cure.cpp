#include "Cure.hpp"
#include "ICharacter.hpp"

/**
 * @brief Default constructor
 * Initializes Cure with type "cure".
 */
Cure::Cure() : AMateria("cure") {}

/**
 * @brief Copy constructor
 * Creates a copy of an existing Cure.
 * @param other - The Cure object to copy
 */
Cure::Cure(const Cure & other) : AMateria(other) {}

/**
 * @brief Destructor
 */
Cure::~Cure() {}

/**
 * @brief Assignment operator
 * Assigns the state of another Cure to this one.
 * @param other - The Cure object to assign from
 * @return Reference to this Cure
 */
Cure & Cure::operator=(const Cure & other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

/**
 * @brief Clone the Cure
 * Creates a new instance of Cure.
 * @return Pointer to the new Cure instance
 */
AMateria* Cure::clone() const
{
	return new Cure(*this);
}

/**
 * @brief Use the Cure on a target
 * Prints the healing message.
 * @param target - The character to heal
 */
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
