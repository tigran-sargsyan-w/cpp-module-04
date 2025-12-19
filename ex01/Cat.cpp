#include "Cat.hpp"

/**
 * @brief Default constructor for Cat. Sets type to "Cat".
 */
Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "[Cat] default constructor called\n";
}

/**
 * @brief Copy constructor for Cat.
 * @param other The Cat object to copy from.
 */
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
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
    {
        Animal::operator=(other);

        delete brain;
        brain = new Brain(*other.brain);
    }
	return *this;
}

/**
 * @brief Destructor for Cat.
 */
Cat::~Cat()
{
	std::cout << "[Cat] destructor called\n";
	delete brain;
}

/**
 * @brief Makes a sound. Prints "Meow!".
 */
void Cat::makeSound() const
{
	std::cout << "Meow!\n";
}

void Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

const std::string& Cat::getIdea(int index) const
{
    return brain->getIdea(index);
}
