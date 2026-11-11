#include "definitions.h"

struct MergedNeuronUpdateGroup0
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    float* __restrict__ RingOutputLossTerm;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingWriteOffset;
    float* __restrict__ V;
    float* __restrict__ YTrue;
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
static MergedNeuronUpdateGroup0 mergedNeuronUpdateGroup0[1];
void pushMergedNeuronUpdateGroup0ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* RingOutputLossTerm, int32_t* RingReadOffset, int32_t* RingWriteOffset, float* V, float* YTrue, float* outPostInSyn0, uint32_t Trial) {
    mergedNeuronUpdateGroup0[idx].LambdaI = LambdaI;
    mergedNeuronUpdateGroup0[idx].LambdaV = LambdaV;
    mergedNeuronUpdateGroup0[idx].RingOutputLossTerm = RingOutputLossTerm;
    mergedNeuronUpdateGroup0[idx].RingReadOffset = RingReadOffset;
    mergedNeuronUpdateGroup0[idx].RingWriteOffset = RingWriteOffset;
    mergedNeuronUpdateGroup0[idx].V = V;
    mergedNeuronUpdateGroup0[idx].YTrue = YTrue;
    mergedNeuronUpdateGroup0[idx].outPostInSyn0 = outPostInSyn0;
    mergedNeuronUpdateGroup0[idx].Trial = Trial;
}
static MergedNeuronUpdateGroup1 mergedNeuronUpdateGroup1[1];
void pushMergedNeuronUpdateGroup1ToDevice(unsigned int idx, float* V, uint32_t* spkSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkCntEventSynSpikeEvent0, float* outPreOutSyn1, float* outPreOutSyn0, float* outPostInSyn1, float* outPostInSyn0, uint8_t* BackSpike, int32_t* RingWriteOffset, float* RingSpikeTime, int32_t* RingReadOffset, int32_t* RingReadEndOffset, float* RingIMinusV, float* RefracTime, float* LambdaV, float* LambdaI) {
    mergedNeuronUpdateGroup1[idx].V = V;
    mergedNeuronUpdateGroup1[idx].spkSynSpike0 = spkSynSpike0;
    mergedNeuronUpdateGroup1[idx].spkEventSynSpikeEvent0 = spkEventSynSpikeEvent0;
    mergedNeuronUpdateGroup1[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronUpdateGroup1[idx].spkCntEventSynSpikeEvent0 = spkCntEventSynSpikeEvent0;
    mergedNeuronUpdateGroup1[idx].outPreOutSyn1 = outPreOutSyn1;
    mergedNeuronUpdateGroup1[idx].outPreOutSyn0 = outPreOutSyn0;
    mergedNeuronUpdateGroup1[idx].outPostInSyn1 = outPostInSyn1;
    mergedNeuronUpdateGroup1[idx].outPostInSyn0 = outPostInSyn0;
    mergedNeuronUpdateGroup1[idx].BackSpike = BackSpike;
    mergedNeuronUpdateGroup1[idx].RingWriteOffset = RingWriteOffset;
    mergedNeuronUpdateGroup1[idx].RingSpikeTime = RingSpikeTime;
    mergedNeuronUpdateGroup1[idx].RingReadOffset = RingReadOffset;
    mergedNeuronUpdateGroup1[idx].RingReadEndOffset = RingReadEndOffset;
    mergedNeuronUpdateGroup1[idx].RingIMinusV = RingIMinusV;
    mergedNeuronUpdateGroup1[idx].RefracTime = RefracTime;
    mergedNeuronUpdateGroup1[idx].LambdaV = LambdaV;
    mergedNeuronUpdateGroup1[idx].LambdaI = LambdaI;
}
static MergedNeuronUpdateGroup2 mergedNeuronUpdateGroup2[1];
void pushMergedNeuronUpdateGroup2ToDevice(unsigned int idx, uint8_t* BackSpike, uint32_t* EndSpike, int32_t* RingReadEndOffset, int32_t* RingReadOffset, float* RingSpikeTime, int32_t* RingWriteOffset, float* SpikeTimes, uint32_t* StartSpike, uint32_t* spkCntEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkSynSpike0) {
    mergedNeuronUpdateGroup2[idx].BackSpike = BackSpike;
    mergedNeuronUpdateGroup2[idx].EndSpike = EndSpike;
    mergedNeuronUpdateGroup2[idx].RingReadEndOffset = RingReadEndOffset;
    mergedNeuronUpdateGroup2[idx].RingReadOffset = RingReadOffset;
    mergedNeuronUpdateGroup2[idx].RingSpikeTime = RingSpikeTime;
    mergedNeuronUpdateGroup2[idx].RingWriteOffset = RingWriteOffset;
    mergedNeuronUpdateGroup2[idx].SpikeTimes = SpikeTimes;
    mergedNeuronUpdateGroup2[idx].StartSpike = StartSpike;
    mergedNeuronUpdateGroup2[idx].spkCntEventSynSpikeEvent0 = spkCntEventSynSpikeEvent0;
    mergedNeuronUpdateGroup2[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronUpdateGroup2[idx].spkEventSynSpikeEvent0 = spkEventSynSpikeEvent0;
    mergedNeuronUpdateGroup2[idx].spkSynSpike0 = spkSynSpike0;
}
static MergedNeuronSpikeQueueUpdateGroup0 mergedNeuronSpikeQueueUpdateGroup0[2];
void pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(unsigned int idx, uint32_t* spkCntEventSynSpikeEvent0, uint32_t* spkCntSynSpike0) {
    mergedNeuronSpikeQueueUpdateGroup0[idx].spkCntEventSynSpikeEvent0 = spkCntEventSynSpikeEvent0;
    mergedNeuronSpikeQueueUpdateGroup0[idx].spkCntSynSpike0 = spkCntSynSpike0;
}
void pushMergedNeuronUpdate0RingOutputLossTermToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup0[idx].RingOutputLossTerm = value;
}
void pushMergedNeuronUpdate0TrialToDevice(unsigned int idx, uint32_t value) {
    mergedNeuronUpdateGroup0[idx].Trial = value;
}
void pushMergedNeuronUpdate0YTrueToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup0[idx].YTrue = value;
}
void pushMergedNeuronUpdate1RingIMinusVToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup1[idx].RingIMinusV = value;
}
void pushMergedNeuronUpdate1RingSpikeTimeToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup1[idx].RingSpikeTime = value;
}
void pushMergedNeuronUpdate2RingSpikeTimeToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup2[idx].RingSpikeTime = value;
}
void pushMergedNeuronUpdate2SpikeTimesToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup2[idx].SpikeTimes = value;
}
void updateNeurons(float t) {
    const auto neuronUpdateStart = std::chrono::high_resolution_clock::now();
     {
        // merged neuron spike queue update group 0
        for(unsigned int g = 0; g < 2; g++) {
            const auto *group = &mergedNeuronSpikeQueueUpdateGroup0[g]; 
             {
                // spike queue update 0
                group->spkCntSynSpike0[0] = 0;
            }
             {
                // spike event queue update 0
                group->spkCntEventSynSpikeEvent0[0] = 0;
            }
        }
    }
     {
        // merged neuron update group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronUpdateGroup0[g]; 
            
            for(unsigned int i = 0; i < (17u); i++) {
                float Isyn = 0;
                int32_t _lRingReadOffset = group->RingReadOffset[i];
                float _lLambdaI = group->LambdaI[i];
                float _lLambdaV = group->LambdaV[i];
                int32_t _lRingWriteOffset = group->RingWriteOffset[i];
                float _lV = group->V[i];
                 {
                    // postsynaptic model 0
                    float linSyn = group->outPostInSyn0[i];
                    Isyn += linSyn * (9.900663347e-01f);
                    linSyn *= (9.801986733e-01f);
                    group->outPostInSyn0[i] = linSyn;
                }
                // calculate membrane potential
                const float _backT = 68.0f - t - 1.000000000e-01f;
                float _drive = 0.0f;
                const int32_t _ringOffset = (0 * (17u) * 1360) + (i * 1360);
                if(group->Trial > 0)
                 {
                    _lRingReadOffset--;
                    const float _error = group->RingOutputLossTerm[_ringOffset + _lRingReadOffset];
                    _drive = _error / ((2.000000000e+01f) * 1 * 68.0f);
                }
                
                _lLambdaI = _drive + ((_lLambdaI - _drive) * (9.801986733e-01f)) + ((1.333333333e+00f) * (_lLambdaV - _drive) * ((9.950124792e-01f) - (9.801986733e-01f)));
                _lLambdaV = _drive + ((_lLambdaV - _drive) * (9.950124792e-01f));
                _lV = ((9.950124792e-01f) * _lV) + ((1.0f - (9.950124792e-01f)) * Isyn) + (0.000000000e+00f);
                const uint32_t _timestep = (int32_t)round(t / 1.000000000e-01f);
                const uint32_t _index = (0 * 680 * (17u)) + (_timestep * (17u)) + i;
                group->RingOutputLossTerm[_ringOffset + _lRingWriteOffset] = group->YTrue[_index] - _lV;
                _lRingWriteOffset++;
                group->RingReadOffset[i] = _lRingReadOffset;
                group->LambdaI[i] = _lLambdaI;
                group->LambdaV[i] = _lLambdaV;
                group->RingWriteOffset[i] = _lRingWriteOffset;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged neuron update group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronUpdateGroup1[g]; 
            
            for(unsigned int i = 0; i < (256u); i++) {
                float Isyn = 0;
                float _RevISyn = 0.000000000e+00f;
                int32_t _lRingReadEndOffset = group->RingReadEndOffset[i];
                float _lLambdaI = group->LambdaI[i];
                uint8_t _lBackSpike = group->BackSpike[i];
                int32_t _lRingReadOffset = group->RingReadOffset[i];
                float _lLambdaV = group->LambdaV[i];
                float _lRefracTime = group->RefracTime[i];
                int32_t _lRingWriteOffset = group->RingWriteOffset[i];
                float _lV = group->V[i];
                 {
                    // postsynaptic model 0
                    float linSyn = group->outPostInSyn0[i];
                    Isyn += linSyn * (9.900663347e-01f);
                    linSyn *= (9.801986733e-01f);
                    group->outPostInSyn0[i] = linSyn;
                }
                 {
                    // postsynaptic model 1
                    float linSyn = group->outPostInSyn1[i];
                    Isyn += linSyn * (9.900663347e-01f);
                    linSyn *= (9.801986733e-01f);
                    group->outPostInSyn1[i] = linSyn;
                }
                 {
                    _RevISyn += group->outPreOutSyn0[i];
                    group->outPreOutSyn0[i] = 0.000000000e+00f;
                }
                 {
                    _RevISyn += group->outPreOutSyn1[i];
                    group->outPreOutSyn1[i] = 0.000000000e+00f;
                }
                // test whether spike condition was fulfilled previously
                // calculate membrane potential
                const int32_t _ringOffset = (0 * (256u) * 500) + (i * 500);
                const float _backT = 68.0f - t - 1.000000000e-01f;
                _lLambdaI = ((-1.333333333e+00f) * _lLambdaV * ((9.801986733e-01f) - (9.950124792e-01f))) + (_lLambdaI * (9.801986733e-01f));
                _lLambdaV *= (9.950124792e-01f);
                if(_lBackSpike)
                 {
                    _lLambdaV += (1.0f / group->RingIMinusV[_ringOffset + _lRingReadOffset]) * ((5.000000000e-01f) * _lLambdaV + _RevISyn);
                    _lRingReadOffset--;
                    if(_lRingReadOffset < 0)
                     {
                        _lRingReadOffset = 500 - 1;
                    }
                    
                    _lBackSpike = false;
                }
                
                if(_lRingReadOffset != _lRingReadEndOffset && fabs(_backT - group->RingSpikeTime[_ringOffset + _lRingReadOffset] - 1.000000000e-01f) < 1e-3f * 1.000000000e-01f)
                 {
                    _lBackSpike = true;
                }
                
                if(_lRefracTime > 0.0f)
                 {
                    _lRefracTime -= 1.000000000e-01f;
                }
                else
                 {
                    _lV = ((9.950124792e-01f) * _lV) + ((1.0f - (9.950124792e-01f)) * Isyn);
                }
                
                 {
                    // spike event condition 0
                    if((_lBackSpike)) {
                         {
                            group->spkEventSynSpikeEvent0[group->spkCntEventSynSpikeEvent0[0]++] = i;
                        }
                    }
                }
                // test for and register a true spike
                if ((_lV >= (5.000000000e-01f) && _lRefracTime <= 0.0f)) {
                     {
                        group->spkSynSpike0[group->spkCntSynSpike0[0]++] = i;
                    }
                    // spike reset code
                    if(_lRingWriteOffset != _lRingReadEndOffset)
                     {
                        group->RingSpikeTime[_ringOffset + _lRingWriteOffset] = t;
                        group->RingIMinusV[_ringOffset + _lRingWriteOffset] = (Isyn * (1.010033333e+00f)) - _lV;
                        _lRingWriteOffset++;
                        if(_lRingWriteOffset >= 500)
                         {
                            _lRingWriteOffset = 0;
                        }
                        
                    }
                    
                    _lV = (0.000000000e+00f);
                    _lRefracTime = (1.000000000e+00f);
                }
                group->RingReadEndOffset[i] = _lRingReadEndOffset;
                group->LambdaI[i] = _lLambdaI;
                group->BackSpike[i] = _lBackSpike;
                group->RingReadOffset[i] = _lRingReadOffset;
                group->LambdaV[i] = _lLambdaV;
                group->RefracTime[i] = _lRefracTime;
                group->RingWriteOffset[i] = _lRingWriteOffset;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged neuron update group 2
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronUpdateGroup2[g]; 
            
            for(unsigned int i = 0; i < (115u); i++) {
                int32_t _lRingReadEndOffset = group->RingReadEndOffset[i];
                uint8_t _lBackSpike = group->BackSpike[i];
                int32_t _lRingWriteOffset = group->RingWriteOffset[i];
                const uint32_t _lEndSpike = group->EndSpike[i];
                int32_t _lRingReadOffset = group->RingReadOffset[i];
                uint32_t _lStartSpike = group->StartSpike[i];
                // test whether spike condition was fulfilled previously
                // calculate membrane potential
                const int32_t _ringOffset = (0 * (115u) * 500) + (i * 500);
                const float _backT = 68.0f - t - 1.000000000e-01f;
                if(_lBackSpike)
                 {
                    _lRingReadOffset--;
                    if(_lRingReadOffset < 0)
                     {
                        _lRingReadOffset = 500 - 1;
                    }
                    
                    _lBackSpike = false;
                }
                
                if(_lRingReadOffset != _lRingReadEndOffset && fabs(_backT - group->RingSpikeTime[_ringOffset + _lRingReadOffset] - 1.000000000e-01f) < 1e-3f * 1.000000000e-01f)
                 {
                    _lBackSpike = true;
                }
                
                 {
                    // spike event condition 0
                    if((_lBackSpike)) {
                         {
                            group->spkEventSynSpikeEvent0[group->spkCntEventSynSpikeEvent0[0]++] = i;
                        }
                    }
                }
                // test for and register a true spike
                if ((_lStartSpike != _lEndSpike && t >= group->SpikeTimes[_lStartSpike])) {
                     {
                        group->spkSynSpike0[group->spkCntSynSpike0[0]++] = i;
                    }
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
                group->RingReadEndOffset[i] = _lRingReadEndOffset;
                group->BackSpike[i] = _lBackSpike;
                group->RingWriteOffset[i] = _lRingWriteOffset;
                group->RingReadOffset[i] = _lRingReadOffset;
                group->StartSpike[i] = _lStartSpike;
            }
        }
    }
    neuronUpdateTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - neuronUpdateStart).count();
}
