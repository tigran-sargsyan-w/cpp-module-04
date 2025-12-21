#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* memory[4];

		void initMemory();
		void clearMemory();
		void copyFrom(MateriaSource const & other);

	public:
		MateriaSource();
		MateriaSource(const MateriaSource & other);
		virtual ~MateriaSource();

		MateriaSource & operator=(const MateriaSource & other);

		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
