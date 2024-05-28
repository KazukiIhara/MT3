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

	if (length != 0)
	{
		normalizedVector.x = a.x / length;
		normalizedVector.y = a.y / length;
		normalizedVector.z = a.z / length;
	}
	else
	{
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

Matrix4x4 Add(const Matrix4x4& a, const Matrix4x4& b)
{
	return
	{
		a.m[0][0] + b.m[0][0] ,a.m[0][1] + b.m[0][1] ,a.m[0][2] + b.m[0][2] ,a.m[0][3] + b.m[0][3] ,
		a.m[1][0] + b.m[1][0] ,a.m[1][1] + b.m[1][1] ,a.m[1][2] + b.m[1][2] ,a.m[1][3] + b.m[1][3] ,
		a.m[2][0] + b.m[2][0] ,a.m[2][1] + b.m[2][1] ,a.m[2][2] + b.m[2][2] ,a.m[2][3] + b.m[2][3] ,
		a.m[3][0] + b.m[3][0] ,a.m[3][1] + b.m[3][1] ,a.m[3][2] + b.m[3][2] ,a.m[3][3] + b.m[3][3] ,
	};
}

Matrix4x4 Subtract(const Matrix4x4& a, const Matrix4x4& b)
{
	return
	{
		a.m[0][0] - b.m[0][0] ,a.m[0][1] - b.m[0][1] ,a.m[0][2] - b.m[0][2] ,a.m[0][3] - b.m[0][3] ,
		a.m[1][0] - b.m[1][0] ,a.m[1][1] - b.m[1][1] ,a.m[1][2] - b.m[1][2] ,a.m[1][3] - b.m[1][3] ,
		a.m[2][0] - b.m[2][0] ,a.m[2][1] - b.m[2][1] ,a.m[2][2] - b.m[2][2] ,a.m[2][3] - b.m[2][3] ,
		a.m[3][0] - b.m[3][0] ,a.m[3][1] - b.m[3][1] ,a.m[3][2] - b.m[3][2] ,a.m[3][3] - b.m[3][3] ,
	};
}

Matrix4x4 Multiply(const float& scalar, const Matrix4x4& a)
{
	return
	{
		a.m[0][0] * scalar ,a.m[0][1] * scalar ,a.m[0][2] * scalar ,a.m[0][3] * scalar ,
		a.m[1][0] * scalar ,a.m[1][1] * scalar ,a.m[1][2] * scalar ,a.m[1][3] * scalar ,
		a.m[2][0] * scalar ,a.m[2][1] * scalar ,a.m[2][2] * scalar ,a.m[2][3] * scalar ,
		a.m[3][0] * scalar ,a.m[3][1] * scalar ,a.m[3][2] * scalar ,a.m[3][3] * scalar ,
	};
}

Matrix4x4 Multiply(const Matrix4x4& a, const Matrix4x4& b)
{
	return
	{
		a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0] + a.m[0][2] * b.m[2][0] + a.m[0][3] * b.m[3][0],		a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1] + a.m[0][2] * b.m[2][1] + a.m[0][3] * b.m[3][1],		a.m[0][0] * b.m[0][2] + a.m[0][1] * b.m[1][2] + a.m[0][2] * b.m[2][2] + a.m[0][3] * b.m[3][2],		a.m[0][0] * b.m[0][3] + a.m[0][1] * b.m[1][3] + a.m[0][2] * b.m[2][3] + a.m[0][3] * b.m[3][3],
		a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0] + a.m[1][2] * b.m[2][0] + a.m[1][3] * b.m[3][0],		a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1] + a.m[1][2] * b.m[2][1] + a.m[1][3] * b.m[3][1],		a.m[1][0] * b.m[0][2] + a.m[1][1] * b.m[1][2] + a.m[1][2] * b.m[2][2] + a.m[1][3] * b.m[3][2],		a.m[1][0] * b.m[0][3] + a.m[1][1] * b.m[1][3] + a.m[1][2] * b.m[2][3] + a.m[1][3] * b.m[3][3],
		a.m[2][0] * b.m[0][0] + a.m[2][1] * b.m[1][0] + a.m[2][2] * b.m[2][0] + a.m[2][3] * b.m[3][0],		a.m[2][0] * b.m[0][1] + a.m[2][1] * b.m[1][1] + a.m[2][2] * b.m[2][1] + a.m[2][3] * b.m[3][1],		a.m[2][0] * b.m[0][2] + a.m[2][1] * b.m[1][2] + a.m[2][2] * b.m[2][2] + a.m[2][3] * b.m[3][2],		a.m[2][0] * b.m[0][3] + a.m[2][1] * b.m[1][3] + a.m[2][2] * b.m[2][3] + a.m[2][3] * b.m[3][3],
		a.m[3][0] * b.m[0][0] + a.m[3][1] * b.m[1][0] + a.m[3][2] * b.m[2][0] + a.m[3][3] * b.m[3][0],		a.m[3][0] * b.m[0][1] + a.m[3][1] * b.m[1][1] + a.m[3][2] * b.m[2][1] + a.m[3][3] * b.m[3][1],		a.m[3][0] * b.m[0][2] + a.m[3][1] * b.m[1][2] + a.m[3][2] * b.m[2][2] + a.m[3][3] * b.m[3][2],		a.m[3][0] * b.m[0][3] + a.m[3][1] * b.m[1][3] + a.m[3][2] * b.m[2][3] + a.m[3][3] * b.m[3][3],

	};
}

