#ifndef _DO_SOMETHING_HPP_
#define _DO_SOMETHING_HPP_

#include <glog/logging.h> 

// Testing verbose logging.

void GlobalSomething() {
  VLOG(0) << "Global something!";
}

void GlobalWarning() {
  VLOG(1) << "Yikes.";
}

class DoSomething {
public:
  DoSomething() {
    VLOG(0) << "Something, from a class.";
  }
  
  void warning() {
    VLOG(1) << "Warning from DoSomething";
  }
};

#endif // _DO_SOMETHING_HPP_
