# GPT-2 Written in Plain C

<img src="{https://img.shields.io/badge/ChatGPT-74aa9c?style=for-the-badge&logo=openai&logoColor=white}" />




The primary goal of this project was to gain a deeper understanding of how complex systems are built from the ground up. I hope this project can inspire others to realize that they, too, can build anything from scratch. I looked back in my life and realized I have implemented Multithreaded Neural Net in C++ which motivated me to further makes use of that implemenation by me Muheeb Uddin [main.cpp](https://github.com/syedMohib44/Multithread_NeuralNetwork)

## Lessons Learned During Development

1. **Understanding Tensors:** Multi-dimensional arrays and tensors are essentially 1D arrays with strides, which enable efficient row and column access.
2. **Improved C Language Skills:** I learned a lot about C, particularly in the areas of memory management, parallelism, and memory access patterns. This is only my second project in C—the first being a basic password manager.
3. **Mathematics & Backpropagation:** I derived backpropagation for layers such as LayerNorm and Attention mechanisms, greatly improving my mathematical ability.
4. **Virtual Memory with File Mapping:** I explored file mapping as virtual memory because managing activations and parameters in RAM (which can be as large as ~20GB) was challenging.

Building this has been both fun and educational.

## Compiler Optimization Flags

To improve performance, the following compiler flags were used:

- `-O3`: Aggressive optimization
- `-march=native`: CPU-specific optimizations
- `-funroll-loops`: Unroll loops to potentially speed up execution
- `-fopenmp`: Enables OpenMP support for parallel processing

## Helpful Blogs

- [Matrix Multiplication on CPU](https://marek.ai/matrix-multiplication-on-cpu.html)
- [Fast Matrix Multiplication on CPU](https://siboehm.com/articles/22/Fast-MMM-on-CPU)

## References

- [Neural Net Backpropagation](https://medium.com/p/29efae801c81)

## TODO

- Optimize matrix multiplication further.
- Improve the attention mechanism and its backpropagation since it significantly increases training time.
