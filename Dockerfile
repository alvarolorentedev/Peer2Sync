#######################################################################
# Dockerfile to build Syncronization peer to peer container images
# Based on Ubuntu
#######################################################################
FROM ubuntu:14.04

MAINTAINER Kanekotic
RUN         apt-get update \
                && apt-get install -y \
                    software-properties-common \
                && add-apt-repository -y ppa:ubuntu-toolchain-r/test \
                && apt-get update \
                && apt-get install -y \
                    gcc-5 \
                    g++-5 \
                    libboost-all-dev \
                    redis-server \
                && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 60 --slave /usr/bin/g++ g++ /usr/bin/g++-5

RUN apt-get update && apt-get install -y libboost-all-dev redis-server

COPY ./dependencies/libcpp_redis.so /usr/lib/
COPY ./src/P2S_App/P2S_App /usr/bin/
COPY ./src/P2S_Lib/libP2S_Lib.so /usr/lib/
COPY ./src/P2S_Lib/libP2S_Lib.so.1 /usr/lib/

CMD ["/usr/bin/P2S_App"]
