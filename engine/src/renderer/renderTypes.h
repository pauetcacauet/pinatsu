#pragma once

#include "defines.h"
#include "resources/resourcesTypes.h"

// TEMP
#include "external/glm/glm.hpp"

typedef enum DefaultRenderPasses
{
    RENDER_PASS_FORWARD
} DefaultRenderPasses;

typedef struct RenderMeshData
{
    glm::mat4 model;
    Mesh* mesh;
    Material* material;
} RenderMeshData;

struct LightData
{
    glm::vec3 position;
    glm::vec3 color;
    f32 radius;
    f32 intensity;
};

typedef struct RenderPacket
{
    f32 deltaTime;

    u32 renderMeshDataCount;
    RenderMeshData* meshes;
    u32 lightDataCount;
    LightData* lights;
} RenderPacket;
