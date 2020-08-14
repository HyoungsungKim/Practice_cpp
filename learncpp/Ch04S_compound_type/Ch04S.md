# Ch04S Compound Types

## S4.5a Enum classes

C++11 defines a new concept, the **enum class** (also called a **scoped enumeration**), which makes enumerations both strongly typed and strongly scoped. To make an enum class, we use the keyword **class** after the enum keyword. 

- The strong typing rules means that each enum class is considered a unique type.  **This means that the compiler will *not* implicitly compare enumerators from different enumerations**. If you try to do so, the compiler will throw an error.
- Although enum classes use the class keyword, they aren’t considered “classes” in the traditional C++ sense.

