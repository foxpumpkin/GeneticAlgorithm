# GeneticAlgorithm


## Introduction 

このプログラムは遺伝的アルゴリズム（Genetic Algorithm）のC++による実装である。C++17の使用を前提としている。

現代では遺伝的アルゴリズムの基礎研究はなされていないため特別参考にした論文はない。
仮に基礎研究の論文が見つかれば、それに準ずる実装を進める。

## Previous Studies

### 遺伝的アルゴリズムについて
Kazuhide Okamura,  遺伝的アルゴリズム（Genetic Algorithm）を始めよう！, https://www.slideshare.net/kzokm/genetic-algorithm-41617242

### 設計について
@nanasess, ログ設計指針, https://qiita.com/nanasess/items/350e59b29cceb2f122b3
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
## Conclusion

実行結果を示す。

<pre>
% ./GeneticAlgorithm.out -h
Options:
  -h [ --help ]           Help
  -v [ --version ]        Version information
  -C [ --Color ]          color log
  -p [ --population ] arg Number of population (for test)
  -i [ --individual ] arg Number of individual (for test)
  -c [ --chromosome ] arg Number of population (for test)
  -g [ --gene ] arg       Number of population (for test)
  -V [ --verbose ]        more log
</pre>

<pre>
% ./GeneticAlgorithm.out
[Debug/None/06:13:24.370] (Options) color option was set to false.
[Trace/None/06:13:24.371] (GeneticAlgorithm) instancing
[Trace/None/06:13:24.371] (GeneticAlgorithm) allocation: 0
[Trace/None/06:13:24.371] (GeneticAlgorithm) initializing
[Error/None/06:13:24.371] (GeneticAlgorithm) length is zero. allocate memory.
[Debug/None/06:13:24.371] (main) application was successful
[Trace/None/06:13:24.371] (GeneticAlgorithm) destructing
</pre>

<pre>
% ./GeneticAlgorithm.out -v
Implementation of The GeneticAlgorithm with C++
     Version: 0.0
 Update Date: Mar. 2019
      Author: foxpumpkin
</pre>

## Release Note

| 日付 | 版数 | 備考 |
| ---: | ---: | ---  |
| Mar. 18th 2019 | 0.0 | アップロード |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
|                |  .  |              |
