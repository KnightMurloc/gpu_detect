#include "gpu_detect.h"
#include <vulkan/vulkan.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<GPU> get_gpu_list(){
        vk::ApplicationInfo AppInfo{
            "gpuDetect",      // Application Name
            1,                    // Application Version
            nullptr,              // Engine Name or nullptr
            0,                    // Engine Version
            VK_API_VERSION_1_0    // Vulkan API version
    };

    vk::InstanceCreateInfo InstanceCreateInfo(vk::InstanceCreateFlags(), // Flags
                                              &AppInfo,                  // Application Info
                                              0,             // Layers count
                                              nullptr);            // Layers

    vk::Instance instance = vk::createInstance(InstanceCreateInfo);

    auto devices = instance.enumeratePhysicalDevices();

    vector<GPU> result;

    for(auto device : devices){
        auto prop = device.getProperties();
        string name = prop.deviceName.data();
        GPU gpu;
        gpu.name = name;

        switch (prop.vendorID) {
            case 0x10DE:
                gpu.vendor = Vendor::NVIDIA;
                break;
            case 0x1002:
                gpu.vendor = Vendor::AMD;
                break;
            case 0x8086:
                gpu.vendor = Vendor::INTEL;
                break;
            default:
                gpu.vendor = Vendor::UNKNOWN;
        }
        result.push_back(gpu);
    }

    instance.destroy();

    return std::move(result);
}