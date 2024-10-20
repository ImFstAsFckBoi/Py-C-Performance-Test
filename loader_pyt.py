import ctypes
import threading
bench = ctypes.cdll.LoadLibrary("./bench.so")
ts = [threading.Thread(target=bench.run_test) for _ in range(8)]
for t in ts:
    t.start()
for t in ts:
    t.join()
