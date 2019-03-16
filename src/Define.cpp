#include <Define.hpp> 

namespace GA{
  using namespace std;
  namespace global{
    bool verbose_log = false;
    bool color_log = false;
  }

  namespace code{
    const uint64_t code_A = 0x00'00'00'00'00'00'00'01;
    const uint64_t code_B = 0x00'00'00'00'00'00'00'02;
    const uint64_t code_C = 0x00'00'00'00'00'00'00'04;
    const uint64_t code_D = 0x00'00'00'00'00'00'00'08;
    const uint64_t code_E = 0x00'00'00'00'00'00'00'10;
    const uint64_t none = 0x00'00'00'00'00'00'00'00;

    string to_string(const uint64_t &flag){
      map<uint64_t, string> funcs;
      funcs.insert(make_pair(code::code_A, "A"));
      funcs.insert(make_pair(code::code_B, "B"));
      funcs.insert(make_pair(code::code_C, "C"));
      funcs.insert(make_pair(code::code_D, "D"));
      funcs.insert(make_pair(code::code_E, "E"));
      funcs.insert(make_pair(code::none, "None"));

      map<uint64_t, string>::iterator itr= funcs.find(flag);
      if(itr!= funcs.end()) return itr->second;
      return "unknown";
    }
  }

  namespace loglevel{

    const uint64_t all         = 0x00'00'00'00'00'00'00'FF;
    const uint64_t fatal       = 0x00'00'00'00'00'00'00'20;
    const uint64_t error       = 0x00'00'00'00'00'00'00'10;
    const uint64_t warning     = 0x00'00'00'00'00'00'00'08;
    const uint64_t information = 0x00'00'00'00'00'00'00'04;
    const uint64_t debug       = 0x00'00'00'00'00'00'00'02;
    const uint64_t trace       = 0x00'00'00'00'00'00'00'01;
    const uint64_t none        = 0x00'00'00'00'00'00'00'00;

    string to_string(const uint64_t &flag){
      map<uint64_t, string> funcs;
      funcs.insert(make_pair(loglevel::all,         color::to_string<color::Clear>("All")        ));
      funcs.insert(make_pair(loglevel::fatal,       color::to_string<color::Red>("Fatal")        ));
      funcs.insert(make_pair(loglevel::error,       color::to_string<color::Green>("Error")      ));
      funcs.insert(make_pair(loglevel::warning,     color::to_string<color::Yellow>("Warning")   ));
      funcs.insert(make_pair(loglevel::information, color::to_string<color::Blue>("Information") ));
      funcs.insert(make_pair(loglevel::debug,       color::to_string<color::Magenta>("Debug")    ));
      funcs.insert(make_pair(loglevel::trace,       color::to_string<color::Cyan>("Trace")       ));
      funcs.insert(make_pair(loglevel::none,        color::to_string<color::White>("None")       ));

      map<uint64_t, string>::iterator itr= funcs.find(flag);
      return (itr!= funcs.end())? itr->second: "Unknown";
    }
  }

  namespace color{
    const uint64_t black=   0x00'00'00'00'00'00'00'01;
    const uint64_t red=     0x00'00'00'00'00'00'00'02;
    const uint64_t green=   0x00'00'00'00'00'00'00'04;
    const uint64_t yellow=  0x00'00'00'00'00'00'00'08;
    const uint64_t blue=    0x00'00'00'00'00'00'00'10;
    const uint64_t magenta= 0x00'00'00'00'00'00'00'20;
    const uint64_t cyan=    0x00'00'00'00'00'00'00'40; 
    const uint64_t white=   0x00'00'00'00'00'00'00'80;
    const uint64_t clear=   0x00'00'00'00'00'00'01'00;
    uint64_t Color::getColorCode() const{return code;}
    Color::~Color(){}
    Black::Black(){code= black;}
    Black::~Black(){}
    Red::Red(){code= red;}
    Red::~Red(){}
    Green::Green(){code= green;}
    Green::~Green(){}
    Yellow::Yellow(){code= yellow;}
    Yellow::~Yellow(){}
    Blue::Blue(){code= blue;}
    Blue::~Blue(){}
    Magenta::Magenta(){code= magenta;}
    Magenta::~Magenta(){}
    Cyan::Cyan(){code= cyan;}
    Cyan::~Cyan(){}
    White::White(){code= white;}
    White::~White(){}
    Clear::Clear(){code= clear;}
    Clear::~Clear(){}

    template<class T> string to_string( const std::string &message){
      if( !global::color_log) return message;

      T t;
      uint64_t color_code= t.getColorCode();

      map<uint64_t, string> funcs;
      funcs.insert(make_pair( color::black,   "\e[30m"));
      funcs.insert(make_pair( color::red,     "\e[31m"));
      funcs.insert(make_pair( color::green,   "\e[32m"));
      funcs.insert(make_pair( color::yellow,  "\e[33m"));
      funcs.insert(make_pair( color::blue,    "\e[34m"));
      funcs.insert(make_pair( color::magenta, "\e[35m"));
      funcs.insert(make_pair( color::cyan,    "\e[36m"));
      funcs.insert(make_pair( color::white,   "\e[37m"));
      funcs.insert(make_pair( color::clear,   "\e[m"  ));

      map<uint64_t, string>::iterator itr;

      // get color code
      itr= funcs.find(color_code);
      string color= (itr!= funcs.end())? itr->second: "";

      // get clear code
      itr= funcs.find(clear);
      string clear= (itr!= funcs.end())? itr->second: "";

      string msg= color+ message+ clear;

      return msg;
    }
    
    //! template color::to_stringにおける黒の特殊化実装
    template string to_string<Black>( const string &message);
    
    //! template color::to_stringにおける赤の特殊化実装
    template string to_string<Red>( const string &message);
    
    //! template color::to_stringにおける緑の特殊化実装
    template string to_string<Green>( const string &message);
    
    //! template color::to_stringにおける黄の特殊化実装
    template string to_string<Yellow>( const string &message);
    
    //! template color::to_stringにおける青の特殊化実装
    template string to_string<Blue>( const string &message);
    
    //! template color::to_stringにおけるマゼンタの特殊化実装
    template string to_string<Magenta>( const string &message);
    
    //! template color::to_stringにおけるシアンの特殊化実装
    template string to_string<Cyan>( const string &message);
    
    //! template color::to_stringにおける白の特殊化実装
    template string to_string<White>( const string &message);
    
    //! template color::to_stringにおける初期化の特殊化実装
    template string to_string<Clear>( const string &message);
  }
}

