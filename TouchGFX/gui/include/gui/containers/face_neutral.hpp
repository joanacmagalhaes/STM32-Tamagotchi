#ifndef FACE_NEUTRAL_HPP
#define FACE_NEUTRAL_HPP

#include <gui_generated/containers/face_neutralBase.hpp>

class face_neutral : public face_neutralBase
{
public:
    face_neutral();
    virtual ~face_neutral() {}

    virtual void initialize();
protected:
};

#endif // FACE_NEUTRAL_HPP
