FROM debian:10

ARG GPP_VERSION=10
ARG EXERCISM_VERSION=3.0.13

# Unstable repositories
RUN echo "deb http://http.us.debian.org/debian unstable main non-free contrib" >> /etc/apt/sources.list \
    && echo "deb-src http://http.us.debian.org/debian unstable main non-free contrib" >> /etc/apt/sources.list \
    && apt-get update

# Compiler
RUN apt-get install -y gcc-${GPP_VERSION} g++-${GPP_VERSION} \
    && ln -s /usr/bin/g++-${GPP_VERSION} /usr/bin/g++ \
    && ln -s /usr/bin/gcc-${GPP_VERSION} /usr/bin/gcc

# Git
RUN apt-get update && \
    apt-get install -y git

# GDB
RUN apt-get update && \
    apt-get install -y gdb

# Exercism
RUN apt-get update && \
    apt-get install -y curl && \
    curl -LJ https://github.com/exercism/cli/releases/download/v${EXERCISM_VERSION}/exercism-${EXERCISM_VERSION}-linux-x86_64.tar.gz -o /tmp/exercism.tar.gz && \
    mkdir /tmp/exercism && \
    tar -xf /tmp/exercism.tar.gz -C /tmp/exercism && \
    cp /tmp/exercism/exercism /usr/bin