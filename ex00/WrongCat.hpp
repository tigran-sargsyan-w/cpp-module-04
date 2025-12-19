#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        virtual ~WrongCat();

        // Trying to "override", but base function is not virtual → no polymorphism
        void makeSound() const;
};

#endif
