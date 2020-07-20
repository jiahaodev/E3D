/****************************************************
	文件：EVector.h
	作者：JiahaoWu
	邮箱: jiahaodev@163.ccom
	日期：2020/07/19
	功能：实现 2D、3D、4D 向量
*****************************************************/

#pragma once

#include "ECommon.h"
#include "EMath.h"
#include "EUtil.h"

namespace E3D
{
	//2D向量定义
	struct EVector2D
	{
		static EVector2D ZERO;
		static EVector2D UNIT_X;
		static EVector2D UNIT_Y;

		EFloat x;
		EFloat y;

		EVector2D() :x(0), y(0) {}
		EVector2D(EFloat xf, EFloat yf) :x(xf), y(yf) {}
		EVector2D(const EVector2D &v) :x(v.x), y(v.y) {}

		//规范化
		inline EFloat normalize()
		{
			EFloat len = length();
			if (len > EPSILON_E6) // 主要考虑分母不能为0的情况
			{
				EFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
			}
			return len;
		}

		//点乘
		inline EFloat dotProduct(const EVector2D &right)const
		{
			return x  *right.x + y  *right.y;
		}

		//两个向量间的夹角（单位：弧度）
		inline EFloat angleBetween(const EVector2D &right)const
		{
			EFloat lenProduct = length()  *right.length();

			// 除零检查
			if (lenProduct < EPSILON_E6)
				lenProduct = EPSILON_E6;

			EFloat f = dotProduct(right) / lenProduct;
			f = Clamp(f, -1.0f, 1.0f);

			return acos(f);
		}

		//判断长度是否为零
		inline bool isZero() const
		{
			return length() < EPSILON_E6;
		}

		//长度
		inline EFloat length() const
		{
			return sqrt(x  *x + y  *y);
		}

		//长度的平方
		inline EFloat squaredLength()const
		{
			return x  *x + y  *y;
		}

		//向量与数字的乘法
		inline EVector2D operator  *(float right)const
		{
			return EVector2D(x  *right, y  *right);
		}

		//向量点积
		inline EVector2D operator  *(const EVector2D &right)const
		{
			return  EVector2D(x  *right.x, y  *right.y);
		}

		//向量加法
		inline EVector2D operator + (const EVector2D &right)const
		{
			return EVector2D(x + right.x, y + right.y);
		}

		//向量减法
		inline EVector2D operator - (const EVector2D &right)const
		{
			return EVector2D(x - right.x, y - right.y);
		}
		//向量取反
		inline EVector2D operator - ()
		{
			//x = -x;
			//y = -y;
			//return *this;
			return EVector2D(-x,-y);
		}

		//向量取正
		inline EVector2D operator + ()
		{
			x = +x;
			y = +y;
			return *this;
		}

		//判断两个向量是否相等
		inline bool operator == (const EVector2D &right)const
		{
			return EqualFloat(x, right.x) && EqualFloat(y, right.y);
		}

		//赋值
		inline EVector2D operator = (const EVector2D &right)
		{
			x = right.x;
			y = right.y;
			return *this;
		}

	};



	//3D向量定义
	struct EVector3D
	{
		static EVector3D ZERO;
		static EVector3D UNIT_X;
		static EVector3D UNIT_Y;
		static EVector3D UNIT_Z;

		EFloat x;
		EFloat y;
		EFloat z;

		EVector3D() :x(0), y(0), z(0) {}
		EVector3D(EFloat xf, EFloat yf, EFloat zf) :x(xf), y(yf), z(zf) {}
		EVector3D(const EVector3D &v) :x(v.x), y(v.y), z(v.z) {}

		//规范化
		inline EFloat normalize()
		{
			EFloat len = length();
			if (len > EPSILON_E6) // 主要考虑分母不能为0的情况
			{
				EFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
				z *= invLength;
			}
			return len;
		}

		//点乘
		inline EFloat dotProduct(const EVector3D &right)const
		{
			return x  *right.x + y  *right.y + z  *right.z;
		}

		//叉积
		inline EVector3D crossProduct(const EVector3D &right)const
		{
			return EVector3D(y  *right.z - z  *right.y,
				z  *right.x - x  *right.z,
				x  *right.y - y  *right.x);
		}

		//两个向量间的夹角（单位：弧度）
		inline EFloat angleBetween(const EVector3D &right)const
		{
			EFloat lenProduct = length()  *right.length();

			// 除零检查
			if (lenProduct < EPSILON_E6)
				lenProduct = EPSILON_E6;

			EFloat f = dotProduct(right) / lenProduct;
			f = Clamp(f, -1.0f, 1.0f);

			return acos(f);
		}

		//判断长度是否为零
		inline bool isZero() const
		{
			return length() < EPSILON_E6;
		}

		//长度
		inline EFloat length() const
		{
			return sqrt(x  *x + y  *y + z  *z);
		}

