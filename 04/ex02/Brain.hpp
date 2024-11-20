#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& B);
		~Brain();

		std::string	getType(int index) const;
		void		setType(int index, const std::string& m_ideas);
};

#endif
