# What is Fuzz Testing and why should I care?

Generate input to some interface to force unexpected behaviour to check for crashes or security vulnerabilities. Used with Sanitizers which instruments compiled code whicxh can check for undefined behaviour or memory leaks.

Recommended usage at external interfaces or trust boundaries where some input can not be trusted.

## Isn't this just random input testing?

This is more systematic. Just generating random inputs for unit tests is terrible. Almost all test cases are in the same equivalence class and you will trigger edge cases almost never due to the nature of random distribution. Fuzzing frameworks are smarter about how input data is generated.

## How to use?

From [libFuzzer docs](https://llvm.org/docs/LibFuzzer.html):

* Implement a "Fuzz target" taking some data and uses that data.
* `-fsanitize=fuzzer` flag to link fuzzer driver.
* You did it! :D

Also use with sanitizers.

## Moar

* [C++ Weekly - Not Doing This Should Be Illegal!](https://www.youtube.com/watch?v=Is1MurHeZvg)
