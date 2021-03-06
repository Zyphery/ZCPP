#pragma once

#include <iostream>
#include <math.h>

#define TEMPLATE template<typename Type = double>

namespace ZCPP
{
	namespace Vector
	{
		TEMPLATE class Vec2
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Vec2");

			Type x, y;

			constexpr Vec2() : x(0), y(0) {}
			constexpr Vec2(const Type v) : x(v), y(v) {}
			constexpr Vec2(const Type _x, const Type _y) : x(_x), y(_y) {}

			static const Type Length(Vec2 v)
			{
				return (Type)sqrt(v.x * v.x + v.y * v.y);
			}

			static const Type LengthSqr(Vec2 v)
			{
				return v.x * v.x + v.y * v.y;
			}

			static const Type Distance(Vec2 v0, Vec2 v1)
			{
				Type _x = v1.x - v0.x;
				Type _y = v1.y - v0.y;
				return (Type)sqrt(_x * _x + _y * _y);
			}

			static Vec2 Normalized(Vec2 v)
			{
				Type d = ((Type)1.0) / Length(v);
				return Vec2(v.x * d, v.y * d);
			}

			static const Type DotProduct(Vec2 v0, Vec2 v1)
			{
				return v0.x * v1.x + v0.y * v1.y;
			}

			static Vec2 Floor(Vec2 v)
			{
				return Vec2((Type)floor(v.x), (Type)floor(v.y));
			}

			static Vec2 Ceil(Vec2 v)
			{
				return Vec2((Type)ceil(v.x), (Type)ceil(v.y));
			}

			static Vec2 Abs(Vec2 v)
			{
				return Vec2((Type)abs(v.x), (Type)abs(v.y));
			}

			static Vec2 Rotate(Vec2 v, Type r)
			{
				Type cr = (Type)cos(r);
				Type sr = (Type)sin(r);
				return Vec2(v.x * cr - v.y * sr, v.x * sr + v.y * cr);
			}

			static Vec2 Direction(Type r)
			{
				return Vec2((Type)cos(r), (Type)sin(r));
			}

			static Vec2 Reflect(Vec2 v, Vec2 n)
			{
				return v - n * ((Type)2.0) * DotProduct(v, n);
			}

			static Vec2 CartesianToPolar(Vec2 v)
			{
				Vec2 polar;
				polar.x = Length(v);
				polar.y = (Type)atan(v.x / v.y);
				return polar;
			}

			static Vec2 PolarToCartesian(Vec2 v)
			{
				Vec2 cartesian;
				cartesian.x = v.x * (Type)cos(v.y);
				cartesian.y = v.x * (Type)sin(v.y);
				return cartesian;
			}

			Type Length()
			{
				return Length(*this);
			}

			Vec2 Normalized()
			{
				return Normalized(*this);
			}

			Vec2 Floor()
			{
				return Floor(*this);
			}

			Vec2 Ceil()
			{
				return Ceil(*this);
			}

			Vec2 Abs()
			{
				return Abs(*this);
			}

			Vec2 Rotate(Type r)
			{
				return Rotate(*this, r);
			}

			Vec2 Reflect(Vec2 n)
			{
				return Reflect(*this, n);
			}

			Type& operator [](const size_t index)
			{
				switch (index)
				{
				case 0: return this->x;
				case 1: return this->y;
				}
			}

			bool operator == (const Vec2& rhs) { return this->x == rhs.x && this->y == rhs.y; }
			bool operator != (const Vec2& rhs) { return !(this == rhs); }
			bool operator < (const Vec2& rhs) { return this->x < rhs.x && this->y < rhs.y; }
			bool operator <= (const Vec2& rhs) { return this->x <= rhs.x && this->y <= rhs.y; }
			bool operator > (const Vec2& rhs) { return this->x > rhs.x && this->y > rhs.y; }
			bool operator >= (const Vec2& rhs) { return this->x >= rhs.x && this->y >= rhs.y; }
			
			Vec2 operator * (Vec2 rhs) { return Vec2(this->x * rhs.x, this->y * rhs.y); }
			Vec2 operator / (Vec2 rhs) { return Vec2(this->x / rhs.x, this->y / rhs.y); }
			Vec2 operator + (Vec2 rhs) { return Vec2(this->x + rhs.x, this->y + rhs.y); }
			Vec2 operator - (Vec2 rhs) { return Vec2(this->x - rhs.x, this->y - rhs.y); }
			
			Vec2 operator *= (Vec2 rhs) { *this = *this * rhs; return *this; }
			Vec2 operator /= (Vec2 rhs) { *this = *this / rhs; return *this; }
			Vec2 operator += (Vec2 rhs) { *this = *this + rhs; return *this; }
			Vec2 operator -= (Vec2 rhs) { *this = *this - rhs; return *this; }

			Vec2& operator ++ () { return Vec2(++x, ++y); }
			Vec2& operator -- () { return Vec2(--x, --y); }
			Vec2 operator ++ (int) { return Vec2(x++, y++); }
			Vec2 operator -- (int) { return Vec2(x--, y--); }

