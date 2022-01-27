# Domjudge

請先確認有安裝 docker 和 docker-compose

### 啟動 docker compose

* `docker-compose.yml` 可調整 `Judgehost` 的數量。

```
> git clone https://github.com/roy4801/domjudge-setup
> cd domjudge-setup/
> sudo docker-compose up -d
```

* 檢查是否成功開啟，這時候 `domjudge/judgehost:latest` 開啟失敗是正確的

```
>sudo docker ps -a
CONTAINER ID   IMAGE                       COMMAND                  CREATED             STATUS                     PORTS                                         NAMES
73d206ecc5f8   domjudge/judgehost:latest   "/usr/bin/dumb-init …"   7 seconds ago       Exited (1) 5 seconds ago                                                 judgedaemon-0
bd34e340e120   domjudge/domserver:latest   "/scripts/start.sh"      About an hour ago   Up 6 seconds               0.0.0.0:80->80/tcp, :::80->80/tcp             domserver
09962ae62b21   mariadb                     "docker-entrypoint.s…"   About an hour ago   Up 6 seconds               0.0.0.0:13306->3306/tcp, :::13306->3306/tcp   dj-mariadb
```

* 取得 `admin` 密碼

```
> sudo docker exec -it domserver cat /opt/domjudge/domserver/etc/initial_admin_password.secret
```

* 登入 domjudge

## 設定 judgehost

* 這時候 `.docker-compose.yml` 中的 judgehost 密碼和 domjudge 的 judgehost 密碼不同，必須一致 judgehost container 才會正確啟動。到 `domjudge` 的 `jury/users` 中把密碼改成 `.docker-compose.yml` 中的 judgehost 密碼。
* ![](https://i.imgur.com/17GnYlN.png)
* 接著重啟 `judgehost`

```
> sudo docker-compose up -d
```

* 進入 `/jury/judgehosts` 就可以看到 judgehost 正常開啟

## 上傳 team/account 資料

[參考連結](https://ccs-specs.icpc.io/2021-11/ccs_system_requirements#teamstsv)

* teams.tsv格式
```
teams    1
team number    external_ID    group_id    team_name    institution_name    institution_short_name    country_code
```

* accounts.tsv格式：For accounts of type `team` username is on the form "team-nnn" where "nnn" is the zero padded team number as given in teams.tsv.
```
accounts	1
account_type	fullname	username	password
```

## 上傳 contest

* 手動設定。
* 上傳壓縮檔：參考 [這裡](../contesttool/#_3)，同樣的資料會以新增方式加入而非覆蓋。
