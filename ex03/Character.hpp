#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];

		void initInventory();
		void clearInventory();
		void copyFrom(Character const & other);

	public:
		Character();
		Character(std::string const & name);
		Character(const Character & other);
		virtual ~Character();

		Character & operator=(const Character & other);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* materia);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
