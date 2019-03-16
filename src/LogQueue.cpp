#include <LogQueue.hpp>

namespace GA{
  LogQueue::LogQueue(){
  }

  LogQueue::~LogQueue(){
  }
  void LogQueue::addQueue(LogInstance log){ loglist.push_back(log);}
  void LogQueue::addQueue(std::string message, uint64_t code){
    if(global::verbose_log){
      loglist.push_back(LogInstance(id, message, code));
    } else{
      auto itr= std::find(loglist.begin(),loglist.end(),code);
      if(itr!=loglist.end()){ // コードが重複している場合
        // cout<< "addQueue: found: code: "<< code<< ", counter: " << itr->getCounter()<< endl;
        (*itr)+= 1;
      } else{ // コードがこれまでにない場合
        // cout<< "addQueue: not found: code: "<< code<< endl;
        loglist.push_back(LogInstance(id, message, code));
      }
    }
  }
  std::vector<LogInstance> LogQueue::getQueue() const{ return loglist; }
  LogQueue& LogQueue::operator<<( const LogQueue &queue){
    auto queue_vector= queue.getQueue();
    if(global::verbose_log){
      loglist.insert( loglist.end(), queue_vector.begin(), queue_vector.end());
    } else{
      for(auto itr= queue_vector.begin(); itr!= queue_vector.end(); itr++){
        auto result= std::find(loglist.begin(), loglist.end(), *itr);
        if(result!=loglist.end()){ // 既知のコード
          (*result)+= (*itr);
        } else{ // はじめましてのコード
          addQueue(*itr);
        }
      }
    }
    return *this;
  }
  void LogQueue::setId(uint64_t id){ this->id = id; }
  void LogQueue::print(){ for( auto itr= loglist.begin(); itr!= loglist.end(); itr++){ itr->print(); } }
  int LogQueue::getHttpResponseCode(const uint64_t &code){
    /*! LogQueue::getGtppResponseCode 未実装 */
    /* 
       int value= 0;
       int _code = code<< 16;
       for(auto itr= loglist.begin(); itr!= loglist.end(); itr++){
       if((_code&code::status)==(itr->getCode()&code::status)){
       value+=itr->getCounter();
       }
       }
       return value;
       }

       int LogQueue::getStatistics(const uint64_t &code){
       int value= 0;
       for(auto itr= loglist.begin(); itr!= loglist.end(); itr++){
       if( (code&code::message)==(itr->getCode()&code::message)){
       value+=itr->getCounter();
       }
       }
       return value;
       */
    return 0;
  }

  void LogQueue::sort(){
    std::sort(loglist.begin(), loglist.end());
  }
}

