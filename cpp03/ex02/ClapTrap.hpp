#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP


#include <string>


class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	protected:
		ClapTrap(const std::string&, unsigned int, unsigned int, unsigned int);

		const std::string	&_getName() const;
		unsigned int		_getHitPoints() const;
		unsigned int		_getEnergyPoints() const;
		unsigned int		_getAttackDamage() const;
		void				_consumeEnergy();

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		virtual ~ClapTrap();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
