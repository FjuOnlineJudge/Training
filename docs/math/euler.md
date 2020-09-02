# 歐拉定理及相關應用

## 歐拉函數

歐拉函數計算對於一個整數N，小於等於N的正整數中，有幾個和N互質。通常用$\\Phi(n)$表示。其公式為$\\Phi(N)=N\\times\\Pi\_{p|N}(1-\\frac{1}{p})$

```cpp
int Phi(int n){
    int ret = n;
    for(int i: p){
        if(i * i > n)break;
        if(n % i == 0){
            ret /= i;
            ret *= i - 1;
            while(n % i == 0)n /= i;
        }
    }
    if(n != 1){
        ret /= n;
        ret *= n - 1;
    }
    return ret;
}
```

歐拉函數還有一些性質
如果 p 是質數：$\\Phi(p) = p-1$以及$\\Phi(p^k)=p^{k−1}\\times (p−1)$
如果 pq 互質：$\\Phi(pq) = \\Phi(p)\\times\\Phi(q)$
根據這些性質，我們能寫出一個類似質數篩法的作法。

```cpp
void phi_table(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(phi[i])continue;
        for(int j = i; j < n; j += i){
            if(!phi[j])phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}
```

## 費馬小定理

給定一個質數 $p$ 及一個整數 $a$，那麼：
$a^p \\equiv a (\\mod p)$
如果$gcd(a,p)=1$，則：
$a^{p-1} \\equiv 1 (\\mod p)$

## 歐拉定理

歐拉定理是比較 generate 版本的費馬小定理。給定兩個整數 $n$ 和 $a$，如果 $gcd(a,n)=1$，則 $a^{\\Phi(n)} \\equiv 1 (\\mod n)$
如果n是質數，$\\Phi(n)=n-1$，也就是費馬小定理。

## Wilson's theorem

給定一個質數$p$，則：
$(p-1)!\\equiv -1 (\\mod p)$
