#include "definitions.h"

struct MergedNeuronUpdateGroup0
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    float* __restrict__ Softmax;
    float* __restrict__ V;
    float* __restrict__ VMax;
    float* __restrict__ VMaxTime;
    float* __restrict__ VMaxTimeBack;
    uint8_t* __restrict__ YTrueBack;
    float* __restrict__ outPostInSyn0;
    uint32_t Trial;
    
}
;
struct MergedNeuronUpdateGroup1
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
    int32_t* __restrict__ RingWriteOffset;
    float* __restrict__ RingSpikeTime;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingReadEndOffset;
    float* __restrict__ RingIMinusV;
    float* __restrict__ RefracTime;
    float* __restrict__ LambdaV;
    float* __restrict__ LambdaI;
    
}
;
struct MergedNeuronUpdateGroup2
 {
    uint8_t* __restrict__ BackSpike;
    uint32_t* __restrict__ EndSpike;
    int32_t* __restrict__ RingReadEndOffset;
    int32_t* __restrict__ RingReadOffset;
    float* __restrict__ RingSpikeTime;
    int32_t* __restrict__ RingWriteOffset;
    float* __restrict__ SpikeTimes;
    uint32_t* __restrict__ StartSpike;
    uint32_t* __restrict__ spkCntEventSynSpikeEvent0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkEventSynSpikeEvent0;
    uint32_t* __restrict__ spkSynSpike0;
    
}
;
struct MergedNeuronSpikeQueueUpdateGroup0
 {
    uint32_t* __restrict__ spkCntEventSynSpikeEvent0;
    uint32_t* __restrict__ spkCntSynSpike0;
    
}
;
__device__ __constant__ MergedNeuronSpikeQueueUpdateGroup0 d_mergedNeuronSpikeQueueUpdateGroup0[2];
void pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(unsigned int idx, uint32_t* spkCntEventSynSpikeEvent0, uint32_t* spkCntSynSpike0) {
    MergedNeuronSpikeQueueUpdateGroup0 group = {spkCntEventSynSpikeEvent0, spkCntSynSpike0, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronSpikeQueueUpdateGroup0, &group, sizeof(MergedNeuronSpikeQueueUpdateGroup0), idx * sizeof(MergedNeuronSpikeQueueUpdateGroup0), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedNeuronUpdateGroup0 d_mergedNeuronUpdateGroup0[1];
void pushMergedNeuronUpdateGroup0ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* Softmax, float* V, float* VMax, float* VMaxTime, float* VMaxTimeBack, uint8_t* YTrueBack, float* outPostInSyn0, uint32_t Trial) {
    MergedNeuronUpdateGroup0 group = {LambdaI, LambdaV, Softmax, V, VMax, VMaxTime, VMaxTimeBack, YTrueBack, outPostInSyn0, Trial, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup0, &group, sizeof(MergedNeuronUpdateGroup0), idx * sizeof(MergedNeuronUpdateGroup0), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedNeuronUpdateGroup1 d_mergedNeuronUpdateGroup1[1];
void pushMergedNeuronUpdateGroup1ToDevice(unsigned int idx, float* V, uint32_t* spkSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkCntEventSynSpikeEvent0, float* outPreOutSyn1, float* outPreOutSyn0, float* outPostInSyn1, float* outPostInSyn0, uint8_t* BackSpike, int32_t* RingWriteOffset, float* RingSpikeTime, int32_t* RingReadOffset, int32_t* RingReadEndOffset, float* RingIMinusV, float* RefracTime, float* LambdaV, float* LambdaI) {
    MergedNeuronUpdateGroup1 group = {V, spkSynSpike0, spkEventSynSpikeEvent0, spkCntSynSpike0, spkCntEventSynSpikeEvent0, outPreOutSyn1, outPreOutSyn0, outPostInSyn1, outPostInSyn0, BackSpike, RingWriteOffset, RingSpikeTime, RingReadOffset, RingReadEndOffset, RingIMinusV, RefracTime, LambdaV, LambdaI, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup1, &group, sizeof(MergedNeuronUpdateGroup1), idx * sizeof(MergedNeuronUpdateGroup1), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ MergedNeuronUpdateGroup2 d_mergedNeuronUpdateGroup2[1];
void pushMergedNeuronUpdateGroup2ToDevice(unsigned int idx, uint8_t* BackSpike, uint32_t* EndSpike, int32_t* RingReadEndOffset, int32_t* RingReadOffset, float* RingSpikeTime, int32_t* RingWriteOffset, float* SpikeTimes, uint32_t* StartSpike, uint32_t* spkCntEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkSynSpike0) {
    MergedNeuronUpdateGroup2 group = {BackSpike, EndSpike, RingReadEndOffset, RingReadOffset, RingSpikeTime, RingWriteOffset, SpikeTimes, StartSpike, spkCntEventSynSpikeEvent0, spkCntSynSpike0, spkEventSynSpikeEvent0, spkSynSpike0, };
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup2, &group, sizeof(MergedNeuronUpdateGroup2), idx * sizeof(MergedNeuronUpdateGroup2), cudaMemcpyHostToDevice, 0));
}
void pushMergedNeuronUpdate0TrialToDevice(unsigned int idx, uint32_t value) {
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup0, &value, sizeof(value), (sizeof(MergedNeuronUpdateGroup0) * (idx)) + offsetof(MergedNeuronUpdateGroup0, Trial), cudaMemcpyHostToDevice, 0));
}
void pushMergedNeuronUpdate1RingIMinusVToDevice(unsigned int idx, float* value) {
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup1, &value, sizeof(value), (sizeof(MergedNeuronUpdateGroup1) * (idx)) + offsetof(MergedNeuronUpdateGroup1, RingIMinusV), cudaMemcpyHostToDevice, 0));
}
void pushMergedNeuronUpdate1RingSpikeTimeToDevice(unsigned int idx, float* value) {
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup1, &value, sizeof(value), (sizeof(MergedNeuronUpdateGroup1) * (idx)) + offsetof(MergedNeuronUpdateGroup1, RingSpikeTime), cudaMemcpyHostToDevice, 0));
}
void pushMergedNeuronUpdate2RingSpikeTimeToDevice(unsigned int idx, float* value) {
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup2, &value, sizeof(value), (sizeof(MergedNeuronUpdateGroup2) * (idx)) + offsetof(MergedNeuronUpdateGroup2, RingSpikeTime), cudaMemcpyHostToDevice, 0));
}
void pushMergedNeuronUpdate2SpikeTimesToDevice(unsigned int idx, float* value) {
    CHECK_RUNTIME_ERRORS(cudaMemcpyToSymbolAsync(d_mergedNeuronUpdateGroup2, &value, sizeof(value), (sizeof(MergedNeuronUpdateGroup2) * (idx)) + offsetof(MergedNeuronUpdateGroup2, SpikeTimes), cudaMemcpyHostToDevice, 0));
}
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID0[] = {0, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID1[] = {32, };
__device__ __constant__ unsigned int d_mergedNeuronUpdateGroupStartID2[] = {288, };

extern "C" __global__ void neuronSpikeQueueUpdateKernel() {
    const unsigned int id = 32 * blockIdx.x + threadIdx.x;
    if(id < 2) {
        struct MergedNeuronSpikeQueueUpdateGroup0 *group = &d_mergedNeuronSpikeQueueUpdateGroup0[id - 0]; 
        for(unsigned int batch = 0; batch < 64; batch++) {
             {
                // spike queue update 0
                group->spkCntSynSpike0[batch] = 0;
            }
             {
                // spike event queue update 0
                group->spkCntEventSynSpikeEvent0[batch] = 0;
            }
        }
    }
}

extern "C" __global__ void updateNeuronsKernel(float t)
 {
    const unsigned int batch = blockIdx.y;
    const unsigned int id = 32 * blockIdx.x + threadIdx.x; 
    __shared__ unsigned int shSpk[1][32];
    __shared__ unsigned int shSpkPos[1];
    __shared__ unsigned int shSpkCount[1];
    if (threadIdx.x == 0) {
        shSpkCount[0] = 0;
    }
    
    __shared__ unsigned int shSpkEvent[1][32];
    __shared__ unsigned int shSpkEventPos[1];
    __shared__ unsigned int shSpkEventCount[1];
    if (threadIdx.x < 1) {
        shSpkEventCount[threadIdx.x] = 0;
    }
    __syncthreads();
    // merged0
    if(id < 32) {
        const unsigned int lid = id - 0;
        struct MergedNeuronUpdateGroup0 *group = &d_mergedNeuronUpdateGroup0[0]; 
         {
            const unsigned int batchOffset = (17u) * batch;
            if(lid < (17u)) {
                float Isyn = 0;
                const float _lVMaxTimeBack = group->VMaxTimeBack[batchOffset + lid];
                const float _lSoftmax = group->Softmax[batchOffset + lid];
                float _lLambdaV = group->LambdaV[batchOffset + lid];
                float _lLambdaI = group->LambdaI[batchOffset + lid];
                const uint8_t _lYTrueBack = group->YTrueBack[batch];
                float _lVMaxTime = group->VMaxTime[batchOffset + lid];
                float _lVMax = group->VMax[batchOffset + lid];
                float _lV = group->V[batchOffset + lid];
                 {
                    // postsynaptic model 0
                    float linSyn = group->outPostInSyn0[batchOffset + lid];
                    Isyn += linSyn * (9.063462346e-01f);
                    linSyn *= (8.187307531e-01f);
                    group->outPostInSyn0[batchOffset + lid] = linSyn;
                }
                // calculate membrane potential
                const float _backT = 680.0f - t - 1.000000000e+00f;
                float _drive = 0.0f;
                if(group->Trial > 0 && fabs(_backT - _lVMaxTimeBack) < 1e-3f * 1.000000000e+00f)
                 {
                    const float _g = (lid == _lYTrueBack) ? (1.0f - _lSoftmax) : -_lSoftmax;
                    _drive = _g / ((2.000000000e+01f) * 64 * 680.0f);
                }
                
                _lLambdaI = _drive + ((_lLambdaI - _drive) * (8.187307531e-01f)) + ((1.333333333e+00f) * (_lLambdaV - _drive) * ((9.512294245e-01f) - (8.187307531e-01f)));
                _lLambdaV = _drive + ((_lLambdaV - _drive) * (9.512294245e-01f));
                _lV = ((9.512294245e-01f) * _lV) + ((1.0f - (9.512294245e-01f)) * Isyn) + (0.000000000e+00f);
                if(_lV > _lVMax)
                 {
                    _lVMax = _lV;
                    _lVMaxTime = t;
                }
                
                group->LambdaV[batchOffset + lid] = _lLambdaV;
                group->LambdaI[batchOffset + lid] = _lLambdaI;
                group->VMaxTime[batchOffset + lid] = _lVMaxTime;
                group->VMax[batchOffset + lid] = _lVMax;
                group->V[batchOffset + lid] = _lV;
            }
            __syncthreads();
        }
    }
    // merged1
    if(id >= 32 && id < 288) {
        const unsigned int lid = id - 32;
        struct MergedNeuronUpdateGroup1 *group = &d_mergedNeuronUpdateGroup1[0]; 
         {
            const unsigned int batchOffset = (256u) * batch;
            if(lid < (256u)) {
                float Isyn = 0;
                float _RevISyn = 0.000000000e+00f;
                int32_t _lRingReadEndOffset = group->RingReadEndOffset[batchOffset + lid];
                float _lLambdaI = group->LambdaI[batchOffset + lid];
                uint8_t _lBackSpike = group->BackSpike[batchOffset + lid];
                int32_t _lRingReadOffset = group->RingReadOffset[batchOffset + lid];
                float _lLambdaV = group->LambdaV[batchOffset + lid];
                float _lRefracTime = group->RefracTime[batchOffset + lid];
                int32_t _lRingWriteOffset = group->RingWriteOffset[batchOffset + lid];
                float _lV = group->V[batchOffset + lid];
                 {
                    // postsynaptic model 0
                    float linSyn = group->outPostInSyn0[batchOffset + lid];
                    Isyn += linSyn * (9.063462346e-01f);
                    linSyn *= (8.187307531e-01f);
                    group->outPostInSyn0[batchOffset + lid] = linSyn;
                }
                 {
                    // postsynaptic model 1
                    float linSyn = group->outPostInSyn1[batchOffset + lid];
                    Isyn += linSyn * (9.063462346e-01f);
                    linSyn *= (8.187307531e-01f);
                    group->outPostInSyn1[batchOffset + lid] = linSyn;
                }
                 {
                    _RevISyn += group->outPreOutSyn0[batchOffset + lid];
                    group->outPreOutSyn0[batchOffset + lid] = 0.000000000e+00f;
                }
                 {
                    _RevISyn += group->outPreOutSyn1[batchOffset + lid];
                    group->outPreOutSyn1[batchOffset + lid] = 0.000000000e+00f;
                }
                // test whether spike condition was fulfilled previously
                // calculate membrane potential
                const int32_t _ringOffset = (batch * (256u) * 500) + (lid * 500);
                const float _backT = 680.0f - t - 1.000000000e+00f;
                _lLambdaI = ((-1.333333333e+00f) * _lLambdaV * ((8.187307531e-01f) - (9.512294245e-01f))) + (_lLambdaI * (8.187307531e-01f));
                _lLambdaV *= (9.512294245e-01f);
                if(_lBackSpike)
                 {
                    _lLambdaV += (1.0f / group->RingIMinusV[_ringOffset + _lRingReadOffset]) * ((2.000000000e-01f) * _lLambdaV + _RevISyn);
                    _lRingReadOffset--;
                    if(_lRingReadOffset < 0)
                     {
                        _lRingReadOffset = 500 - 1;
                    }
                    
                    _lBackSpike = false;
                }
                
                if(_lRingReadOffset != _lRingReadEndOffset && fabs(_backT - group->RingSpikeTime[_ringOffset + _lRingReadOffset] - 1.000000000e+00f) < 1e-3f * 1.000000000e+00f)
                 {
                    _lBackSpike = true;
                }
                
                if(_lRefracTime > 0.0f)
                 {
                    _lRefracTime -= 1.000000000e+00f;
                }
                else
                 {
                    _lV = ((9.512294245e-01f) * _lV) + ((1.0f - (9.512294245e-01f)) * Isyn);
                }
                
                 {
                    // spike event condition 0
                    if((_lBackSpike)) {
                        const unsigned int eventIdx = atomicAdd(&shSpkEventCount[0], 1);
                        shSpkEvent[0][eventIdx] = lid;
                    }
                }
                // test for and register a true spike
                if ((_lV >= (2.000000000e-01f) && _lRefracTime <= 0.0f)) {
                    const unsigned int eventIdx = atomicAdd(&shSpkCount[0], 1);
                    shSpk[0][eventIdx] = lid;
                    // spike reset code
                    if(_lRingWriteOffset != _lRingReadEndOffset)
                     {
                        group->RingSpikeTime[_ringOffset + _lRingWriteOffset] = t;
                        group->RingIMinusV[_ringOffset + _lRingWriteOffset] = (Isyn * (1.103331113e+00f)) - _lV;
                        _lRingWriteOffset++;
                        if(_lRingWriteOffset >= 500)
                         {
                            _lRingWriteOffset = 0;
                        }
                        
                    }
                    
                    _lV = (0.000000000e+00f);
                    _lRefracTime = (1.000000000e+00f);
                }
                group->RingReadEndOffset[batchOffset + lid] = _lRingReadEndOffset;
                group->LambdaI[batchOffset + lid] = _lLambdaI;
                group->BackSpike[batchOffset + lid] = _lBackSpike;
                group->RingReadOffset[batchOffset + lid] = _lRingReadOffset;
                group->LambdaV[batchOffset + lid] = _lLambdaV;
                group->RefracTime[batchOffset + lid] = _lRefracTime;
                group->RingWriteOffset[batchOffset + lid] = _lRingWriteOffset;
                group->V[batchOffset + lid] = _lV;
            }
            __syncthreads();
            if(threadIdx.x == 0) {
                 {
                    shSpkPos[0] = atomicAdd(&group->spkCntSynSpike0[batch], shSpkCount[0]);
                }
                 {
                    shSpkEventPos[0] = atomicAdd(&group->spkCntEventSynSpikeEvent0[batch], shSpkEventCount[0]);
                }
            }
            __syncthreads();
            if(threadIdx.x < shSpkCount[0]) {
                const unsigned int n = shSpk[0][threadIdx.x];
                 {
                    group->spkSynSpike0[batchOffset + shSpkPos[0] + threadIdx.x] = n;
                }
            }
             {
                if(threadIdx.x < shSpkEventCount[0]) {
                    const unsigned int n = shSpkEvent[0][threadIdx.x];
                    group->spkEventSynSpikeEvent0[batchOffset + shSpkEventPos[0] + threadIdx.x] = n;
                }
            }
        }
    }
    // merged2
    if(id >= 288 && id < 416) {
        const unsigned int lid = id - 288;
        struct MergedNeuronUpdateGroup2 *group = &d_mergedNeuronUpdateGroup2[0]; 
         {
            const unsigned int batchOffset = (115u) * batch;
            if(lid < (115u)) {
                int32_t _lRingReadEndOffset = group->RingReadEndOffset[batchOffset + lid];
                uint8_t _lBackSpike = group->BackSpike[batchOffset + lid];
                int32_t _lRingWriteOffset = group->RingWriteOffset[batchOffset + lid];
                const uint32_t _lEndSpike = group->EndSpike[batchOffset + lid];
                int32_t _lRingReadOffset = group->RingReadOffset[batchOffset + lid];
                uint32_t _lStartSpike = group->StartSpike[batchOffset + lid];
                // test whether spike condition was fulfilled previously
                // calculate membrane potential
                const int32_t _ringOffset = (batch * (115u) * 500) + (lid * 500);
                const float _backT = 680.0f - t - 1.000000000e+00f;
                if(_lBackSpike)
                 {
                    _lRingReadOffset--;
                    if(_lRingReadOffset < 0)
                     {
                        _lRingReadOffset = 500 - 1;
                    }
                    
                    _lBackSpike = false;
                }
                
                if(_lRingReadOffset != _lRingReadEndOffset && fabs(_backT - group->RingSpikeTime[_ringOffset + _lRingReadOffset] - 1.000000000e+00f) < 1e-3f * 1.000000000e+00f)
                 {
                    _lBackSpike = true;
                }
                
                 {
                    // spike event condition 0
                    if((_lBackSpike)) {
                        const unsigned int eventIdx = atomicAdd(&shSpkEventCount[0], 1);
                        shSpkEvent[0][eventIdx] = lid;
                    }
                }
                // test for and register a true spike
                if ((_lStartSpike != _lEndSpike && t >= group->SpikeTimes[_lStartSpike])) {
                    const unsigned int eventIdx = atomicAdd(&shSpkCount[0], 1);
                    shSpk[0][eventIdx] = lid;
                    // spike reset code
                    if(_lRingWriteOffset != _lRingReadEndOffset)
                     {
                        group->RingSpikeTime[_ringOffset + _lRingWriteOffset] = t;
                        _lRingWriteOffset++;
                        if(_lRingWriteOffset >= 500)
                         {
                            _lRingWriteOffset = 0;
                        }
                        
                    }
                    
                    _lStartSpike++;
                }
                group->RingReadEndOffset[batchOffset + lid] = _lRingReadEndOffset;
                group->BackSpike[batchOffset + lid] = _lBackSpike;
                group->RingWriteOffset[batchOffset + lid] = _lRingWriteOffset;
                group->RingReadOffset[batchOffset + lid] = _lRingReadOffset;
                group->StartSpike[batchOffset + lid] = _lStartSpike;
            }
            __syncthreads();
            if(threadIdx.x == 0) {
                 {
                    shSpkPos[0] = atomicAdd(&group->spkCntSynSpike0[batch], shSpkCount[0]);
                }
                 {
                    shSpkEventPos[0] = atomicAdd(&group->spkCntEventSynSpikeEvent0[batch], shSpkEventCount[0]);
                }
            }
            __syncthreads();
            if(threadIdx.x < shSpkCount[0]) {
                const unsigned int n = shSpk[0][threadIdx.x];
                 {
                    group->spkSynSpike0[batchOffset + shSpkPos[0] + threadIdx.x] = n;
                }
            }
             {
                if(threadIdx.x < shSpkEventCount[0]) {
                    const unsigned int n = shSpkEvent[0][threadIdx.x];
                    group->spkEventSynSpikeEvent0[batchOffset + shSpkEventPos[0] + threadIdx.x] = n;
                }
            }
        }
    }
}
void updateNeurons(float t) {
     {
        const dim3 threads(32, 1);
        const dim3 grid(1, 1);
        neuronSpikeQueueUpdateKernel<<<grid, threads>>>();
        CHECK_RUNTIME_ERRORS(cudaPeekAtLastError());
    }
     {
        CHECK_RUNTIME_ERRORS(cudaEventRecord(neuronUpdateStart));
        const dim3 threads(32, 1);
        const dim3 grid(13, 64);
        updateNeuronsKernel<<<grid, threads>>>(t);
        CHECK_RUNTIME_ERRORS(cudaPeekAtLastError());
        CHECK_RUNTIME_ERRORS(cudaEventRecord(neuronUpdateStop));
    }
}
