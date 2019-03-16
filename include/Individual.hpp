#ifndef _GAINDIVISUAL_HPP__
#define _GAINDIVISUAL_HPP__

#include <memory>
#include <cstdint>

#include <Chromosome.hpp>
#include <Log.hpp>

namespace GA{
  
  //! 個体（individual）
  /*!
   * １つまたは複数の染色体によって表現される自律的な個命題に対する解の候補
   */
  class Individual{
    public:
      Individual(const uint64_t& population_locus, const uint64_t& indivisual_locus);
      ~Individual();
      const uint64_t get_population_locus() const;
      const uint64_t get_individual_locus() const;
      uint64_t length() const;
      void allocation(const uint64_t &length);
      //const std::shared_ptr<Chromosome> operator[](std::size_t idx) const;
      //std::shared_ptr<Chromosome> operator[](std::size_t idx);
      const Chromosome& operator[](std::size_t idx) const;
      Chromosome& operator[](std::size_t idx);
      void initialize();

    private:
      
      //! Chromosomeのシェアードポインタ配列を保持するユニークポインタ
      std::unique_ptr<std::shared_ptr<Chromosome>[], std::default_delete<std::shared_ptr<Chromosome>[]> > chromosomes;
      
      //! Chromosomeのシェアードポインタ配列長
      uint64_t _length;
      
      //! 上位Populationのlocusを保持する変数
      uint64_t _population_locus;
      
      //! Individualのlocusを保持する変数
      uint64_t _individual_locus;
      
      //! ログ出力用インスタンス
      Log log;
  };
      
  //! Individualのポインタを引数としてlocusをstring型で返す
  extern const std::string locus_to_string(const Individual *individual);
}

#endif
