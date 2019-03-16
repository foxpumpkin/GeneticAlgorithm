#ifndef _GENE_HPP__
#define _GENE_HPP__

#include <cstdint>
#include <random>

#include <Log.hpp>
#include <Define.hpp>

namespace GA{

  //! 遺伝子（gene）
  /*!
   * 個体の形質を表すための基本となる構成要素
   */
  class Gene{
    public:
      Gene( const uint64_t& population_locus,
          const uint64_t& individual_locus,
          const uint64_t& chromosome_locus,
          const uint64_t& locus);
      ~Gene();
      const uint64_t get_population_locus() const;
      const uint64_t get_individual_locus() const;
      const uint64_t get_chromosome_locus() const;
      const uint64_t get_locus() const;
      void initialize();
      uint64_t getValue() const;
      //uint64_t locus() const;
    private:
      uint64_t _population_locus;
      uint64_t _individual_locus;
      uint64_t _chromosome_locus;
      uint64_t _locus;
      Log log;
      // uint8_t kb[1024];
      uint64_t _value;
  };

  extern const std::string locus_to_string(const Gene *gene);
}
#endif
