CFLAGS = -Wall -Wextra -Wpedantic

default: test

test.dat: tests.txt
	sed -n -e 's/^< \(.*\)/\1/pw test.dat'     tests.txt >/dev/null

expected.dat: tests.txt
	sed -n -e 's/^> \(.*\)/\1/pw expected.dat' tests.txt >/dev/null

.PHONY: test
test: rent test.dat expected.dat
	./rent <test.dat >result.dat
	git diff --no-index expected.dat result.dat

debug: CFLAGS += -DDEBUG -g
debug: rent test.dat expected.dat
	@echo "To debug on macOs, use:"
	@echo "$$ lldb rent"
	@echo "(lldb) b main"
	@echo "(lldb) process launch -i test.dat"
	@echo "(lldb) run"

.PHONY: clean
clean:
	rm -f rent *.o *.dat
