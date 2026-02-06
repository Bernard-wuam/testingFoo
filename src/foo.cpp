#include "foo/foo.h"
#include <boost/json.hpp>

void Foo::sayFoo(){
    boost::json::value v{boost::json::object{{"name","franchis"}}};
    std::string stringVal{boost::json::serialize(v)};
    std::cout << " saying Foo ==> " << stringVal << std::endl;
}