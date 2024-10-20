make -j
export LD_LIBRARY_PATH=.
echo -e "Pure C"
time ./main
echo -e "Loaded from Python"
time python3 loader.py
echo -e "Pure C threaded"
time ./main_t
echo -e "Loaded from Python threaded"
time python3 loader_t.py
echo -e "Threding and Loaded in Pyton"
time python3 loader_pyt.py
