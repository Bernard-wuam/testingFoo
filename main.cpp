#include <iostream>
#include <boost/json.hpp>
#include <boost/json/value.hpp>

int main(int, char**){
    boost::json::value val = boost::json::object{{"name", "frankwhite"}};
    std::string stringVal{boost::json::serialize(val)};
    std::cout << " this is the value of the json: ==> "  << stringVal << std::endl;
    std::cout << "Hello, from learningcxxlibinstallation!\n";
}
