#ifndef IRenderable_h_
#define IRenderable_h_

#include "IFeature.h"

namespace ISpace
{
    class IRenderable : public IFeature
    {
    public:

        virtual ~IRenderable() { }

        virtual void render() = 0;
    };

}

#endif
