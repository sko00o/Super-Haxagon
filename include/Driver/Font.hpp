#ifndef SUPER_HAXAGON_FONT_HPP
#define SUPER_HAXAGON_FONT_HPP

#include <string>

namespace SuperHaxagon {
	enum class Alignment {
		LEFT,
		CENTER,
		RIGHT
	};

	struct Color;
	struct Point;

	class Font {
	public:
		Font() = default;
		Font(Font&) = delete;

		virtual int getHeight() const = 0;
		virtual void draw(const Color& color, const Point& position, Alignment alignment, std::string text) const = 0;
	};
}

#endif //SUPER_HAXAGON_FONT_HPP