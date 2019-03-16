#include <LogSystem.hpp>

namespace GA{
  using namespace std;

  LogType::~LogType(){ }

  LogSystem::LogSystem(){
  }

  std::unique_ptr<LogSystem> LogSystem::logsystem= unique_ptr<LogSystem>(nullptr);
}
