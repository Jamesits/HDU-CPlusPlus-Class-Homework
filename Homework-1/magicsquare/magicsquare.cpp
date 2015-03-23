// magicsquare.cpp
// generate even dimension magic square 
// by James Swineson. 2015-03-23

#include <iostream>
//#define DEBUG

// generate a 2d array
class SquareMatrix {
private:
	unsigned int dimension; // size is n * n
	int** data;

	// this function prevents label out-of-bound error
	unsigned int formLabel(int n) {
		while (n < 0) n += dimension;
		n = n % dimension;
		return (unsigned int)n;
	}
public:
	// constructor
	SquareMatrix() {
		dimension = 0;
	}

	SquareMatrix(unsigned int n) {
		dimension = n;
		data = new int*[n];
		for (unsigned int i = 0; i < n; i++)
			data[i] = new int[n];
		for (unsigned int i = 0; i < n; i++)
			for (unsigned int j = 0; j < n; j++)
				data[i][j] = 0;
	}

	// deconstructor
	~SquareMatrix() {
		if (dimension != 0) {
			for (unsigned int i = 0; i < dimension; ++i)
				delete[] data[i];
			delete[] data;
		}
	}

	// setter
	void set(int x, int y, int value) {
#ifdef DEBUG
		std::clog << "Set (" << x << ", " << y << ") to " << value << ", ";
#endif
		x = formLabel(x);
		y = formLabel(y);
#ifdef DEBUG
		std::clog << "Real position: (" << x << ", " << y << ")" << std::endl;
#endif
		data[x][y] = value;
	}

	// getter
	int get(int x, int y) {
		x = formLabel(x);
		y = formLabel(y);
		return data[x][y];
	}
};

int main()
{
	unsigned int n;
	std::cout << "Input dimension: ";
	std::cin >> n;
	if (!(n % 2) || n <= 0) {
		std::cerr << "Dimension must be valid even number!" << std::endl;
		return 0;
	}
	SquareMatrix mat(n);
	int currentX = n / 2, currentY = 0;
	for (unsigned int currentNum = 1; currentNum <= n * n; currentNum++) {
		mat.set(currentX, currentY, currentNum);
		if (mat.get(currentX + 1, currentY - 1) != 0) {
#ifdef DEBUG
 			std::clog << "Next blocked square: (" << currentX + 1 << ", " << currentY - 1 << ") = " << mat.get(currentX + 1, currentY - 1) << std::endl;
#endif
			currentY += 1;
		} else {
			currentX += 1;
			currentY -= 1;
		}
	}
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++)
			std::cout << mat.get(j, i) << "\t";
		std::cout << std::endl;
	}
	return 0;
}