			Vec2 operator - () { return Vec2(-x, -y); }

			TEMPLATE friend std::ostream& operator << (std::ostream& os, const Vec2<Type>& v);
		};

		TEMPLATE Vec2<Type> operator - (const float& lhs, const Vec2<Type>& rhs) { return Vec2(lhs) - rhs; }
		TEMPLATE Vec2<Type> operator + (const float& lhs, const Vec2<Type>& rhs) { return Vec2(lhs) + rhs; }
		TEMPLATE Vec2<Type> operator * (const float& lhs, const Vec2<Type>& rhs) { return Vec2(lhs) * rhs; }
		TEMPLATE Vec2<Type> operator / (const float& lhs, const Vec2<Type>& rhs) { return Vec2(lhs) / rhs; }

		TEMPLATE std::ostream& operator << (std::ostream& os, const Vec2<Type>& v)
		{
			os << "<" << v.x << ", " << v.y << ">";
			return os;
		}

		TEMPLATE class Vec3
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Vec3");

			Type x, y, z;

			constexpr Vec3() : x(0), y(0), z(0) {}
			constexpr Vec3(const Type v) : x(v), y(v), z(v) {}
			constexpr Vec3(const Type _x, const Type _y, const Type _z) : x(_x), y(_y), z(_z) {}
			constexpr Vec3(const Vec2<Type> v, Type _z) : x(v.x), y(v.y), z(_z) {}

			operator Vec2<Type>() const { return Vec2<Type>(x, y); }

			static const Type Length(Vec3 v)
			{
				return (Type)sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
			}

			static const Type LengthSqr(Vec3 v)
			{
				return v.x * v.x + v.y * v.y + v.z * v.z;
			}

			static const Type Distance(Vec3 v0, Vec3 v1)
			{
				Type _x = v1.x - v0.x;
				Type _y = v1.y - v0.y;
				Type _z = v1.z - v0.z;
				return (Type)sqrt(_x * _x + _y * _y + _z * _z);
			}

			static Vec3 Normalized(Vec3 v)
			{
				Type d = ((Type)1.0) / Length(v);
				return Vec3(v.x * d, v.y * d, v.z * d);
			}

			static const Type DotProduct(Vec3 v0, Vec3 v1)
			{
				return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
			}

			static Vec3 CrossProduct(Vec3 v0, Vec3 v1)
			{
				return Vec3(v0.y * v1.z - v0.z * v1.y, v0.z * v1.x - v0.x * v1.z, v0.x * v1.y - v0.y * v1.x);
			}

			static Vec3 Floor(Vec3 v)
			{
				return Vec3((Type)floor(v.x), (Type)floor(v.y), (Type)floor(v.z));
			}

			static Vec3 Ceil(Vec3 v)
			{
				return Vec3((Type)ceil(v.x), (Type)ceil(v.y), (Type)ceil(v.z));
			}

			static Vec3 Abs(Vec3 v)
			{
				return Vec3((Type)abs(v.x), (Type)abs(v.y), (Type)abs(v.z));
			}

			static Vec3 Reflect(Vec3 v, Vec3 n)
			{
				return v - n * ((Type)2.0) * DotProduct(v, n);
			}

			Type Length()
			{
				return Length(*this);
			}

			Vec3 Normalized()
			{
				return Normalized(*this);
			}

			Vec3 Floor()
			{
				return Floor(*this);
			}

			Vec3 Ceil()
			{
				return Ceil(*this);
			}

			Vec3 Abs()
			{
				return Abs(*this);
			}

			Vec3 Reflect(Vec3 n)
			{
				return Reflect(*this, n);
			}

			bool operator == (const Vec3& rhs) { return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z; }
			bool operator != (const Vec3& rhs) { return !(this == rhs); }
			bool operator < (const Vec3& rhs) { return this->x < rhs.x && this->y < rhs.y && this->z < rhs.z; }
			bool operator <= (const Vec3& rhs) { return this->x <= rhs.x && this->y <= rhs.y && this->z <= rhs.z; }
			bool operator > (const Vec3& rhs) { return this->x > rhs.x && this->y > rhs.y && this->z > rhs.z; }
			bool operator >= (const Vec3& rhs) { return this->x >= rhs.x && this->y >= rhs.y && this->z >= rhs.z; }

