//
// Created by victor on 17.06.2022.
//

#ifndef GPU_DETECT_GPU_DETECT_H
#define GPU_DETECT_GPU_DETECT_H

#include <vector>
#include <string>

enum class Vendor{
    NVIDIA,
    AMD,
    INTEL,
    UNKNOWN
};

class GPU{
public:
    std::string name;
    Vendor vendor;
};

std::vector<GPU> get_gpu_list();

#endif //GPU_DETECT_GPU_DETECT_H
