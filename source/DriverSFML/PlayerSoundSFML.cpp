#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

#include "DriverSFML/PlayerSoundSFML.hpp"

namespace SuperHaxagon {
	PlayerSoundSFML::PlayerSoundSFML(std::unique_ptr<sf::Sound> sound) : _sound(std::move(sound)) {}

	PlayerSoundSFML::~PlayerSoundSFML() {
		_sound->stop();
	}

	void PlayerSoundSFML::setLoop(const bool loop) {
		_sound->setLoop(loop);
	}

	void PlayerSoundSFML::play() {
		_sound->play();
	}

	bool PlayerSoundSFML::isDone() {
		return _sound->getStatus() == sf::SoundSource::Stopped;
	}

	double PlayerSoundSFML::getVelocity() {
		return 0;
	}
}
