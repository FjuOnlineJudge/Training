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
* `*.tex`：題本。
    * `statment`：題目敘述。
    * `input`：輸入說明。
    * `output`：輸出說明。
    * `spec`：測資範圍說明。
* `generate.py`：生測資工具。
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
    |-- input.tex
    |-- output.tex
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
contest_id = 1
adminName = ""
adminPassword = ""
onlyCorrectCode = True # get the correct code ID
teamId = [i for i in range(101,200)] # range of team ID
problemDict = {"":"A","":"B","":"C","":"D","":"E","":"F","":"G"} # map problem ID to alphabet
```

設定完請執行。

```shell
python script/domjudgeExportSubmissions.py
```

成功後會生成一個資料夾名稱為 `submit`，每個有繳交紀錄的 Team 有一個對應 ID 的資料夾和壓縮檔。

## 寄出程式碼

在 `script/sendEmail.py` 設定以下參數，`self.password` 請參考註解內容取得。`text_template` 和 `html_template` 需修改。

```py
def __init__(self):
    self.port = 465
    self.smtp_server_domain_name = "smtp.gmail.com"
    # https://stackoverflow.com/questions/16512592/login-credentials-not-working-with-gmail-smtp
    # https://www.google.com/settings/security/lesssecureapps
    # https://www.learncodewithmike.com/2020/02/python-email.html
    self.sender_mail = ""
    self.password = ""
    self.subject = ""
```

設定完請執行。執行的輸入格式為 `email teamid passwd`，如果 `teamid` 有對應的壓縮檔 `submit/teamid.zip` 會當成附件寄出。

```shell
python script/sendEmail.py
```

如果一次寄太多信，可能會遇到部分信件無法寄出，請稍後再寄。
