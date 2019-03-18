#ifndef _POPULATION_HPP__
#define _POPULATION_HPP__

#include <Individual.hpp>
#include <Log.hpp>

namespace GA{
  //! 集団（population）
  /*!
   * 様々な個体の集まり
   */
  class Population{
    public:
      
      //! Populationのlocusを引数とするコンストラクタ
      Population(const uint64_t& population_locus);
      
      //! 
      ~Population();
      
      //! Populationインスタンスのlocusを返す
      const uint64_t get_population_locus() const;
      
      //! Individualの配列長を返す
      uint64_t length() const;
      
      //!  Individualの配列長を引数としてメモリを確保する
      void allocation(const uint64_t &length);
      
      //! 指定された位置のIndividualの参照を返す
      const Individual& operator[](std::size_t idx) const;
      
      //!  指定された位置のIndividualの参照を返す
      Individual& operator[](std::size_t idx);
      
      //!  包含するIndividualの現世代を生成する
      void initialize();

    private:
      
      //! Individualのシェアードポインタ配列を保持するユニークポインタ
      std::unique_ptr<std::shared_ptr<Individual>[], std::default_delete<std::shared_ptr<Individual>[]> > individuals;
      
      //! Individualのシェアードポインタ配列長
      uint64_t _length;
      
      //! Populationのlocusを保持する変数
      uint64_t _population_locus;
      
      //! ログ出力用インスタンス
      Log log;
  };

  //! Populationのポインタを引数としてlocusをstring型で返す
  extern const std::string locus_to_string(const Population *population);
}

#endif
