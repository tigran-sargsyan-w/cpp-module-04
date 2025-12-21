#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

static void subjectTest()
{
	std::cout << "\n--- Subject tests ---" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

static void extraTests()
{
	std::cout << "\n--- Extra tests ---" << std::endl;

	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());
	// If there is no delete inside learnMateria on overflow -> will be leak
	src.learnMateria(new Ice());

	Character a("Alice");
	Character b("Bob");

	AMateria* m0 = src.createMateria("ice");
	AMateria* m1 = src.createMateria("cure");
	AMateria* m2 = src.createMateria("ice");
	AMateria* m3 = src.createMateria("cure");
	AMateria* m4 = src.createMateria("ice");

	a.equip(m0);
	a.equip(m1);
	a.equip(m2);
	a.equip(m3);
	a.equip(m4); // won't fit -> must be deleted manually
	delete m4;

	a.use(0, b);
	a.use(1, b);

	// Deep copy Character
	Character copy(a);
	a.unequip(0); // NOT delete - just clear the slot (m0 would leak if we didn't save it)
	// We saved m0 earlier, so we can delete it manually:
	delete m0;

	std::cout << "Copy Use" << std::endl;
	// In the copy everything should work, since clone() -> deep copy
	copy.use(0, b);
	copy.use(1, b);

	// Unknown materia
	AMateria* unknown = src.createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia: OK (returned 0)" << std::endl;
}

static void abstractAndDeleteTest()
{
	std::cout << "\n--- Abstract and delete test ---" << std::endl;

	// These lines should NOT compile (interfaces/abstractions):
	// AMateria x("x");
	// ICharacter y;
	// IMateriaSource z;

	AMateria* ice = new Ice();
	std::cout << "Ptr of ice before delete: \t" << ice << std::endl;
	// When you delete a pointer in C++, two main things happen:
	// 1. calls destructors (Ice,then AMateria)
	// 2. Free memory(returns to OS the allocated block)
	delete ice; 
	// But the pointer variable 'p' itself still exists in the scope
	// and holds the same address value as before deletion,
	// although that memory is no longer valid to use.
	std::cout << "Ptr of ice after delete: \t" << ice << std::endl;
	// Always set dangling pointers to NULL after deletion to avoid undefined behavior
	ice = NULL;
	if (!ice)
		std::cout << "ice is NULL, safe to exit" << std::endl;
	else
		std::cout << "ice is NOT NULL, but dangling pointer!" << std::endl;
}

int main()
{
	subjectTest();
	extraTests();
	abstractAndDeleteTest();

	return 0;
}
