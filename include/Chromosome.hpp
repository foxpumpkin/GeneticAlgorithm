#ifndef _CHROMOSOME_HPP
#define _CHROMOSOME_HPP

#include <memory>
#include <cstdint>

#include <Gene.hpp>
#include <Log.hpp>

namespace GA{

  //! 染色体（chromosome）
  /*!
   * 複数の遺伝子に集まり
   */
  class Chromosome{
    public:
      Chromosome( const uint64_t& population_locus, const uint64_t& individual_locus, const uint64_t& locus);
      ~Chromosome();
      const uint64_t get_population_locus() const;
      const uint64_t get_individual_locus() const;
      const uint64_t get_chromosome_locus() const;
      uint64_t length() const;
      void allocation(const uint64_t &length);
      //const std::shared_ptr<Gene> operator[](std::size_t idx) const;
      //std::shared_ptr<Gene> operator[](std::size_t idx);
      const Gene& operator[](std::size_t idx) const;
      Gene& operator[](std::size_t idx);
      void initialize();

    private:
      std::unique_ptr<std::shared_ptr<Gene>[], std::default_delete<std::shared_ptr<Gene>[]> > genes;
      //std::shared_ptr<Gene> genes;
      uint64_t _length;
      uint64_t _population_locus;
      uint64_t _individual_locus;
      uint64_t _chromosome_locus;
      Log log;
  };

  extern const std::string locus_to_string(const Chromosome *chromosome);
}

#endif
