#pragma once
#include <random>
#include <limits.h>
#include <algorithm>

namespace ZCPP
{
	namespace Random
	{
		// /-----------------------------------------------\
		// | ZCPP::Random Header                           |
		// |                                               |
		// | Random()        - float (-1.0, 1.0)           |
		// | Random<Float>() - float (-1.0, 1.0)           |
		// | Random<Int>()   - int(int::min, int::max)     |
		// | Random<Bool>()  - bool(false, true)           |
		// |                                               |
		// | Random<Type>(min, max) - Type(min, max)       |
		// |                                     - Zyphery |
		// \-----------------------------------------------/

		// /-----------------------------------------------\
		// | Random Device                                 |
		// \-----------------------------------------------/
		
		static std::random_device device;

		static std::mt19937 rng(device());

		// /-----------------------------------------------\
		// | Random Functions                              |
		// \-----------------------------------------------/

		const static bool Random(bool) {
			return std::uniform_real_distribution<float>(-1.0f, 1.0f)(rng) >= 0.0f;
		}

		const static float Random(float) {
			return std::uniform_real_distribution<float>(-1.0f, 1.0f)(rng);
		}

		const static double Random(double) {
			return std::uniform_real_distribution<double>(-1.0, 1.0)(rng);
		}

		const static long double Random(long double) {
			return std::uniform_real_distribution<long double>(-1.0l, 1.0l)(rng);
		}

		const static char Random(char) {
			return std::uniform_int_distribution<char>(std::numeric_limits<char>::min(), std::numeric_limits<char>::max())(rng);
		}

		const static unsigned char Random(unsigned char) {
			return std::uniform_int_distribution<unsigned char>(std::numeric_limits<unsigned char>::min(), std::numeric_limits<unsigned char>::max())(rng);
		}

		const static short Random(short) {
			return std::uniform_int_distribution<short>(std::numeric_limits<short>::min(), std::numeric_limits<short>::max())(rng);
		}

		const static unsigned short Random(unsigned short) {
			return std::uniform_int_distribution<unsigned short>(std::numeric_limits<unsigned short>::min(), std::numeric_limits<unsigned short>::max())(rng);
		}

		const static long Random(long) {
			return std::uniform_int_distribution<long>(std::numeric_limits<long>::min(), std::numeric_limits<long>::max())(rng);
		}

		const static unsigned long Random(unsigned long) {
			return std::uniform_int_distribution<unsigned long>(std::numeric_limits<unsigned long>::min(), std::numeric_limits<unsigned long>::max())(rng);
		}

		const static long long Random(long long) {
			return std::uniform_int_distribution<long long>(std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max())(rng);
		}

		const static unsigned long long Random(unsigned long long) {
			return std::uniform_int_distribution<unsigned long long>(std::numeric_limits<unsigned long long>::min(), std::numeric_limits<unsigned long long>::max())(rng);
		}

		const static int Random(int) {
			return std::uniform_int_distribution<int>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max())(rng);
		}

		const static unsigned int Random(unsigned int) {
			return std::uniform_int_distribution<unsigned int>(std::numeric_limits<unsigned int>::min(), std::numeric_limits<unsigned int>::max())(rng);
		}

		template<typename Type = float>
		const static Type Random() {
			return Random(Type());
		}

		const static float Random(const float& min, const float& max) {
			return std::uniform_real_distribution<float>(min, max)(rng);
		}

		const static double Random(const double& min, const double& max) {
			return std::uniform_real_distribution<double>(min, max)(rng);
		}

		const static long double Random(const long double& min, const long double& max) {
			return std::uniform_real_distribution<long double>(min, max)(rng);
		}

		const static char Random(const char& min, const char& max) {
			return std::uniform_int_distribution<char>(min, max)(rng);
		}

		const static unsigned char Random(const unsigned char& min, const unsigned char& max) {
			return std::uniform_int_distribution<unsigned char>(min, max)(rng);
		}

		const static short Random(const short& min, const short& max) {
			return std::uniform_int_distribution<short>(min, max)(rng);
		}

		const static unsigned short Random(const unsigned short& min, const unsigned short& max) {
			return std::uniform_int_distribution<unsigned short>(min, max)(rng);
		}

		const static long Random(const long& min, const long& max) {
			return std::uniform_int_distribution<long>(min, max)(rng);
		}

		const static unsigned long Random(const unsigned long& min, const unsigned long& max) {
			return std::uniform_int_distribution<unsigned long>(min, max)(rng);
		}

		const static long long Random(const long long& min, const long long& max) {
			return std::uniform_int_distribution<long long>(min, max)(rng);
		}

		const static unsigned long long Random(const unsigned long long& min, const unsigned long long& max) {
			return std::uniform_int_distribution<unsigned long long>(min, max)(rng);
		}

		const static int Random(const int& min, const int& max) {
			return std::uniform_int_distribution<int>(min, max)(rng);
		}

		const static unsigned int Random(const unsigned int& min, const unsigned int& max) {
			return std::uniform_int_distribution<unsigned int>(min, max)(rng);
		}

		template<typename Type = float>
		const static Type Random(const Type& min, const Type& max) {
			Type tmin = min, tmax = max;
			if(min > max)
				std::swap(tmin, tmax);
			return Random(tmin, tmax);
		}
	}
}
