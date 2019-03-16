#include <Gene.hpp>

namespace GA{
  using namespace std;
  Gene::Gene( const uint64_t& population_locus,
      const uint64_t& individual_locus,
      const uint64_t& chromosome_locus,
      const uint64_t& locus):
    _population_locus(population_locus),
    _individual_locus(individual_locus),
    _chromosome_locus(chromosome_locus),
    _locus(locus),
    log("Gene"){
      log.log<LogTrace>(locus_to_string(this)+ " instancing");
    }

  Gene::~Gene(){
    log.log<LogTrace>(locus_to_string(this)+ " destructing");
  }
  //uint64_t GA::Gene::locus() const{ return _locus; }
  const uint64_t Gene::get_population_locus() const{ return _population_locus; }
  const uint64_t Gene::get_individual_locus() const{ return _individual_locus; }
  const uint64_t Gene::get_chromosome_locus() const{ return _chromosome_locus; }
  const uint64_t Gene::get_locus() const{ return _locus; }

  const string locus_to_string(const Gene *gene){
    return 
      to_string(gene->get_population_locus())+ "-"
      + to_string(gene->get_individual_locus())+ "-"
      + to_string(gene->get_chromosome_locus())+ "-"
      + to_string(gene->get_locus());
  }

  void Gene::initialize(){
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand100( 0, 99);
    _value= rand100(mt);
    // _value= 0;//rnd(mt19937(random_device()())); 
    log.log<LogTrace>( locus_to_string(this)+ " initializing: "+ to_string( _value ));
  }

  uint64_t Gene::getValue() const{ return _value; }
}
