#pragma once

#include "defines.h"
#include "vulkan\vulkan.h"
#include <string>

struct VertexDeclaration
{
    u32 size = 0;
    const VkVertexInputAttributeDescription* layout = nullptr;
    std::string name;
    
    VertexDeclaration(const char* name, const VkVertexInputAttributeDescription* newLayout, u32 size);
};

const VertexDeclaration*
getVertexDeclarationByName(const std::string& name);