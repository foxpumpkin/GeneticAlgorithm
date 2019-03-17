#include <memory>
#include <iostream>
#include <string>
#include <map>

#include <GeneticAlgorithm.hpp>
#include <Log.hpp>
#include <Options.hpp>

using namespace std;
using namespace GA;

int main(const int _ac, const char* const * const _av){
  Log log("main");

  Options o(_ac, _av);
  try{
    o.parse();
  } catch( std::runtime_error &e){
    //log.log<LogFatal>("options: "+ std::string(e.what()));
    return 0;
  } catch( std::exception &e){
    log.log<LogFatal>("options: "+ std::string(e.what()));
    return -1;
  }

  GeneticAlgorithm ga;
  ga.allocation(o.getPopulationNumber());

  for(int pl= 0; pl< o.getPopulationNumber(); pl++){
    ga[pl].allocation(o.getIndividualNumber());
    for(int in= 0; in< o.getIndividualNumber(); in++){
      ga[pl][in].allocation(o.getChromosomeNumber());
      for(int ch= 0; ch< o.getChromosomeNumber(); ch++){
        ga[pl][in][ch].allocation(o.getGeneNumber());
      }
    }
  }
  ga.initialize();

  //LogSystem::get()->print();

  log.log<LogDebug>("application was successful");
  return 0;
}


