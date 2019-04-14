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
	};						//�����ķ���

	Vector2();
	Vector2(float, float);
	float Length();			//ģ��
	float DirRad();			//�����
	Vector2 Unit();			//��������Ӧ��λ����
	void Normalize();		//�Ը�������λ�����ƻ��ԣ�
	bool IsNormalized();	//�ж������Ƿ��ǵ�λ����
	bool IsZero();			//�ж������Ƿ���������
	bool IsValid();			//�ж������Ƿ���Ч��������NAN�����
};



extern Vector2 operator+(Vector2 v0, Vector2 v1);	// �����ӷ�
extern Vector2 operator-(Vector2 v0, Vector2 v1);	// ��������
extern Vector2 operator*(float s, Vector2 v);		// ��������
extern Vector2 operator*(Vector2 v, float s);		// �������ˣ������ɣ�
extern Vector2 operator/(Vector2 v, float s);		// ����������������ˣ�
extern bool operator==(Vector2 v0, Vector2 v1);		// �����е�
extern bool operator!=(Vector2 v0, Vector2 v1);		// ��������
extern float DotProd(Vector2 v0, Vector2 v1);		// ������
extern float operator^(Vector2 v0, Vector2 v1);		// �н