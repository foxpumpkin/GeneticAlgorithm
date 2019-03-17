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

### システム構成

下記の５つに分類できる。
1. mainプログラム  
  GeneticAlgorithmライブラリの動作確認用テストプログラム
1. GeneticAlgorithm  
  本リポジトリのメインとなる遺伝的アルゴリズムを実装する
1. Log  
  ログ出力を管理する
1. Option  
  コマンドライン引数を解釈する
1. Define  
  全体で使用する変数やクラスを記述する

---


## Release Note

| 日付 | 版数 | 備考 |
| ---: | ---: | ---  |
| March 18th 2019 | 0.0 | アップロード |
