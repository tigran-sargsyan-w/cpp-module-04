#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

static void testArrayDeletion()
{
    std::cout << "\n=== Array creation/deletion test ===" << std::endl;

    const int count = 10;
    Animal* animals[count];

    for (int i = 0; i < count; i++)
    {
        if (i < count / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Deleting animals through Animal* ---" << std::endl;
    for (int i = 0; i < count; i++)
        delete animals[i];
}

static void testDeepCopyDog()
{
    std::cout << "\n=== Deep copy test (Dog) ===" << std::endl;

    Dog original;
    original.setIdea(0, "I want a bone");

    Dog copy(original);
    original.setIdea(0, "I want to sleep");

    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;

    Dog assigned;
    assigned = original;
    original.setIdea(0, "Changed again");

    std::cout << "Assigned idea[0]: " << assigned.getIdea(0) << std::endl;
    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
}

static void testDeepCopyCat()
{
    std::cout << "\n=== Deep copy test (Cat) ===" << std::endl;

    Cat original;
    original.setIdea(0, "I rule this house");

    Cat copy = original;
    original.setIdea(0, "Actually, I rule the universe");

    std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
    std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;
}

int main()
{
    testArrayDeletion();
    testDeepCopyDog();
    testDeepCopyCat();

    std::cout << "\n=== Done ===" << std::endl;
    return 0;
}
