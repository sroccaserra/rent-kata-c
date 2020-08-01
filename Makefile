default: test

test.dat: tests.txt
	sed -n -e 's/^< \(.*\)/\1/pw test.dat'     tests.txt >/dev/null

expected.dat: tests.txt
	sed -n -e 's/^> \(.*\)/\1/pw expected.dat' tests.txt >/dev/null

.PHONY: test
test: rent test.dat expected.dat
	./rent <test.dat >result.dat
	diff expected.dat result.dat

.PHONY: clean
clean:
	rm -f rent *.o *.dat
