#ifndef _DEFINE_HPP__
#define _DEFINE_HPP__

#include <cstdint>
#include <mutex>
#include <thread>
#include <string>
#include <map>

namespace GA{
  namespace global{
    extern bool verbose_log;
    extern bool color_log;
  }

  namespace code{
    extern const uint64_t code_A;
    extern const uint64_t code_B;
    extern const uint64_t code_C;
    extern const uint64_t code_D;
    extern const uint64_t code_E;
    extern const uint64_t none;

    extern std::string to_string(const uint64_t &code);
  }

  namespace loglevel{
    extern const uint64_t all;
    extern const uint64_t fatal;
    extern const uint64_t error;
    extern const uint64_t warning;
    extern const uint64_t information;
    extern const uint64_t debug;
    extern const uint64_t trace;
    extern const uint64_t none;
    extern std::string to_string(const uint64_t &flag);

  }

  namespace color{
    extern const uint64_t black;
    extern const uint64_t red;
    extern const uint64_t green;
    extern const uint64_t yellow;
    extern const uint64_t blue;
    extern const uint64_t magenta; 
    extern const uint64_t cyan; 
    extern const uint64_t white;
    extern const uint64_t clear;
    
    //! ログカラー出力用の基底クラス
    /*!
     */
    class Color{
      public:
        Color()= default;
        virtual ~Color()= 0;
        uint64_t getColorCode() const;
      protected:
        uint64_t code;
    };
    
    //! ログカラー出力用の派生クラス（黒）
    /*!
     */
    class Black: public Color{
      public:
        Black();
        virtual ~Black();
    };
    
    //! ログカラー出力用の派生クラス（赤）
    /*!
     */
    class Red: public Color{
      public:
        Red();
        virtual ~Red();
    };
    
    //! ログカラー出力用の派生クラス（緑）
    /*!
     */
    class Green: public Color{
      public:
        Green();
        virtual ~Green();
    };
    
    //! ログカラー出力用の派生クラス（黄）
    /*!
     */
    class Yellow: public Color{
      public:
        Yellow();
        virtual ~Yellow();
    };
    
    //! ログカラー出力用の派生クラス（青）
    /*!
     */
    class Blue: public Color{
      public:
        Blue();
        virtual ~Blue();
    };
    
    //! ログカラー出力用の派生クラス（マゼンタ）
    /*!
     */
    class Magenta: public Color{
      public:
        Magenta();
        virtual ~Magenta();
    };
    
    //! ログカラー出力用の派生クラス（シアン）
    /*!
     */
    class Cyan: public Color{
      public:
        Cyan();
        virtual ~Cyan();
    };
    
    //! ログカラー出力用の派生クラス（白）
    /*!
     */
    class White: public Color{
      public:
        White();
        virtual ~White();
    };
    
    //! ログカラー出力用の派生クラス（初期化）
    /*!
     */
    class Clear: public Color{
      public:
        Clear();
        virtual ~Clear();
    };
    template<class T> std::string to_string( const std::string &message);
  }
}

#endif

/*! \mainpage
 * hello
 */
