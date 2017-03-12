#include <stdio.h>

// Define a structure for the vector type;
typedef struct
{
	int arr[100];
	int length;
} vector;

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}


/*
	Reads integer numbers until 0 in encountered and stores them to a vector.
	Input: -
	Output: the vector with the read numbers.
*/
vector readNumbers()
{
	vector res;
	res.length = 0;

	int n = -1;

	while (n != 0)
	{
		n = readIntegerNumber("Enter number: ");
		res.arr[res.length++] = n;
	}

	return res;
}

/*
	Computes the sum of all numbers from a vector.
	Input: v - vector of integers
	Output: the sum of all numbers from the vector.
*/
int sum(vector v)
{
	int s = 0;
	for (int i = 0; i < v.length; i++)
		s += v.arr[i];
	return s;
}

/*
	Returns the start and end positions for the longest sequence of equal numbers.
	Input: v - of type vector, vector of integer numbers.
	Output: start, end - pointers to integers containing the positions of the beginning and end for the longest sequence of equal numbers.
*/
vector getLongestEqualNumbersSequencePositions(vector v, int* start, int* end)
{
	*start = 0;
	*end = 0;
	int max_difference = 0;
	int i;
	for (i = 0; i < v.length - 1; i++) {
		int j = i + 1;
		while (j < v.length && v.arr[j] == v.arr[j - 1]) 
			j++;
		if (j - i > max_difference) 
		{
			max_difference = j - i;
			*start = i;
			*end = j - 1;
		}
	}
}

/*
	Reads a vector of integer numbers.
	Input: -
	Output: v - of type vector, the read vector.
*/
vector readVector()
{
	vector v;
	int i = 0;

	v.length = readIntegerNumber("Input the length of the vector: ");
	for (i = 0; i < v.length; i++)
	{
		v.arr[i] = readIntegerNumber("Enter element: ");
	}

	return v;
}

// Prints the elements of a vector between the given positions (start and end).
void printVector(vector v, int start, int end)
{
	int i = 0;
	for (i = start; i <= end; i++)
	{
		printf("%d ", v.arr[i]);
	}
	printf("\n");
}

/*
	Prints the available menu for the problem
	Input: -
	Output: the menu is printed at the console
*/
void printMenu()
{
	printf("1 - to read a list of numbers and compute their sum.\n");
	printf("2 - to compute the longest subsequence of equal numbers from a vector.\n");
	printf("0 - to exit.\n");
}

/*
	Verifies if the given command is valid (is either 1, 2 or 0)
	Input: command - integer
	Output: 1 - if the command is valid
			0 - otherwise

*/
int validCommand(int command)
{
	if (command >= 0 && command <= 2)
		return 1;
	return 0;
}

int main()
{
	int command = -1;

	while (1)
	{
		printMenu();
		command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			vector v = readNumbers();
			printf("The sum of the read numbers is: %d.\n", sum(v));
			break;
		}
		case 2:
		{
			vector v = readVector();
			printf("The longest sequence of equal numbers is:\n");
			int startPos = 0, endPos = 0;
			getLongestEqualNumbersSequencePositions(v, &startPos, &endPos);
			printVector(v, startPos, endPos);
			break;
		}
		}
	}

	return 0;
}
