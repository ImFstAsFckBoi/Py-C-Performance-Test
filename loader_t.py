import ctypes
bench = ctypes.cdll.LoadLibrary("./bench.so")
bench.run_threaded();
