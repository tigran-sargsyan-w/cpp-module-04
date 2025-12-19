#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
 * @brief Main function. Tests Animal polymorphism and WrongAnimal behavior.
 * @return 0 on success.
 */
int main()
{
	std::cout << "\n==== Subject-like polymorphism test ====\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << "\n";
	std::cout << i->getType() << "\n";
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

    std::cout << "\n==== Animal copy tests ====\n";
	Dog a;
	Dog b(a);
	Dog c;
	c = a;
	a.makeSound();
	b.makeSound();
	c.makeSound();

    std::cout << "\n==== WrongAnimal test (no virtual makeSound) ====\n";
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << wa->getType() << "\n";
	std::cout << wc->getType() << "\n";
	wa->makeSound();
	wc->makeSound(); // <-- it will call WrongAnimal's makeSound, not WrongCat's

	delete wc;
	delete wa;
    
    std::cout << "\n==== Stack objects (destruction order visible) ====\n";
    Animal x;
    Cat y;
    Dog z;
    x.makeSound();
    y.makeSound();
    z.makeSound();

	return 0;
}
