# What is Mutation Testing and why should I care?

Injecting errors in source code and see which errors do not trigger failure in automated tests. The injected error is a "Mutant" and Mutants are "Killed" if triggering errors in automated tests or "Alive" if all tests pass. 

A constexpr [color class](https://github.com/nkavid/sandbox-gfx/blob/main/gfx/vocabulary/color.hpp) is something I have 100% killed mutants by my [unit test](https://github.com/nkavid/sandbox-gfx/blob/main/gfx/test/color_test.cpp). This will be used as an example use case.

## Code examples or Mutants

Replace binary operator

```diff
constexpr float add(float srcColor, float srcAlpha, float dstColor)
{
-  return srcColor * srcAlpha + dstColor * (1.0F - srcAlpha);
+  return srcColor * srcAlpha - dstColor * (1.0F - srcAlpha);
}
```

Replacing a boolean expression with a constant

```diff
-      return redEqual && blueEqual && greenEqual && alphaEqual;
+      return true;
```

Removing statements

```diff
    constexpr bool operator==(const float& other) const
    {
-      return (_data <= other + epsilon) && (_data >= other - epsilon);
    } 
```

After a mutation is applied to source code, the software under test is compiled including the error. Automated tests are run and results are stored with the mutation. Then we do it over again with a different mutation.

## When to stop refactoring?

I like to think of refactoring as "local minima" sort of, where further improvement would mean rethinking more fundamentally what the code is supposed to be doing.

```cpp
constexpr float add(float srcColor, float srcAlpha, float dstColor)
{
  return srcColor * srcAlpha + dstColor * (1.0F - srcAlpha);
}

constexpr Color operator+(const Color& dst, const Color& src)
{
  const float red   = add(src.red(), src.alpha(), dst.red());
  const float green = add(src.green(), src.alpha(), dst.green());
  const float blue  = add(src.blue(), src.alpha(), dst.blue());
  const float alpha = src.alpha() + dst.alpha() * (1.0F - src.alpha());

  return Color{red, green, blue, alpha};
}
```

By extracting this blending operation into a function that is reused there are fewer sources of mutants.

100% coverage is not the end goal. I used this to diagnose both the test and the implementation as insufficient. I could have implemented a much more complicated suite of tests to cover each channel separately but then I would have more sources of bugs in both the implementation and the test.

*"Your code would be faster if you inline the extracted function."*

Inline does not mean faster. In fact, inline does not mean anything.

## What analysis can you do with mutant database?

Idk, lots of cool stuff I guess. :) 
