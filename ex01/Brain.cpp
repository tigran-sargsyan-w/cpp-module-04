#include "Brain.hpp"
#include <iostream>

/**
 * @brief Default constructor for Brain.
 */
Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Brain.
 * @param other The Brain object to copy from.
 */
Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

/**
 * @brief Copy assignment operator for Brain.
 * @param other The Brain object to assign from.
 * @return Reference to the assigned Brain object.
 */
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

/**
 * @brief Destructor for Brain.
 */
Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

/**
 * @brief Sets an idea at the specified index.
 * @param index The index to set the idea at (0-99).
 * @param idea The idea to set.
 */
void Brain::setIdea(int index, const std::string& idea)
{
    if (index < 0 || index >= 100)
        return;
    ideas[index] = idea;
}

/**
 * @brief Gets the idea at the specified index.
 * @param index The index to get the idea from (0-99).
 * @return The idea at the specified index.
 */
const std::string& Brain::getIdea(int index) const
{
    static const std::string empty = "";
    if (index < 0 || index >= 100)
        return empty;
    return ideas[index];
}
