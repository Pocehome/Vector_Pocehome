#include "Vector.hpp"

#define SIZE 5

int main() {
	int* A_coords = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		A_coords[i] = i;
	}

	Vector<int> A(SIZE, A_coords);
	Vector<int> B(SIZE, A_coords);
	Vector<double> C(SIZE);
	//A.add_left_coord(6);
	//A.set_size(8);
	//A.add_right_coord(5);
	A.print_vector();
	B.print_vector();
	C.print_vector();
	if (A == C) {
		std::cout << A[2] << std::endl;
	}
}