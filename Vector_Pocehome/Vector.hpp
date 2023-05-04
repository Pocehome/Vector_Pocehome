#pragma once
#include "Exception.hpp"

template <class T>
class Vector {
private:
	size_t size;
	T* coords;

public:
	// constructors
	Vector() {		// default constructor
		size = 0;
		coords = nullptr;
	}
	Vector(size_t size) {		// size constructor
		this->size = size;
		this->coords = new T[size];
		for (size_t i = 0; i < size; i++) {
			this->coords[i] = 0;
		}
	}
	Vector(size_t size, T* coords) {		// size and coords constructor
		this->size = size;
		this->coords = new T[size];
		for (size_t i = 0; i < size; i++) {
			this->coords[i] = coords[i];
		}
	}
	Vector(const Vector& vector) {			// copy constructor
		this->size = vector.size;
		this->coords = new T[vector.size];
		for (size_t i = 0; i < vector.size; i++) {
			this->coords[i] = vector.coords[i];
		}
	}

	// destructor
	~Vector() {			// destruct coords
		if (this->coords != nullptr) {
			delete[] this->coords;
		}
	}

	// get & set
	size_t get_size() const {		// get size
		return this->size;
	}
	void set_size(size_t size) {		//set size (and filling new cells 0)
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

	T& get_coord(size_t index) const {		// get coord
		if (this->size <= index) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Out of range: too big index");
		}
		else if (index < 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Out of range: too small index");
		}
		return this->coords[index];
	}
	void set_coord(size_t index, T coord) {		// set cooord
		if (this->size <= index) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Out of range: too big index");
		}
		else if (index < 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Out of range: too small index");
		}
		this->coords[index] = coord;
	}

	// add element
	void add_right_coord(T coord) {			// adding a coordinate to the end of the list
		set_size(this->size + 1);
		this->coords[this->size - 1] = coord;
	}
	void add_left_coord(T coord) {			// adding a coordinate to the start of the list
		set_size(this->size + 1);
		for (size_t i = this->size - 1; i > 0; i--) {
			this->coords[i] = this->coords[i - 1];
		}
		this->coords[0] = coord;
	}

	T& operator[](size_t index) const {			// index operator
		if (this->size <= index) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Out of range: too big index");
		}
		else if (index < 0) {
			throw Exception(__FILE__, __FUNCTION__, __LINE__, "Out of range: too small index");
		}
		return this->coords[index];
	}
	Vector<T>& operator=(const Vector<T>& vector) {			// assignment operator !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		this->size = vector.size;
		if ((vector.size != 0) && (this != &vector)) {
			this->coords = new T[vector.size];
			for (size_t i = 0; i < vector.size; i++) {
				this->coords[i] = vector[i];
			}
		}
		else if (this->size == vector.size) {
			this->coords = nullptr;
		}
		return *this;
	}

	// input/output operators
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector) {		// output operator
		if (vector.size != 0) {
			out << "(";
			for (size_t i = 0; i < vector.size - 1; i++) {
				out << vector[i] << ", ";
			}
			out << vector[vector.size - 1] << ")";
		}
		else {
			;
			out << "size = 0";
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const Vector& vector) {		// input operator
		for (size_t i = 0; i < vector.size; i++) {
			in >> vector[i];
		}
		return in;
	}
};

