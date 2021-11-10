#pragma once
#include <ostream>
#include <math.h>

#undef RGB
#undef HSV
#undef HSL
#undef CMYK

namespace ZCPP
{
	namespace Color
	{
		// /-----------------------------------------------\
		// | ZCPP::Color Header                            |
		// |                                               |
		// | Floating point range: < 0.0 - 1.0 >           |
		// | Integer range         < 0   - 255 >           |
		// |                                               |
		// | Current supported types:                      |
		// | RGB32 - Base type                             |
		// | RGB  |  HSV  |  HSL  |  CMYK                  |
		// |                                               |
		// | Conversion to type:   To_TYPE(value)          |
		// |                                               |
		// | Extra functions:                              |
		// | RGB_TO_HUE(RGB) - Converts rgb to a hue       |
		// | HUE_TO_RGB(HUE) - Converts a hue to rgb       |
		// |                                     - Zyphery |
		// \-----------------------------------------------/

		// /-----------------------------------------------\
		// | Color Variable  Types                         |
		// \-----------------------------------------------/

		typedef unsigned char BYTE;

		// /-----------------------------------------------\
		// | Primary Math Functions                        |
		// \-----------------------------------------------/

		float max(float _x, float _y) { if (_x > _y) return _x; return _y; }
		float min(float _x, float _y) { if (_x < _y) return _x; return _y; }
		float mod(float _x, float _y) { return fmod(_x, _y); }
		float abs(float _x) { if (_x < 0.0f) return -_x; return _x; }

		BYTE byte_clamp(float _x) {
			if (_x < 0.0f) return static_cast<BYTE>(0);
			else if (_x > 1.0f) return static_cast<BYTE>(255);
			return static_cast<BYTE>(_x * 255.0f);
		}

		// /-----------------------------------------------\
		// | Color Class Definitions                       |
		// \-----------------------------------------------/

		class RGB32;
		class RGB;
		class HSV;
		class HSL;
		class CMYK;

		// < Utilizes 8bit int >
		class RGB32
		{
		public:
			// < Red >
			// 0 - 255
			BYTE r;
			// < Green >
			// 0 - 255
			BYTE g;
			// < Blue >
			// 0 - 255
			BYTE b;
			// < Alpha >
			// 0 - 255
			BYTE a;

			RGB32(BYTE red, BYTE green, BYTE blue, BYTE alpha) : r(red), g(green), b(blue), a(alpha) {}
			RGB32(BYTE red, BYTE green, BYTE blue) : r(red), g(green), b(blue), a(255) {}
			RGB32() : r(0), g(0), b(0), a(255) {}

			bool operator == (const RGB32& rhs) { return this->r == rhs.r && this->g == rhs.g && this->b == rhs.b && this->a == rhs.a; }
			bool operator != (const RGB32& rhs) { return !(*this == rhs); }

			RGB32 operator = (const RGB& rhs);
			RGB32 operator = (const HSV& rhs);
			RGB32 operator = (const HSL& rhs);
			RGB32 operator = (const CMYK& rhs);
			friend std::ostream& operator << (std::ostream& os, const RGB32& rgb32);
		};

		// < Utilizes 32bit float >
		class RGB
		{
		public:
			// < Red >
			// 0.0 - 1.0
			float r;
			// < Green >
			// 0.0 - 1.0
			float g;
			// < Blue >
			// 0.0 - 1.0
			float b;
			// < Alpha >
			// 0.0 - 1.0
			float a;

			RGB(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}
			RGB(float red, float green, float blue) : r(red), g(green), b(blue), a(1.0f) {}
			RGB() : r(0.0f), g(0.0f), b(0.0f), a(1.0f) {}

			bool operator == (const RGB& rhs) { return this->r == rhs.r && this->g == rhs.g && this->b == rhs.b && this->a == rhs.a; }
			bool operator != (const RGB& rhs) { return !(*this == rhs); }

