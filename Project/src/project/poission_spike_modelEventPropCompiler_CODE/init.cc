#include "definitions.h"
#include <iostream>
#include <random>
#include <cstdint>

struct MergedNeuronInitGroup0
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    float* __restrict__ Softmax;
    float* __restrict__ V;
    float* __restrict__ VMax;
    float* __restrict__ VMaxTime;
    float* __restrict__ VMaxTimeBack;
    uint8_t* __restrict__ YTrue;
    uint8_t* __restrict__ YTrueBack;
    float* __restrict__ outPostInSyn0;
    
}
;
struct MergedNeuronInitGroup1
 {
    float* __restrict__ V;
    uint32_t* __restrict__ spkSynSpike0;
    uint32_t* __restrict__ spkEventSynSpikeEvent0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkCntEventSynSpikeEvent0;
    float* __restrict__ outPreOutSyn1;
    float* __restrict__ outPreOutSyn0;
    float* __restrict__ outPostInSyn1;
    float* __restrict__ outPostInSyn0;
    uint8_t* __restrict__ BackSpike;
    int32_t* __restrict__ RingWriteStartOffset;
    int32_t* __restrict__ RingWriteOffset;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingReadEndOffset;
    float* __restrict__ RefracTime;
    float* __restrict__ LambdaV;
    float* __restrict__ LambdaI;
    
}
;
struct MergedNeuronInitGroup2
 {
    uint8_t* __restrict__ BackSpike;
    uint32_t* __restrict__ EndSpike;
    int32_t* __restrict__ RingReadEndOffset;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingWriteOffset;
    int32_t* __restrict__ RingWriteStartOffset;
    uint32_t* __restrict__ StartSpike;
    uint32_t* __restrict__ spkCntEventSynSpikeEvent0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkEventSynSpikeEvent0;
    uint32_t* __restrict__ spkSynSpike0;
    
}
;
struct MergedSynapseInitGroup0
 {
    float* __restrict__ Gradient;
    float* __restrict__ g;
    uint32_t numSrcNeurons;
    uint32_t numTrgNeurons;
    uint32_t rowStride;
    
}
;
struct MergedCustomUpdateInitGroup0
 {
    float* __restrict__ SumExpVal;
    
}
;
struct MergedCustomUpdateInitGroup1
 {
    float* __restrict__ MaxVal;
    
}
;
struct MergedCustomWUUpdateInitGroup0
 {
    float* __restrict__ M;
    float* __restrict__ V;
    uint32_t numSrcNeurons;
    uint32_t numTrgNeurons;
    uint32_t rowStride;
    
}
;
struct MergedCustomWUUpdateInitGroup1
 {
    float* __restrict__ ReducedGradient;
    uint32_t numSrcNeurons;
    uint32_t numTrgNeurons;
    uint32_t rowStride;
    
}
;
__device__ __constant__ MergedNeuronInitGroup0 d_mergedNeuronInitGroup0[1];
void pushMergedNeuronInitGroup0ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* Softmax, float* V, float* VMax, float* VMaxTime, float* VMaxTimeBack, uint8_t* YTrue, uint8_t* YTrueBack, float* outPostInSyn0) {
    MergedNeuronInitGroup0 group = {LambdaI, LambdaV, Softmax, V, VMax, VMaxTime, VMaxTimeBack, YTrue, YTrueBack, outPostInSyn0, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup0, &group, sizeof(MergedNeuronInitGroup0), idx * sizeof(MergedNeuronInitGroup0), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedNeuronInitGroup1 d_mergedNeuronInitGroup1[1];
void pushMergedNeuronInitGroup1ToDevice(unsigned int idx, float* V, uint32_t* spkSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkCntEventSynSpikeEvent0, float* outPreOutSyn1, float* outPreOutSyn0, float* outPostInSyn1, float* outPostInSyn0, uint8_t* BackSpike, int32_t* RingWriteStartOffset, int32_t* RingWriteOffset, int32_t* RingReadOffset, int32_t* RingReadEndOffset, float* RefracTime, float* LambdaV, float* LambdaI) {
    MergedNeuronInitGroup1 group = {V, spkSynSpike0, spkEventSynSpikeEvent0, spkCntSynSpike0, spkCntEventSynSpikeEvent0, outPreOutSyn1, outPreOutSyn0, outPostInSyn1, outPostInSyn0, BackSpike, RingWriteStartOffset, RingWriteOffset, RingReadOffset, RingReadEndOffset, RefracTime, LambdaV, LambdaI, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup1, &group, sizeof(MergedNeuronInitGroup1), idx * sizeof(MergedNeuronInitGroup1), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedNeuronInitGroup2 d_mergedNeuronInitGroup2[1];
void pushMergedNeuronInitGroup2ToDevice(unsigned int idx, uint8_t* BackSpike, uint32_t* EndSpike, int32_t* RingReadEndOffset, int32_t* RingReadOffset, int32_t* RingWriteOffset, int32_t* RingWriteStartOffset, uint32_t* StartSpike, uint32_t* spkCntEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkSynSpike0) {
    MergedNeuronInitGroup2 group = {BackSpike, EndSpike, RingReadEndOffset, RingReadOffset, RingWriteOffset, RingWriteStartOffset, StartSpike, spkCntEventSynSpikeEvent0, spkCntSynSpike0, spkEventSynSpikeEvent0, spkSynSpike0, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronInitGroup2, &group, sizeof(MergedNeuronInitGroup2), idx * sizeof(MergedNeuronInitGroup2), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedSynapseInitGroup0 d_mergedSynapseInitGroup0[3];
void pushMergedSynapseInitGroup0ToDevice(unsigned int idx, float* Gradient, float* g, uint32_t numSrcNeurons, uint32_t numTrgNeurons, uint32_t rowStride) {
    MergedSynapseInitGroup0 group = {Gradient, g, numSrcNeurons, numTrgNeurons, rowStride, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedSynapseInitGroup0, &group, sizeof(MergedSynapseInitGroup0), idx * sizeof(MergedSynapseInitGroup0), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedCustomUpdateInitGroup0 d_mergedCustomUpdateInitGroup0[1];
void pushMergedCustomUpdateInitGroup0ToDevice(unsigned int idx, float* SumExpVal) {
    MergedCustomUpdateInitGroup0 group = {SumExpVal, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedCustomUpdateInitGroup0, &group, sizeof(MergedCustomUpdateInitGroup0), idx * sizeof(MergedCustomUpdateInitGroup0), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedCustomUpdateInitGroup1 d_mergedCustomUpdateInitGroup1[1];
void pushMergedCustomUpdateInitGroup1ToDevice(unsigned int idx, float* MaxVal) {
    MergedCustomUpdateInitGroup1 group = {MaxVal, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedCustomUpdateInitGroup1, &group, sizeof(MergedCustomUpdateInitGroup1), idx * sizeof(MergedCustomUpdateInitGroup1), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedCustomWUUpdateInitGroup0 d_mergedCustomWUUpdateInitGroup0[3];
void pushMergedCustomWUUpdateInitGroup0ToDevice(unsigned int idx, float* M, float* V, uint32_t numSrcNeurons, uint32_t numTrgNeurons, uint32_t rowStride) {
    MergedCustomWUUpdateInitGroup0 group = {M, V, numSrcNeurons, numTrgNeurons, rowStride, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedCustomWUUpdateInitGroup0, &group, sizeof(MergedCustomWUUpdateInitGroup0), idx * sizeof(MergedCustomWUUpdateInitGroup0), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedCustomWUUpdateInitGroup1 d_mergedCustomWUUpdateInitGroup1[3];
void pushMergedCustomWUUpdateInitGroup1ToDevice(unsigned int idx, float* ReducedGradient, uint32_t numSrcNeurons, uint32_t numTrgNeurons, uint32_t rowStride) {
    MergedCustomWUUpdateInitGroup1 group = {ReducedGradient, numSrcNeurons, numTrgNeurons, rowStride, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedCustomWUUpdateInitGroup1, &group, sizeof(MergedCustomWUUpdateInitGroup1), idx * sizeof(MergedCustomWUUpdateInitGroup1), cudaMemcpyHostToDevice, 0));
}
void initializeHost() {
}
__device__ unsigned int d_mergedNeuronInitGroupStartID0[] = {0, };
__device__ unsigned int d_mergedNeuronInitGroupStartID1[] = {32, };
__device__ unsigned int d_mergedNeuronInitGroupStartID2[] = {288, };
__device__ unsigned int d_mergedSynapseInitGroupStartID0[] = {416, 672, 928, };
__device__ unsigned int d_mergedCustomUpdateInitGroupStartID0[] = {960, };
__device__ unsigned int d_mergedCustomUpdateInitGroupStartID1[] = {992, };
__device__ unsigned int d_mergedCustomWUUpdateInitGroupStartID0[] = {1024, 1280, 1536, };
__device__ unsigned int d_mergedCustomWUUpdateInitGroupStartID1[] = {1568, 1824, 2080, };

extern "C" __global__ void initializeRNGKernel(unsigned long long deviceRNGSeed) {
    if(threadIdx.x == 0) {
        curand_init(deviceRNGSeed, 0, 0, d_rng);
    }
}

extern "C" __global__ void initializeKernel(unsigned long long deviceRNGSeed) {
    const unsigned int id = 32 * blockIdx.x + threadIdx.x;
    // ------------------------------------------------------------------------
    // Local neuron groups
    // merged0
    if(id < 32) {
        const unsigned int lid = id - 0;
        struct MergedNeuronInitGroup0 *group = &d_mergedNeuronInitGroup0[0]; 
        // only do this for existing neurons
        if(lid < (17u)) {
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->V[(d * (17u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->VMax[(d * (17u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->VMaxTime[(d * (17u)) + lid] = initVal;
                }
            }
             {
                if(lid == 0) {
                    uint8_t initVal;
                    initVal = (0.000000000e+00f);
                    for(unsigned int d = 0; d < 64; d++) {
                        group->YTrue[d] = initVal;
                    }
                }
            }
             {
                if(lid == 0) {
                    uint8_t initVal;
                    initVal = (0.000000000e+00f);
                    for(unsigned int d = 0; d < 64; d++) {
                        group->YTrueBack[d] = initVal;
                    }
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->LambdaV[(d * (17u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->LambdaI[(d * (17u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->Softmax[(d * (17u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->VMaxTimeBack[(d * (17u)) + lid] = initVal;
                }
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->outPostInSyn0[(d * (17u)) + lid] = 0.000000000e+00f;
            }
        }
    }
    // merged1
    if(id >= 32 && id < 288) {
        const unsigned int lid = id - 32;
        struct MergedNeuronInitGroup1 *group = &d_mergedNeuronInitGroup1[0]; 
        // only do this for existing neurons
        if(lid < (256u)) {
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->V[(d * (256u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RefracTime[(d * (256u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingWriteOffset[(d * (256u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (4.990000000e+02f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingReadOffset[(d * (256u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (4.990000000e+02f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingWriteStartOffset[(d * (256u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (4.990000000e+02f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingReadEndOffset[(d * (256u)) + lid] = initVal;
                }
            }
             {
                uint8_t initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->BackSpike[(d * (256u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->LambdaV[(d * (256u)) + lid] = initVal;
                }
            }
             {
                float initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->LambdaI[(d * (256u)) + lid] = initVal;
                }
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->spkSynSpike0[(d * (256u)) + lid] = 0;
            }
            if(lid == 0) {
                for(unsigned int d = 0; d < 64; d++) {
                    group->spkCntSynSpike0[d] = 0;
                }
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->spkEventSynSpikeEvent0[(d * (256u)) + lid] = 0;
            }
            if(lid == 0) {
                for(unsigned int d = 0; d < 64; d++) {
                    group->spkCntEventSynSpikeEvent0[d] = 0;
                }
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->outPostInSyn0[(d * (256u)) + lid] = 0.000000000e+00f;
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->outPostInSyn1[(d * (256u)) + lid] = 0.000000000e+00f;
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->outPreOutSyn0[(d * (256u)) + lid] = 0.000000000e+00f;
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->outPreOutSyn1[(d * (256u)) + lid] = 0.000000000e+00f;
            }
        }
    }
    // merged2
    if(id >= 288 && id < 416) {
        const unsigned int lid = id - 288;
        struct MergedNeuronInitGroup2 *group = &d_mergedNeuronInitGroup2[0]; 
        // only do this for existing neurons
        if(lid < (115u)) {
             {
                uint32_t initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->StartSpike[(d * (115u)) + lid] = initVal;
                }
            }
             {
                uint32_t initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->EndSpike[(d * (115u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingWriteOffset[(d * (115u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (4.990000000e+02f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingReadOffset[(d * (115u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (4.990000000e+02f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingWriteStartOffset[(d * (115u)) + lid] = initVal;
                }
            }
             {
                int32_t initVal;
                initVal = (4.990000000e+02f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->RingReadEndOffset[(d * (115u)) + lid] = initVal;
                }
            }
             {
                uint8_t initVal;
                initVal = (0.000000000e+00f);
                for(unsigned int d = 0; d < 64; d++) {
                    group->BackSpike[(d * (115u)) + lid] = initVal;
                }
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->spkSynSpike0[(d * (115u)) + lid] = 0;
            }
            if(lid == 0) {
                for(unsigned int d = 0; d < 64; d++) {
                    group->spkCntSynSpike0[d] = 0;
                }
            }
            for(unsigned int d = 0; d < 64; d++) {
                group->spkEventSynSpikeEvent0[(d * (115u)) + lid] = 0;
            }
            if(lid == 0) {
                for(unsigned int d = 0; d < 64; d++) {
                    group->spkCntEventSynSpikeEvent0[d] = 0;
                }
            }
        }
    }
    
    // ------------------------------------------------------------------------
    // Synapse groups
    // merged0
    if(id >= 416 && id < 960) {
        unsigned int lo = 0;
        unsigned int hi = 3;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedSynapseInitGroupStartID0[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedSynapseInitGroup0 *group = &d_mergedSynapseInitGroup0[lo - 1]; 
        const unsigned int groupStartID = d_mergedSynapseInitGroupStartID0[lo - 1];
        const unsigned int lid = id - groupStartID;
        if(lid < group->numTrgNeurons) {
            curandStatePhilox4_32_10_t localRNG = *d_rng;
            skipahead_sequence((unsigned long long)id, &localRNG);
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    const unsigned int idSyn = (i * group->rowStride) + lid;
                    float initVal;
                    initVal = (5.000000000e-01f) + (curand_normal(&localRNG) * (1.000000000e+00f));
                    group->g[idSyn] = initVal;
                }
                 {
                    const unsigned int idSyn = (i * group->rowStride) + lid;
                    float initVal;
                    initVal = (0.000000000e+00f);
                    for(unsigned int d = 0; d < 64; d++) {
                        group->Gradient[(d * group->numSrcNeurons * group->rowStride) + idSyn] = initVal;
                    }
                }
            }
        }
    }
    
    // ------------------------------------------------------------------------
    // Custom update groups
    // merged0
    if(id >= 960 && id < 992) {
        const unsigned int lid = id - 960;
        struct MergedCustomUpdateInitGroup0 *group = &d_mergedCustomUpdateInitGroup0[0]; 
        // only do this for existing variables
        if(lid < (17u)) {
             {
                if(lid == 0) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    for(unsigned int d = 0; d < 64; d++) {
                        group->SumExpVal[d] = initVal;
                    }
                }
            }
        }
    }
    // merged1
    if(id >= 992 && id < 1024) {
        const unsigned int lid = id - 992;
        struct MergedCustomUpdateInitGroup1 *group = &d_mergedCustomUpdateInitGroup1[0]; 
        // only do this for existing variables
        if(lid < (17u)) {
             {
                if(lid == 0) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    for(unsigned int d = 0; d < 64; d++) {
                        group->MaxVal[d] = initVal;
                    }
                }
            }
        }
    }
    
    // ------------------------------------------------------------------------
    // Custom WU update groups
    // merged0
    if(id >= 1024 && id < 1568) {
        unsigned int lo = 0;
        unsigned int hi = 3;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedCustomWUUpdateInitGroupStartID0[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedCustomWUUpdateInitGroup0 *group = &d_mergedCustomWUUpdateInitGroup0[lo - 1]; 
        const unsigned int groupStartID = d_mergedCustomWUUpdateInitGroupStartID0[lo - 1];
        const unsigned int lid = id - groupStartID;
        if(lid < group->numTrgNeurons) {
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    const unsigned int idSyn = (i * group->rowStride) + lid;
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->M[idSyn] = initVal;
                }
                 {
                    const unsigned int idSyn = (i * group->rowStride) + lid;
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->V[idSyn] = initVal;
                }
            }
        }
    }
    // merged1
    if(id >= 1568 && id < 2112) {
        unsigned int lo = 0;
        unsigned int hi = 3;
        while(lo < hi)
         {
            const unsigned int mid = (lo + hi) / 2;
            if(id < d_mergedCustomWUUpdateInitGroupStartID1[mid]) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        struct MergedCustomWUUpdateInitGroup1 *group = &d_mergedCustomWUUpdateInitGroup1[lo - 1]; 
        const unsigned int groupStartID = d_mergedCustomWUUpdateInitGroupStartID1[lo - 1];
        const unsigned int lid = id - groupStartID;
        if(lid < group->numTrgNeurons) {
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    const unsigned int idSyn = (i * group->rowStride) + lid;
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->ReducedGradient[idSyn] = initVal;
                }
            }
        }
    }
    
    // ------------------------------------------------------------------------
    // Custom connectivity presynaptic update groups
    
    // ------------------------------------------------------------------------
    // Custom connectivity postsynaptic update groups
    
    // ------------------------------------------------------------------------
    // Synapse groups with sparse connectivity
    
}
void initialize() {
    unsigned long long deviceRNGSeed = 0;
     {
        std::random_device seedSource;
        uint32_t *deviceRNGSeedWord = reinterpret_cast<uint32_t*>(&deviceRNGSeed);
        for(int i = 0; i < 2; i++) {
            deviceRNGSeedWord[i] = seedSource();
        }
    }
    initializeRNGKernel<<<1, 1>>>(deviceRNGSeed);
    CHECK_RUNTIME_ERRORS(cudaPeekAtLastError());
     {
        CHECK_RUNTIME_ERRORS(cudaEventRecord(initStart));
        const dim3 threads(32, 1);
        const dim3 grid(66, 1);
        initializeKernel<<<grid, threads>>>(deviceRNGSeed);
        CHECK_RUNTIME_ERRORS(cudaPeekAtLastError());
        CHECK_RUNTIME_ERRORS(cudaEventRecord(initStop));
        CHECK_RUNTIME_ERRORS(cudaEventSynchronize(initStop));
        float tmp;
        CHECK_RUNTIME_ERRORS(cudaEventElapsedTime(&tmp, initStart, initStop));
        initTime += tmp / 1000.0;
    }
}

void initializeSparse() {
}
