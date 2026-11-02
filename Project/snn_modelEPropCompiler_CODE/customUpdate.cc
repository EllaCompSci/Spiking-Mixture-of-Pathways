#include "definitions.h"

struct MergedCustomUpdateGroup0
 {
    float* __restrict__ MaxVal;
    float* __restrict__ SoftmaxVal;
    float* __restrict__ SumExpVal;
    float* __restrict__ Val;
    
}
;
struct MergedCustomUpdateGroup1
 {
    float* __restrict__ MaxVal;
    float* __restrict__ SumExpVal;
    float* __restrict__ Val;
    
}
;
struct MergedCustomUpdateGroup2
 {
    float* __restrict__ MaxVal;
    float* __restrict__ Val;
    
}
;
struct MergedCustomUpdateGroup3
 {
    float* __restrict__ VSoftmaxSum;
    
}
;
struct MergedCustomUpdateGroup4
 {
    float* __restrict__ Gradient;
    float* __restrict__ M;
    float* __restrict__ V;
    float* __restrict__ Variable;
    float Alpha;
    float MomentScale1;
    float MomentScale2;
    
}
;
struct MergedCustomUpdateWUGroup0
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
static MergedCustomUpdateGroup0 mergedCustomUpdateGroup0[1];
void pushMergedCustomUpdateGroup0ToDevice(unsigned int idx, float* MaxVal, float* SoftmaxVal, float* SumExpVal, float* Val) {
    mergedCustomUpdateGroup0[idx].MaxVal = MaxVal;
    mergedCustomUpdateGroup0[idx].SoftmaxVal = SoftmaxVal;
    mergedCustomUpdateGroup0[idx].SumExpVal = SumExpVal;
    mergedCustomUpdateGroup0[idx].Val = Val;
}
static MergedCustomUpdateGroup1 mergedCustomUpdateGroup1[1];
void pushMergedCustomUpdateGroup1ToDevice(unsigned int idx, float* MaxVal, float* SumExpVal, float* Val) {
    mergedCustomUpdateGroup1[idx].MaxVal = MaxVal;
    mergedCustomUpdateGroup1[idx].SumExpVal = SumExpVal;
    mergedCustomUpdateGroup1[idx].Val = Val;
}
static MergedCustomUpdateGroup2 mergedCustomUpdateGroup2[1];
void pushMergedCustomUpdateGroup2ToDevice(unsigned int idx, float* MaxVal, float* Val) {
    mergedCustomUpdateGroup2[idx].MaxVal = MaxVal;
    mergedCustomUpdateGroup2[idx].Val = Val;
}
static MergedCustomUpdateGroup3 mergedCustomUpdateGroup3[1];
void pushMergedCustomUpdateGroup3ToDevice(unsigned int idx, float* VSoftmaxSum) {
    mergedCustomUpdateGroup3[idx].VSoftmaxSum = VSoftmaxSum;
}
static MergedCustomUpdateGroup4 mergedCustomUpdateGroup4[1];
void pushMergedCustomUpdateGroup4ToDevice(unsigned int idx, float* Gradient, float* M, float* V, float* Variable, float Alpha, float MomentScale1, float MomentScale2) {
    mergedCustomUpdateGroup4[idx].Gradient = Gradient;
    mergedCustomUpdateGroup4[idx].M = M;
    mergedCustomUpdateGroup4[idx].V = V;
    mergedCustomUpdateGroup4[idx].Variable = Variable;
    mergedCustomUpdateGroup4[idx].Alpha = Alpha;
    mergedCustomUpdateGroup4[idx].MomentScale1 = MomentScale1;
    mergedCustomUpdateGroup4[idx].MomentScale2 = MomentScale2;
}
static MergedCustomUpdateWUGroup0 mergedCustomUpdateWUGroup0[2];
void pushMergedCustomUpdateWUGroup0ToDevice(unsigned int idx, float* Gradient, float* M, float* V, float* Variable, float Alpha, float MomentScale1, float MomentScale2, uint32_t numSrcNeurons, uint32_t numTrgNeurons) {
    mergedCustomUpdateWUGroup0[idx].Gradient = Gradient;
    mergedCustomUpdateWUGroup0[idx].M = M;
    mergedCustomUpdateWUGroup0[idx].V = V;
    mergedCustomUpdateWUGroup0[idx].Variable = Variable;
    mergedCustomUpdateWUGroup0[idx].Alpha = Alpha;
    mergedCustomUpdateWUGroup0[idx].MomentScale1 = MomentScale1;
    mergedCustomUpdateWUGroup0[idx].MomentScale2 = MomentScale2;
    mergedCustomUpdateWUGroup0[idx].numSrcNeurons = numSrcNeurons;
    mergedCustomUpdateWUGroup0[idx].numTrgNeurons = numTrgNeurons;
}
void pushMergedCustomUpdate4AlphaToDevice(unsigned int idx, float value) {
    mergedCustomUpdateGroup4[idx].Alpha = value;
}
void pushMergedCustomUpdate4MomentScale1ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateGroup4[idx].MomentScale1 = value;
}
void pushMergedCustomUpdate4MomentScale2ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateGroup4[idx].MomentScale2 = value;
}
void pushMergedCustomUpdateWU0AlphaToDevice(unsigned int idx, float value) {
    mergedCustomUpdateWUGroup0[idx].Alpha = value;
}
void pushMergedCustomUpdateWU0MomentScale1ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateWUGroup0[idx].MomentScale1 = value;
}
void pushMergedCustomUpdateWU0MomentScale2ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateWUGroup0[idx].MomentScale2 = value;
}
void updateGradientLearn(unsigned long long timestep) {
     {
        // merged custom update group 4
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup4[g]; 
            for(unsigned int i = 0; i < (10u); i++) {
                float _lV = group->V[i];
                float _lM = group->M[i];
                float _lVariable = group->Variable[i];
                float _lGradient = group->Gradient[i];
                _lM = ((9.000000000e-01f) * _lM) + ((1.0f - (9.000000000e-01f)) * _lGradient);
                _lV = ((9.990000000e-01f) * _lV) + ((1.0f - (9.990000000e-01f)) * _lGradient * _lGradient);
                _lVariable -= (group->Alpha * _lM * group->MomentScale1) / (sqrt(_lV * group->MomentScale2) + (1.000000000e-08f));
                _lGradient = 0.0f;
                group->Variable[i] = _lVariable;
                group->Gradient[i] = _lGradient;
                group->V[i] = _lV;
                group->M[i] = _lM;
            }
        }
    }
     {
        // merged custom WU update group 0
        for(unsigned int g = 0; g < 2; g++) {
            const auto *group = &mergedCustomUpdateWUGroup0[g]; 
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
}
void updateReset(unsigned long long timestep) {
     {
        // merged custom update group 3
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup3[g]; 
            for(unsigned int i = 0; i < (10u); i++) {
                float _lVSoftmaxSum;
                _lVSoftmaxSum = (0.000000000e+00f);
                group->VSoftmaxSum[i] = _lVSoftmaxSum;
            }
        }
    }
}
void updateSoftmax1(unsigned long long timestep) {
     {
        // merged custom update group 2
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup2[g]; 
            float _lrMaxVal = -3.402823466e+38f;
            for(unsigned int i = 0; i < (10u); i++) {
                float _lMaxVal;
                const float _lVal = group->Val[i];
                _lMaxVal = _lVal;
                _lrMaxVal = fmax(_lrMaxVal, _lMaxVal);
            }
            group->MaxVal[0] = _lrMaxVal;
        }
    }
}
void updateSoftmax2(unsigned long long timestep) {
     {
        // merged custom update group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup1[g]; 
            float _lrSumExpVal = 0.0f;
            for(unsigned int i = 0; i < (10u); i++) {
                float _lSumExpVal;
                const float _lMaxVal = group->MaxVal[0];
                const float _lVal = group->Val[i];
                _lSumExpVal = exp((_lVal - _lMaxVal) / (1.000000000e+00f));
                _lrSumExpVal += _lSumExpVal;
            }
            group->SumExpVal[0] = _lrSumExpVal;
        }
    }
}
void updateSoftmax3(unsigned long long timestep) {
     {
        // merged custom update group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup0[g]; 
            for(unsigned int i = 0; i < (10u); i++) {
                float _lSoftmaxVal = group->SoftmaxVal[i];
                const float _lSumExpVal = group->SumExpVal[0];
                const float _lMaxVal = group->MaxVal[0];
                const float _lVal = group->Val[i];
                _lSoftmaxVal = exp((_lVal - _lMaxVal) / (1.000000000e+00f)) / _lSumExpVal;
                group->SoftmaxVal[i] = _lSoftmaxVal;
            }
        }
    }
}
