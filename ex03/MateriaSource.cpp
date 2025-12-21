#include "MateriaSource.hpp"

/**
 * @brief Default constructor
 * Initializes MateriaSource with empty memory.
 */
MateriaSource::MateriaSource()
{
	initMemory();
}

/**
 * @brief Copy constructor
 * Creates a deep copy of an existing MateriaSource.
 * @param other - The MateriaSource object to copy
 */
MateriaSource::MateriaSource(const MateriaSource & other)
{
	initMemory();
	copyFrom(other);
}

/**
 * @brief Destructor
 * Cleans up learned materia memory.
 */
MateriaSource::~MateriaSource()
{
	clearMemory();
}

/**
 * @brief Assignment operator
 * Assigns the state of another MateriaSource to this one.
 * @param other - The MateriaSource object to assign from
 * @return Reference to this MateriaSource
 */
MateriaSource & MateriaSource::operator=(const MateriaSource & other)
{
	if (this != &other)
	{
		clearMemory();
		initMemory();
		copyFrom(other);
	}
	return *this;
}

/**
 * @brief Initialize memory slots to NULL
 */
void MateriaSource::initMemory()
{
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

/**
 * @brief Clear memory and delete learned materials
 */
void MateriaSource::clearMemory()
{
	for (int i = 0; i < 4; i++)
	{
		delete memory[i];
		memory[i] = NULL;
	}
}

/**
 * @brief Copy memory from another MateriaSource
 * Helper function for copy constructor and assignment operator.
 * @param other - The source to copy from
 */
void MateriaSource::copyFrom(MateriaSource const & other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.memory[i])
			memory[i] = other.memory[i]->clone();
	}
}

/**
 * @brief Learn a new materia
 * Stores a clone of the materia in the first available slot.
 * @param materia - The materia to learn
 */
void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!memory[i])
		{
			memory[i] = materia->clone();
			delete materia; // We saved a copy, the original is no longer needed.
			return;
		}
	}
	// Memory full: delete incoming, otherwise there will be a leak
	delete materia;
}

/**
 * @brief Create a new materia of a specific type
 * @param type - The type of materia to create
 * @return Pointer to the new materia, or NULL if type is unknown
 */
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] && memory[i]->getType() == type)
			return memory[i]->clone();
	}
	return 0;
}
