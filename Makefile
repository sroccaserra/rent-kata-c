test: rent tests.txt
	sed -n -e 's/^< \(.*\)/\1/pw test.dat'     tests.txt >/dev/null
	sed -n -e 's/^> \(.*\)/\1/pw expected.dat' tests.txt >/dev/null
	./rent <test.dat >result.dat
	diff expected.dat result.dat

rent: rent.o
rent.o: rent.c

.PHONY: clean
clean:
	rm rent *.dat
