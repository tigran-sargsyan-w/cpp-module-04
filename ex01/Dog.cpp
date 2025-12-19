#include "Dog.hpp"

/**
 * @brief Default constructor for Dog.
 * Sets type to "Dog". Initializes brain.
 */
Dog::Dog() : brain(new Brain())
{
	type = "Dog";
	std::cout << "[Dog] default constructor called\n";
}

/**
 * @brief Copy constructor for Dog.
 * Initializes brain with a deep copy.
 * @param other The Dog object to copy from.
 */
Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "[Dog] copy constructor called\n";
}

/**
 * @brief Copy assignment operator for Dog.
 * Deep copies the brain.
 * @param other The Dog object to assign from.
 * @return Reference to the assigned Dog object.
 */
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] copy assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);

		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

/**
 * @brief Destructor for Dog.
 * Deletes the brain.
 */
Dog::~Dog()
{
	std::cout << "[Dog] destructor called\n";
	delete brain;
}

/**
 * @brief Makes a sound. Prints "Woof!".
 */
void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}

/**
 * @brief Sets an idea in the Dog's brain.
 * @param index The index to set the idea at (0-99).
 * @param idea The idea to set.
 */
void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

/**
 * @brief Gets an idea from the Dog's brain.
 * @param index The index to get the idea from (0-99).
 * @return The idea at the specified index.
 */
const std::string& Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}
