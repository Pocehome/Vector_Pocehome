#pragma once
#include <iostream>

template <class T>
class Vector {
private:
	size_t size;
	T* coords;

public:
	// constructors
	Vector() {
		size = 0;
		coords = nullptr;
	}
	Vector(size_t size) {
		this->size = size;
		this->coords = new T[size];
		for (size_t i = 0; i < size; i++) {
			this->coords[i] = 0;
		}
	}
	Vector(size_t size, T* coords) {
		this->size = size;
		this->coords = new T[size];
		for (size_t i = 0; i < size; i++) {
			this->coords[i] = coords[i];
		}
	}
	Vector(const Vector& vector) {
		this->size = vector.size;
		this->coords = new T[vector.size];
		for (size_t i = 0; i < vector.size; i++) {
			this->coords[i] = vector.coords[i];
		}
	}

	// destructor
	~Vector() {
		if (this->coords != nullptr) {
			delete[] this->coords;
		}
	}

	// get & set
	size_t get_size() {
		return this->size;
	}
	void set_size(size_t size) {
		Vector copy(*this);
		this->size = size;
		delete[] this->coords;
		this->coords = new T[size];
		for (size_t i = 0; i < size; i++) {
			if (copy.get_size() - 1 < i) {
				this->coords[i] = 0;
				continue;
			}
			this->coords[i] = copy.coords[i];
		}
	}

	T get_coord(size_t index) {
		return this->coords[index];
	}
	void set_coord(size_t index, T coord) {
		this->coords[index] = coord;
	}

	// add element
	void add_right_coord(T coord) {
		set_size(this->size + 1);
		this->coords[this->size - 1] = coord;
	}
	void add_left_coord(T coord) {
		set_size(this->size + 1);
		for (size_t i = this->size - 1; i > 0; i--) {
			this->coords[i] = this->coords[i - 1];
		}
		this->coords[0] = coord;
	}

	// operators
	const T& operator[](size_t index) const {
		return this->coords[index];
	}
	Vector& operator=(const Vector& vector) {
		return *this;
	}

	// print
	void print_vector() {
		for (size_t i = 0; i < this->size; i++) {
			std::cout << "+---";
		}
		std::cout << "+" << std::endl;

		for (size_t i = 0; i < this->size; i++) {
			std::cout << "| " << this->coords[i] << " ";
		}
		std::cout << "|" << std::endl;

		for (size_t i = 0; i < this->size; i++) {
			std::cout << "+---";
		}
		std::cout << "+" << std::endl;
	}
};

template <class V1, class V2>
bool operator==(Vector<V1> vector1, Vector<V2> vector2) {
	if (vector1.get_size() != vector2.get_size()) {
		return false;
	}
	for (size_t i = 0; i < vector1.get_size(); i++) {
		if (vector1.get_coord(i) != vector2.get_coord(i)) {
			return false;
		}
	}
	return true;
}