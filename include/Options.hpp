#ifndef _LTOPTIONS_HPP__
#define _LTOPTIONS_HPP__

// standard libraries
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>

// boost libraries
#include <boost/program_options.hpp>

#include <Log.hpp>

using namespace boost::program_options;

namespace GA{
  //! コマンドライン引数を処理する基底クラス
  /*!
   * 純粋仮想関数を含むため、直接インスタンスにできない。
   * ベースはboost::program_optionsを使用している。
   */
  class Options{
    public:
      
      //! 標準のhelpオプションとversionオプションを追加
      Options(const int _ac, const char* const * const _av);
      
      //! 処理なし 
      ~Options();
      
      //! オプションの解釈
      /*!
       */
      virtual void parse();
      bool isColor();
      const uint64_t getPopulationNumber() const;
      const uint64_t getIndividualNumber() const;
      const uint64_t getChromosomeNumber() const;
      const uint64_t getGeneNumber() const;

    protected:
      
      //! boost::program_options
      options_description description;
      
      //! バージョン情報をstring型で返す。
      std::string getVersion();
      
      //! main関数が受け取るコマンドライン引数
      const int ac;
      
      //! main関数が受け取るコマンドライン引数
      const char* const * const av;
      
      //! boost::program_options用の実マップ
      variables_map vmap;

    private:
      bool verbose;
      bool color;
      Log log;
      uint64_t population_number;
      uint64_t individual_number;
      uint64_t chromosome_number;
      uint64_t gene_number;
  };
}

#endif
