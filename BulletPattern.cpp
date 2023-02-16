#include "BulletPattern.h"
#include <iostream>

void BulletPattern::Update(float deltaTime) {
	// Update every bullet
	// totalFrames++;									// performance test
	// auto start = std::chrono::steady_clock::now();	// performance test
	for (int i = 0; i < _bullets.size(); i++) {
		_bullets[i].get()->Update(deltaTime);
	}

	// If a bullet is out of bounds, remove it from pattern
	for (int i = 0; i < _bullets.size(); i++) {
		if (_bullets[i].get()->OutsideViewPort) {
			_bullets.erase(_bullets.begin() + i);
		}
	}
	// Update public property
	ActiveBullets = (unsigned int)_bullets.size();

	if (ActiveBullets == 0) {
		PatternEnded = true;
	}

	// Performance test
	/*auto end = std::chrono::steady_clock::now();
	std::cout << "Elapsed time in milliseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n" << std::endl;
	totalTime += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "Avg per frame: " << (float)totalTime / (float)totalFrames << " ns" << std::endl;*/
}

void BulletPattern::Draw() {
	for (int i = 0; i < _bullets.size(); i++) {
		if (_bullets[i].get()) {
			_bullets[i].get()->Draw();
		}
	}
}