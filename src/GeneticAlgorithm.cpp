#include <GeneticAlgorithm.hpp>

using namespace std;

namespace GA{

  GeneticAlgorithm::GeneticAlgorithm():
    _length(0),
    log("GeneticAlgorithm"){
      log.log<LogTrace>("instancing");
    }

  GeneticAlgorithm::~GeneticAlgorithm(){
    log.log<LogTrace>("destructing");
  }

  uint64_t GeneticAlgorithm::length() const{
    log.log<LogTrace>(string("get length: ")+to_string(_length));
    return _length;
  }

  void GeneticAlgorithm::allocation(const uint64_t &length){
    _length= length;
    log.log<LogTrace>(string("allocation: ")+to_string(_length));
    populations= unique_ptr<shared_ptr<Population>[], std::default_delete<std::shared_ptr<Population>[]> >
      (new shared_ptr<Population>[_length]);

    for(int i= 0; i< length; i++){
      populations.get()[i]= shared_ptr<Population>(new Population(i));
    }
  }

  const Population& GeneticAlgorithm::operator[](std::size_t idx) const {
    return *(populations.get()[idx]);
  }

  Population& GeneticAlgorithm::operator[](std::size_t idx) {
    return *(populations.get()[idx]);
  }

  void GeneticAlgorithm::initialize(){
    log.log<LogTrace>( " initializing");
    if(_length){
      for(int i= 0; i< _length; i++){
        populations.get()[i]->initialize();
      }
    } else{
      log.log<LogError>( "length is zero. allocate memory.");
    }
  }
}
