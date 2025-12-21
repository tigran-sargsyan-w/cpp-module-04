#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	initMemory();
}

MateriaSource::MateriaSource(const MateriaSource & other)
{
	initMemory();
	copyFrom(other);
}

MateriaSource::~MateriaSource()
{
	clearMemory();
}

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

void MateriaSource::initMemory()
{
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

void MateriaSource::clearMemory()
{
	for (int i = 0; i < 4; i++)
	{
		delete memory[i];
		memory[i] = NULL;
	}
}

void MateriaSource::copyFrom(MateriaSource const & other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.memory[i])
			memory[i] = other.memory[i]->clone();
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!memory[i])
		{
			memory[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] && memory[i]->getType() == type)
			return memory[i]->clone();
	}
	return 0;
}
