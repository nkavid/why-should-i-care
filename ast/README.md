# What is an Abstract Syntax Tree and why should I care?

Syntactic representation of source code. Nodes are different types of statements in the code. Closer to what a compiler sees than loosy goosy strings. Not only syntactic breakdown of a particular statement node there is also the context of the rest of the tree that can be used in static analysis.

## C++

AST viewer is supported in [compiler-explorer](https://godbolt.org/z/Y74GGKn35) when using clang compiler.

```cpp
bool foobar(const int integer)
{
    return true;
}
```

```
`-FunctionDecl <line:1:1, line:4:1> line:1:6 foobar 'bool (const int)'
  |-ParmVarDecl <col:13, col:23> col:23 integer 'const int'
  `-CompoundStmt <line:2:1, line:4:1>
    `-ReturnStmt <line:3:5, col:12>
      `-CXXBoolLiteralExpr <col:12> 'bool' true
```

or another example

```cpp
class Lorem
{
public:
    void ipsum() const;
};
```

```
`-CXXRecordDecl <line:1:1, line:5:1> line:1:7 class Lorem definition
  |-DefinitionData pass_in_registers empty aggregate standard_layout trivially_copyable pod trivial literal has_constexpr_non_copy_move_ctor can_const_default_init
  | |-DefaultConstructor exists trivial constexpr needs_implicit defaulted_is_constexpr
  | |-CopyConstructor simple trivial has_const_param needs_implicit implicit_has_const_param
  | |-MoveConstructor exists simple trivial needs_implicit
  | |-CopyAssignment simple trivial has_const_param needs_implicit implicit_has_const_param
  | |-MoveAssignment exists simple trivial needs_implicit
  | `-Destructor simple irrelevant trivial needs_implicit
  |-CXXRecordDecl <col:1, col:7> col:7 implicit class Lorem
  |-AccessSpecDecl <line:3:1, col:7> col:1 public
  `-CXXMethodDecl <line:4:5, col:18> col:10 ipsum 'void () const'
```

Clang compiler AST utilities are used when implementing clang-tidy plugins as I do with [gfx-checks](https://github.com/nkavid/gfx-checks). These can also be used as a standalone tool together with LLVM standard tool options arg parsing.

## Python

See usage in `main.py` with inpyt python file `foobar.py`.

```python
class FooBar():
  name = "FooBar"
  def lorem(self, str):
    print(self.name + ": " + str)
```

AST node dump to terminal.

```
Module(
  body=[
    ClassDef(
      name='FooBar',
      bases=[],
      keywords=[],
      body=[
        Assign(
          targets=[Name(id='name', ctx=Store())],
          value=Constant(value='FooBar')
        ),
        FunctionDef(
          name='lorem',
          args=arguments(
            posonlyargs=[],
            args=[arg(arg='self'), arg(arg='str')],
            kwonlyargs=[],
            kw_defaults=[],
            defaults=[]
          ),
          body=[
            Expr(
              value=Call(
                func=Name(id='print', ctx=Load()),
                args=[
                  BinOp(
                    left=BinOp(
                      left=Attribute(
                        value=Name(id='self', ctx=Load()),
                        attr='name',
                        ctx=Load()
                      ),
                      op=Add(),
                      right=Constant(value=': ')
                    ),
                    op=Add(),
                    right=Name(id='str', ctx=Load())
                  )
                ],
                keywords=[]
              )
            )
          ],
          decorator_list=[]
        )
      ],
      decorator_list=[])
  ],
  type_ignores=[]
)
```

