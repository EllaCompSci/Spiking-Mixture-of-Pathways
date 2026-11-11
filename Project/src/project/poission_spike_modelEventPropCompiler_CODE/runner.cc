#include "definitions.h"

extern "C" {
// ------------------------------------------------------------------------
// global variables
// ------------------------------------------------------------------------
__device__ curandStatePhilox4_32_10_t *d_rng;

// ------------------------------------------------------------------------
// timers
// ------------------------------------------------------------------------
double initTime = 0.0;
double initSparseTime = 0.0;
double neuronUpdateTime = 0.0;
double presynapticUpdateTime = 0.0;
double postsynapticUpdateTime = 0.0;
double synapseDynamicsTime = 0.0;
double customUpdateBatchSoftmax1Time = 0.0;
double customUpdateBatchSoftmax1TransposeTime = 0.0;
double customUpdateBatchSoftmax1RemapTime = 0.0;
double customUpdateBatchSoftmax1HostTime = 0.0;
double customUpdateBatchSoftmax2Time = 0.0;
double customUpdateBatchSoftmax2TransposeTime = 0.0;
double customUpdateBatchSoftmax2RemapTime = 0.0;
double customUpdateBatchSoftmax2HostTime = 0.0;
double customUpdateBatchSoftmax3Time = 0.0;
double customUpdateBatchSoftmax3TransposeTime = 0.0;
double customUpdateBatchSoftmax3RemapTime = 0.0;
double customUpdateBatchSoftmax3HostTime = 0.0;
double customUpdateGradientBatchReduceTime = 0.0;
double customUpdateGradientBatchReduceTransposeTime = 0.0;
double customUpdateGradientBatchReduceRemapTime = 0.0;
double customUpdateGradientBatchReduceHostTime = 0.0;
double customUpdateGradientLearnTime = 0.0;
double customUpdateGradientLearnTransposeTime = 0.0;
double customUpdateGradientLearnRemapTime = 0.0;
double customUpdateGradientLearnHostTime = 0.0;
double customUpdateResetTime = 0.0;
double customUpdateResetTransposeTime = 0.0;
double customUpdateResetRemapTime = 0.0;
double customUpdateResetHostTime = 0.0;
double customUpdateZeroGradientTime = 0.0;
double customUpdateZeroGradientTransposeTime = 0.0;
double customUpdateZeroGradientRemapTime = 0.0;
double customUpdateZeroGradientHostTime = 0.0;
double customUpdateZeroOutPostTime = 0.0;
double customUpdateZeroOutPostTransposeTime = 0.0;
double customUpdateZeroOutPostRemapTime = 0.0;
double customUpdateZeroOutPostHostTime = 0.0;
cudaEvent_t neuronUpdateStart;
cudaEvent_t neuronUpdateStop;
cudaEvent_t presynapticUpdateStart;
cudaEvent_t presynapticUpdateStop;
cudaEvent_t customUpdateBatchSoftmax1Start;
cudaEvent_t customUpdateBatchSoftmax1Stop;
cudaEvent_t customUpdateBatchSoftmax1TransposeStart;
cudaEvent_t customUpdateBatchSoftmax1TransposeStop;
cudaEvent_t customUpdateBatchSoftmax1RemapStart;
cudaEvent_t customUpdateBatchSoftmax1RemapStop;
cudaEvent_t customUpdateBatchSoftmax2Start;
cudaEvent_t customUpdateBatchSoftmax2Stop;
cudaEvent_t customUpdateBatchSoftmax2TransposeStart;
cudaEvent_t customUpdateBatchSoftmax2TransposeStop;
cudaEvent_t customUpdateBatchSoftmax2RemapStart;
cudaEvent_t customUpdateBatchSoftmax2RemapStop;
cudaEvent_t customUpdateBatchSoftmax3Start;
cudaEvent_t customUpdateBatchSoftmax3Stop;
cudaEvent_t customUpdateBatchSoftmax3TransposeStart;
cudaEvent_t customUpdateBatchSoftmax3TransposeStop;
cudaEvent_t customUpdateBatchSoftmax3RemapStart;
cudaEvent_t customUpdateBatchSoftmax3RemapStop;
cudaEvent_t customUpdateGradientBatchReduceStart;
cudaEvent_t customUpdateGradientBatchReduceStop;
cudaEvent_t customUpdateGradientBatchReduceTransposeStart;
cudaEvent_t customUpdateGradientBatchReduceTransposeStop;
cudaEvent_t customUpdateGradientBatchReduceRemapStart;
cudaEvent_t customUpdateGradientBatchReduceRemapStop;
cudaEvent_t customUpdateGradientLearnStart;
cudaEvent_t customUpdateGradientLearnStop;
cudaEvent_t customUpdateGradientLearnTransposeStart;
cudaEvent_t customUpdateGradientLearnTransposeStop;
cudaEvent_t customUpdateGradientLearnRemapStart;
cudaEvent_t customUpdateGradientLearnRemapStop;
cudaEvent_t customUpdateResetStart;
cudaEvent_t customUpdateResetStop;
cudaEvent_t customUpdateResetTransposeStart;
cudaEvent_t customUpdateResetTransposeStop;
cudaEvent_t customUpdateResetRemapStart;
cudaEvent_t customUpdateResetRemapStop;
cudaEvent_t customUpdateZeroGradientStart;
cudaEvent_t customUpdateZeroGradientStop;
cudaEvent_t customUpdateZeroGradientTransposeStart;
cudaEvent_t customUpdateZeroGradientTransposeStop;
cudaEvent_t customUpdateZeroGradientRemapStart;
cudaEvent_t customUpdateZeroGradientRemapStop;
cudaEvent_t customUpdateZeroOutPostStart;
cudaEvent_t customUpdateZeroOutPostStop;
cudaEvent_t customUpdateZeroOutPostTransposeStart;
cudaEvent_t customUpdateZeroOutPostTransposeStop;
cudaEvent_t customUpdateZeroOutPostRemapStart;
cudaEvent_t customUpdateZeroOutPostRemapStop;
cudaEvent_t initStart;
cudaEvent_t initStop;

// ------------------------------------------------------------------------
// merged group arrays
// ------------------------------------------------------------------------
}  // extern "C"
void allocateMem() {
     {
        curandStatePhilox4_32_10_t *hostPtr;
        CHECK_RUNTIME_ERRORS(cudaMalloc(&hostPtr, sizeof(curandStatePhilox4_32_10_t)));
        CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbol(d_rng, &hostPtr, sizeof(void*)));
    }
    // ------------------------------------------------------------------------
    // global variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // timers
    // ------------------------------------------------------------------------
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&neuronUpdateStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&neuronUpdateStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&presynapticUpdateStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&presynapticUpdateStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax1Start));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax1Stop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax1TransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax1TransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax1RemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax1RemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax2Start));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax2Stop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax2TransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax2TransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax2RemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax2RemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax3Start));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax3Stop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax3TransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax3TransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax3RemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateBatchSoftmax3RemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientBatchReduceStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientBatchReduceStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientBatchReduceTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientBatchReduceTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientBatchReduceRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientBatchReduceRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientLearnStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientLearnStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientLearnTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientLearnTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientLearnRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateGradientLearnRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateResetStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateResetStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateResetTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateResetTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateResetRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateResetRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroGradientStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroGradientStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroGradientTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroGradientTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroGradientRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroGradientRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroOutPostStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroOutPostStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroOutPostTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroOutPostTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroOutPostRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&customUpdateZeroOutPostRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&initStart));
    CHECK_RUNTIME_ERRORS(cudaEventCreate(&initStop));
    
}

