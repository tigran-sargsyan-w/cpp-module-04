#include "AMateria.hpp"

/**
 * @brief Default constructor
 * Initializes AMateria with default type.
 */
AMateria::AMateria() : type("default") {}

/**
 * @brief Parameterized constructor
 * Initializes AMateria with a specific type.
 * @param type - The type of the materia
 */
AMateria::AMateria(std::string const & type) : type(type) {}

/**
 * @brief Copy constructor
 * Creates a copy of an existing AMateria.
 * @param other - The AMateria object to copy
 */
AMateria::AMateria(const AMateria & other)
{
	*this = other;
}

/**
 * @brief Destructor
 */
AMateria::~AMateria() {}

/**
 * @brief Assignment operator
 * Assigns the values of another AMateria to this one.
 * @param other - The AMateria object to assign from
 * @return Reference to this AMateria
 */
AMateria & AMateria::operator=(const AMateria & other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

/**
 * @brief Get the type of the materia
 * @return The type of the materia as a string reference
 */
std::string const & AMateria::getType() const
{
	return this->type;
}

/**
 * @brief Use the materia on a target character
 * Base implementation does nothing.
 * @param target - The character to use the materia on
 */
void AMateria::use(ICharacter& target)
{
	(void)target;
}
