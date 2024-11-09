#include "sed2.hpp"

std::string ft_replace(const std::string &line, const std::string &old_str, 
						const std::string &new_str) {
    std::string res;
    size_t start = 0;
    size_t pos;

    while ((pos = line.find(old_str, start)) != std::string::npos) {
        res += line.substr(start, pos - start);
        res += new_str;
        start = pos + old_str.length();
    }
    res += line.substr(start);
    return res;
}

std::string	make_outfile(std::string str) {
	int end = 0;

	for ( ; str[end]; end++) {
		if (str[end] == '.')
			break ;
	}
	return (str.substr(0, end) + ".replace");
}

int main(int ac, char **av) {

	if (ac != 4) {
		std::cerr << "Bad arguments ./sed2 <filename> <old> <new>" << std::endl;
		return 1;
	}

	std::string line;
	std::ifstream inFile(av[1]);
	if (!inFile.is_open()) { 
        std::cerr << "Error: Infile does not exist or has bad permissions" << std::endl; 
        return 1; 
    }

	std::ofstream outFile(make_outfile(av[1]).c_str());
	if (!outFile.is_open()) { 
        std::cerr << "Error: Outfile creation failed" << std::endl; 
        return 1; 
    }

    while (std::getline(inFile, line)) {
        std::string new_line = ft_replace(line, av[2], av[3]);
        outFile << new_line << '\n';
    }
	
	inFile.close();
	outFile.close();
	return 0;
}