# SSO-Check

Simple C++ program to compare address and size of `std::string` instance and the `c_str()` pointer
to see what is the maximum length of SSO (short string optimization - storing the data inside the
`std::string` instance itself if its very small, to avoid using a dynamic allocation).

An instance of `std::string` commonly has a pointer to the string data, and a couple of
integers (size and capacity), which adds up to 24 bytes on a 64-bit architecture. SSO takes
advantage of the fact that many strings in common programs are small, and stores them inside
those bytes themselves, instead of allocating memory on the heap. This also helps avoid a cache
miss, but all this at the cost of some extra complexity (having to figure out and store flag to
mark short vs. normal string).


# Extra reading about SSO:

* [(video) CppCon 2016: Nicholas Ormrod - The strange details of std::string at Facebook](https://www.youtube.com/watch?v=kPR8h4-qZdk)
* [SSO-23 - proof of concept string that uses all bytes for SSO](https://github.com/elliotgoodrich/SSO-23)
* [Meaning of acronym SSO in the context of std::string](https://stackoverflow.com/questions/10315041/meaning-of-acronym-sso-in-the-context-of-stdstring)
* [How to Measure String SSO Length with constinit and constexpr](https://www.cppstories.com/2022/sso-cpp20-checks/)


# Example outputs:
* 64-bit `g++ 13` and `MSVC 19`:
```
sizeof(std::string) = 32
sizeof(void*) = 8
max SSO = 15
```

* 32-bit `g++ 13` and `MSVC 19`:
```
sizeof(std::string) = 24
sizeof(void*) = 4
max SSO = 15
```

* 64-bit executable created by with `zig c++`:
```
sizeof(std::string) = 24
sizeof(void*) = 8
max SSO = 22
```
