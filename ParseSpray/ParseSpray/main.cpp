#pragma warning(disable:4996)
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "json/json.h"

int main()
{
	std::ifstream file_out(std::string("Spray.json"), std::ios::in);
	if (!file_out.good())
	{
		printf("File does not exist.\n");
		return 0;
	}
	std::stringstream ss;
	ss << file_out.rdbuf();
	std::string JsonString(ss.str());
	file_out.close();
	Json::Reader reader;
	Json::Value value;
	if (reader.parse(JsonString, value))
	{
		for (unsigned int i = 0; i < value.size(); i++)
		{
			int ID = value[i]["#id"].asInt();
			auto Sprayname = value[i]["sprayname"].asString();
			auto Decalname = value[i]["decalname"].asString();
			auto Imgfilename = value[i]["imgfilename"].asString();
			int ItemID = value[i]["itemID"].asInt();
			printf("Id: %d, Sprayname: %s, Decalname: %s, Imgfilename: %s, ItemID: %d\n", ID, Sprayname.c_str(), Decalname.c_str(), Imgfilename.c_str(), ItemID);
		}
	}
	file_out.clear();
	JsonString.clear();
	value.clear();
	Sleep(0xFFFFFFF);
	return 1;
}