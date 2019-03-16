#include <LogInstance.hpp>

GA::LogInstance::LogInstance(uint64_t id, std::string _message, uint64_t _code):
  message(_message),
  code(_code),
  time(std::chrono::system_clock::now()),
  counter(1),
  id(id){
    print();
  }

GA::LogInstance::~LogInstance(){
}

void GA::LogInstance::print(){
  time_t t = std::chrono::system_clock::to_time_t(time);
  const tm* lt = localtime(&t);
  const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>( time.time_since_epoch()) % 1000;
  //std::cout << "["<<std::put_time(lt,"%a %b %d %Y %T")// "%c")
  std::cout << "[";
  // if(GA::global::verbose_log)
  std::cout<< loglevel::to_string(id)<< "/"
    << code::to_string(code)<< "/"
    //<< std::setfill('0')<<std::setw(16)<< std::hex << code<<"/"
    << std::dec<< std::put_time(lt,"%T")// "%c")
    << '.'<< std::setfill('0') << std::setw(3) << ms.count()<< "] ";
  //if(!GA::global::verbose_log) std::cout<< counter<< " - ";
  std::cout<< message<< std::endl;
}

std::string GA::LogInstance::getMessage(){ return message; }
uint64_t GA::LogInstance::getCode(){ return code; }
uint64_t GA::LogInstance::getCounter(){ return counter; }
// bool GA::LogInstance::operator<(const LogInstance& right){ return true;}

