#include <Log.hpp>

namespace GA{
  using namespace std;
  Log::Log(string name): name(name){
  }
  template<class T> void Log::log( std::string message) const{
    T t;
    string msg("("+name+") "+ message);
    LogInstance loginstance= LogInstance( t.getLogType(), msg, code::none);
    LogSystem::get()->addLog( loginstance);
    //loginstance.print();
    // LogInstance(uint64_t id, std::string _message, uint64_t _code);
  }
  template void Log::log<LogAll>( string message) const;
  template void Log::log<LogFatal>( string message) const;
  template void Log::log<LogError>( string message) const;
  template void Log::log<LogWarning>( string message) const;
  template void Log::log<LogInformation>( string) const;
  template void Log::log<LogDebug>( string message) const;
  template void Log::log<LogTrace>( string message) const;
  template void Log::log<LogNone>( string message) const;
    /*
  class LogAll: public LogType{}
  class LogFatal: public LogType{}
  class LogError: public LogType{}
  class LogWarning: public LogType{}
  class LogInformation: public LogType{}
  class LogDebug: public LogType{}
  class LogNone: public LogType{}
  */
}
