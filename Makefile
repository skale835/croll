main: textfiles.h
	g++ main.cpp -o croll

test: main testUtils/testutils.h
	g++ test_croll.cpp -o test_croll

textfiles.h: textfiles/help.txt textfiles/version.txt
	xxd -i textfiles/help.txt textfiles/helpTxt.include
	xxd -i textfiles/version.txt textfiles/versionTxt.include
	cat textfiles/helpTxt.include textfiles/versionTxt.include > textfiles.h
	rm textfiles/helpTxt.include
	rm textfiles/versionTxt.include
