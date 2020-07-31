test: rent tests.txt
	sed -n -e 's/\(< \)\(.*\)/\2/pw test.dat'     tests.txt >/dev/null
	sed -n -e 's/\(> \)\(.*\)/\2/pw expected.dat' tests.txt >/dev/null
	./rent <test.dat >result.dat
	diff expected.dat result.dat

rent: rent.o
rent.o: rent.c
