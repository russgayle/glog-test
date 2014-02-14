#include <glog/logging.h>
#include <gflags/gflags.h>

#include "DoSomething.hpp"

int main(int argc, char* argv[]) {
  // Parse flags
  google::SetVersionString("0.0.1");
  google::ParseCommandLineFlags(&argc, &argv, true);

  // Configure logging
  FLAGS_log_dir = "./logs";       // Put logs here.
  FLAGS_log_link = ".";           // Add links here.
  FLAGS_colorlogtostderr = true;  // If logtostderr, make it colored. Cool.

  // Init logging
  google::InitGoogleLogging(argv[0]);

  // Test levels 
  DLOG(INFO) << "DEBUG(INFO): Only prints in debug mode";
  LOG(INFO) << "INFO: We have INFO!";
  LOG(WARNING) << "WARNING: We have a warning!"; 
  LOG(ERROR) << "ERROR: We have an error!";

  // Test conditional logs
  size_t testVal = 10;
  LOG_IF(INFO, testVal > 9) << "Passed. Should have printed.";
  LOG_IF(INFO, testVal > 11) << "Should not be printed!";

  for (size_t i = 0; i < 100; i++) {
    LOG_EVERY_N(INFO, 10) << "Iter " << google::COUNTER;
    // LOG_IF_EVERY_N(INFO, (testVal > 9), 10) << "Passed. And, iter " << google::COUNTER;
  }

  for (size_t i = 0; i < 100; i++) {
    LOG_FIRST_N(INFO, 10) << "Iter " << google::COUNTER;
  }

  // CHECK macros (coming soon)

  // VERBOSE logging (coming soon)
  GlobalSomething();
  GlobalWarning();

  DoSomething something;
  something.warning();

  LOG(FATAL) << "FATAL: Ruh-roh."; // Note: This exits.
}
