#include "Character.hpp"

Character::Character() : name("default")
{
	initInventory();
}

Character::Character(std::string const & name) : name(name)
{
	initInventory();
}

Character::Character(const Character & other) : name(other.name)
{
	initInventory();
	copyFrom(other);
}

Character::~Character()
{
	clearInventory();
}

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

void Character::initInventory()
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
}

void Character::copyFrom(Character const & other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
}

std::string const & Character::getName() const
{
	return name;
}

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

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	// Unequip has to simply set the slot to NULL(no deletion).
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (!inventory[idx])
		return;
	inventory[idx]->use(target);
}
