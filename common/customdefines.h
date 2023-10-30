#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using f32 = float;
using f64 = double;


// Constants default settings
enum class RenderAPI
{
    GL,
    VK
};

enum Platform
{
    Win32,
    Linux
};

const auto RenderAPIToString = [](RenderAPI api) -> std::string {
    if(api == RenderAPI::GL)
        return "OpenGL";
    else if(api == RenderAPI::VK)
        return "Vulkan";
};

enum MeshType
{
    TYPE_2D,
    TYPE_3D,
    NON_RENDERABLE
};

enum ShaderType
{
    VERTEX,
    FRAGMENT,
    COMPUTE,
    GEOMETRY,
    TESSELATION
};

typedef struct 
{
    unsigned int shader_program{0};
    std::vector<std::pair<ShaderType, std::string>> shader_data_type_and_source{0};
}ShaderData;


const auto ShaderTypesToString = [](ShaderType type) -> std::string {
    if(type == ShaderType::VERTEX)
        return "Vertex";
    else if(type == ShaderType::FRAGMENT)
        return "Fragment";
};

enum PrimitiveType
{
    Triangle,
    Point,
    Square,
    Circle,
    Line,
    Curve,
    Cube,
    Sphere,
    Cone
};

#ifdef _WIN32
    const Platform CURRENT_PLATFORM = Platform::Win32;
#elif _LINUX
    const Platform CURRENT_PLATFORM = Platform::Linux;
#endif

const std::string DEFAULT_API = RenderAPIToString(RenderAPI::GL) ;

