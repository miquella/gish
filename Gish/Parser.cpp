#include "Parser.h"

#include <fstream>
#include <sstream>

using namespace Gish;
using namespace std;

Parser::Parser(const std::string& filename)
	: mFilename(filename)
{
}

Parser::~Parser()
{
}

void Parser::Load()
{
	fstream filestream(mFilename, ios_base::in);
	if (filestream.fail())
		return;

	string line;
	mValues.clear();
	while (filestream.good()) {
		getline(filestream, line);

		size_t pos = line.find("=");
		if (pos != string::npos && pos > 0)
			mValues[line.substr(0, pos)] = line.substr(pos+1);
	}
}

void Parser::Save()
{
	fstream filestream(mFilename, ios_base::out);
	if (filestream.fail())
		return;

	for (auto const& value : mValues) {
		filestream << value.first << "=" << value.second << endl;
	}
}

void Parser::Clear()
{
	mValues.clear();
}

string Parser::GetString(const string& key) const
{
	return mValues.count(key) ? mValues.at(key) : string();
}

void Parser::SetString(const string& key, const string& value)
{
	mValues[key] = value;
}

int Parser::GetInt(const string& key) const
{
	int result;
	return (stringstream(GetString(key)) >> result) ? result : 0;
}

void Parser::SetInt(const string& key, int value)
{
	stringstream convert;
	convert << value;
	mValues[key] = convert.str();
}

Parser& Parser::Config()
{
	static Parser* config = nullptr;
	if (!config) {
		config = new Parser("config.txt");
		config->Load();
	}
	return *config;
}
