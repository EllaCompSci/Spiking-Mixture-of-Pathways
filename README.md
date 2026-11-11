# Spiking-Mixture-of-Pathways
Masters of research project at the university of Sussex with supervision from Dr Jamie Knight. The goal of this research project is implement Heterogeneous Mixture of expert (HMoE) along with the inductive biases stated in Cook et al. (2026, DOI: 10.52202/085713-2800) to produce brain like processing pathways. This implementation uses GeNN library along with MlGeNN as EventProp implementation will be used for training said model. Any information surronding this project you can contact me at me email: Cb792@sussec.ac.uk  


## Installation
1. Pull library
2. Run the following commands:
    - sudo apt update
    - sudo apt install -y libffi-dev
    - sudo apt install -y build-essential
    - curl -LsSf https://astral.sh/uv/install.sh | sh
    - uv python install 3.11
    - rm -rf genn
    - git clone https://github.com/genn-team/genn
    - uv sync --python 3.11
