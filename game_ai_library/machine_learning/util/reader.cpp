#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::ifstream trainDataFile(argv[1], std::ios::in | std::ios::binary);
	char data;
	std::cout << sizeof(data) << std::endl;

	std::string trash;
	size_t counter = 0;
	size_t loopCounter = 0;
	while (!trainDataFile.eof())
	{
		trainDataFile.read(&data, 1);
		if (trainDataFile.fail())
		{
			if (trainDataFile.eof())
			{
				break;
			}
			trainDataFile.clear();
			trainDataFile >> trash;
		}
		else
		{
			++counter;
		}
		++loopCounter;
	}

	std::cout << counter << " ~ " << loopCounter << std::endl;

	trainDataFile.close();

	return 0;
}