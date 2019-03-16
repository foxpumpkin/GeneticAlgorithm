#ifndef _LOG_HPP__
#define _LOG_HPP__

#include <string>
#include <iostream>

#include <LogSystem.hpp>

namespace GA{
  //! ログ生成用
  /*!
   * Singletonで実装されているLogSystem Classに対するインタフェースの役割
   */
  class Log{
    public:
      Log(std::string name);
      ~Log()= default;
      template<class T> void log( std::string message) const;
    private:
      std::string name;
  };
}



#endif
