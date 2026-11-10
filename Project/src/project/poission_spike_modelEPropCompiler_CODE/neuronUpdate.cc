#include "definitions.h"

struct MergedNeuronUpdateGroup0
 {
    float* __restrict__ E;
    float* __restrict__ FAvgInSynWUMPost0;
    float* __restrict__ FAvgInSynWUMPost1;
    float* __restrict__ PsiInSynWUMPost0;
    float* __restrict__ PsiInSynWUMPost1;
    float* __restrict__ RefracTime;
    float* __restrict__ V;
    float* __restrict__ ZFilterOutSynWUMPre0;
    float* __restrict__ ZFilterOutSynWUMPre1;
    float* __restrict__ outPostInSyn0;
    float* __restrict__ outPreOutSyn0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkSynSpike0;
    
}
;
struct MergedNeuronUpdateGroup1
 {
    float* __restrict__ Bias;
    float* __restrict__ DeltaBias;
    float* __restrict__ E;
    float* __restrict__ V;
    float* __restrict__ YTrue;
    float* __restrict__ outPostInSyn0;
    
}
;
struct MergedNeuronUpdateGroup2
 {
    uint32_t* __restrict__ EndSpike;
    float* __restrict__ SpikeTimes;
    uint32_t* __restrict__ StartSpike;
    float* __restrict__ ZFilterOutSynWUMPre0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkSynSpike0;
    
}
;
struct MergedNeuronSpikeQueueUpdateGroup0
 {
    uint32_t* __restrict__ spkCntSynSpike0;
    
}
;
static MergedNeuronUpdateGroup0 mergedNeuronUpdateGroup0[1];
void pushMergedNeuronUpdateGroup0ToDevice(unsigned int idx, float* E, float* FAvgInSynWUMPost0, float* FAvgInSynWUMPost1, float* PsiInSynWUMPost0, float* PsiInSynWUMPost1, float* RefracTime, float* V, float* ZFilterOutSynWUMPre0, float* ZFilterOutSynWUMPre1, float* outPostInSyn0, float* outPreOutSyn0, uint32_t* spkCntSynSpike0, uint32_t* spkSynSpike0) {
    mergedNeuronUpdateGroup0[idx].E = E;
    mergedNeuronUpdateGroup0[idx].FAvgInSynWUMPost0 = FAvgInSynWUMPost0;
    mergedNeuronUpdateGroup0[idx].FAvgInSynWUMPost1 = FAvgInSynWUMPost1;
    mergedNeuronUpdateGroup0[idx].PsiInSynWUMPost0 = PsiInSynWUMPost0;
    mergedNeuronUpdateGroup0[idx].PsiInSynWUMPost1 = PsiInSynWUMPost1;
    mergedNeuronUpdateGroup0[idx].RefracTime = RefracTime;
    mergedNeuronUpdateGroup0[idx].V = V;
    mergedNeuronUpdateGroup0[idx].ZFilterOutSynWUMPre0 = ZFilterOutSynWUMPre0;
    mergedNeuronUpdateGroup0[idx].ZFilterOutSynWUMPre1 = ZFilterOutSynWUMPre1;
    mergedNeuronUpdateGroup0[idx].outPostInSyn0 = outPostInSyn0;
    mergedNeuronUpdateGroup0[idx].outPreOutSyn0 = outPreOutSyn0;
    mergedNeuronUpdateGroup0[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronUpdateGroup0[idx].spkSynSpike0 = spkSynSpike0;
}
static MergedNeuronUpdateGroup1 mergedNeuronUpdateGroup1[1];
void pushMergedNeuronUpdateGroup1ToDevice(unsigned int idx, float* Bias, float* DeltaBias, float* E, float* V, float* YTrue, float* outPostInSyn0) {
    mergedNeuronUpdateGroup1[idx].Bias = Bias;
    mergedNeuronUpdateGroup1[idx].DeltaBias = DeltaBias;
    mergedNeuronUpdateGroup1[idx].E = E;
    mergedNeuronUpdateGroup1[idx].V = V;
    mergedNeuronUpdateGroup1[idx].YTrue = YTrue;
    mergedNeuronUpdateGroup1[idx].outPostInSyn0 = outPostInSyn0;
}
static MergedNeuronUpdateGroup2 mergedNeuronUpdateGroup2[1];
void pushMergedNeuronUpdateGroup2ToDevice(unsigned int idx, uint32_t* EndSpike, float* SpikeTimes, uint32_t* StartSpike, float* ZFilterOutSynWUMPre0, uint32_t* spkCntSynSpike0, uint32_t* spkSynSpike0) {
    mergedNeuronUpdateGroup2[idx].EndSpike = EndSpike;
    mergedNeuronUpdateGroup2[idx].SpikeTimes = SpikeTimes;
    mergedNeuronUpdateGroup2[idx].StartSpike = StartSpike;
    mergedNeuronUpdateGroup2[idx].ZFilterOutSynWUMPre0 = ZFilterOutSynWUMPre0;
    mergedNeuronUpdateGroup2[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronUpdateGroup2[idx].spkSynSpike0 = spkSynSpike0;
}
static MergedNeuronSpikeQueueUpdateGroup0 mergedNeuronSpikeQueueUpdateGroup0[2];
void pushMergedNeuronSpikeQueueUpdateGroup0ToDevice(unsigned int idx, uint32_t* spkCntSynSpike0) {
    mergedNeuronSpikeQueueUpdateGroup0[idx].spkCntSynSpike0 = spkCntSynSpike0;
}
void pushMergedNeuronUpdate1YTrueToDevice(unsigned int idx, float* value) {
    mergedNeuronUpdateGroup1[idx].YTrue = value;
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
        }
    }
     {
        // merged neuron update group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronUpdateGroup0[g]; 
            
            for(unsigned int i = 0; i < (256u); i++) {
                float Isyn = 0;
                float _ISynFeedback = 0.000000000e+00f;
                float _lE = group->E[i];
                float _lRefracTime = group->RefracTime[i];
                float _lV = group->V[i];
                 {
                    // postsynaptic model 0
                    float linSyn = group->outPostInSyn0[i];
                    Isyn += linSyn;
                    linSyn = 0;
                    group->outPostInSyn0[i] = linSyn;
                }
                 {
                    _ISynFeedback += group->outPreOutSyn0[i];
                    group->outPreOutSyn0[i] = 0.000000000e+00f;
                }
                // test whether spike condition was fulfilled previously
                // calculate membrane potential
                _lV = ((9.512294245e-01f) * _lV) + Isyn;
                if(_lRefracTime > 0.0f)
                 {
                    _lRefracTime -= 1.000000000e+00f;
                }
                
                _lE = _ISynFeedback;
                 {
                    // presynaptic weight update 0
                    float _lZFilter = group->ZFilterOutSynWUMPre0[i];
                    _lZFilter *= (9.512294245e-01f);
                    group->ZFilterOutSynWUMPre0[i] = _lZFilter;
                }
                 {
                    // presynaptic weight update 1
                    float _lZFilter = group->ZFilterOutSynWUMPre1[i];
                    _lZFilter *= (9.512294245e-01f);
                    group->ZFilterOutSynWUMPre1[i] = _lZFilter;
                }
                 {
                    // postsynaptic weight update 0
                    float _lFAvg = group->FAvgInSynWUMPost0[i];
                    float _lPsi = group->PsiInSynWUMPost0[i];
                    _lFAvg *= (9.980019987e-01f);
                    if(_lRefracTime > 0.0f)
                     {
                        _lPsi = 0.0f;
                    }
                    else
                     {
                        _lPsi = (1.0f / (6.100000000e-01f)) * 0.3f * fmax(0.0f, 1.0f - fabs((_lV - (6.100000000e-01f)) / (6.100000000e-01f)));
                    }
                    
                    group->FAvgInSynWUMPost0[i] = _lFAvg;
                    group->PsiInSynWUMPost0[i] = _lPsi;
                }
                 {
                    // postsynaptic weight update 1
                    float _lFAvg = group->FAvgInSynWUMPost1[i];
                    float _lPsi = group->PsiInSynWUMPost1[i];
                    _lFAvg *= (9.980019987e-01f);
                    if(_lRefracTime > 0.0f)
                     {
                        _lPsi = 0.0f;
                    }
                    else
                     {
                        _lPsi = (1.0f / (6.100000000e-01f)) * 0.3f * fmax(0.0f, 1.0f - fabs((_lV - (6.100000000e-01f)) / (6.100000000e-01f)));
                    }
                    
                    group->FAvgInSynWUMPost1[i] = _lFAvg;
                    group->PsiInSynWUMPost1[i] = _lPsi;
                }
                // test for and register a true spike
                if ((_lV >= (6.100000000e-01f) && _lRefracTime <= 0.0f)) {
                     {
                        // presynaptic weight update 0
                        float _lZFilter = group->ZFilterOutSynWUMPre0[i];
                        _lZFilter += 1.0f;
                        group->ZFilterOutSynWUMPre0[i] = _lZFilter;
                    }
                     {
                        // presynaptic weight update 1
                        float _lZFilter = group->ZFilterOutSynWUMPre1[i];
                        _lZFilter += 1.0f;
                        group->ZFilterOutSynWUMPre1[i] = _lZFilter;
                    }
                     {
                        // postsynaptic weight update 0
                        float _lFAvg = group->FAvgInSynWUMPost0[i];
                        _lFAvg += (1.0f - (9.980019987e-01f));
                        group->FAvgInSynWUMPost0[i] = _lFAvg;
                    }
                     {
                        // postsynaptic weight update 1
                        float _lFAvg = group->FAvgInSynWUMPost1[i];
                        _lFAvg += (1.0f - (9.980019987e-01f));
                        group->FAvgInSynWUMPost1[i] = _lFAvg;
                    }
                     {
                        group->spkSynSpike0[group->spkCntSynSpike0[0]++] = i;
                    }
                    // spike reset code
                    _lV -= ((6.100000000e-01f) - (0.000000000e+00f));
                    _lRefracTime = (0.000000000e+00f);
                }
                group->E[i] = _lE;
                group->RefracTime[i] = _lRefracTime;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged neuron update group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronUpdateGroup1[g]; 
            
            for(unsigned int i = 0; i < (34u); i++) {
                float Isyn = 0;
                float _lDeltaBias = group->DeltaBias[i];
                const float _lBias = group->Bias[i];
                float _lE = group->E[i];
                float _lV = group->V[i];
                 {
                    // postsynaptic model 0
                    float linSyn = group->outPostInSyn0[i];
                    Isyn += linSyn;
                    linSyn = 0;
                    group->outPostInSyn0[i] = linSyn;
                }
                // calculate membrane potential
                _lV = ((9.512294245e-01f) * _lV) + Isyn + _lBias;
                const uint32_t _timestep = (int32_t)round(t / 1.000000000e+00f);
                const uint32_t _index = (0 * 680 * (34u)) + (_timestep * (34u)) + i;
                const float _yTrue = group->YTrue[_index];
                _lE = _lV - _yTrue;
                _lDeltaBias += _lE;
                group->DeltaBias[i] = _lDeltaBias;
                group->E[i] = _lE;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged neuron update group 2
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronUpdateGroup2[g]; 
            
            for(unsigned int i = 0; i < (115u); i++) {
                const uint32_t _lEndSpike = group->EndSpike[i];
                uint32_t _lStartSpike = group->StartSpike[i];
                // test whether spike condition was fulfilled previously
                // calculate membrane potential
                 {
                    // presynaptic weight update 0
                    float _lZFilter = group->ZFilterOutSynWUMPre0[i];
                    _lZFilter *= (9.512294245e-01f);
                    group->ZFilterOutSynWUMPre0[i] = _lZFilter;
                }
                // test for and register a true spike
                if ((_lStartSpike != _lEndSpike && t >= group->SpikeTimes[_lStartSpike])) {
                     {
                        // presynaptic weight update 0
                        float _lZFilter = group->ZFilterOutSynWUMPre0[i];
                        _lZFilter += 1.0f;
                        group->ZFilterOutSynWUMPre0[i] = _lZFilter;
                    }
                     {
                        group->spkSynSpike0[group->spkCntSynSpike0[0]++] = i;
                    }
                    // spike reset code
                    _lStartSpike++;
                }
                group->StartSpike[i] = _lStartSpike;
            }
        }
    }
    neuronUpdateTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - neuronUpdateStart).count();
}
