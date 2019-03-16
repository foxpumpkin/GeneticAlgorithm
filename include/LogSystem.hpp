#ifndef _LOGSYSTEM_HPP__
#define _LOGSYSTEM_HPP__

#include <memory>
#include <string>
#include <cstdint>

#include <LogQueue.hpp>
#include <Log.hpp>

namespace GA{

  //! ログレベルの基底クラス
  /*!
   * 新規にログレベルを実装する場合は、メンバ変数typeにuint64_tを設定する必要がある。
   * ログレベルの指定を型に任せることで不正な引数によるエラーをバグを避ける狙いがある。
   */
  class LogType{
    public:
      LogType()= default;
      virtual ~LogType()= 0;
      uint64_t getLogType()const{ return type;}
    protected:
      uint64_t type;
  };
  
  //! ログレベルLogAllクラス
  /*!
   * 
   */
  class LogAll: public LogType{
    public:
      LogAll(){type=loglevel::all;}
      ~LogAll(){}
  };
  
  //! ログレベルLogFatalクラス
  /*!
   * 致命的なエラー  
   * プログラムの異常終了を伴うようなもの。コンソール等に即時出力することを想定
   */
  class LogFatal: public LogType{
    public:
      LogFatal(){ type=loglevel::fatal; }
      ~LogFatal(){}
  };
  
  //! ログレベルLogErrorクラス
  /*!
   * エラー  
   * 予期しないその他の実行時エラー。コンソール等に即時出力することを想定
   */
  class LogError: public LogType{
    public:
      LogError(){ type=loglevel::error;}
      ~LogError(){}
  };
  
  //! ログレベルLogWarningクラス
  /*!
   * 警告  
   * 予期しないその他の実行時エラー。コンソール等に即時出力することを想定
   */
  class LogWarning: public LogType{
    public:
      LogWarning(){ type=loglevel::warning;}
      ~LogWarning(){}
  };
  
  //! ログレベルLogInformationクラス
  /*!
   * 情報  
   * 実行時の何らかの注目すべき事象（開始や終了など）。メッセージ内容は簡潔に止めるべき
   */
  class LogInformation: public LogType{
    public:
      LogInformation(){ type=loglevel::information;}
      ~LogInformation(){}
  };
  
  //! ログレベルLogDebugクラス
  /*!
   * デバッグ情報  
   * 予期しないその他の実行時エラー。コンソール等に即時出力することを想定
   */
  class LogDebug: public LogType{
    public:
      LogDebug(){ type=loglevel::debug;}
      ~LogDebug(){}
  };
  
  //! ログレベルLogTraceクラス
  /*!
   * トレース情報  
   * デバッグ情報よりも、更に詳細な情報
   */
  class LogTrace: public LogType{
    public:
      LogTrace(){ type=loglevel::trace;}
      ~LogTrace(){}
  };
  
  //! ログレベルLogNoneクラス
  /*!
   * ログレベルを定義しない特殊メッセージ用。本運用での利用は非推奨。
   */
  class LogNone: public LogType{
    public:
      LogNone(){ type=loglevel::none;}
      ~LogNone(){}
  };
  
  //! LogSystemクラス
  /*!
   * Singletonにしているが、インスタンスを一意に保てないバグが存在し、
   * 下記の方法でインスタンスを増やせてしまう。  
   * unique_ptr<LogSystem> lsystem= unique_ptr<LogSystem>(LogSystem::get().release());
   */
  class LogSystem{
    private:
      LogSystem();
    public:
      ~LogSystem() = default;

    public:
      LogSystem( const LogSystem&)= delete;
      LogSystem& operator=( const LogSystem&)= delete;
      LogSystem( LogSystem&&)= delete;
      LogSystem& operator=( LogSystem&&)= delete;
      static std::unique_ptr<LogSystem>& get(){
        create();
        return logsystem;
      }
      static void create(){
        if(!logsystem.get()){ // nullptrの場合
          logsystem.reset(new LogSystem);
        }
      }
      static void destroy(){
        logsystem.reset(nullptr);
      }
      void addLog(const LogInstance &log){
      }
    private:
      static std::unique_ptr<LogSystem> logsystem;
      static LogQueue queue;
  };
}

#endif
