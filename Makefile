main: textfiles.h
	g++ main.cpp -o croll

textfiles.h: textfiles/help.txt textfiles/version.txt
	xxd -i textfiles/help.txt textfiles/helpTxt.include
	xxd -i textfiles/version.txt textfiles/versionTxt.include
	cat textfiles/helpTxt.include textfiles/versionTxt.include > textfiles.h
	rm textfiles/helpTxt.include
	rm textfiles/versionTxt.include