			RGB operator * (const RGB& rhs) { return RGB(this->r * rhs.r, this->g * rhs.g, this->b * rhs.b, this->a * rhs.a); }
			RGB operator / (const RGB& rhs) { return RGB(this->r / rhs.r, this->g / rhs.g, this->b / rhs.b, this->a / rhs.a); }

			RGB operator * (const float& rhs) { return RGB(this->r * rhs, this->g * rhs, this->b * rhs, this->a * rhs); }
			RGB operator / (const float& rhs) { return RGB(this->r / rhs, this->g / rhs, this->b / rhs, this->a / rhs); }

			RGB operator + (const RGB& rhs) { return RGB(this->r + rhs.r, this->g + rhs.g, this->b + rhs.b, this->a + rhs.a); }
			RGB operator - (const RGB& rhs) { return RGB(this->r - rhs.r, this->g - rhs.g, this->b - rhs.b, this->a - rhs.a); }

			RGB operator = (const RGB32& rhs);
			RGB operator = (const HSV& rhs);
			RGB operator = (const HSL& rhs);
			RGB operator = (const CMYK& rhs);
			friend std::ostream& operator << (std::ostream& os, const RGB& rgb);
		};

		// < Utilizes 32bit float >
		class HSV
		{
		public:
			// < Hue >
			// 0.0 - 1.0
			float h;
			// < Saturation >
			// 0.0 - 1.0
			float s;
			// < Value >
			// 0.0 - 1.0
			float v;
			// < Alpha >
			// 0.0 - 1.0
			float a;

			HSV(float hue, float saturation, float value, float alpha) : h(hue), s(saturation), v(value), a(alpha) {}
			HSV(float hue, float saturation, float value) : h(hue), s(saturation), v(value), a(1.0f) {}
			HSV() : h(0.0f), s(0.0f), v(0.0f), a(1.0f) {}

			bool operator == (const HSV& rhs) { return this->h == rhs.h && this->s == rhs.s && this->v == rhs.v && this->a == rhs.a; }
			bool operator != (const HSV& rhs) { return !(*this == rhs); }

			HSV operator * (const HSV& rhs) { return HSV(this->h * rhs.h, this->s * rhs.s, this->v * rhs.v, this->a * rhs.a); }
			HSV operator / (const HSV& rhs) { return HSV(this->h / rhs.h, this->s / rhs.s, this->v / rhs.v, this->a / rhs.a); }

			HSV operator = (const RGB32& rhs);
			HSV operator = (const RGB& rhs);
			HSV operator = (const HSL& rhs);
			HSV operator = (const CMYK& rhs);
			friend std::ostream& operator << (std::ostream& os, const HSV& hsv);
		};

		// < Utilizes 32bit float >
		class HSL
		{
		public:
			// < Hue >
			// 0.0 - 1.0
			float h;
			// < Saturation >
			// 0.0 - 1.0
			float s;
			// < Lightness >
			// 0.0 - 1.0
			float l;
			// < Alpha >
			// 0.0 - 1.0
			float a;

			HSL(float hue, float saturation, float lightness, float alpha) : h(hue), s(saturation), l(lightness), a(alpha) {}
			HSL(float hue, float saturation, float lightness) : h(hue), s(saturation), l(lightness), a(1.0f) {}
			HSL() : h(0.0f), s(0.0f), l(0.0f), a(1.0f) {}

			bool operator == (const HSL& rhs) { return this->h == rhs.h && this->s == rhs.s && this->l == rhs.l && this->a == rhs.a; }
			bool operator != (const HSL& rhs) { return !(*this == rhs); }

			HSL operator * (const HSL& rhs) { return HSL(this->h * rhs.h, this->s * rhs.s, this->l * rhs.l, this->a * rhs.a); }
			HSL operator / (const HSL& rhs) { return HSL(this->h / rhs.h, this->s / rhs.s, this->l / rhs.l, this->a / rhs.a); }