		//长度的平方
		inline EFloat squaredLength()const
		{
			return x  *x + y  *y + z  *z;
		}

		//向量与数字的乘法
		inline EVector3D operator  *(float right)const
		{
			return EVector3D(x  *right, y  *right, z  *right);
		}

		//向量点积
		inline EVector3D operator  *(const EVector3D &right)const
		{
			return  EVector3D(x  *right.x, y  *right.y, z  *right.z);
		}

		//向量加法
		inline EVector3D operator + (const EVector3D &right)const
		{
			return EVector3D(x + right.x, y + right.y, z + right.z);
		}

		//向量减法
		inline EVector3D operator - (const EVector3D &right)const
		{
			return EVector3D(x - right.x, y - right.y, z - right.z);
		}
		//向量取反
		inline EVector3D operator - ()
		{
			//x = -x;
			//y = -y;
			//z = -z;
			//return *this;
			return EVector3D(-x,-y,-z);
		}

		//向量取正
		inline EVector3D operator + ()
		{
			x = +x;
			y = +y;
			z = +z;
			return *this;
		}

		//判断两个向量是否相等
		inline bool operator == (const EVector3D &right)const
		{
			return EqualFloat(x, right.x) && EqualFloat(y, right.y) && EqualFloat(z, right.z);
		}

		//赋值
		inline EVector3D operator = (const EVector3D &right)
		{
			x = right.x;
			y = right.y;
			z = right.z;
			return *this;
		}
	};



	//3D向量定义
	struct EVector4D
	{
		static EVector4D ZERO;
		static EVector4D UNIT_X;
		static EVector4D UNIT_Y;
		static EVector4D UNIT_Z;

		EFloat x;
		EFloat y;
		EFloat z;
		EFloat w;

		EVector4D() :x(0), y(0), z(0), w(1) {}
		EVector4D(EFloat xf, EFloat yf, EFloat zf, EFloat wf = 1) :x(xf), y(yf), z(zf), w(wf) {}
		EVector4D(const EVector4D &v) :x(v.x), y(v.y), z(v.z), w(v.w) {}

		//规范化
		inline EFloat normalize()
		{
			EFloat len = length();
			if (len > EPSILON_E6) // 主要考虑分母不能为0的情况
			{
				EFloat invLength = 1.0f / len;
				x *= invLength;
				y *= invLength;
				z *= invLength;
				w = 1;
			}
			return len;
		}

		//点乘
		inline EFloat dotProduct(const EVector4D &right)const
		{
			return x  *right.x + y  *right.y + z  *right.z;
		}

		//叉积
		inline EVector4D crossProduct(const EVector4D &right)const
		{
			return EVector4D(y  *right.z - z  *right.y,
				z  *right.x - x  *right.z,
				x  *right.y - y  *right.x,
				1);
		}

		//两个向量间的夹角（单位：弧度）
		inline EFloat angleBetween(const EVector4D &right)const
		{
			EFloat lenProduct = length()  *right.length();

			// 除零检查
			if (lenProduct < EPSILON_E6)
				lenProduct = EPSILON_E6;

			EFloat f = dotProduct(right) / lenProduct;
			f = Clamp(f, -1.0f, 1.0f);

			return acos(f);
		}

		//判断长度是否为零
		inline bool isZero() const
		{
			return length() < EPSILON_E6;
		}

		//长度
		inline EFloat length() const
		{
			return sqrt(x  *x + y  *y + z  *z);
		}

		//长度的平方
		inline EFloat squaredLength()const
		{
			return x  *x + y  *y + z  *z;
		}

		//向量与数字的乘法
		inline EVector4D operator  *(float right)const
		{
			return EVector4D(x  *right, y  *right, z  *right, 1);
		}

		//向量点积
		inline EVector4D operator  *(const EVector4D &right)const
		{
			return  EVector4D(x  *right.x, y  *right.y, z  *right.z, 1);
		}

		//向量加法
		inline EVector4D operator + (const EVector4D &right)const
		{
			return EVector4D(x + right.x, y + right.y, z + right.z, 1);
		}

		//向量减法
		inline EVector4D operator - (const EVector4D &right)const
		{
			return EVector4D(x - right.x, y - right.y, z - right.z, 1);
		}
		//TODO:向量取反
		inline EVector4D operator - ()
		{
			//x = -x;
			//y = -y;
			//z = -z;
			//return *this;
			return EVector4D(-x, -y, -z, w);
		}

		//判断两个向量是否相等
		inline bool operator == (const EVector4D &right)const
		{
			return EqualFloat(x, right.x) && EqualFloat(y, right.y) && EqualFloat(z, right.z) && EqualFloat(w, right.w);
		}

		//赋值
		inline EVector4D operator = (const EVector4D &right)
		{
			x = right.x;
			y = right.y;
			z = right.z;
			w = right.w;
			return *this;
		}
	};
}