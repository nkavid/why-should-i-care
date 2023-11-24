# What is C Linkage and why should I care?

C and C++ have different binary interfaces. Even when the signature in plaintext in source code looks identical a linker will not be able to find a mismatching definition and declaration if compiled with mismatch of languages.

```cpp
namespace lorem
{
void ipsum();
}

// C-wrapper over C++ to integrate into C (or C++ with old ABI)
extern "C" lorem_ipsum(void)
{
  lorem::ipsum();
}
```

```
# list symbols in binary file
nm build/cpp-lorem-app
# [...]
0000000000401153 T _Z5loremi

# demangle symbol names
nm build/cpp-lorem-app | c++filt
# [...]
0000000000401153 T lorem(int)

# symbols in c binary
nm build/c-lorem-app
# [...]
0000000000401153 T lorem
```

No integer parameter signature in function symbol? May or may not be related to no overloading in C.

## Why 'void' in function paramater signature?

```c
void foo();

void foo()
{
}
```

Compiled with `-Wmissing-prototypes`

```
void.c:3:6: error: no previous prototype for ‘foo’ [-Werror=missing-prototypes]
    3 | void foo()
      |      ^~~
```

Compiled with `-Wstrict-prototypes`

```
void.c:1:1: error: function declaration isn’t a prototype [-Werror=strict-prototypes]
    1 | void foo();
      | ^~~~
void.c:3:6: error: function declaration isn’t a prototype [-Werror=strict-prototypes]
    3 | void foo()
      |      ^~~
```

Required to add `void` in the declaration. What does it mean without `void`? From [cppreference](https://en.cppreference.com/w/c/language/function_declaration): Non-prototype declarator with unspecified number of parameters (unless used in a function definition).

