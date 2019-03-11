#pragma once

#include <string>

using std::string;

class Resources
{
private:
	string ResourceName;
public:
	
	Resources() {};
	
	Resources(string RecourceName);
	void setResourceName(string name)
	{
		ResourceName = name;
	}
	string getResourceName()
	{
		return ResourceName;
	}
	~Resources();

};
