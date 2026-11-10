#include "definitions.h"

struct MergedPresynapticUpdateGroup0
 {
    float* __restrict__ Gradient;
    float* __restrict__ LambdaI_post;
    float* __restrict__ LambdaV_post;
    float* __restrict__ g;
    float* __restrict__ outPost;
    float* __restrict__ outPre;
    uint32_t* __restrict__ srcSpk;
    uint32_t* __restrict__ srcSpkCnt;
    uint32_t* __restrict__ srcSpkCntEvent;
    uint32_t* __restrict__ srcSpkEvent;
    uint32_t numTrgNeurons;
    
}
;
struct MergedPresynapticUpdateGroup1
 {
    float* __restrict__ Gradient;
    float* __restrict__ LambdaI_post;
    float* __restrict__ g;
    float* __restrict__ outPost;
    uint32_t* __restrict__ srcSpk;
    uint32_t* __restrict__ srcSpkCnt;
    uint32_t* __restrict__ srcSpkCntEvent;
    uint32_t* __restrict__ srcSpkEvent;
    
}
;
static MergedPresynapticUpdateGroup0 mergedPresynapticUpdateGroup0[2];
void pushMergedPresynapticUpdateGroup0ToDevice(unsigned int idx, float* Gradient, float* LambdaI_post, float* LambdaV_post, float* g, float* outPost, float* outPre, uint32_t* srcSpk, uint32_t* srcSpkCnt, uint32_t* srcSpkCntEvent, uint32_t* srcSpkEvent, uint32_t numTrgNeurons) {
    mergedPresynapticUpdateGroup0[idx].Gradient = Gradient;
    mergedPresynapticUpdateGroup0[idx].LambdaI_post = LambdaI_post;
    mergedPresynapticUpdateGroup0[idx].LambdaV_post = LambdaV_post;
    mergedPresynapticUpdateGroup0[idx].g = g;
    mergedPresynapticUpdateGroup0[idx].outPost = outPost;
    mergedPresynapticUpdateGroup0[idx].outPre = outPre;
    mergedPresynapticUpdateGroup0[idx].srcSpk = srcSpk;
    mergedPresynapticUpdateGroup0[idx].srcSpkCnt = srcSpkCnt;
    mergedPresynapticUpdateGroup0[idx].srcSpkCntEvent = srcSpkCntEvent;
    mergedPresynapticUpdateGroup0[idx].srcSpkEvent = srcSpkEvent;
    mergedPresynapticUpdateGroup0[idx].numTrgNeurons = numTrgNeurons;
}
static MergedPresynapticUpdateGroup1 mergedPresynapticUpdateGroup1[1];
void pushMergedPresynapticUpdateGroup1ToDevice(unsigned int idx, float* Gradient, float* LambdaI_post, float* g, float* outPost, uint32_t* srcSpk, uint32_t* srcSpkCnt, uint32_t* srcSpkCntEvent, uint32_t* srcSpkEvent) {
    mergedPresynapticUpdateGroup1[idx].Gradient = Gradient;
    mergedPresynapticUpdateGroup1[idx].LambdaI_post = LambdaI_post;
    mergedPresynapticUpdateGroup1[idx].g = g;
    mergedPresynapticUpdateGroup1[idx].outPost = outPost;
    mergedPresynapticUpdateGroup1[idx].srcSpk = srcSpk;
    mergedPresynapticUpdateGroup1[idx].srcSpkCnt = srcSpkCnt;
    mergedPresynapticUpdateGroup1[idx].srcSpkCntEvent = srcSpkCntEvent;
    mergedPresynapticUpdateGroup1[idx].srcSpkEvent = srcSpkEvent;
}
void updateSynapses(float t) {
    const auto synapseDynamicsStart = std::chrono::high_resolution_clock::now();
    synapseDynamicsTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - synapseDynamicsStart).count();
    const auto presynapticUpdateStart = std::chrono::high_resolution_clock::now();
     {
        // merged presynaptic update group 0
        for(unsigned int g = 0; g < 2; g++) {
            const auto *group = &mergedPresynapticUpdateGroup0[g]; 
            
            // process presynaptic events: Spike type events
            for (unsigned int i = 0; i < group->srcSpkCntEvent[0]; i++) {
                const unsigned int idPre = group->srcSpkEvent[i];
                for (unsigned int ipost = 0; ipost < group->numTrgNeurons; ipost++) {
                    const uint32_t idSyn = ((uint32_t)idPre * group->numTrgNeurons) + ipost;
                    group->Gradient[idSyn] -= (group->LambdaI_post[ipost] * (5.000000000e+00f));
                    group->outPre[idPre] += group->g[idSyn] * (group->LambdaV_post[ipost] - group->LambdaI_post[ipost]);
                }
            }
            // process presynaptic events: True Spikes
            for (unsigned int i = 0; i < group->srcSpkCnt[0]; i++) {
                const unsigned int idPre = group->srcSpk[i];
                for (unsigned int ipost = 0; ipost < group->numTrgNeurons; ipost++) {
                    const uint32_t idSyn = ((uint32_t)idPre * group->numTrgNeurons) + ipost;
                    group->outPost[ipost] += group->g[idSyn];
                }
            }
        }
    }
     {
        // merged presynaptic update group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedPresynapticUpdateGroup1[g]; 
            
            // process presynaptic events: Spike type events
            for (unsigned int i = 0; i < group->srcSpkCntEvent[0]; i++) {
                const unsigned int idPre = group->srcSpkEvent[i];
                for (unsigned int ipost = 0; ipost < (256u); ipost++) {
                    const uint32_t idSyn = ((uint32_t)idPre * (256u)) + ipost;
                    group->Gradient[idSyn] -= (group->LambdaI_post[ipost] * (5.000000000e+00f));
                }
            }
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
