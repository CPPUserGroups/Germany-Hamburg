def very_python_calc(value):
  return value*value+3

def f(oneclass, value):
  print(oneclass)
  print(value)
  oneclass.set(very_python_calc(value))
