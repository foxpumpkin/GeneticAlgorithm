#ifndef _LOGQUEUE_HPP__
#define _LOGQUEUE_HPP__

#include <vector>

#include <Define.hpp>
#include <LogInstance.hpp>

namespace GA{
  //! ログを格納し、リスト化するクラス
  /*!
   * シフト(perator<<)はstd::vectorを連結する。
   * define.hppで定義される(bool)GA::global::verbose_logがtrueであれば
   * std::vectorを連結し、falseであればコードをキーとしてカウンタを合算する。
   */
  class LogQueue{
    public:
      //! 処理なし
      LogQueue();
      //! 処理なし
      ~LogQueue();
      //! キューの追加 ※使用は非推奨
      void addQueue(LogInstance log);
      //! キューの追加
      void addQueue(std::string message, uint64_t code= code::none);
      //! キューのIDをセット
      /*!
       * 実際はスレッドIDとして使用しており、ログを詳細に出力する場合は
       * 効果がある。
       */
      void setId(uint64_t id);
      //! キュー（std::vector）を返す
      std::vector<LogInstance> getQueue() const;
      //! キュー（std::vector）を結合する
      /*!
       * global::verbose_logがtrueの場合はstd::vectorを結合する。
       * falseの場合はコードをキーとしてカウンタを加算する。
       */
      LogQueue& operator<<( const LogQueue &queue);
      //! 格納されているLogインスタンスに対してprint()をコールする
      void print();
      //! HTTP Response Codeが一致するLogインスタンスのカウンタ合計を返す
      int getHttpResponseCode(const uint64_t &code);
      //! code::messageとのビット積が一致するLogインスタンスのカウンタ合計を返す
      int getStatistics(const uint64_t &code);
      //! Logの記録時間をキーとしてstd::vectorを昇順にソートする
      void sort();

    protected:

    private:
      //! Log用のキュー(std::vector)
      std::vector<LogInstance> loglist;
      //! IDを格納する
      uint64_t id;
  };
}


#endif
