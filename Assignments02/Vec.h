#pragma once

class Vector2
{
public:
	union
	{
		float comp[2];
		struct
		{
			float x;
			float y;
		};
	};						//向量的分量

	Vector2();
	Vector2(float, float);
	float Length();			//模长
	float DirRad();			//方向角
	Vector2 Unit();			//此向量对应单位向量
	void Normalize();		//对该向量单位化（破坏性）
	bool IsNormalized();	//判断向量是否是单位向量
	bool IsZero();			//判断向量是否是零向量
	bool IsValid();			//判断向量是否有效（不含有NAN和无穷）
};



extern Vector2 operator+(Vector2 v0, Vector2 v1);	// 向量加法
extern Vector2 operator-(Vector2 v0, Vector2 v1);	// 向量减法
extern Vector2 operator*(float s, Vector2 v);		// 向量数乘
extern Vector2 operator*(Vector2 v, float s);		// 向量数乘（交换律）
extern Vector2 operator/(Vector2 v, float s);		// 向量数除（倒数相乘）
extern bool operator==(Vector2 v0, Vector2 v1);		// 向量判等
extern bool operator!=(Vector2 v0, Vector2 v1);		// 向量不等
extern float DotProd(Vector2 v0, Vector2 v1);		// 数量积
extern float operator^(Vector2 v0, Vector2 v1);		// 夹角