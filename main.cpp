#include <iostream>
#include <memory>

#include "game_ai_library/machine_learning/cnn/Galdef.h"
#include "game_ai_library/machine_learning/cnn/Filter.h"
#include "game_ai_library/machine_learning/cnn/Image.h"

int main(int argc, char* argv[]) {
	// std::unique_ptr<gal::Image> image = std::make_unique<gal::Image>(0, gal::CIFAR10_CHANNEL_COUNT, gal::CIFAR10_IMAGE_SIZE, gal::CIFAR10_IMAGE_SIZE);
	std::unique_ptr<gal::Filter<double>> filter = std::make_unique<gal::Filter<double>>(gal::CIFAR10_IMAGE_SIZE, gal::CIFAR10_IMAGE_SIZE);
	std::cout << "Hello, world! " << filter->GetHeight() << std::endl;
	// image.reset();
	filter.reset();
}
