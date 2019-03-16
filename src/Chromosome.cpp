#include <Chromosome.hpp>

namespace GA{
  using namespace std;
  Chromosome::Chromosome( const uint64_t& population_locus,
      const uint64_t& individual_locus, const uint64_t& chromosome_locus):
    _length(0),
    _population_locus(population_locus),
    _individual_locus(individual_locus),
    _chromosome_locus(chromosome_locus),
    log("Chromosome"){
      log.log<LogTrace>(locus_to_string(this)+ " instancing");
    }

  Chromosome::~Chromosome(){
    log.log<LogTrace>(locus_to_string(this)+ " destructing");
  }

  const uint64_t Chromosome::get_population_locus() const{ return _population_locus; }
  const uint64_t Chromosome::get_individual_locus() const{ return _individual_locus; }
  const uint64_t Chromosome::get_chromosome_locus() const{ return _chromosome_locus; }

  uint64_t Chromosome::length() const{return _length;}

  void Chromosome::allocation(const uint64_t &length){
    _length= length;
    log.log<LogTrace>(string("allocation: ")+to_string(_length));
    genes= unique_ptr<shared_ptr<Gene>[], std::default_delete<std::shared_ptr<Gene>[]> >
      (new shared_ptr<Gene>[_length]);
    for(int i= 0; i< _length; i++){
      genes.get()[i]= shared_ptr<Gene>(new Gene(_population_locus, _individual_locus, _chromosome_locus, i));
    }
  }

  const Gene& Chromosome::operator[](std::size_t idx) const {
    return *(genes.get()[idx]);
  }

  Gene& Chromosome::operator[](std::size_t idx) {
    return *(genes.get()[idx]);
  }
  /*
     const std::shared_ptr<Gene> Individual::operator[](std::size_t idx) const {
     return chromosomes.get()[idx];
     }

     std::shared_ptr<Gene> Individual::operator[](std::size_t idx) {
     return chromosomes.get()[idx];
     }
     */

  void Chromosome::initialize(){
    log.log<LogTrace>( locus_to_string(this)+ " initializing");
    if(_length){
      for(int i= 0; i< _length; i++){
        genes.get()[i]->initialize();
      }
    } else{
      log.log<LogError>( "length is zero. allocate memory.");
    }
  }


  const string locus_to_string(const Chromosome *chromosome){
    return 
      to_string(chromosome->get_population_locus())+ "-"
      + to_string(chromosome->get_individual_locus())+ "-"
      + to_string(chromosome->get_chromosome_locus());
  }
}
