#include "logger.h"

// Create a logger for IO
const std::shared_ptr<spdlog::logger> mpm::Logger::io_logger =
    spdlog::stdout_color_st("IO");

// Create a logger for reading mesh
const std::shared_ptr<spdlog::logger> mpm::Logger::read_mesh =
    spdlog::stdout_color_st("ReadMesh");

// Create a logger for reading ascii mesh
const std::shared_ptr<spdlog::logger> mpm::Logger::read_mesh_ascii =
    spdlog::stdout_color_st("ReadMeshAscii");

// Create a logger for MPM
const std::shared_ptr<spdlog::logger> mpm::Logger::mpm_logger =
    spdlog::stdout_color_st("MPM");

// Create a logger for MPM Explicit
const std::shared_ptr<spdlog::logger> mpm::Logger::mpm_explicit_logger =
    spdlog::stdout_color_st("MPMExplicit");