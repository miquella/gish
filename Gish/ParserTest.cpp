#include <iostream>
#include "Parser.h"

using namespace std;

int main(int argc, char* argv[]) {
	Gish::Parser parser("config2.txt");
	parser.Load();
	cout << "soundvolume:" << parser.GetString("soundvolume") << endl;
	cout << "depthbits:" << parser.GetInt("depthbits") << endl;
	parser.SetInt("soundvolume", 100);
	parser.SetString("depthbits", "24");
	parser.Save();
}
