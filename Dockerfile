FROM ubuntu

ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=US

WORKDIR /app

RUN apt-get update && \
    apt-get -y install gcc mono-mcs && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install valgrind -y

RUN apt-get update && apt-get install libncurses5-dev -y
#docker run -v /Users/rakso/Projects/todd:/app -it 881934d5b459 /bin/bash
