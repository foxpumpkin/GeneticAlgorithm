#include <Population.hpp>

namespace GA{
  using namespace std;

  Population::Population(const uint64_t& population_locus):
    _length(0),
    _population_locus(population_locus),
    log("Population"){
      log.log<LogTrace>(locus_to_string(this)+ " instancing");
    }

  Population::~Population(){
    log.log<LogTrace>(locus_to_string(this)+ " destructing");
  }

  const uint64_t Population::get_population_locus() const{ return _population_locus; }

  uint64_t Population::length() const{return _length;}

  void Population::allocation(const uint64_t &length){
    _length= length;
    log.log<LogTrace>(string("allocation: ")+to_string(_length));
    individuals= unique_ptr<shared_ptr<Individual>[], std::default_delete<std::shared_ptr<Individual>[]> >
      (new shared_ptr<Individual>[_length]);

    for(int i= 0; i< _length; i++){
      individuals.get()[i]= shared_ptr<Individual>(new Individual( _population_locus, i));
    }
  }

  const Individual& Population::operator[](std::size_t idx) const {
    return *(individuals.get()[idx]);
  }

  Individual& Population::operator[](std::size_t idx) {
    return *(individuals.get()[idx]);
  }

  const string locus_to_string(const Population *population){
    return to_string(population->get_population_locus());
  }

  void Population::initialize(){
    log.log<LogTrace>( locus_to_string(this)+ " initializing");
    if(_length){
      for(int i= 0; i< _length; i++){
        individuals.get()[i]->initialize();
      }
    } else{
      log.log<LogError>( "length is zero. allocate memory.");
    }
  }
}
