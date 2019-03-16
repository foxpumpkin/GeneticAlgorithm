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
      Population(const uint64_t& population_locus);
      ~Population();
      const uint64_t get_population_locus() const;
      uint64_t length() const;
      void allocation(const uint64_t &length);
      //const std::shared_ptr<Individual> operator[](std::size_t idx) const;
      //std::shared_ptr<Individual> operator[](std::size_t idx);
      const Individual& operator[](std::size_t idx) const;
      Individual& operator[](std::size_t idx);
      void initialize();

    private:
      std::unique_ptr<std::shared_ptr<Individual>[], std::default_delete<std::shared_ptr<Individual>[]> > individuals;
      uint64_t _length;
      uint64_t _population_locus;
      Log log;
  };

  extern const std::string locus_to_string(const Population *population);
}

#endif
