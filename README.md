# Postie

A message-based communication environment

## Prerequisites

- C++ compiler with `C++20` support
- CMake
- [ext](https://github.com/isnullxbh/ext) (version >= 0.1.0)
- GTest (for unit tests only)

## Build

To build library, go to the project's root directory and execute the following
commands:

```shell
# Prepare the build system
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DCMAKE_CXX_FLAGS="-std=c++20" \
      -S . -B build/debug

# Build
cmake --build build/debug
```

### Options

|         Name         |              Description               | Since | Default |
|:--------------------:|:--------------------------------------:|:-----:|:-------:|
| `POSTIE_BUILD_TESTS` | Generates build targets for unit tests | 0.1.0 |   OFF   |

## Installation

Go to the project's root directory, build the library and then execute the following
command:

```shell
cmake --install build/debug
```

## Documentation

To generate a documentation, go to the project's root directory and execute the
following command:

```shell
doxygen docs/Doxyfile
```

The generated documentation will be placed in the [following](docs/out) directory.

## Author

Oleg E. Vorobiov <isnullxbh@gmail.com>
