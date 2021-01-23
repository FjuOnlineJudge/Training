### Command Line
#### MinGW
**要在電腦編譯C或C++的檔案需安裝MinGW**
* 載點: https://sourceforge.net/projects/mingw/
* 其他設定都不用改，直到這邊選Mark All Upgrades
    ![](https://i.imgur.com/jvpTKaZ.png)
* 再選Apply Changes
    ![](https://i.imgur.com/FFLgiJM.png)
* 設定環境變數: 
    1. 對本機點右鍵選內容
        ![](https://i.imgur.com/GdcOgQ1.png)
    2. 進階系統設定
        ![](https://i.imgur.com/SAJEFB1.png)
    3. 環境變數
        ![](https://i.imgur.com/ywCdBdM.png)
    4. 點開系統變數中的PATH
        ![](https://i.imgur.com/CdCO7w7.png)
    5. 新增 "C:\MinGW\bin" (預設在這個path下)
        ![](https://i.imgur.com/YbbpnKs.png)
    6. 打開cmd
        ![](https://i.imgur.com/Ae77CPH.png)
    7. 輸入gcc --version (或g++ --version) 檢查是否安裝成功
        ![](https://i.imgur.com/RmGdq5Q.png)



**格式**
```
C: gcc *.c -o *.exe
C++: g++ *.cpp -o *.exe 
Note: -o 是讓自己可以選擇exe檔要叫什麼名字，不然預設都會為a.exe
```

**範例**
前提: a.cpp存在桌面
1. 打開cmd
2. 到a.cpp檔案路徑: cd C:\Users\User_name\Desktop
    (若存在桌面通常打開cmd，可以直接 cd Desktop)
3. 編譯: g++ a.cpp -o a.exe
4. 執行: a.exe
    ![](https://i.imgur.com/BHYNJUO.png)

5. 輸入和輸出: a.exe < in.in > out.out