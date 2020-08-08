Firstly, you need to generate and compile the C++ bindings.
Use this command and substitute <platform> with windows, linux or osx.
(depending on your OS)

```
cd godot-cpp
scons platform=<platform> generate_bindings=yes -j4
cd ..
```

To compile the C dynamic library. Use:
```
scons plaform=<platform>
```
Where platform is the exported platform.

For optimized builds, you should compile both godot-cpp and GDNative library
with `target=release` switch.
