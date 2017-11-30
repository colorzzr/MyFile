# ECE244 Lab6

cmake command adding requiring package of basic library
```
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

```