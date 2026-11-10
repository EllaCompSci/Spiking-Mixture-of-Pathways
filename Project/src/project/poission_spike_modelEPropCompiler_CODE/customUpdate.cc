#include "definitions.h"

struct MergedCustomUpdateGroup0
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
void pushMergedCustomUpdateGroup0ToDevice(unsigned int idx, float* Gradient, float* M, float* V, float* Variable, float Alpha, float MomentScale1, float MomentScale2) {
    mergedCustomUpdateGroup0[idx].Gradient = Gradient;
    mergedCustomUpdateGroup0[idx].M = M;
    mergedCustomUpdateGroup0[idx].V = V;
    mergedCustomUpdateGroup0[idx].Variable = Variable;
    mergedCustomUpdateGroup0[idx].Alpha = Alpha;
    mergedCustomUpdateGroup0[idx].MomentScale1 = MomentScale1;
    mergedCustomUpdateGroup0[idx].MomentScale2 = MomentScale2;
}
static MergedCustomUpdateWUGroup0 mergedCustomUpdateWUGroup0[3];
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
void pushMergedCustomUpdate0AlphaToDevice(unsigned int idx, float value) {
    mergedCustomUpdateGroup0[idx].Alpha = value;
}
void pushMergedCustomUpdate0MomentScale1ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateGroup0[idx].MomentScale1 = value;
}
void pushMergedCustomUpdate0MomentScale2ToDevice(unsigned int idx, float value) {
    mergedCustomUpdateGroup0[idx].MomentScale2 = value;
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
    const auto customUpdateGradientLearnStart = std::chrono::high_resolution_clock::now();
     {
        // merged custom update group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateGroup0[g]; 
            for(unsigned int i = 0; i < (34u); i++) {
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
        for(unsigned int g = 0; g < 3; g++) {
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
    customUpdateGradientLearnTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateGradientLearnStart).count();
    const auto customUpdateGradientLearnRemapStart = std::chrono::high_resolution_clock::now();
    customUpdateGradientLearnRemapTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateGradientLearnRemapStart).count();
    const auto customUpdateGradientLearnTransposeStart = std::chrono::high_resolution_clock::now();
    customUpdateGradientLearnTransposeTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - customUpdateGradientLearnTransposeStart).count();
}
