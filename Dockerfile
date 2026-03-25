# 1단계: 빌드 스테이지
FROM ubuntu:24.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY include ./include
COPY src ./src
COPY tests ./tests
COPY Makefile ./

RUN make
RUN make test

# 2단계: 실행 스테이지
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    ca-certificates \
    libc6 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/calculator /app/calculator

CMD ["./calculator"]

