#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>

using namespace std;


struct TestConfigurationParameter
{
    bool is_set_x;
    bool is_set_y;
    int x;
    float y;
};


bool extractArgument(std::string& arg, const std::string&& argName, const std::unordered_map<std::string, std::string>& argMap)
{
    std::unordered_map<std::string, std::string>::const_iterator argFound;
    argFound = argMap.find(argName);
    if(argFound == argMap.cend())
    {
        arg = "";
        return false;
    }
    arg = argFound->second;
    return true;
}

void loadParams(const std::string& configPath, std::vector<TestConfigurationParameter>& Params){
    ifstream configData(configPath, ios::in);

    vector<map<string, string>> configMap;
    if (configData.is_open()){
        vector<string> configHead;

        string line;
        istringstream sin; 
        getline(configData, line);
        string word;

        sin.str(line);
        while (getline(sin, word, ','))
        {
            configHead.push_back(word);
        }
        
        while (getline(configData, line))
        {
            sin.clear();
            sin.str(line);
            map<string, string> configCurrent;
            int idx = 0;
            while (getline(sin, word, ',')){
                configCurrent.insert({configHead[idx], word});
                ++idx;
            }
            configMap.push_back(configCurrent);
        }

        for (auto config : configMap){
            TestConfigurationParameter Param;
            Param.is_set_x = (config["is_set_x"] == "True");
            Param.is_set_y = (config["is_set_y"] == "True");
            Param.x = stoi(config["x"]);
            Param.y = stof(config["y"]);
            Params.push_back(Param);
        }
    }
}

int main(int argc, char** argv){

    std::unordered_map<std::string, std::string> argMap;
    for(uint32_t i = 1; i < argc; i += 2)
    {
        argMap.insert({argv[i], argv[i+1]});
    }
    std::string scenarioFilePath;
    if(!extractArgument(scenarioFilePath, "--configFile", argMap))
    {
         std::cout << "No configuration file provided!" << std::endl;
    }
    else
    {
         std::cout << "Configuration file provided! " << scenarioFilePath << " will be used for initialization."<< std::endl;
    }

    vector<map<string, string>> configMap;
    vector<TestConfigurationParameter> Params;
    loadParams(scenarioFilePath, Params);
    cout << "print from 0 " << Params[0].x << endl;
    cout << "print from 1 " << Params[1].y << endl;
    return 0;
}