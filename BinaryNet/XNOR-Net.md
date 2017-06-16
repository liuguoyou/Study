# XNOR-Net
[XNOR-Net: ImageNet Classification Using Binary Convolutional Neural Networks](https://arxiv.org/pdf/1603.05279.pdf)

## Related Work

### Shallow networks

### Compressing pre-trained deep networks

- Weight decay [cite 17]
- the Hessian of loss function: Optimal Brain Damage [cite 18] and Optimal Brain Surgeon [cite 19]
- ...

### Designing compact layers
Using in Network in Network architecture, GoogLenet and Residual-Net

In Residual-Net, bottleneck structure has benn proposed.

### Quantizing parameters

### Network binarization

- Expectation BackPropagation(EBP) [cite 36]
- Bayesian approach
- BinaryConnect [cite 38]
- BinaryNet [cite 11]

## Binary Convolutional Neural Network

$L$-layer CNN architecture: $ <\mathit{I}, \mathit{W}, * > $

$I = \mathit{I} _ {l(l=1,\dots,L)}$ is the input tensor for the $l^{\mathrm{th}}$ layer of CNN.

## Binary-Weight-Networks

**Result:**
- is smaller ($~32 \times$) than an equivalent network with single-precision weights values.
- in $~ 2\times$ speed up.

## XNOR-Networks

**Result:**
- $~58 \times$ speed up.