			HSL operator = (const RGB32& rhs);
			HSL operator = (const RGB& rhs);
			HSL operator = (const HSV& rhs);
			HSL operator = (const CMYK& rhs);
			friend std::ostream& operator << (std::ostream& os, const HSL& hsl);
		};

		// < Utilizes 32bit float >
		class CMYK
		{
		public:
			// < Cyan >
			// 0.0 - 1.0
			float c;
			// < Magenta >
			// 0.0 - 1.0
			float m;
			// < Yellow >
			// 0.0 - 1.0
			float y;
			// < Black >
			// 0.0 - 1.0
			float k;
			// < Alpha >
			// 0.0 - 1.0
			float a;

			CMYK(float cyan, float magenta, float yellow, float black, float alpha) : c(cyan), m(magenta), y(yellow), k(black), a(alpha) {}
			CMYK(float cyan, float magenta, float yellow, float black) : c(cyan), m(magenta), y(yellow), k(black), a(1.0f) {}
			CMYK() : c(0.0f), m(0.0f), y(0.0f), k(0.0f), a(1.0f) {}

			bool operator == (const CMYK& rhs) { return this->c == rhs.c && this->m == rhs.m && this->y == rhs.y && this->k == rhs.k && this->a == rhs.a; }
			bool operator != (const CMYK& rhs) { return !(*this == rhs); }

			CMYK operator * (const CMYK& rhs) { return CMYK(this->c * rhs.c, this->m * rhs.m, this->y * rhs.y, this->k * rhs.k, this->a * rhs.a); }
			CMYK operator / (const CMYK& rhs) { return CMYK(this->c / rhs.c, this->m / rhs.m, this->y / rhs.y, this->k * rhs.k, this->a / rhs.a); }

			CMYK operator = (const RGB32& rhs);
			CMYK operator = (const RGB& rhs);
			CMYK operator = (const HSV& rhs);
			CMYK operator = (const HSL& rhs);
			friend std::ostream& operator << (std::ostream& os, const CMYK& cmyk);
		};

		// /-----------------------------------------------\
		// | Function Declarations                         |
		// \-----------------------------------------------/

		RGB RGB_TO_GRAYSCALE(RGB);
		RGB32 RGB_TO_RGB32(RGB);
		HSV RGB_TO_HSV(RGB);
		HSL RGB_TO_HSL(RGB);
		CMYK RGB_TO_CMYK(RGB);

		HSV HSV_TO_GRAYSCALE(HSV);
		RGB32 HSV_TO_RGB32(HSV);
		RGB HSV_TO_RGB(HSV);
		HSL HSV_TO_HSV(HSV);
		CMYK HSV_TO_CMYK(HSV);

		HSL HSL_TO_GRAYSCALE(HSL);
		RGB32 HSL_TO_RGB32(HSL);
		RGB HSL_TO_RGB(HSL);
		HSV HSL_TO_HSV(HSL);
		CMYK HSL_TO_CMYK(HSL);

		CMYK CMYK_TO_GRAYSCALE(CMYK);
		RGB32 CMYK_TO_RGB32(CMYK);
		RGB CMYK_TO_RGB(CMYK);
		HSV CMYK_TO_HSV(CMYK);
		HSL CMYK_TO_HSL(CMYK);

		RGB32 RGB32_TO_GRAYSCALE(RGB32);
		RGB RGB32_TO_RGB(RGB32);
		HSV RGB32_TO_HSV(RGB32);
		HSL RGB32_TO_HSL(RGB32);
		CMYK RGB32_TO_CMYK(RGB32);

		// /-----------------------------------------------\
		// | Helper Functions                              |
		// \-----------------------------------------------/

		float RGB_TO_HUE(RGB rgb)
		{
			float hue = 0.0f;

			float cMax = max(max(rgb.r, rgb.g), rgb.b);
			float cMin = min(min(rgb.r, rgb.g), rgb.b);
			float delta = cMax - cMin;

			if (delta == 0.0f) {
				hue = 0.0f;
			}
			else if (cMax == rgb.r) {
				hue = (rgb.g - rgb.b) / delta;
			}
			else if (cMax == rgb.g) {
				hue = 2.0f + ((rgb.b - rgb.r) / delta);
			}
			else if (cMax == rgb.b) {
				hue = 4.0f + ((rgb.r - rgb.g) / delta);
			}

			hue = (hue * 60.0f) * .0027777777777f;
			if (hue < 0)
				hue++;

			return hue;
		}

