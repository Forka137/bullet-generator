#pragma once
#include <vector>
#include <memory>
#include "Bullet.h"
class BulletPattern
{
public:
	void Update(float timeDelta);
	void Draw();

	unsigned int ActiveBullets = 0;
	bool PatternEnded = false;

protected:
	Texture2D _texture;
	std::vector<std::unique_ptr<Bullet>> _bullets;

	// Performance test
	// int totalTime = 0;
	// int totalFrames = 0;
};

