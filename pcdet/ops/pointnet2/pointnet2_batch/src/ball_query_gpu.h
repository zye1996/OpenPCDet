#ifndef _BALL_QUERY_GPU_H
#define _BALL_QUERY_GPU_H

#include <THC/THC.h>
#include <cuda.h>
#include <cuda_runtime_api.h>
#include <torch/extension.h>
#include <torch/serialize/tensor.h>

#include <vector>

extern THCState *state;

int ball_query_wrapper_fast(int b, int n, int m, float min_radius, float max_radius, int nsample,
                       at::Tensor new_xyz_tensor, at::Tensor xyz_tensor,
                       at::Tensor idx_tensor);

void ball_query_kernel_launcher_fast(int b, int n, int m, float min_radius, float max_radius,
                                int nsample, const float *xyz, const float *new_xyz,
                                int *idx, cudaStream_t stream);

#endif