Matrix4x4 Inverse(const Matrix4x4& a)
{
	Matrix4x4 A = a;
	Matrix4x4 B = MakeIdentity4x4();

	int i, j, k;
	for (i = 0; i < 4; ++i)
	{
		float scale = 1.0f / A.m[i][i];
		for (j = 0; j < 4; ++j)
		{
			A.m[i][j] *= scale;
			B.m[i][j] *= scale;
		}
		for (k = 0; k < 4; ++k)
		{
			if (k != i)
			{
				float factor = A.m[k][i];
				for (j = 0; j < 4; ++j)
				{
					A.m[k][j] -= factor * A.m[i][j];
					B.m[k][j] -= factor * B.m[i][j];
				}
			}
		}
	}

	return B;
}

Matrix4x4 Transpose(const Matrix4x4& a)
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = a.m[j][i];
		}
	}
	return result;
}

Matrix4x4 MakeIdentity4x4()
{
	Matrix4x4 identity{};
	identity.m[0][0] = 1.0f; identity.m[0][1] = 0.0f; identity.m[0][2] = 0.0f; identity.m[0][3] = 0.0f;
	identity.m[1][0] = 0.0f; identity.m[1][1] = 1.0f; identity.m[1][2] = 0.0f; identity.m[1][3] = 0.0f;
	identity.m[2][0] = 0.0f; identity.m[2][1] = 0.0f; identity.m[2][2] = 1.0f; identity.m[2][3] = 0.0f;
	identity.m[3][0] = 0.0f; identity.m[3][1] = 0.0f; identity.m[3][2] = 0.0f; identity.m[3][3] = 1.0f;
	return identity;
}

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label)
{
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			Novice::ScreenPrintf
			(
				x + column * kColumnWidth, y + (row + 1) * kRowHeight, "%6.02f", matrix.m[row][column]
			);
		}
	}
	Novice::ScreenPrintf(x, y, "%s", label);
}

Matrix4x4 MakeTranslateMatrix(const Vector3& translate)
{
	Matrix4x4 result = {
	   { 1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f ,
		0.0f, 0.0f, 1.0f, 0.0f ,
	   translate.x,translate.y, translate.z, 1.0f}
	};
	return result;
}

Matrix4x4 MakeScaleMatrix(const Vector3& scale)
{
	Matrix4x4 result = {
		{scale.x, 0.0f, 0.0f, 0.0f,
		 0.0f, scale.y, 0.0f, 0.0f,
		 0.0f, 0.0f, scale.z, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f,
		}
	};
	return result;
}

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix)
{
	Vector3 result{};
	Vector4 coord = { vector.x,vector.y,vector.z, 1.0f };
	Vector4 temp{};
	temp.x = coord.x * matrix.m[0][0] + coord.y * matrix.m[1][0] + coord.z * matrix.m[2][0] + coord.w * matrix.m[3][0];
	temp.y = coord.x * matrix.m[0][1] + coord.y * matrix.m[1][1] + coord.z * matrix.m[2][1] + coord.w * matrix.m[3][1];
	temp.z = coord.x * matrix.m[0][2] + coord.y * matrix.m[1][2] + coord.z * matrix.m[2][2] + coord.w * matrix.m[3][2];
	temp.w = coord.x * matrix.m[0][3] + coord.y * matrix.m[1][3] + coord.z * matrix.m[2][3] + coord.w * matrix.m[3][3];

	result.x = temp.x / temp.w;
	result.y = temp.y / temp.w;
	result.z = temp.z / temp.w;

	return result;

}

