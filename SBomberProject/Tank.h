#pragma once

#include <stdint.h>
#include <array>
#include <string>

#include "DestroyableGroundObject.h"
#include "LevelGUI.h"

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	Tank(Mediator* mediator) : _m(mediator) {}

	void addToQueue();

private:

	const uint16_t score = 30;

	Mediator* _m;

	static std::array<std::string, 3>messages;
};

