#include "definitions.h"
struct MergedNeuronInitGroup0
 {
    float* __restrict__ Bias;
    float* __restrict__ DeltaBias;
    float* __restrict__ E;
    float* __restrict__ V;
    float* __restrict__ outPostInSyn0;
    
}
;
struct MergedNeuronInitGroup1
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
struct MergedNeuronInitGroup2
 {
    uint32_t* __restrict__ EndSpike;
    uint32_t* __restrict__ StartSpike;
    float* __restrict__ ZFilterOutSynWUMPre0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkSynSpike0;
    
}
;
struct MergedSynapseInitGroup0
 {
    float* __restrict__ DeltaG;
    float* __restrict__ g;
    
}
;
struct MergedSynapseInitGroup1
 {
    float* __restrict__ DeltaG;
    float* __restrict__ eFiltered;
    float* __restrict__ g;
    uint32_t numSrcNeurons;
    float sdg;
    
}
;
struct MergedCustomUpdateInitGroup0
 {
    float* __restrict__ M;
    float* __restrict__ V;
    
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
static MergedNeuronInitGroup0 mergedNeuronInitGroup0[1];
void pushMergedNeuronInitGroup0ToDevice(unsigned int idx, float* Bias, float* DeltaBias, float* E, float* V, float* outPostInSyn0) {
    mergedNeuronInitGroup0[idx].Bias = Bias;
    mergedNeuronInitGroup0[idx].DeltaBias = DeltaBias;
    mergedNeuronInitGroup0[idx].E = E;
    mergedNeuronInitGroup0[idx].V = V;
    mergedNeuronInitGroup0[idx].outPostInSyn0 = outPostInSyn0;
}
static MergedNeuronInitGroup1 mergedNeuronInitGroup1[1];
void pushMergedNeuronInitGroup1ToDevice(unsigned int idx, float* E, float* FAvgInSynWUMPost0, float* FAvgInSynWUMPost1, float* PsiInSynWUMPost0, float* PsiInSynWUMPost1, float* RefracTime, float* V, float* ZFilterOutSynWUMPre0, float* ZFilterOutSynWUMPre1, float* outPostInSyn0, float* outPreOutSyn0, uint32_t* spkCntSynSpike0, uint32_t* spkSynSpike0) {
    mergedNeuronInitGroup1[idx].E = E;
    mergedNeuronInitGroup1[idx].FAvgInSynWUMPost0 = FAvgInSynWUMPost0;
    mergedNeuronInitGroup1[idx].FAvgInSynWUMPost1 = FAvgInSynWUMPost1;
    mergedNeuronInitGroup1[idx].PsiInSynWUMPost0 = PsiInSynWUMPost0;
    mergedNeuronInitGroup1[idx].PsiInSynWUMPost1 = PsiInSynWUMPost1;
    mergedNeuronInitGroup1[idx].RefracTime = RefracTime;
    mergedNeuronInitGroup1[idx].V = V;
    mergedNeuronInitGroup1[idx].ZFilterOutSynWUMPre0 = ZFilterOutSynWUMPre0;
    mergedNeuronInitGroup1[idx].ZFilterOutSynWUMPre1 = ZFilterOutSynWUMPre1;
    mergedNeuronInitGroup1[idx].outPostInSyn0 = outPostInSyn0;
    mergedNeuronInitGroup1[idx].outPreOutSyn0 = outPreOutSyn0;
    mergedNeuronInitGroup1[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronInitGroup1[idx].spkSynSpike0 = spkSynSpike0;
}
static MergedNeuronInitGroup2 mergedNeuronInitGroup2[1];
void pushMergedNeuronInitGroup2ToDevice(unsigned int idx, uint32_t* EndSpike, uint32_t* StartSpike, float* ZFilterOutSynWUMPre0, uint32_t* spkCntSynSpike0, uint32_t* spkSynSpike0) {
    mergedNeuronInitGroup2[idx].EndSpike = EndSpike;
    mergedNeuronInitGroup2[idx].StartSpike = StartSpike;
    mergedNeuronInitGroup2[idx].ZFilterOutSynWUMPre0 = ZFilterOutSynWUMPre0;
    mergedNeuronInitGroup2[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronInitGroup2[idx].spkSynSpike0 = spkSynSpike0;
}
static MergedSynapseInitGroup0 mergedSynapseInitGroup0[1];
void pushMergedSynapseInitGroup0ToDevice(unsigned int idx, float* DeltaG, float* g) {
    mergedSynapseInitGroup0[idx].DeltaG = DeltaG;
    mergedSynapseInitGroup0[idx].g = g;
}
static MergedSynapseInitGroup1 mergedSynapseInitGroup1[2];
void pushMergedSynapseInitGroup1ToDevice(unsigned int idx, float* DeltaG, float* eFiltered, float* g, uint32_t numSrcNeurons, float sdg) {
    mergedSynapseInitGroup1[idx].DeltaG = DeltaG;
    mergedSynapseInitGroup1[idx].eFiltered = eFiltered;
    mergedSynapseInitGroup1[idx].g = g;
    mergedSynapseInitGroup1[idx].numSrcNeurons = numSrcNeurons;
    mergedSynapseInitGroup1[idx].sdg = sdg;
}
static MergedCustomUpdateInitGroup0 mergedCustomUpdateInitGroup0[1];
void pushMergedCustomUpdateInitGroup0ToDevice(unsigned int idx, float* M, float* V) {
    mergedCustomUpdateInitGroup0[idx].M = M;
    mergedCustomUpdateInitGroup0[idx].V = V;
}
static MergedCustomWUUpdateInitGroup0 mergedCustomWUUpdateInitGroup0[3];
void pushMergedCustomWUUpdateInitGroup0ToDevice(unsigned int idx, float* M, float* V, uint32_t numSrcNeurons, uint32_t numTrgNeurons, uint32_t rowStride) {
    mergedCustomWUUpdateInitGroup0[idx].M = M;
    mergedCustomWUUpdateInitGroup0[idx].V = V;
    mergedCustomWUUpdateInitGroup0[idx].numSrcNeurons = numSrcNeurons;
    mergedCustomWUUpdateInitGroup0[idx].numTrgNeurons = numTrgNeurons;
    mergedCustomWUUpdateInitGroup0[idx].rowStride = rowStride;
}
void initializeHost() {
}
void initialize() {
    const auto initStart = std::chrono::high_resolution_clock::now();
    // ------------------------------------------------------------------------
    // Neuron groups
     {
        // merged neuron init group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronInitGroup0[g]; 
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->V[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->E[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->Bias[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->DeltaBias[i] = initVal;
                }
            }
            for (unsigned int i = 0; i < ((34u)); i++) {
                group->outPostInSyn0[i] = 0.000000000e+00f;
            }
        }
    }
     {
        // merged neuron init group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronInitGroup1[g]; 
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->V[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->RefracTime[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->E[i] = initVal;
                }
            }
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->spkSynSpike0[i] = 0;
            }
            group->spkCntSynSpike0[0] = 0;
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->outPostInSyn0[i] = 0.000000000e+00f;
            }
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->outPreOutSyn0[i] = 0.000000000e+00f;
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->ZFilterOutSynWUMPre0[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->ZFilterOutSynWUMPre1[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->PsiInSynWUMPost0[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->FAvgInSynWUMPost0[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->PsiInSynWUMPost1[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->FAvgInSynWUMPost1[i] = initVal;
                }
            }
        }
    }
     {
        // merged neuron init group 2
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedNeuronInitGroup2[g]; 
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    uint32_t initVal;
                    initVal = (0.000000000e+00f);
                    group->StartSpike[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    uint32_t initVal;
                    initVal = (0.000000000e+00f);
                    group->EndSpike[i] = initVal;
                }
            }
            for (unsigned int i = 0; i < ((115u)); i++) {
                group->spkSynSpike0[i] = 0;
            }
            group->spkCntSynSpike0[0] = 0;
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->ZFilterOutSynWUMPre0[i] = initVal;
                }
            }
        }
    }
    // ------------------------------------------------------------------------
    // Synapse groups
     {
        // merged synapse init group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedSynapseInitGroup0[g]; 
            for(unsigned int i = 0; i < (256u); i++) {
                 {
                    for (unsigned int j = 0; j < (34u); j++) {
                        const unsigned int idSyn = (i * (34u)) + j;
                        float initVal;
                        initVal = (0.000000000e+00f) + (standardNormalDistribution(hostRNG) * (6.250000000e-02f));
                        group->g[idSyn] = initVal;
                    }
                }
                 {
                    for (unsigned int j = 0; j < (34u); j++) {
                        const unsigned int idSyn = (i * (34u)) + j;
                        float initVal;
                        initVal = (0.000000000e+00f);
                        group->DeltaG[idSyn] = initVal;
                    }
                }
            }
        }
    }
     {
        // merged synapse init group 1
        for(unsigned int g = 0; g < 2; g++) {
            const auto *group = &mergedSynapseInitGroup1[g]; 
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    for (unsigned int j = 0; j < (256u); j++) {
                        const unsigned int idSyn = (i * (256u)) + j;
                        float initVal;
                        initVal = (0.000000000e+00f) + (standardNormalDistribution(hostRNG) * group->sdg);
                        group->g[idSyn] = initVal;
                    }
                }
                 {
                    for (unsigned int j = 0; j < (256u); j++) {
                        const unsigned int idSyn = (i * (256u)) + j;
                        float initVal;
                        initVal = (0.000000000e+00f);
                        group->eFiltered[idSyn] = initVal;
                    }
                }
                 {
                    for (unsigned int j = 0; j < (256u); j++) {
                        const unsigned int idSyn = (i * (256u)) + j;
                        float initVal;
                        initVal = (0.000000000e+00f);
                        group->DeltaG[idSyn] = initVal;
                    }
                }
            }
        }
    }
    // ------------------------------------------------------------------------
    // Custom update groups
     {
        // merged custom init group 0
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateInitGroup0[g]; 
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->M[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->V[i] = initVal;
                }
            }
        }
    }
    // ------------------------------------------------------------------------
    // Custom connectivity presynaptic update groups
    // ------------------------------------------------------------------------
    // Custom connectivity postsynaptic update groups
    // ------------------------------------------------------------------------
    // Custom WU update groups
     {
        // merged custom WU update group 0
        for(unsigned int g = 0; g < 3; g++) {
            const auto *group = &mergedCustomWUUpdateInitGroup0[g]; 
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    for (unsigned int j = 0; j < group->numTrgNeurons; j++) {
                        const unsigned int idSyn = (i * group->rowStride) + j;
                        float initVal;
                        initVal = (0.000000000e+00f);
                        group->M[idSyn] = initVal;
                    }
                }
                 {
                    for (unsigned int j = 0; j < group->numTrgNeurons; j++) {
                        const unsigned int idSyn = (i * group->rowStride) + j;
                        float initVal;
                        initVal = (0.000000000e+00f);
                        group->V[idSyn] = initVal;
                    }
                }
            }
        }
    }
    // ------------------------------------------------------------------------
    // Synapse sparse connectivity
    initTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - initStart).count();
}

void initializeSparse() {
    const auto initSparseStart = std::chrono::high_resolution_clock::now();
    // ------------------------------------------------------------------------
    // Synapse groups with sparse connectivity
    // ------------------------------------------------------------------------
    // Custom sparse WU update groups
    // ------------------------------------------------------------------------
    // Custom connectivity update sparse init groups
    initSparseTime += std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - initSparseStart).count();
}