		RGB HUE_TO_RGB(float hue = 1.0f)
		{
			RGB rgb;

			float h = mod(hue, 1.0f) * 360.0f;
			float X = (1.0f - abs(mod(h * 0.01666666666f, 2) - 1.0f));

			if (hue >= 0.0f && hue < 60.0f) {
				rgb = RGB(1.0f, X, 0.0f);
			}
			else if (hue >= 60.0f && hue < 120.0f) {
				rgb = RGB(X, 1.0f, 0.0f);
			}
			else if (hue >= 120.0f && hue < 180.0f) {
				rgb = RGB(0.0f, 1.0f, X);
			}
			else if (hue >= 180.0f && hue < 240.0f) {
				rgb = RGB(0.0f, X, 1.0f);
			}
			else if (hue >= 240.0f && hue < 300.0f) {
				rgb = RGB(X, 0.0f, 1.0f);
			}
			else {
				rgb = RGB(1.0f, 0.0f, X);
			}

			return rgb;
		}

		// /-----------------------------------------------\
		// | Function Definitions                          |
		// \-----------------------------------------------/

		// < RGB32 >

		RGB32 RGB32_TO_GRAYSCALE(RGB32 rgb32)
		{
			RGB rgb = RGB32_TO_RGB(rgb32);
			rgb = RGB_TO_GRAYSCALE(rgb);
			return RGB_TO_RGB32(rgb);
		}
		RGB RGB32_TO_RGB(RGB32 rgb32)
		{
			RGB rgb;
			float i = 1.0 / 255.0;
			rgb.r = static_cast<float>(rgb32.r) * i;
			rgb.g = static_cast<float>(rgb32.g) * i;
			rgb.b = static_cast<float>(rgb32.b) * i;
			rgb.a = static_cast<float>(rgb32.a) * i;
			return rgb;
		}
		HSV RGB32_TO_HSV(RGB32 rgb32)
		{
			RGB rgb = RGB32_TO_RGB(rgb32);
			return RGB_TO_HSV(rgb);
		}
		HSL RGB32_TO_HSL(RGB32 rgb32)
		{
			RGB rgb = RGB32_TO_RGB(rgb32);
			return RGB_TO_HSL(rgb);
		}
		CMYK RGB32_TO_CMYK(RGB32 rgb32)
		{
			RGB rgb = RGB32_TO_RGB(rgb32);
			return RGB_TO_CMYK(rgb);
		}
		std::ostream& operator << (std::ostream& os, const RGB32& rgb32)
		{
			os << "R: " << (int)rgb32.r << " G: " << (int)rgb32.g << " B: " << (int)rgb32.b << " A: " << (int)rgb32.a;
			return os;
		}

		// < RGB > 

