#include "definitions.h"

struct MergedCustomUpdateGroup0
 {
    float* __restrict__ OutPost;
    uint32_t numNeurons;
    
}
;
struct MergedCustomUpdateGroup1
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingWriteOffset;
    float* __restrict__ V;
    
}
;
struct MergedCustomUpdateGroup2
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    float* __restrict__ RefracTime;
    int32_t* __restrict__ RingReadEndOffset;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingWriteOffset;
    int32_t* __restrict__ RingWriteStartOffset;
    float* __restrict__ V;
    
}
;
struct MergedCustomUpdateGroup3
 {
    int32_t* __restrict__ RingReadEndOffset;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingWriteOffset;
    int32_t* __restrict__ RingWriteStartOffset;
    uint32_t* __restrict__ StartSpike;
    
}
;
struct MergedCustomUpdateWUGroup0
 {
    float* __restrict__ Gradient;
    uint32_t numSrcNeurons;
    uint32_t numTrgNeurons;
    
}
;
struct MergedCustomUpdateWUGroup1
 {
    float* __restrict__ Gradient;
    float* __restrict__ M;
    float* __restrict__ V;
    float* __restrict__ Variable;
    float Alpha;
    float MomentScale1;
    float MomentScale2;
    uint32_t numSrcNeurons;
    uint32_t numTrgNeurons;
    
}
;
static MergedCustomUpdateGroup0 mergedCustomUpdateGroup0[3];
void pushMergedCustomUpdateGroup0ToDevice(unsigned int idx, float* OutPost, uint32_t numNeurons) {
    mergedCustomUpdateGroup0[idx].OutPost = OutPost;
    mergedCustomUpdateGroup0[idx].numNeurons = numNeurons;
}
static MergedCustomUpdateGroup1 mergedCustomUpdateGroup1[1];
void pushMergedCustomUpdateGroup1ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, int32_t* RingReadOffset, int32_t* RingWriteOffset, float* V) {
    mergedCustomUpdateGroup1[idx].LambdaI = LambdaI;
    mergedCustomUpdateGroup1[idx].LambdaV = LambdaV;
    mergedCustomUpdateGroup1[idx].RingReadOffset = RingReadOffset;
    mergedCustomUpdateGroup1[idx].RingWriteOffset = RingWriteOffset;
    mergedCustomUpdateGroup1[idx].V = V;
}
static MergedCustomUpdateGroup2 mergedCustomUpdateGroup2[1];
void pushMergedCustomUpdateGroup2ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* RefracTime, int32_t* RingReadEndOffset, int32_t* RingReadOffset, int32_t* RingWriteOffset, int32_t* RingWriteStartOffset, float* V) {
    mergedCustomUpdateGroup2[idx].LambdaI = LambdaI;
    mergedCustomUpdateGroup2[idx].LambdaV = LambdaV;
    mergedCustomUpdateGroup2[idx].RefracTime = RefracTime;
    mergedCustomUpdateGroup2[idx].RingReadEndOffset = RingReadEndOffset;
    mergedCustomUpdateGroup2[idx].RingReadOffset = RingReadOffset;
    mergedCustomUpdateGroup2[idx].RingWriteOffset = RingWriteOffset;
    mergedCustomUpdateGroup2[idx].RingWriteStartOffset = RingWriteStartOffset;
    mergedCustomUpdateGroup2[idx].V = V;
}
static MergedCustomUpdateGroup3 mergedCustomUpdateGroup3[1];
void pushMergedCustomUpdateGroup3ToDevice(unsigned int idx, int32_t* RingReadEndOffset, int32_t* RingReadOffset, int32_t* RingWriteOffset, int32_t* RingWriteStartOffset, uint32_t* StartSpike) {
    mergedCustomUpdateGroup3[idx].RingReadEndOffset = RingReadEndOffset;
    mergedCustomUpdateGroup3[idx].RingReadOffset = RingReadOffset;
    mergedCustomUpdateGroup3[idx].RingWriteOffset = RingWriteOffset;
    mergedCustomUpdateGroup3[idx].RingWriteStartOffset = RingWriteStartOffset;
    mergedCustomUpdateGroup3[idx].StartSpike = StartSpike;
}
static MergedCustomUpdateWUGroup0 mergedCustomUpdateWUGroup0[3];
void pushMergedCustomUpdateWUGroup0ToDevice(unsigned int idx, float* Gradient, uint32_t numSrcNeurons, uint32_t numTrgNeurons) {
    mergedCustomUpdateWUGroup0[idx].Gradient = Gradient;
    mergedCustomUpdateWUGroup0[idx].numSrcNeurons = numSrcNeurons;
    mergedCustomUpdateWUGroup0[idx].numTrgNeurons = numTrgNeurons;
}
static MergedCustomUpdateWUGroup1 mergedCustomUpdateWUGroup1[3];
void pushMergedCustomUpdateWUGroup1ToDevice(unsigned int idx, float* Gradient, float* M, float* V, float* Variable, float Alpha, float MomentScale1, float MomentScale2, uint32_t numSrcNeurons, uint32_t numTrgNeurons) {
    mergedCustomUpdateWUGroup1[idx].Gradient = Gradient;
    mergedCustomUpdateWUGroup1[idx].M = M;
    mergedCustomUpdateWUGroup1[idx].V = V;
    mergedCustomUpdateWUGroup1[idx].Variable = Variable;
    mergedCustomUpdateWUGroup1[idx].Alpha = Alpha;
    mergedCustomUpdateWUGroup1[idx].MomentScale1 = MomentScale1;
    mergedCustomUpdateWUGroup1[idx].MomentScale2 = MomentScale2;
    mergedCustomUpdateWUGroup1[idx].numSrcNeurons = numSrcNeurons;
    mergedCustomUpdateWUGroup1[idx].numTrgNeurons = numTrgNeurons;
}
void pushMergedCustomUpdateWU1AlphaToDevice(unsigned int idx, float value) {
    mergedCustomUpdateWUGroup1[idx].Alpha = value;
}
void pushMergedCustomUpdateWU1MomentScale1ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateWUGroup1[idx].MomentScale1 = value;
}
void pushMergedCustomUpdateWU1MomentScale2ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateWUGroup1[idx].MomentScale2 = value;
}
void updateGradientLearn(unsigned long long timestep) {
    const auto customUpdateGradientLearnStart = std::chrono::high_resolution_clock::now();
     {
        // merged custom WU update group 1
        for(unsigned int g = 0; g < 3; g++) {
            const auto *group = &mergedCustomUpdateWUGroup1[g]; 
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                for (unsigned int j = 0; j < group->numTrgNeurons; j++) {
                    const unsigned int idSyn = (i * group->numTrgNeurons) + j;
                    float _lV = group->V[idSyn];
                    float _lM = group->M[idSyn];
                    float _lVariable = group->Variable[idSyn];
                    float _lGradient = group->Gradient[idSyn];
                    _lM = ((9.000000000e-01f) * _lM) + ((1.0f - (9.000000000e-01f)) * _lGradient);
                    _lV = ((9.990000000e-01f) * _lV) + ((1.0f - (9.990000000e-01f)) * _lGradient * _lGradient);
                    _lVariable -= (group->Alpha * _lM * group->MomentScale1) / (sqrt(_lV * group->MomentScale2) + (1.000000000e-08f));
                    _lGradient = 0.0f;
                    group->Variable[idSyn] = _lVariable;
                    group->Gradient[idSyn] = _lGradient;
                    group->V[idSyn] = _lV;
                    group->M[idSyn] = _lM;
                }
            }
        }
    }
    customUpdateGradientLearnTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateGradientLearnStart).count();
    const auto customUpdateGradientLearnRemapStart = std::chrono::high_resolution_clock::now();
    customUpdateGradientLearnRemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateGradientLearnRemapStart).count();
    const auto customUpdateGradientLearnTransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateGradientLearnTransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateGradientLearnTransposeStart).count();
}
void updateReset(unsigned long long timestep) {
    const auto customUpdateResetStart = std::chrono::high_resolution_clock::now();
     {
        // merged custom update group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup1[g]; 
            for(unsigned int i = 0; i < (17u); i++) {
                int32_t _lRingWriteOffset = group->RingWriteOffset[i];
                int32_t _lRingReadOffset = group->RingReadOffset[i];
                float _lLambdaI;
                float _lLambdaV;
                float _lV;
                _lV = (0.000000000e+00f);
                _lLambdaV = (0.000000000e+00f);
                _lLambdaI = (0.000000000e+00f);
                _lRingReadOffset = _lRingWriteOffset;
                if(_lRingWriteOffset >= 1360)
                 {
                    _lRingWriteOffset = 0;
                }
                
                group->RingWriteOffset[i] = _lRingWriteOffset;
                group->RingReadOffset[i] = _lRingReadOffset;
                group->LambdaI[i] = _lLambdaI;
                group->LambdaV[i] = _lLambdaV;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged custom update group 2
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup2[g]; 
            for(unsigned int i = 0; i < (256u); i++) {
                int32_t _lRingReadEndOffset = group->RingReadEndOffset[i];
                int32_t _lRingWriteStartOffset = group->RingWriteStartOffset[i];
                int32_t _lRingWriteOffset = group->RingWriteOffset[i];
                int32_t _lRingReadOffset = group->RingReadOffset[i];
                float _lLambdaI;
                float _lLambdaV;
                float _lRefracTime;
                float _lV;
                _lV = (0.000000000e+00f);
                _lRefracTime = (0.000000000e+00f);
                _lLambdaV = (0.000000000e+00f);
                _lLambdaI = (0.000000000e+00f);
                _lRingReadOffset = _lRingWriteOffset - 1;
                if(_lRingReadOffset < 0)
                 {
                    _lRingReadOffset = 499;
                }
                
                _lRingReadEndOffset = _lRingWriteStartOffset;
                _lRingWriteStartOffset = _lRingReadOffset;
                group->RingReadEndOffset[i] = _lRingReadEndOffset;
                group->RingWriteStartOffset[i] = _lRingWriteStartOffset;
                group->RingWriteOffset[i] = _lRingWriteOffset;
                group->RingReadOffset[i] = _lRingReadOffset;
                group->LambdaI[i] = _lLambdaI;
                group->LambdaV[i] = _lLambdaV;
                group->RefracTime[i] = _lRefracTime;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged custom update group 3
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup3[g]; 
            for(unsigned int i = 0; i < (115u); i++) {
                int32_t _lRingReadEndOffset = group->RingReadEndOffset[i];
                int32_t _lRingWriteStartOffset = group->RingWriteStartOffset[i];
                int32_t _lRingWriteOffset = group->RingWriteOffset[i];
                int32_t _lRingReadOffset = group->RingReadOffset[i];
                uint32_t _lStartSpike;
                _lStartSpike = (0u);
                _lRingReadOffset = _lRingWriteOffset - 1;
                if(_lRingReadOffset < 0)
                 {
                    _lRingReadOffset = 499;
                }
                
                _lRingReadEndOffset = _lRingWriteStartOffset;
                _lRingWriteStartOffset = _lRingReadOffset;
                group->RingReadEndOffset[i] = _lRingReadEndOffset;
                group->RingWriteStartOffset[i] = _lRingWriteStartOffset;
                group->RingWriteOffset[i] = _lRingWriteOffset;
                group->RingReadOffset[i] = _lRingReadOffset;
                group->StartSpike[i] = _lStartSpike;
            }
        }
    }
    customUpdateResetTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateResetStart).count();
    const auto customUpdateResetRemapStart = std::chrono::high_resolution_clock::now();
    customUpdateResetRemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateResetRemapStart).count();
    const auto customUpdateResetTransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateResetTransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateResetTransposeStart).count();
}
void updateZeroGradient(unsigned long long timestep) {
    const auto customUpdateZeroGradientStart = std::chrono::high_resolution_clock::now();
     {
        // merged custom WU update group 0
        for(unsigned int g = 0; g < 3; g++) {
            const auto *group = &mergedCustomUpdateWUGroup0[g]; 
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                for (unsigned int j = 0; j < group->numTrgNeurons; j++) {
                    const unsigned int idSyn = (i * group->numTrgNeurons) + j;
                    float _lGradient;
                    _lGradient = (0.000000000e+00f);
                    group->Gradient[idSyn] = _lGradient;
                }
            }
        }
    }
    customUpdateZeroGradientTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateZeroGradientStart).count();
    const auto customUpdateZeroGradientRemapStart = std::chrono::high_resolution_clock::now();
    customUpdateZeroGradientRemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateZeroGradientRemapStart).count();
    const auto customUpdateZeroGradientTransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateZeroGradientTransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateZeroGradientTransposeStart).count();
}
void updateZeroOutPost(unsigned long long timestep) {
    const auto customUpdateZeroOutPostStart = std::chrono::high_resolution_clock::now();
     {
        // merged custom update group 0
        for(unsigned int g = 0; g < 3; g++) {
            const auto *group = &mergedCustomUpdateGroup0[g]; 
            for(unsigned int i = 0; i < group->numNeurons; i++) {
                float _lOutPost;
                _lOutPost = (0.000000000e+00f);
                group->OutPost[i] = _lOutPost;
            }
        }
    }
    customUpdateZeroOutPostTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateZeroOutPostStart).count();
    const auto customUpdateZeroOutPostRemapStart = std::chrono::high_resolution_clock::now();
    customUpdateZeroOutPostRemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateZeroOutPostRemapStart).count();
    const auto customUpdateZeroOutPostTransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateZeroOutPostTransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateZeroOutPostTransposeStart).count();
}
