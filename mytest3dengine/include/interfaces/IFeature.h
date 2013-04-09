#ifndef IFeature_h_
#define IFeature_h_

#include <vector>
#include <algorithm>
#include <string>

namespace ISpace
{
    class IFeature
    {
    public:

        std::string getName()
        {
            return name;
        }

        std::string getType()
        {
            return type;
        }

        void setName( const std::string& name )
        {
            this->name = name;
        }

        void setType( const std::string& name )
        {
            this->type = type;
        }

        bool addFeature( IFeature* feature )
        {
            if ( feature->name.empty() || feature->type.empty() )
                return false;

            if ( !feature  )
                return false;

            if ( getFeature( feature->name ) )
                return false;

            features.push_back( feature );
            feature->parent = this;

            return true;
        }

        bool removeFeature( const std::string& name )
        {
            IFeature* f = getFeature( name );
            if ( !f )
                return false;

            features.erase( std::find( features.begin(), features.end(), f ) );
            return true;
        }

        IFeature* getFeature( const std::string& name )
        {
            if ( name.empty() )
                return NULL;

            std::vector<IFeature*>::iterator begin;
            for ( begin = features.begin(); begin != features.end(); ++ begin )
                if ( (*begin)->name == name )
                    return (*begin);

            return NULL;
        }

    protected:
        IFeature() { }
        virtual ~IFeature() { }

    private:
        std::string name;
        std::string type;
        IFeature* parent;

        std::vector<IFeature*> features;
    };
}

#endif
