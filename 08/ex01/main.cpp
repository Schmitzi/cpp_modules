#include "Span.hpp"

int main()
{
	try {
		std::cout << "----- Mandatory -----" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const Span::NoSpaceException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const Span::NoSpanException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

	try {
		std::cout << "----- Large -----" << std::endl;
		Span large = Span(214748);
	
		large.fillSpan();
		std::cout << large.shortestSpan() << std::endl;
		std::cout << large.longestSpan() << std::endl;
	}
	catch (const Span::NoSpaceException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const Span::NoSpanException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

	try {
		std::cout << "----- Empty ----- " << std::endl;
		Span empty;
	
		empty.fillSpan();
		std::cout << empty.shortestSpan() << std::endl;
		std::cout << empty.longestSpan() << std::endl;
	}
	catch (const Span::NoSpaceException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const Span::NoSpanException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
	try {
		std::cout << "----- Fill ----- " << std::endl;
		Span fill = Span(42);
	
		fill.fillSpan();
		std::cout << fill.shortestSpan() << std::endl;
		std::cout << fill.longestSpan() << std::endl;
		fill.addNumber(42);
	}
	catch (const Span::NoSpaceException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const Span::NoSpanException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
	return 0;
}
