#include <memory>
#include <iostream>
#include <string>
#include <map>

#include <GeneticAlgorithm.hpp>
#include <Log.hpp>

using namespace std;
using namespace GA;

int main(){
  //global::verbose_log= true;
  global::color_log= true;

  Log log("main");
  int pl_num= 2;
  int in_num= 2;
  int ch_num= 2;
  int gn_num= 2;

  GeneticAlgorithm ga;
  ga.allocation(pl_num);

  for(int pl= 0; pl< pl_num; pl++){
    ga[pl].allocation(in_num);
    for(int in= 0; in< in_num; in++){
      ga[pl][in].allocation(ch_num);
      for(int ch= 0; ch< ch_num; ch++){
        ga[pl][in][ch].allocation(gn_num);
      }
    }
  }
  ga.initialize();

  //LogSystem::get()->print();

  log.log<LogDebug>("application was successful");
  return 0;
}