Matrix4x4 MakeRotateXMatrix(float radian)
{
	Matrix4x4 rotateX{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,std::cos(radian),std::sin(radian),0.0f,
		0.0f,-std::sin(radian),std::cos(radian),0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	return rotateX;
}

Matrix4x4 MakeRotateYMatrix(float radian)
{
	Matrix4x4 rotateY{
		std::cos(radian),0.0f,-std::sin(radian),0.0f,
		0.0f,1.0f,0.0f,0.0f,
		std::sin(radian),0.0f,std::cos(radian),0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	return rotateY;
}

Matrix4x4 MakeRotateZMatrix(float radian)
{
	Matrix4x4 rotateZ{
		std::cos(radian),std::sin(radian),0.0f,0.0f,
		-std::sin(radian),std::cos(radian),0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	return rotateZ;
}

Matrix4x4 MakeRotateXYZMatrix(Vector3 rotate)
{
	Matrix4x4 rotateX{
		1.0f,0.0f,0.0f,0.0f,
		0.0f,std::cos(rotate.x),std::sin(rotate.x),0.0f,
		0.0f,-std::sin(rotate.x),std::cos(rotate.x),0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	Matrix4x4 rotateY{
		std::cos(rotate.y),0.0f,-std::sin(rotate.y),0.0f,
		0.0f,1.0f,0.0f,0.0f,
		std::sin(rotate.y),0.0f,std::cos(rotate.y),0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	Matrix4x4 rotateZ{
		std::cos(rotate.z),std::sin(rotate.z),0.0f,0.0f,
		-std::sin(rotate.z),std::cos(rotate.z),0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f,
	};
	Matrix4x4 result = Multiply(rotateX, Multiply(rotateY, rotateZ));
	return result;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate)
{
	Matrix4x4 result = Multiply(MakeScaleMatrix(scale), Multiply(MakeRotateXYZMatrix(rotate), MakeTranslateMatrix(translate)));
	return result;
}

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRaito, float nearClip, float farClip)
{
	Matrix4x4 result =
	{
		(1.0f / aspectRaito) * (1.0f / std::tan(fovY / 2.0f)),0.0f,0.0f,0.0f,
		0.0f, 1.0f / std::tan(fovY / 2.0f), 0.0f, 0.0f,
		0.0f, 0.0f, farClip / (farClip - nearClip),1.0f,
		0.0f, 0.0f, (-nearClip * farClip) / (farClip - nearClip),0.0f,
	};
	return result;
}

Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip)
{
	Matrix4x4 result =
	{
		2.0f / (right - left), 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f / (top - bottom), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f / (farClip - nearClip), 0.0f,
		(left + right) / (left - right),(top + bottom) / (bottom - top), nearClip / (nearClip - farClip),1.0f,
	};
	return result;
}

Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth)
{
	Matrix4x4 result =
	{
		width / 2.0f, 0.0f, 0.0f, 0.0f,
		0.0f, -height / 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, maxDepth - minDepth, 0.0f,
		left + width / 2.0f, top + height / 2.0f, minDepth, 1.0f,
	};
	return result;
}

Vector3 Cross(const Vector3& v1, const Vector3& v2)
{
	Vector3 result
	{
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	};
	return result;
}

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix)
{
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubdivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);
	Vector3 kLocalGrid{ 0.0f,0.0f,0.0f };

	//奥から手前への線を隅々にひいていく
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex)
	{
		Vector3 startPos = { -kGridHalfWidth + xIndex * kGridEvery,0.0f,-kGridHalfWidth };
		Vector3 endPos = { -kGridHalfWidth + xIndex * kGridEvery,0.0f,kGridHalfWidth };

		Matrix4x4 sWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, startPos);
		Matrix4x4 sWorldViewProjectionMatrix = Multiply(sWorldMatrix, viewProjectionMatrix);
		Vector3 ndcStart = Transform(kLocalGrid, sWorldViewProjectionMatrix);
		Vector3 screenStart = Transform(ndcStart, viewportMatrix);

		Matrix4x4 eWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, endPos);
		Matrix4x4 eWorldViewProjectionMatrix = Multiply(eWorldMatrix, viewProjectionMatrix);
		Vector3 ndcEnd = Transform(kLocalGrid, eWorldViewProjectionMatrix);
		Vector3 screenEnd = Transform(ndcEnd, viewportMatrix);

		Novice::DrawLine(int(screenStart.x), int(screenStart.y), int(screenEnd.x), int(screenEnd.y), 0xaaaaaaff);
	}
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex)
	{
		Vector3 startPos = { -kGridHalfWidth,0.0f,-kGridHalfWidth + xIndex * kGridEvery };
		Vector3 endPos = { kGridHalfWidth,0.0f,-kGridHalfWidth + xIndex * kGridEvery };

		Matrix4x4 sWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, startPos);
		Matrix4x4 sWorldViewProjectionMatrix = Multiply(sWorldMatrix, viewProjectionMatrix);
		Vector3 ndcStart = Transform(kLocalGrid, sWorldViewProjectionMatrix);
		Vector3 screenStart = Transform(ndcStart, viewportMatrix);

		Matrix4x4 eWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, endPos);
		Matrix4x4 eWorldViewProjectionMatrix = Multiply(eWorldMatrix, viewProjectionMatrix);
		Vector3 ndcEnd = Transform(kLocalGrid, eWorldViewProjectionMatrix);
		Vector3 screenEnd = Transform(ndcEnd, viewportMatrix);

		Novice::DrawLine(int(screenStart.x), int(screenStart.y), int(screenEnd.x), int(screenEnd.y), 0xaaaaaaff);
	}

}

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix)
{
	const uint32_t kSubdivision = 20; // 分割数
	const float kLonEvery = 2.0f * std::numbers::pi_v<float> / float(kSubdivision); // 経度分割1つ分の角度
	const float kLatEvery = std::numbers::pi_v<float> / float(kSubdivision); // 緯度分割1つ分の角度
	Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, sphere.rotate, sphere.center);
	Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewProjectionMatrix);

	// 緯度の方向に分割 -π/2 ~ π/2
	for (uint32_t latIndex = 0; latIndex < kSubdivision; latIndex++)
	{
		float lat = -std::numbers::pi_v<float> / 2.0f + kLatEvery * latIndex;//現在の緯度
		// 経度の方向に分割 0 ~ 2π
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; lonIndex++)
		{
			float lon = kLonEvery * lonIndex; // 現在の経度

			// world座標系でのa,b,cを求める
			Vector3 a, b, c;
			a = { std::cosf(lat) * std::cosf(lon) * sphere.radius,sinf(lat) * sphere.radius, std::cosf(lat) * std::sinf(lon) * sphere.radius };
			b = { std::cosf(lat + kLatEvery) * std::cosf(lon) * sphere.radius,std::sinf(lat + kLatEvery) * sphere.radius,std::cosf(lat + kLatEvery) * std::sinf(lon) * sphere.radius };
			c = { std::cos(lat) * std::cos(lon + kLonEvery) * sphere.radius,std::sin(lat) * sphere.radius,std::cos(lat) * std::sin(lon + kLonEvery) * sphere.radius };
			// a, b, c を screen 座標系に変換

			Vector3 ndcA = Transform(a, worldViewProjectionMatrix);
			Vector3 screenA = Transform(ndcA, viewportMatrix);

			Vector3 ndcB = Transform(b, worldViewProjectionMatrix);
			Vector3 screenB = Transform(ndcB, viewportMatrix);

			Vector3 ndcC = Transform(c, worldViewProjectionMatrix);
			Vector3 screenC = Transform(ndcC, viewportMatrix);

			// ab, bc で線を引く
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenB.x), int(screenB.y), sphere.color);
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenC.x), int(screenC.y), sphere.color);
		}
	}

}

