import python_output.foobar_pb2 as foobar

def main():
  baz = foobar.Baz()
  
  baz.someInteger = 64
  baz.someString = "wawaweewa"
  
  string_buffer = baz.SerializeToString()
  
  print(string_buffer.decode("ascii"))

if __name__ == "__main__":
  main()