void freeMem() {
    // ------------------------------------------------------------------------
    // global variables
    // ------------------------------------------------------------------------
    
    // ------------------------------------------------------------------------
    // timers
    // ------------------------------------------------------------------------
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(neuronUpdateStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(neuronUpdateStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(presynapticUpdateStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(presynapticUpdateStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax1Start));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax1Stop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax1TransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax1TransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax1RemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax1RemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax2Start));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax2Stop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax2TransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax2TransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax2RemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax2RemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax3Start));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax3Stop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax3TransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax3TransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax3RemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateBatchSoftmax3RemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientBatchReduceStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientBatchReduceStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientBatchReduceTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientBatchReduceTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientBatchReduceRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientBatchReduceRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientLearnStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientLearnStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientLearnTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientLearnTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientLearnRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateGradientLearnRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateResetStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateResetStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateResetTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateResetTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateResetRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateResetRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroGradientStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroGradientStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroGradientTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroGradientTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroGradientRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroGradientRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroOutPostStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroOutPostStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroOutPostTransposeStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroOutPostTransposeStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroOutPostRemapStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(customUpdateZeroOutPostRemapStop));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(initStart));
    CHECK_RUNTIME_ERRORS(cudaEventDestroy(initStop));
    
}

void stepTime(unsigned long long timestep, unsigned long long numRecordingTimesteps) {
    const float t = timestep * 1.000000000e+00f;
    updateSynapses(t);
    updateNeurons(t); 
    CHECK_RUNTIME_ERRORS(cudaEventSynchronize(neuronUpdateStop));
     {
        float tmp;
        CHECK_RUNTIME_ERRORS(cudaEventElapsedTime(&tmp, neuronUpdateStart, neuronUpdateStop));
        neuronUpdateTime += tmp / 1000.0;
    }
     {
        float tmp;
        CHECK_RUNTIME_ERRORS(cudaEventElapsedTime(&tmp, presynapticUpdateStart, presynapticUpdateStop));
        presynapticUpdateTime += tmp / 1000.0;
    }
}

