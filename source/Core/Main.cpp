#include <iostream>

#include "Core/Game.hpp"

#if defined _3DS
#include "Driver3DS/Platform3DS.hpp"
#elif defined __SWITCH__
#include "DriverSFML/PlatformSFML.hpp"
#elif defined _WIN64 || defined __CYGWIN__
#include "Driver/SFML/PlatformSFML.hpp"
#elif defined __linux__
#include "DriverSFML/PlatformSFML.hpp"
#else
#error "Target platform is not supported by any driver."
#endif

namespace SuperHaxagon {
	std::unique_ptr<Platform> getPlatform() {
		#if defined _3DS
		return std::make_unique<Platform3DS>();
		#elif defined __SWITCH__
		return std::make_unique<PlatformSFML>();
		#elif defined _WIN64 || defined __CYGWIN__
		return std::make_unique<PlatformSFML>();
		#elif defined __linux__
		return std::make_unique<PlatformSFML>();
		#else
		return nullptr;
		#endif
	}
}

#ifdef _WIN64
int WinMain() {
#else
int main(int, char**) {
#endif
	const auto platform = SuperHaxagon::getPlatform();
	SuperHaxagon::Game game(*platform);
	return game.run();
}