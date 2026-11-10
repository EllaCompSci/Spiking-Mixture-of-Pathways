#include "definitions.h"

struct MergedPresynapticUpdateGroup0
 {
    float* __restrict__ g;
    float* __restrict__ outPost;
    uint32_t* __restrict__ srcSpk;
    uint32_t* __restrict__ srcSpkCnt;
    
}
;
struct MergedPresynapticUpdateGroup1
 {
    float* __restrict__ g;
    float* __restrict__ outPost;
    uint32_t* __restrict__ srcSpk;
    uint32_t* __restrict__ srcSpkCnt;
    
}
;
struct MergedSynapseDynamicsGroup0
 {
    float* __restrict__ DeltaG;
    float* __restrict__ E_post;
    float* __restrict__ ZFilter;
    float* __restrict__ g;
    float* __restrict__ outPre;
    
}
;
struct MergedSynapseDynamicsGroup1
 {
    float* __restrict__ DeltaG;
    float* __restrict__ E_post;
    float* __restrict__ FAvg;
    float* __restrict__ Psi;
    float* __restrict__ ZFilter;
    float* __restrict__ eFiltered;
    uint32_t numSrcNeurons;
    
}
;
static MergedPresynapticUpdateGroup0 mergedPresynapticUpdateGroup0[1];
void pushMergedPresynapticUpdateGroup0ToDevice(unsigned int idx, float* g, float* outPost, uint32_t* srcSpk, uint32_t* srcSpkCnt) {
    mergedPresynapticUpdateGroup0[idx].g = g;
    mergedPresynapticUpdateGroup0[idx].outPost = outPost;
    mergedPresynapticUpdateGroup0[idx].srcSpk = srcSpk;
    mergedPresynapticUpdateGroup0[idx].srcSpkCnt = srcSpkCnt;
}
static MergedPresynapticUpdateGroup1 mergedPresynapticUpdateGroup1[2];
void pushMergedPresynapticUpdateGroup1ToDevice(unsigned int idx, float* g, float* outPost, uint32_t* srcSpk, uint32_t* srcSpkCnt) {
    mergedPresynapticUpdateGroup1[idx].g = g;
    mergedPresynapticUpdateGroup1[idx].outPost = outPost;
    mergedPresynapticUpdateGroup1[idx].srcSpk = srcSpk;
    mergedPresynapticUpdateGroup1[idx].srcSpkCnt = srcSpkCnt;
}
static MergedSynapseDynamicsGroup0 mergedSynapseDynamicsGroup0[1];
void pushMergedSynapseDynamicsGroup0ToDevice(unsigned int idx, float* DeltaG, float* E_post, float* ZFilter, float* g, float* outPre) {
    mergedSynapseDynamicsGroup0[idx].DeltaG = DeltaG;
    mergedSynapseDynamicsGroup0[idx].E_post = E_post;
    mergedSynapseDynamicsGroup0[idx].ZFilter = ZFilter;
    mergedSynapseDynamicsGroup0[idx].g = g;
    mergedSynapseDynamicsGroup0[idx].outPre = outPre;
}
static MergedSynapseDynamicsGroup1 mergedSynapseDynamicsGroup1[2];
void pushMergedSynapseDynamicsGroup1ToDevice(unsigned int idx, float* DeltaG, float* E_post, float* FAvg, float* Psi, float* ZFilter, float* eFiltered, uint32_t numSrcNeurons) {
    mergedSynapseDynamicsGroup1[idx].DeltaG = DeltaG;
    mergedSynapseDynamicsGroup1[idx].E_post = E_post;
    mergedSynapseDynamicsGroup1[idx].FAvg = FAvg;
    mergedSynapseDynamicsGroup1[idx].Psi = Psi;
    mergedSynapseDynamicsGroup1[idx].ZFilter = ZFilter;
    mergedSynapseDynamicsGroup1[idx].eFiltered = eFiltered;
    mergedSynapseDynamicsGroup1[idx].numSrcNeurons = numSrcNeurons;
}
void updateSynapses(float t) {
    const auto synapseDynamicsStart = std::chrono::high_resolution_clock::now();
     {
        // merged synapse dynamics group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedSynapseDynamicsGroup0[g]; 
            for(unsigned int i = 0; i < (256u); i++) {
                for (unsigned int j = 0; j < (34u); j++) {
                    const uint32_t idSyn = ((uint32_t)i * (34u)) + j;
                    group->DeltaG[idSyn] += group->ZFilter[i] * group->E_post[j];
                    group->outPre[i] += group->g[idSyn] * group->E_post[j];
                }
            }
        }
    }
     {
        // merged synapse dynamics group 1
        for(unsigned int g = 0; g < 2; g++) {
            const auto *group = &mergedSynapseDynamicsGroup1[g]; 
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                for (unsigned int j = 0; j < (256u); j++) {
                    const uint32_t idSyn = ((uint32_t)i * (256u)) + j;
                    const float _e = group->ZFilter[i] * group->Psi[j];
                    float _eF = group->eFiltered[idSyn];
                    _eF = (_eF * (9.512294245e-01f)) + _e;
                    group->DeltaG[idSyn] += (_eF * group->E_post[j]) + ((group->FAvg[j] - (1.000000000e-02f)) * (1.000000000e-03f) * _e);
                    group->eFiltered[idSyn] = _eF;
                }
            }
        }
    }
    synapseDynamicsTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - synapseDynamicsStart).count();
    const auto presynapticUpdateStart = std::chrono::high_resolution_clock::now();
     {
        // merged presynaptic update group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedPresynapticUpdateGroup0[g]; 
            
            // process presynaptic events: True Spikes
            for (unsigned int i = 0; i < group->srcSpkCnt[0]; i++) {
                const unsigned int idPre = group->srcSpk[i];
                for (unsigned int ipost = 0; ipost < (34u); ipost++) {
                    const uint32_t idSyn = ((uint32_t)idPre * (34u)) + ipost;
                    group->outPost[ipost] += group->g[idSyn];
                }
            }
        }
    }
     {
        // merged presynaptic update group 1
        for(unsigned int g = 0; g < 2; g++) {
            const auto *group = &mergedPresynapticUpdateGroup1[g]; 
            
            // process presynaptic events: True Spikes
            for (unsigned int i = 0; i < group->srcSpkCnt[0]; i++) {
                const unsigned int idPre = group->srcSpk[i];
                for (unsigned int ipost = 0; ipost < (256u); ipost++) {
                    const uint32_t idSyn = ((uint32_t)idPre * (256u)) + ipost;
                    group->outPost[ipost] += group->g[idSyn];
                }
            }
        }
    }
    presynapticUpdateTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - presynapticUpdateStart).count();
    const auto postsynapticUpdateStart = std::chrono::high_resolution_clock::now();
    postsynapticUpdateTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - postsynapticUpdateStart).count();
}
