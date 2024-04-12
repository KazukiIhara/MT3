﻿#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "math.h"
#define _USE_MATH_DIFINES

/*---定数---*/
static const int kScreenWidth = 1920;//ウィンドウの横幅
static const int kScreenHeight = 1080;//ウィンドウの高さ

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
