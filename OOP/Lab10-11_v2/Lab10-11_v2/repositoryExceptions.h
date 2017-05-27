#pragma once
#include <exception>
#include <string>


class RepositoryException : public std::exception
{
protected:
	std::string message;

public:
	RepositoryException();
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {}
	virtual const char* what();
};

class DuplicateSongException : public RepositoryException
{
	const char* what();
};