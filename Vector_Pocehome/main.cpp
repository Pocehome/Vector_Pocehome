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

		std::cout << "start Vector A: " << A << std::endl;
		std::cout << "start Vector B: " << B << std::endl;
		std::cout << "start Vector C: " << C << std::endl;
		std::cout << "start Vector D: " << D << std::endl;
		std::cout << std::endl;


		//std::cin >> D;
		//double mult = C * A;
		//A += D;		// exception

		A++;
		std::cout << "Vector A++: " << A << std::endl;
		B = A + 4;
		std::cout << "Vector B = A + 4: " << B << std::endl;
		Vector<int> E(SIZE);
		E = B - A;
		std::cout << "Vector E = B - A: " << E << std::endl;
		E = E * 4;
		std::cout << "Vector E = E * 4: " << E << std::endl;
		E = E / 16;
		std::cout << "Vector E = E / 16: " << E << std::endl;

		std::cout << "A * B (scalar) = " << A * B << std::endl;

		D.add_left_coord(6);
		std::cout << "Vector D.add_left_coord(6): " << D << std::endl;
		D.set_size(8);
		std::cout << "Vector D.set_size(8): " << D << std::endl;
		D.add_right_coord(5);
		std::cout << "Vector D.add_right_coord(5): " << D << std::endl;

		std::cout << std::endl;
		std::cout << "finish Vector A: " << A << std::endl;
		std::cout << "finish Vector B: " << B << std::endl;
		std::cout << "finish Vector C: " << C << std::endl;
		std::cout << "finish Vector D: " << D << std::endl;

		std::cout << std::endl;
		if (B != A) {
			std::cout << "A[2] = " << A[2] << std::endl;
		}
	}
	catch (const Exception& ex) {
		std::cout << ex << std::endl;
	}
}