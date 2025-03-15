# Description

a small little library for my little lua project, and simultaneously learn some C(and math). proof of concept !!
Do not use this in production, this is just an expirement im working on. I cannot guarantee the C will be good, but,
alas: enjoy :)
-- t_aggelos

# Changelog 
## MathLib v0.0.3

**Release Date**: March 13th, 2025  
**Version**: 0.0.3

MathLib has been successfully ported from JavaScript to C, marking a major milestone in the library's evolution. This version includes significant performance improvements, a more flexible structure, and a shift toward a function-oriented approach. The port required a complete rewrite of the original project, which resulted in a refactor of many parts of the codebase. The library is now fully intended for use as a shared library.

---

## Key Changes:

### Design Considerations:
- **Ported to C**: The entire library has been rewritten in C for better hardware control.
- **Faster Computations**: Expect significant performance gains, especially in complex mathematical operations.
- **Memory Management**: The C-based implementation allows for greater flexibility in memory management.
- **More Room for Optimizations**: Since we're not bound by JS shenanigans.
- **No longer bound by the web:** The code is now 

### Shared Library Focus(?):
- The library is to be designed as a shared library, if I can like... attempt that lol
- But there's also an additional `tests.c` that will attempt various computations, and see if the library can actually work
---

## Missing Features & In-Progress Work

| **Feature**                            | **Status**               | **Description** |
|----------------------------------------|--------------------------|-----------------|
| **Unknown Row/Col Matrices**           | Not Implemented          | Support for matrices with unknown rows or columns and their respective operations is still to be added. |
| **Voronoi Structure & Noise Patterns** | Not Implemented          | Structures like Voronoi diagrams, Perlin noise, and other noise patterns are still under development. |
| **Matrix 3x3 Support**                 | Not Implemented          | Only 4x4 matrices (`M4x4f`) are supported at the moment. 3x3 matrices will be added in a future release. |
| **Angle Handling**                     | In Progress              | Angles will only be specified as degrees or radians, with a suffix indicating the unit (e.g., `deg` or `rad`). |

---

## API Changes:

### Updated Object Naming:
- `Vector3D` → `Vec3<data_type>` (i.e `Vec3f`)
- `Vector2D` → *(not implemented yet)*
- `Mat4x4` → `M4x4<data_type>`
- `Mat3x3` → *(not implemented yet)*
- `Angle` → *(Specified as degrees or radians with a suffix)*

### Example of Function Naming:
- `vec3f_mult_scalars(Vec2f *v, float k)` instead of more generic function names.
---

This release focuses on performance, functionality, and maintainability improvements. The transition to C provides better memory management and opens up new optimization opportunities. We are continuing to work on implementing the missing features in upcoming releases. Stay tuned for more updates!

## MathLib v0.0.4

**Release Date**: March 15th, 2025  
**Version**: 0.0.4

This version of mathlib has had a series of refinements, first and foremost with a focus on preparing for better tools like make and doxygen. Nothing else has changed, this is a minor update.