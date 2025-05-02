#ifndef POOP_HPP
#define POOP_HPP

#include <gui_generated/containers/poopBase.hpp>

class poop : public poopBase
{
public:
    poop();
    virtual ~poop() {}

    virtual void initialize();
    virtual void poopClicked();
protected:
};

#endif // POOP_HPP
