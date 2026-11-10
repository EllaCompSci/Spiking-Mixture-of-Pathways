#include "definitions.h"
struct MergedNeuronInitGroup0
 {
    float* __restrict__ LambdaI;
    float* __restrict__ LambdaV;
    float* __restrict__ Softmax;
    float* __restrict__ V;
    float* __restrict__ VAvg;
    uint8_t* __restrict__ YTrue;
    uint8_t* __restrict__ YTrueBack;
    float* __restrict__ outPostInSyn0;
    
}
;
struct MergedNeuronInitGroup1
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
    int32_t* __restrict__ RingWriteStartOffset;
    int32_t* __restrict__ RingWriteOffset;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingReadEndOffset;
    float* __restrict__ RefracTime;
    float* __restrict__ LambdaV;
    float* __restrict__ LambdaI;
    
}
;
struct MergedNeuronInitGroup2
 {
    uint8_t* __restrict__ BackSpike;
    uint32_t* __restrict__ EndSpike;
    int32_t* __restrict__ RingReadEndOffset;
    int32_t* __restrict__ RingReadOffset;
    int32_t* __restrict__ RingWriteOffset;
    int32_t* __restrict__ RingWriteStartOffset;
    uint32_t* __restrict__ StartSpike;
    uint32_t* __restrict__ spkCntEventSynSpikeEvent0;
    uint32_t* __restrict__ spkCntSynSpike0;
    uint32_t* __restrict__ spkEventSynSpikeEvent0;
    uint32_t* __restrict__ spkSynSpike0;
    
}
;
struct MergedSynapseInitGroup0
 {
    float* __restrict__ Gradient;
    float* __restrict__ g;
    uint32_t numSrcNeurons;
    uint32_t numTrgNeurons;
    uint32_t rowStride;
    float sdg;
    
}
;
struct MergedCustomUpdateInitGroup0
 {
    float* __restrict__ SumExpVal;
    
}
;
struct MergedCustomUpdateInitGroup1
 {
    float* __restrict__ MaxVal;
    
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
void pushMergedNeuronInitGroup0ToDevice(unsigned int idx, float* LambdaI, float* LambdaV, float* Softmax, float* V, float* VAvg, uint8_t* YTrue, uint8_t* YTrueBack, float* outPostInSyn0) {
    mergedNeuronInitGroup0[idx].LambdaI = LambdaI;
    mergedNeuronInitGroup0[idx].LambdaV = LambdaV;
    mergedNeuronInitGroup0[idx].Softmax = Softmax;
    mergedNeuronInitGroup0[idx].V = V;
    mergedNeuronInitGroup0[idx].VAvg = VAvg;
    mergedNeuronInitGroup0[idx].YTrue = YTrue;
    mergedNeuronInitGroup0[idx].YTrueBack = YTrueBack;
    mergedNeuronInitGroup0[idx].outPostInSyn0 = outPostInSyn0;
}
static MergedNeuronInitGroup1 mergedNeuronInitGroup1[1];
void pushMergedNeuronInitGroup1ToDevice(unsigned int idx, float* V, uint32_t* spkSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkCntEventSynSpikeEvent0, float* outPreOutSyn1, float* outPreOutSyn0, float* outPostInSyn1, float* outPostInSyn0, uint8_t* BackSpike, int32_t* RingWriteStartOffset, int32_t* RingWriteOffset, int32_t* RingReadOffset, int32_t* RingReadEndOffset, float* RefracTime, float* LambdaV, float* LambdaI) {
    mergedNeuronInitGroup1[idx].V = V;
    mergedNeuronInitGroup1[idx].spkSynSpike0 = spkSynSpike0;
    mergedNeuronInitGroup1[idx].spkEventSynSpikeEvent0 = spkEventSynSpikeEvent0;
    mergedNeuronInitGroup1[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronInitGroup1[idx].spkCntEventSynSpikeEvent0 = spkCntEventSynSpikeEvent0;
    mergedNeuronInitGroup1[idx].outPreOutSyn1 = outPreOutSyn1;
    mergedNeuronInitGroup1[idx].outPreOutSyn0 = outPreOutSyn0;
    mergedNeuronInitGroup1[idx].outPostInSyn1 = outPostInSyn1;
    mergedNeuronInitGroup1[idx].outPostInSyn0 = outPostInSyn0;
    mergedNeuronInitGroup1[idx].BackSpike = BackSpike;
    mergedNeuronInitGroup1[idx].RingWriteStartOffset = RingWriteStartOffset;
    mergedNeuronInitGroup1[idx].RingWriteOffset = RingWriteOffset;
    mergedNeuronInitGroup1[idx].RingReadOffset = RingReadOffset;
    mergedNeuronInitGroup1[idx].RingReadEndOffset = RingReadEndOffset;
    mergedNeuronInitGroup1[idx].RefracTime = RefracTime;
    mergedNeuronInitGroup1[idx].LambdaV = LambdaV;
    mergedNeuronInitGroup1[idx].LambdaI = LambdaI;
}
static MergedNeuronInitGroup2 mergedNeuronInitGroup2[1];
void pushMergedNeuronInitGroup2ToDevice(unsigned int idx, uint8_t* BackSpike, uint32_t* EndSpike, int32_t* RingReadEndOffset, int32_t* RingReadOffset, int32_t* RingWriteOffset, int32_t* RingWriteStartOffset, uint32_t* StartSpike, uint32_t* spkCntEventSynSpikeEvent0, uint32_t* spkCntSynSpike0, uint32_t* spkEventSynSpikeEvent0, uint32_t* spkSynSpike0) {
    mergedNeuronInitGroup2[idx].BackSpike = BackSpike;
    mergedNeuronInitGroup2[idx].EndSpike = EndSpike;
    mergedNeuronInitGroup2[idx].RingReadEndOffset = RingReadEndOffset;
    mergedNeuronInitGroup2[idx].RingReadOffset = RingReadOffset;
    mergedNeuronInitGroup2[idx].RingWriteOffset = RingWriteOffset;
    mergedNeuronInitGroup2[idx].RingWriteStartOffset = RingWriteStartOffset;
    mergedNeuronInitGroup2[idx].StartSpike = StartSpike;
    mergedNeuronInitGroup2[idx].spkCntEventSynSpikeEvent0 = spkCntEventSynSpikeEvent0;
    mergedNeuronInitGroup2[idx].spkCntSynSpike0 = spkCntSynSpike0;
    mergedNeuronInitGroup2[idx].spkEventSynSpikeEvent0 = spkEventSynSpikeEvent0;
    mergedNeuronInitGroup2[idx].spkSynSpike0 = spkSynSpike0;
}
static MergedSynapseInitGroup0 mergedSynapseInitGroup0[3];
void pushMergedSynapseInitGroup0ToDevice(unsigned int idx, float* Gradient, float* g, uint32_t numSrcNeurons, uint32_t numTrgNeurons, uint32_t rowStride, float sdg) {
    mergedSynapseInitGroup0[idx].Gradient = Gradient;
    mergedSynapseInitGroup0[idx].g = g;
    mergedSynapseInitGroup0[idx].numSrcNeurons = numSrcNeurons;
    mergedSynapseInitGroup0[idx].numTrgNeurons = numTrgNeurons;
    mergedSynapseInitGroup0[idx].rowStride = rowStride;
    mergedSynapseInitGroup0[idx].sdg = sdg;
}
static MergedCustomUpdateInitGroup0 mergedCustomUpdateInitGroup0[1];
void pushMergedCustomUpdateInitGroup0ToDevice(unsigned int idx, float* SumExpVal) {
    mergedCustomUpdateInitGroup0[idx].SumExpVal = SumExpVal;
}
static MergedCustomUpdateInitGroup1 mergedCustomUpdateInitGroup1[1];
void pushMergedCustomUpdateInitGroup1ToDevice(unsigned int idx, float* MaxVal) {
    mergedCustomUpdateInitGroup1[idx].MaxVal = MaxVal;
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
                    group->VAvg[i] = initVal;
                }
            }
             {
                uint8_t initVal;
                initVal = (0.000000000e+00f);
                group->YTrue[0] = initVal;
            }
             {
                uint8_t initVal;
                initVal = (0.000000000e+00f);
                group->YTrueBack[0] = initVal;
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->LambdaV[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->LambdaI[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((34u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->Softmax[i] = initVal;
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
                    int32_t initVal;
                    initVal = (0.000000000e+00f);
                    group->RingWriteOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    int32_t initVal;
                    initVal = (4.990000000e+02f);
                    group->RingReadOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    int32_t initVal;
                    initVal = (4.990000000e+02f);
                    group->RingWriteStartOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    int32_t initVal;
                    initVal = (4.990000000e+02f);
                    group->RingReadEndOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    uint8_t initVal;
                    initVal = (0.000000000e+00f);
                    group->BackSpike[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->LambdaV[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((256u)); i++) {
                    float initVal;
                    initVal = (0.000000000e+00f);
                    group->LambdaI[i] = initVal;
                }
            }
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->spkSynSpike0[i] = 0;
            }
            group->spkCntSynSpike0[0] = 0;
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->spkEventSynSpikeEvent0[i] = 0;
            }
            group->spkCntEventSynSpikeEvent0[0] = 0;
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->outPostInSyn0[i] = 0.000000000e+00f;
            }
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->outPostInSyn1[i] = 0.000000000e+00f;
            }
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->outPreOutSyn0[i] = 0.000000000e+00f;
            }
            for (unsigned int i = 0; i < ((256u)); i++) {
                group->outPreOutSyn1[i] = 0.000000000e+00f;
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
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    int32_t initVal;
                    initVal = (0.000000000e+00f);
                    group->RingWriteOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    int32_t initVal;
                    initVal = (4.990000000e+02f);
                    group->RingReadOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    int32_t initVal;
                    initVal = (4.990000000e+02f);
                    group->RingWriteStartOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    int32_t initVal;
                    initVal = (4.990000000e+02f);
                    group->RingReadEndOffset[i] = initVal;
                }
            }
             {
                for (unsigned int i = 0; i < ((115u)); i++) {
                    uint8_t initVal;
                    initVal = (0.000000000e+00f);
                    group->BackSpike[i] = initVal;
                }
            }
            for (unsigned int i = 0; i < ((115u)); i++) {
                group->spkSynSpike0[i] = 0;
            }
            group->spkCntSynSpike0[0] = 0;
            for (unsigned int i = 0; i < ((115u)); i++) {
                group->spkEventSynSpikeEvent0[i] = 0;
            }
            group->spkCntEventSynSpikeEvent0[0] = 0;
        }
    }
    // ------------------------------------------------------------------------
    // Synapse groups
     {
        // merged synapse init group 0
        for(unsigned int g = 0; g < 3; g++) {
            const auto *group = &mergedSynapseInitGroup0[g]; 
            for(unsigned int i = 0; i < group->numSrcNeurons; i++) {
                 {
                    for (unsigned int j = 0; j < group->numTrgNeurons; j++) {
                        const unsigned int idSyn = (i * group->rowStride) + j;
                        float initVal;
                        initVal = (0.000000000e+00f) + (standardNormalDistribution(hostRNG) * group->sdg);
                        group->g[idSyn] = initVal;
                    }
                }
                 {
                    for (unsigned int j = 0; j < group->numTrgNeurons; j++) {
                        const unsigned int idSyn = (i * group->rowStride) + j;
                        float initVal;
                        initVal = (0.000000000e+00f);
                        group->Gradient[idSyn] = initVal;
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
                float initVal;
                initVal = (0.000000000e+00f);
                group->SumExpVal[0] = initVal;
            }
        }
    }
     {
        // merged custom init group 1
        for(unsigned int g = 0; g < 1; g++) {
            const auto *group = &mergedCustomUpdateInitGroup1[g]; 
             {
                float initVal;
                initVal = (0.000000000e+00f);
                group->MaxVal[0] = initVal;
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