		RGB RGB_TO_GRAYSCALE(RGB rgb)
		{
			float value = 0.2126f * rgb.r + 0.7152f * rgb.g + 0.0722f * rgb.b;
			return RGB(value, value, value, rgb.a);
		}
		HSV RGB_TO_HSV(RGB rgb)
		{
			HSV hsv;

			float cMax = max(max(rgb.r, rgb.g), rgb.b);
			float cMin = min(min(rgb.r, rgb.g), rgb.b);
			float delta = cMax - cMin;

			hsv.v = cMax;

			if (cMax == 0.0f) {
				hsv.s = 0.0f;
			}
			else {
				hsv.s = delta / cMax;
			}

			if (delta == 0.0f) {
				hsv.h = 0.0f;
			}
			else if (cMax == rgb.r) {
				hsv.h = (rgb.g - rgb.b) / delta;
			}
			else if (cMax == rgb.g) {
				hsv.h = 2.0f + ((rgb.b - rgb.r) / delta);
			}
			else if (cMax == rgb.b) {
				hsv.h = 4.0f + ((rgb.r - rgb.g) / delta);
			}

			hsv.h = (hsv.h * 60.0f) * .0027777777777f;
			if (hsv.h < 0)
				hsv.h++;

			hsv.a = rgb.a;
			return hsv;
		}
		HSL RGB_TO_HSL(RGB rgb)
		{
			HSL hsl;

			float cMax = max(max(rgb.r, rgb.g), rgb.b);
			float cMin = min(min(rgb.r, rgb.g), rgb.b);
			float delta = cMax - cMin;

			hsl.l = (cMax + cMin) * 0.5f;

			if (delta == 0.0f) {
				hsl.h = 0.0f;
				hsl.s = 0.0f;
			}
			else {
				hsl.s = delta / (1.0f - abs(2.0f * hsl.l - 1.0f));
				if (cMax == rgb.r) {
					hsl.h = (rgb.g - rgb.b) / delta;
				}
				else if (cMax == rgb.g) {
					hsl.h = 2.0f + ((rgb.b - rgb.r) / delta);
				}
				else if (cMax == rgb.b) {
					hsl.h = 4.0f + ((rgb.r - rgb.g) / delta);
				}
			}

			hsl.h = (hsl.h * 60.0f) * .0027777777777f;
			if (hsl.h < 0)
				hsl.h++;

			hsl.a = rgb.a;
			return hsl;
		}
		CMYK RGB_TO_CMYK(RGB rgb)
		{
			CMYK cmyk;
			float ik;

			cmyk.k = 1.0f - max(max(rgb.r, rgb.g), rgb.b);
			ik = 1.0f / (1.0f - cmyk.k);

			cmyk.c = (1.0f - rgb.r - cmyk.k) * ik;
			cmyk.m = (1.0f - rgb.g - cmyk.k) * ik;
			cmyk.y = (1.0f - rgb.b - cmyk.k) * ik;

			cmyk.a = rgb.a;
			return cmyk;

		}
		RGB32 RGB_TO_RGB32(RGB rgb)
		{
			RGB32 rgb32{};
			rgb32.r = byte_clamp(rgb.r);
			rgb32.g = byte_clamp(rgb.g);
			rgb32.b = byte_clamp(rgb.b);
			rgb32.a = byte_clamp(rgb.a);
			return rgb32;
		}
		std::ostream& operator << (std::ostream& os, const RGB& rgb)
		{
			os << "R: " << rgb.r << " G: " << rgb.g << " B: " << rgb.b << " A: " << rgb.a;
			return os;
		}

		// < HSV >

		HSV HSV_TO_GRAYSCALE(HSV hsv)
		{
			RGB rgb = HSV_TO_RGB(hsv);
			rgb = RGB_TO_GRAYSCALE(rgb);
			return RGB_TO_HSV(rgb);
		}
		RGB HSV_TO_RGB(HSV hsv)
		{
			RGB rgb;

			float h = mod(hsv.h, 1.0f) * 360.0f;

			float C = hsv.s * hsv.v;
			float X = C * (1.0f - abs(mod(h * 0.01666666666f, 2) - 1.0f));
			float m = hsv.v - C;

			if (h >= 0.0f && h < 60.0f) {
				rgb = RGB(C, X, 0.0f);
			}
			else if (h >= 60.0f && h < 120.0f) {
				rgb = RGB(X, C, 0.0f);
			}
			else if (h >= 120.0f && h < 180.0f) {
				rgb = RGB(0.0f, C, X);
			}
			else if (h >= 180.0f && h < 240.0f) {
				rgb = RGB(0.0f, X, C);
			}
			else if (h >= 240.0f && h < 300.0f) {
				rgb = RGB(X, 0.0f, C);
			}
			else {
				rgb = RGB(C, 0.0f, X);
			}

			rgb = RGB(rgb.r + m, rgb.g + m, rgb.b + m);

			rgb.a = hsv.a;
			return rgb;
		}
		HSL HSV_TO_HSL(HSV hsv)
		{
			HSL hsl;

			hsl.h = hsv.h;
			hsl.l = (2.0f - hsv.s) * hsv.v;
			hsl.s = hsv.s * hsv.v;

			if (hsl.l <= 1.0f) {
				hsl.s = hsl.s / hsl.l;
			}
			else {
				hsl.s = hsl.s / (2.0f - hsl.l);
			}

			hsl.l *= 0.5f;

			hsl.a = hsv.a;
			return hsl;
		}
		CMYK HSV_TO_CMYK(HSV hsv)
		{
			RGB rgb = HSV_TO_RGB(hsv);
			return RGB_TO_CMYK(rgb);
		}
		RGB32 HSV_TO_RGB32(HSV hsv)
		{
			RGB rgb = HSV_TO_RGB(hsv);
			return RGB_TO_RGB32(rgb);
		}
		std::ostream& operator << (std::ostream& os, const HSV& hsv)
		{
			os << "H: " << hsv.h << " S: " << hsv.s << " V: " << hsv.v << " A: " << hsv.a;
			return os;
		}

