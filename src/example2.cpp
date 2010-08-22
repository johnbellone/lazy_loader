#include <thunk/lazy_loader.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/nil_generator.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <string>

class Unique
{
public:
    Unique() 
        : m_uuid(boost::uuids::random_generator()())
    {
    }

    Unique(boost::uuids::nil_generator& gen)
        : m_uuid(gen())
    {
    }

    const boost::uuids::uuid& uuid()
    {
        return m_uuid;
    }
private:
    boost::uuids::uuid m_uuid;
};

static void allocate(boost::shared_ptr<Unique>& impl)
{
    impl = new Unique(boost::uuids::nil_generator());
}

int main(int argc, char* argv[])
{
    thunk::lazy_loader<Unique> loader;

    const boost::uuids::uuid& u = loader->uuid();

    std::cout<<"uuid: "<<boost::lexical_cast<std::string>(u)<<std::endl;    

    return 0;
}
