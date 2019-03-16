#include <Individual.hpp>

namespace GA{
  using namespace std;

  Individual::Individual( const uint64_t& population_locus, const uint64_t& individual_locus):
    _length(0),
    _population_locus(population_locus),
    _individual_locus(individual_locus),
    log("Individual"){
      log.log<LogTrace>(locus_to_string(this)+ " instancing");
    }

  Individual::~Individual(){
    log.log<LogTrace>(locus_to_string(this)+ " destructing");
  }

  const uint64_t Individual::get_population_locus() const{ return _population_locus; }
  const uint64_t Individual::get_individual_locus() const{ return _individual_locus; }

  uint64_t Individual::length() const{return _length;}

  void Individual::allocation(const uint64_t &length){
    _length= length;
    log.log<LogTrace>(string("allocation: ")+to_string(_length));
    chromosomes= unique_ptr<shared_ptr<Chromosome>[], std::default_delete<std::shared_ptr<Chromosome>[]> >
      (new shared_ptr<Chromosome>[_length]);
    for(int i= 0; i< _length; i++){
      chromosomes.get()[i]= shared_ptr<Chromosome>(new Chromosome(_population_locus, _individual_locus, i));
    }
  }

  const Chromosome& Individual::operator[](std::size_t idx) const {
    return *(chromosomes.get()[idx]);
  }

  Chromosome& Individual::operator[](std::size_t idx) {
    return *(chromosomes.get()[idx]);
  }
  /*
     const std::shared_ptr<Chromosome> Individual::operator[](std::size_t idx) const {
     return chromosomes.get()[idx];
     }

     std::shared_ptr<Chromosome> Individual::operator[](std::size_t idx) {
     return chromosomes.get()[idx];
     }
     */

  void Individual::initialize(){
    log.log<LogTrace>( locus_to_string(this)+ " initializing");
    if(_length){
      for(int i= 0; i< _length; i++){
        chromosomes.get()[i]->initialize();
      }
    } else{
      log.log<LogError>( "length is zero. allocate memory.");
    }
  }

  const string locus_to_string(const Individual *individual){
    return 
      to_string(individual->get_population_locus())+ "-"
      + to_string(individual->get_individual_locus());
  }
}
