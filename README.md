# Исходные файлы echoServer + база данных (base.db)
Вы можете собрать образ с помощью команды `docker build`:<br>
`docker build -t echoserver_image .`<br><br>
Эта команда соберет Docker-образ с именем "echoserver_image" на основе Dockerfile из текущего каталога (где находится Dockerfile). После успешного сбора образа вы сможете запустить контейнер на его основе.<br><br>
Для запуска контейнера из образа вы можете использовать команду `docker run`:<br>
`docker run -p 33333:33333 --name myserver echoserver_image`