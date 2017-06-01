#pragma once
#include "domain.h"
#include <string>
#include <vector>

class CoatExceptions
{
private:
	std::vector<std::string> errors;

public:
	CoatExceptions(std::vector<std::string> _errors) : errors{ _errors } {}
	std::vector<std::string> getErrors() const {
		return this->errors;
	}
	std::string getErrorsAsString() const
	{
		std::string err;
		for (auto e : this->errors)
			err += e;
		return err;
	}
	
};


class CoatValidator {

public:

	void validate(Coat x) {
		std::vector<std::string> errors;
		
		if (x.get_price() < 0)
			errors.push_back("Price should be a Natural number\n");
		if (x.get_size() < 0)
			errors.push_back("Size should be a Natural number\n");
		if (x.get_quantity() <= 0)
			errors.push_back("Quantity should be > 0\n");

		if (errors.size() > 0)
			throw  CoatExceptions(errors);
	}
	


};