// comparison operators
template <class T1, class T2>
bool operator==(Vector<T1> vector1, Vector<T2> vector2) {		// equality operator
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
template <class T1, class T2>
bool operator!=(Vector<T1> vector1, Vector<T2> vector2) {		// inequality operator
	if (vector1.get_size() != vector2.get_size()) {
		return true;
	}
	for (size_t i = 0; i < vector1.get_size(); i++) {
		if (vector1.get_coord(i) != vector2.get_coord(i)) {
			return true;
		}
	}
	return false;
}

// Vector + scalar (scalar + vector)
template <class T>
Vector<T> operator+(const Vector<T>& vector, const T& n) {		// operator+ (Vector<T> + T); return Vector<T>
	Vector<T> res(vector.get_size());
	for (size_t i = 0; i < vector.get_size(); i++) {
		res.set_coord(i, vector.get_coord(i) + n);
	}
	return res;
}
template <class T>
Vector<T> operator+(const T& n, const Vector<T>& vector) {		// operator+ (T + Vector<T>); return Vector<T>
	return vector + n;
}

// Vector - scalar
template <class T>
Vector<T> operator-(const Vector<T>& vector, const T& n) {		// operator- (Vector<T> - T); return Vector<T>
	Vector<T> res(vector.get_size());
	for (size_t i = 0; i < vector.get_size(); i++) {
		res.set_coord(i, vector.get_coord(i) - n);
	}
	return res;
}

// Vector * scalar (scalar * Vector)
template <class T>
Vector<T> operator*(const Vector<T>& vector, const T& n) {		// operator* (Vector<T> * T); return Vector<T>
	Vector<T> res(vector.get_size());
	for (size_t i = 0; i < vector.get_size(); i++) {
		res.set_coord(i, vector.get_coord(i) * n);
	}
	return res;
}
template <class T>
Vector<T> operator*(const T& n, const Vector<T>& vector) {		// operator* (T * Vector<T>); return Vector<double>
	return vector * n;
}

// Vector / scalar
template <class T>
Vector<T> operator/(const Vector<T>& vector, const T& n) {		// operator/ (Vector<T> / T); return Vector<T>
	Vector<T> res(vector.get_size());
	for (size_t i = 0; i < vector.get_size(); i++) {
		double vector_coord = vector.get_coord(i);
		res.set_coord(i, vector_coord / n);
	}
	return res;
}

// Vector + Vector
template <class T>
Vector<T> operator+(const Vector<T>& vector1, const Vector<T>& vector2) {		// operator+ (Vector<T> + Vector<T>); return Vector<T>
	if (vector1.get_size() != vector2.get_size()) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Different vector sizes");
	}
	Vector<T> res(vector1.get_size());
	for (size_t i = 0; i < vector1.get_size(); i++) {
		res.set_coord(i, vector1.get_coord(i) + vector2.get_coord(i));
	}
	return res;
}

// Vector - Vector
template <class T>
Vector<T> operator-(const Vector<T>& vector1, const Vector<T>& vector2) {		// operator- (Vector<T> - Vector<T>); return Vector<T>
	if (vector1.get_size() != vector2.get_size()) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Different vector sizes");
	}
	Vector<T> res(vector1.get_size());
	for (size_t i = 0; i < vector1.get_size(); i++) {
		res.set_coord(i, vector1.get_coord(i) - vector2.get_coord(i));
	}
	return res;
}

// Vector * Vector (scalar)
template <class T>
T operator*(const Vector<T>& vector1, const Vector<T>& vector2) {		// operator* (Vector<T> * Vector<T>); return T
	if (vector1.get_size() != vector2.get_size()) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Different vector sizes");
	}
	T res = 0;
	for (size_t i = 0; i < vector1.get_size(); i++) {
		res += vector1.get_coord(i) * vector2.get_coord(i);
	}
	return res;
}

// Vector += Vector
template <class T>
Vector<T>& operator+=(Vector<T>& vector1, const Vector<T>& vector2) {		// operator+= (Vector<T> += Vector<T>); return Vector<T>
	if (vector1.get_size() != vector2.get_size()) {
		throw Exception(__FILE__, __FUNCTION__, __LINE__, "Different vector sizes");
	}
	for (size_t i = 0; i < vector1.get_size(); i++) {
		vector1[i] += vector2[i];
	}
	return vector1;
}

// Vector += scalar
template <class T>
Vector<T>& operator+=(Vector<T>& vector, const T& n) {			// operator+= (Vector<T> += T); return Vector<T>
	for (size_t i = 0; i < vector.get_size(); i++) {
		vector[i] = vector[i] + n;
	}
	return vector;
}

// ++Vector
template<class T>
Vector<T>& operator++(Vector<T>& vector) {		// operator++ (Vector<T> += 1)
	T temp = 1;
	vector += temp;
	return vector;
}

// Vector++
template<class T>
Vector<T>& operator++(Vector<T>& vector, int) {			// operator++ (Vector<T> += 1)
	vector += 1;
	return vector;
}