# Changelog 
## MathLib v0.0.3

**Release Date**: March 13th, 2025  
**Version**: 0.0.3

MathLib has been successfully ported from JavaScript to C, marking a major milestone in the library's evolution. This version includes significant performance improvements, a more flexible structure, and a shift toward a function-oriented approach. The port required a complete rewrite of the original project, which resulted in a refactor of many parts of the codebase. The library is now fully intended for use as a shared library.

---

## Key Changes:
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