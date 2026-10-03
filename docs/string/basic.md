# 字串基礎
## 字串定義
字元的序列稱為字串 $S$。

字元的個數代表字串的長度 $|S|$。

## 子字串 Substring
子字串為字串 $S$ 的一段連續區間 $S[i,j]$，即 $S[i],S[i+1],\dots,S[j]$。

??? "Substring 範例"
    $S=abcdef$
    $abc,ef,c, \varnothing$ 是 Substring
    $abd,cba$ 不是 Substring

## 子序列 Subsequence
從字串 $S$ 中抽出若干個元素，並保留相對位置所形成的序列，稱為子序列。即 $S[p_1],S[p_2],\dots,S[p_k]$ $p_1<p_2<\dots<p_k$


??? "Subsequence 範例"
    $S=abcdef$
    $abc,abd,f,\varnothing$ 是 Subsequence
    $cba,fb$ 不是 Subsequence

## 前綴 Prefix
從字串 $S$ 第 $1$ 個位置到第 $i$ 個位置形成的子字串，即 $S[1,i]$，稱為前綴。

??? "前綴範例"
    $S=abcdef$
    有以下前綴：$a,ab,abc,abcd,abcde,abcdef$

## 後綴 Suffix
從字串 $S$ 第 $i$ 個位置到最後一個位置形成的子字串，即 $S[i,|S|]$，稱為後綴。

??? "後綴範例"
    $S=abcdef$
    有以下後綴：$f,ef,def,cdef,bcdef,abcdef$

## 回文 Palindrome
假設字串 $S'$ 是將 $S$ 倒著寫的字串，如果 $S=S'$ 那麼 $S$ 為回文字串。

??? "回文範例"
    $a,aba,abba,\varnothing$ 是回文字串
    $ab,abab,abbac$ 不是回文字串

## 相關主題
- [C 式字串](../syntax/cstring.md)：C 語言字元陣列