array2d
=======

Simple, one-header static and dynamic 2D arrays in C++.  Public domain licensed.


`StaticArray2D` has fixed size at compile-time,
`Array2D` has fixed size at construction.


Memory is stored in a contiguous block.
`begin()` and `end()` return pointers, which work as iterators for `std::algorithm`.

`Operator()` is used for 2D indexing.
`Oprerator[]` is used for 1D indexing.
Arrays are row-major: `arr(3, 1)` and `arr(3, 2)` are consecutive in memory.


Please message me with feature requests or comments!