		// < HSL >

		HSL HSL_TO_GRAYSCALE(HSL hsl)
		{
			RGB rgb = HSL_TO_RGB(hsl);
			rgb = RGB_TO_GRAYSCALE(rgb);
			return RGB_TO_HSL(rgb);
		}
		RGB HSL_TO_RGB(HSL hsl)
		{
			RGB rgb;

			float h = mod(hsl.h, 1.0f) * 360.0f;
			float s = hsl.s;
			float l = hsl.l;

			float C = (1.0f - abs(2.0f * l - 1.0f)) * s;
			float X = C * (1.0f - abs(mod(h * 0.01666666666f, 2) - 1.0f));
			float m = l - C * 0.5f;

			if (h >= 0 && h < 60) {
				rgb = RGB(C, X, 0.0f);
			}
			else if (h >= 60 && h < 120) {
				rgb = RGB(X, C, 0.0f);
			}
			else if (h >= 120 && h < 180) {
				rgb = RGB(0.0f, C, X);
			}
			else if (h >= 180 && h < 240) {
				rgb = RGB(0.0f, X, C);
			}
			else if (h >= 240 && h < 300) {
				rgb = RGB(X, 0.0f, C);
			}
			else {
				rgb = RGB(C, 0.0f, X);
			}

			rgb = RGB(rgb.r + m, rgb.g + m, rgb.b + m);

			rgb.a = hsl.a;
			return rgb;
		}
		HSV HSL_TO_HSV(HSL hsl)
		{
			HSV hsv;

			hsv.h = hsl.h;

			hsl.l *= 2.0f;

			if (hsl.l <= 1.0f) {
				hsl.s *= hsl.l;
			}
			else {
				hsl.s *= (2.0f - hsl.l);
			}

			hsv.v = (hsl.l + hsl.s) * 0.5f;
			hsv.s = (2.0f * hsl.s) / (hsl.l + hsl.s);

			hsv.a = hsl.a;
			return hsv;
		}
		CMYK HSL_TO_CMYK(HSL hsl)
		{
			RGB rgb = HSL_TO_RGB(hsl);
			return RGB_TO_CMYK(rgb);
		}
		RGB32 HSL_TO_RGB32(HSL hsl)
		{
			RGB rgb = HSL_TO_RGB(hsl);
			return RGB_TO_RGB32(rgb);
		}
		std::ostream& operator << (std::ostream& os, const HSL& hsl)
		{
			os << "H: " << hsl.h << " S: " << hsl.s << " L: " << hsl.l << " A: " << hsl.a;
			return os;
		}

		// < CMYK >

