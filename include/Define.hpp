#ifndef _DEFINE_HPP__
#define _DEFINE_HPP__

#include <cstdint>
#include <mutex>
#include <thread>
#include <string>
#include <map>

namespace GA{

  //! グローバル変数定義用の名前空間
  /*! 
   */
  namespace global{
    
    //! verboseモード（Mar. 2019時点未実装）を有効にしたい場合trueを与える。
    extern bool verbose_log;
    
    //! ログをカラー出力したい（color::to_stringを有効にしたい）場合trueを与える。
    extern bool color_log;
  }

  //! ログコード定義用の名前空間
  /*! 
   */
  namespace code{

    //! 用途未定仮設コード（A）
    extern const uint64_t code_A;

    //! 用途未定仮設コード（B）
    extern const uint64_t code_B;

    //! 用途未定仮設コード（C）
    extern const uint64_t code_C;

    //! 用途未定仮設コード（D）
    extern const uint64_t code_D;

    //! 用途未定仮設コード（E）
    extern const uint64_t code_E;

    //! デフォルトコード
    extern const uint64_t none;

    //! コードをstring型に変換する関数
    /*! 
     * 未定義のコードの場合はUnknownを返す。
     */
    extern std::string to_string(const uint64_t &code);
  }

  //! ログレベル定義用の名前空間
  /*! 
   * 
   */
  namespace loglevel{

    //! すべてのログを出力するさいに指定する
    extern const uint64_t all;

    //! 致命的なエラーを指す定数
    extern const uint64_t fatal;

    //! エラーを指す定数
    extern const uint64_t error;

    //! 警告を指す定数
    extern const uint64_t warning;

    //! 情報を指す定数
    extern const uint64_t information;

    //! デバッグを指す定数
    extern const uint64_t debug;

    //! トレースを指す定数
    extern const uint64_t trace;

    //! 使用非推奨のログレベルを指す定数
    extern const uint64_t none;

    //! ログレベルをstring型に変換する関数
    /*!
     * 未定義のログレベルの場合はUnknownを返す。
     */
    extern std::string to_string(const uint64_t &flag);

  }

  //! 標準出力への着色用名前空間
  /*! 
   * 
   */
  namespace color{

    //! 文字色（黒）を指す定数
    extern const uint64_t black;

    //! 文字色（赤）を指す定数
    extern const uint64_t red;

    //! 文字色（緑）を指す定数
    extern const uint64_t green;

    //! 文字色（黄）を指す定数
    extern const uint64_t yellow;

    //! 文字色（青）を指す定数
    extern const uint64_t blue;

    //! 文字色（マゼンタ）を指す定数
    extern const uint64_t magenta; 

    //! 文字色（シアン）を指す定数
    extern const uint64_t cyan; 

    //! 文字色（白）を指す定数
    extern const uint64_t white;

    //! 文字色（初期化）を指す定数
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

