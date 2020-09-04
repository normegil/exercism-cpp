FROM debian:10

ARG GPP_VERSION=10
ARG CMAKE_VERSION=3.18.2
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

# MAKE
RUN apt-get update && \
    apt-get install -y make

# CURL
RUN apt-get update && \
    apt-get install -y curl
    
# CMake
RUN curl -LJ https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.sh -o /tmp/cmake-install.sh && \
    chmod u+x /tmp/cmake-install.sh && \
    mkdir -p /usr/share/cmake/${CMAKE_VERSION} && \
    /tmp/cmake-install.sh --skip-license --prefix=/usr/share/cmake/${CMAKE_VERSION} && \
    rm /tmp/cmake-install.sh && \
    ln -s /usr/share/cmake/${CMAKE_VERSION}/bin/cmake /usr/bin/cmake

# Exercism
RUN curl -LJ https://github.com/exercism/cli/releases/download/v${EXERCISM_VERSION}/exercism-${EXERCISM_VERSION}-linux-x86_64.tar.gz -o /tmp/exercism.tar.gz && \
    mkdir /tmp/exercism && \
    tar -xf /tmp/exercism.tar.gz -C /tmp/exercism && \
    cp /tmp/exercism/exercism /usr/bin

# Boost
RUN apt-get update && \
    apt-get install -y libboost-all-dev