		CMYK CMYK_TO_GRAYSCALE(CMYK cmyk)
		{
			RGB rgb = CMYK_TO_RGB(cmyk);
			rgb = RGB_TO_GRAYSCALE(rgb);
			return RGB_TO_CMYK(rgb);
		}
		RGB CMYK_TO_RGB(CMYK cmyk)
		{
			RGB rgb;
			rgb.r = (1.0f - cmyk.c) * (1.0f - cmyk.k);
			rgb.g = (1.0f - cmyk.m) * (1.0f - cmyk.k);
			rgb.b = (1.0f - cmyk.y) * (1.0f - cmyk.k);
			rgb.a = cmyk.a;
			return rgb;
		}
		HSL CMYK_TO_HSL(CMYK cmyk)
		{
			RGB rgb = CMYK_TO_RGB(cmyk);
			return RGB_TO_HSL(rgb);
		}
		HSV CMYK_TO_HSV(CMYK cmyk)
		{
			RGB rgb = CMYK_TO_RGB(cmyk);
			return RGB_TO_HSV(rgb);
		}
		RGB32 CMYK_TO_RGB32(CMYK cmyk)
		{
			RGB rgb = CMYK_TO_RGB(cmyk);
			return RGB_TO_RGB32(rgb);
		}
		std::ostream& operator << (std::ostream& os, const CMYK& cmyk)
		{
			os << "C: " << cmyk.c << " M: " << cmyk.m << " Y: " << cmyk.y << " K: " << cmyk.k << " A: " << cmyk.a;
			return os;
		}

		// < Conversions >

		RGB32 To_grayscale(RGB32 rgb32) { return RGB32_TO_GRAYSCALE(rgb32); }
		RGB To_grayscale(RGB rgb) { return RGB_TO_GRAYSCALE(rgb); }
		HSV To_grayscale(HSV hsv) { return HSV_TO_GRAYSCALE(hsv); }
		HSL To_grayscale(HSL hsl) { return HSL_TO_GRAYSCALE(hsl); }
		CMYK To_grayscale(CMYK cmyk) { return CMYK_TO_GRAYSCALE(cmyk); }

		RGB32 To_RGB32(RGB rgb) { return RGB_TO_RGB32(rgb); }
		RGB32 To_RGB32(HSV hsv) { return HSV_TO_RGB32(hsv); }
		RGB32 To_RGB32(HSL hsl) { return HSL_TO_RGB32(hsl); }
		RGB32 To_RGB32(CMYK cmyk) { return CMYK_TO_RGB32(cmyk); }

		RGB To_RGB(RGB32 rgb32) { return RGB32_TO_RGB(rgb32); }
		RGB To_RGB(HSV hsv) { return HSV_TO_RGB(hsv); }
		RGB To_RGB(HSL hsl) { return HSL_TO_RGB(hsl); }
		RGB To_RGB(CMYK cmyk) { return CMYK_TO_RGB(cmyk); }

		HSV To_HSV(RGB32 rgb32) { return RGB32_TO_HSV(rgb32); }
		HSV To_HSV(RGB rgb) { return RGB_TO_HSV(rgb); }
		HSV To_HSV(HSL hsl) { return HSL_TO_HSV(hsl); }
		HSV To_HSV(CMYK cmyk) { return CMYK_TO_HSV(cmyk); }

		HSL To_HSL(RGB32 rgb32) { return RGB32_TO_HSL(rgb32); }
		HSL To_HSL(RGB rgb) { return RGB_TO_HSL(rgb); }
		HSL To_HSL(HSV hsv) { return HSV_TO_HSL(hsv); }
		HSL To_HSL(CMYK cmyk) { return CMYK_TO_HSL(cmyk); }

		CMYK To_CMYK(RGB32 rgb32) { return RGB32_TO_CMYK(rgb32); }
		CMYK To_CMYK(RGB rgb) { return RGB_TO_CMYK(rgb); }
		CMYK To_CMYK(HSV hsv) { return HSV_TO_CMYK(hsv); }
		CMYK To_CMYK(HSL hsl) { return HSL_TO_CMYK(hsl); }
	}
}