			Vec3 operator * (Vec3 rhs) { return Vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z); }
			Vec3 operator / (Vec3 rhs) { return Vec3(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z); }
			Vec3 operator + (Vec3 rhs) { return Vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z); }
			Vec3 operator - (Vec3 rhs) { return Vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z); }

			Vec3 operator *= (Vec3 rhs) { *this = *this * rhs; return *this; }
			Vec3 operator /= (Vec3 rhs) { *this = *this / rhs; return *this; }
			Vec3 operator += (Vec3 rhs) { *this = *this + rhs; return *this; }
			Vec3 operator -= (Vec3 rhs) { *this = *this - rhs; return *this; }

			Vec3& operator ++ () { return Vec3(x++, y++, z++); }
			Vec3& operator -- () { return Vec3(x--, y--, z--); }
			Vec3 operator ++ (int) { return Vec3(x++, y++, z++); }
			Vec3 operator -- (int) { return Vec3(x--, y--, z--); }

			Vec3 operator - () { return Vec3(-x, -y, -z); }

			Type& operator [](const size_t index)
			{
				switch (index)
				{
				case 0: return this->x;
				case 1: return this->y;
				case 2: return this->z;
				}
			}

			TEMPLATE friend std::ostream& operator << (std::ostream& os, const Vec3<Type>& v);
		};

		TEMPLATE Vec3<Type> operator - (const float& lhs, const Vec3<Type>& rhs) { return Vec3(lhs) - rhs; }
		TEMPLATE Vec3<Type> operator + (const float& lhs, const Vec3<Type>& rhs) { return Vec3(lhs) + rhs; }
		TEMPLATE Vec3<Type> operator * (const float& lhs, const Vec3<Type>& rhs) { return Vec3(lhs) * rhs; }
		TEMPLATE Vec3<Type> operator / (const float& lhs, const Vec3<Type>& rhs) { return Vec3(lhs) / rhs; }

		TEMPLATE std::ostream& operator << (std::ostream& os, const Vec3<Type>& v)
		{
			os << "<" << v.x << ", " << v.y << ", " << v.z << ">";
			return os;
		}

		TEMPLATE class Vec4
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Vec4");

			Type x, y, z, w;

			constexpr Vec4() : x(0), y(0), z(0), w(0) {}
			constexpr Vec4(const Type v) : x(v), y(v), z(v), w(v) {}
			constexpr Vec4(const Type _x, const Type _y, const Type _z, const Type _w) : x(_x), y(_y), z(_z), w(_w) {}
			constexpr Vec4(const Vec3<Type> v, const Type _w) : x(v.x), y(v.y), z(v.z), w(_w) {}
			constexpr Vec4(const Vec2<Type> v0, const Vec2<Type> v1) : x(v0.x), y(v0.y), z(v1.x), w(v1.y) {}

			operator Vec2<Type>() const { return Vec2<Type>(x, y); }
			operator Vec3<Type>() const { return Vec3<Type>(x, y, z); }

			static const Type Length(Vec4 v)
			{
				return (Type)sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
			}

			static const Type LengthSqr(Vec4 v)
			{
				return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
			}

			static const Type Distance(Vec4 v0, Vec4 v1)
			{
				Type _x = v1.x - v0.x;
				Type _y = v1.y - v0.y;
				Type _z = v1.z - v0.z;
				Type _w = v1.w - v0.w;
				return (Type)sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
			}

			static Vec4 Normalized(Vec4 v)
			{
				Type d = ((Type)1.0) / Length(v);
				return Vec4(v.x * d, v.y * d, v.z * d, v.w * d);
			}

			static const Type DotProduct(Vec4 v0, Vec4 v1)
			{
				return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w;
			}
			
			static Vec4 Floor(Vec4 v)
			{
				return Vec4((Type)floor(v.x), (Type)floor(v.y), (Type)floor(v.z), (Type)floor(v.w));
			}

			static Vec4 Ceil(Vec4 v)
			{
				return Vec4((Type)ceil(v.x), (Type)ceil(v.y), (Type)ceil(v.z), (Type)ceil(v.w));
			}

			static Vec4 Abs(Vec4 v)
			{
				return Vec4((Type)abs(v.x), (Type)abs(v.y), (Type)abs(v.z), (Type)abs(v.w));
			}

			static Vec4 Reflect(Vec4 v, Vec4 n)
			{
				return v - n * ((Type)2.0) * DotProduct(v, n);
			}

			static Vec4 Conjugate(Vec4 v)
			{
				return Vec4(-v.x, -v.y, -v.z, v.w);
			}

			static Vec4 Multiply(Vec4 v0, Vec4 v1)
			{
				return Vec4(
					v1.w * v0.x + v1.x * v0.w + v1.y * v0.z - v1.z * v0.y,
					v1.w * v0.y + v1.y * v0.w + v1.z * v0.x - v1.x * v0.z,
					v1.w * v0.z + v1.z * v0.w + v1.x * v0.y - v1.y * v0.x,
					v1.w * v0.w - v1.x * v0.x - v1.y * v0.y - v1.z * v0.z);
			}

			const Type Length()
			{
				return Length(*this);
			}

			Vec4 Normalized()
			{
				return Normalized(*this);
			}

			Vec4 Floor()
			{
				return Floor(*this);
			}

			Vec4 Ceil()
			{
				return Ceil(*this);
			}

			Vec4 Abs()
			{
				return Abs(*this);
			}

			Vec4 Reflect(Vec4& n)
			{
				return Reflect(*this, n);
			}

			bool operator == (const Vec4& rhs) { return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w; }
			bool operator != (const Vec4& rhs) { return !(this == rhs); }
			bool operator < (const Vec4& rhs) { return this->x < rhs.x && this->y < rhs.y && this->z < rhs.z && this->w < rhs.w; }
			bool operator <= (const Vec4& rhs) { return this->x <= rhs.x && this->y <= rhs.y && this->z <= rhs.z && this->w <= rhs.w; }
			bool operator > (const Vec4& rhs) { return this->x > rhs.x && this->y > rhs.y && this->z > rhs.z && this->w > rhs.w; }
			bool operator >= (const Vec4& rhs) { return this->x >= rhs.x && this->y >= rhs.y && this->z >= rhs.z && this->w >= rhs.w; }

			Vec4 operator * (Vec4 rhs) { return Vec4(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z, this->w * rhs.w); }
			Vec4 operator / (Vec4 rhs) { return Vec4(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z, this->w / rhs.w); }
			Vec4 operator + (Vec4 rhs) { return Vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w); }
			Vec4 operator - (Vec4 rhs) { return Vec4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w); }

			Vec4 operator *= (Vec4 rhs) { *this = *this * rhs; return *this; }
			Vec4 operator /= (Vec4 rhs) { *this = *this / rhs; return *this; }
			Vec4 operator += (Vec4 rhs) { *this = *this + rhs; return *this; }
			Vec4 operator -= (Vec4 rhs) { *this = *this - rhs; return *this; }

			Vec4& operator ++ () { return Vec4(x++, y++, z++, w++); }
			Vec4& operator -- () { return Vec4(x--, y--, z--, w--); }
			Vec4 operator ++ (int) { return Vec4(x++, y++, z++, w++); }
			Vec4 operator -- (int) { return Vec4(x--, y--, z--, w--); }

			Vec4 operator - () { return Vec4(-x, -y, -z, -w); }

			Type& operator [](const size_t index)
			{
				switch (index)
				{
				case 0: return this->x;
				case 1: return this->y;
				case 2: return this->z;
				case 3: return this->w;
				}
			}

			TEMPLATE friend std::ostream& operator << (std::ostream& os, const Vec4<Type>& v);
		};

		TEMPLATE Vec4<Type> operator - (const float& lhs, const Vec4<Type>& rhs) { return Vec4(lhs) - rhs; }
		TEMPLATE Vec4<Type> operator + (const float& lhs, const Vec4<Type>& rhs) { return Vec4(lhs) + rhs; }
		TEMPLATE Vec4<Type> operator * (const float& lhs, const Vec4<Type>& rhs) { return Vec4(lhs) * rhs; }
		TEMPLATE Vec4<Type> operator / (const float& lhs, const Vec4<Type>& rhs) { return Vec4(lhs) / rhs; }

		TEMPLATE std::ostream& operator << (std::ostream& os, const Vec4<Type>& v)
		{
			os << "<" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ">";
			return os;
		}

		TEMPLATE class Matrix2
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Matrix2");

			Vec2<Type> m[2];

			constexpr Matrix2() { m[0] = 0; m[1] = 0; }
			constexpr Matrix2(const Type v) { m[0] = v; m[1] = v; }
			constexpr Matrix2(const Type m00, const Type m01, const Type m10, const Type m11)
			{
				m[0][0] = m00; m[0][1] = m01;
				m[1][0] = m10; m[1][1] = m11;
			}
			constexpr Matrix2(const Vec2<Type> v0, const Vec2<Type> v1) { m[0] = v0; m[1] = v1; }

			static Matrix2 Identity()
			{
				return Matrix2(1, 0, 0, 1);
			}

			static Matrix2 Adjugate(Matrix2 m)
			{
				return Matrix2(m[1][1], -m[0][1], -m[1][0], m[0][0]);
			}

			static Matrix2 Inverse(Matrix2 m)
			{
				Type det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
				return Matrix2(det, 0, 0, det);
			}

			static Matrix2 Normalize(Matrix2 m)
			{
				return Matrix2(m[0].Normalized(), m[1].Normalized());
			}

			static Matrix2 Shear(Vec2<Type> s)
			{
				Matrix2 m;

				m = Identity();

				m[0][1] = s.x;
				m[1][1] = s.y;

				return m;
			}

			static Matrix2 Shear(Type s0, Type s1)
			{
				return Shear(Vec2<Type>(s0, s1));
			}

			static Matrix2 Scale(Vec2<Type> s)
			{
				Matrix2 m;

				m[0][0] = s.x;
				m[1][1] = s.y;

				return m;
			}

			static Matrix2 Scale(Type s0, Type s1)
			{
				return Scale(Vec2<Type>(s0, s1));
			}

			static Matrix2 Rotation(Type r)
			{
				Matrix2 m;
				Type cr = (Type)cos(r);
				Type sr = (Type)sin(r);
				m[0] = Vec2<Type>(cr, -sr);
				m[1] = Vec2<Type>(sr, cr);
				return m;
			}

			static Matrix2 Multiply(Matrix2 m, Type v)
			{
				m[0][0] = m[0][0] * v;
				m[0][1] = m[0][1] * v;
				m[1][0] = m[1][0] * v;
				m[1][1] = m[1][1] * v;

				return m;
			}

			static Matrix2 Multiply(Matrix2 m0, Matrix2 m1)
			{
				Matrix2 m;

				m[0][0] = m0[0][0] * m1[0][0] + m0[0][1] * m1[1][0];
				m[0][1] = m0[0][0] * m1[0][1] + m0[0][1] * m1[1][1];
				m[1][0] = m0[1][0] * m1[0][0] + m0[1][1] * m1[1][0];
				m[1][1] = m0[1][0] * m1[0][1] + m0[1][1] * m1[1][1];

				return m;
			}

			static const Vec2<Type> Multiply(Matrix2 m, Vec2<Type> v)
			{
				Vec2<Type> V;

				V[0] = m[0][0] * v[0] + m[0][1] * v[1];
				V[1] = m[1][0] * v[0] + m[1][1] * v[1];

				return V;
			}

			Matrix2 Adjugate()
			{
				return Adjugate(*this);
			}

			Matrix2 Inverse()
			{
				return Inverse(*this);
			}

			Type& operator()(const size_t index0, const size_t index1)
			{
				return m[index0][index1];
			}

			Vec2<Type>& operator [](const size_t index)
			{
				return m[index];
			}

			Matrix2 operator * (Type rhs) { return Multiply(*this, rhs); }
			Matrix2 operator * (Matrix2 rhs) { return Multiply(*this, rhs); }
			Vec2<Type> operator * (Vec2<Type> rhs) { return Multiply(*this, rhs); }

			Matrix2 operator + (Matrix2 rhs) { return Matrix2(this[0][0] + rhs[0][0], this[0][1] + rhs[0][1], this[1][0] + rhs[1][0], this[1][1] + rhs[1][1]); }
			Matrix2 operator - (Matrix2 rhs) { return Matrix2(this[0][0] - rhs[0][0], this[0][1] - rhs[0][1], this[1][0] - rhs[1][0], this[1][1] - rhs[1][1]); }
		};

		TEMPLATE std::ostream& operator << (std::ostream& os, const Matrix2<Type>& m)
		{
			os << "<" << m.m[0] << ", " << m.m[1] << ">";
			return os;
		}

		TEMPLATE class Matrix3
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Matrix3");

			Vec3<Type> m[3];

			constexpr Matrix3() { m[0] = 0; m[1] = 0; m[2] = 0; }
			constexpr Matrix3(const Type v) { m[0] = v; m[1] = v; m[2] = v; }
			constexpr Matrix3(const Type m00, const Type m01, const Type m02, const Type m10, const Type m11, const Type m12, const Type m20, const Type m21, const Type m22)
			{
				m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
				m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
				m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;
			}
			constexpr Matrix3(const Vec3<Type> v0, const Vec3<Type> v1, const Vec3<Type> v2) { m[0] = v0; m[1] = v1; m[2] = v2; }

			Type& operator()(const size_t index0, const size_t index1)
			{
				return m[index0][index1];
			}

			Vec3<Type>& operator [](const size_t index)
			{
				return m[index];
			}
		};

		TEMPLATE std::ostream& operator << (std::ostream& os, const Matrix3<Type>& m)
		{
			os << "<" << m.m[0] << ", " << m.m[1] << ", " << m.m[2] << ">";
			return os;
		}

		TEMPLATE class Matrix4
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Matrix4");

			Vec4<Type> m[4];

			constexpr Matrix4() { m[0] = 0; m[1] = 0; m[2] = 0; m[3] = 0; }
			constexpr Matrix4(const Type v) { m[0] = v; m[1] = v; m[2] = v; m[3] = v; }
			constexpr Matrix4(const Type m00, const Type m01, const Type m02, const Type m03, const Type m10, const Type m11, const Type m12, const Type m13, const Type m20, const Type m21, const Type m22, const Type m23, const Type m30, const Type m31, const Type m32, const Type m33)
			{
				m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
				m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
				m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
				m[3][0] = m20; m[3][1] = m21; m[3][2] = m22; m[3][3] = m23;
			}
			constexpr Matrix4(const Vec4<Type> v0, const Vec4<Type> v1, const Vec4<Type> v2, const Vec4<Type> v3) { m[0] = v0; m[1] = v1; m[2] = v2; m[3] = v3; }

			Type& operator()(const size_t index0, const size_t index1)
			{
				return m[index0][index1];
			}

			Vec4<Type>& operator [](const size_t index)
			{
				return m[index];
			}

			/*Type m[4][4]{ 0 };

			Matrix4() {}

			static Matrix4 Identity()
			{
				Matrix4 m;
				m.m[0][0] = 1.0;
				m.m[1][1] = 1.0;
				m.m[2][2] = 1.0;
				m.m[3][3] = 1.0;
				return m;
			}

			static Matrix4 Multiply(Matrix4 m0, Matrix4 m1)
			{
				Matrix4 m2;
				m2.m[0][0] = m0.m[0][0] * m1.m[0][0] + m0.m[0][1] * m1.m[1][0] + m0.m[0][2] * m1.m[2][0] + m0.m[0][3] * m1.m[3][0];
				m2.m[0][1] = m0.m[0][0] * m1.m[0][1] + m0.m[0][1] * m1.m[1][1] + m0.m[0][2] * m1.m[2][1] + m0.m[0][3] * m1.m[3][1];
				m2.m[0][2] = m0.m[0][0] * m1.m[0][2] + m0.m[0][1] * m1.m[1][2] + m0.m[0][2] * m1.m[2][2] + m0.m[0][3] * m1.m[3][2];
				m2.m[0][3] = m0.m[0][0] * m1.m[0][3] + m0.m[0][1] * m1.m[1][3] + m0.m[0][2] * m1.m[2][3] + m0.m[0][3] * m1.m[3][3];

				m2.m[1][0] = m0.m[1][0] * m1.m[0][0] + m0.m[1][1] * m1.m[1][0] + m0.m[1][2] * m1.m[2][0] + m0.m[1][3] * m1.m[3][0];
				m2.m[1][1] = m0.m[1][0] * m1.m[0][1] + m0.m[1][1] * m1.m[1][1] + m0.m[1][2] * m1.m[2][1] + m0.m[1][3] * m1.m[3][1];
				m2.m[1][2] = m0.m[1][0] * m1.m[0][2] + m0.m[1][1] * m1.m[1][2] + m0.m[1][2] * m1.m[2][2] + m0.m[1][3] * m1.m[3][2];
				m2.m[1][3] = m0.m[1][0] * m1.m[0][3] + m0.m[1][1] * m1.m[1][3] + m0.m[1][2] * m1.m[2][3] + m0.m[1][3] * m1.m[3][3];

				m2.m[2][0] = m0.m[2][0] * m1.m[0][0] + m0.m[2][1] * m1.m[1][0] + m0.m[2][2] * m1.m[2][0] + m0.m[2][3] * m1.m[3][0];
				m2.m[2][1] = m0.m[2][0] * m1.m[0][1] + m0.m[2][1] * m1.m[1][1] + m0.m[2][2] * m1.m[2][1] + m0.m[2][3] * m1.m[3][1];
				m2.m[2][2] = m0.m[2][0] * m1.m[0][2] + m0.m[2][1] * m1.m[1][2] + m0.m[2][2] * m1.m[2][2] + m0.m[2][3] * m1.m[3][2];
				m2.m[2][3] = m0.m[2][0] * m1.m[0][3] + m0.m[2][1] * m1.m[1][3] + m0.m[2][2] * m1.m[2][3] + m0.m[2][3] * m1.m[3][3];

				m2.m[3][0] = m0.m[3][0] * m1.m[0][0] + m0.m[3][1] * m1.m[1][0] + m0.m[3][2] * m1.m[3][0] + m0.m[3][3] * m1.m[3][0];
				m2.m[3][1] = m0.m[3][0] * m1.m[0][1] + m0.m[3][1] * m1.m[1][1] + m0.m[3][2] * m1.m[3][1] + m0.m[3][3] * m1.m[3][1];
				m2.m[3][2] = m0.m[3][0] * m1.m[0][2] + m0.m[3][1] * m1.m[1][2] + m0.m[3][2] * m1.m[3][2] + m0.m[3][3] * m1.m[3][2];
				m2.m[3][3] = m0.m[3][0] * m1.m[0][3] + m0.m[3][1] * m1.m[1][3] + m0.m[3][2] * m1.m[3][3] + m0.m[3][3] * m1.m[3][3];
				return m2;
			}

			static Vec4<Type> Multiply(Matrix4 m0, Vec4<Type> v0)
			{
				Vec4<Type> v1;
				v1.x = v0.x * m0.m[0][0] + v0.y * m0.m[0][1] + v0.z * m0.m[0][2] + v0.w * m0.m[0][3];
				v1.y = v0.x * m0.m[1][0] + v0.y * m0.m[1][1] + v0.z * m0.m[1][2] + v0.w * m0.m[1][3];
				v1.z = v0.x * m0.m[2][0] + v0.y * m0.m[2][1] + v0.z * m0.m[2][2] + v0.w * m0.m[2][3];
				v1.w = v0.x * m0.m[3][0] + v0.y * m0.m[3][1] + v0.z * m0.m[3][2] + v0.w * m0.m[3][3];
				return v1;
			}

			static Matrix4 PerspectiveProjection(Type Znear, Type Zfar, Type rFOV, Type AR)
			{
				Matrix4 m;
				Type tfh = tan(rFOV * 0.5);
				Type izfzn = 1.0 / (Zfar - Znear);

				m.m[0][0] = 1.0 / (AR * tfh);
				m.m[1][1] = -1.0 / (tfh);
				m.m[2][2] = (Zfar - Znear) * izfzn;
				m.m[3][2] = 1.0;
				m.m[2][3] = (2.0 * Zfar * Znear) * izfzn;
				return m;
			}

			static Matrix4 LookAt(Vec3<Type> Right, Vec3<Type> Up, Vec3<Type> Direction, Vec3<Type> Position)
			{
				Matrix4 lM = Identity();
				lM.m[0][0] = Right.x;
				lM.m[0][1] = Right.y;
				lM.m[0][2] = Right.z;
				lM.m[1][0] = Up.x;
				lM.m[1][1] = Up.y;
				lM.m[1][2] = Up.z;
				lM.m[2][0] = Direction.x;
				lM.m[2][1] = Direction.y;
				lM.m[2][2] = Direction.z;
				return Multiply(lM, Translate(Position * -1));
			}

			static Matrix4 Translate(Vec3<Type> position)
			{
				Matrix4 m = Identity();
				m.m[0][3] = position.x;
				m.m[1][3] = position.y;
				m.m[2][3] = position.z;
				return m;
			}

			static Matrix4 Scale(Vec3<Type> scale)
			{
				Matrix4 m = Identity();
				m.m[0][0] = scale.x;
				m.m[1][1] = scale.y;
				m.m[2][2] = scale.z;
				return m;
			}

			Matrix4 operator * (Matrix4 rhs) { return Multiply(*this, rhs); }
			Vec4<Type> operator * (Vec4<Type> rhs) { return Multiply(*this, rhs); }*/
		};

		TEMPLATE std::ostream& operator << (std::ostream& os, const Matrix4<Type>& m)
		{
			os << "<" << m.m[0] << ", " << m.m[1] << ", " << m.m[2] << ", " << m.m[3] << ">";
			return os;
		}



		TEMPLATE class Quaternion : public Vec4<Type>
		{
		public:
			static_assert(
				std::is_same<Type, char>() ||
				std::is_same<Type, unsigned char>() ||
				std::is_same<Type, short int>() ||
				std::is_same<Type, unsigned short int>() ||
				std::is_same<Type, long int>() ||
				std::is_same<Type, int>() ||
				std::is_same<Type, unsigned int>() ||
				std::is_same<Type, unsigned long int>() ||
				std::is_same<Type, long long int>() ||
				std::is_same<Type, unsigned long long int>() ||
				std::is_same<Type, float>() ||
				std::is_same<Type, double>() ||
				std::is_same<Type, long double>(),
				"Invalid type used for Quaternion");

			constexpr Quaternion() { this->x = 0; this->y = 0; this->z = 0; this->w = 1; }
			constexpr Quaternion(Vec3<Type> v) { this->x = v.x; this->y = v.y; this->z = v.z; this->w = 0; }
			constexpr Quaternion(Vec4<Type> v) { this->x = v.x; this->y = v.y; this->z = v.z; this->w = v.w; }
			constexpr Quaternion(Type _x, Type _y, Type _z, Type _w) { this->x = _x; this->y = _y; this->z = _z; this->w = _w; }

			constexpr static Quaternion Identity()
			{
				return Quaternion(0, 0, 0, 1);
			}

			static Quaternion Conjugate(const Quaternion& q)
			{
				return Quaternion(-q.x, -q.y, -q.z, q.w);
			}

			static Quaternion Multiply(const Quaternion& q0, const Quaternion& q1)
			{
				return Quaternion(
					q1.w * q0.x + q1.x * q0.w + q1.y * q0.z - q1.z * q0.y,
					q1.w * q0.y + q1.y * q0.w + q1.z * q0.x - q1.x * q0.z,
					q1.w * q0.z + q1.z * q0.w + q1.x * q0.y - q1.y * q0.x,
					q1.w * q0.w - q1.x * q0.x - q1.y * q0.y - q1.z * q0.z);
			}

			static Quaternion EulerToQuaternion(Vec3<Type> euler)
			{
				euler *= 0.5;

				Type cr = cos(euler.x);
				Type sr = sin(euler.x);
				Type cp = cos(euler.y);
				Type sp = sin(euler.y);
				Type cy = cos(euler.z);
				Type sy = sin(euler.z);

				Quaternion q;

				q.w = cr * cp * cy + sr * sp * sy;
				q.x = sr * cp * cy - cr * sp * sy;
				q.y = cr * sp * cy + sr * cp * sy;
				q.z = cr * cp * sy - sr * sp * cy;

				return q;
			}

			static Vec3<Type> QuaternionToEuler(Quaternion q)
			{
				Vec3<Type> euler;

				euler.x = atan2(2.0 * (q.w * q.x + q.y * q.z), 1.0 - 2.0 * (q.x * q.x + q.y * q.y));

				Type sinp = 2.0 * (q.w * q.y - q.z * q.x);
				euler.y = abs(sinp) >= 1.0 ? copysign(1.5707963268, sinp) : asin(sinp);

				euler.z = atan2(2.0 * (q.w * q.z + q.x * q.y), 1.0 - 2.0 * (q.y * q.y + q.z * q.z));
					

				return euler;
			}

			static Quaternion RotationQuaternion(Vec3<Type> axis, Type r)
			{
				Quaternion q;

				r *= 0.5;
				Type sr = sin(r);

				q.w = cos(r);
				q.x = axis.x * sr;
				q.y = axis.y * sr;
				q.z = axis.z * sr;

				return q;
			}

			static Vec3<Type> MultiplyVector(Quaternion q, Vec3<Type> vector)
			{
				Quaternion qp = Conjugate(q);
				Quaternion v = Quaternion(vector);

				v = Multiply(Multiply(q, v), qp);
				return Vec3<Type>(v.x, v.y, v.z);
			}

			static Vec3<Type> RotateVector(Vec3<Type> axis, Type r, Vec3<Type> vector)
			{
				Quaternion q = RotationQuaternion(axis, r);
				Quaternion qp = Conjugate(q);
				Quaternion v = Quaternion(vector);

				v = Multiply(Multiply(q, v), qp);
				return Vec3<Type>(v.x, v.y, v.z);
			}

			static Matrix4<Type> QuaternionToRotationMatrix(Quaternion q)
			{
				Matrix4 m;

				Type xx = q.x * q.x;
				Type yy = q.y * q.y;
				Type zz = q.z * q.z;

				Type xy = q.x * q.y;
				Type xz = q.x * q.z;
				Type xw = q.x * q.w;
				Type yz = q.y * q.z;
				Type yw = q.y * q.w;
				Type zw = q.z * q.w;
				
				// 1 - 2 y^2 - 2 z^2	2 xy - 2 wz			2 xz + 2 wy			0
				// 2 xy + 2wz			1 - 2 x^2 - 2 z^2	2 yz - 2 wx			0
				// 2 xz - 2 wy			2 yz + 2 wx			1 - 2x^2 - 2 y^2	0
				// 0					0					0					1

				//m.m[0][0] = 1.0 - 2.0 * yy - 2 * zz; m.m[1][0] = 2 * xy - 2 * zw; m.m[2][0] = 2 * xz + 2 * yw; m.m[3][0] = 0;
				//m.m[0][1] = 2 * xy + 2 * zw; m.m[1][1] = 1 - 2 * xx - 2 * zz; m.m[2][1] = 2 * yz - 2 * xw; m.m[3][1] = 0;
				//m.m[0][2] = 2 * xz - 2 * yw; m.m[1][2] = 2 * yz + 2 * xw; m.m[2][2] = 1 - 2 * xx - 2 * yy; m.m[3][2] = 0;
				//m.m[0][3] = 0; m.m[1][3] = 0; m.m[2][3] = 0; m.m[3][3] = 1;

				m.m[0][0] = 1.0 - 2.0 * yy - 2 * zz; m.m[0][1] = 2 * xy - 2 * zw; m.m[0][2] = 2 * xz + 2 * yw; m.m[0][3] = 0;
				m.m[1][0] = 2 * xy + 2 * zw; m.m[1][1] = 1 - 2 * xx - 2 * zz; m.m[1][2] = 2 * yz - 2 * xw; m.m[1][3] = 0;
				m.m[2][0] = 2 * xz - 2 * yw; m.m[2][1] = 2 * yz + 2 * xw; m.m[2][2] = 1 - 2 * xx - 2 * yy; m.m[2][3] = 0;
				m.m[3][0] = 0; m.m[3][1] = 0; m.m[3][2] = 0; m.m[3][3] = 1;

				return m;
			}

			Vec3<Type> operator * (Vec3<Type> rhs) { return MultiplyVector(*this, rhs); }

			template<typename Type> friend std::ostream& operator << (std::ostream& os, const Quaternion<Type>& v);
		};

		TEMPLATE std::ostream& operator << (std::ostream& os, const Quaternion<Type>& v)
		{
			os << "<" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ">";
			return os;
		}

		typedef Vec2<double> Vec2d;
		typedef Vec2<float> Vec2f;
		typedef Vec2<long int> Vec2i;

		typedef Vec3<double> Vec3d;
		typedef Vec3<float> Vec3f;
		typedef Vec3<long int> Vec3i;

		typedef Vec4<double> Vec4d;
		typedef Vec4<float> Vec4f;
		typedef Vec4<long int> Vec4i;

		typedef Matrix2<double> Matrix2d;
		typedef Matrix2<float> Matrix2f;
		typedef Matrix2<long int> Matrix2i;

		typedef Matrix3<double> Matrix3d;
		typedef Matrix3<float> Matrix3f;
		typedef Matrix3<long int> Matrix3i;

		typedef Matrix4<double> Matrix4d;
		typedef Matrix4<float> Matrix4f;
		typedef Matrix4<long int> Matrix4i;

		typedef Quaternion<double> Quaterniond;
		typedef Quaternion<float> Quaternionf;
	}
}
