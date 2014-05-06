BINPATH=/usr/bin
all:
	${CXX} -o nulocks-simple-cli nulocks-simple-cli.cpp -lnulockscore
debug:
	${CXX} -o nulocks-simple-cli nulocks-simple-cli.cpp -lnulockscore -g
install:
	cp nulocks-simple-cli ${BINPATH}
clean:
	rm -rf nulocks-simple-cli
