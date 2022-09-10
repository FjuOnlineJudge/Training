# Contest Tool
[專案連結](https://github.com/FjuOnlineJudge/Contest-Tool)

 本篇文介紹此專案的功能，包含：

* 製作題本
* 將題目打包成壓縮檔
* 生成測資
* 匯出 Domjudge 程式碼並依 Team ID 儲存和壓縮
* 寄出程式碼

## 題目資料夾
每道題目都用一個資料夾存放，裡面的資料如下：

* `data`：測資。
    * `sample` 為範例測資，`secret` 為隱藏測資。
    * 輸入為 `in` 檔，輸出為 `ans` 檔。
* `domjudge-problem.ini`： Domjudge 設定檔。
* `*.tex`：題本 `tex` 檔。
    * `statment`：題目敘述。
    * `input`：輸入說明。
    * `output`：輸出說明。
    * `spec`：測資範圍說明。
    * `hint`：提示。
* `generate.py`：生測資工具。
* `problem.{pdf,html,txt}`：題本。
* `submissions`：範例程式，程式碼的命名不拘，子資料夾名稱如下：
    * `accecpted`：預設結果 `AC`。
    * `wrong_answer`：預設結果 `WA`。
    * `time_limit_exceeded`：預設結果 `TLE`。
    * `run_time_error`：預設結果 `RE`。

??? "詳細結構"
    ```
    |-- data
    |   |-- sample
    |   |   |-- 1.ans
    |   |   |-- 1.in
    |   |   |-- 2.ans
    |   |   |-- 2.in
    |   |   `-- ....
    |   `-- secret
    |       |-- 1.ans
    |       |-- 1.in
    |       |-- 2.ans
    |       |-- 2.in
    |       `-- ....
    |-- domjudge-problem.ini
    |-- generate.py
    |-- hint.tex
    |-- input.tex
    |-- output.tex
    |-- problem.{pdf,html,txt}
    |-- spec.tex
    |-- statment.tex
    `-- submissions
        `-- accepted
            |-- 1.cpp
            |-- 1.py
            |-- Main.java
            `-- ...
    ```

詳細請參考 `sample` 資料夾，`script/folderGenerator.py` 可以複製一個題目資料夾以供使用。

```shell
python script/folderGenerator.py test # 生成 test 題目資料夾
```

## 製作題本

 `tex` 檔用來製作題本，需要學習基本 `latex` 語法，當準備好題目資料夾，請到 `main.tex`，找到註解起來的 `problemList` 和 `problem` 指令，取消註解並使用。

```tex
% \problemList{folder_name}{problem_name}{time_limit}{memory_limit}
% \problem{folder_name}{problem_name}{time_limit}{memory_limit}
\problemList{test}{test}{1}{256}
\problem{test}{test}{1}{256}
```

其他可以調整設定標題的 `title`，設定頁首與頁尾的 `fancypagestyle`，還有封面的內容，調整好後就可生成 pdf 檔。

使用 `GNU make` 生成，要確認在主機上安裝好 `xelatex` 以及相關套件。

```shell
make
```

使用 `docker-compose` 生成，只要使用 `pdfMaker` 這個服務即可。

```shell
docker-compose up -d # 只使用 pdfMaker
sh script/makePdf.sh
```

## 將題目打包成壓縮檔

`script/folderCompressor.py` 負責將題目資料夾壓縮，預設會將所有檔案壓縮，`-d` 則預設壓縮成 `domjudge` 格式的壓縮檔，包含 `data`、`domjudge-problem.ini` 和 `submissions`。

```shell
python script/folderCompressor.py test # 壓縮 test 題目資料夾
python script/folderCompressor.py -d test # 將 test 資料夾壓縮成 `domjudge` 格式
```

## 生成測資

`script/testdataGenerator.py` 提供的辦法如下：

* 範例程式存在 `submissions/accepted/1.cpp`。
* 生測資檔案存在 `generate.py`，`generate.py` 可利用 [CYaRon](https://github.com/luogu-dev/cyaron)。
* 測資會在 `data/secret`。

```shell
python script/folderCompressor.py test # 壓縮 test 題目資料夾
python script/folderCompressor.py -d test # 將 test 資料夾壓縮成 `domjudge` 格式
```

## 匯出 Domjudge 程式碼並依 Team ID 儲存和壓縮

在 `script/domjudgeExportSubmissions.py` 設定以下參數。

```py
server = "" # server ip
adminName = ""
adminPassword = ""
cid = 0 # contest id
```

設定完請執行。

```shell
python script/domjudgeExportSubmissions.py
```

成功後會生成一個資料夾名稱為 `submit`，每個有繳交紀錄的 Team 有一個對應 ID 的資料夾和壓縮檔。

## 寄出程式碼

將收件人資訊整理在 `maillist.csv`，包含電子郵件、姓名和登入帳號密碼。

在 `script/sendEmail.py` 建立 class 時可設定 port、SMTP Server Domain、寄件人電子郵件、電子郵件密碼和標題。

```py
if __name__ == '__main__':
    data = [s.split(",") for s in sys.stdin]
    mail = Mail() # 設定資訊
    mail.send(data)
```

常用 SMTP server：

- smtp.gmail.com，port 為 465。
- smtp.office365.com，port 為 587。

`send` 函式有幾處需要修改，`text_template` 和 `html_template` 設定信件內容，前者為純文字，後者為 html 格式，如果信件包含附件，在 `file_path_set` 填入附件路徑。

設定完之後，請執行下面指令。

```shell
python script/sendEmail.py < maillist.csv
```

如果一次寄太多信，可能會遇到部分信件無法寄出，請稍後再寄。