void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
	Vector3 center = Multiply(plane.distance, plane.normal);
	Vector3 perpendiculars[4];
	perpendiculars[0] = Normalize(Perpendicular(plane.normal));
	perpendiculars[1] = { -perpendiculars[0].x,-perpendiculars[0].y,-perpendiculars[0].z };
	perpendiculars[2] = Cross(plane.normal, perpendiculars[0]);
	perpendiculars[3] = { -perpendiculars[2].x,-perpendiculars[2].y,-perpendiculars[2].z };

	Vector3 points[4]{};
	for (int32_t index = 0; index < 4; ++index)
	{
		Vector3 extend = Multiply(2.0f, perpendiculars[index]);
		Vector3 point = Add(center, extend);
		points[index] = Transform(Transform(point, viewProjectionMatrix), viewportMatrix);
	}

	Novice::DrawLine(int(points[2].x), int(points[2].y), int(points[1].x), int(points[1].y), color);
	Novice::DrawLine(int(points[1].x), int(points[1].y), int(points[3].x), int(points[3].y), color);
	Novice::DrawLine(int(points[2].x), int(points[2].y), int(points[0].x), int(points[0].y), color);
	Novice::DrawLine(int(points[3].x), int(points[3].y), int(points[0].x), int(points[0].y), color);

}

