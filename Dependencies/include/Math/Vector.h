#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector		//Vector class to perform vector equations
{
public:
	Vector<T>();							//Default constructor for the Vector class
	Vector<T>(T, T);						//Manual constructor for a 2D Vector class
	Vector<T>(T, T, T);						//Manual constructor for a 3D Vector class
	T x, y, z;								//Creates the x, y, and z variables to represent the x, y, and z values for Vectors
	template <typename T>
	Vector<T> operator+(Vector<T> other)	//Overloads the addition operator to allow for Vectors to be added together
	{
		Vector<T> temp;
		temp.x = x + other.x;
		temp.y = y + other.y;
		temp.z = z + other.z;

		return temp;
	}
	template <typename T>
	Vector<T> operator-(Vector<T> other)	//Overloads the subtraction operator to allow a Vector to subtract the values of another Vector
	{
		Vector<T> temp;
		temp.x = x - other.x;
		temp.y = y - other.y;
		temp.z = z - other.z;

		return temp;
	}
	template <typename T>
	Vector<T> operator*(Vector<T> other)	//Overloads the multiplication operator to allow for Vectors to be multiplied by each other
	{
		Vector<T> temp;
		temp.x = x * other.x;
		temp.y = y * other.y;
		temp.z = z * other.z;

		return temp;
	}
	T magnitude;							//Creates the magnitude variable to hold the value of a Vector's magnitude
	T Magnitude();							//Multiplies the Vector by itself, adds the resulting x, y, & z values together and retrieves the square root of the result to find the magnitude
	Vector<T> Normalize();					//Divides the Vectors x, y, z, & magnitude by it's magnitude and assigns the results to a temporary Vector for assinging the values to a Vector
	T DotProduct(Vector<T>);				//Gets the dot product of two Vectors and stores it in a temporary variable
	Vector<T> CrossProduct(Vector<T>);		//Gets the cross product of two Vectors and stores it in a temporary Vector

private:

};

template <typename T>
Vector<T>::Vector()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

template <typename T>
Vector<T>::Vector(T a, T b)
{
	x = a;
	y = b;
	z = 0.0;
}

template <typename T>
Vector<T>::Vector(T a, T b, T c)
{
	x = a;
	y = b;
	z = c;
}

template <typename T>
T Vector<T>::Magnitude()
{
	Vector<T> temp = *this * *this;
	magnitude = sqrt(temp.x + temp.y + temp.z);

	return magnitude;
}

template <typename T>
Vector<T> Vector<T>::Normalize()
{
	Vector<T> temp;
	temp.x = x / magnitude;
	temp.y = y / magnitude;
	temp.z = z / magnitude;
	temp.magnitude = magnitude / magnitude;

	return temp;
}

template <typename T>
T Vector<T>::DotProduct(Vector<T> other)
{
	T dotprod;
	dotprod = ((x*other.x) + (y*other.y) + (z*other.z));

	return dotprod;
}

template <typename T>
Vector<T> Vector<T>::CrossProduct(Vector<T> other)
{
	Vector<T> temp;
	temp.x = ((y*other.z) - (z*other.y));
	temp.y = ((z*other.x) - (x*other.z));
	temp.z = ((x*other.y) - (y*other.x));
	
	return temp;
}

#endif VECTOR_H