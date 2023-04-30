#include "Vector.hpp"

#define SIZE 5

int main() {
	try {
		int* A_coords = new int[SIZE];
		for (int i = 0; i < SIZE; i++) {
			A_coords[i] = i;
		}

		double C_coords[SIZE] = { 0.0, 1.1, 2.2, 3.3, 4.4 };

		Vector<int> A(SIZE, A_coords);
		Vector<double> C(SIZE, C_coords);
		Vector<int> D(0);
		Vector<int> B = A;

		//std::cin >> D;
		//double mult = C * A;
		A += C;
		A++;
		++C;
		B = D + 4;

		//A.add_left_coord(6);
		//A.set_size(8);
		//A.add_right_coord(5);

		std::cout << "Vector A: " << A << std::endl;
		std::cout << "Vector B: " << B << std::endl;
		std::cout << "Vector C: " << C << std::endl;
		std::cout << "Vector D: " << D << std::endl;

		/*if (B == A) {
			std::cout << A[2] << std::endl;
		}*/
	}
	catch (const std::out_of_range& ex) {
		std::cerr << "Exeption: " << ex.what();
	}
}