# Description

a small little library for my little lua project, and simultaneously learn some C(and math). proof of concept !!
Do not use this in production, this is just an expirement im working on. I cannot guarantee the C will be good, but,
alas: enjoy :)

I should also say: this *is* a learning project, and the library will be unusable, until hopefully, 0.1.X. 
That's the plan at least; I don't plan to just throw out code. 
-- t_aggelos

---
## Rewriting from JS to C
Ported from JavaScript to C, this version includes significant performance improvements (duh). The port required a complete rewrite of the original project, which resulted in a refactor of many parts of the codebase. The library will be fully intended for use as a shared library. As part of a larger project I'm working on

### Shared Library Focus(?):
- The library is to be designed as a shared library, if I can like... attempt that lol
- But there's also an additional `tests.c` that will attempt various computations, and see if the library can actually work
---
## Missing Features & In-Progress Work

Here are a couple things I plan on implementing, but either haven't learned yet, or just haven't reached that point

| **Feature**                            | **Status**               | **Description** |
|----------------------------------------|--------------------------|-----------------|
| **Unknown Row/Col Matrices**           | Not Implemented          | Support for matrices with unknown rows or columns and their respective operations is still to be added. |
| **Voronoi Structure & Noise Patterns** | Not Implemented          | Structures like Voronoi diagrams, Perlin noise, and other noise patterns are still under development. |
| **Matrix 3x3 Support**                 | Not Implemented          | Only 4x4 matrices (`M4x4f`) are supported at the moment. 3x3 matrices will be added in a future release. |
| **Angle Handling**                     | In Progress              | Angles will only be specified as degrees or radians, with a suffix indicating the unit (e.g., `deg` or `rad`). |

---

There kind of won't be a milestone; but that's okay. I just add things as I see necessary. I will, though, eventually write a goal plan to reach a couple as this library grows.