void DrawLine(const Segment& line, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
	Vector3 points[2]{};
	points[0] = Transform(Transform(line.origin, viewProjectionMatrix), viewportMatrix);
	points[1] = Transform(Transform(Add(line.origin, line.diff), viewProjectionMatrix), viewportMatrix);

	Novice::DrawLine(int(points[0].x), int(points[0].y), int(points[1].x), int(points[1].y), color);
}

Vector3 Project(const Vector3& a, const Vector3& b)
{
	Vector3 projection{};
	float dot_product = a.x * b.x + a.y * b.y + a.z * b.z;
	float b_magnitude_squared = b.x * b.x + b.y * b.y + b.z * b.z;

	float scalar_projection = dot_product / b_magnitude_squared;

	projection.x = scalar_projection * b.x;
	projection.y = scalar_projection * b.y;
	projection.z = scalar_projection * b.z;

	return projection;
}

Vector3 ClosestPoint(const Vector3& point, const Segment& segment)
{
	// 線分をベクトルで表現
	Vector3 v = segment.diff;
	Vector3 w = Subtract(point, segment.origin);

	// 線分の始点から点までのベクトルと、線分の方向ベクトルの内積を計算
	float c1 = Dot(w, v);
	if (c1 <= 0)
	{
		return segment.origin; // 点が線分の始点よりも前にある場合
	}

	float c2 = Dot(v, v);
	if (c2 <= c1)
	{
		return Add(segment.origin, segment.diff); // 点が線分の終点よりも後ろにある場合
	}

	// 線分の外にある場合、点から線分までの距離を計算して最近接点を求める
	float b = c1 / c2;
	Vector3 closest_point{};
	closest_point.x = segment.origin.x + b * v.x;
	closest_point.y = segment.origin.y + b * v.y;
	closest_point.z = segment.origin.z + b * v.z;

	return closest_point;
}

Vector3 Perpendicular(const Vector3& vector)
{
	if (vector.x != 0.0f || vector.y != 0.0f)
	{
		return { -vector.y,vector.x,0.0f };
	}
	return { 0.0f,-vector.z,vector.y };
}

bool IsCollision(const Sphere& s1, const Sphere& s2)
{
	float distance = Length(Subtract(s2.center, s1.center));
	if (distance <= Add(s1.radius, s2.radius))
	{
		return true;
	}
	return false;
}

bool IsCollision(const Sphere& sphere, const Plane& plane)
{
	float distance = fabs(Dot(sphere.center, plane.normal) - plane.distance);

	if (distance < sphere.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsCollision(const Segment& line, const Plane& plane)
{
	float dot = Dot(plane.normal, line.diff);

	if (dot == 0.0f)
	{
		float dist = Dot(line.origin, plane.normal) - plane.distance;
		if (dist == 0.0f)
		{
			return false;
		}
	}

	float t = (plane.distance - Dot(line.origin, plane.normal)) / dot;

	if (t >= 0.0f && t <= 1.0f)
	{
		return true;
	}

	return false;

}

