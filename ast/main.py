import ast
import astpretty

def main():

  with open("foobar.py", "r", encoding="utf-8") as foobar_file:
    node = ast.parse(foobar_file.read())
    print(ast.dump(node))
    print("============")
    astpretty.pprint(node)

  print("============")
  node = ast.parse("import numpy")
  print(ast.dump(node))
  astpretty.pprint(node)

if __name__ == "__main__":
  main()
