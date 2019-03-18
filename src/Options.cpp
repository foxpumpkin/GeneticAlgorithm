#include <Options.hpp>

namespace GA{
  using namespace std;

  Options::Options(const int _ac, const char* const * const _av):
    description("Options"), ac(_ac), av(_av), vmap(), log("Options"),
      population_number(0), individual_number(0), chromosome_number(0), gene_number(0)
  {
      description.add_options() ("help,h", "Help");
      description.add_options() ("version,v", "Version information") ;
      description.add_options() ("Color,C", "color log");

      description.add_options()
        ("population,p", value<uint64_t>(),
         "Number of population (for test)");
      description.add_options()
        ("individual,i", value<uint64_t>(),
         "Number of individual (for test)");
      description.add_options()
        ("chromosome,c", value<uint64_t>(),
         "Number of population (for test)");
      description.add_options()
        ("gene,g", value<uint64_t>(),
         "Number of population (for test)");
      description.add_options() ("verbose,V", "more log");
      //description.add_options()
      //  ("gene,g", value<uint64_t>()->default_value(0),
      //   "Number of population (for test)");
    }

  Options::~Options(){
  }

  void Options::parse(){
    store(parse_command_line(ac, av, description), vmap);
    notify(vmap);

    if( vmap.count("help") ) {
      cout << description << endl;
      throw runtime_error("called help option");
    }
    if( vmap.count("version") ) {
      cout << this->getVersion();
      throw runtime_error("called version option");
    }
    if( vmap.count("Color") ) {
      color= true;
      global::color_log= true;
    }
    log.log<LogDebug>( "color option was set to "+ string( color?"true.":"false."));

    if( vmap.count("populationn")){
      population_number= vmap["population"].as<uint64_t>();
    }
    if( vmap.count("individual")){
      individual_number= vmap["individual"].as<uint64_t>();
    }
    if( vmap.count("chromosome")){
      chromosome_number= vmap["chromosome"].as<uint64_t>();
    }
    if( vmap.count("gene")){
      gene_number= vmap["gene"].as<uint64_t>();
    }
    if( vmap.count("verbose") ) verbose = true;
  }

  bool Options::isColor(){
    return color;
  }

  const uint64_t Options::getPopulationNumber() const{ return population_number;}

  const uint64_t Options::getIndividualNumber() const{ return individual_number; }

  const uint64_t Options::getChromosomeNumber() const{ return chromosome_number; }

  const uint64_t Options::getGeneNumber() const{ return gene_number; }


  string Options::getVersion(){
    stringstream ss;
    ss<< "Implementation of The GeneticAlgorithm with C++"<< endl;
    ss<< "     Version: 0.0"<< endl;
    ss<< " Update Date: Mar. 2019"<< endl;
    ss<< "      Author: foxpumpkin"<< endl;
    return ss.str();
  }
}

