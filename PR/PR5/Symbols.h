#pragma once
class Symbols
{
	int rows_length, columns_length;
	char **matrix;
	
	void create(int rows_size, int columns_size);
	void create(char***matrix,int rows_size, int columns_size);
	void delete_matrix();
	void copy_from(char** matrix2);//copy value of this->matrix to matrix2 
	void copy_to(char**matrix2);//copy value of matrix2 to this->matrix
	void resize(int rows_size, int columns_size);//change size of matrix on rows_size and columns_size
	void displacment(int, int) {};
public:
	Symbols(int, int = 0);
	const char get(int rows_index, int colummns_index = 0);
	void add(char symbol, int rows_index, int colummns_index = 0);
	void add(char*, int,int,int);
	~Symbols();
};

