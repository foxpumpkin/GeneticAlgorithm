#ifndef _LOGINSTANCE_HPP__
#define _LOGINSTANCE_HPP__

#include <iostream>
#include <iomanip>

#include <Define.hpp>

namespace GA{
  
//! ログの実クラス
/*!
 * 時刻(time_point)、メッセージ(string)、ID(uint64_t)、コード(uint64_t)、カウンタ(uint64_t)を持つ。
 * 比較(operator==)はコードを比較し、和(operator+=)はカウンタを合算する。  
 * ログレベルは下記URLを参考にしている。
 * https://qiita.com/nanasess/items/350e59b29cceb2f122b3
 */
  class LogInstance{
    public:
      //! 処理なし
      LogInstance(uint64_t id, std::string _message, uint64_t _code);
      //! 処理なし
      ~LogInstance();
      //! ログ内容を出力する
      /*!
       * GA::global::verbose_logがfalseの場合、IDは出力されない。
       */
      void print();
      //! 格納されているメッセージを返す
      std::string getMessage();
      //! 格納されているコードを返す
      uint64_t getCode();
      //! 格納されているカウンタを返す
      uint64_t getCounter();
      //! 時間を比較する
      friend bool operator<(const LogInstance& left, const LogInstance& right) {return left.time< right.time;}
      //! コードを比較する
      bool operator==(const LogInstance& right) const{ return code==right.code; }
      //! コードを比較する
      bool operator==(const uint64_t& right) const{ return code==right; }
      //! カウンタを加算する
      LogInstance& operator+=(const LogInstance& right){counter+= right.counter; return *this;}
      //! カウンタを加算する
      LogInstance& operator+=(const int& right_counter){counter+= right_counter; return *this;}

    protected:

    private:
      //! メッセージを格納する
      std::string message;
      //! コードを格納する（詳細はdefine.hppを参照）
      uint64_t code;
      //! LogInstanceインスタンスが作成された時刻を格納する
      std::chrono::system_clock::time_point time;
      //! カウンタを格納する
      uint64_t counter;
      //! IDを格納する
      uint64_t id;
  };
}
#endif
