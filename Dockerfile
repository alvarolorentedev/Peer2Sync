#######################################################################
# Dockerfile to build Syncronization peer to peer container images
# Based on Ubuntu
#######################################################################
FROM ubuntu:16.04

MAINTAINER Kanekotic

RUN apt-get update && apt-get install -y libboost-all-dev redis-server
RUN redis-server&

RUN mkdir /P2S

ADD /usr/lib/libcpp_redis.so /P2S/
ADD ./test/P2S_App/P2S_App /P2S/
ADD ./test/P2S_Lib/libP2S_Lib.so /P2S/

CMD ["/P2S/P2S_App"]
