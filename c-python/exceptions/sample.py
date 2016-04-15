import sampleexc as ex
import traceback

try:
  ex.f1()
except Exception as e:
  print(type(e))
  print(e)

try:
  ex.f2()
except Exception as e:
  print(type(e))
  print(e)
