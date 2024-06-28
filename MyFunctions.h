#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>
#include <cmath>
#include <numbers>
#define _USE_MATH_DIFINES

/*---定数---*/
static const int kScreenWidth = 1280;//ウィンドウの横幅
static const int kScreenHeight = 720;//ウィンドウの高さ

static const int kRowHeight = 24;
static const int kColumnWidth = 60;//Vector3を画面に描画する時に使う定数

/*---構造体---*/
struct Transform
{
	int x;
	int y;
};

struct Matrix2x2
{
	float m[2][2];
};

struct Matrix3x3
{
	float m[3][3];
};

struct Matrix4x4
{
	float m[4][4];
};

struct Sphere
{
	Vector3 center;//中心点
	Vector3 rotate;//回転
	float radius;//半径
	uint32_t color;//色
};

struct Triangle
{
	Vector3 vertices[3];
};

struct Line
{
	Vector3 origin;	//始点
	Vector3 diff;	//終点への差分ベクトル
};

struct Ray
{
	Vector3 origin;	//始点
	Vector3 diff;	//終点への差分ベクトル
};

struct Segment
{
	Vector3 origin;	//始点
	Vector3 diff;	//終点への差分ベクトル
};

struct Plane
{
	Vector3 normal;
	float distance;
};

struct AABB
{
	Vector3 min;
	Vector3 max;
};

struct OBB
{
	Vector3 center;
	Vector3 orientations[3];
	Vector3 size;
};

struct Spring {
	Vector3 anchor; // アンカー。固定された端の位置
	float naturalLength; // 自然長
	float stiffness; // 剛性。バネ定数k
	float dampingCoefficient; // 減衰係数
};

struct Ball {
	Vector3 position; // ボールの位置
	Vector3 velocity; // ボールの速度
	Vector3 acceleration; // ボールの加速度
	float mass; // ボールの質量
	float radius; // ボールの半径
	unsigned int color; // ボールの色
};

struct Pendulum {
	Vector3 anchor; // アンカーポイント
	float length; // 弦の長さ
	float angle; // 現在の角度
	float angulerVelocity; // 角速度
	float angulerAcceleration; // 角加速度
};

/*---関数---*/

int Add(const int& a, const int& b);
int Subtract(const int& a, const int& b);
int Multiply(const int& a, const int& b);
int Divide(const int& a, const int& b);

float Add(const float& a, const float& b);
float Subtract(const float& a, const float& b);
float Multiply(const float& a, const float& b);
float Divide(const float& a, const float& b);

Vector2 Add(const Vector2& a, const Vector2& b);
Vector2 Subtract(const Vector2& a, const Vector2& b);
Vector2 Multiply(const Vector2& a, const Vector2& b);
Vector2 Divide(const Vector2& a, const Vector2& b);

Vector3 Add(const Vector3& a, const Vector3& b);
Vector3 Subtract(const Vector3& a, const Vector3& b);
Vector3 Multiply(const Vector3& a, const Vector3& b);
Vector3 Multiply(const float& scalar, const Vector3& a);//3次元ベクトルのスカラー倍関数
Vector3 Divide(const Vector3& a, const Vector3& b);
float Dot(Vector3 a, Vector3 b);//3次元ベクトルの内積を返す関数
float Length(Vector3 a);//3次元ベクトルの長さをfloat型で返す関数
Vector3 Normalize(Vector3 a);//正規化した3次元ベクトルを返す関数
void VectorScreenPrintf(int x, int y, const Vector3& a, const char* label);

Matrix4x4 Add(const Matrix4x4& a, const Matrix4x4& b);
Matrix4x4 Subtract(const Matrix4x4& a, const Matrix4x4& b);
Matrix4x4 Multiply(const float& scalar, const Matrix4x4& a);
Matrix4x4 Multiply(const Matrix4x4& a, const Matrix4x4& b);
Matrix4x4 Inverse(const Matrix4x4& a);
Matrix4x4 Transpose(const Matrix4x4& a);
Matrix4x4 MakeIdentity4x4();
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);

Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
Matrix4x4 MakeScaleMatrix(const Vector3& scale);
Vector3 Transform(const  Vector3& vector, const  Matrix4x4& matrix);

Matrix4x4 MakeRotateXMatrix(float radian);
Matrix4x4 MakeRotateYMatrix(float radian);
Matrix4x4 MakeRotateZMatrix(float radian);
Matrix4x4 MakeRotateXYZMatrix(Vector3 radian);

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRaito, float nearClip, float farClip);
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

void DrawSphereWorldMatrix(const Matrix4x4& worldMatrix, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

void DrawLine(const Segment& line, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

void DrawOBB(const OBB& obb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

Vector3 Project(const Vector3& v1, const Vector3& v2);
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

Vector3 Perpendicular(const Vector3& vector);

bool IsCollision(const Sphere& s1, const Sphere& s2);
bool IsCollision(const Sphere& sphere, const Plane& plane);
bool IsCollision(const Segment& line, const Plane& plane);
bool IsCollision(const Triangle& triangle, const Segment& line);
bool IsCollision(const AABB& aabb1, const AABB& aabb2);
bool IsCollision(const AABB& aabb, const Sphere& sphere);
bool IsCollision(const AABB& aabb, const Segment& segment);
bool IsCollision(const OBB& obb, const Sphere& sphere);

Plane CreatePlaneFromTriangle(const Triangle& triangle);

Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);

void DrawBezier(const Vector3& controlPoint0, const Vector3& consrolPoint1, const Vector3& controlPoint2,
	const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewPortMatrix, uint32_t color);

// operator oveloading

Vector3 operator+(const Vector3& v1, const Vector3& v2);

Vector3 operator-(const Vector3& v1, const Vector3& v2);

Vector3 operator*(const Vector3& v1, const Vector3& v2);

Vector3 operator/(const Vector3& v1, const Vector3& v2);

Vector3 operator*(float s, const Vector3& v);

Vector3 operator*(const Vector3& v, float s);

Vector3 operator/(const Vector3& v, float s);


Matrix4x4 operator+(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator-(const Matrix4x4& m1, const Matrix4x4& m2);

Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);


Vector3 operator-(const Vector3& v);

Vector3 operator+(const Vector3& v);
