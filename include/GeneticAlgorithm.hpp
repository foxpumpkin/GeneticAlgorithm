#ifndef _GENETICALGORITHM_HPP__
#define _GENETICALGORITHM_HPP__

#include <memory>

#include <Population.hpp>
#include <Log.hpp>
#include <Define.hpp>

namespace GA{

  //! 遺伝的アルゴリズムのベースクラス
  /*!
   * main関数からは呼ぶのは原則このクラスのみ
   */
  class GeneticAlgorithm{
    public:
      
      //! コンストラクタ
      GeneticAlgorithm();
      
      //! デストラクタ
      ~GeneticAlgorithm();
      
      //! Populationの列数を返す
      uint64_t length() const;
      
      //! 指定した列長のPopulationをインスタンス化する
      void allocation(const uint64_t &length);
      
      //! 配列アクセス用のオペレータ
      const Population& operator[](std::size_t idx) const;
      
      //! 配列アクセス用のオペレータ
      Population& operator[](std::size_t idx);
      
      //! allocation後の現世代生成用関数
      void initialize();
      
    private:
      
      //! Population配列を格納するユニークポインタ
      std::unique_ptr<std::shared_ptr<Population>[], std::default_delete<std::shared_ptr<Population>[]> > populations;
      
      //! 列帳を格納する
      uint64_t _length;
      
      //! ログ出力用インスタンス
      Log log;
  };
}

#endif
