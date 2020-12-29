#pragma once

#include <string>

#include "TrainData.h"
#include "NeuralNetwork.h"

namespace gal
{
	class VggNet : public NeuralNetwork
	{
	public:
		VggNet(const TrainData& trainData);
		~VggNet();
	private:
		TrainData* trainData;
	};
}