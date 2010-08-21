#include <thunk/lazy_loader.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <string>

class Unique
{
public:
    Unique() 
    {
    }

    const boost::uuids::uuid& uuid()
    {
        return m_uuid;
    }
private:
    boost::uuids::uuid m_uuid;
};

int main(int argc, char* argv[])
{
    thunk::lazy_loader<Unique> loader;

    const boost::uuids::uuid& u = loader->uuid();

    std::cout<<"uuid: "<<boost::lexical_cast<std::string>(u)<<std::endl;    

    return 0;
}
