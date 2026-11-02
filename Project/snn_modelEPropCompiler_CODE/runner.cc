#include "definitions.h"

extern "C" {
// ------------------------------------------------------------------------
// global variables
// ------------------------------------------------------------------------
std::mt19937 hostRNG;
std::uniform_real_distribution<float> standardUniformDistribution(0.000000000e+00f, 1.000000000e+00f);
std::normal_distribution<float> standardNormalDistribution(0.000000000e+00f, 1.000000000e+00f);
std::exponential_distribution<float> standardExponentialDistribution(1.000000000e+00f);


// ------------------------------------------------------------------------
// timers
// ------------------------------------------------------------------------
double initTime = 0.0;
double initSparseTime = 0.0;
double neuronUpdateTime = 0.0;
double presynapticUpdateTime = 0.0;
double postsynapticUpdateTime = 0.0;
double synapseDynamicsTime = 0.0;
double customUpdateGradientLearnTime = 0.0;
double customUpdateGradientLearnTransposeTime = 0.0;
double customUpdateGradientLearnRemapTime = 0.0;
double customUpdateGradientLearnHostTime = 0.0;
double customUpdateResetTime = 0.0;
double customUpdateResetTransposeTime = 0.0;
double customUpdateResetRemapTime = 0.0;
double customUpdateResetHostTime = 0.0;
double customUpdateSoftmax1Time = 0.0;
double customUpdateSoftmax1TransposeTime = 0.0;
double customUpdateSoftmax1RemapTime = 0.0;
double customUpdateSoftmax1HostTime = 0.0;
double customUpdateSoftmax2Time = 0.0;
double customUpdateSoftmax2TransposeTime = 0.0;
double customUpdateSoftmax2RemapTime = 0.0;
double customUpdateSoftmax2HostTime = 0.0;
double customUpdateSoftmax3Time = 0.0;
double customUpdateSoftmax3TransposeTime = 0.0;
double customUpdateSoftmax3RemapTime = 0.0;
double customUpdateSoftmax3HostTime = 0.0;
// ------------------------------------------------------------------------
// merged group arrays
// ------------------------------------------------------------------------
}  // extern "C"
void allocateMem() {
    // ------------------------------------------------------------------------
    // global variables
    // ------------------------------------------------------------------------
     {
        uint32_t seedData[std::mt19937::state_size];
        std::random_device seedSource;
        for(int i = 0; i < std::mt19937::state_size; i++) {
            seedData[i] = seedSource();
        }
        std::seed_seq seeds(std::begin(seedData), std::end(seedData));
        hostRNG.seed(seeds);
    }
    
    // ------------------------------------------------------------------------
    // timers
    // ------------------------------------------------------------------------
}

void freeMem() {
    // ------------------------------------------------------------------------
    // global variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // timers
    // ------------------------------------------------------------------------
}

void stepTime(unsigned long long timestep, unsigned long long numRecordingTimesteps) {
    const float t = timestep * 1.000000000e+00f;
    updateSynapses(t);
    updateNeurons(t); 
}

