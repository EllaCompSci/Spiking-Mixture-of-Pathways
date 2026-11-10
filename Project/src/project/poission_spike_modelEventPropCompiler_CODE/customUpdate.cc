#include "definitions.h"

struct MergedCustomUpdateGroup0
 {
    float* __restrict__ OutPost;
    uint32_t numNeurons;
    
}
;
struct MergedCustomUpdateGroup1
 {
    float* __restrict__ MaxVal;
    float* __restrict__ SoftmaxVal;
    float* __restrict__ SumExpVal;
    float* __restrict__ Val;
    
}
;
struct MergedCustomUpdateGroup2
 {
    float* __restrict__ MaxVal;
    float* __restrict__ SumExpVal;
    float* __restrict__ Val;
    
}
;
struct MergedCustomUpdateGroup3
 {
    float* __restrict__ MaxVal;
    float* __restrict__ Val;
    
}
;
struct MergedCustomUpdateGroup4
 {
    uint8_t* __restrict__ YTrue;
    uint8_t* __restrict__ YTrueBack;
    
}
;
struct MergedCustomUpdateGroup5
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    float* __restrict__ V;
    float* __restrict__ VAvg;
    
}
;
struct MergedCustomUpdateGroup6
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
struct MergedCustomUpdateGroup7
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
void pushMergedCustomUpdateGroup1ToDevice(unsigned int idx, float* MaxVal, float* SoftmaxVal, float* SumExpVal, float* Val) {
    mergedCustomUpdateGroup1[idx].MaxVal = MaxVal;
    mergedCustomUpdateGroup1[idx].SoftmaxVal = SoftmaxVal;
    mergedCustomUpdateGroup1[idx].SumExpVal = SumExpVal;
    mergedCustomUpdateGroup1[idx].Val = Val;
}
static MergedCustomUpdateGroup2 mergedCustomUpdateGroup2[1];
void pushMergedCustomUpdateGroup2ToDevice(unsigned int idx, float* MaxVal, float* SumExpVal, float* Val) {
    mergedCustomUpdateGroup2[idx].MaxVal = MaxVal;
    mergedCustomUpdateGroup2[idx].SumExpVal = SumExpVal;
    mergedCustomUpdateGroup2[idx].Val = Val;
}
static MergedCustomUpdateGroup3 mergedCustomUpdateGroup3[1];
void pushMergedCustomUpdateGroup3ToDevice(unsigned int idx, float* MaxVal, float* Val) {
    mergedCustomUpdateGroup3[idx].MaxVal = MaxVal;
    mergedCustomUpdateGroup3[idx].Val = Val;
}
static MergedCustomUpdateGroup4 mergedCustomUpdateGroup4[1];
void pushMergedCustomUpdateGroup4ToDevice(unsigned int idx, uint8_t* YTrue, uint8_t* YTrueBack) {
    mergedCustomUpdateGroup4[idx].YTrue = YTrue;
    mergedCustomUpdateGroup4[idx].YTrueBack = YTrueBack;
}
static MergedCustomUpdateGroup5 mergedCustomUpdateGroup5[1];
void pushMergedCustomUpdateGroup5ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* V, float* VAvg) {
    mergedCustomUpdateGroup5[idx].LambdaI = LambdaI;
    mergedCustomUpdateGroup5[idx].LambdaV = LambdaV;
    mergedCustomUpdateGroup5[idx].V = V;
    mergedCustomUpdateGroup5[idx].VAvg = VAvg;
}
static MergedCustomUpdateGroup6 mergedCustomUpdateGroup6[1];
void pushMergedCustomUpdateGroup6ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* RefracTime, int32_t* RingReadEndOffset, int32_t* RingReadOffset, int32_t* RingWriteOffset, int32_t* RingWriteStartOffset, float* V) {
    mergedCustomUpdateGroup6[idx].LambdaI = LambdaI;
    mergedCustomUpdateGroup6[idx].LambdaV = LambdaV;
    mergedCustomUpdateGroup6[idx].RefracTime = RefracTime;
    mergedCustomUpdateGroup6[idx].RingReadEndOffset = RingReadEndOffset;
    mergedCustomUpdateGroup6[idx].RingReadOffset = RingReadOffset;
    mergedCustomUpdateGroup6[idx].RingWriteOffset = RingWriteOffset;
    mergedCustomUpdateGroup6[idx].RingWriteStartOffset = RingWriteStartOffset;
    mergedCustomUpdateGroup6[idx].V = V;
}
static MergedCustomUpdateGroup7 mergedCustomUpdateGroup7[1];
void pushMergedCustomUpdateGroup7ToDevice(unsigned int idx, int32_t* RingReadEndOffset, int32_t* RingReadOffset, int32_t* RingWriteOffset, int32_t* RingWriteStartOffset, uint32_t* StartSpike) {
    mergedCustomUpdateGroup7[idx].RingReadEndOffset = RingReadEndOffset;
    mergedCustomUpdateGroup7[idx].RingReadOffset = RingReadOffset;
    mergedCustomUpdateGroup7[idx].RingWriteOffset = RingWriteOffset;
    mergedCustomUpdateGroup7[idx].RingWriteStartOffset = RingWriteStartOffset;
    mergedCustomUpdateGroup7[idx].StartSpike = StartSpike;
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
void updateBatchSoftmax1(unsigned long long timestep) {
    const auto customUpdateBatchSoftmax1Start = std::chrono::high_resolution_clock::now();
     {
        // merged custom update group 3
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup3[g]; 
            float _lrMaxVal = -3.402823466e+38f;
            for(unsigned int i = 0; i < (34u); i++) {
                float _lMaxVal;
                const float _lVal = group->Val[i];
                _lMaxVal = _lVal;
                _lrMaxVal = fmax(_lrMaxVal, _lMaxVal);
            }
            group->MaxVal[0] = _lrMaxVal;
        }
    }
    customUpdateBatchSoftmax1Time += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax1Start).count();
    const auto customUpdateBatchSoftmax1RemapStart = std::chrono::high_resolution_clock::now();
    customUpdateBatchSoftmax1RemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax1RemapStart).count();
    const auto customUpdateBatchSoftmax1TransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateBatchSoftmax1TransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax1TransposeStart).count();
}
void updateBatchSoftmax2(unsigned long long timestep) {
    const auto customUpdateBatchSoftmax2Start = std::chrono::high_resolution_clock::now();
     {
        // merged custom update group 2
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup2[g]; 
            float _lrSumExpVal = 0.0f;
            for(unsigned int i = 0; i < (34u); i++) {
                float _lSumExpVal;
                const float _lMaxVal = group->MaxVal[0];
                const float _lVal = group->Val[i];
                _lSumExpVal = exp((_lVal - _lMaxVal) / (1.000000000e+00f));
                _lrSumExpVal += _lSumExpVal;
            }
            group->SumExpVal[0] = _lrSumExpVal;
        }
    }
    customUpdateBatchSoftmax2Time += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax2Start).count();
    const auto customUpdateBatchSoftmax2RemapStart = std::chrono::high_resolution_clock::now();
    customUpdateBatchSoftmax2RemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax2RemapStart).count();
    const auto customUpdateBatchSoftmax2TransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateBatchSoftmax2TransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax2TransposeStart).count();
}
void updateBatchSoftmax3(unsigned long long timestep) {
    const auto customUpdateBatchSoftmax3Start = std::chrono::high_resolution_clock::now();
     {
        // merged custom update group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup1[g]; 
            for(unsigned int i = 0; i < (34u); i++) {
                float _lSoftmaxVal = group->SoftmaxVal[i];
                const float _lSumExpVal = group->SumExpVal[0];
                const float _lMaxVal = group->MaxVal[0];
                const float _lVal = group->Val[i];
                _lSoftmaxVal = exp((_lVal - _lMaxVal) / (1.000000000e+00f)) / _lSumExpVal;
                group->SoftmaxVal[i] = _lSoftmaxVal;
            }
        }
    }
    customUpdateBatchSoftmax3Time += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax3Start).count();
    const auto customUpdateBatchSoftmax3RemapStart = std::chrono::high_resolution_clock::now();
    customUpdateBatchSoftmax3RemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax3RemapStart).count();
    const auto customUpdateBatchSoftmax3TransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateBatchSoftmax3TransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateBatchSoftmax3TransposeStart).count();
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
        // merged custom update group 4
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup4[g]; 
             {
                const uint8_t _lYTrue = group->YTrue[0];
                uint8_t _lYTrueBack;
                _lYTrueBack = _lYTrue;
                group->YTrueBack[0] = _lYTrueBack;
            }
        }
    }
     {
        // merged custom update group 5
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup5[g]; 
            for(unsigned int i = 0; i < (34u); i++) {
                float _lLambdaI;
                float _lLambdaV;
                float _lVAvg;
                float _lV;
                _lV = (0.000000000e+00f);
                _lVAvg = (0.000000000e+00f);
                _lLambdaV = (0.000000000e+00f);
                _lLambdaI = (0.000000000e+00f);
                group->LambdaI[i] = _lLambdaI;
                group->LambdaV[i] = _lLambdaV;
                group->VAvg[i] = _lVAvg;
                group->V[i] = _lV;
            }
        }
    }
     {
        // merged custom update group 6
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup6[g]; 
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
        // merged custom update group 7
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup7[g]; 
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
