#include "MyFunctions.h"
#include <Novice.h>

/*---関数定義---*/

int Add(const int& a, const int& b)
{
	return a + b;
}

int Subtract(const int& a, const int& b)
{
	return a - b;
}

int Multiply(const int& a, const int& b)
{
	return a * b;
}

int Divide(const int& a, const int& b)
{
	return a / b;
}


float Add(const float& a, const float& b)
{
	return a + b;
}

float Subtract(const float& a, const float& b)
{
	return a - b;
}

float Multiply(const float& a, const float& b)
{
	return a * b;
}

float Divide(const float& a, const float& b)
{
	return a / b;
}


Vector2 Add(const Vector2& a, const Vector2& b)
{
	return{ a.x + b.x,a.y + b.y };
}

Vector2 Subtract(const Vector2& a, const Vector2& b)
{
	return{ a.x - b.x,a.y - b.y };
}

Vector2 Multiply(const Vector2& a, const Vector2& b)
{
	return{ a.x * b.x,a.y * b.y };
}

Vector2 Divide(const Vector2& a, const Vector2& b)
{
	return{ a.x / b.x,a.y / b.y };
}


Vector3 Add(const Vector3& a, const Vector3& b)
{
	return{ a.x + b.x,a.y + b.y,a.z + b.z };
}

Vector3 Subtract(const Vector3& a, const Vector3& b)
{
	return{ a.x - b.x,a.y - b.y,a.z - b.z };
}

Vector3 Multiply(const Vector3& a, const Vector3& b)
{
	return{ a.x * b.x,a.y * b.y,a.z * b.z };
}

Vector3 Multiply(const float& scalar, const Vector3& a)
{
	return{ a.x * scalar,a.y * scalar,a.z * scalar };
}

Vector3 Divide(const Vector3& a, const Vector3& b)
{
	return{ a.x / b.x,a.y / b.y,a.z / b.z };
}

float Dot(Vector3 a, Vector3 b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float Length(Vector3 a)
{
	return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

Vector3 Normalize(Vector3 a)
{
	float length = Length(a);
	Vector3 normalizedVector;

	if (length != 0) {
		normalizedVector.x = a.x / length;
		normalizedVector.y = a.y / length;
		normalizedVector.z = a.z / length;
	}
	else {
		normalizedVector.x = 0;
		normalizedVector.y = 0;
		normalizedVector.z = 0;
	}

	return normalizedVector;
}

void VectorScreenPrintf(int x, int y, const Vector3& a, const char* label)
{
	Novice::ScreenPrintf(x, y, "%.02f", a.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", a.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", a.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}