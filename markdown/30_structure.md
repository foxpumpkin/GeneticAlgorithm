## Structure

下記の５つに分類できる。

### main()
  GeneticAlgorithmライブラリの動作確認用テストプログラムである。

### GeneticAlgorithm
  本リポジトリのメインとなる遺伝的アルゴリズムを実装する。

### Log
  ログ出力を管理する。ベースはLogSystem classであるが、
  Log classでラップするように運用する。ただし、LogSystem classは
  Singletonで設計/実装されているため、必ずしもLog classを使用する必要はない。
  非推奨であるが、直接LogSystem classを呼んでログ出力（統計）も可能である。

### Option
  コマンドライン引数を解釈する。
  boost::program_optionsを使用し、コマンドライン引数を解釈する。
  現時点（March 2019）では一般化されていないため、他のプログラムに
  流用するのは難しいと思われる。

### Define
  全体で使用する変数やクラスを記述する。
  
#### 名前空間 global
  プログラム全体で使用するフラグ類である。

#### 名前空間 loglevel
  ログレベルを表すuint64_t型の変数を宣言/定義し、
  また、loglevel::to_string()を使用し、uint64_t型のログレベルを引数としてstring型へ
  変換できる。

#### 名前空間 color
  標準出力/標準エラー出力時の色を指定することを目的とした変数およびクラスを宣言/定義する。
  色の指定はuint64_t型で宣言/定義される変数を使用する。

  color::to_string&lt;color::Color&gt;()で引数として与えるstringに対してglobal::color_logが
  trueの場合はカラータグを付与したstringを返す。
  global::color_logがfalseの場合はタグを付与せずそのまま返す。
