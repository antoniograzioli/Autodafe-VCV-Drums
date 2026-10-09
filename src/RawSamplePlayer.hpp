#pragma once

#include <cstdint>

// Embedded samples are unsigned byte arrays containing little-endian, signed
// 16-bit PCM recorded at this rate.
class RawSamplePlayer {
public:
	static constexpr float sampleRate = 44100.0f;

	RawSamplePlayer() = default;
	RawSamplePlayer(const unsigned char *data, unsigned int byteLength) {
		setSample(data, byteLength);
	}

	void setSample(const unsigned char *data, unsigned int byteLength) {
		data_ = data;
		frameCount_ = byteLength / sizeof(int16_t);
		reset();
	}

	void reset() {
		position_ = 0.0f;
	}

	float next(float engineSampleRate) {
		if (!data_ || frameCount_ == 0 || position_ >= frameCount_)
			return 0.0f;

		const unsigned int frame = static_cast<unsigned int>(position_);
		const float fraction = static_cast<float>(position_ - static_cast<double>(frame));
		const float current = pcm(frame);
		const float nextFrame = pcm(frame + 1 < frameCount_ ? frame + 1 : frame);
		const float output = current + (nextFrame - current) * fraction;

		position_ += static_cast<double>(sampleRate) / static_cast<double>(engineSampleRate);
		return output;
	}

private:
	const unsigned char *data_ = nullptr;
	unsigned int frameCount_ = 0;
	double position_ = 0.0;

	float pcm(unsigned int frame) const {
		const unsigned int byte = frame * sizeof(int16_t);
		const uint16_t bits = static_cast<uint16_t>(data_[byte]) |
			(static_cast<uint16_t>(data_[byte + 1]) << 8);
		return static_cast<float>(static_cast<int16_t>(bits)) / 32768.0f;
	}
};
