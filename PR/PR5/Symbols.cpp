#include "Symbols.h"


void Symbols::create(int i, int j)
{
	this->matrix = new char*[i];
	for (int k = 0; k < i; k++)
		this->matrix[k] = new char[i];
}

void Symbols::create(char ***matrix, int rows_length, int columns_length)
{
	matrix[0] = new char*[this->rows_length];
	for (int k = 0; k < this->rows_length; k++)
	{
		matrix[0][k] = new char[this->columns_length];
	}
}

void Symbols::delete_matrix()
{
	for (int i = 0; i < this->rows_length; i++)
	{
		delete [] this->matrix[i];
	}
}

void Symbols::copy_from(char ** matrix2)
{
	for (int i = 0; i < this->rows_length; i++)
	{
		for (int j = 0; j < this->columns_length; j++)
		{
			matrix2[i][j] = this->matrix[i][j];
		}
	}
}

void Symbols::copy_to(char ** matrix2)
{
	for (int i = 0; i < this->rows_length; i++)
	{
		for (int j = 0; j < this->columns_length; j++)
		{
			 this->matrix[i][j]=matrix2[i][j] ;
		}
	}
}

void Symbols::resize(int i, int j)
{
	char **temp;
	this->create(&temp, this->rows_length, this->columns_length);
	this->copy_from(temp);
	
}

Symbols::Symbols(int i, int j):rows_length{i},columns_length{j}
{
	this->create(i, j);
}

const char Symbols::get(int i, int j)
{
	return this->matrix[i][j];
}

void Symbols::add(char symbol, int i, int j)
{
	this->resize(++this->columns_length,++this->rows_length);
	this->displacment(i, j);
	this->matrix[i][j] = symbol;
}

Symbols::~Symbols()
{
}
