/*
Copyright (c) 2014 - Mark Severson

This file is part of Gish.

Gish is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef GISH_PARSER_H
#define GISH_PARSER_H

#include <map>
#include <string>

namespace Gish {

	class Parser {
	private:
		std::string mFilename;
		std::map<std::string, std::string> mValues;

	public:
		Parser(const std::string& filename);
		~Parser();

		void Load();
		void Save();
		void Clear();

		std::string GetString(const std::string& key) const;
		void SetString(const std::string& key, const std::string& value);

		int GetInt(const std::string& key) const;
		void SetInt(const std::string& key, int value);

		static Parser& Config();
	};

}

#endif // GISH_PARSER_H
