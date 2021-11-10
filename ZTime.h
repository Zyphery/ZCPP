#pragma once
#include <chrono>

namespace ZCPP
{
	namespace Time
	{
		// /-----------------------------------------------\
		// | ZCPP::Time Header                             |
		// |                                               |
		// | zTime - Measures time in milliseconds         |
		// | zTimePrecise - Measures time in seconds       |
		// |                                               |
		// | Time_Instance - Registers a point in time     |
		// |                                               |
		// | Extra functions:                              |
		// | GetClock() - Milliseconds since start         |
		// | Wait(ms) - Thread halts for milliseconds      |
		// |                                               |
		// | CONVERT_SECONDS - Milliseconds to seconds     |
		// | CONVERT_MINUTES - Milliseconds to minutes     |
		// | CONVERT_HOURS - Milliseconds to hours         |
		// | CONVERT_DAYS - Milliseconds to days           |
		// |                                     - Zyphery |
		// \-----------------------------------------------/
		
		// /-----------------------------------------------\
		// | Time Vartiable Types                          |
		// \-----------------------------------------------/

		typedef signed long long int zTime;
		typedef double zTimePrecise;
		typedef std::chrono::steady_clock::time_point zTimePoint;

		// /-----------------------------------------------\
		// | Application Variables                         |
		// \-----------------------------------------------/

		// Time of program start         (Do not edit or remove)
		static inline const zTimePoint program_start = std::chrono::steady_clock::now();
		// Milliseconds to seconds       (Do not edit or remove)
		static inline const zTimePrecise CONVERT_SECONDS = 1.0 / 1000.0;
		// Milliseconds to minutes       (Do not edit or remove)
		static inline const zTimePrecise CONVERT_MINUTES = 1.0 / 60000.0;
		// Milliseconds to hours         (Do not edit or remove)
		static inline const zTimePrecise CONVERT_HOURS = 1.0 / 3600000.0;
		// Milliseconds to days          (Do not edit or remove)
		static inline const zTimePrecise CONVERT_DAYS = 1.0 / 86400000.0;

		// /-----------------------------------------------\
		// | Helper Functions                              |
		// \-----------------------------------------------/

		// Get the current program clock time (in seconds)
		static zTime GetClock()
		{
			zTimePoint now = std::chrono::steady_clock::now();
			auto span = std::chrono::duration_cast<std::chrono::milliseconds>(now - program_start);
			return span.count();
		}

		// Halt the current thread for said amount of milliseconds
		static void Wait(const zTime milliseconds)
		{
			if (milliseconds <= 0)
				return;

			zTime now = GetClock();
			zTime start = GetClock();

			while (now - start < milliseconds)
				now = GetClock();

			return;
		}

		// /-----------------------------------------------\
		// | Primary Time Class                            |
		// \-----------------------------------------------/

		// Primary class of capturing a time point
		class Time_Instance
		{
		private:
			zTime time;

		public:
			Time_Instance() { time = 0; }

			// Returns the current Time_Instance's time in seconds
			zTimePrecise GetTime() const { return static_cast<zTimePrecise>(time) * CONVERT_SECONDS; }
			zTime GetRawTime() const { return time; }

			// Returns a Time_Instance set to the current program's run time
			static Time_Instance Now() { Time_Instance ti; ti.time = GetClock(); return ti; }
			// Sets this Time_Instance to the current program's run time
			const void IsNow() { *this = Now(); }

			// Returns two Time_Instances added together
			static Time_Instance Add(const Time_Instance& t1, const Time_Instance& t2)
			{
				Time_Instance time;
				time.time = t1.time + t2.time;
				return time;
			}

			// Returns two Time_Instances subtracted from eachother
			static Time_Instance Subtract(const Time_Instance& t1, const Time_Instance& t2)
			{
				Time_Instance time;
				time.time = t1.time - t2.time;
				return time;
			}

			// Returns the time between two Time_Instances
			static Time_Instance Difference(const Time_Instance& t1, const Time_Instance& t2)
			{
				Time_Instance time;
				time.time = std::abs(t1.time - t2.time);
				return time;
			}

			void Add(const Time_Instance& t) { *this = Add(*this, t); }
			void Subtract(const Time_Instance& t) { *this = Subtract(*this, t); }
			void Add(const zTime& milliseconds) { this->time += milliseconds; }
			void Subtract(const zTime& milliseconds) { this->time -= milliseconds; }

			Time_Instance TimeToNow() { return Difference(*this, Now()); }
			const zTimePrecise GetSeconds() { return static_cast<zTimePrecise>(time) * CONVERT_SECONDS; }
			const zTimePrecise GetMinutes() { return static_cast<zTimePrecise>(time) * CONVERT_MINUTES; }
			const zTimePrecise GetHours() { return static_cast<zTimePrecise>(time) * CONVERT_HOURS; }
			const zTimePrecise GetDays() { return	static_cast<zTimePrecise>(time) * CONVERT_DAYS; }

			bool operator == (const Time_Instance& rhs) { return time == rhs.time; }
			bool operator != (const Time_Instance& rhs) { return !(time == rhs.time); }
			bool operator <= (const Time_Instance& rhs) { return time <= rhs.time; }
			bool operator >= (const Time_Instance& rhs) { return time >= rhs.time; }
			bool operator <  (const Time_Instance& rhs) { return time < rhs.time; }
			bool operator >  (const Time_Instance& rhs) { return time > rhs.time; }

			Time_Instance operator + (const Time_Instance& rhs) { return Add(*this, rhs); }
			Time_Instance operator - (const Time_Instance& rhs) { return Subtract(*this, rhs); }
			Time_Instance& operator += (const Time_Instance& rhs) { *this = Add(*this, rhs); return *this; }
			Time_Instance& operator -= (const Time_Instance& rhs) { *this = Subtract(*this, rhs); return *this; }

			Time_Instance& operator += (const zTime& milliseconds) { this->Add(milliseconds); return *this; }
			Time_Instance& operator -= (const zTime& milliseconds) { this->Subtract(milliseconds); return *this; }

			friend std::ostream& operator << (std::ostream& os, const Time_Instance& t);
		};

		std::ostream& operator << (std::ostream& os, const Time_Instance& t)
		{
			os << t.GetTime() << "s";
			return os;
		}
	};
};