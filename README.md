glog-test
=========

Goofing around with google-glog.

Build
-----

`g++ -L/usr/local/lib -lgflags -lglog main.cpp` 
`g++ -L/usr/local/lib -lgflags -lglog -DNDEBUG main.cpp`

Also, make the logs directory. (Links to log messages should be made in the working directory by default.) 
