#ifndef FACE_DEAD_HPP
#define FACE_DEAD_HPP

#include <gui_generated/containers/face_deadBase.hpp>

class face_dead : public face_deadBase
{
public:
    face_dead();
    virtual ~face_dead() {}

    virtual void initialize();
protected:
};

#endif // FACE_DEAD_HPP
