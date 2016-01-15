#ifndef __FUDANDNN_MODEL_H
#define __FUDANDNN_MODEL_H
#include "Network.h"
#include "criteria\Criteria.h"
#include "criteria\Mse.h"
#include "util\XMLInput.h"

class Model{
public:
	Model();
	size_t addLinearLayerToNetwork(size_t visualUnit, size_t hiddenUnit, size_t init_scheme, size_t solver_type, 
		double regularizationRate,double weightLearningRate, double biasLearningRate, double momentumRate, double dropoutLayer);
	size_t addNonlinearLayerToNetwork(size_t visualUnit, size_t type, double s, double lb, double ub, double prec, double ic);

	size_t addEdgeToNetwork(size_t inID, size_t outID);
	size_t addInputEdgeToNetwork(size_t inputId, size_t layerId);

	void removeNodeInNetwork(size_t id);

	size_t addInput(size_t type,string fileName);
	size_t linkInputToNetwork(size_t inputId);
	size_t setCriteria(size_t type,size_t unit);

	void run();

	void setTrainingTimes(size_t trainingTimes);
	void setBatchSize(size_t batchSize);

protected:
	size_t currentInputId = 0;
	vector<shared_ptr<Input>> inputs;
	shared_ptr<Criteria> criteria;
	shared_ptr<Network> network;
	size_t trainingTimes;
	size_t batchSize;
	//map id to input
	map<size_t, shared_ptr<Input>> inputMap;
};
#endif;