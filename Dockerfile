#######################################################################
# Dockerfile to build Syncronization peer to peer container images
# Based on Ubuntu
#######################################################################
FROM ubuntu:16.04

MAINTAINER Kanekotic

RUN apt-get update && apt-get install -y libboost-all-dev redis-server supervisor

COPY ./dependencies/libcpp_redis.so /usr/lib/
COPY ./src/P2S_App/P2S_App /usr/bin/
COPY ./src/P2S_Lib/libP2S_Lib.so /usr/lib/
COPY ./src/P2S_Lib/libP2S_Lib.so.1 /usr/lib/
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf
COPY supervisord.sh /supervisord.sh

CMD ["/usr/bin/supervisord"]
