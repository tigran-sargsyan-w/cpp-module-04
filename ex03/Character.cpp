#include "Character.hpp"

/**
 * @brief Default constructor
 * Initializes Character with default name and empty inventory.
 */
Character::Character() : name("default")
{
	initInventory();
}

/**
 * @brief Parameterized constructor
 * Initializes Character with a specific name.
 * @param name - The name of the character
 */
Character::Character(std::string const & name) : name(name)
{
	initInventory();
}

/**
 * @brief Copy constructor
 * Creates a deep copy of an existing Character.
 * @param other - The Character object to copy
 */
Character::Character(const Character & other) : name(other.name)
{
	initInventory();
	copyFrom(other);
}

/**
 * @brief Destructor
 * Cleans up inventory resources.
 */
Character::~Character()
{
	clearInventory();
}

/**
 * @brief Assignment operator
 * Assigns the state of another Character to this one.
 * @param other - The Character object to assign from
 * @return Reference to this Character
 */
Character & Character::operator=(const Character & other)
{
	if (this != &other)
	{
		name = other.name;
		clearInventory();
		initInventory();
		copyFrom(other);
	}
	return *this;
}

/**
 * @brief Initialize inventory slots to NULL
 */
void Character::initInventory()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

/**
 * @brief Clear inventory and delete materials
 */
void Character::clearInventory()
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
}

/**
 * @brief Copy inventory from another character
 * Helper function for copy constructor and assignment operator.
 * @param other - The character to copy from
 */
void Character::copyFrom(Character const & other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

/**
 * @brief Get the character's name
 * @return The name of the character
 */
std::string const & Character::getName() const
{
	return name;
}

/**
 * @brief Equip a materia into the first available slot
 * @param materia - The materia to equip
 */
void Character::equip(AMateria* materia)
{
	if (!materia)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = materia;
			return;
		}
	}
	// Inventory is full - do nothing (and DO NOT delete materia).
}

/**
 * @brief Unequip a materia from a specific slot
 * Does not delete the materia.
 * @param idx - The index of the slot to unequip
 */
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	// Unequip has to simply set the slot to NULL(no deletion).
	inventory[idx] = NULL;
}

/**
 * @brief Use a materia from a specific slot on a target
 * @param idx - The index of the slot to use
 * @param target - The target character
 */
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (!inventory[idx])
		return;
	inventory[idx]->use(target);
}
