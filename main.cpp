#include <glog/logging.h>
#include <gflags/gflags.h>

int main(int argc, char* argv[]) {
  // Parse flags
  google::SetVersionString("0.0.1");
  google::ParseCommandLineFlags(&argc, &argv, true);

  // Init logging
  google::InitGoogleLogging(argv[0]);

  // ...
  LOG(INFO) << "Hello, world!";
}
